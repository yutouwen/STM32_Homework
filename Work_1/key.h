 #ifndef __KEY_H
#define	__KEY_H

#include "stm32f10x.h"

/*���Ŷ���*/
#define    KEY1_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    KEY1_GPIO_PORT    GPIOA			   
#define    KEY1_GPIO_PIN		 GPIO_Pin_0

#define    KEY2_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    KEY2_GPIO_PORT    GPIOA		   
#define    KEY2_GPIO_PIN		  GPIO_Pin_4

#define    KEY3_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    KEY3_GPIO_PORT    GPIOA			   
#define    KEY3_GPIO_PIN		 GPIO_Pin_8

#define    KEY4_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    KEY4_GPIO_PORT    GPIOA			   
#define    KEY4_GPIO_PIN		 GPIO_Pin_12


#define KEY_ON	1
#define KEY_OFF	0

void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif
