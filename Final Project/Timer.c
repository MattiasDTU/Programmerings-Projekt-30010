#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "Header_file.h"

// Funktion til konfiguration af timeren
void config_timer() {
    RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
    TIM15->CR1 |= 0x01; // Enable timer 15
    TIM15->ARR = 10000; // Set reload value
    TIM15->PSC = 1000; // Set prescale value
    TIM15->DIER |= 0x0001; // Enable timer 15 interrupts
    NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0); // Set interrupt priority
    NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
}

// Afbrydelseshåndteringsfunktion for TIM15
void TIM1_BRK_TIM15_IRQHandler(void) {
    timer++;
    TIM15->SR &= ~0x0001; // Clear interrupt bit
 }
