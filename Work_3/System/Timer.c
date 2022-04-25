#include "stm32f10x.h"                  // Device header

void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  /*开启时钟，TIM2属于APB1*/
	
	TIM_InternalClockConfig(TIM2); /*选择用内部时钟驱动*/
	
	/*配置时基单元
	 * 定时频率 = 时钟频率 / （PSC + 1）/（ARR + 1）
	 */
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; /*消除抖动*/
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; /*向上计数*/
	TIM_TimeBaseInitStructure.TIM_Period = 1000 - 1;    /*ARR设定,取值范围0-65535，在10k频率下，记10k个数*/
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;  /*PSC设定,取值范围0-65535，给72MHz分频，得到10k计数频率*/
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; /*重复计数器，只有高级定时器才有的功能*/
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	/*产生更新时，触发中断*/
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); /*开启更新中断到NVIC的通路*/
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); /*NVIC优先级分组*/
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; /*定时器2的中断通道*/
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  /*抢占优先级*/
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; /*响应优先级*/
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
}

/*
 *更新中断函数
 *由于变量跨文件 需要声明extern，所以移动到主函数中
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update); //清除标志位
	}
}
*/
