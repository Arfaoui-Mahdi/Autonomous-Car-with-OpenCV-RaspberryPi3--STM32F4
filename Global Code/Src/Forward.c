#include "stm32f4xx_hal.h"


/* 
PB0 and PB1 : Direction pins for left motor
PE0 and PE1 : Direction pins for right motor

PA1 : enable pin for left motor -PWM Pin-
PA2 : enable pin for right motor -PWM Pin-

*/


void Forward(int Speed)
{
   TIM_HandleTypeDef htim2;
	 int CurrSpeed; 
	 CurrSpeed = htim2.Instance->CCR2; //Duty cycle of one of the two motors cause they are equal
	 
	 
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //enable for the left motor PA1 (PWM) 
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //enable for the right motor PA2 (PWM)
	 
	
	
     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);//====> set           forward              morot
     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET); //====>	    direction         for the left
     
     HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET);//====> set           forward              morot
     HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);  //====>	    direction         for the right
   
   if( CurrSpeed == 0)
   {
   for(int i=5 ; i<60; i+=2)        //   
     {  htim2.Instance->CCR3=i;   // for a smooth start_up
        htim2.Instance->CCR2=i;    //
        HAL_Delay(100);
                              		 
	 }
     //
   }
    else
   {  
     for ( int i =CurrSpeed ; i < Speed ; i+=2)
	       {
	         htim2.Instance->CCR1 = i; 
           htim2.Instance->CCR2 = i;  
			     HAL_Delay(100);
	       }
	  
    }	
	
	
		
		 
		
}
	
	

