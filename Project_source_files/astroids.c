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
#include <math.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "Header_file.h"




void Asteroid1(int size, const int x, const int y) {
    if (size == 0) {
    	int offsets[] = {-2, -1, 0, 1, 2};
		for (int i = 0; i < 21; ++i) {
			int offsetX = offsets[i % 5];
			int offsetY = (i < 5) ? 0 : ((i < 10) ? 1 : ((i < 13) ? 2 : ((i < 18) ? -1 : -2)));
			very_small_asteroid1[i] = (struct Asteroid){x + offsetX, y + offsetY};
		}
	}
    if (size == 1) {
    	int offsets_x[] = {0, -1, -2, -3, 1, 2, 3, 0, -1, -2, -3, 1, 2, 3, 0, -1, -2, 1, 2, 0, -1, 1, 0, -1, -2, -3, 1, 2, 3, 0, -1, -2, 1, 2, 0, -1, 1};
    	int offsets_y[] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -3, -3, -3};
    	for (int i = 0; i < 37; ++i) {
    	    small_asteroid1[i] = (struct Asteroid){x + offsets_x[i], y + offsets_y[i]};
    	}
    }
}
void Asteroid2(int size, const int x, const int y) {
    if (size == 0) {
    	int offsets[] = {-2, -1, 0, 1, 2};
		for (int i = 0; i < 21; ++i) {
			int offsetX = offsets[i % 5];
			int offsetY = (i < 5) ? 0 : ((i < 10) ? 1 : ((i < 13) ? 2 : ((i < 18) ? -1 : -2)));
			very_small_asteroid2[i] = (struct Asteroid){x + offsetX, y + offsetY};
		}
	}
    if (size == 1) {
    	int offsets_x[] = {0, -1, -2, -3, 1, 2, 3, 0, -1, -2, -3, 1, 2, 3, 0, -1, -2, 1, 2, 0, -1, 1, 0, -1, -2, -3, 1, 2, 3, 0, -1, -2, 1, 2, 0, -1, 1};
    	int offsets_y[] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -3, -3, -3};
    	for (int i = 0; i < 37; ++i) {
    	    small_asteroid2[i] = (struct Asteroid){x + offsets_x[i], y + offsets_y[i]};
    	}
    }
}
void Asteroid3(int size, const int x, const int y) {
    if (size == 0) {
    	int offsets[] = {-2, -1, 0, 1, 2};
		for (int i = 0; i < 21; ++i) {
			int offsetX = offsets[i % 5];
			int offsetY = (i < 5) ? 0 : ((i < 10) ? 1 : ((i < 13) ? 2 : ((i < 18) ? -1 : -2)));
			very_small_asteroid3[i] = (struct Asteroid){x + offsetX, y + offsetY};
		}
	}
    if (size == 1) {
    	int offsets_x[] = {0, -1, -2, -3, 1, 2, 3, 0, -1, -2, -3, 1, 2, 3, 0, -1, -2, 1, 2, 0, -1, 1, 0, -1, -2, -3, 1, 2, 3, 0, -1, -2, 1, 2, 0, -1, 1};
    	int offsets_y[] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -3, -3, -3};
    	for (int i = 0; i < 37; ++i) {
    	    small_asteroid3[i] = (struct Asteroid){x + offsets_x[i], y + offsets_y[i]};
    	}
    }
}
void Asteroid4(int size, const int x, const int y) {
    if (size == 0) {
    	int offsets[] = {-2, -1, 0, 1, 2};
		for (int i = 0; i < 21; ++i) {
			int offsetX = offsets[i % 5];
			int offsetY = (i < 5) ? 0 : ((i < 10) ? 1 : ((i < 13) ? 2 : ((i < 18) ? -1 : -2)));
			very_small_asteroid4[i] = (struct Asteroid){x + offsetX, y + offsetY};
		}
	}
    if (size == 1) {
    	int offsets_x[] = {0, -1, -2, -3, 1, 2, 3, 0, -1, -2, -3, 1, 2, 3, 0, -1, -2, 1, 2, 0, -1, 1, 0, -1, -2, -3, 1, 2, 3, 0, -1, -2, 1, 2, 0, -1, 1};
    	int offsets_y[] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -3, -3, -3};
    	for (int i = 0; i < 37; ++i) {
    	    small_asteroid4[i] = (struct Asteroid){x + offsets_x[i], y + offsets_y[i]};
    	}
    }
}

