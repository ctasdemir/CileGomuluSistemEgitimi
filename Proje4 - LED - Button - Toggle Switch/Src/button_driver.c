#include "button_driver.h"
#include "stm32f070xb.h"
#include "stm32f0xx_hal.h"


void button_init()
{
	//BUTTON ==>  GPIOC - 13. pin
	
	// Enable Clock
	__HAL_RCC_GPIOC_CLK_ENABLE();	
	
	// Select Mode: Input
	GPIOC->MODER   &= ~((3UL << 26));  // set 00 ==> Input
	
	// Select Output Type	
  GPIOC->OTYPER  &= ~((1UL <<13));   // 0 ==> Push pull
	
	// Select Speed	
  GPIOC->OSPEEDR &= ~((3UL << 26));  // 00 ==> Low speed
	
	// Pull-up pull-down	
  GPIOC->PUPDR   &= ~((3UL << 26));  // 00 ==> // No pull-up, no pull-down
	
}

int32_t button_get_state(void)
{
	//BUTTON ==>  GPIOC - 13. pin
	if( (GPIOC->IDR & GPIO_PIN_13) )
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}
