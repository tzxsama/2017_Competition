#include "main.h"

/*TIM3----CH1-----PC6*/
/*TIM3----CH2-----PC7*/
/*TIM3----CH3-----PB0*/
/*TIM3----CH4-----PB1*/
void PWM_Configuration(void)
{
    GPIO_InitTypeDef           GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef   TIM_TimeBaseStructure;
    TIM_OCInitTypeDef         TIM_OCInitStructure;
	
		TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
		TIM_OCStructInit(&TIM_OCInitStructure);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
		GPIO_PinAFConfig(GPIOD,GPIO_PinSource12,GPIO_AF_TIM4); 
	  GPIO_PinAFConfig(GPIOD,GPIO_PinSource13,GPIO_AF_TIM4); 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	
	 GPIO_Init(GPIOD, &GPIO_InitStructure); 
		
  TIM_TimeBaseStructure.TIM_Period = 1000;									
  TIM_TimeBaseStructure.TIM_Prescaler = 84-1;		
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);


  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC1Init(TIM4, &TIM_OCInitStructure);
  TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	
	TIM_CtrlPWMOutputs(TIM4, ENABLE);
  TIM_ARRPreloadConfig(TIM4, ENABLE);
  TIM_Cmd(TIM4, ENABLE);
}


