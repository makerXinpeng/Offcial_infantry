#ifndef __IMAGE_SEND
#define __IMAGE_SEND
#include "sys.h"
#include "usart.h"
#include "cloudMotor.h"

typedef  struct
{
	 int set_x;
	 int set_y;
} Image_Info_t;

Image_Info_t* get_Image_Info(void);
void USART_Image_Recieve(void);
#endif
