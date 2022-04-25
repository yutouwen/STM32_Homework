#include "key.h"  


void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*���������˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK|KEY3_GPIO_CLK|KEY4_GPIO_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; /*ѡ�񰴼������� */	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; /* ���ð���������Ϊ�������� 0x04 �����ƽ���ⲿ����  */
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);/*ʹ�ýṹ���ʼ������	*/
	
	GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = KEY3_GPIO_PIN; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = KEY4_GPIO_PIN; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(KEY4_GPIO_PORT, &GPIO_InitStructure);	
}


uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  /*����Ƿ��а������� */
	{	 
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON); /*�ȴ������ͷ� */  
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}
