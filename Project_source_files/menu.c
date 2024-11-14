/*
 * menu.c
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

void menuHELP() {
	background();
	lives(0);
	asteroid(2,2);
	border();
	box();
	write_help_header();
	text_color_blink(1);
	write_exit();
	text_color_blink(0);
	help_design();
	lcd_resetwrite("Controls and object of the game!",1);
	HelpControls();
}
void menuPLAY() {
	background();
	border();
	lives(0);
	asteroid(2,2);
	asteroid(90,20);
	lcd_resetwrite("Select a level to play",1);
	//BORDER FOR LEVELS
	gotoxy(37,15);
	Smallbox();
	gotoxy(52,15);
	Smallbox();
	gotoxy(67,15);
	Smallbox();
	gotoxy(82,15);
	Smallbox();
	gotoxy(97,15);
	Smallbox();
	gotoxy(37,23);
	Smallbox();
	gotoxy(52,23);
	Smallbox();
	gotoxy(67,23);
	Smallbox();
	gotoxy(82,23);
	Smallbox();
	gotoxy(97,23);
	Smallbox();
	PlayControls();
}
void menuSCORE() {
	background();
	border();
	asteroid(2,2);
	asteroid(90,20);
	write_score_header(54,8,2);
	box();
	text_color_blink(1);
	write_exit();
	text_color_blink(0);
	write_highscore();
	lcd_resetwrite("Look at your highscore!",1);
	gotoxy(50,15);
		for (int i = 0; i< 10; i++) {
		int scorearray[2] = {0,scores[i].score_count};
			gotoxy(50,15+(i<<1));
			if (scorearray[0]== 0) {printf("nr. %d Score ..........................",i+1);}
			printf("%d",scorearray[1]);
		}
	ScoreControls();
	//display scores:
}
void menu() {
	ClearScreen();
	background(); //FØRST
	lives(0);
	border();
	asteroid(2,2);
	asteroid(90,20);
	write_Welcome();
	menubox();
	lcd_resetwrite("Please select a menu", 1);
	credits();
	int value = MenuControls();
	if (value == 1) {
				menuHELP();
			}
	if (value == 2) {
		menuSCORE();

	}
	if (value == 3) {
		menuPLAY();
		}
}

void menuGAMEOVER() {
	ClearScreen();
	background(); //FØRST
	border();
	text_color_blink(1);
	write_exit();
	text_color_blink(0);
	write_gameover(37,5);
	write_score(50,15,1);
 	write_colon(75,16,1);
	write_yourendscore(77,14,1);
	globalPoints = 0;
	skull(67,22,7);
	lcd_resetwrite("",1);
	lcd_write_index("GAME",2,50);
	lcd_write_index("OVER!",3,50);
	lcd_write_index("   ",1,0);
	GAMEOVERControls();
}
void menuWIN(int level) {
	ClearScreen();
	background(); //FØRST
	border();
	write_youwin(46,5,2);
	write_score(55,15,1);
	write_colon(80,16,1);
	write_yourendscore(82,14,1);
	globalPoints = 0;
	int value = GAMEWINControls();
	if (value == 1) {
		switch (level) {
		case 1:
			level_2();
		case 2:
			level_3();
		case 3:
			level_4();
		case 4:
			level_5();
		case 5:
			level_6();
		case 6:
			level_7();
		case 7:
			level_8();
		case 8:
			level_9();
		case 9:
			menuPLAY();
		default:
			menu();
		}
	}
	if (value == 2) {
		menu();
	}

}
