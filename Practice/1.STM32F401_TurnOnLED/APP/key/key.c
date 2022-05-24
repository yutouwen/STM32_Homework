#include "key.h"
#include "SysTick.h"

/*******************************************************************************
* �� �� ��         : KEY_Init
* ��������		   : ������ʼ��
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����	
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE,ENABLE); //ʹ�ܶ˿�ʱ��
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN; //����ģʽ
	GPIO_InitStructure.GPIO_Pin=KEY8_PIN|KEY1_PIN|KEY2_PIN|KEY3_PIN|KEY4_PIN|KEY5_PIN|KEY6_PIN|KEY7_PIN;//�ܽ�����
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_DOWN;//��������֤�ǰ���ʱ״̬Ϊ�͵�ƽ������ʱ״̬Ϊ�ߵ�ƽ
	GPIO_Init(KEY_PORT,&GPIO_InitStructure); //��ʼ���ṹ��
	
	GPIO_InitStructure.GPIO_Pin=KEY_UP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

}

/*******************************************************************************
* �� �� ��         : KEY_Scan
* ��������		   : ����ɨ����
* ��    ��         : mode=0:���ΰ��°���
					 mode=1���������°���
* ��    ��         : 0��δ�а�������
					 KEY_UP_PRESS��KEY_UP������
					 KEY0_PRESS��KEY0������
					 KEY1_PRESS��KEY1������
*******************************************************************************/
u8 KEY_Scan(u8 mode)
{
	static u8 key=1;
	
	if(mode==1) //������������
		key=1;
	if(key==1&&(KEY_UP==1||KEY8==1||KEY1==1||KEY2==1||KEY3==1||KEY4==1||KEY5==1||KEY6==1||KEY7==1)) //�����Ѿ�̧��������һ���������£���ĳһ��Ϊ�ߵ�ƽ
	{
//		delay_ms(10);  //����
		key=0;//������̧��״̬��0
		 
		if(KEY_UP==1)
			return KEY_UP_PRESS;
		else if(KEY1==1)
			return KEY1_PRESS; 
		else if(KEY2==1)
			return KEY2_PRESS; 
		else if(KEY3==1)
			return KEY3_PRESS; 
		else if(KEY4==1)
			return KEY4_PRESS; 
		else if(KEY5==1)
			return KEY5_PRESS; 
		else if(KEY6==1)
			return KEY6_PRESS; 
		else if(KEY7==1)
			return KEY7_PRESS; 
		else if(KEY8==1)
			return KEY8_PRESS; 
		
	}
	
	return 0;
}
