#ifndef HX711_H_
#define HX711_H_

#include "stm32f4xx_hal.h"

#define HX711_SCK_PORT clk_GPIO_Port
#define HX711_SCK_PIN1 clk_Pin

#define HX711_DATA_PORT data_GPIO_Port
#define HX711_DATA_PIN1 data_Pin

struct _hx711_t
{
	GPIO_TypeDef* portSck;
	GPIO_TypeDef* portData;
	uint16_t pinSck;
	uint16_t pinData;
	long offset;
	float scale;
	uint8_t gain;
	int buffer;
};

typedef struct _hx711_t hx711_t;

float HX711_Value(hx711_t *data);
long HX711_AverageValue(hx711_t *data, uint8_t times);
void init_hx711_port(hx711_t *data, GPIO_TypeDef* portScki, uint16_t pinScki, GPIO_TypeDef* portDatai, uint16_t pinDatai ); //USED

#endif
