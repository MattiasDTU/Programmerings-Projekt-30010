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

// Funktion til at læse joystickens input
uint16_t Joystickport(){
// PA4 UP
RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A PA0 = 110
GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
GPIOA->MODER |= (0x00000000 << (4 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
GPIOA->PUPDR |= (0x00000002 << (4 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
uint16_t val_UP = GPIOA->IDR & (0x0001 << 4); //Read from pin PA0
if (val_UP != 0) {
	val_UP=1;
}
// PB0 DOWN
RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port A PA0 = 110
GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
GPIOB->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
GPIOB->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
uint16_t val_DOWN = GPIOB->IDR & (0x0001 << 0); //Read from pin PA0
if (val_DOWN != 0) {
	val_DOWN=1;
}
// PC0 RIGHT
RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A PA0 = 110
GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
GPIOC->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
GPIOC->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
uint16_t val_RIGHT = GPIOC->IDR & (0x0001 << 0); //Read from pin PA0
if (val_RIGHT != 0) {
	val_RIGHT=1;
}
// PC1 LEFT
RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A PA0 = 110
GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
GPIOC->MODER |= (0x00000000 << (1 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
GPIOC->PUPDR |= (0x00000002 << (1 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
uint16_t val_LEFT = GPIOC->IDR & (0x0001 << 1); //Read from pin PA0
if (val_LEFT != 0) {
	val_LEFT=1;
}
// PB5 CENTER
RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port A PA0 = 110
GPIOB->MODER &= ~(0x00000003 << (5 * 2));
GPIOB->MODER |= (0x00000000 << (5 * 2));
GPIOB->PUPDR &= ~(0x00000003 << (5 * 2));
GPIOB->PUPDR |= (0x00000002 << (1 * 2));
uint16_t val_CENTER = GPIOB->IDR & (0x0001 << 5);
if (val_CENTER != 0) {
	 val_CENTER=1;
}

int all_bits = val_CENTER + val_RIGHT + val_LEFT + val_UP + val_DOWN;
if (all_bits != 0) {
uint8_t bit[8] = {0,0,0,val_CENTER,val_RIGHT,val_LEFT,val_DOWN,val_UP};
    uint8_t result = 0;

    for (int i = 0; i < 8; i++) {
        result = (result << 1) | bit[i];
    }
    return result;
	}
return 0;
}

// Funktion til at læse keyboard input
uint8_t readKeyboard() {
    uint8_t value = 0;
    value = uart_get_char();
    if (value == 'a' || value == 's' || value == 'd' || value == 'w' || value == ' ' || value == 'x' || value == 'p') {
   return value;
    }
    return 0;
}
