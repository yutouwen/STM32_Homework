#include "stm32f10x.h"                  // Device header

u16 temperatureSetting = 0;

void TempSet_Init(){
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_11; //多口中断
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource8);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource11);
	

	EXTI_InitStructure.EXTI_Line = EXTI_Line8 | EXTI_Line11;								//配置中断线
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;									//开启中断
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;				//中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//触发边沿，下降沿
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	

	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;		//指定通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级 0-3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 				//响应优先级 0-3
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;		//指定通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//抢占优先级
	NVIC_Init(&NVIC_InitStructure);
	
}

//返回最新温度值
u16 check_temp(){
	return temperatureSetting;
}

//从主函数更新一下最新温度值
void updateT(int T){
	temperatureSetting = T;
}

void EXTI15_10_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line11) == SET)			//中断标志位判断
	{
		if(temperatureSetting>0) --temperatureSetting;
		EXTI_ClearITPendingBit(EXTI_Line11);			//清除中断标志位
	}
}

void EXTI9_5_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line8) == SET)			//EXTI 10-15都可以进入，需要判断是否是14
	{
		if(temperatureSetting<1351) ++temperatureSetting;
		EXTI_ClearITPendingBit(EXTI_Line8);			//清除中断标志位
	}
}
