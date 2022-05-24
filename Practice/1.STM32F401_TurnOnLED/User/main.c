#include "stm32f4xx.h"                  // Device header
#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "key.h"
#include "time.h"
#include "usart.h"



/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void cal (void);

int main()
{

	//RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);

	USART1_Init(9600);
//	SysTick_Init(168);
	LED_Init();
	//LED_OFF();
	
	//KEY_Init();
	//TIM4_Init(200-1,16-1);//定时器初始化，中断周期为1ms
	while(1)
	{
		//key=KEY_Scan(0);   //扫描按键
		/*
		LED0_ON();
		LED1_ON();
		LED2_ON();
		LED3_ON();
		LED4_ON();
		*/
		//GPIOD_BSRR |= (1<<16<<10);
		//GPIO_ResetBits(GPIOD,GPIO_Pin_9); 
		LED0_ON();
		cal();
		LED_OFF();
				LED1_ON();
		cal();
		LED_OFF();
				LED2_ON();
		cal();
		LED_OFF();
				LED3_ON();
		cal();
		LED_OFF();
				LED4_ON();
		cal();
		LED_OFF();
				LED5_ON();
		cal();
		LED_OFF();
				LED6_ON();
		cal();
		LED_OFF();
				LED7_ON();
		cal();
		LED_OFF();
		
	}
}

void cal (void) //计算斐波那契数列
{	 		  	  
		int dp[301] = {0};
		dp[1] = 1;
		for(int i = 0; i<100; i++){
		int i = 2;
		while(i<300){
			dp[i] = dp[i-1]+dp[i-2];
			++i;
		}
		}
} 


