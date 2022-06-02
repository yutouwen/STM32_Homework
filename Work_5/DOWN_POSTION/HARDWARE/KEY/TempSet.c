#include "stm32f10x.h"                  // Device header

u16 temperatureSetting = 0;

void TempSet_Init(){
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_11; //����ж�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource8);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource11);
	

	EXTI_InitStructure.EXTI_Line = EXTI_Line8 | EXTI_Line11;								//�����ж���
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;									//�����ж�
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;				//�ж�ģʽ
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//�������أ��½���
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	

	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;		//ָ��ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ� 0-3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 				//��Ӧ���ȼ� 0-3
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;		//ָ��ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//��ռ���ȼ�
	NVIC_Init(&NVIC_InitStructure);
	
}

//���������¶�ֵ
u16 check_temp(){
	return temperatureSetting;
}

//������������һ�������¶�ֵ
void updateT(int T){
	temperatureSetting = T;
}

void EXTI15_10_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line11) == SET)			//�жϱ�־λ�ж�
	{
		if(temperatureSetting>0) --temperatureSetting;
		EXTI_ClearITPendingBit(EXTI_Line11);			//����жϱ�־λ
	}
}

void EXTI9_5_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line8) == SET)			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
	{
		if(temperatureSetting<1351) ++temperatureSetting;
		EXTI_ClearITPendingBit(EXTI_Line8);			//����жϱ�־λ
	}
}
