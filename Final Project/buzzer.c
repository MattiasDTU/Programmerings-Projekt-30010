#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Header_file.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
void TIM2_IRQHandler(void) {
TIM2->SR &= ~0x0001; // Clear interrupt bit
}

void inittim2() {
	//Taken from exercise 9

	RCC -> APB1ENR |= RCC_APB1Periph_TIM2 ; // Enable clock line to timer 2;
	// RCC - > AHBENR |= RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB |RCC_AHBPeriph_GPIOC ; // Enable clock for GPIO Port A
	TIM2 -> CR1 = 0; // Configure timer 2
	TIM2 -> ARR = 5000 ; // Set reload value
	TIM2 -> PSC = 300; // Set prescale value

	TIM2 -> DIER |= 0x0001 ; // Enable timer 2 interrupts
	TIM2 -> CR1 = 1;

	TIM2 -> CCER &= ~ TIM_CCER_CC3P ; // Clear CCER register
	TIM2 -> CCER |= 0x00000001 << 8; // Enable OC3 output
	TIM2 -> CCMR2 &= ~ TIM_CCMR2_OC3M ; // Clear CCMR2 register
	TIM2 -> CCMR2 &= ~ TIM_CCMR2_CC3S ;
	TIM2 -> CCMR2 |= TIM_OCMode_PWM1 ; // Set output mode to PWM1
	TIM2 -> CCMR2 &= ~ TIM_CCMR2_OC3PE ;
	TIM2 -> CCMR2 |= TIM_OCPreload_Enable ;
	TIM2 -> CCR3 = 5000 / 2; // Set duty cycle to 50 %


	RCC -> AHBENR |= RCC_AHBPeriph_GPIOB ; // Enable clock for GPIO Port B
	// Set pin Pb10 to input
	GPIOB -> MODER &= ~(0x00000003 << (10 * 2) ) ; // Clear mode register
	GPIOB -> MODER |= (0x00000002 << (10 * 2) ) ; // Set mode register (0 x00
	// Input , 0x01 - Output , 0x02 - Alternate Function , 0 x03 - Analog in/ out)
	GPIOB -> PUPDR &= ~(0x00000003 << (10 * 2) ) ; // Clear push / pull register
	GPIOB -> PUPDR |= (0x00000002 << (10 * 2) ) ; // Set push / pull register (0

	 GPIO_PinAFConfig ( GPIOB , GPIO_PinSource10 , GPIO_AF_1 ) ;

	}



void setFreq(uint16_t freq) {
	uint32_t reload = 64e6/freq/(300+1)-1;
	TIM2->ARR = reload;
	TIM2->CCR3 = reload/2;
	TIM2->EGR |= 0x01;

}


void delaysong(uint16_t milli) {

uint32_t delay = milli * 52000;
for (uint32_t i = 0; i < delay; i++) {
}
}
void playingsong(int value) {
	int FSH = 740;
	int G = 391;
	int C4 = 262;
	int D4 = 294;
	int E4 = 330;
	int F = 349;
	int A4 = 440;
	int B4 = 494;

	if (value == 0) {
		uint16_t notearray1[] = {A4,E4,A4,E4,B4,E4,B4,E4,C4,E4,C4,E4,
			 D4,E4,D4,E4};
	size_t interlength = sizeof(notearray1)/sizeof(notearray1[0]);
	//How long you want it to play
	uint16_t duration = 20;
	for (size_t i = 0; i < interlength; i++) {
			//Changes the frequency on the buzzer
		uint16_t freq = notearray1[i];
		setFreq(freq);
			  //Delays it
		delaysong(duration);
			  //Resets the frequency
		setFreq(0);
			  //Delay again until next note
		delaysong(0);
	}
	}
	else if (value == 1) {
		uint16_t notearray[] = {FSH,G,F,E4};
		size_t arraylength = sizeof(notearray)/sizeof(notearray[0]);
		uint16_t duration = 40;
	for (size_t i = 0; i < arraylength; i++) {
		//Changes the frequency on the buzzer
	uint16_t freq = notearray[i];
	setFreq(freq);
		  //Delays it
	delaysong(duration);
		  //Resets the frequency
	setFreq(0);
	}
}
}
