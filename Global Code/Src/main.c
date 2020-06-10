
 
 
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "Forward.h"
#include "Backward.h"
#include "turn_left.h"
#include "turn_right.h"
#include "Stop_Func.h"
#include "Speed_Changer.h"
#include "Default_Functions_Gen.h"

//#include "Variables.h"




/* Private variables ---------------------------------------------------------*/
//TIM_HandleTypeDef htim2;

//UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

  uint8_t Rx_Data[10]; // array of informations received from the RPI 3
  uint8_t US , Stop , Feu_R , Feu_G , Ced , T_left , T_right , Speed_Lim; 
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_TIM2_Init(void);
void MX_USART1_UART_Init(void);                                    
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
                                


int main(void)
{
	UART_HandleTypeDef huart1;
 
  HAL_Init();

 
  SystemClock_Config();

  
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
   __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE); // enabling UART Receiving
  /* USER CODE END 2 */
   
   US = Rx_Data[0] ;
	 Stop = Rx_Data[1] ;
	 Feu_R = Rx_Data[2] ;
	 Feu_G= Rx_Data[3] ;
	 Ced = Rx_Data[4] ;
	 T_left= Rx_Data[5] ;
	 T_right = Rx_Data[6] ;
	 Speed_Lim = Rx_Data[7];

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
     HAL_UART_Receive_IT(&huart1 , (uint8_t*)Rx_Data , 10 ); // receiving the buffer
		
		if(US==1)
		{
		  while (US==1)
			{
			  Do_Stop();
			}
			Forward(60);
		}
		else 
		
		  if (Feu_R==1)
			{
			  while(Feu_R==1)
				{
				   Do_Stop();
				}
			    Forward(60);
			}
			if(Feu_G==1)
			{
			    Forward(60);
			}
		  
			if ( Stop == 1 )
		{
		 do{
			    Do_Stop();
			 
			 }while(!(US==1));
		 Forward(60);
		}
		if (Ced==1)
		{
		  do{
			      Do_Stop();
			 
			  }while(!(US==1));
		   Forward(60);
		}
      
			 else if( Speed_Lim != 0  )
			 {
			    Speed_Ch(Speed_Lim);
			 
			 }
		else
			if ( T_left==1 || T_right==1)
{
    
	if( T_left==1)
	{
	  while(T_left ==1)
		{
		 Turn_Left();
		 
		}
		Forward(60);
	
	}
	 if( T_right==1)
	 {
	  while(T_right == 1)
		{
		 Turn_Right();
		 
		}
		Forward(60);
	 }
	
}

  }
  

}

