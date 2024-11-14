/*
 * game.c
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

struct Score scores[10];
void update_score(long int score) {
    for (int i = 0; i < 10; i++) {
        if (score > scores[i].score_count) {
        	if (i != 9) {
        	scores[i+1].score_count = scores[i].score_count;}
            scores[i].score_count = score;
            score = 0;
            break;
        }
    }
}


void pause_control(int time_between) {
	int first = 0;
	while (first < time_between) {first += 1;}
}
void initiate_rocket(int x, int y){
	gotoxy(x,(y-1));
	printf("%c",186);
	gotoxy(x,y);
	printf("%c",219);

	fgcolor(1);
	gotoxy(x,(y+1));
	printf("%c",177);
	fgcolor(15);

	gotoxy((x-1),(y+1));
	printf("%c",47);
	gotoxy((x+1),(y+1));
	printf("%c",92);
}
void delete_rocket(int x, int y){
	gotoxy(x,(y-1));
	printf(" ");
	gotoxy(x,y);
	printf(" ");

	fgcolor(1);
	gotoxy(x,(y+1));
	printf(" ");
	fgcolor(15);

	gotoxy((x-1),(y+1));
	printf(" ");
	gotoxy((x+1),(y+1));
	printf(" ");
}

void initiate_enemies(int x, int y,int color) {
    fgcolor(color);
    gotoxy(x,y);
    printf("%c", 204);
    printf("%c", 219);
    printf("%c", 185);
    fgcolor(15);
}


void points(int points) {
    globalPoints += points;
}
void lives(int damage) {
    globalLives -= damage;
}
void clear_enemy(int x, int y) {
    gotoxy(x, y);
    printf("   ");
}

struct enemy enemies_level[100];
struct enemy old_enemies_level[100];
struct Shot shots[100];
struct Shot oldshots[100];
void addShot(int x, int y) {
    for (int i = 0; i < 100; ++i) {
        if (shots[i].x == 0 && shots[i].y == 0) {
            shots[i].x = x;
            shots[i].y = y;
            break;
        }
    }
}

int gravityenemy(struct enemy enemy_values, struct Asteroid asteroid_values) {
    if (abs(enemy_values.x - asteroid_values.x) <= 8 && enemy_values.y == asteroid_values.y) {
        if (enemy_values.x < asteroid_values.x) {
            return -1;
        } else if (enemy_values.x > asteroid_values.x) {
            return +1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void prevShot(int x, int y) {
    for (int i = 0; i < 100; ++i) {
        if (oldshots[i].x == 0 && shots[i].y == 0) {
            oldshots[i].x = x;
            oldshots[i].y = y;
            break;
        }
    }
}
bool isCollision(struct Shot shot_values, struct enemy enemy_values) {
    return (shot_values.x == enemy_values.x || shot_values.x == enemy_values.x + 1 || shot_values.x == enemy_values.x + 2) && (shot_values.y == enemy_values.y);
}
bool isAstroidCollision(struct Shot shot_values, struct Asteroid asteroid_values) {
    return (shot_values.x == asteroid_values.x && shot_values.y == asteroid_values.y);
}
int gravity(struct Shot shot_values, struct Asteroid asteroid_values) {
    if (abs(shot_values.x - asteroid_values.x) <= 8 && shot_values.y == asteroid_values.y) {
        if (shot_values.x < asteroid_values.x) {
            return +1;
        } else if (shot_values.x > asteroid_values.x) {
            return -1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void enemiesbegin(int speed,int level, int reset) {
	int gravityResult = 0;
	static int amount;
	if (reset) {
	        amount = 0;
	    }
	int size = (level >=1 && level <= 9) ? 10 * level : 0;
	if (globalLives != 0) {
		gotoxy(0,0);
		printf("enemies left to spawn %d", amount);
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
	    			clear_enemy(enemies_level[j].x, enemies_level[j].y);
	    			enemies_level[j].x = 0;
	    			enemies_level[j].y = 0;
					lives(1);
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
					clear_enemy(enemies_level[j].x, enemies_level[j].y);
					enemies_level[j].x = 0;
					enemies_level[j].y = 0;
					lives(1);
	    		 }
	    	 }
	    	 timer = 0;

	    	}
	    }
}
void clearallshots() {
	for (int j = 0; j <100; j++) {
		shots[j].x = 0;
		shots[j].y = 0;
	}
}
void handleEnemyCollision(int i,int j,int level) {
    if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {

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
        points(pointsEarned);

        clear_enemy(enemies_level[j].x, enemies_level[j].y);
        gotoxy(shots[i].x,shots[i].y);
        printf(" ");
        shots[i].x = 0;
        shots[i].y = 0;
        enemies_level[j].x = 0;
        enemies_level[j].y = 0;
    }
}
void updateAndPrintShots(int pause, int level,int speed) {
	static int once = 0;
	static int enemies = 0;
	int enemy_down;
	int gravityResult;
	if (once != 1) {
		enemiesbegin(speed,level, 1);
	}
	if (!once) {
			if (level > 0) {small_gravity(very_small_asteroid1[2].x-2, very_small_asteroid1[2].y+2);}
			if (level > 1) {small_gravity(very_small_asteroid2[2].x-2, very_small_asteroid2[2].y+2);}
			if (level > 2) {small_gravity(very_small_asteroid3[2].x-2, very_small_asteroid3[2].y+2);}
			if (level > 3) {small_gravity(very_small_asteroid4[2].x-2, very_small_asteroid4[2].y+2);}
			if (level > 0) {large_gravity(small_asteroid1[0].x-3, small_asteroid1[0].y+3);}
			if (level > 1) {large_gravity(small_asteroid2[0].x-3, small_asteroid2[0].y+3);}
			if (level > 2) {large_gravity(small_asteroid3[0].x-3, small_asteroid3[0].y+3);}
			if (level > 3) {large_gravity(small_asteroid4[0].x-3, small_asteroid4[0].y+3);}

	        enemies = level * 10;
	        once = 1;
	    }
	gotoxy(10,40);
	printf("%d",enemies);
	if ((enemies == 0) || ((enemies == 1) && (globalLives == 2)) || ((enemies == 2) && (globalLives == 1))) {
		enemiesbegin(10,level,1);
		for (int i = 0; i< 100; i++) {clear_enemy(enemies_level[i].x,enemies_level[i].y);enemies_level[i].x = 0;enemies_level[i].y = 0;enemies_level[i].color = 0;}
		update_score(globalPoints);
		once = 0;
		clearallshots();
		menuWIN(level);
	}
	if (globalLives == 0) {
		enemiesbegin(10,level,1);
		for (int i = 0; i< 100; i++) {clear_enemy(enemies_level[i].x,enemies_level[i].y);enemies_level[i].x = 0;enemies_level[i].y = 0;enemies_level[i].color = 0;}
		once = 0;
		clearallshots();
		update_score(globalPoints);
		menuGAMEOVER();
	}
    for (int i = 0; i < 100; ++i) {
    	if (shots[i].x != 0 || shots[i].y != 0) {
    		oldshots[i].x = shots[i].x;
    	    oldshots[i].y = shots[i].y;
    	    	if (shots[i].y > 2) {
    	    		for (int j = 0; j< 21; j++) {
    	    				if (level > 0) {gravityResult = gravity(shots[i], very_small_asteroid1[j]);}
    	    	        	if (level > 1) {gravityResult +=gravity(shots[i], very_small_asteroid2[j]);}
    	    	        	if (level > 2) {gravityResult +=gravity(shots[i], very_small_asteroid3[j]);}
		    	        	if (level > 3) {gravityResult +=gravity(shots[i], very_small_asteroid4[j]);}
		    	        	if (gravityResult != 0) {
		    	        		shots[i].x += gravityResult;
    	        			    break;
    	        			    }
    	        		 }
    	        	for (int j = 0; j< 37; j++) {
    	        			if (level > 0) {gravityResult = gravity(shots[i], small_asteroid1[j]);}
    	        			if (level > 1) {gravityResult += gravity(shots[i], small_asteroid2[j]);}
    	        			if (level > 2) {gravityResult +=gravity(shots[i], small_asteroid3[j]);}
    	    	        	if (level > 3) {gravityResult +=gravity(shots[i], small_asteroid4[j]);}
    	        			if (gravityResult != 0) {
    	        				shots[i].x += gravityResult;
    	        				break;
    	        			    }
    	        		}
    	        		--shots[i].y;
    	        		gotoxy(shots[i].x, shots[i].y);
    	        		fgcolor(7);
    	        		printf("o");
    	        		gotoxy(oldshots[i].x, oldshots[i].y);
    	        		printf(" ");
    	        			}
    	    		else {
    	    			gotoxy(oldshots[i].x, oldshots[i].y);
    	    			printf(" ");
        	            shots[i].x = 0;
        	            shots[i].y = 0;
        	            oldshots[i].x = 0;
        	            oldshots[i].y = 0;
        	            break;
        	            }

    	        for (int j = 0; j < 21; ++j) {
    	        	if (level > 0 && isAstroidCollision(shots[i], very_small_asteroid1[j])) {
    	        	    shots[i].x = 0;
    	        	    shots[i].y = 0;
    	        	    small_gravity(very_small_asteroid1[2].x-2, very_small_asteroid1[2].y+2);
    	        	    break;
    	        	    }
    	        	if (level > 1 && isAstroidCollision(shots[i], very_small_asteroid2[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						small_gravity(very_small_asteroid2[2].x-2, very_small_asteroid2[2].y+2);
						break;
    	        	    }
    	        	if (level > 2 && isAstroidCollision(shots[i], very_small_asteroid3[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						small_gravity(very_small_asteroid3[2].x-2, very_small_asteroid3[2].y+2);
						break;
						}
    	        	if (level > 3 && isAstroidCollision(shots[i], very_small_asteroid4[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						small_gravity(very_small_asteroid4[2].x-2, very_small_asteroid4[2].y+2);
						break;
						}
    	        	}
    	        for (int j = 0; j < 37; ++j) {
    	        	if (level > 0 && isAstroidCollision(shots[i], small_asteroid1[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						large_gravity(small_asteroid1[0].x-3, small_asteroid1[0].y+3);
						break;
						}
    	        	if (level > 1 && isAstroidCollision(shots[i], small_asteroid2[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						large_gravity(small_asteroid2[0].x-3, small_asteroid2[0].y+3);
						break;
						}
    	        	if (level > 2 && isAstroidCollision(shots[i], small_asteroid3[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						large_gravity(small_asteroid3[0].x-3, small_asteroid3[0].y+3);
						break;
    	        		}
    	        	if (level > 3 && isAstroidCollision(shots[i], small_asteroid4[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						large_gravity(small_asteroid4[0].x-3, small_asteroid4[0].y+3);
						break;
						}
    	        	}
    	  for (int loop = 0; loop < 20; loop++) {
    		  for (int j = 0; j < 90; ++j) {
    			  if(enemies_level[j].x!=0 && enemies_level[j].y!=0) {
    			  if (isCollision(shots[i], enemies_level[j])) {
    				  	  handleEnemyCollision(i,j,level);
    				  	  enemy_down = 1;
    			  }
    		  	  }
    		  }
    	  }
    	  if (enemy_down == 1) {
    	          enemies -= 1;
    	          enemy_down = 0;
    	       }
    	}
    	pause_control(pause);
    }
}

void initiate_black_hole(int x,int y){
	fgcolor(8);
	gotoxy(x-2,y-1);
	for (int k=0; k <= 4; k++){
		printf("%c",187);
	}
	cursor_down(1);
	cursor_left(6);
	for (int k=0; k <= 6; k++){
		if (k == 0) {
			printf("%c",201);
		}
		else if (k==6){
			printf("%c",188);
		}
		else{
			printf("%c",178);
		}
	}
	cursor_down(1);
	cursor_left(6);
	for (int k=0; k <=4; k++){
		printf("%c",200);
	}
	fgcolor(15);
}
