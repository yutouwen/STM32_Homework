#include "TempSet.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "OLED.h" 
#include "adc.h"
#include "T_Adc.h"
#include "led.h"
#include "usart.h"

int recTimes = 0;
u16 temp_flu = 0;
u16 temp_set = 0;
void tempUpdate(void);
 
 int main(void)
 {	 
  u16 adcx;
	float temp;
	short temp_env;
	int cnt = 1;
	
	 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
 	//LED_Init();			     //LED�˿ڳ�ʼ��		 	

	OLED_Init();
	//OLED_ShowString(1, 5, "WelCome");
	OLED_ShowString(2, 1, "T_fur:     C");
	OLED_ShowString(3, 1, "Input:");
	OLED_ShowString(4, 1, "T_set:     C");
	Adc_Init();		  		//ADC��ʼ��
	//OLED_ShowNum(1, 13, 1,1);
	T_Adc_Init();
	TempSet_Init();
	LED_Init();
	 	 uart_init(115200);
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_9,10);
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
		//temp_flu = adcx/3>1350?1350:adcx/3;
		OLED_ShowNum(2, 8, temp_flu,4);//��ʾ¯��0-1350
		//temp=(float)adcx*(3.3/4096);
		//adcx=temp;
		//OLED_ShowNum(2, 1, adcx,16);//��ʾ��ѹֵ
		temp-=adcx;
		temp*=1000;
		//OLED_ShowNum(4, 1, temp,16);
		temp_env=Get_Temprate();
		//OLED_ShowNum(3, 7, temp_env/100,2);
		//OLED_ShowNum(3, 10, temp_env%100,2);
		
		temp_set = check_temp();
		OLED_ShowNum(4, 8, temp_set,4);
		
		
		if(temp_set == adcx/3) {OLED_ShowString(1, 5, "T Reach    "); LED3_ON();LED2_OFF();LED1_OFF();}
		else if(temp_set > adcx/3) {OLED_ShowString(1, 1, "T_fur TOO LOW!"); 	LED1_ON();LED2_OFF();LED3_OFF();}
		else if(temp_set < adcx/3) {OLED_ShowString(1, 1, "T_fur TOO High");LED2_ON();LED1_OFF();LED3_OFF();}
		
		delay_ms(250);	
		
		//���յ������ݣ�ֻ�������趨���¶�ֵ,δ����
		if(USART_RX_STA&0x8000)  tempUpdate();
	}
 }
 
 
 //�¶ȸ��£�1�����趨�¶ȣ�2����¯��
 	void tempUpdate(void){
		int len = 0;
		int T = 0;
			int t;
			int attribute;
	len=USART_RX_STA&0x3fff;
	//OLED_ShowNum(3, 8, len,1);
			
			attribute = (int)USART_RX_BUF[len-1]; //��־λ
		//OLED_ShowNum(3, 8, (int)USART_RX_BUF[1],1);
			for(t=0;t<len-1;t++) //����4λ�¶�����
			{
				//OLED_ShowNum(3, t+7, (int)USART_RX_BUF[t],1);
				T*=10;
				T += (int)USART_RX_BUF[t];
				
				//USART_SendData(USART1, USART_RX_BUF[t]);//�򴮿�1��������
				//while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
			}
			//OLED_ShowNum(4, 16, ++recTimes,1);
			//OLED_ShowNum(3, 12, T,5);
			if(attribute==1){
				temp_set = T;
				updateT(T);
			}
			else if(attribute==2) temp_flu = T;
			
			//++recTimes;
			USART_RX_STA=0;
	}

