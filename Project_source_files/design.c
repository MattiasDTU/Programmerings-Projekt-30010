/*
 * design.c
 *
 *  Created on: 10. jan. 2024
 *      Author: Matti
 */
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "Header_file.h"
void hideCursor() {printf("\e[?25l");}
//Function for blinking text based on colour index, will also turn on the led for given colour
void text_color_blink(int on, int colour) {
	if (on == 1) {
		LED(colour);
		blink(1);
		switch (colour) {
		case 1:
			fgcolor(1);
			break;
		case 2:
			fgcolor(2);
			break;
		case 3:
			fgcolor(4);
			break;
		case 4:
			fgcolor(6);
			break;
		case 5:
			fgcolor(11);
			break;
		case 6:
			fgcolor(5);
			break;
		case 7:
			fgcolor(15);
			break;
		default:
			break;
		}
	}
	else if (on != 1) {
		LED(colour);
		blink(0);
		fgcolor(7);
	}
}
void credits() {
	gotoxy(2,39);
	printf("Lavet af Mattias, Ida, Emil & Peter");
}
void border() {
	fgcolor(7);
	// 140x40
			//Værdier vi benytter:
			int  toplength = 138; //trukket 2 fra for at have hjørner med
			int  sidelength = 40;
			gotoxy(0,0);
			//toppen
			printf("%c",201);
			for (int j = 0; j <= (toplength); j++) {
				printf("%c",205);
			}
			printf("%c",187);
			//Sider
			for (int i = 2; i< sidelength;i++) {
				gotoxy(0,i);
				printf("%c",186);
				gotoxy(141,i);
				printf("%c",186);
			}
			//bund
			gotoxy(1,40);
			printf("%c",200);
			for (int j = 0; j <= (toplength); j++) {
							printf("%c",205);
						}
			printf("%c",188);
}


void background() {
	fgcolor(7);
	for (int i = 0; i<40; i++) {
		for (int j = 0; j < 8; j++) {
			int x_value = rand()% 140;
			gotoxy(x_value,i);
			printf("*");
		}
	}
/*

    int x_value = 0; // Initialize x_value
    int y_value = 0; // Initialize y_value
    int range = 140; // Calculate the range

        srand(123); // Set a constant seed for the random number generator
        for (int antal_stjerner = 0; antal_stjerner < 200; antal_stjerner++) {
            // Generate a random number within the specified range
        int random_number = (rand() % range) + 40;
        // Add random number to x_value and y_value
        x_value += random_number;
        y_value += random_number;

        // Adjust x_value and y_value based on conditions
        while (x_value < 2) {
            x_value += 10;
        }
        while (y_value < 2) {
            y_value += 10;
        }
        while (x_value > 139) {
            x_value -= 137;
        }
        while (y_value > 39) {
            y_value -= 37;
        }

        // Print asterisk at the computed position
        gotoxy(x_value, y_value);
        printf("%c", '*');
    }
    */
}
void menubox() {
	// 140x40
				//Værdier vi benytter:
				int  toplength = 51; //trukket 2 fra for at have hjørner med
				int  sidelength = 39;
				gotoxy(45,9);
				//toppen
				printf("%c",201);
				for (int j = 0; j <= (toplength); j++) {
					printf("%c",205);
				}
				printf("%c",187);
				//Sider
				for (int i = 10; i< sidelength;i++) {
					gotoxy(45,i);
					printf("%c",186);
					gotoxy(98,i);
					printf("%c",186);
				}
				//bund
				gotoxy(45,39);
				printf("%c",200);
				for (int j = 0; j <= (toplength); j++) {
								printf("%c",205);
							}
				printf("%c",188);
				gotoxy(60,10);
				write_menu();
}
void box() {
	//Værdier vi benytter:
					int  toplength = 51; //trukket 2 fra for at have hjørner med
					int  sidelength = 39;
					gotoxy(45,9);
					//toppen
					printf("%c",201);
					for (int j = 0; j <= (toplength); j++) {
						printf("%c",205);
					}
					printf("%c",187);
					//Sider
					for (int i = 10; i< sidelength;i++) {
						gotoxy(45,i);
						printf("%c",186);
						gotoxy(98,i);
						printf("%c",186);
					}
					//bund
					gotoxy(45,39);
					printf("%c",200);
					for (int j = 0; j <= (toplength); j++) {
									printf("%c",205);
								}
					printf("%c",188);
					gotoxy(60,10);
}
void Smallbox() {
	//Værdier vi benytter:
					int  toplength = 8; //trukket 2 fra for at have hjørner med
					int  sidelength = 5;
					//toppen
					printf("%c",201);
					for (int j = 0; j <= (toplength); j++) {
						printf("%c",205);
					}
					printf("%c",187);
					cursor_down(1);
					cursor_left(1);
					//Sider
					for (int i = 0; i< sidelength;i++) {
						printf("%c",186);
						cursor_left(11);
						printf("%c",186);
						cursor_down(1);
						cursor_right(9);
					}
					//bund
					cursor_left(10);
					printf("%c",200);
					for (int j = 0; j <= (toplength); j++) {
									printf("%c",205);
								}
					printf("%c",188);
}
void help_design() {
	box();
	fgcolor(15);
	gotoxy(47,18);
	printf("Move the spaceship right or left using joystick");
	gotoxy(47,23);
	printf("Obstacles have gravitational pull");
	small_gravity(85,25);
	fgcolor(15);
	gotoxy(94,26);printf("o");cursor_up(1);cursor_left(1);printf("o");
	cursor_up(1);cursor_left(2);printf("o");cursor_up(1);cursor_left(1);printf("o");cursor_up(1);cursor_left(2);printf("o");
	cursor_up(1);cursor_left(2);printf("o");cursor_up(1);cursor_left(2);printf("o");
	gotoxy(47,27);
	printf("Shoot enemies by pressing center");
	initiate_enemies(80,27,6);initiate_enemies(85,27,2);initiate_enemies(90,27,11);
	initiate_rocket(94,30);
	gotoxy(94,27);printf("o");cursor_down(1);cursor_left(1);printf("o");
	gotoxy(47,31);printf("Play through the levels");
	gotoxy(47,32);printf("and beat your own highscore!");
}
/*
// Function to display the big asteroid at a specific location
void displayBigAsteroid(struct astroid asteroid) {
    fgcolor(8);
    printf("\033[%d;%dH      .-\"\"\"\"\"\"-.\n", asteroid.y, asteroid.x);
    printf("\033[%d;%dH    .-'   ()       '-.\n", asteroid.y + 1, asteroid.x);
    printf("\033[%d;%dH   .'          O       '.\n", asteroid.y + 2, asteroid.x);
    printf("\033[%d;%dH /   O      .    ()       \\\n", asteroid.y + 3, asteroid.x);
    printf("\033[%d;%dH:           .           o  :\n", asteroid.y + 4, asteroid.x);
    printf("\033[%d;%dH :  .   ()   .      '    :\n", asteroid.y + 5, asteroid.x);
    printf("\033[%d;%dH  \\           .    .    /\n", asteroid.y + 6, asteroid.x);
    printf("\033[%d;%dH   '.()   O        o  .'\n", asteroid.y + 7, asteroid.x);
    printf("\033[%d;%dH       '-.______ _.-'\n", asteroid.y + 8, asteroid.x);
}

// Function to display the medium asteroid at a specific location
void displayMediumAsteroid(struct astroid asteroid) {
    fgcolor(8);
    printf("\033[%d;%dH      .--\"\"\"\"\"--.,.\n", asteroid.y, asteroid.x);
    printf("\033[%d;%dH    .' o    ()   .   '.\n", asteroid.y + 1, asteroid.x);
    printf("\033[%d;%dH   /  .      O     .    \\\n", asteroid.y + 2, asteroid.x);
    printf("\033[%d;%dH  :      :     O    o  :\n", asteroid.y + 3, asteroid.x);
    printf("\033[%d;%dH  :  o .      ()   .   .:\n", asteroid.y + 4, asteroid.x);
    printf("\033[%d;%dH   \\       .     o  . /\n", asteroid.y + 5, asteroid.x);
    printf("\033[%d;%dH    '.() o  O   o .   '\n", asteroid.y + 6, asteroid.x);
    printf("\033[%d;%dH      '--...__.-:.__ '\n", asteroid.y + 7, asteroid.x);
}

// Function to display the small asteroid at a specific location
void displaySmallAsteroid(struct astroid asteroid) {
    fgcolor(8);
    printf("\033[%d;%dH    .- .\"\"_.    \n", asteroid.y, asteroid.x);
    printf("\033[%d;%dH .  .   o     :  \n", asteroid.y + 1, asteroid.x);
    printf("\033[%d;%dH/     .  () .   \\ \n", asteroid.y + 2, asteroid.x);
    printf("\033[%d;%dH.  ()      o    :\n", asteroid.y + 3, asteroid.x);
    printf("\033[%d;%dH.   o  '  .    :\n", asteroid.y + 4, asteroid.x);
    printf("\033[%d;%dH\\    ( ) .  o  /\n", asteroid.y + 5, asteroid.x);
    printf("\033[%d;%dH  :  .        . \n", asteroid.y + 6, asteroid.x);
    printf("\033[%d;%dH   \\ () __.. /  \n", asteroid.y + 7, asteroid.x);
}

// Function to print asteroids of diffrent size
void displayAsteroidBySize(char size, struct astroid asteroid) {
    switch (size) {
        case 'B':
            displayBigAsteroid(asteroid);
            break;
        case 'M':
            displayMediumAsteroid(asteroid);
            break;
        case 'S':
            displaySmallAsteroid(asteroid);
            break;
        default:
            printf("Invalid size!\n");
    }
}

*/
void small_gravity(int x, int y) {
	fgcolor(3);
	gotoxy(x+1,y);
    printf("___");
    gotoxy(x,y-1);
    printf("/o. |");
    gotoxy(x,y-2);
    printf("(. o|");
    gotoxy(x,y-3);
    printf("\\. /");
    gotoxy(x+1,y-4);
    printf("---");
}
void large_gravity(int x, int y) {
	fgcolor(3);
	gotoxy(x+2,y);
	printf("___");
	gotoxy(x+1,y-1);
	printf("/ ..|");
	gotoxy(x,y-2);;
	printf("/  .o\\");
	gotoxy(x,y-3);
	printf("(o. : )");
	gotoxy(x+1,y-4);
	printf("\\oo/");
	gotoxy(x+2,y-5);
	printf("---");
}
