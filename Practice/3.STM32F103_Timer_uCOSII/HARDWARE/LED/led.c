#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK mini�SSTM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PA8��PD2Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PA,PD�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0| GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4| GPIO_Pin_5 | GPIO_Pin_6| GPIO_Pin_7;				 //LED0-->PA.8 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA
 GPIO_SetBits(GPIOA,GPIO_Pin_0| GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4| GPIO_Pin_5 | GPIO_Pin_6| GPIO_Pin_7);						 //PA.8 �����
//��ʼ��led�ɹ�

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA
 GPIO_SetBits(GPIOC,GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3);		
	
}
 
void LED0_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_0);
}

void LED0_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

void LED3_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
}

void LED3_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_3);
}
void LED4_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

void LED4_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}
void LED5_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
}

void LED5_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
}

void LED6_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_6);
}

void LED6_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
}
void LED7_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
}

void LED7_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_7);
}

void LED8_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_1);
}

void LED8_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_1);
}
void LED9_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_2);
}

void LED9_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_2);
}
void LED10_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_3);
}

void LED10_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_3);
}
