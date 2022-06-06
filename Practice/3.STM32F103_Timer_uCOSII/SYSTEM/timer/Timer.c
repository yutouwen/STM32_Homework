#include "stm32f10x.h"                  // Device header
#include "OLED.h" 

static u16 time = 0;
void Timer_Init(void)
{
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  /*����ʱ�ӣ�TIM2����APB1*/
	
	TIM_InternalClockConfig(TIM2); /*ѡ�����ڲ�ʱ������*/
	
	/*����ʱ����Ԫ
	 * ��ʱƵ�� = ʱ��Ƶ�� / ��PSC + 1��/��ARR + 1��
	 */

	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; /*��������*/
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; /*���ϼ���*/
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;    /*ARR�趨,ȡֵ��Χ0-65535����10kƵ���£���10k���� 1000*/
	TIM_TimeBaseInitStructure.TIM_Prescaler = 210 - 1;  /*PSC�趨,ȡֵ��Χ0-65535����72MHz��Ƶ���õ�10k����Ƶ�� 7200*/
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; /*�ظ���������ֻ�и߼���ʱ�����еĹ���*/
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	/*��������ʱ�������ж�*/
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); /*���������жϵ�NVIC��ͨ·*/
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); /*NVIC���ȼ�����*/
	

	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; /*��ʱ��2���ж�ͨ��*/
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  /*��ռ���ȼ�*/
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; /*��Ӧ���ȼ�*/
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
}

/*
 *�����жϺ���
 *���ڱ������ļ� ��Ҫ����extern�������ƶ�����������
*/
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		OLED_ShowNum(2,1,time++,6);
		OLED_ShowNum(3,5,time%60,2); //ms
		OLED_ShowNum(3,3,time/60,2); //s
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update); //�����־λ
	}
}

