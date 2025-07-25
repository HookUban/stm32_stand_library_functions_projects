#include "stm32f10x.h"                  // Device header
#include "Delay.h"



int main()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed =   GPIO_Speed_50MHz; 
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	//GPIO_SetBits(GPIOA, GPIO_Pin_0);
	//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
	while(1)
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)0);
		Delay_ms(1000);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)1);
		Delay_ms(1000);
	}
}
