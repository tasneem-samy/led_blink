/*
 * Time.c
 *
 *  Created on: Dec 25, 2018
 *      Author: tasneem samy
 */


#include "Time.h"

volatile int counter = 0;
volatile unsigned int ticks;
void delay_ms(unsigned int ms_time){
	RCC_DeInit();	//initialize the clock to internal
	SystemCoreClockUpdate();  //update system clock variable
	ticks = ms_time / (1000.0/SystemCoreClock);	//calculate the number of CLK ticks to cover the requested time
	if(ticks < SysTick_LOAD_RELOAD_Msk){
		counter = 1;
		SysTick_Config(ticks);
		while(counter > 0);
	}
	else{
		counter = ticks / SysTick_LOAD_RELOAD_Msk;
		SysTick_Config(SysTick_LOAD_RELOAD_Msk);
		while(counter > 0);
	}
}

void delay_us(unsigned int us_time){
	RCC_DeInit();	//initialize the clock to internal
	SystemCoreClockUpdate();  //update system clock variable
	ticks = us_time / (1000000.0/SystemCoreClock);	//calculate the number of CLK ticks to cover the requested time
	if(ticks < SysTick_LOAD_RELOAD_Msk){
		counter = 1;
		SysTick_Config(ticks);
		while(counter > 0);
	}
	else{
		counter = ticks / SysTick_LOAD_RELOAD_Msk;
		SysTick_Config(SysTick_LOAD_RELOAD_Msk);
		while(counter > 0);
	}
}

void SysTick_Handler(void)
{
	counter --;
}
