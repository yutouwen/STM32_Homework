#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "includes.h"
#include "OLED.h" 
#include "Timer.h"
//ALIENTEK miniSTM32������ʵ��1
//�����ʵ��  ǿ����ֲuCOSII
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾

//START ����
//�����������ȼ�
#define START_TASK_PRIO			10  ///��ʼ��������ȼ�Ϊ���
//���������ջ��С
#define START_STK_SIZE			128
//���������ջ
OS_STK START_TASK_STK[START_STK_SIZE];
//������
void start_task(void *pdata);

//LED0����
//�����������ȼ�
#define LED0_TASK_PRIO			7
//���������ջ��С
#define LED0_STK_SIZE			64
//�����ջ
OS_STK LED0_TASK_STK[LED0_STK_SIZE];
//������
void led0_task(void *pdata);

//LED1����
//�����������ȼ�
#define LED1_TASK_PRIO			6
//���������ջ��С
#define LED1_STK_SIZE			64
//�����ջ
OS_STK LED1_TASK_STK[LED1_STK_SIZE];
//������
void led1_task(void *pdata);

//�����������
#define CLOCK_TASK_PRIO			5
//���������ջ��С
#define CLOCK_STK_SIZE			128
//�����ջ
//���������ʹ��printf����ӡ�������ݵĻ�һ��Ҫ8�ֽڶ���
OS_STK CLOCK_TASK_STK[CLOCK_STK_SIZE]; 
//������
void clock_task(void *pdata);

 int main(void)
 {	
	 
	delay_init();	    	 //��ʱ������ʼ��	  
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�жϷ�������
	 uart_init(115200); //���ڲ���������
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	 OLED_Init();
	OLED_ShowString(1, 5, "WelCome");
	 
	 Timer_Init();

	 OSInit();		//��ʼ��UCOSIII
	OSTaskCreate(start_task,(void*)0,(OS_STK*)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO); //������ʼ����
	OSStart(); 	//��ʼ����
	 }
 
	 
//��ʼ����
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr=0;
	pdata=pdata;
	OSStatInit();  //����ͳ������
	
	OS_ENTER_CRITICAL();  //�����ٽ���(�ر��ж�)
	OSTaskCreate(led0_task,(void*)0,(OS_STK*)&LED0_TASK_STK[LED0_STK_SIZE-1],LED0_TASK_PRIO);//����LED0����
	OSTaskCreate(led1_task,(void*)0,(OS_STK*)&LED1_TASK_STK[LED1_STK_SIZE-1],LED1_TASK_PRIO);//����LED1����
	OSTaskCreate(clock_task,(void*)0,(OS_STK*)&CLOCK_TASK_STK[CLOCK_STK_SIZE-1],CLOCK_TASK_PRIO);//���������������
	OSTaskSuspend(START_TASK_PRIO);//����ʼ���񣬷���ʹ�ô������Դ
	OS_EXIT_CRITICAL();  //�˳��ٽ���(���ж�)
}
 

//LED0����
void led0_task(void *pdata)
{
	while(1)
	{
		LED0_OFF();
		delay_ms(800); //�л����������
		LED0_ON();
		delay_ms(800);
	}
}

//LED1����
void led1_task(void *pdata)
{
	while(1)
	{
		LED10_OFF();
		LED8_ON();
		delay_ms(300);
		LED8_OFF();
		LED9_ON();
		delay_ms(300);
		LED9_OFF();
		LED10_ON();
		delay_ms(300);
	}
}

//�����������
void clock_task(void *pdata)
{
	OS_CPU_SR cpu_sr=0;
	
	//��ʼ����ʱ��
	
	
	while(1)
	{

		OS_ENTER_CRITICAL();	//�����ٽ���(�ر��ж�)
		
		OS_EXIT_CRITICAL();		//�˳��ٽ���(���ж�)
		delay_ms(500);
	}
}

	/*							 
	while(1)
	{
		LED0_ON();
		LED1_OFF();
		delay_ms(300);
		LED1_ON();
		LED0_OFF();
		delay_ms(300);
		

		
	}

	return 0;
 }
*/
