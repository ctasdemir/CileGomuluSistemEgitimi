#include "button_driver.h"
#include "stm32f070xb.h"
#include "stm32f0xx_hal.h"


void button_init()
{
	//BUTTON ==>  GPIOC - 13. pin
	GPIO_InitTypeDef gpio_init;
	
	// Enable Clock
	__HAL_RCC_GPIOC_CLK_ENABLE();	
	
	gpio_init.Mode = GPIO_MODE_INPUT;
	gpio_init.Pin = GPIO_PIN_13;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Speed = GPIO_SPEED_MEDIUM;

  HAL_GPIO_Init(GPIOC,&gpio_init);	
	
}

int32_t button_get_state(void)
{
	//BUTTON ==>  GPIOC - 13. pin
	GPIO_PinState state;
	state = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
	
	if( state == GPIO_PIN_SET )
	{
		return BUTTON_OFF;
	}
	else
	{
		return BUTTON_ON;
	}	
}
