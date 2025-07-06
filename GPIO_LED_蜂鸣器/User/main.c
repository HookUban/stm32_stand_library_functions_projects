#include "stm32f10x.h"                  // Device header
#include "Delay.h"


#define D_TIME 1000


int main()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed =   GPIO_Speed_50MHz; 
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	uint16_t mask = 0x0001;
	while(1)
	{
//		GPIO_Write(GPIOB, 0x0800); // 0000 1000 0000 0000
//		Delay_ms(D_TIME);
//		GPIO_Write(GPIOB, ~0x0800); // 0000 1000 0000 0000
//		Delay_ms(D_TIME);
//		GPIO_ResetBits(GPIOB, GPIO_Pin_12); 
//		Delay_ms(D_TIME);
		GPIO_SetBits(GPIOB, GPIO_Pin_12); 
		Delay_ms(D_TIME);
	
		

	}
}
