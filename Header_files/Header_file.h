#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_
#define ESC 0x1B

/* Includes -------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
//### STRUCT ####
struct vector_t {
	int x;
	int y;
};
struct enemy {
    int x;
    int y;
    int color;
};
struct Score {
    long int score_count;
};
//ARRAYS
extern struct Score scores[10];
struct Score scores[10];
struct vector_t heart[2];
struct vector_t bomb[10];
struct vector_t very_small_asteroid1[21];
struct vector_t very_small_asteroid2[21];
struct vector_t very_small_asteroid3[21];
struct vector_t very_small_asteroid4[21];
struct vector_t very_small_asteroid5[21];
struct vector_t small_asteroid1[37];
struct vector_t small_asteroid2[37];
struct vector_t small_asteroid3[37];
struct vector_t small_asteroid4[37];
struct vector_t small_asteroid5[37];
struct enemy enemies_level[100];
struct enemy old_enemies_level[100];
struct vector_t shots[100];
struct vector_t oldshots[100];
struct vector_t hole[15];


// GLOBAL VARIABLER
int globalLives;
int globalPoints;
int UserPlayMode;
volatile uint32_t timer;




/* Exported functions -------------------------------------------------- */
// #### MENU_TEXT.c ####
void write_score();
void write_play();
void write_menu();
void write_help();
void write_help_header();
void write_score_header(int x, int y, int color);
void write_exit();
void write_Welcome();
void write_highscore();
void write_exitplay();
void write_play_header();
void write_numbers(int number,int x,int y);
void write_asteroid(int x, int y);
void write_gameover(int x, int y);
void write_colon(int x,int y,int color);
void write_yourendscore(int x,int y, int color);
void write_skull(int x, int y, int color);
void write_youwin(int x, int y, int color);
void write_nextlevel(int x, int y, int color);

// #### Controls.c ####
int ScoreControls();
int HelpControls();
int MenuControls();
int PlayControls();
void cursor_movement(uint8_t value, int *cursorUpDown, int *cursorLeftRight);
void level_selection(uint8_t value, int cursorUpDown, int cursorLeftRight);
void playexit(uint8_t value, int cursorUpDown);
void updateScreen(int cursorUpDown, int cursorLeftRight, int prevCursorUpDown, int prevCursorLeftRight);
void show_cursor_pos(int cursorUpDown, int cursorLeftRight);
int levelControls(int difficulty);
void GAMEOVERControls();
int GAMEWINControls();

// #### dataread.c ####
uint16_t Joystickport();
uint8_t readKeyboard();

//### LCD/LED ####
void lcd_resetwrite(const char* input_string, int line_number);
void lcd_write_index(const char* input_string,int line_number, int index);
void level_lcd(int level, int globalLives, int globalPoints);
void LED(int color);


// #### ansi.c ####
void fgcolor(uint8_t foreground);
void blink(uint8_t on);
void gotoxy();
void ClearScreen();
void cursor_up(int amount);
void cursor_down(int amount);
void cursor_right(int amount);
void cursor_left(int amount);
void underline(uint8_t on);
void hideCursor();

// #### design.c ####
void border();
void text_color_blink(int on,int color);
void background();
void box();
void credits();
void Smallbox();
void help_design();
void drawLevelBoxes();


// #### menu.c ####
void menuHELP();
void menuSCORE();
void menuPLAY();
void menu();
void menuGAMEOVER();
void menuWIN(int level);
void ChooseUserInput();

// #### game.c ####
//ENEMIES
void initiate_enemies(int x, int y,int color);
void clear_enemy(int x, int y);
void handleEnemyCollision(int i,int j,int level);
int gravityenemy(struct enemy enemy_values, struct vector_t asteroid_values);
void enemiesbegin(int speed,int level, int reset);

//PLAYER
void initiate_rocket(int x, int y);
void delete_rocket(int x, int y);

//POWER UPS AND OTHER
void heart_power(const int x, const int y);
void bomb_power(const int x, const int y);
void print_worm_hole(int x, int y);
void initiate_worm_hole(int x,int y);
int hitpowerupHeart(int pos);
void deletepowerUpHeart();
int hitpowerupBomb(struct vector_t shot_values,int level);
void deletepowerUpBomb();
void powerUpBomb();
void powerUpHeart();

//GAMEMECHANICS
void initiate_shot(int x, int y);
void pause_control(int time_between);
void points(int points);
void addShot(int x, int y);
void updateAndPrintShots(int pause, int level,int speed, int position);
void update_score(long int score);
void lives(int damage);
void prevShot(int x, int y);
void clearallshots();
int callreturn (int value);
bool isCollision(struct vector_t shot_values, struct enemy enemy_values);
bool isCollisionHole(struct vector_t shot_values, struct vector_t hole);
bool isAstroidCollision(struct vector_t shot_values, struct vector_t asteroid_values);
int gravity(struct vector_t shot_values, struct vector_t asteroid_values);

//TIMER
void config_timer();
void TIM1_BRK_TIM15_IRQHandler(void);

//#### levels.c ####
void level_1();
void level_2();
void level_3();
void level_4();
void level_5();
void level_6();
void level_7();
void level_8();
void level_9();

//#### asteroids.c ####
void Asteroid1(int size, const int x, const int y);
void Asteroid2(int size, const int x, const int y);
void Asteroid3(int size, const int x, const int y);
void Asteroid4(int size, const int x, const int y);
void print_small_asteroid(int x, int y);
void print_big_asteroid(int x, int y);


//BOSS KEY
void boss_key_function();
void boss_spreadsheet();

//BUZZER
void TIM2_IRQHandler(void);
void inittim2();
void setFreq(uint16_t freq);
void delaysong(uint16_t milli);
void playingsong(int value);

#endif // _HEADER_FILE_H_
