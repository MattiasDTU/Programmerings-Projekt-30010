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
// Function to push buffer to LCD (assuming this function is already defined)
const char character_data[95][5] = {
  {0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x5F, 0x5F, 0x00, 0x00},
  {0x00, 0x07, 0x00, 0x07, 0x00},
  {0x14, 0x7F, 0x14, 0x7F, 0x14},
  {0x24, 0x2A, 0x7F, 0x2A, 0x12},
  {0x23, 0x13, 0x08, 0x64, 0x62},
  {0x36, 0x49, 0x55, 0x22, 0x50},
  {0x00, 0x05, 0x03, 0x00, 0x00},
  {0x00, 0x1C, 0x22, 0x41, 0x00},
  {0x00, 0x41, 0x22, 0x1C, 0x00},
  {0x14, 0x08, 0x3E, 0x08, 0x14},
  {0x08, 0x08, 0x3E, 0x08, 0x08},
  {0x00, 0x50, 0x30, 0x00, 0x00},
  {0x08, 0x08, 0x08, 0x08, 0x08},
  {0x00, 0x60, 0x60, 0x00, 0x00},
  {0x20, 0x10, 0x08, 0x04, 0x02},
  {0x3E, 0x51, 0x49, 0x45, 0x3E},
  {0x00, 0x42, 0x7F, 0x40, 0x00},
  {0x42, 0x61, 0x51, 0x49, 0x46},
  {0x22, 0x49, 0x49, 0x49, 0x36},
  {0x18, 0x14, 0x12, 0x7F, 0x10},
  {0x2F, 0x49, 0x49, 0x49, 0x31},
  {0x3E, 0x49, 0x49, 0x49, 0x32},
  {0x03, 0x01, 0x71, 0x09, 0x07},
  {0x36, 0x49, 0x49, 0x49, 0x36},
  {0x26, 0x49, 0x49, 0x49, 0x3E},
  {0x00, 0x36, 0x36, 0x00, 0x00},
  {0x00, 0x56, 0x36, 0x00, 0x00},
  {0x08, 0x14, 0x22, 0x41, 0x00},
  {0x14, 0x14, 0x14, 0x14, 0x14},
  {0x00, 0x41, 0x22, 0x14, 0x08},
  {0x02, 0x01, 0x51, 0x09, 0x06},
  {0x32, 0x49, 0x79, 0x41, 0x3E},
  {0x7C, 0x0A, 0x09, 0x0A, 0x7C},
  {0x7F, 0x49, 0x49, 0x49, 0x36},
  {0x3E, 0x41, 0x41, 0x41, 0x22},
  {0x7F, 0x41, 0x41, 0x41, 0x3E},
  {0x7F, 0x49, 0x49, 0x49, 0x41},
  {0x7F, 0x09, 0x09, 0x09, 0x01},
  {0x3E, 0x41, 0x49, 0x49, 0x7A},
  {0x7F, 0x08, 0x08, 0x08, 0x7F},
  {0x00, 0x41, 0x7F, 0x41, 0x00},
  {0x30, 0x40, 0x40, 0x40, 0x3F},
  {0x7F, 0x08, 0x14, 0x22, 0x41},
  {0x7F, 0x40, 0x40, 0x40, 0x40},
  {0x7F, 0x02, 0x0C, 0x02, 0x7F},
  {0x7F, 0x02, 0x04, 0x08, 0x7F},
  {0x3E, 0x41, 0x41, 0x41, 0x3E},
  {0x7F, 0x09, 0x09, 0x09, 0x06},
  {0x3E, 0x41, 0x51, 0x21, 0x5E},
  {0x7F, 0x09, 0x09, 0x09, 0x76},
  {0x26, 0x49, 0x49, 0x49, 0x32},
  {0x01, 0x01, 0x7F, 0x01, 0x01},
  {0x3F, 0x40, 0x40, 0x40, 0x3F},
  {0x1F, 0x20, 0x40, 0x20, 0x1F},
  {0x3F, 0x40, 0x38, 0x40, 0x3F},
  {0x63, 0x14, 0x08, 0x14, 0x63},
  {0x03, 0x04, 0x78, 0x04, 0x03},
  {0x61, 0x51, 0x49, 0x45, 0x43},
  {0x7F, 0x41, 0x41, 0x00, 0x00},
  {0x02, 0x04, 0x08, 0x10, 0x20},
  {0x00, 0x41, 0x41, 0x7F, 0x00},
  {0x04, 0x02, 0x01, 0x02, 0x04},
  {0x40, 0x40, 0x40, 0x40, 0x40},
  {0x00, 0x01, 0x02, 0x04, 0x00},
  {0x20, 0x54, 0x54, 0x54, 0x78},
  {0x7F, 0x48, 0x44, 0x44, 0x38},
  {0x38, 0x44, 0x44, 0x44, 0x20},
  {0x38, 0x44, 0x44, 0x48, 0x7F},
  {0x38, 0x54, 0x54, 0x54, 0x18},
  {0x08, 0x7E, 0x09, 0x01, 0x02},
  {0x0C, 0x52, 0x52, 0x52, 0x3E},
  {0x7F, 0x08, 0x04, 0x04, 0x78},
  {0x00, 0x44, 0x7D, 0x40, 0x00},
  {0x20, 0x40, 0x44, 0x3D, 0x00},
  {0x7F, 0x10, 0x28, 0x44, 0x00},
  {0x00, 0x41, 0x7F, 0x40, 0x00},
  {0x7C, 0x04, 0x18, 0x04, 0x78},
  {0x7C, 0x08, 0x04, 0x04, 0x78},
  {0x38, 0x44, 0x44, 0x44, 0x38},
  {0x7C, 0x14, 0x14, 0x14, 0x08},
  {0x08, 0x14, 0x14, 0x18, 0x7C},
  {0x7C, 0x08, 0x04, 0x04, 0x08},
  {0x48, 0x54, 0x54, 0x54, 0x20},
  {0x04, 0x3F, 0x44, 0x40, 0x20},
  {0x3C, 0x40, 0x40, 0x20, 0x7C},
  {0x1C, 0x20, 0x40, 0x20, 0x1C},
  {0x3C, 0x40, 0x38, 0x40, 0x3C},
  {0x44, 0x28, 0x10, 0x28, 0x44},
  {0x0C, 0x50, 0x50, 0x50, 0x3C},
  {0x44, 0x64, 0x54, 0x4C, 0x44},
  {0x00, 0x08, 0x36, 0x41, 0x00},
  {0x00, 0x00, 0x7F, 0x00, 0x00},
  {0x00, 0x41, 0x36, 0x08, 0x00},
  {0x08, 0x04, 0x08, 0x10, 0x08}};

//Resets the LCD and writes the input string on line number:
void lcd_resetwrite(const char* input_string, int line_number) {
    //Checks for errors on line number
    if (line_number < 1 || line_number > 4) {
    	return;
    }

    // Creates the array in which the characters are stored
    uint8_t buffer[512]; //128(pixels wide) * 4 (lines) = 512
    //Puts 0's in each element in the buffer
    memset(buffer,0x00,512);

    //Finds the index based on the line number
    int buffer_index = (line_number - 1) * 128;

    //Looks through each letter in the input string
    while (*input_string) {
        //Finds the index in the charactermap
        int char_index = *input_string - 32;
        //Making sure the letter wont go out of index
        if (buffer_index>120){
        	if (buffer_index<128) {
        		buffer_index = 128;
        	}
        }
        //Puts the characters in the array based on hexadecimal
        for (int i = 0; i < 5; i++) {

            buffer[buffer_index++] = character_data[char_index][i];
        }

        //Puts a space between characters
        buffer[buffer_index++] = 0x00;

        //Go to the next letter in the string
        input_string++;
    }

    //Pushing the buffer to the LCD
    lcd_push_buffer(buffer);
}

//Writes the string at given line and index without resetting the LCD
void lcd_write_index(const char* input_string, int line_number, int index) {
	//Checks for errors on line number
		    if (line_number < 1 || line_number > 4) {
		        // Handle error or choose a default line
		        return;
		    }

		    // Set the cursor position based on the line_number

		    // Creates the array in which the characters are stored
		    uint8_t buffer[512]; //128(pixels wide) * 4 (lines) = 512


		    //Checks the buffer for existing data, else put 0
		    for (int i = 0; i < sizeof(buffer); i++) {
		    	if (buffer[i] != 0) {;}
		    	else {
		    		buffer[i] = 0x00;
		    }

		    //Finds the buffer index based on the line number and index
		    int buffer_index = (line_number - 1) * 128+index;

		    //Looks through each letter in the input string
		    while (*input_string) {
		    	//Finds the index in the charactermap
		        int char_index = *input_string - 32;

		        //Puts the characters in the array based on hexadecimal
		        for (int i = 0; i < 5; i++) {
		            buffer[buffer_index++] = character_data[char_index][i];
		        }

		        //Puts a space between characters
		        buffer[buffer_index++] = 0x00;

		        //Go to the next letter in the string
		        input_string++;
		    }

		    //Pushing the buffer to the LCD
		    lcd_push_buffer(buffer);
		}
}

void level_lcd(int level, int globalLives, int globalPoints) {
	uint8_t array[512];
	memset(array,0x00,512);

	int index = 45;
	char* leveltext = "Level";

//Writing Level
	while (*leveltext) {
      //Finds the index
	   int char_index = *leveltext - 32;
	    //Puts the characters in the array based on hexadecimal
	   for (int i = 0; i < 5; i++) {
		   array[index++] = character_data[char_index][i];
	   }

	   //Puts a space between the characters
	   array[index++] = 0x00;

	   //Go to the next character
        leveltext++;
			    }

//Writing the level number
		char buffernum[20];
		sprintf(buffernum,"%d",level);
			switch (buffernum[0]) {
			case '0' ... '9':
				index++;
			for (int i = 0; i<5;i++) {
				array[index++]=character_data[buffernum[0]-32][i];

			}

			}

//Writing "Lives:" and "Score:"
		char* livestext = "Lives:";
		index = 128;
		while (*livestext) {
		//Finding the index in charactermap
		int charindex = *livestext-32;
			for (int i = 0; i<5;i++) {
				array[index++]=character_data[charindex][i];
			}
		//Making a space between the characters:
		array[index++]=0x00;

		//Taking the next letter:
		livestext++;
	}

	char* scoretext = "Score:";
	index = 220;
	while (*scoretext) {
	int charindex = *scoretext-32;
		for (int i = 0; i<5;i++) {
			array[index++]=character_data[charindex][i];
		}
		//Creating a space between the characters:
		array[index++]=0x00;
		//Taking the next letter in the text
		scoretext++;
	}


//Sending number of lives left to LCD
	//Doing each line on their own and *9 for each heart required
	for(int i=0;i<globalLives;i++) {
		array[256+9*i]=0x0;
		array[257+9*i]=0xC;
		array[258+9*i]=0x1E;
		array[259+9*i]=0x03E;
		array[260+9*i]=0x7C;
		array[261+9*i]=0x3E;
		array[262+9*i]=0x1E;
		array[263+9*i]=0xC;
		array[264+9*i]=0x0;
		}
//Writing the score which updates
	char buffer[20];
	sprintf(buffer,"%d", globalPoints);
	index = 360;
	for (int i = 0;i<3;i++) {
		switch (buffer[i]){
		case '0' ... '9':
		for (int j = 0;j<5;j++) {
			array[index++]=character_data[buffer[i]-32][j];

			}
		index++;
		break;
			default:
				break;
		}
	}

	lcd_push_buffer(array);
}
//Void function used to turn on/off the LED on the microcontroller with an integer as input
//
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

