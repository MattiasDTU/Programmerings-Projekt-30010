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

// Funktion til at initialisere en fjende på en given position (x, y) med en given farve
void initiate_enemies(int x, int y,int color) {
    fgcolor(color);
    gotoxy(x,y);
    printf("%c", 204);
    printf("%c", 219);
    printf("%c", 185);
    fgcolor(15);
}

// Funktion til at fjerne en fjende fra en given position (x, y).
void clear_enemy(int x, int y) {
    gotoxy(x, y);
    printf("   ");
}

// Funktion til at håndtere kollision mellem en fjende og en asteroid baseret på deres positioner
int gravityenemy(struct enemy enemy_values, struct vector_t asteroid_values) {
    if (abs(enemy_values.x - asteroid_values.x) <= 8 &&
    	    (((asteroid_values.y - enemy_values.y) == 3) ||
    	     ((asteroid_values.y - enemy_values.y) == 2) ||
    	     ((asteroid_values.y - enemy_values.y) == 1) ||
			 (asteroid_values.y - enemy_values.y) == 0)) {
        if (enemy_values.x < asteroid_values.x) {
            return -1;
        } else if (enemy_values.x > asteroid_values.x) {
            return +1;
        } else {
            return 0;
        }
    } else {
        return 0; // Returnerer retningen for fjenden baseret på kollisionen med asteroiden.
    }
}

// Funktion til at håndtere kollisionen mellem skud og fjender.
void handleEnemyCollision(int i,int j,int level) {
    if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {
    	LED(3);

        int pointsEarned = 0;

        switch (enemies_level[j].color) {
            case 1:
                pointsEarned = 2;
                break;
            case 2:
                pointsEarned = 4;
                break;
            case 3:
                pointsEarned = 6;
                break;
            case 4:
                pointsEarned = 8;
                break;
            case 5:
                pointsEarned = 10;
                break;
        }
        points(pointsEarned); // Håndterer kollisionen ved at opdatere point, fjerne fjenden og fjerne skuddet.
	
        clear_enemy(enemies_level[j].x, enemies_level[j].y);
        if (shots[i].x != 0 && shots[i].y != 0) {
        gotoxy(shots[i].x,shots[i].y);
        printf(" ");
        }
        shots[i].x = 0;
        shots[i].y = 0;
        enemies_level[j].x = 0;
        enemies_level[j].y = 0;
        LED(8);
    }
}

// Funktion til at starte eller genstarte fjenderne med en given hastighed og niveau.
void enemiesbegin(int speed,int level, int reset) {
	int gravityResult = 0;
	static int amount;
	static int bomb_amount = 0;
	if (reset) {
	        amount = 0;
	        bomb_amount = 0;
	        callreturn(5);
	    }
	int size = (level >=1 && level <= 9) ? 10 * level : 0;
	if (amount == size>>2 && bomb_amount == 0) {
			powerUpBomb();
			bomb_amount = 1;
			}
	if (globalLives != 0) {
	    if (timer == speed && amount < size) {
	    	//Spawn enemies random
	    	enemies_level[amount].x = rand() % 137 + 2;
	    	enemies_level[amount].y = 2;
	    	enemies_level[amount].color =rand() % 5 + 1;
	    	old_enemies_level[amount].x = enemies_level[amount].x;
	        initiate_enemies(enemies_level[amount].x, enemies_level[amount].y,enemies_level[amount].color);
	        amount++;
	    for (int j = 0; j < amount; j++) {
	    	if (enemies_level[j].y != 39) {
	    		if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {
	    			for (int i = 0; i< 21; i++) {
					if (level > 0) {gravityResult = gravityenemy(enemies_level[j], very_small_asteroid1[i]);}
					if (level > 1) {gravityResult +=gravityenemy(enemies_level[j], very_small_asteroid2[i]);}
					if (level > 2) {gravityResult +=gravityenemy(enemies_level[j], very_small_asteroid3[i]);}
					if (level > 3) {gravityResult +=gravityenemy(enemies_level[j], very_small_asteroid4[i]);}
					if (gravityResult != 0) {
						enemies_level[j].x += gravityResult;
						break;
						}
				 }
			for (int i = 0; i< 37; i++) {
					if (level > 0) {gravityResult = gravityenemy(enemies_level[j], small_asteroid1[i]);}
					if (level > 1) {gravityResult += gravityenemy(enemies_level[j], small_asteroid2[i]);}
					if (level > 2) {gravityResult +=gravityenemy(enemies_level[j], small_asteroid3[i]);}
					if (level > 3) {gravityResult +=gravityenemy(enemies_level[j], small_asteroid4[i]);}
					if (gravityResult != 0) {
						enemies_level[j].x += gravityResult;
						break;
						}
				}
	    			// ryk enemy hvis den ikke er ramt
	    				clear_enemy(old_enemies_level[j].x, enemies_level[j].y);
	    				enemies_level[j].y++;
	    				old_enemies_level[j].x = enemies_level[j].x;
	    				initiate_enemies(enemies_level[j].x, enemies_level[j].y,enemies_level[j].color);
	    		}
	    	}else {
	    			// Enemy er nået bunden
	    		LED(1);
	    			clear_enemy(enemies_level[j].x, enemies_level[j].y);
	    			enemies_level[j].x = 0;
	    			enemies_level[j].y = 0;
					lives(1);
					LED(8);
	    		}
	    	}
	    timer = 0;
		}
		//Tjek hvis alle enemies har nået bunden
	    if (amount == size && timer == speed) {
	    	 for (int j = 0; j < amount; j++) {
	    		 if (enemies_level[j].y != 39) {
	    			 if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {
						// Ryk og print enemies som ikke er døde
	    				 for (int i = 0; i< 21; i++) {
	    				 					if (level > 0) {gravityResult = gravityenemy(enemies_level[j], very_small_asteroid1[i]);}
	    				 					if (level > 1) {gravityResult +=gravityenemy(enemies_level[j], very_small_asteroid2[i]);}
	    				 					if (level > 2) {gravityResult +=gravityenemy(enemies_level[j], very_small_asteroid3[i]);}
	    				 					if (level > 3) {gravityResult +=gravityenemy(enemies_level[j], very_small_asteroid4[i]);}
	    				 					if (gravityResult != 0) {
	    				 						enemies_level[j].x += gravityResult;
	    				 						break;
	    				 						}
	    				 				 }
	    				 			for (int i = 0; i< 37; i++) {
	    				 					if (level > 0) {gravityResult = gravityenemy(enemies_level[j], small_asteroid1[i]);}
	    				 					if (level > 1) {gravityResult += gravityenemy(enemies_level[j], small_asteroid2[i]);}
	    				 					if (level > 2) {gravityResult +=gravityenemy(enemies_level[j], small_asteroid3[i]);}
	    				 					if (level > 3) {gravityResult +=gravityenemy(enemies_level[j], small_asteroid4[i]);}
	    				 					if (gravityResult != 0) {
	    				 						enemies_level[j].x += gravityResult;
	    				 						break;
	    				 						}
	    				 				}
	    				 	    			// ryk enemy hvis den ikke er ramt
	    				 	    				clear_enemy(old_enemies_level[j].x, enemies_level[j].y);
	    				 	    				enemies_level[j].y++;
	    				 	    				old_enemies_level[j].x = enemies_level[j].x;
	    				 	    				initiate_enemies(enemies_level[j].x, enemies_level[j].y,enemies_level[j].color);
						  }
	    			 } else {
	    			 //enemy er nået bunden og skal fjernes
	    				 LED(1);
					clear_enemy(enemies_level[j].x, enemies_level[j].y);
					enemies_level[j].x = 0;
					enemies_level[j].y = 0;
					lives(1);
					LED(8);
	    		 }
	    	 }
	    	 timer = 0;

	    	}
	    }
}
