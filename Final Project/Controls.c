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

// Funktion som tager sværhedsgraden som input og ændrer hastighed og layout af level
int levelControls(int difficulty) {
	// Initialiser variabler
	LED(8);
	int rocket_position = 38;
	int speed = 0;
	int level = 0;
	int pause = 0;
	// Konfigurer niveauindstillinger baseret på sværhedsgrad
	if (difficulty == 1) {speed = 10;level = 1;pause = 2000;Asteroid1(0,14,10); Asteroid1(1, 80,20);}
	if (difficulty == 2) {speed = 10;level = 2;pause = 1500;Asteroid1(0, 20, 12);Asteroid1(1, 70, 7);Asteroid2(0,90,6);Asteroid2(1,50,9);}
	if (difficulty == 3) {speed = 9;level = 3;pause = 1000;Asteroid1(0,14,15); Asteroid1(1, 80, 7);Asteroid2(0,90,20);Asteroid2(1,32,18);Asteroid3(0,70,10);Asteroid3(1,70,15);}
	if (difficulty == 4) {speed = 9;level = 4;pause = 500;Asteroid1(0,14,15); Asteroid1(1, 80, 7);Asteroid2(0,90,20);Asteroid2(1,32,18);Asteroid3(0,70,10);Asteroid3(1,70,15); Asteroid4(0,70,20); Asteroid4(1,20,15);}
	if (difficulty == 5) {speed = 8;level = 5;pause = 500;Asteroid1(0,14,7); Asteroid1(1, 14, 14);Asteroid2(0,50,10);Asteroid2(1,90,10);Asteroid3(0,110,10);Asteroid3(1,70,10); Asteroid4(0,120,10); Asteroid4(1,70,25);}
	if (difficulty == 6) {speed = 8;level = 6;pause = 0;Asteroid1(0,14,6); Asteroid1(1, 14, 12);Asteroid2(0,14,18);Asteroid2(1,14,24);Asteroid3(0,120,6);Asteroid3(1,120,12); Asteroid4(0,120,18); Asteroid4(1,120,28);}
	if (difficulty == 7) {speed = 7;level = 7;pause = 0;Asteroid1(0,14,13); Asteroid1(1, 14, 14);Asteroid2(0,50,23);Asteroid2(1,90,8);Asteroid3(0,110,17);Asteroid3(1,70,10); Asteroid4(0,120,13); Asteroid4(1,70,23);}
	if (difficulty == 8) {speed = 7;level = 8;pause = 0;Asteroid1(0,65,5); Asteroid1(1, 75, 5);Asteroid2(0,50,10);Asteroid2(1,90,10);Asteroid3(0,35,15);Asteroid3(1,105,15); Asteroid4(0,20,20); Asteroid4(1,120,20);}
	if (difficulty == 9) {speed = 7;level = 9;pause = 0;Asteroid1(0, 20, 20);Asteroid1(1, 70, 30);Asteroid2(0, 30, 25);Asteroid2(1, 40, 15);Asteroid3(0, 100, 20);Asteroid3(1, 70, 30);Asteroid4(0, 57, 17);Asteroid4(1, 89, 10);}

	int cursor_leftright = 38;
	int prev_cursor_leftright = 3;
	int shot_x = 0;
	int shot_y = 0;

	// Initialiser raketen og vis den på skærmen
	initiate_rocket(cursor_leftright, 38);
	text_color_blink(0,8);
	int shot = 0;
	uint8_t value;
	while(1) {
		//Boss key start
				if (uart_get_char() == 0x1B){
					boss_key_function();
				}
		//Boss key slut
		// Vis niveauinformation og fjender
		level_lcd(difficulty,globalLives,globalPoints);
		enemiesbegin(speed,level,0);

		// Læs input fra brugeren (joystick eller tastatur)
		if (UserPlayMode == 0) {
		value =  Joystickport();//Joystickport();
		} else if (UserPlayMode == 1) {
			value = readKeyboard();
		}
		// Opdater raketcursor baseret på brugerinput
		if (cursor_leftright == 139 && (value == 8 || value == 'd')) {
			cursor_leftright = 3;}
		if (cursor_leftright == 3 && value == 4) {
					cursor_leftright = 139;}

	if (cursor_leftright > 3 && (value == 4 || value == 'a') ) { //LEFT
						if (cursor_leftright> 3) {cursor_leftright -= 1;}
						pause_control(pause<<2);
					}
			if (cursor_leftright < 139 && (value == 8 || value == 'd')) { //RIGHT
						if (cursor_leftright< 139) {cursor_leftright += 1;}
						pause_control(pause<<2);
					}
	 // Opdater raketcursoren og vis ændringer på skærmen
	if (cursor_leftright != prev_cursor_leftright) {
						blink(0);
						fgcolor(7);
						delete_rocket(prev_cursor_leftright , 38);
						prev_cursor_leftright = cursor_leftright;
						initiate_rocket(cursor_leftright, 38);
						rocket_position =cursor_leftright;
							}
	// Behandl skud fra brugeren
	if (value == 16 || value == ' ') { //SKUD
		shot_x = cursor_leftright;
		shot_y = 36;
		shot = 1;
		addShot(shot_x, shot_y);
		prevShot(shot_x, shot_y);
		if (UserPlayMode == 0) {
		pause_control(200000);
		}
		}
	// Opdater og vis skud på skærmen	
	if (shot == 1) {
	        updateAndPrintShots(pause,level, speed, rocket_position);
	    }
	}
}

//Funktioner der kontrollerer menu
int HelpControls() {
	LED(8);
	uint8_t value = 0;
	while(1) {
	//Boss key start
	if (uart_get_char() == 0x1B){
		boss_key_function();
	}
	//Boss key slut
	if (UserPlayMode == 0) {
			value =  Joystickport();//Joystickport();
			} else if (UserPlayMode == 1) {
				value = readKeyboard();
			}
	if (value == 16 || value == ' ') {menu();}
	}
}

//################## FUNKTIONER TIL PLAYMENU##################################
// DE ER LAVET FORDI VI BRUGTE FOR MEGET PLADS
// funktion for cursor bevægelse
void cursor_movement(uint8_t value, int *cursorUpDown, int *cursorLeftRight) {
    if ((value == 1 || value == 'w') && *cursorUpDown > 0) { // UP
        (*cursorUpDown)--;
    } else if ((value == 2 || value == 's') && *cursorUpDown < 4) { // DOWN
        (*cursorUpDown)++;
    } else if ((value == 4 || value == 'a') && *cursorLeftRight > 0) { // LEFT
        (*cursorLeftRight)--;
    } else if ((value == 8 || value == 'd') && *cursorLeftRight < 4) { // RIGHT
        (*cursorLeftRight)++;
    }
}

// Funktion for at bestemme level
void level_selection(uint8_t value, int cursorUpDown, int cursorLeftRight) {
    if (value == 16 || value == ' ') {
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

// Funktion til hvis der trykkes på exit eller play
void playexit(uint8_t value, int cursorUpDown) {
    if (value == 16 || value == ' ') {
        ClearScreen();
        if (cursorUpDown == 0) { level_1();// PLAY
        } else if (cursorUpDown == 3) { // EXIT
            menu();
        }
    }
}

// Opdater skærmen
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

// Funktion som viser kursorposition
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

// Kontrol af spil
int PlayControls() {
    int cursorUpDown = 0;
    int cursorLeftRight = 0;
    int prevCursorUpDown = 0;
    int prevCursorLeftRight = 0;
    uint8_t value;
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
	if (UserPlayMode == 0) {
			value =  Joystickport();//Joystickport();
			} else if (UserPlayMode == 1) {
				value = readKeyboard();
			}
// ALLE DISSE FUNKTIONER ER LAVET OG BENYTTES FORDI VI ER LØBET TØR FOR PLADS TIL AT LEGE MED STORE TAL
	    
        // Kursor bevægelse
        cursor_movement(value, &cursorUpDown, &cursorLeftRight);

        // Levels
        level_selection(value, cursorUpDown, cursorLeftRight);

        // Hvis cursor er over play eller exit
        playexit(value, cursorUpDown);

        // Fremvis poisition for cursor
        show_cursor_pos(cursorUpDown, cursorLeftRight);

        // Opdater skærmen hvis cursor skifter position
        updateScreen(cursorUpDown, cursorLeftRight, prevCursorUpDown, prevCursorLeftRight);
        prevCursorUpDown = cursorUpDown;
        prevCursorLeftRight = cursorLeftRight;
        // Pause
        if (value != 0 && UserPlayMode == 0) {
            pause_control(1000000);
        }
    }
}

//Funktion for kontrol af score menu
int ScoreControls() {
	uint8_t value = 0;
	while(1) {
	//Boss key start
	if (uart_get_char() == 0x1B){
		boss_key_function();
	}
	//Boss key slut
	if (UserPlayMode == 0) {
			value =  Joystickport();//Joystickport();
			} else if (UserPlayMode == 1) {
				value = readKeyboard();
			}
	if (value == 16 || value == ' ') {menu();}
	}
}

//Funktion for kontrol af menu
int MenuControls() {
	int cursor_placement = 0;
	int prev_cursor_placement = 0;
	int stop = 100;
	text_color_blink(0,8);
			gotoxy(62,17);
			write_help();
			write_score(60,23,7);
			gotoxy(63,29);
			write_play();
			uint8_t value;
	while(1) {
	//Boss key start
	if (uart_get_char() == 0x1B){
		boss_key_function();
	}
	//Boss key slut
	if (UserPlayMode == 0) {
			value =  Joystickport();//Joystickport();
			} else {
				value = readKeyboard();
			}
	if (value == 1 || value == 5 || value== 9 || value == 17 || value == 21 || value == 25 || value == 'w') { //UP
		if (cursor_placement> 0) {cursor_placement -= 1;}
	}
	if (value == 2 || value == 6 || value == 10 || value == 18 || value == 22 || value == 26 || value == 's') { //DOWN
		if (cursor_placement< 2) {cursor_placement += 1;}
	}
	if ((value == 16 || value == ' ') && cursor_placement == 0)  { //HELP
		ClearScreen();
		return 1;}
	if ((value == 16 || value == ' ') && cursor_placement == 1)  { //SCORE
		ClearScreen();
		return 2;}
	if ((value == 16 || value == ' ') && cursor_placement == 2)  { //PLAY
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
			write_score(60,23,2);
			text_color_blink(0,2);
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
	if (value != 0 && UserPlayMode == 0) {
	pause_control(1000000);}}
}

// Kontrol ved tabt spil
void GAMEOVERControls() {
	uint8_t value;
	while(1) {
		LED(8);
		//Boss key start
		if (uart_get_char() == 0x1B){
		boss_key_function();
		}
		//Boss key slut
		if (UserPlayMode == 0) {
				value =  Joystickport();//Joystickport();
				} else if (UserPlayMode == 1) {
					value = readKeyboard();
				}
		if ((value == 16 || value == ' ')) {menu();}
		}
}

// Kontrol ved vundet spil
int GAMEWINControls() {
	//Boss key start
	if (uart_get_char() == 0x1B){
		boss_key_function();
	}
	//Boss key slut
	int cursor_placement = 0;
	int prev_cursor_placement = 0;
	int stop = 100;
	text_color_blink(0,4);
	write_nextlevel(47,25,15);
	write_exit(60,23,15);
	uint8_t value;
	while (1) {
		if (UserPlayMode == 0) {
				value =  Joystickport();//Joystickport();
				} else if (UserPlayMode == 1) {
					value = readKeyboard();
				}
		if (value == 1 || value == 5 || value== 9 || value == 17 || value == 21 || value == 25 || value == 'w') { //UP
			if (cursor_placement> 0) {cursor_placement -= 1;}
		}
		if (value == 2 || value == 6 || value == 10 || value == 18 || value == 22 || value == 26|| value == 's') { //DOWN
			if (cursor_placement< 1) {cursor_placement += 1;}
		}
		if ((value == 16 || value == ' ') && cursor_placement == 0)  { //NEXT LEVEL
			ClearScreen();
			return 1;}
		if ((value == 16 || value == ' ') && cursor_placement == 1)  { //MENU
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
			text_color_blink(0,5);
			stop = 0;}
		}
		if (cursor_placement == 1) {
			if (stop != 1) {
			prev_cursor_placement = cursor_placement;
				text_color_blink(1,4);
				write_exit(60,23,1);
				text_color_blink(0,4);
					stop = 1;}
		}
		if (value != 0 && UserPlayMode == 0) {
			pause_control(1000000);}
	}
}
