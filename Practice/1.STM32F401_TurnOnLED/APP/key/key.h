#ifndef _key_H
#define _key_H


#include "system.h"
 
#define KEY1_PIN   			GPIO_Pin_0    	//����KEY0�ܽ�
#define KEY2_PIN    		GPIO_Pin_1    	//����KEY1�ܽ�
#define KEY3_PIN    		GPIO_Pin_2    	//����KEY2�ܽ�
#define KEY4_PIN    		GPIO_Pin_3    	//����KEY3�ܽ�
#define KEY5_PIN    		GPIO_Pin_4    	//����KEY4�ܽ�
#define KEY6_PIN    		GPIO_Pin_5    	//����KEY5�ܽ�
#define KEY7_PIN    		GPIO_Pin_6    	//����KEY6�ܽ�
#define KEY8_PIN    		GPIO_Pin_7    	//����KEY7�ܽ�

#define KEY_PORT 			GPIOE 		//����˿�

//ʹ��λ��������

#define KEY_UP	PAin(0)
#define KEY8 	PEin(0)
#define KEY7 	PEin(1)
#define KEY6 	PEin(2)
#define KEY5 	PEin(3)
#define KEY4 	PEin(4)
#define KEY3 	PEin(5)
#define KEY2 	PEin(6)
#define KEY1 	PEin(7)

//�����������ֵ 

#define KEY_UP_PRESS  9
#define KEY1_PRESS		11
#define KEY2_PRESS		12
#define KEY3_PRESS		13
#define KEY4_PRESS		14
#define KEY5_PRESS		15
#define KEY6_PRESS		16
#define KEY7_PRESS		17
#define KEY8_PRESS		18



void KEY_Init(void);
u8 KEY_Scan(u8 mode);

#endif
