#include "led.h"

/*******************************************************************************
* 函 数 名         : LED_Init
* 函数功能		   : LED初始化函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void LED_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //使能端口F时钟
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE); //使能端口F时钟
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT; //输出模式
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;//管脚设置F9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//速度为100M
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//推挽输出,如果使用开漏输出不能使用高电平，还要在外部接上拉电阻
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//上拉，可以小幅提高电流输出能力
	//GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_DOWN;
	GPIO_Init(GPIOD,&GPIO_InitStructure); //初始化结构体
	GPIO_SetBits(GPIOD,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
	
	//GPIO_ResetBits(GPIOD, 8);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOB,&GPIO_InitStructure); 
	GPIO_SetBits(GPIOB,GPIO_Pin_3);
}




void LED0_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_8);
}
void LED1_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_9);
}
void LED2_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_10);
}
void LED3_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_11);
}
void LED4_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_12);
}
void LED5_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_13);
}
void LED6_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_14);
}
void LED7_ON(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_15);
}

void LED9_ON(void)
{
	GPIO_ResetBits(GPIOB, 3);
}

void LED_OFF(void)
{
	GPIO_SetBits(GPIOD,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
}
