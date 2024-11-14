
//All includes for LED.c
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


void LED(int colour){
	/*Colour table for LED on microcontroller
	| Red     1
	| Green   2
	| Blue    3
	| Cyan    4
	| Yellow  5
	| Purple  6
	| White   7
	| Off     8
	*/

	switch (colour) {
	case 1: //Red
		RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
		GPIOB->ODR &= ~(1<<4);
		GPIOB->BSRR &= ~(1<<4);
		GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
		GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOB->OTYPER &= ~(0x0001 << (4 * 1)); // Clear output type register
		GPIOB->OTYPER |= (0x0000 << (4)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
		GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOB->ODR |= (0 << 4);
		GPIOB->BSRR |= (0 << 4);
		break;
	case 2: //Green
		RCC->AHBENR |= RCC_AHBPeriph_GPIOC;
		GPIOC->ODR &= ~(1<<7);
		GPIOC->BSRR &= ~(1<<7);
		GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
		GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOC->OTYPER &= ~(0x0001 << (7 * 1)); // Clear output type register
		GPIOC->OTYPER |= (0x0000 << (7)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOC->ODR |= (0 << 7);
		GPIOC->BSRR |= (0 << 7);
		break;
	case 3: //Blue
		RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
		GPIOA->ODR &= ~(1<<9);
		GPIOA->BSRR &= ~(1<<9);
		GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
		GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOA->OTYPER &= ~(0x0001 << (9 * 1)); // Clear output type register
		GPIOA->OTYPER |= (0x0000 << (9)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
		GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOA->ODR |= (0 << 9);
		GPIOA->BSRR |= (0 << 9);
		break;
	case 4: //Cyan
		//Activating Blue
		RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
		GPIOA->ODR &= ~(1<<9);
		GPIOA->BSRR &= ~(1<<9);
		GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
		GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOA->OTYPER &= ~(0x0001 << (9 * 1)); // Clear output type register
		GPIOA->OTYPER |= (0x0000 << (9)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
		GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOA->ODR |= (0 << 9);
		GPIOA->BSRR |= (0 << 9);

		//Activating Green
		RCC->AHBENR |= RCC_AHBPeriph_GPIOC;
		GPIOC->ODR &= ~(1<<7);
		GPIOC->BSRR &= ~(1<<7);
		GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
		GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOC->OTYPER &= ~(0x0001 << (7 * 1)); // Clear output type register
		GPIOC->OTYPER |= (0x0000 << (7)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOC->ODR |= (0 << 7);
		GPIOC->BSRR |= (0 << 7);
		break;
	case 5: //Yellow
		//Activating Green
		RCC->AHBENR |= RCC_AHBPeriph_GPIOC;
		GPIOC->ODR &= ~(1<<7);
		GPIOC->BSRR &= ~(1<<7);
		GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
		GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOC->OTYPER &= ~(0x0001 << (7 * 1)); // Clear output type register
		GPIOC->OTYPER |= (0x0000 << (7)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOC->ODR |= (0 << 7);
		GPIOC->BSRR |= (0 << 7);

		//Activating Red
		RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
		GPIOB->ODR &= ~(1<<4);
		GPIOB->BSRR &= ~(1<<4);
		GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
		GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOB->OTYPER &= ~(0x0001 << (4 * 1)); // Clear output type register
		GPIOB->OTYPER |= (0x0000 << (4)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
		GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOB->ODR |= (0 << 4);
		GPIOB->BSRR |= (0 << 4);
		break;
	case 6: //Purple
		//Activating Red
		RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
		GPIOB->ODR &= ~(1<<4);
		GPIOB->BSRR &= ~(1<<4);
		GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
		GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOB->OTYPER &= ~(0x0001 << (4 * 1)); // Clear output type register
		GPIOB->OTYPER |= (0x0000 << (4)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
		GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOB->ODR |= (0 << 4);
		GPIOB->BSRR |= (0 << 4);

		//Activating Blue
		RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
		GPIOA->ODR &= ~(1<<9);
		GPIOA->BSRR &= ~(1<<9);
		GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
		GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOA->OTYPER &= ~(0x0001 << (9 * 1)); // Clear output type register
		GPIOA->OTYPER |= (0x0000 << (9)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
		GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOA->ODR |= (0 << 9);
		GPIOA->BSRR |= (0 << 9);
		break;

	case 7: //White
		//Activating Blue
		RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
		GPIOA->ODR &= ~(1<<9);
		GPIOA->BSRR &= ~(1<<9);
		GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
		GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOA->OTYPER &= ~(0x0001 << (9 * 1)); // Clear output type register
		GPIOA->OTYPER |= (0x0000 << (9)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
		GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOA->ODR |= (0 << 9);
		GPIOA->BSRR |= (0 << 9);

		//Activating Green
		RCC->AHBENR |= RCC_AHBPeriph_GPIOC;
		GPIOC->ODR &= ~(1<<7);
		GPIOC->BSRR &= ~(1<<7);
		GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
		GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOC->OTYPER &= ~(0x0001 << (7 * 1)); // Clear output type register
		GPIOC->OTYPER |= (0x0000 << (7)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOC->ODR |= (0 << 7);
		GPIOC->BSRR |= (0 << 7);

		//Activating Red
		RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
		GPIOB->ODR &= ~(1<<4);
		GPIOB->BSRR &= ~(1<<4);
		GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
		GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOB->OTYPER &= ~(0x0001 << (4 * 1)); // Clear output type register
		GPIOB->OTYPER |= (0x0000 << (4)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
		GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
		GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOB->ODR |= (0 << 4);
		GPIOB->BSRR |= (0 << 4);
		break;
		//Turning them off
	case 8:
		RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
		GPIOA->ODR |= (1<<9);
		GPIOA-> BSRR |= (1<<9);

		RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
		GPIOB->ODR |= (1<<4);
		GPIOB->BSRR |= (1<<4);

		RCC->AHBENR |= RCC_AHBPeriph_GPIOC;
		GPIOC->ODR |= (1<<7);
		GPIOC->BSRR |= (1<<7);
		break;
	default:
		break;
	}

}
