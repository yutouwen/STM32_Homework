#include "TempSet.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "OLED.h" 
#include "adc.h"
#include "T_Adc.h"
#include "led.h"

 
 int main(void)
 {	 
  u16 adcx;
	float temp;
	short temp_env;
	int cnt = 1;
	u16 temp_flu = 0;
	u16 temp_set = 0;
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
 	//LED_Init();			     //LED�˿ڳ�ʼ��		 	

	OLED_Init();
	//OLED_ShowString(1, 5, "WelCome");
	OLED_ShowString(2, 1, "T_fur:     C");
	OLED_ShowString(3, 1, "T_env:  .  C");
	OLED_ShowString(4, 1, "T_set:     C");
	Adc_Init();		  		//ADC��ʼ��
	//OLED_ShowNum(1, 13, 1,1);
	T_Adc_Init();
	TempSet_Init();
	LED_Init();
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_1,10);
		/*
		if(temp_flu != adcx){
			temp_flu = adcx;
			cnt = 1;
			while(temp_flu/=10){
				++cnt;
			}
		}
		*/
		//OLED_ShowNum(2, 13, adcx,4);//��ʾADC��ֵ 0-4096
		OLED_ShowNum(2, 8, adcx/3,4);//��ʾ¯��0-1350
		//temp=(float)adcx*(3.3/4096);
		//adcx=temp;
		//OLED_ShowNum(2, 1, adcx,16);//��ʾ��ѹֵ
		temp-=adcx;
		temp*=1000;
		//OLED_ShowNum(4, 1, temp,16);
		temp_env=Get_Temprate();
		OLED_ShowNum(3, 7, temp_env/100,2);
		OLED_ShowNum(3, 10, temp_env%100,2);
		
		temp_set = check_temp();
		OLED_ShowNum(4, 8, temp_set,4);
		
		
		if(temp_set == adcx/3) {OLED_ShowString(1, 5, "T Reach    "); LED3_ON();LED2_OFF();LED1_OFF();}
		else if(temp_set > adcx/3) {OLED_ShowString(1, 1, "T_fur TOO LOW!"); 	LED1_ON();LED2_OFF();LED3_OFF();}
		else if(temp_set < adcx/3) {OLED_ShowString(1, 1, "T_fur TOO High");LED2_ON();LED1_OFF();LED3_OFF();}
		
		delay_ms(250);	
	}
 }

