#include "stm32f10x.h"                  // Device header
#include "Delay.h"
//#include "OLED.h"
#include "CountSensor.h"
#include "LED.h"


int main(void)
{
	//OLED_Init();
	CountSensor_Init();
	LED_Init();
	//OLED_ShowString(1, 1, "Count:");
	
	int a[3] = {-1,-1,-1};
	int cnt = 0;
	int OldNum = CountSensor_Get();
	
	while (1)
	{
		//OLED_ShowNum(1, 7, CountSensor_Get(), 5);
		int num = CountSensor_Get(); //返回值为按键编号,按顺序写入数组
		if(num != OldNum && cnt<4 && num != a[0]&& num != a[1]) a[cnt++] = num;
		switch(a[0]){
			case 0: 
				LED1_Turn();
				Delay_ms(10000);
				break;
			case 1: 
				LED1_Turn();
				Delay_ms(10000);
				break;
			case 2: 
				LED1_Turn();
				Delay_ms(10000);
				break;
			case 3: 
				LED1_Turn();
				Delay_ms(10000);
				break;
			case 4: 
				LED1_Turn();
				Delay_ms(10000);
				break;
			case 8: 
				LED2_Turn();
				Delay_ms(10000);
				break;
		}
		switch(a[1]){
			case 0: 
				LED1_Turn();
				Delay_ms(20000);
				break;
			case 1: 
				LED1_Turn();
				Delay_ms(20000);
				break;
			case 2: 
				LED1_Turn();
				Delay_ms(20000);
				break;
			case 3: 
				LED1_Turn();
				Delay_ms(20000);
				break;
			case 4: 
				LED1_Turn();
				Delay_ms(20000);
				break;
			case 8: 
				LED2_Turn();
				Delay_ms(20000);
				break;
		}
	switch(a[2]){
			case 0: 
				LED1_Turn();
				Delay_ms(40000);
				break;
			case 1: 
				LED1_Turn();
				Delay_ms(40000);
				break;
			case 2: 
				LED1_Turn();
				Delay_ms(40000);
				break;
			case 14: 
				LED3_Turn();
				Delay_ms(40000);
				break;
			case 4: 
				LED1_Turn();
				Delay_ms(40000);
				break;
			case 8: 
				LED2_Turn();
				Delay_ms(40000);
				break;
		}
		/*
		if(CountSensor_Get() == 4){
		LED1_Turn();
		Delay_ms(10000);
		}
		*/
	}
}
