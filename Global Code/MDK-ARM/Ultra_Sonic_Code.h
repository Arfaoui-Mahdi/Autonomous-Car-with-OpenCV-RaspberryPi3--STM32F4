#include "stm32f4xx_hal.h"
 



float Distance , TimCop , TimVal;

void Delay_us(uint16_t i)
	{
	
	 static uint16_t j=0 , k=0 ;
		for(k=0;k<i;k++)
		  for(j=0;j<1;j++);
		

	}

/* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
    //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);

float Get_Distance()
{
	GPIOD->ODR &= ~GPIO_PIN_12;
		Delay_us(1);
        GPIOD->ODR |= GPIO_PIN_12;
		//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
    Delay_us(5);
    //HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    GPIOD->ODR &= ~GPIO_PIN_12;
    
    while((GPIOD -> IDR & GPIO_PIN_13) == 0x00){}
		
		TimVal = 0;
    while((GPIOD -> IDR & GPIO_PIN_13) != 0x00)
		{
		 
		   TimVal++;
			 Delay_us(1);
		
		}			

  TimCop=TimVal;
  Distance=(float)TimCop*0.0171821*4;	 
		return Distance;
	
 		
		
	}
