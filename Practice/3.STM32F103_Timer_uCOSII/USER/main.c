#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "includes.h"
#include "OLED.h" 
#include "Timer.h"
//ALIENTEK miniSTM32开发板实验1
//跑马灯实验  强行移植uCOSII
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

//START 任务
//设置任务优先级
#define START_TASK_PRIO			10  ///开始任务的优先级为最低
//设置任务堆栈大小
#define START_STK_SIZE			128
//任务任务堆栈
OS_STK START_TASK_STK[START_STK_SIZE];
//任务函数
void start_task(void *pdata);

//LED0任务
//设置任务优先级
#define LED0_TASK_PRIO			7
//设置任务堆栈大小
#define LED0_STK_SIZE			64
//任务堆栈
OS_STK LED0_TASK_STK[LED0_STK_SIZE];
//任务函数
void led0_task(void *pdata);

//LED1任务
//设置任务优先级
#define LED1_TASK_PRIO			6
//设置任务堆栈大小
#define LED1_STK_SIZE			64
//任务堆栈
OS_STK LED1_TASK_STK[LED1_STK_SIZE];
//任务函数
void led1_task(void *pdata);

//浮点测试任务
#define CLOCK_TASK_PRIO			5
//设置任务堆栈大小
#define CLOCK_STK_SIZE			128
//任务堆栈
//如果任务中使用printf来打印浮点数据的话一点要8字节对齐
OS_STK CLOCK_TASK_STK[CLOCK_STK_SIZE]; 
//任务函数
void clock_task(void *pdata);

 int main(void)
 {	
	 
	delay_init();	    	 //延时函数初始化	  
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组配置
	 uart_init(115200); //串口波特率设置
	LED_Init();		  	//初始化与LED连接的硬件接口
	 OLED_Init();
	OLED_ShowString(1, 5, "WelCome");
	 
	 Timer_Init();

	 OSInit();		//初始化UCOSIII
	OSTaskCreate(start_task,(void*)0,(OS_STK*)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO); //创建开始任务
	OSStart(); 	//开始任务
	 }
 
	 
//开始任务
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr=0;
	pdata=pdata;
	OSStatInit();  //开启统计任务
	
	OS_ENTER_CRITICAL();  //进入临界区(关闭中断)
	OSTaskCreate(led0_task,(void*)0,(OS_STK*)&LED0_TASK_STK[LED0_STK_SIZE-1],LED0_TASK_PRIO);//创建LED0任务
	OSTaskCreate(led1_task,(void*)0,(OS_STK*)&LED1_TASK_STK[LED1_STK_SIZE-1],LED1_TASK_PRIO);//创建LED1任务
	OSTaskCreate(clock_task,(void*)0,(OS_STK*)&CLOCK_TASK_STK[CLOCK_STK_SIZE-1],CLOCK_TASK_PRIO);//创建浮点测试任务
	OSTaskSuspend(START_TASK_PRIO);//挂起开始任务，放弃使用处理机资源
	OS_EXIT_CRITICAL();  //退出临界区(开中断)
}
 

//LED0任务
void led0_task(void *pdata)
{
	while(1)
	{
		LED0_OFF();
		delay_ms(800); //切换到别的任务
		LED0_ON();
		delay_ms(800);
	}
}

//LED1任务
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

//浮点测试任务
void clock_task(void *pdata)
{
	OS_CPU_SR cpu_sr=0;
	
	//初始化定时器
	
	
	while(1)
	{

		OS_ENTER_CRITICAL();	//进入临界区(关闭中断)
		
		OS_EXIT_CRITICAL();		//退出临界区(开中断)
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
