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

// Funktion til at håndtere niveau 1
void level_1(){
	border();
	globalLives = 3; // Nulstiller antallet af liv
	timer = 0; // Nulstiller timer
	enemiesbegin(10,1,1); // Initialiserer fjender for niveau 1
	while(1) { // Uendeligt loop for at opretholde spil
	levelControls(1); // Håndterer styring og logik for niveau 1
	}
}
// Funktion til at håndtere niveau 2
void level_2(){
	border();
	globalLives = 3;
		timer = 0;
		enemiesbegin(10,2,1);
	while(1) {
		levelControls(2);
		}
}
// Funktion til at håndtere niveau 3
void level_3(){
	border();
	globalLives = 3;
		timer = 0;
		enemiesbegin(9,2,1);
	while(1) {
		levelControls(3);
		}
}
// Funktion til at håndtere niveau 4
void level_4(){
	border();
	globalLives = 3;
		timer = 0;
		enemiesbegin(9,4,1);
	while(1) {
		levelControls(4);
		}
}
// Funktion til at håndtere niveau 5
void level_5(){
	border();
	globalLives = 3;
		timer = 0;
		enemiesbegin(8,5,1);
	while(1) {
		levelControls(5);
		}
}
// Funktion til at håndtere niveau 6
void level_6(){
	border();
	globalLives = 3;
		timer = 0;
		enemiesbegin(8,6,1);
	while(1) {
		levelControls(6);
		}
}
// Funktion til at håndtere niveau 7
void level_7(){
	border();
	globalLives = 3;
		timer = 0;
		enemiesbegin(7,7,1);
	while(1) {
		levelControls(7);
		}
}
// Funktion til at håndtere niveau 8
void level_8(){
	border();
	globalLives = 3;
		timer = 0;
		enemiesbegin(7,8,1);
	while(1) {
		levelControls(8);
		}
}
// Funktion til at håndtere niveau 9
void level_9(){
	border();
	globalLives = 3;
	timer = 0;
	enemiesbegin(7,9,1);
	while(1) {
		levelControls(9);
		}
}
