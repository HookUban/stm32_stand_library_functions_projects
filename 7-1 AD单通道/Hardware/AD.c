#include "stm32f10x.h"                  // Device header

void AD_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	ADC_RegularChannelConfig(ADC1,ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	
	ADC_InitTypeDef ADC_Initstructure;
	ADC_Initstructure.ADC_Mode = ADC_Mode_Independent;
	ADC_Initstructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_Initstructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_Initstructure.ADC_ContinuousConvMode = ENABLE;
	ADC_Initstructure.ADC_ScanConvMode = DISABLE;
	ADC_Initstructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_Initstructure);
	
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1)==SET);
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1)==SET); 
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

uint16_t AD_GetValue(void)
{

	return ADC_GetConversionValue(ADC1);
	
}