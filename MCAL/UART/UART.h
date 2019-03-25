/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: cisco126
 */

#ifndef UART_UART_H_
#define UART_UART_H_

#include "stm32f4xx.h"
#include "GPIO.h"

void UART_Init(unsigned long baud);
void UART_PutC(unsigned char data);
unsigned char UART_GetC(void);
void UART_PutStr(unsigned char* str);

#endif /* UART_UART_H_ */
