#include "stm32f10x.h"                  // Device header

uint16_t CountSensor_Count;
uint16_t place;
void CountSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; //多口中断
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource8); //配置AFIO数据选择器，选择中断引脚
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource9);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource10);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource11);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource12);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource13);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource15);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line8 | EXTI_Line9 | EXTI_Line10 | EXTI_Line11 | EXTI_Line12 | EXTI_Line13 | EXTI_Line14 | GPIO_Pin_15;								//配置中断线
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;									//开启中断
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;				//中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//触发边沿，下降沿
	EXTI_Init(&EXTI_InitStructure);
	
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);					//因为优先级可能会冲突，而选择优先级分组，第二组是两位抢占两位响应。
																													//不同通道设置不同优先级
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;		//指定通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级 0-3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 				//响应优先级 0-3
	NVIC_Init(&NVIC_InitStructure);
	
/*
	NVIC_InitStructure.NVIC_IRQChannel = EXTI8_IRQn;		//指定通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
*/
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;		//指定通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//抢占优先级
	NVIC_Init(&NVIC_InitStructure);
}

uint16_t CountSensor_Get(void)		
{
	return CountSensor_Count; //返回需要点亮的端口
}

void EXTI15_10_IRQHandler(void)		//中断函数
{
	if (EXTI_GetITStatus(EXTI_Line15) == SET)			//中断标志位判断
	{
		CountSensor_Count = 15;
		EXTI_ClearITPendingBit(EXTI_Line15);			//清除中断标志位
	}
	
		if (EXTI_GetITStatus(EXTI_Line14) == SET)			//EXTI 10-15都可以进入，需要判断是否是14
	{
		CountSensor_Count = 14;
		EXTI_ClearITPendingBit(EXTI_Line14);			//清除中断标志位
	}
	
		if (EXTI_GetITStatus(EXTI_Line13) == SET)			//中断标志位判断
	{
		CountSensor_Count = 13;
		EXTI_ClearITPendingBit(EXTI_Line13);			//清除中断标志位
	}
	
		if (EXTI_GetITStatus(EXTI_Line12) == SET)			//中断标志位判断
	{
		CountSensor_Count = 12;
		EXTI_ClearITPendingBit(EXTI_Line12);			//清除中断标志位
	}
	
		if (EXTI_GetITStatus(EXTI_Line11) == SET)			//中断标志位判断
	{
		CountSensor_Count = 11;
		EXTI_ClearITPendingBit(EXTI_Line11);			//清除中断标志位
	}
	
		if (EXTI_GetITStatus(EXTI_Line10) == SET)			//中断标志位判断
	{
		CountSensor_Count = 10;
		EXTI_ClearITPendingBit(EXTI_Line10);			//清除中断标志位
	}
	
}

void EXTI9_5_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line8) == SET)			//EXTI 10-15都可以进入，需要判断是否是14
	{
		CountSensor_Count = 8;
		EXTI_ClearITPendingBit(EXTI_Line8);			//清除中断标志位
	}
	
	if (EXTI_GetITStatus(EXTI_Line9) == SET)			//EXTI 10-15都可以进入，需要判断是否是14
	{
		CountSensor_Count = 9;
		EXTI_ClearITPendingBit(EXTI_Line9);			//清除中断标志位
	}
	
	
}
/*
void EXTI4_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line4) == SET)			//EXTI 10-15都可以进入，需要判断是否是14
	{
		CountSensor_Count  = 4 ;
		EXTI_ClearITPendingBit(EXTI_Line4);			//清除中断标志位
}
}
*/
