#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"

/*��ʼ��LED��Ӧ��GPIO */
#define LED1_GPIO_PORT    	GPIOC		              /* GPIO�˿� */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN				GPIO_Pin_0			        

#define LED2_GPIO_PORT    	GPIOC			              /* GPIO�˿� */
#define LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define LED2_GPIO_PIN				GPIO_Pin_1			        

#define LED3_GPIO_PORT    	GPIOC		              /* GPIO�˿� */
#define LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define LED3_GPIO_PIN				GPIO_Pin_2

#define LED4_GPIO_PORT    	GPIOC		              /* GPIO�˿� */
#define LED4_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO�˿�ʱ�� */
#define LED4_GPIO_PIN				GPIO_Pin_3

#define ON  0
#define OFF 1

/* ʹ�ñ�׼�Ĺ̼������IO*/
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)

#define LED4(a)	if (a)	\
					GPIO_SetBits(LED4_GPIO_PORT,LED4_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED4_GPIO_PORT,LED4_GPIO_PIN)
					
/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 /*���Ϊ�ߵ�ƽ����p��Ϊָ��ָ��32λ��λ�Ĵ���BSRR	*/	
#define digitalLo(p,i)		 {p->BRR=i;}	 /*����͵�ƽ����p��Ϊָ��ָ��16λ��λ�Ĵ���BRR����LED2_GPIO_PIN��ֵ������*/
#define digitalToggle(p,i) {p->ODR ^=i;} /*�����ת״̬����p��Ϊָ��ָ������Ĵ���ODR��	   */


/* �������IO�ĺ� */
#define LED1_TOGGLE		 digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		   digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			   digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2_TOGGLE		 digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF		   digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			   digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3_TOGGLE		 digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF		   digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_ON			   digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)

#define LED4_TOGGLE		 digitalToggle(LED4_GPIO_PORT,LED4_GPIO_PIN)
#define LED4_OFF		   digitalHi(LED4_GPIO_PORT,LED4_GPIO_PIN)
#define LED4_ON			   digitalLo(LED4_GPIO_PORT,LED4_GPIO_PIN)

void LED_GPIO_Config(void);

#endif
