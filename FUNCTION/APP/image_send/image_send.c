#include "image_send.h"

u8 READ[USART_REC_LEN];
Image_Info_t image_info;



Image_Info_t* get_Image_Info(void)
{
		return &image_info;
}

void USART_Image_Recieve(void)
{
	  int buff[4]={0,0,0,0},x=0,y=0,Image_count = 0;
    if(USART_RX_STA&0x8000)
    {
        for(int i=0; i<200; i++)
            READ[i]=USART_RX_BUF[i];
			  for(int i=0;i<4;i++)
        buff[i]=USART_RX_BUF[i]-'50';
				x=buff[0]*10+buff[1];
				y=buff[2]*10+buff[3];
				image_info.set_x = x;
				image_info.set_y = y;
            //在串口中断中的判断处理函数
//					{
//							u16 set_x = (READ[0] - '0') | (READ[1] - '0' << 8);
//							u16 set_y = (READ[2] - '0' | READ[3] - '0'<< 8);
//							USART_TRANS (set_x,set_y);
//					}
        USART_RX_STA=0;
    } else
    {
        if(image_info.set_x == 0 && image_info.set_y == 0)
				{
						Image_count++;
				}
				else
				{
						Image_count = 0;
				}
				if (Image_count >= 1000)
        {
            GIMBAL_Mode = GIMBAL_MODE_HAND;
        }
    }

}
