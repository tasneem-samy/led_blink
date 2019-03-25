/*
 * GPIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: cisco126
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

typedef struct{
	unsigned long MODER0:2;
	unsigned long MODER1:2;
	unsigned long MODER2:2;
	unsigned long MODER3:2;
	unsigned long MODER4:2;
	unsigned long MODER5:2;
	unsigned long MODER6:2;
	unsigned long MODER7:2;
	unsigned long MODER8:2;
	unsigned long MODER9:2;
	unsigned long MODER10:2;
	unsigned long MODER11:2;
	unsigned long MODER12:2;
	unsigned long MODER13:2;
	unsigned long MODER14:2;
	unsigned long MODER15:2;
}MODER_BF;

typedef struct{
	unsigned long long AFR0:4;
	unsigned long long AFR1:4;
	unsigned long long AFR2:4;
	unsigned long long AFR3:4;
	unsigned long long AFR4:4;
	unsigned long long AFR5:4;
	unsigned long long AFR6:4;
	unsigned long long AFR7:4;
	unsigned long long AFR8:4;
	unsigned long long AFR9:4;
	unsigned long long AFR10:4;
	unsigned long long AFR11:4;
	unsigned long long AFR12:4;
	unsigned long long AFR13:4;
	unsigned long long AFR14:4;
	unsigned long long AFR15:4;
}AFR_BF;

#define MODERA ((volatile MODER_BF*)(&(GPIOA->MODER)))
#define MODERC ((volatile MODER_BF*)(&(GPIOC->MODER)))

#define AFRA ((volatile AFR_BF*)(&(GPIOA->AFR[0])))

#endif /* GPIO_GPIO_H_ */
