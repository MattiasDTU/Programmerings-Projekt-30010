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

// Funktion til at opdatere scoren og placere den i highscore-listen
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

// Funktion til at kontrollere en pause baseret på et givet tidsinterval
void pause_control(int time_between) {
	int first = 0;
	while (first < time_between) {first += 1;}
}

// Funktion til at tilføje point til den globale pointvariabel
void points(int points) {
    globalPoints += points;
}

// Funktion til at reducere antallet af liv baseret på givet skade
void lives(int damage) {
    globalLives -= damage;
}

// Funktion til at tilføje en skudposition til skudarrayet
void addShot(int x, int y) {
    for (int i = 0; i < 100; ++i) {
        if (shots[i].x == 0 && shots[i].y == 0) {
            shots[i].x = x;
            shots[i].y = y;
            break;
        }
    }
}

// Funktion til at tilføje en tidligere skudposition til arrayet af gamle skud
void prevShot(int x, int y) {
    for (int i = 0; i < 100; ++i) {
        if (oldshots[i].x == 0 && shots[i].y == 0) {
            oldshots[i].x = x;
            oldshots[i].y = y;
            break;
        }
    }
}

// Funktion til at detektere kollision mellem et skud og en fjende
bool isCollision(struct vector_t shot_values, struct enemy enemy_values) {
    return (shot_values.x == enemy_values.x || shot_values.x == enemy_values.x + 1 || shot_values.x == enemy_values.x + 2) && (shot_values.y == enemy_values.y);
}

// Funktion til at detektere kollision mellem et skud og en "ormehul"
bool isCollisionHole(struct vector_t shot_values, struct vector_t hole) {
    return (shot_values.x == hole.x  && shot_values.y == hole.y);
}

// Funktion til at detektere kollision mellem et skud og en asteroid
bool isAstroidCollision(struct vector_t shot_values, struct vector_t asteroid_values) {
    return (shot_values.x == asteroid_values.x && shot_values.y == asteroid_values.y);
}

// Funktion til at beregne og returnere tyngdekraftens påvirkning på et skud og en asteroid
int gravity(struct vector_t shot_values, struct vector_t asteroid_values) {
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

// Funktion til at styre en variabels værdi baseret på en given handling
int callreturn (int value) {
	static int call = 0;
	if (value == 5) {
		call = 0;
	}
	if (call > 1 || call < 0) {
		call = 0;
	}
	call += value;
	return call;
}

// Funktion til at nulstille alle skudpositioner
void clearallshots() {
	for (int j = 0; j <100; j++) {
		shots[j].x = 0;
		shots[j].y = 0;
	}
}

// Funktion til at opdatere og udskrive skudpositioner baseret på forskellige betingelser
void updateAndPrintShots(int pause, int level,int speed, int position) {
	// Initialisering af variabler og flags
	static int once = 0;
	static int enemies = 0;
	static int printpowerup = 0;
	static int printwormhole = 0;
	int enemy_down;
	static int amount_enemies_down = 0;
	int gravityResult;
	// Kontrol af, om nok fjender er slået ud til at starte power-up
	if (amount_enemies_down == 14) {
		powerUpHeart();
		amount_enemies_down = 15;
		printpowerup = 1;
	}
	// Udskrivning af power-up hjerte, hvis betingelserne er opfyldt
	if (printpowerup == 1) {
		for (int i = 0; i< 2; i++) {
			if (position == heart[i].x || position == heart[i].x - 1|| position == heart[i].x + 1) {
				for (int i = 0; i< 2; i++) {
						gotoxy(heart[i].x,heart[i].y);
						fgcolor(1);
						if (i == 0) {printf("<");}
						if (i == 1) {printf("3");}
					}
				}
		}
	}
	// Opdatering af liv baseret på power-up hjerte
	if (globalLives != 3) {
	globalLives += hitpowerupHeart(position);
	amount_enemies_down = 0;
	printpowerup = 0;
	}
	// Flag for initialisering af fjender og asteroider
	if (once != 1) {
		enemiesbegin(speed,level, 1);
	}
	// Udskrivning af forskellige typer asteroider baseret på level
	if (!once) {
			if (level > 0) {print_small_asteroid(very_small_asteroid1[2].x-2, very_small_asteroid1[2].y-2);}
			if (level > 1) {print_small_asteroid(very_small_asteroid2[2].x-2, very_small_asteroid2[2].y-2);}
			if (level > 2) {print_small_asteroid(very_small_asteroid3[2].x-2, very_small_asteroid3[2].y-2);}
			if (level > 3) {print_small_asteroid(very_small_asteroid4[2].x-2, very_small_asteroid4[2].y-2);}
			if (level > 0) {print_big_asteroid(small_asteroid1[0].x-3, small_asteroid1[0].y-3);}
			if (level > 1) {print_big_asteroid(small_asteroid2[0].x-3, small_asteroid2[0].y-3);}
			if (level > 2) {print_big_asteroid(small_asteroid3[0].x-3, small_asteroid3[0].y-3);}
			if (level > 3) {print_big_asteroid(small_asteroid4[0].x-3, small_asteroid4[0].y-3);}

	        enemies = level * 10;
	        once = 1;
			// Initialisering af ormehuller baseret på level
			if (level == 6) {initiate_worm_hole(17,30);printwormhole=1;}
			if (level == 7) {initiate_worm_hole(35,30);printwormhole=1;}
			if (level == 8) {initiate_worm_hole(70,30);printwormhole=1;}
			if (level == 9) {initiate_worm_hole(100,30);printwormhole=1;}
	    }
	// Udskrivning af ormehuller, hvis betingelserne er opfyldt
	if (printwormhole == 1) {
		if (level == 6) {print_worm_hole(17,30);}
		if (level == 7) {print_worm_hole(35,30);}
		if (level == 8) {print_worm_hole(70,30);}
		if (level == 9) {print_worm_hole(100,30);}
	}
	// Håndtering af betingelser for sejr eller nederlag
	if ((enemies == 0) || ((enemies == 1) && (globalLives == 2)) || ((enemies == 2) && (globalLives == 1))) {
		// Rydning af fjender og opdatering af score ved sejr
		enemiesbegin(10,level,1);
		for (int i = 0; i< 100; i++) {clear_enemy(enemies_level[i].x,enemies_level[i].y);enemies_level[i].x = 0;enemies_level[i].y = 0;enemies_level[i].color = 0;}
		update_score(globalPoints);
		once = 0;
		clearallshots();
		menuWIN(level);
	}
	// Håndtering af betingelser for nederlag
	if (globalLives == 0) {
		// Håndtering af betingelser for nederlag
		enemiesbegin(10,level,1);
		for (int i = 0; i< 100; i++) {clear_enemy(enemies_level[i].x,enemies_level[i].y);enemies_level[i].x = 0;enemies_level[i].y = 0;enemies_level[i].color = 0;}
		once = 0;
		clearallshots();
		update_score(globalPoints);
		menuGAMEOVER();
	}
    // Loop gennem alle skudpositioner
    for (int i = 0; i < 100; ++i) {
	// Tjek om skuddet er aktivt (ikke nul)
    	if (shots[i].x != 0 || shots[i].y != 0) {
		// Gem gamle skudpositioner
    		oldshots[i].x = shots[i].x;
    	    oldshots[i].y = shots[i].y;
		// Gem gamle skudpositioner
    	    	if (shots[i].y > 2) {
    	    		for (int j = 0; j< 21; j++) {
				// Beregn tyngdekraften for meget små asteroider
    	    			if (level > 0) {gravityResult = gravity(shots[i], very_small_asteroid1[j]);}
    	    	        	if (level > 1) {gravityResult +=gravity(shots[i], very_small_asteroid2[j]);}
    	    	        	if (level > 2) {gravityResult +=gravity(shots[i], very_small_asteroid3[j]);}
		    	        	if (level > 3) {gravityResult +=gravity(shots[i], very_small_asteroid4[j]);}
					// Anvend tyngdekraften, hvis den ikke er nul
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
				 // Opdater skudets y-koordinat og udskriv det på skærmen
    	        		--shots[i].y;
				// Slet det gamle skud fra den gamle position
    	        		gotoxy(shots[i].x, shots[i].y);
    	        		fgcolor(7);
    	        		printf("o");
    	        		gotoxy(oldshots[i].x, oldshots[i].y);
    	        		printf(" ");
    	        			}
    	    		else {
				// Hvis skuddet er over en vis y-koordinat, slet det og nulstil positionen
    	    			gotoxy(oldshots[i].x, oldshots[i].y);
    	    			printf(" ");
        	            shots[i].x = 0;
        	            shots[i].y = 0;
        	            oldshots[i].x = 0;
        	            oldshots[i].y = 0;
        	            break;
        	            }
		// Håndter kollision med fjender og opdater fjender og score
    	    	if (callreturn(0) == 0) {
    	    	    		  enemies -= hitpowerupBomb(shots[i],level);}

    	        for (int j = 0; j < 21; ++j) {
    	        	if (level > 0 && isAstroidCollision(shots[i], very_small_asteroid1[j])) {
    	        	    shots[i].x = 0;
    	        	    shots[i].y = 0;
    	        	    print_small_asteroid(very_small_asteroid1[2].x-2, very_small_asteroid1[2].y-2);
    	        	    break;
    	        	    }
    	        	if (level > 1 && isAstroidCollision(shots[i], very_small_asteroid2[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						print_small_asteroid(very_small_asteroid2[2].x-2, very_small_asteroid2[2].y-2);
						break;
    	        	    }
    	        	if (level > 2 && isAstroidCollision(shots[i], very_small_asteroid3[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						print_small_asteroid(very_small_asteroid3[2].x-2, very_small_asteroid3[2].y-2);
						break;
						}
    	        	if (level > 3 && isAstroidCollision(shots[i], very_small_asteroid4[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						print_small_asteroid(very_small_asteroid4[2].x-2, very_small_asteroid4[2].y-2);
						break;
						}
    	        	}
    	        for (int j = 0; j < 37; ++j) {
    	        	if (level > 0 && isAstroidCollision(shots[i], small_asteroid1[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						print_big_asteroid(small_asteroid1[0].x-3, small_asteroid1[0].y-3);
						break;
						}
    	        	if (level > 1 && isAstroidCollision(shots[i], small_asteroid2[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						print_big_asteroid(small_asteroid2[0].x-3, small_asteroid2[0].y-3);
						break;
						}
    	        	if (level > 2 && isAstroidCollision(shots[i], small_asteroid3[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						print_big_asteroid(small_asteroid3[0].x-3, small_asteroid3[0].y-3);
						break;
    	        		}
    	        	if (level > 3 && isAstroidCollision(shots[i], small_asteroid4[j])) {
						shots[i].x = 0;
						shots[i].y = 0;
						print_big_asteroid(small_asteroid4[0].x-3, small_asteroid4[0].y-3);
						break;
						}
    	        	}
	// Håndter kollision med fjender og opdater fjender og score
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
	// Hvis spilniveauet er over en vis værdi, håndter kollision med ormehuller
    	  if (level > 5 ) {
    	  for (int j = 0; j < 15; j++) {
    		  if (isCollisionHole(shots[i],hole[j])) {
    			  shots[i].x = rand() % 139+2;
    			  shots[i].y = rand() % 38+2;
    		  }
    	  }
    	  }
	 // Hvis en fjende er blevet nedkæmpet, opdater score og fjender
    	  if (enemy_down == 1) {
    		  	  amount_enemies_down += 1;
    	          enemies -= 1;
    	          enemy_down = 0;
    	       }
    	}
    	pause_control(pause);
    }
}


