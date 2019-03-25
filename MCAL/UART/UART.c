/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: cisco126
 */
#include "UART.h"

void UART_Init(unsigned long baud){
	float USARTDIV = 0;
	int intPart, fracPart;
	/* Clocking USART2 ->APB1 */
	RCC->APB1ENR |= (RCC_APB1ENR_USART2EN);
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN);
	/* USART2 TX/RX -> PA2 (TX), PA3 (RX) */
	MODERA->MODER2 = GPIO_Mode_AF;
	MODERA->MODER3 = GPIO_Mode_AF;
	AFRA->AFR2 = GPIO_AF_USART2;
	AFRA->AFR3 = GPIO_AF_USART2;
	// Sampling default 16 -> OVER8 = 0
	// Calculate division from baud
	USARTDIV = ((SystemCoreClock) / (16.0*baud));
	intPart = (int) USARTDIV;
	fracPart = (USARTDIV - intPart) * 16;
	USART2->BRR = fracPart + intPart<<4;
	USART2->CR1 |= (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE);
}
void UART_PutC(unsigned char data){
	while(!((USART2->SR)&(USART_FLAG_TXE)));// wait until transmit is empty
	USART2->DR = data;
}
unsigned char UART_GetC(void){
	while(!((USART2->SR)&(USART_FLAG_RXNE)));// wait until data is received
		return USART2->DR;
}
void UART_PutStr(unsigned char* str){
	int ind = 0;
	while(str[ind]){
		UART_PutC(str[ind++]);
	}
}
