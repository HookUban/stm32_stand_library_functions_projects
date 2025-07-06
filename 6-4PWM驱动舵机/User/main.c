#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"
#include "Encoder.h"


uint8_t KeyNum;
float Angle;
int16_t coder;


int main(void)
{	
	OLED_Init();
	Servo_Init();
	Key_Init();
	Encoder_Init();
	
	OLED_ShowString(1, 1, "coder:");
	
	while(1)
	{
		coder += Encoder_Get();
//		OLED_ShowSignedNum(1, 7, coder, 3);
//		KeyNum = Key_GetNum();
//		if (KeyNum == 1)
//		{
//			Angle += 30;
//			if (Angle > 180)
//			{
//				Angle = 0;
//			}
//		}
		if (coder < 0 || coder > 36){
			coder = 0;
		}
		Servo_SetAngle(coder*5);
		OLED_ShowNum(1, 7, coder, 3);
	}
	
}
