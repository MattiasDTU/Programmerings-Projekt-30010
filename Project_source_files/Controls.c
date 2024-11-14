/*
 * Controls.c
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
volatile uint32_t timer;
int levelControls(int difficulty) {
	int speed = 0;
	int level = 0;
	int pause = 0;
	if (difficulty == 1) {speed = 10;level = 1;pause = 2000;Asteroid1(0,12,10); Asteroid1(1, 80,20);}
	if (difficulty == 2) {speed = 10;level = 2;pause = 1500;Asteroid1(0, 20, 12);Asteroid1(1, 70, 7);Asteroid2(0,90,6);Asteroid2(1,50,9);}
	if (difficulty == 3) {speed = 9;level = 3;pause = 1000;Asteroid1(0,12,15); Asteroid1(1, 80, 7);Asteroid2(0,90,20);Asteroid2(1,32,18);Asteroid3(0,70,10);Asteroid3(1,70,15);}
	if (difficulty == 4) {speed = 9;level = 4;pause = 500;Asteroid1(0,12,15); Asteroid1(1, 80, 7);Asteroid2(0,90,20);Asteroid2(1,32,18);Asteroid3(0,70,10);Asteroid3(1,70,15); Asteroid4(0,70,20); Asteroid4(1,10,15);}
	if (difficulty == 5) {speed = 8;level = 5;pause = 500;Asteroid1(0,12,7); Asteroid1(1, 10, 14);Asteroid2(0,50,10);Asteroid2(1,90,10);Asteroid3(0,110,10);Asteroid3(1,70,10); Asteroid4(0,130,10); Asteroid4(1,70,25);}
	if (difficulty == 6) {speed = 8;level = 6;pause = 0;Asteroid1(0,12,6); Asteroid1(1, 12, 12);Asteroid2(0,12,18);Asteroid2(1,12,24);Asteroid3(0,130,6);Asteroid3(1,130,12); Asteroid4(0,130,18); Asteroid4(1,130,28);}
	if (difficulty == 7) {speed = 7;level = 7;pause = 0;Asteroid1(0,12,13); Asteroid1(1, 12, 14);Asteroid2(0,50,23);Asteroid2(1,90,8);Asteroid3(0,110,17);Asteroid3(1,70,10); Asteroid4(0,130,13); Asteroid4(1,70,23);}
	if (difficulty == 8) {speed = 7;level = 8;pause = 0;Asteroid1(0,65,5); Asteroid1(1, 75, 5);Asteroid2(0,50,10);Asteroid2(1,90,10);Asteroid3(0,35,15);Asteroid3(1,105,15); Asteroid4(0,20,20); Asteroid4(1,120,20);}
	if (difficulty == 9) {speed = 7;level = 9;pause = 0;Asteroid1(0, 20, 20);Asteroid1(1, 70, 30);Asteroid2(0, 30, 25);Asteroid2(1, 40, 15);Asteroid3(0, 100, 20);Asteroid3(1, 70, 30);Asteroid4(0, 57, 17);Asteroid4(1, 89, 10);}
	int cursor_leftright = 38;
	int prev_cursor_leftright = 3;
	int shot_x = 0;
	int shot_y = 0;
	initiate_rocket(cursor_leftright, 38);
	text_color_blink(0,0);
	int shot = 0;
	while(1) {
		//Boss key start
				if (uart_get_char() == 0x1B){
					boss_key_function();
				}
				//Boss key slut
		level_lcd(difficulty,globalLives,globalPoints);
		enemiesbegin(speed,level,0);
		int value =  Joystickport();
		if (cursor_leftright == 139 && value == 8) {
			cursor_leftright = 3;}
		if (cursor_leftright == 3 && value == 4) {
					cursor_leftright = 139;}

	if (cursor_leftright > 3 && value == 4 ) { //LEFT
						if (cursor_leftright> 3) {cursor_leftright -= 1;}
						pause_control(pause<<2);
					}
			if (cursor_leftright < 139 && value == 8) { //RIGHT
						if (cursor_leftright< 139) {cursor_leftright += 1;}
						pause_control(pause<<2);
					}
	if (cursor_leftright != prev_cursor_leftright) {
						blink(0);
						fgcolor(7);
						delete_rocket(prev_cursor_leftright , 38);
						prev_cursor_leftright = cursor_leftright;
						initiate_rocket(cursor_leftright, 38);
							}

	if (value == 16) { //SKUD
		shot_x = cursor_leftright;
		shot_y = 36;
		shot = 1;
		addShot(shot_x, shot_y);
		prevShot(shot_x, shot_y);
		pause_control(200000);
		}
	if (shot == 1) {
	        updateAndPrintShots(pause,level, speed);
	    }
	}
}
int HelpControls() {
	int value = 0;
	while(1) {
	//Boss key start
	if (uart_get_char() == 0x1B){
		boss_key_function();
	}
	//Boss key slut
	value = Joystickport();
	if (value == 16) {menu();}
	}
}

//################## FUNKTIONER TIL PLAYMENU##################################
// DE ER LAVET FORDI VI BRUGTE FOR MEGET PLADS
// funktion for cursor bevægelse
void cursor_movement(int value, int *cursorUpDown, int *cursorLeftRight) {
    if (value == 1 && *cursorUpDown > 0) { // UP
        (*cursorUpDown)--;
    } else if (value == 2 && *cursorUpDown < 4) { // DOWN
        (*cursorUpDown)++;
    } else if (value == 4 && *cursorLeftRight > 0) { // LEFT
        (*cursorLeftRight)--;
    } else if (value == 8 && *cursorLeftRight < 4) { // RIGHT
        (*cursorLeftRight)++;
    }
}

// funktion for at bestemme level
void level_selection(int value, int cursorUpDown, int cursorLeftRight) {
    if (value == 16) {
        ClearScreen();
        switch (cursorUpDown) {
            case 1:
                switch (cursorLeftRight) {
                    case 0: level_1(); break;
                    case 1: level_2(); break;
                    case 2: level_3(); break;
                    case 3: level_4(); break;
                    case 4: level_5(); break;
                }
                break;
            case 2:
                switch (cursorLeftRight) {
                    case 0: level_6(); break;
                    case 1: level_7(); break;
                    case 2: level_8(); break;
                    case 3: level_9(); break;
                }
                break;
        }
    }
}

// funktion til hvis der trykkes på exit eller play
void playexit(int value, int cursorUpDown) {
    if (value == 16) {
        ClearScreen();
        if (cursorUpDown == 0) { // PLAY
        } else if (cursorUpDown == 3) { // EXIT
            menu();
        }
    }
}

// opdater skærmen
void updateScreen(int cursorUpDown, int cursorLeftRight, int prevCursorUpDown, int prevCursorLeftRight) {
    if (cursorLeftRight != prevCursorLeftRight || cursorUpDown != prevCursorUpDown) {
        text_color_blink(0,0);
        write_exit();
        write_play_header();
        write_numbers(1, 40, 16);
        write_numbers(2, 55, 16);
        write_numbers(3, 70, 16);
        write_numbers(4, 85, 16);
        write_numbers(5, 100, 16);
        write_numbers(6, 40, 24);
        write_numbers(7, 55, 24);
        write_numbers(8, 70, 24);
        write_numbers(9, 85, 24);
    }
}

//Switches for cursor pos
void show_cursor_pos(int cursorUpDown, int cursorLeftRight) {
		switch (cursorLeftRight) {
			case 0: switch (cursorUpDown) {
				case 0:text_color_blink(1,1);write_play_header();text_color_blink(0,1); 		break;
				case 1:text_color_blink(1,1);write_numbers(1, 40, 16);text_color_blink(0,1);	break;
				case 2:text_color_blink(1,1);write_numbers(6, 40, 24);text_color_blink(0,1);	break;
				case 3:text_color_blink(1,1);write_exit();text_color_blink(0,1); 				break;
				}
			break;
			case 1: switch (cursorUpDown) {
				case 0:text_color_blink(1,1);write_play_header();text_color_blink(0,1); 		break;
				case 1:text_color_blink(1,1);write_numbers(2, 55, 16);text_color_blink(0,1);	break;
				case 2:text_color_blink(1,1);write_numbers(7, 55, 24);text_color_blink(0,1);	break;
				case 3:text_color_blink(1,1);write_exit();text_color_blink(0,1); 				break;
				}
			break;
			case 2: switch (cursorUpDown) {
				case 0:text_color_blink(1,1);write_play_header();text_color_blink(0,1); 		break;
				case 1:text_color_blink(1,1);write_numbers(3, 70, 16);text_color_blink(0,1);	break;
				case 2:text_color_blink(1,1);write_numbers(8, 70, 24);text_color_blink(0,1);	break;
				case 3:text_color_blink(1,1);write_exit();text_color_blink(0,1); 				break;
				}
			break;
			case 3: switch (cursorUpDown) {
				case 0:text_color_blink(1,1);write_play_header();text_color_blink(0,1); 		break;
				case 1:text_color_blink(1,1);write_numbers(4, 85, 16);text_color_blink(0,1);	break;
				case 2:text_color_blink(1,1);write_numbers(9, 85, 24);text_color_blink(0,1);	break;
				case 3:text_color_blink(1,1);write_exit();text_color_blink(0,1); 				break;
				}
			break;
			case 4: switch (cursorUpDown) {
				case 0:text_color_blink(1,1);write_play_header();text_color_blink(0,1); 		break;
				case 1:text_color_blink(1,1);write_numbers(5, 100, 16);text_color_blink(0,1);	break;
				case 2:text_color_blink(1,1);text_color_blink(0,1);								break;
				case 3:text_color_blink(1,1);write_exit();text_color_blink(0,1); 				break;
				}
			break;
	}
}

// PlayControls
int PlayControls() {
    int cursorUpDown = 0;
    int cursorLeftRight = 0;
    int prevCursorUpDown = 0;
    int prevCursorLeftRight = 0;

    // Vis normal skærm
    text_color_blink(0,8);
    write_exit();
    write_play_header();
    write_numbers(1, 40, 16);
    write_numbers(2, 55, 16);
    write_numbers(3, 70, 16);
    write_numbers(4, 85, 16);
    write_numbers(5, 100, 16);
    write_numbers(6, 40, 24);
    write_numbers(7, 55, 24);
    write_numbers(8, 70, 24);
    write_numbers(9, 85, 24);

    while (1) {
	//Boss key start
	if (uart_get_char() == 0x1B){
		boss_key_function();
	}
	//Boss key slut
        int value = Joystickport();
// ALLE DISSE FUNKTIONER ER LAVET OG BENYTTES FORDI VI ER LØBET TØR FOR PLADS TIL AT LEGE MED STORE TAL
        // cursor bevægelse
        cursor_movement(value, &cursorUpDown, &cursorLeftRight);

        // levels
        level_selection(value, cursorUpDown, cursorLeftRight);

        // hvis cursor er over play eller exit
        playexit(value, cursorUpDown);

        // Fremvis poisition for cursor
        show_cursor_pos(cursorUpDown, cursorLeftRight);

        // opdater skærmen hvis cursor skifter position
        updateScreen(cursorUpDown, cursorLeftRight, prevCursorUpDown, prevCursorLeftRight);
        prevCursorUpDown = cursorUpDown;
        prevCursorLeftRight = cursorLeftRight;
        // pause
        if (value != 0) {
            pause_control(1000000);
        }
    }
}

int ScoreControls() {
	int value = 0;
	while(1) {
	//Boss key start
	if (uart_get_char() == 0x1B){
		boss_key_function();
	}
	//Boss key slut
	value = Joystickport();
	if (value == 16) {menu();}
	}
}


int MenuControls() {
	int cursor_placement = 0;
	int prev_cursor_placement = 0;
	int stop = 100;
	text_color_blink(0,0);
			gotoxy(62,17);
			write_help();
			write_score(60,23,7);
			gotoxy(63,29);
			write_play();
	while(1) {
	//Boss key start
	if (uart_get_char() == 0x1B){
		boss_key_function();
	}
	//Boss key slut
	int value = Joystickport();
	if (value == 1 || value == 5 || value== 9 || value == 17 || value == 21 || value == 25) { //UP
		if (cursor_placement> 0) {cursor_placement -= 1;}
	}
	if (value == 2 || value == 6 || value == 10 || value == 18 || value == 22 || value == 26) { //DOWN
		if (cursor_placement< 2) {cursor_placement += 1;}
	}
	if (value == 16 && cursor_placement == 0)  { //HELP
		ClearScreen();
		return 1;}
	if (value == 16 && cursor_placement == 1)  { //SCORE
		ClearScreen();
		return 2;}
	if (value == 16 && cursor_placement == 2)  { //PLAY
		ClearScreen();
		return 3;}
	if (cursor_placement != prev_cursor_placement) {
		text_color_blink(0,8);
		gotoxy(62,17);
		write_help();
		write_score(60,23,7);
		gotoxy(63,29);
		write_play();
	}
	if (cursor_placement == 0) {
		if (stop != 0) {
		prev_cursor_placement = cursor_placement;
		gotoxy(62,17);
		text_color_blink(1,1);
		write_help();
		text_color_blink(0,1);
		stop = 0;}
	}
	if (cursor_placement == 1) {
		if (stop != 1) {
		prev_cursor_placement = cursor_placement;
			text_color_blink(1,2);
			write_score(60,23,1);
			text_color_blink(0,2);;
				stop = 1;}
	}
	if (cursor_placement == 2) {
		if (stop != 2) {
			prev_cursor_placement = cursor_placement;
			gotoxy(63,29);
			text_color_blink(1,3);
			write_play();
			text_color_blink(0,3);
			stop = 2;}
		}
	if (value != 0) {
	pause_control(1000000);}}
}
void GAMEOVERControls() {
	int value = 0;
	while(1) {
		//Boss key start
		if (uart_get_char() == 0x1B){
		boss_key_function();
		}
		//Boss key slut
		value = Joystickport();
		if (value == 16) {menu();}
		}
}
int GAMEWINControls() {
	//Boss key start
	if (uart_get_char() == 0x1B){
		boss_key_function();
	}
	//Boss key slut
	int cursor_placement = 0;
	int prev_cursor_placement = 0;
	int stop = 100;
	text_color_blink(0,6);
	write_nextlevel(47,25,15);
	write_exit(60,23,15);
	while (1) {
		int value = Joystickport();
		if (value == 1 || value == 5 || value== 9 || value == 17 || value == 21 || value == 25) { //UP
			if (cursor_placement> 0) {cursor_placement -= 1;}
		}
		if (value == 2 || value == 6 || value == 10 || value == 18 || value == 22 || value == 26) { //DOWN
			if (cursor_placement< 1) {cursor_placement += 1;}
		}
		if (value == 16 && cursor_placement == 0)  { //NEXT LEVEL
			ClearScreen();
			return 1;}
		if (value == 16 && cursor_placement == 1)  { //MENU
			ClearScreen();
			return 2;}
		if (cursor_placement != prev_cursor_placement) {
				text_color_blink(0,1);
				write_nextlevel(47,25,15);
				write_exit(60,23,15);
			}
		if (cursor_placement == 0) {
			if (stop != 0) {
			prev_cursor_placement = cursor_placement;

			text_color_blink(1,5);
			write_nextlevel(47,25,1);
			text_color_blink(0);
			stop = 0;}
		}
		if (cursor_placement == 1) {
			if (stop != 1) {
			prev_cursor_placement = cursor_placement;
				text_color_blink(1,4);
				write_exit(60,23,1);
				text_color_blink(0);;
					stop = 1;}
		}
		if (value != 0) {
			pause_control(1000000);}
	}
}
