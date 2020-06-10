#include "stm32f4xx_hal.h"



/* 
PB0 and PB1 : Direction pins for left motor
PE0 and PB1 : Direction pins for right motor

PA1 : enable pin for left motor -PWM Pin-
PA2 : enable pin for right motor -PWM Pin-

*/



// we perform a left turn by decreasing the left motor speed 

void Turn_Left()
{ 
	TIM_HandleTypeDef htim2;
	int CurrSpeed;

	   HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //enable for the left motor PA1 (PWM) 
	   HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //enable for the right motor PA2 (PWM)
	 
	
	  
     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);//====> set           forward              morot
     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET); //====>	    direction         for the left
     
     HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET);//====> set          forward              morot
     HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);  //====>	    direction         for the right


     


    htim2.Instance->CCR4 = 30;
	  
	   


      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);//====> 
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); // ====> set Direction to the left





//		
//		CurrSpeed=htim2.Instance->CCR2;
//		int edge=CurrSpeed*35/100; //decrease left motor speed by 35% from the current speed 		
//		   
//		   for(int i=CurrSpeed; i > edge ; i-=5 )
//		   {
//			   htim2.Instance->CCR2=i;
//			   HAL_Delay(100);
		   //}			   
		
		
		
	
	
}
