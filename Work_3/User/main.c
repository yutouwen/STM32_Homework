#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CountSensor.h"
#include "LED.h"
#include "Timer.h"

uint16_t Num = 0;
uint16_t Num_ms = 0;
uint16_t Num_s = 0;
void display1(int Place);
int time[3] = {0};
int main(void)
{
	OLED_Init();
	CountSensor_Init();
	LED_Init();
	
	
	int a[3] = {-1,-1,-1};
	int cnt = 0;
	int OldNum = CountSensor_Get();
	int delayCount = 0;
	int pla = 0;
	
	while (1)
	{
		if(++Num >= 60){
			Num = 0;
			++Num_ms;
		}
		if(Num_ms >= 60){
			Num_ms = 0;
			++Num_s;
		}
		OLED_ShowString(3, 1, "Cloc:");
		OLED_ShowNum(3, 6, Num_s,2);
		OLED_ShowChar(3, 8, ':');
		OLED_ShowNum(3, 9, Num_ms,2);
		OLED_ShowChar(3, 11, ':');
		OLED_ShowNum(3, 12, Num, 2);
		
		OLED_ShowNum(4, 5, TIM_GetCounter(TIM2), 5);
		
		int num = CountSensor_Get(); //返回值为按键编号,按顺序写入数组
		if(num != OldNum && cnt<4 && num != a[0]&& num != a[1]) {
			a[cnt++] = num;
			time[0] = Num_s; 
			time[1] = Num_ms;
			time[2] = Num;
		}
		switch(a[0]){
			case 8: 
				LED1_Turn();
				Delay_ms(50000);
				++delayCount;
				break;
			case 9: 
				LED2_Turn();
				Delay_ms(50000);
				++delayCount;
				break;
			case 10: 
				LED3_Turn();
				Delay_ms(50000);
				++delayCount;
				break;
			case 11: 
				LED4_Turn();
				Delay_ms(50000);
				++delayCount;
				break;
			case 12: 
				LED5_Turn();
				Delay_ms(50000);
				++delayCount;
				break;
			case 13: 
				LED6_Turn();
				Delay_ms(50000);
				++delayCount;
				break;
			case 14: 
				LED7_Turn();
				Delay_ms(50000);
				++delayCount;
				break;
			case 15: 
				LED8_Turn();
				Delay_ms(50000);
				++delayCount;
				break;
		}
		if(delayCount%2==0){
		switch(a[1]){
			case 8: 
				LED1_Turn();
				break;
			case 9: 
				LED2_Turn();
				break;
			case 10: 
				LED3_Turn();
				break;
			case 11: 
				LED4_Turn();
				break;
			case 12: 
				LED5_Turn();
				break;
			case 13: 
				LED6_Turn();
				break;
			case 14: 
				LED7_Turn();
				break;
			case 15: 
				LED8_Turn();
				break;
		}
	}
				if(delayCount%4==0){
		switch(a[2]){
			case 8: 
				LED1_Turn();
				break;
			case 9: 
				LED2_Turn();
				break;
			case 10: 
				LED3_Turn();
				break;
			case 11: 
				LED4_Turn();
				break;
			case 12: 
				LED5_Turn();
				break;
			case 13: 
				LED6_Turn();
				break;
			case 14: 
				LED7_Turn();
				break;
			case 15: 
				LED8_Turn();
				break;
		}
	}
				
				if(a[0] != -1){
					if(a[1] != -1){
						if(a[2] != -1){
							pla = 3;
						}
						else pla = 2;
					}
					else pla = 1;
					display1(pla);
				}
				/*
		if(CountSensor_Get() == 4){
		LED1_Turn();
		Delay_ms(10000);
		}
		*/
		if(delayCount==4) delayCount=0;
	}
}
/*显示函数*/
void display1(int Place){
	OLED_ShowString(1, 1, "Place:");
	OLED_ShowNum(1, 7, Place,1);
	OLED_ShowString(2, 1, "Time:");
	OLED_ShowNum(2, 6, time[0],2);
	OLED_ShowChar(2, 8, ':');
	OLED_ShowNum(2, 9, time[1],2);
	OLED_ShowChar(2, 11, ':');
	OLED_ShowNum(2, 12, time[2], 2);
}

/*微秒计时函数*/
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Num ++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
