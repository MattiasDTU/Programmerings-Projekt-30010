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
// Funktion for at lade teksten blinke i en given farve
void text_color_blink(int on, int color) {
	if (on == 1) {
		// Tænd LED og lav blink-effekt
		LED(color);
		blink(1);
		// Brug farveskema fra LCD_LED.c og oversæt til tilsvarende farve i fgcolor-farveskemaet
		switch (color) {
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
		// Sluk LED og stop blink-effekt
		LED(color);
		blink(0);
		fgcolor(7);
	}
}

// Vis credits-besked på skærmen
void credits() {
	gotoxy(2,39);
	printf("Lavet af Mattias, Ida, Emil & Peter");
}

// Funktion til at tegne en kant omkring skærmen
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

// Funktion for at lave baggrundseffekt med stjerner
void background() {
	fgcolor(7);
	for (int i = 0; i<40; i++) {
		for (int j = 0; j < 8; j++) {
			int x_value = rand()% 140;
			gotoxy(x_value,i);
			printf("*");
		}
	}
}
// Funktion til at tegne en stor boks i midten af skærmen
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

// Funktion for at tegne en mindre boks
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

// Funktion for at vise helpside og spilinstruktioner
void help_design() {
	box();
	fgcolor(15);
	gotoxy(47,11);
	printf("Use black holes to teleport shots");
	gotoxy(47,12);
	printf("Collect TNT or a Heart for powerup");
	bomb_power(50,15);heart_power(56,15);initiate_worm_hole(59,14);print_worm_hole(59,14);heart_power(65,15);bomb_power(68,15);heart_power(74,15);
	initiate_worm_hole(77,14);print_worm_hole(77,14);heart_power(83,15);bomb_power(86,15);heart_power(92,15);fgcolor(15);
	gotoxy(47,18);
	printf("Move the spaceship right or left using joystick");
	gotoxy(47,23);
	printf("Obstacles have gravitational pull");
	print_small_asteroid(85,21);
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

// Funktion for at tegne en række mindre bokse til levels
void drawLevelBoxes() {
    int startX = 37;
    int startY = 15;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 2; ++j) {
            gotoxy(startX + i * 15, startY + j * 8);
            Smallbox();
        }
    }
}
