#include "HX711.h"

long HX711_AverageValue(hx711_t *data, uint8_t times)
{
    int sum = 0;
    for (int i = 0; i < times; i++)
    {
        sum += HX711_Value(data);
    }

    return sum / times;
}

float HX711_Value(hx711_t *data)
{
	int count=0;
    while (HAL_GPIO_ReadPin(data->portData, data->pinData)==1); // wait for data pin 0

    for (uint8_t i = 0; i < 24; i++)
    {
    	HAL_GPIO_WritePin(data->portSck, data->pinSck, GPIO_PIN_SET); //set clk 1
        count = count << 1 ; //increase buffer value
        if(HAL_GPIO_ReadPin(data->portData, data->pinData) == 1){
        	count++;
        } //read and update data buffer

        HAL_GPIO_WritePin(data->portSck, data->pinSck, GPIO_PIN_RESET); //set clk 0
    }

    //25. clk to set next conversation CH.A, Gain:128
    HAL_GPIO_WritePin(data->portSck, data->pinSck, GPIO_PIN_SET);
    count = count ^ 0x800000; //get 2's complement of data
    HAL_GPIO_WritePin(data->portSck, data->pinSck, GPIO_PIN_RESET);

	data->buffer=count;
    return count;
}

void init_hx711_port(hx711_t *data, GPIO_TypeDef* portScki, uint16_t pinScki,
		GPIO_TypeDef* portDatai, uint16_t pinDatai )
{
	data->gain=1;
	data->portData=portDatai;
	data->portSck=portScki;
	data->offset=0;
	data->pinData=pinDatai;
	data->pinSck=pinScki;
	data->buffer=0;

	HAL_GPIO_WritePin(data->portSck, data->pinSck, GPIO_PIN_SET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(data->portSck, data->pinSck, GPIO_PIN_RESET);
}

