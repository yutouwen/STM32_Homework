#include "led.h"

/*******************************************************************************
* �� �� ��         : LED_Init
* ��������		   : LED��ʼ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void LED_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //ʹ�ܶ˿�Fʱ��
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE); //ʹ�ܶ˿�Fʱ��
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT; //���ģʽ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;//�ܽ�����F9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//�ٶ�Ϊ100M
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//�������,���ʹ�ÿ�©�������ʹ�øߵ�ƽ����Ҫ���ⲿ����������
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//����������С����ߵ����������
	//GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_DOWN;
	GPIO_Init(GPIOD,&GPIO_InitStructure); //��ʼ���ṹ��
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
