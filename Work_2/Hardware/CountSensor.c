#include "stm32f10x.h"                  // Device header

uint16_t CountSensor_Count;
uint16_t place;
void CountSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_14|GPIO_Pin_15; //����ж�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource4);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource8); //����AFIO����ѡ������ѡ���ж�����
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource15);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line4 | EXTI_Line8 | EXTI_Line14 | GPIO_Pin_15;								//�����ж���
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;									//�����ж�
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;				//�ж�ģʽ
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//�������أ��½���
	EXTI_Init(&EXTI_InitStructure);
	
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);					//��Ϊ���ȼ����ܻ��ͻ����ѡ�����ȼ�����
																													//��ͬͨ�����ò�ͬ���ȼ�
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;		//ָ��ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;		//ָ��ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;		//ָ��ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//��ռ���ȼ�
	NVIC_Init(&NVIC_InitStructure);
}

uint16_t CountSensor_Get(void)		
{
	return CountSensor_Count; //������Ҫ�����Ķ˿�
}

void EXTI15_10_IRQHandler(void)		//�жϺ���
{
	if (EXTI_GetITStatus(EXTI_Line15) == SET)			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
	{
		CountSensor_Count = 15;
		EXTI_ClearITPendingBit(EXTI_Line15);			//����жϱ�־λ
	}
	
		if (EXTI_GetITStatus(EXTI_Line14) == SET)			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
	{
		CountSensor_Count = 14;
		EXTI_ClearITPendingBit(EXTI_Line14);			//����жϱ�־λ
	}
	
}

void EXTI9_5_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line8) == SET)			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
	{
		CountSensor_Count = 8;
		EXTI_ClearITPendingBit(EXTI_Line8);			//����жϱ�־λ
	}
}
void EXTI4_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line4) == SET)			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
	{
		CountSensor_Count  = 4 ;
		EXTI_ClearITPendingBit(EXTI_Line4);			//����жϱ�־λ
}
}
