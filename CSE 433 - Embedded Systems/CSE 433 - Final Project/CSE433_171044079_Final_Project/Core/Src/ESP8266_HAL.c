#include "ESP8266_HAL.h"
#include "HX711.h"
#include "stdio.h"
#include "string.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim4;
extern hx711_t hx711;

#define wifi_uart &huart1
#define pc_uart &huart2


char buffer[20];

char * response = "\
HTTP/1.1 200 OK\r\n\
Date: Thu, 09 Jun 2020 17:00:00 GMT\r\n\
Server: Pati/1.0.0\r\n\
Content-Type: text/html\r\n\
Content-Length: 3\r\n\
Connection: Closed\r\n\n";




/*****************************************************************************************************************************************/

void ESP_Init (char *SSID, char *PASSWD)
{
	char data[80];

	Ringbuf_init();

	Uart_sendstring("AT+RST\r\n", wifi_uart);
	Uart_sendstring("RESETTING.", pc_uart);
	for (int i=0; i<5; i++)
	{
		Uart_sendstring(".", pc_uart);
		HAL_Delay(1000);
	}

	/********* AT **********/
	Uart_sendstring("AT\r\n", wifi_uart);
	while(!(Wait_for("AT\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("AT---->OK\n\n\r", pc_uart);


	/********* AT+CWMODE=1 **********/
	Uart_sendstring("AT+CWMODE=1\r\n", wifi_uart);
	while (!(Wait_for("AT+CWMODE=1\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("CW MODE---->1\n\n\r", pc_uart);


	/********* AT+CWJAP="SSID","PASSWD" **********/
	Uart_sendstring("connecting... to the provided AP\n\r", pc_uart);
	sprintf (data, "AT+CWJAP=\"%s\",\"%s\"\r\n", SSID, PASSWD);
	Uart_sendstring(data, wifi_uart);
	while (!(Wait_for("WIFI GOT IP\r\n\r\nOK\r\n", wifi_uart)));
	sprintf (data, "Connected to,\"%s\"\n\n\r", SSID);
	Uart_sendstring(data,pc_uart);


	/********* AT+CIFSR **********/
	Uart_sendstring("AT+CIFSR\r\n", wifi_uart);
	while (!(Wait_for("CIFSR:STAIP,\"", wifi_uart)));
	while (!(Copy_upto("\"",buffer, wifi_uart)));
	while (!(Wait_for("OK\r\n", wifi_uart)));
	int len = strlen (buffer);
	buffer[len-1] = '\0';
	sprintf (data, "IP ADDR: %s\n\n\r", buffer);
	Uart_sendstring(data, pc_uart);


	Uart_sendstring("AT+CIPMUX=1\r\n", wifi_uart);
	while (!(Wait_for("AT+CIPMUX=1\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("CIPMUX---->OK\n\n\r", pc_uart);

	Uart_sendstring("AT+CIPSERVER=1,80\r\n", wifi_uart);
	while (!(Wait_for("OK\r\n", wifi_uart)));
	Uart_sendstring("CIPSERVER---->OK\n\n\r", pc_uart);

	Uart_sendstring("Now Connect to the IP ADRESS\n\n\r", pc_uart);

}

int Server_Send (char *str, int Link_ID)
{
	int len = strlen (str);
	char data[80];
	sprintf (data, "AT+CIPSEND=%d,%d\r\n", Link_ID, len);
	Uart_sendstring(data, wifi_uart);
	while (!(Wait_for(">", wifi_uart)));
	Uart_sendstring (str, wifi_uart);
	while (!(Wait_for("SEND OK", wifi_uart)));
	sprintf (data, "AT+CIPCLOSE=5\r\n");
	Uart_sendstring(data, wifi_uart);
	while (!(Wait_for("OK\r\n", wifi_uart)));
	return 1;
}

void Server_Handle (char *str, int Link_ID)
{
	char datatosend[1024] = {0};
	if (strcmp (str, "/open") == 0)
	{
		Uart_sendstring("Open response\n\r", pc_uart);

		htim4.Instance->CCR1 = 125;
		HAL_Delay(3000);
		htim4.Instance->CCR1 = 25;

	}

	else if (strcmp (str, "/weight") == 0)
	{
		Uart_sendstring("Weight response", pc_uart);

		float current_weight = HX711_AverageValue(&hx711, 20);
		sprintf(datatosend, "%f", current_weight);
		Uart_sendstring(datatosend, pc_uart);


		//Empty cup value of the load cell
		if(current_weight < 8310000){
			  current_weight = 8310000;
		 }
		//Full cup value of the load cell
		else if( current_weight > 8338000){
			  current_weight = 8338000;
		}

		int percentage = (current_weight-8310000) * 100 / 28000;
		sprintf (datatosend, response);
		char weight_str[10];

		sprintf(weight_str, "%03d", percentage);
		strcat(datatosend, weight_str);
		Uart_sendstring(datatosend, pc_uart);

		Server_Send(datatosend, Link_ID);

	}
	else if(strcmp(str, "/temperature") == 0){
		//Get temperature
	}



}

void Server_Start (void)
{
	char buftocopyinto[64] = {0};
	char Link_ID;
	while (!(Get_after("+IPD,", 1, &Link_ID, wifi_uart)));
	Link_ID -= 48;
	while (!(Copy_upto(" HTTP/1.1", buftocopyinto, wifi_uart)));

	if (Look_for("/open", buftocopyinto) == 1)
	{
		Server_Handle("/open",Link_ID);
	}

	else if (Look_for("/weight", buftocopyinto) == 1)
	{
		Server_Handle("/weight",Link_ID);
	}

	else if(Look_for("/temperature", buftocopyinto) == 1){
		Server_Handle("/temperature", Link_ID);
	}
	else
	{
		Server_Handle("/ ", Link_ID);
	}
}
