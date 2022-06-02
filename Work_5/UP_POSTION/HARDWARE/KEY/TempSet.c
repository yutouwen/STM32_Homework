#include "stm32f10x.h"                  // Device header
#include "OLED.h"

int cnt = 0;
int newTemp = 0;
u16 temperatureSetting = 0;
void sendT(int data);
void checkTemp(int num);

void TempSet_Init(){
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; //����ж�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource7);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource8);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource9);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource10);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource11);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource12);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource13);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource15);

	EXTI_InitStructure.EXTI_Line = EXTI_Line5|EXTI_Line6|EXTI_Line7|EXTI_Line8|EXTI_Line9|EXTI_Line10|EXTI_Line11|EXTI_Line12|EXTI_Line13|EXTI_Line14|EXTI_Line15;								//�����ж���
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

u16 check_temp(){
	return temperatureSetting;
}

//������������һ�������¶�ֵ
void updateT(int T){
	temperatureSetting = T;
}


void EXTI15_10_IRQHandler(void){
		if (EXTI_GetITStatus(EXTI_Line10) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(5);
		EXTI_ClearITPendingBit(EXTI_Line10);			//����жϱ�־λ
	}
				if (EXTI_GetITStatus(EXTI_Line11) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(6);
		EXTI_ClearITPendingBit(EXTI_Line11);			//����жϱ�־λ
	}
						if (EXTI_GetITStatus(EXTI_Line12) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(7);
		EXTI_ClearITPendingBit(EXTI_Line12);			//����жϱ�־λ
	}
								if (EXTI_GetITStatus(EXTI_Line13) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(8);
		EXTI_ClearITPendingBit(EXTI_Line13);			//����жϱ�־λ
	}
										if (EXTI_GetITStatus(EXTI_Line14) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(9);
		EXTI_ClearITPendingBit(EXTI_Line14);			//����жϱ�־λ
	}
												if (EXTI_GetITStatus(EXTI_Line15) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(-1);
		EXTI_ClearITPendingBit(EXTI_Line15);			//����жϱ�־λ
	}

}

void EXTI9_5_IRQHandler(void){
		if (EXTI_GetITStatus(EXTI_Line5) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(0);
		EXTI_ClearITPendingBit(EXTI_Line5);			//����жϱ�־λ
	}
			if (EXTI_GetITStatus(EXTI_Line6) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(1);
		EXTI_ClearITPendingBit(EXTI_Line6);			//����жϱ�־λ
	}
				if (EXTI_GetITStatus(EXTI_Line7) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(2);
		EXTI_ClearITPendingBit(EXTI_Line7);			//����жϱ�־λ
	}
	if (EXTI_GetITStatus(EXTI_Line8) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(3);
		EXTI_ClearITPendingBit(EXTI_Line8);			//����жϱ�־λ
	}
		if (EXTI_GetITStatus(EXTI_Line9) == SET){			//EXTI 10-15�����Խ��룬��Ҫ�ж��Ƿ���14
		checkTemp(4);
		EXTI_ClearITPendingBit(EXTI_Line9);			//����жϱ�־λ
	}
}

void sendT(int data){
	/* 1.ת�����¶�Ϊ����
	 * 2.ͨ�����ڷ���
	 */
	u16 T = data;
	u16 i = 0;
	
	u16 sendTemp[4]={0}; //�ĸ�����ʾ�¶ȣ����򣩣��������
	
	while(T!=0){
		sendTemp[i]=T%10;
		T/=10;
		++i;
	}
				//�ĸ�����ʾ�¶ȣ�����ķ����������գ�
			USART_SendData(USART1, sendTemp[3]);//�򴮿�1��������
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
					USART_SendData(USART1, sendTemp[2]);//�򴮿�1��������
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
					USART_SendData(USART1, sendTemp[1]);//�򴮿�1��������
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
					USART_SendData(USART1, sendTemp[0]);//�򴮿�1��������
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);

			//OLED_ShowNum(3, 13, ++sendTimes,1); //���������ͬ��times

			USART_SendData(USART1, 0x0d);//�򴮿�1�������ݣ����Ͻ��ձ�־
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
			USART_SendData(USART1, 0x0a);//�򴮿�1�������ݣ����Ͻ��ձ�־
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
}

void checkTemp(int num){
	/*
	 *1.���������ܵ����¶ȷ��ͺ�����������õ�������������1��������4�����֣�2������ENTER�ź�
	 * ����ֵӦΪ�ж϶�Ӧ������ֵ��ENTERΪ-1��
	 */
	if(num != -1){
		++cnt;
		newTemp*=10;
		newTemp += num;
		OLED_ShowNum(3, 8, newTemp,4);
	}
	if(cnt == 4 || num == -1){
		cnt = 0;
		temperatureSetting = newTemp;
		newTemp = 0;
		sendT(temperatureSetting);
	}
}