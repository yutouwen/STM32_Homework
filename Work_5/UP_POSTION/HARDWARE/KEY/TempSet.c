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
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; //多口中断
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

	EXTI_InitStructure.EXTI_Line = EXTI_Line5|EXTI_Line6|EXTI_Line7|EXTI_Line8|EXTI_Line9|EXTI_Line10|EXTI_Line11|EXTI_Line12|EXTI_Line13|EXTI_Line14|EXTI_Line15;								//配置中断线
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

u16 check_temp(){
	return temperatureSetting;
}

//从主函数更新一下最新温度值
void updateT(int T){
	temperatureSetting = T;
}


void EXTI15_10_IRQHandler(void){
		if (EXTI_GetITStatus(EXTI_Line10) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(5);
		EXTI_ClearITPendingBit(EXTI_Line10);			//清除中断标志位
	}
				if (EXTI_GetITStatus(EXTI_Line11) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(6);
		EXTI_ClearITPendingBit(EXTI_Line11);			//清除中断标志位
	}
						if (EXTI_GetITStatus(EXTI_Line12) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(7);
		EXTI_ClearITPendingBit(EXTI_Line12);			//清除中断标志位
	}
								if (EXTI_GetITStatus(EXTI_Line13) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(8);
		EXTI_ClearITPendingBit(EXTI_Line13);			//清除中断标志位
	}
										if (EXTI_GetITStatus(EXTI_Line14) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(9);
		EXTI_ClearITPendingBit(EXTI_Line14);			//清除中断标志位
	}
												if (EXTI_GetITStatus(EXTI_Line15) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(-1);
		EXTI_ClearITPendingBit(EXTI_Line15);			//清除中断标志位
	}

}

void EXTI9_5_IRQHandler(void){
		if (EXTI_GetITStatus(EXTI_Line5) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(0);
		EXTI_ClearITPendingBit(EXTI_Line5);			//清除中断标志位
	}
			if (EXTI_GetITStatus(EXTI_Line6) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(1);
		EXTI_ClearITPendingBit(EXTI_Line6);			//清除中断标志位
	}
				if (EXTI_GetITStatus(EXTI_Line7) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(2);
		EXTI_ClearITPendingBit(EXTI_Line7);			//清除中断标志位
	}
	if (EXTI_GetITStatus(EXTI_Line8) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(3);
		EXTI_ClearITPendingBit(EXTI_Line8);			//清除中断标志位
	}
		if (EXTI_GetITStatus(EXTI_Line9) == SET){			//EXTI 10-15都可以进入，需要判断是否是14
		checkTemp(4);
		EXTI_ClearITPendingBit(EXTI_Line9);			//清除中断标志位
	}
}

void sendT(int data){
	/* 1.转换新温度为数组
	 * 2.通过串口发送
	 */
	u16 T = data;
	u16 i = 0;
	
	u16 sendTemp[4]={0}; //四个数表示温度（倒序），第五个数
	
	while(T!=0){
		sendTemp[i]=T%10;
		T/=10;
		++i;
	}
				//四个数表示温度（倒序的发变成正序的收）
			USART_SendData(USART1, sendTemp[3]);//向串口1发送数据
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
					USART_SendData(USART1, sendTemp[2]);//向串口1发送数据
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
					USART_SendData(USART1, sendTemp[1]);//向串口1发送数据
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
					USART_SendData(USART1, sendTemp[0]);//向串口1发送数据
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);

			//OLED_ShowNum(3, 13, ++sendTimes,1); //计数结果等同于times

			USART_SendData(USART1, 0x0d);//向串口1发送数据，加上接收标志
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
			USART_SendData(USART1, 0x0a);//向串口1发送数据，加上接收标志
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
}

void checkTemp(int num){
	/*
	 *1.本函数才能调用温度发送函数，满足调用的条件有两个：1）输入了4个数字，2）输入ENTER信号
	 * 传入值应为中断对应的数字值，ENTER为-1；
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