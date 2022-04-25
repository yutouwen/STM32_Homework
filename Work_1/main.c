#include <E:\STM32\en.stsw-stm32054_v3-6-0_v3.6.0\STM32F10x_StdPeriph_Lib_V3.6.0\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x\stm32f10x.h>
#include <E:\STM32\Work_1\Libraies\STM32F10x_StdPeriph_Driver\inc\stm32f10x_gpio.h>
#include "led.h"  
#include "key.h"


void delay_ms(int time){
	int i = 0;
	while(time--){
		i = 12000;
		while(i--);
	}
}
 

int main(void){
	LED_GPIO_Config(); //调用了led.c中编写的函数
	LED1_OFF;		   //在led.h中定义过io宏，等同于digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
	LED2_OFF;		   
	LED3_OFF;
	LED4_OFF;

	Key_GPIO_Config(); //调用了key.c中编写的函数

	while(1){			//查询按键状态，按下后反转LED
	    if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON  ){
			LED1_TOGGLE;/*LED1反转*/
		} 

		if( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON  ){
			LED2_TOGGLE;/*LED2反转*/
		}		
		
		if( Key_Scan(KEY3_GPIO_PORT,KEY3_GPIO_PIN) == KEY_ON  ){
			LED3_TOGGLE;/*LED3反转*/
		}		

		if( Key_Scan(KEY4_GPIO_PORT,KEY4_GPIO_PIN) == KEY_ON  ){
			LED4_TOGGLE;/*LED4反转*/
		}
		/*delay_ms (100);*/
		/*Delay(0x FFFF);*/
	}
	return 0;
	}
