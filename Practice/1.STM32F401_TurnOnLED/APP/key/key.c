#include "key.h"
#include "SysTick.h"

/*******************************************************************************
* 函 数 名         : KEY_Init
* 函数功能		   : 按键初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量	
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE,ENABLE); //使能端口时钟
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN; //输入模式
	GPIO_InitStructure.GPIO_Pin=KEY8_PIN|KEY1_PIN|KEY2_PIN|KEY3_PIN|KEY4_PIN|KEY5_PIN|KEY6_PIN|KEY7_PIN;//管脚设置
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_DOWN;//下拉，保证非按下时状态为低电平，按下时状态为高电平
	GPIO_Init(KEY_PORT,&GPIO_InitStructure); //初始化结构体
	
	GPIO_InitStructure.GPIO_Pin=KEY_UP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

}

/*******************************************************************************
* 函 数 名         : KEY_Scan
* 函数功能		   : 按键扫描检测
* 输    入         : mode=0:单次按下按键
					 mode=1：连续按下按键
* 输    出         : 0：未有按键按下
					 KEY_UP_PRESS：KEY_UP键按下
					 KEY0_PRESS：KEY0键按下
					 KEY1_PRESS：KEY1键按下
*******************************************************************************/
u8 KEY_Scan(u8 mode)
{
	static u8 key=1;
	
	if(mode==1) //连续按键按下
		key=1;
	if(key==1&&(KEY_UP==1||KEY8==1||KEY1==1||KEY2==1||KEY3==1||KEY4==1||KEY5==1||KEY6==1||KEY7==1)) //按键已经抬起，且任意一个按键按下，即某一个为高电平
	{
//		delay_ms(10);  //消抖
		key=0;//将按键抬起状态清0
		 
		if(KEY_UP==1)
			return KEY_UP_PRESS;
		else if(KEY1==1)
			return KEY1_PRESS; 
		else if(KEY2==1)
			return KEY2_PRESS; 
		else if(KEY3==1)
			return KEY3_PRESS; 
		else if(KEY4==1)
			return KEY4_PRESS; 
		else if(KEY5==1)
			return KEY5_PRESS; 
		else if(KEY6==1)
			return KEY6_PRESS; 
		else if(KEY7==1)
			return KEY7_PRESS; 
		else if(KEY8==1)
			return KEY8_PRESS; 
		
	}
	
	return 0;
}
