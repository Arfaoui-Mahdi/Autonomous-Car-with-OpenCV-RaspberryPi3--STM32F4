#ifndef _Variables_
#define _Variables_

   uint8_t Rx_Data[10]; // array of informations received from the RPI 3
   uint8_t US , Stop , Feu_R , Feu_G , Ced , T_left , T_right; 



   US = Rx_Data[0] ;
	 Stop = Rx_Data[1] ;
	 Feu_R = Rx_Data[2] ;
	 Feu_G= Rx_Data[3] ;
	 Ced = Rx_Data[4] ;
	 T_left= Rx_Data[5] ;
	 T_right = Rx_Data[6] ;


#endif

