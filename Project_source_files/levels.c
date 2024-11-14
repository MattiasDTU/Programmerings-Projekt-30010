/*
 * levels.c
 *
 *  Created on: 11. jan. 2024
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
void level_1(){
	border();
	globalLives = 3;
	timer = 0;
	while(1) {
	levelControls(1);
	}
}
void level_2(){
	border();
	globalLives = 3;
		timer = 0;
	while(1) {
		levelControls(2);
		}
}
void level_3(){
	border();
	globalLives = 3;
		timer = 0;
	while(1) {
		levelControls(3);
		}
}
void level_4(){
	border();
	globalLives = 3;
		timer = 0;
	while(1) {
		levelControls(4);
		}
}
void level_5(){
	border();
	globalLives = 3;
		timer = 0;
	while(1) {
		levelControls(5);
		}
}
void level_6(){
	border();
	globalLives = 3;
		timer = 0;
	while(1) {
		levelControls(6);
		}
}
void level_7(){
	border();
	globalLives = 3;
		timer = 0;
	while(1) {
		levelControls(7);
		}
}
void level_8(){
	border();
	globalLives = 3;
		timer = 0;
	while(1) {
		levelControls(8);
		}
}
void level_9(){
	border();
	globalLives = 3;
		timer = 0;
	while(1) {
		levelControls(9);
		}
}
void play_whole_game() {

}
