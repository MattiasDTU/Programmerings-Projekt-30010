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

// Funktion til at vise hjælpemenu
void menuHELP() {
	// Initialiserer visuelle elementer som LED, baggrund, liv og asteroider
	LED(8);
	background();
	lives(0);
	write_asteroid(2,2);
	border();
	box();
	text_color_blink(1,4);
	write_exit();
	text_color_blink(0,4);
	help_design();
	lcd_resetwrite("Controls and object of the game!",1);
	HelpControls();
}

// Funktion til at vise menu for spil
void menuPLAY() {
    background();
    border();
    lives(0);
    write_asteroid(2, 2);
    write_asteroid(90, 20);
    lcd_resetwrite("Select a level to play", 1);
    drawLevelBoxes();
    PlayControls();
}

// Funktion til at vise menu for highscores
void menuSCORE() {
	background();
	border();
	write_asteroid(2,2);
	write_asteroid(90,20);
	box();
	text_color_blink(1,5);
	write_exit();
	text_color_blink(0,5);
	write_highscore();
	lcd_resetwrite("Look at your highscore!",1);

	// Viser top 10 highscores
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
// Hovedmenufunktion
void menu() {
	 // Ryd skærmen og initialiser visuelle elementer
	ClearScreen();
	background(); //FØRST
	border();
	write_asteroid(2,2);
	write_asteroid(90,20);
	write_Welcome();
	box();
	gotoxy(0,0);
	printf("%d",UserPlayMode);
	gotoxy(60,10);
	write_menu();
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

// Funktion til visning af game over-menu
void menuGAMEOVER() {
	 // Afspil lyd, ryd skærmen og initialiser visuelle elementer
	playingsong(1);
	ClearScreen();
	background(); //FØRST
	border();
	text_color_blink(1,1);
	write_exit();
	text_color_blink(0,1);
	write_gameover(37,5);
	write_score(50,15,1);
 	write_colon(75,16,1);
	write_yourendscore(77,14,1);
	globalPoints = 0;
	write_skull(67,22,7);
	lcd_resetwrite("",1);
	lcd_write_index("GAME",2,50);
	lcd_write_index("OVER!",3,50);
	lcd_write_index("   ",1,0);
	GAMEOVERControls();
}

// Funktion til visning af vindermenu med angivet niveau
void menuWIN(int level) {
	// Afspil lyd, ryd skærmen og initialiser visuelle elementer
	playingsong(0);
	ClearScreen();
	background(); //FØRST
	border();
	text_color_blink(0,7);
	write_nextlevel(47,25,15);
	write_exit(60,23,15);
	write_youwin(46,5,2);
	write_score(55,15,1);
	write_colon(80,16,1);
	write_yourendscore(82,14,1);
	globalPoints = 0;
	lcd_resetwrite("",1);
	lcd_write_index("YOU WIN!",2,45);
	lcd_write_index("Quit or play again!",3,12);
	lcd_write_index("   ",1,0);
	int value = GAMEWINControls();
	// Start næste niveau baseret på det aktuelle niveau
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
// Funktion til at vælge brugerinputstype (tastatur eller joystick)
void ChooseUserInput() {
	static int once = 0;
	uint8_t value = readKeyboard();
	gotoxy(50,10);
	printf("Press 'x' for keyboard controls. Wait for box to turn red, then press 'p'. (IN BETA)");
	gotoxy(55,11);
	printf("For joystick controls press 'p'");
	 // Aktiver tastaturkontrol ved tryk på 'x'
	if (value == 'x') {
		text_color_blink(1,1);
		gotoxy(67,15);
		Smallbox();
		text_color_blink(0,1);
		gotoxy(0,0);
		printf("keyboard controls activated");
		UserPlayMode = 1;
		once = 1;
	}
	else if (once == 0) {
		gotoxy(67,15);
		Smallbox();
		UserPlayMode = 0;
	}
	if (value == 'p') {
		menu();
	}

}

