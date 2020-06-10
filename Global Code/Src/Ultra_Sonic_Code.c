
#include "stm32f4xx_hal.h"
//#include "main.c"

void Delay_us(uint16_t i)  // this function make a delay of i*2 microsends (exp : if i=1 then we have a delay of 2us ...)
                            //for an internal clock speed of 8 Mhz that's why we multiply the result to 4 not to 2
	{
	
	 static uint16_t j=0 , k=0 ;   
		for(k=0;k<i;k++)
		  for(j=0;j<1;j++);
	}
float Distance , TimCop , TimVal;
int Get_Distance()
{
	

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    //GPIOD->ODR &= ~GPIO_PIN_12;
		Delay_us(1);
       // GPIOD->ODR |= GPIO_PIN_12;
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
    Delay_us(5);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    //GPIOD->ODR &= ~GPIO_PIN_12;
    
    while((/*GPIOD -> IDR & GPIO_PIN_13*/HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13)) == 0x00){};
		
		TimVal = 0;
    while((/*GPIOD -> IDR & GPIO_PIN_13*/HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13)) != 0x00)
		{
		 
		   TimVal++;
			 Delay_us(1);     // calculating in microseconds high pulse lenght of pin D 13
		
		}			

  TimCop=TimVal;
	return Distance=(float)TimCop*0.0171821*4;	 //Distance = measured time * 0.01717821 * 4
}




