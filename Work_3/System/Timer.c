#include "stm32f10x.h"                  // Device header

void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  /*����ʱ�ӣ�TIM2����APB1*/
	
	TIM_InternalClockConfig(TIM2); /*ѡ�����ڲ�ʱ������*/
	
	/*����ʱ����Ԫ
	 * ��ʱƵ�� = ʱ��Ƶ�� / ��PSC + 1��/��ARR + 1��
	 */
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; /*��������*/
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; /*���ϼ���*/
	TIM_TimeBaseInitStructure.TIM_Period = 1000 - 1;    /*ARR�趨,ȡֵ��Χ0-65535����10kƵ���£���10k����*/
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;  /*PSC�趨,ȡֵ��Χ0-65535����72MHz��Ƶ���õ�10k����Ƶ��*/
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; /*�ظ���������ֻ�и߼���ʱ�����еĹ���*/
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	/*��������ʱ�������ж�*/
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); /*���������жϵ�NVIC��ͨ·*/
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); /*NVIC���ȼ�����*/
	
	NVIC_InitTypeDef NVIC_InitStructure;
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
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update); //�����־λ
	}
}
*/
