#include "stm32f4xx_hal.h"



void Speed_Ch(int Speed)
{


	//Variables Declaration
	 TIM_HandleTypeDef htim2;
	 int CurrSpeed; 
	 CurrSpeed = htim2.Instance->CCR2;
	
	
	//set Motors to Forward
	
	
	
     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);//====> set           forward              morot
     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET); //====>	    direction         for the left
     
     HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET);//====> set           forward              motor
     HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);   //          direction        for the right
	
	
 // Code begins
	
	if (Speed > CurrSpeed)
	{
	
	  
	for ( int i =CurrSpeed ; i < Speed ; i+=2)
	       {
	         htim2.Instance->CCR1 = i; 
           htim2.Instance->CCR2 = i;  
			     HAL_Delay(100);
	
	}
}
				 else
	   if( Speed < CurrSpeed)
	{
	
	
	  
	for ( int i =CurrSpeed ; i > Speed ; i-=2)
	       {
	         htim2.Instance->CCR1 = i; 
           htim2.Instance->CCR2 = i;  
			     HAL_Delay(100);
	
	
	
	}					 
	
	
	
	
	
	




}
}