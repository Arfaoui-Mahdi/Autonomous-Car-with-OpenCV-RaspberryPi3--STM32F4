#include "stm32f4xx_hal.h"


/* 
PB0 and PB1 : Direction pins for left motor
PE0 and PB1 : Direction pins for right motor

PA1 : enable pin for left motor -PWM Pin-
PA2 : enable pin for right motor -PWM Pin-

*/


void Backward(int Speed)
{
  int CurrSpeed;
	TIM_HandleTypeDef htim2;
	
	
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //enable for the left motor PA1 (PWM) 
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //enable for the right motor PA2 (PWM)
	 
	
	  // we just invert pins states

     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);//====> set           backward              motor
     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET); //====>	  direction          for the left
     
     HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);//====> set           backward                motor
     HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_SET);  //====>	  direction           for the right
   
       	CurrSpeed=htim2.Instance->CCR2 ; //Duty cycle of one of the two motors cause they are equal

       if ( CurrSpeed == 0 )
	   {
		   for(int i=5; i<Speed ; i+=2)
		   {
			   htim2.Instance->CCR2 = i; 
         htim2.Instance->CCR3 = i;  
			   HAL_Delay(100);
		   }
		 }
			   else
				 {
				 for(int i=CurrSpeed ; i<Speed ; i+=2)
		   {
			   htim2.Instance->CCR2 = i; 
         htim2.Instance->CCR3 = i;  
			   HAL_Delay(100);
		   }
				 
				 }
	  

}   
		 
		 
	
	 


