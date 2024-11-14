/*
 * Menu_text.c
 *
 *  Created on: 10. jan. 2024
 *      Author: Matti
 */
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

//################## ASTEROIDS ###################
void write_Welcome() {
	// 140x40 #219
	gotoxy(45,8);
	fgcolor(2);
//PRINT "A"
	for (int i=0;i<=5;i++) {
	printf("%c",219);
	cursor_up(1);cursor_left(1);
	}
	cursor_right(1);
	for (int j=0;j <= 3;j++) {
		printf("%c",219);
		cursor_down(2);cursor_left(1);
		printf("%c",219);
		cursor_up(2);
		}
	for (int i = 0; i<=5;i++) {
		cursor_down(1);
		printf("%c",219);
		cursor_left(1);
	}
//PRINT "S"
	for (int i=0;i<=4;i++) {
		printf("%c",219);
	}
	for (int i=0; i<= 1; i++) {
		cursor_up(1);
		printf("%c",219);
		cursor_left(1);
	}
	cursor_up(1); cursor_right(1);
	for (int i=0;i<=2; i++) {
		cursor_left(2);
		printf("%c",219);
	}
	cursor_left(2);cursor_up(1);
	printf("%c",219);
	cursor_up(1);
	printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_right(1);

//PRINT "T"
	printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_left(3);
	cursor_down(1);printf("%c",219);cursor_left(1);
	cursor_down(1);printf("%c",219);cursor_left(1);
	cursor_down(1);printf("%c",219);cursor_left(1);
	cursor_down(1);printf("%c",219);cursor_left(1);
	cursor_down(1);printf("%c",219);
	cursor_right(3);
//PRINT "E"
	printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_left(5);cursor_up(1);
	printf("%c",219);cursor_left(1);cursor_up(1);
	printf("%c",219);cursor_left(1);cursor_up(1);
	printf("%c",219);printf("%c",219);printf("%c",219);cursor_left(3);cursor_up(1);
	printf("%c",219);cursor_left(1);cursor_up(1);
	printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);

//PRINT "R"
	cursor_right(1);
	printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_left(6);cursor_down(1);
	printf("%c",219);cursor_right(5);printf("%c",219);
	cursor_left(7);cursor_down(1);
	printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_left(6);cursor_down(1);
	printf("%c",219);cursor_down(1);cursor_left(1);
	printf("%c",219);cursor_down(1);cursor_left(1);
	printf("%c",219);cursor_up(2);cursor_right(3);
	printf("%c",219);cursor_down(1);printf("%c",219);cursor_down(1);printf("%c",219);

//PRINT "O"
	cursor_right(2);
	printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	for (int i =0; i<=3; i++) {
		cursor_up(1);
		printf("%c",219);
		cursor_left(6);
		printf("%c",219);
		cursor_right(4);
	}
	cursor_up(1);cursor_left(4);
	printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
//PRINT "I"
	cursor_right(2);
	printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_down(1);cursor_left(2);printf("%c",219);
	cursor_down(1);cursor_left(1);printf("%c",219);
	cursor_down(1);cursor_left(1);printf("%c",219);
	cursor_down(1);cursor_left(1);printf("%c",219);
	cursor_down(1);cursor_left(2);printf("%c",219);printf("%c",219);printf("%c",219);
//PRINT "D"
	cursor_right(1);
	printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_left(4);cursor_up(1);printf("%c",219);
	cursor_left(1);cursor_up(1);printf("%c",219);
	cursor_left(1);cursor_up(1);printf("%c",219);
	cursor_left(1);cursor_up(1);printf("%c",219);
	cursor_left(1);cursor_up(1);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_down(1);printf("%c",219);
	cursor_down(1);cursor_left(1);printf("%c",219);
	cursor_down(1);cursor_left(1);printf("%c",219);
	cursor_down(1);cursor_left(1);printf("%c",219);
//PRINT "S"
	cursor_down(1);
		for (int i=0;i<=4;i++) {
			printf("%c",219);
		}
		for (int i=0; i<= 1; i++) {
			cursor_up(1);
			printf("%c",219);
			cursor_left(1);
		}
		cursor_up(1); cursor_right(1);
		for (int i=0;i<=2; i++) {
			cursor_left(2);
			printf("%c",219);
		}
		cursor_left(2);cursor_up(1);
		printf("%c",219);
		cursor_up(1);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		cursor_right(1);
		fgcolor(7);
}

//################## MENU ###################
void write_menu(){
	gotoxy(60,10);
	fgcolor(6);
	//Print M
	printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	cursor_up(3);printf("%c", 219);cursor_down(1);
	printf("%c", 219);
	cursor_up(1);printf("%c", 219);
	cursor_up(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	cursor_up(4);cursor_right(1);
	//print E
	printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	printf("%c", 219);printf("%c", 219);printf("%c", 219);
	cursor_up(2);cursor_left(3);printf("%c", 219);printf("%c", 219);
	cursor_up(2);cursor_left(2);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	;cursor_right(1);

	//print N
	printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	cursor_up(4);printf("%c", 219);cursor_down(1);printf("%c", 219);cursor_down(1);printf("%c", 219);cursor_down(1);printf("%c", 219);cursor_down(1);printf("%c", 219);
	cursor_up(1);cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);
	cursor_right(1);

	//print U
	printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	cursor_down(1);printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_up(1);printf("%c",219);cursor_up(1);cursor_left(1);printf("%c",219);cursor_up(1);cursor_left(1);printf("%c",219);cursor_up(1);cursor_left(1);printf("%c",219);
	fgcolor(7);
}

//################## HELP ###################
void write_help(){
	//print H
	printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	cursor_up(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	cursor_down(1);cursor_left(1);printf("%c", 219);cursor_up(2);cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);
	//Print E
	cursor_right(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	printf("%c", 219);printf("%c", 219);printf("%c", 219);
	cursor_up(2);cursor_left(3);printf("%c", 219);cursor_left(1);cursor_up(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	//Print L
	cursor_right(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	printf("%c", 219);printf("%c", 219);printf("%c", 219);
	cursor_up(3);cursor_right(1);
	//Print P
	printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	cursor_up(3);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(3);printf("%c", 219);printf("%c", 219);
	cursor_right(2);cursor_up(2);
}
//################## SCORE ###################
void write_score(int x, int y, int colour) {
	//Sets cursor
	gotoxy(x,y);
	fgcolor(colour);
	//Print S
	printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);
	printf("%c", 219);cursor_down(1);cursor_left(4);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	cursor_up(3);cursor_left(3);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_right(1);
	//Print C
	cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	cursor_up(3);cursor_left(3);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	//print O
	cursor_right(1);
	cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);printf("%c", 219);printf("%c", 219);cursor_up(1);printf("%c", 219);cursor_up(1);
	cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(3);printf("%c", 219);printf("%c", 219);cursor_right(2);
	//Print R
	cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	cursor_up(1);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);
	cursor_up(3);cursor_left(3);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);
	//Print E
	cursor_right(1);cursor_up(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	printf("%c", 219);printf("%c", 219);printf("%c", 219);
	cursor_up(2);cursor_left(3);printf("%c", 219);cursor_left(1);cursor_up(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);
}
//################## PLAY ###################
void write_play(){

	//Print P
	printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	cursor_up(3);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(3);printf("%c", 219);printf("%c", 219);
	cursor_right(2);cursor_up(2);
	//Print L
	printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	printf("%c", 219);printf("%c", 219);printf("%c", 219);
	cursor_up(3);cursor_right(1);
	//Print A
	cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_up(1);printf("%c", 219);printf("%c", 219);
	cursor_down(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(3);printf("%c", 219);printf("%c", 219);
	//Print Y
	cursor_right(2);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
	cursor_up(3);printf("%c", 219);cursor_left(1);cursor_down(1);printf("%c", 219);
}
//################## SCORE HEADER ###################
void write_score_header(int x, int y, int colour) {
	//Setting cursor
	gotoxy(x,y);
	fgcolor(colour);
	//Print big S
	for (int i=0;i<=4;i++) {
			printf("%c",219);
		}
		for (int i=0; i<= 1; i++) {
			cursor_up(1);
			printf("%c",219);
			cursor_left(1);
		}
		cursor_up(1); cursor_right(1);
		for (int i=0;i<=3; i++) {
			cursor_left(2);
			printf("%c",219);
		}
		cursor_left(2);cursor_up(1);
		printf("%c",219);
		cursor_up(1);cursor_left(1);printf("%c", 219);
		cursor_up(1);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		cursor_right(1);

	//Print C
		cursor_right(1);
		cursor_down(2);printf("%c",219);cursor_down(1);cursor_left(1);printf("%c",219);
		cursor_down(1);cursor_left(1);printf("%c",219);cursor_down(1);cursor_left(1);printf("%c",219);
		cursor_down(1);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		cursor_up(5);cursor_left(4);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		cursor_right(1);
	//PRINT "O"
		cursor_right(2); cursor_down(5);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		for (int i =0; i<=3; i++) {
			cursor_up(1);
			printf("%c",219);
			cursor_left(6);
			printf("%c",219);
			cursor_right(4);
		}
		cursor_up(1);cursor_left(4);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	//PRINT "R"
		cursor_right(3);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		cursor_left(6);cursor_down(1);
		printf("%c",219);cursor_right(5);printf("%c",219);
		cursor_left(7);cursor_down(1);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		cursor_left(6);cursor_down(1);
		printf("%c",219);cursor_down(1);cursor_left(1);
		printf("%c",219);cursor_down(1);cursor_left(1);
		printf("%c",219);cursor_up(2);cursor_right(3);
		printf("%c",219);cursor_down(1);printf("%c",219);cursor_down(1);printf("%c",219);

	//PRINT "E"
		cursor_right(2);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		cursor_left(5);cursor_up(1);
		printf("%c",219);cursor_left(1);cursor_up(1);
		printf("%c",219);cursor_left(1);cursor_up(1);
		printf("%c",219);printf("%c",219);printf("%c",219);cursor_left(3);cursor_up(1);
		printf("%c",219);cursor_left(1);cursor_up(1);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		fgcolor(7);
}
//################## HELP HEADER ###################
void write_help_header() {
	fgcolor(2);
	//setting cursor
	gotoxy(60,10);
	//Print H
	for (int i = 0;i <7;i++) {
		printf("%c",219);cursor_down(1);
		cursor_left(1);
	}
	cursor_up(4);cursor_right(1);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	cursor_down(1);cursor_left(1);printf("%c",219);cursor_down(1);cursor_left(1);printf("%c",219);cursor_down(1);
	cursor_left(1);printf("%c",219);cursor_up(4);cursor_left(1);printf("%c",219);cursor_up(1);cursor_left(1);printf("%c",219);
	cursor_up(1);cursor_left(1);printf("%c",219);cursor_right(2);

	//PRINT "E"
		cursor_down(6);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		cursor_left(5);cursor_up(1);
		printf("%c",219);cursor_left(1);cursor_up(1);
		printf("%c",219);cursor_left(1);cursor_up(1);
		printf("%c",219);printf("%c",219);printf("%c",219);cursor_left(3);cursor_up(1);
		printf("%c",219);cursor_left(1);cursor_up(1);
		printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
	//Print L
		cursor_right(2);
		for (int i = 0; i<5;i++) {
			printf("%c",219);
			cursor_down(1);
			cursor_left(1);
		}
		for (int j = 0; j<5;j++) {
			printf("%c",219);
		}
	//Print P
		cursor_right(2);cursor_up(4);
		for (int i = 0; i<5;i++) {
				printf("%c",219);
				cursor_down(1);
				cursor_left(1);
			}
		cursor_up(3);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);cursor_up(1);printf("%c",219);
		cursor_up(1);cursor_left(1);printf("%c",219);cursor_up(1);cursor_left(5);printf("%c",219);printf("%c",219);printf("%c",219);printf("%c",219);
		fgcolor(7);
}
//################## EXIT ###################
void write_exit() {
	//Setting cursor
	gotoxy(62,36);
	//Print E
		cursor_right(1);cursor_up(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
		printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_up(2);cursor_left(3);printf("%c", 219);cursor_left(1);cursor_up(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	//Print X
		cursor_right(1);printf("%c", 219);cursor_down(1);printf("%c", 219);printf("%c", 219);cursor_down(1);
		cursor_left(2);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);cursor_left(4);printf("%c", 219);
		cursor_up(3);cursor_right(2);printf("%c", 219);
	//Print I
		cursor_right(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_down(1);
		cursor_left(3);printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(3);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	//Print T
		cursor_up(3);cursor_right(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(3);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
	fgcolor(7);
	blink(0);
}
void write_highscore() {
	//Sets cursor
	gotoxy(47,10);
	fgcolor(11);
	//Print H
		printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
		cursor_up(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(1);printf("%c", 219);cursor_up(2);cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);

	//Print I
		cursor_right(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_down(1);
		cursor_left(3);printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(3);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);

	//Print G
		cursor_up(2);cursor_right(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
		cursor_down(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);printf("%c", 219);
		cursor_left(4);cursor_up(2);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);

	//Print H
		cursor_right(1);
		printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
		cursor_up(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(1);printf("%c", 219);cursor_up(2);cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);

	//Print "-"
		cursor_right(1);cursor_down(2); printf("%c", 219);printf("%c", 219);
		cursor_up(2);cursor_right(1);

	//Print S
		printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);
		printf("%c", 219);cursor_down(1);cursor_left(4);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_up(3);cursor_left(3);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_right(1);

	//Print C
		cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_up(3);cursor_left(3);printf("%c", 219);printf("%c", 219);printf("%c", 219);

	//print O
		cursor_right(1);
		cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);printf("%c", 219);printf("%c", 219);cursor_up(1);printf("%c", 219);cursor_up(1);
		cursor_left(1);printf("%c", 219);cursor_up(1);cursor_left(3);printf("%c", 219);printf("%c", 219);cursor_right(2);

	//Print R
		cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
		cursor_up(1);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);
		cursor_up(3);cursor_left(3);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);

	//Print E
		cursor_right(1);cursor_up(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
		printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_up(2);cursor_left(3);printf("%c", 219);cursor_left(1);cursor_up(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		fgcolor(7);
	}
void write_exitplay() {
	//Setting cursor
	gotoxy(62,36);
	//Print E
		cursor_right(1);cursor_up(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
		printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_up(2);cursor_left(3);printf("%c", 219);cursor_left(1);cursor_up(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	//Print X
		cursor_right(1);printf("%c", 219);cursor_down(1);printf("%c", 219);printf("%c", 219);cursor_down(1);
		cursor_left(2);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);cursor_left(4);printf("%c", 219);
		cursor_up(3);cursor_right(2);printf("%c", 219);
	//Print I
		cursor_right(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_down(1);
		cursor_left(3);printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(3);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	//Print T
		cursor_up(3);cursor_right(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(3);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
}
void write_play_header() {
	gotoxy(60,10);
	//"P"

	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_down(1);printf("%c", 219);
	cursor_left(7);cursor_down(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	//"L"
	cursor_down(3); cursor_right(2);printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);
	cursor_down(5);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
	//"A"
	cursor_right(1);
	for (int i=0;i<=4;i++) {
	printf("%c",219);
	cursor_up(1);cursor_left(1);
	}
	cursor_right(1);
	for (int j=0;j <= 3;j++) {
		printf("%c",219);
		cursor_down(2);cursor_left(1);
		printf("%c",219);
		cursor_up(2);
		}
	for (int i = 0; i<=4;i++) {
		cursor_down(1);
		printf("%c",219);
		cursor_left(1);
	}
	//"Y"
	cursor_right(5);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_left(1);cursor_up(1);
	printf("%c", 219);cursor_up(1);
	printf("%c", 219);cursor_left(3);printf("%c", 219);cursor_up(1);
	cursor_left(2);printf("%c", 219);cursor_right(3);printf("%c", 219);

}
void write_numbers(int number,int x,int y) {
	//Set cursor
	gotoxy(x,y);
	//Print 1
		if (number == 1) {
			cursor_down(1);printf("%c", 219);
			cursor_up(1);
			printf("%c", 219);printf("%c", 219);printf("%c", 219);
			for (int i = 0;i < 4;i++) {
				cursor_down(1);
				cursor_left(1);
				printf("%c", 219);
			}
			printf("%c", 219);
			cursor_left(4);
			printf("%c", 219);
			printf("%c", 219);
		}
		else if (number == 2) {
			cursor_down(1);
			printf("%c", 219);
			cursor_up(1);
			printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_down(1);printf("%c", 219);
			cursor_down(1);cursor_left(3);printf("%c", 219);printf("%c", 219);
			cursor_down(1);cursor_left(3);printf("%c", 219);
			cursor_down(1);cursor_left(2);printf("%c", 219);
			printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);


		}
		else if (number == 3) {
			cursor_down(1);printf("%c", 219);
			cursor_up(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_down(1);
			printf("%c", 219);cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
			cursor_left(1);cursor_down(1);printf("%c", 219);cursor_left(5);printf("%c", 219);
			cursor_down(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		}
		else if (number == 4) {
			printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
			cursor_left(1);cursor_down(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_up(2);
			for (int i = 0;i <5;i++) {
				printf("%c", 219);
				cursor_down(1);
				cursor_left(1);
			}
		}
		else if (number == 5) {
			cursor_right(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_down(1);cursor_left(5);printf("%c", 219);
			cursor_down(1);cursor_left(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_left(1),cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(5);
			printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		}
		else if (number == 6) {
			printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_down(1);cursor_left(5);printf("%c", 219);cursor_down(1);cursor_left(1);
			printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_left(5);cursor_down(1);printf("%c", 219);cursor_right(3);printf("%c", 219);
			cursor_left(5);cursor_down(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			printf("%c", 219);printf("%c", 219);
		}
		else if (number == 7) {
			printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_down(1);cursor_left(1);printf("%c", 219);
			for (int i = 0;i<3;i++) {
				cursor_left(2);cursor_down(1);
				printf("%c", 219);
			}
		}
		else if (number == 8) {
			printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_down(1);cursor_left(5);printf("%c", 219);cursor_right(3);printf("%c", 219);
			cursor_down(1),cursor_left(4);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_down(1);cursor_left(4);printf("%c", 219);cursor_right(3);printf("%c", 219);
			cursor_down(1);cursor_left(5);printf("%c", 219);printf("%c", 219);
			printf("%c", 219);printf("%c", 219);printf("%c", 219);
		}
		else if (number == 9) {
			printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_down(1);cursor_left(5);printf("%c", 219);cursor_right(3);printf("%c", 219);
			cursor_down(1);cursor_left(5);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
			cursor_down(1);cursor_left(1);printf("%c", 219);
			cursor_down(1);cursor_left(5);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		}
		else if (number == 0) {
			cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
			cursor_down(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_up(1);printf("%c", 219);cursor_up(1);cursor_left(1);
			printf("%c", 219);cursor_left(1);cursor_up(1);printf("%c", 219);cursor_up(1);cursor_left(4);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		}
}
void asteroid(int x, int y){
	fgcolor(3);
	gotoxy(x,y);
    printf("      .-\"\"\"\"\"\"-.\n");
    gotoxy(x,y+1);
    printf("    .-'   ()       '-.\n");
    gotoxy(x,y+2);
    printf("   .'          O       '.\n");
    gotoxy(x,y+3);
    printf(" /   O      .    ()       \\\n");
    gotoxy(x,y+4);
    printf(":           .           o  :\n");
    gotoxy(x,y+5);
    printf(" :  .   ()   .      '    :\n");
    gotoxy(x,y+6);
    printf("  \\           .    .    /\n");
    gotoxy(x,y+7);
    printf("   '.()   O        o  .'\n");
    gotoxy(x,y+8);
    printf("       '-.______ _.-'\n");
    fgcolor(7);
}

void write_gameover(int x,int y) {
	//Sets cursor at x and y
	gotoxy(x,y);
	//Print G
		cursor_down(1);for (int i = 0; i<5;i++) {printf("%c", 219);cursor_down(1);cursor_left(1);}
		cursor_right(1);
		for (int i = 0;i<5;i++) {printf("%c", 219);}cursor_up(1);cursor_left(1);
		printf("%c", 219);printf("%c", 219);cursor_up(1);cursor_left(2);
		printf("%c", 219);printf("%c", 219);cursor_up(1);cursor_left(4); for (int i=0;i<4;i++) {printf("%c", 219);}
		cursor_left(6);cursor_down(2);for (int i =0;i<5;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}
		for (int i=0;i<5;i++){printf("%c", 219);}cursor_down(1);cursor_left(1);printf("%c", 219);printf("%c", 219);


	//Print A
		cursor_right(2); for (int i = 0;i<6;i++) {printf("%c", 219);cursor_down(1);cursor_left(1);}cursor_right(2);
		cursor_up(1);cursor_left(1); for (int i =0;i<6;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}
		for (int i = 0;i<4;i++) {printf("%c", 219);} for (int i = 0;i<6;i++) {cursor_down(1);cursor_left(1);printf("%c", 219);}
		cursor_up(3);cursor_left(3);printf("%c", 219);printf("%c", 219);cursor_right(1);cursor_down(3);
		for (int i =0;i<6;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}

	//Print M
		cursor_right(3); for (int i=0;i<7;i++) {printf("%c", 219);cursor_down(1);cursor_left(1);}
		cursor_up(1);cursor_right(1);
		for (int i = 0;i<7;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}
		cursor_down(1);cursor_right(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
		cursor_up(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);
		for (int i = 0;i<7;i++) {printf("%c", 219);cursor_down(1);cursor_left(1);}cursor_right(1);cursor_up(1);
		for (int i = 0;i<7;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}

	//Print E
		cursor_right(3);cursor_down(1);for (int i=0;i<7;i++) {printf("%c", 219);cursor_down(1);cursor_left(1);}
		cursor_up(1);cursor_right(1);
		for (int i = 0;i<6;i++) {printf("%c", 219);}cursor_left(6);cursor_up(1);
		for (int i = 0;i<6;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}cursor_down(1);cursor_right(1);
		for (int i = 0;i<5;i++) {printf("%c", 219);}cursor_down(3);cursor_left(5);
		for (int i = 0;i<4;i++) {printf("%c", 219);}


	//Space
		cursor_right(7);

	//Print O
		cursor_up(2);for (int i = 0;i<5;i++) {printf("%c", 219);cursor_down(1);cursor_left(1);}
		cursor_right(1);for(int i = 0;i<7;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}cursor_right(1);cursor_down(1);
		for (int i = 0;i<4;i++) {printf("%c", 219);}
		for (int i = 0; i<6;i++) {cursor_down(1);cursor_left(1);printf("%c", 219);}cursor_left(4);
		printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_right(1);cursor_up(1);
		for (int i = 0;i<5;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}

	//Print V
		cursor_right(3);for(int i = 0;i<5;i++){printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}
		cursor_right(1);for(int i = 0;i<5;i++){printf("%c", 219);}
		cursor_down(1);cursor_left(4);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_up(2);
		for(int i = 0;i<5;i++){printf("%c", 219);printf("%c", 219);cursor_up(1);cursor_left(2);}

	//Print E
		cursor_right(4);cursor_down(1);for (int i=0;i<7;i++) {printf("%c", 219);cursor_down(1);cursor_left(1);}
		cursor_up(1);cursor_right(1);
		for (int i = 0;i<6;i++) {printf("%c", 219);}cursor_left(6);cursor_up(1);
		for (int i = 0;i<6;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}cursor_down(1);cursor_right(1);
		for (int i = 0;i<5;i++) {printf("%c", 219);}cursor_down(3);cursor_left(5);
		for (int i = 0;i<4;i++) {printf("%c", 219);}

	//Print R
		cursor_right(3);cursor_up(3);for (int i = 0;i<7;i++) {printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}
		cursor_up(7);cursor_right(2);for(int i = 0;i<4;i++) {printf("%c", 219);}cursor_down(1);cursor_left(1);
		for (int i = 0;i<2;i++){printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}cursor_left(3);
		printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(1);
		for (int i = 0;i<3;i++){printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}

}

void write_colon(int x, int y, int colour) {
	gotoxy(x,y);
	fgcolor(colour);
	printf("%c", 254);
	cursor_down(2);cursor_left(1);
	printf("%c", 254);
}

void write_yourendscore(int x,int y, int colour) {
	gotoxy(x,y);
	fgcolor(colour);
	int digits[3];
	long number = globalPoints;
	for (int i = 0;i<3;i++) {
		digits[i] = number % 10;
		number = number / 10;

	}
	for (int i = 0;i<3;i++) {

		switch (digits[2-i]) {
		case 0:
			write_numbers(0,x+(6*i),y);
			break;
		case 1:
			write_numbers(1,x+(6*i),y);
			break;
		case 2:
			write_numbers(2,x+(6*i),y);
			break;
		case 3:
			write_numbers(3,x+(6*i),y);
			break;
		case 4:
			write_numbers(4,x+(6*i),y);
			break;
		case 5:
			write_numbers(5,x+(6*i),y);
			break;
		case 6:
			write_numbers(6,x+(6*i),y);
			break;
		case 7:
			write_numbers(7,x+(6*i),y);
			break;
		case 8:
			write_numbers(8,x+(6*i),y);
			break;
		case 9:
			write_numbers(9,x+(6*i),y);
			break;
		default:
			break;
		}

		}
}

void skull(int x, int y, int colour){
	//Sets cursor
	gotoxy(x,y);
	//Sets Colour
	fgcolor(colour);
	//Script for drawing the skull
	cursor_right(2); for (int i=0;i<7;i++) {printf("%c", 219);}cursor_left(8);cursor_down(1);
	for (int i = 0;i<9;i++) {printf("%c", 219);}cursor_left(9);cursor_down(1);
	for (int i = 0;i<9;i++) {printf("%c", 219);}cursor_left(10);cursor_down(1);
	printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_right(2);printf("%c", 219);cursor_right(2);
	printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_left(11);cursor_down(1);printf("%c", 219);printf("%c", 219);
	cursor_right(3);printf("%c", 219);cursor_right(3);printf("%c", 219);printf("%c", 219);cursor_left(11);cursor_down(1);
	printf("%c", 219);printf("%c", 219);cursor_right(2);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_right(2);
	printf("%c", 219);printf("%c", 219);cursor_left(10);cursor_down(1);for (int i = 0;i<9;i++){printf("%c", 219);}
	cursor_left(10);cursor_down(1); for(int i = 0;i<2;i++){cursor_right(1);printf("%c", 219);printf("%c", 219);printf("%c", 219);printf("%c", 219);}
	cursor_left(7);cursor_down(1);for (int i = 0;i<5;i++){printf("%c", 219);}
	cursor_down(1);cursor_left(5);for(int i = 0;i<3;i++){printf("%c", 219);cursor_right(1);}
}
void write_youwin(int x, int y, int colour) {
	//Sets cursor
	gotoxy(x,y);
	//Colour:
	fgcolor(colour);
	//"Y"
		for (int i = 0;i<3;i++){printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}
		cursor_right(1); for (int i = 0;i<5;i++){printf("%c", 219);}cursor_down(1);cursor_left(4);
		printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
		cursor_left(1);cursor_down(1);printf("%c", 219);printf("%c", 219);cursor_up(4);
		for (int i = 0;i<3;i++){printf("%c", 219);printf("%c", 219);cursor_up(1);cursor_left(2);}

	//"O"
		cursor_right(4);cursor_down(2);for (int i = 0;i<5;i++) {printf("%c", 219);cursor_down(1);cursor_left(1);}
		cursor_right(1);for(int i = 0;i<7;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}cursor_right(1);cursor_down(1);
		for (int i = 0;i<4;i++) {printf("%c", 219);}
		for (int i = 0; i<6;i++) {cursor_down(1);cursor_left(1);printf("%c", 219);}cursor_left(4);
		printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_right(1);cursor_up(1);
		for (int i = 0;i<5;i++) {printf("%c", 219);cursor_up(1);cursor_left(1);}

	//"U"
		cursor_right(3);for(int i =0;i<6;i++){printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}
		cursor_right(1);for(int i = 0;i<5;i++){printf("%c", 219);}cursor_up(1);cursor_left(1);
		for(int i = 0;i<6;i++){printf("%c", 219);printf("%c", 219);cursor_up(1);cursor_left(2);}

	//Space
		cursor_right(8);

	//"W"
		cursor_down(1);for (int i = 0;i<7;i++){printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}
		cursor_right(2);cursor_up(1);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);printf("%c", 219);cursor_up(1);cursor_left(1);printf("%c", 219);
		cursor_down(1);printf("%c", 219);cursor_down(1);cursor_left(1);printf("%c", 219);
		for (int i = 0;i<7;i++){printf("%c", 219);printf("%c", 219);cursor_up(1);cursor_left(2);}

	//"I"
		cursor_right(4);cursor_down(1);for (int i = 0;i<7;i++){printf("%c", 219);}cursor_down(1);cursor_left(4);
		printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(3);printf("%c", 219);printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(3);
		printf("%c", 219);printf("%c", 219);cursor_left(2);cursor_down(1);printf("%c", 219);printf("%c", 219);
		cursor_down(1);cursor_left(4);for(int i =0;i<7;i++){printf("%c", 219);}

	//"N"
		cursor_up(6);cursor_right(2);for (int i = 0;i<7;i++){printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}
		cursor_up(7);cursor_right(2);printf("%c", 219);printf("%c", 219);printf("%c", 219);
		cursor_down(1);for (int i = 0;i<6;i++){printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}

	//"!"
		cursor_up(7);cursor_right(4);for(int i = 0;i<5;i++){printf("%c", 219);printf("%c", 219);cursor_down(1);cursor_left(2);}
		cursor_down(1);printf("%c", 219);printf("%c", 219);
}


void write_nextlevel(int x, int y, int colour) {
	//Sets cursor
	gotoxy(x,y);
	//Colour
	fgcolor(colour);

	//"N"
		for (int i = 0;i<5;i++){printf("%c", 219);cursor_down(1);cursor_left(1);}cursor_up(4);cursor_right(1);
		for (int i = 0;i<4;i++){printf("%c", 219);cursor_down(1);}cursor_left(1);cursor_up(2);
		for (int i = 0;i<4;i++){printf("%c", 219);cursor_left(1);cursor_up(1);}

	//"E"
		cursor_right(2);cursor_down(1);for (int i = 0;i<5;i++){printf("%c", 219);}cursor_down(1);cursor_left(5);
		for (int i = 0;i<4;i++){printf("%c", 219);cursor_down(1);cursor_left(1);}cursor_up(1);cursor_right(1);
		for (int i = 0;i<4;i++){printf("%c", 219);}cursor_up(2);cursor_left(4);printf("%c", 219);printf("%c", 219);printf("%c", 219);

	//"X"
		cursor_right(2);cursor_up(2);for (int i = 0;i<5;i++){printf("%c", 219);cursor_down(1);}cursor_up(1);cursor_left(5);
		for (int i = 0;i<5;i++){printf("%c", 219);cursor_up(1);}

	//"T"
		cursor_down(1),cursor_right(1);for (int i = 0;i<5;i++){printf("%c", 219);}cursor_down(1);cursor_left(3);
		for (int i = 0;i<4;i++){printf("%c", 219);cursor_down(1);cursor_left(1);}

	//Space
		cursor_right(6);cursor_up(5);

	//"L"
		for (int i = 0;i<5;i++){printf("%c", 219);cursor_down(1);cursor_left(1);}cursor_up(1);cursor_right(1);
		for (int i = 0;i<4;i++){printf("%c", 219);}

	//"E"
		cursor_right(1);cursor_up(4);for (int i = 0;i<5;i++){printf("%c", 219);}cursor_down(1);cursor_left(5);
		for (int i = 0;i<4;i++){printf("%c", 219);cursor_down(1);cursor_left(1);}cursor_up(1);cursor_right(1);
		for (int i = 0;i<4;i++){printf("%c", 219);}cursor_up(2);cursor_left(4);printf("%c", 219);printf("%c", 219);printf("%c", 219);

	//"V"
		cursor_right(2);cursor_up(2);for (int i =0;i<3;i++){printf("%c", 219);cursor_down(1);cursor_left(1);}
		cursor_right(1);printf("%c", 219);cursor_down(1);printf("%c", 219);cursor_up(1);printf("%c", 219);cursor_up(1);
		for (int i = 0;i<3;i++){printf("%c", 219);cursor_up(1);cursor_left(1);}

	//"E"
		cursor_right(2);cursor_down(1);for (int i = 0;i<5;i++){printf("%c", 219);}cursor_down(1);cursor_left(5);
		for (int i = 0;i<4;i++){printf("%c", 219);cursor_down(1);cursor_left(1);}cursor_up(1);cursor_right(1);
		for (int i = 0;i<4;i++){printf("%c", 219);}cursor_up(2);cursor_left(4);printf("%c", 219);printf("%c", 219);printf("%c", 219);

	//"L"
		cursor_right(2);cursor_up(2);
		for (int i = 0;i<5;i++){printf("%c", 219);cursor_down(1);cursor_left(1);}cursor_up(1);cursor_right(1);
		for (int i = 0;i<4;i++){printf("%c", 219);}
}
