#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8);
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void LED1_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

void LED2_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
}

void LED3_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_3) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	}
}

void LED4_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_4) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	}
}

void LED5_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_5) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	}
}

void LED6_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_6) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
	}
}

void LED7_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_7) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	}
}

void LED8_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_8) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	}
}
