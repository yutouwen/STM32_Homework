#include "key.h"  


void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启按键端口的时钟*/
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK|KEY3_GPIO_CLK|KEY4_GPIO_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; /*选择按键的引脚 */	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; /* 设置按键的引脚为浮空输入 0x04 输入电平由外部决定  */
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);/*使用结构体初始化按键	*/
	
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
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  /*检测是否有按键按下 */
	{	 
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON); /*等待按键释放 */  
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}
