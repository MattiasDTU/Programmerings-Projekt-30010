#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Header_file.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"


// Funktion til at generere et regneark og printe Excel-logo med ASCII-karakterer
void boss_spreadsheet(){
	int row = 0;
	// Flytter cursor til position (2,2) og starter et loop
	gotoxy(2,2);
	while (row <=37){
		// Printer vandrette linjer
		if (row % 2 == 0){
			for (int i = 0; i <= 137; i++){
				if (i%11 == 0 && i!=0){
					printf("%c",206);
				}
				if (i%11 != 0 || i==0){
				printf("%c", 205);
				}
			}
		}
		 // Printer lodrette linjer
		if (row %2 != 0){
			for (int j = 0; j <=137; j++){
				if (j%11 == 0 && j !=0){
					printf("%c",186);
				}
				if (j%11 != 0 || j == 0){
					printf(" ");
				}
			}
		}
	row = row + 1;
	gotoxy(2,2+row);
	}
	// Printer excel logo
	int x = 54;
	int y = 14;
	gotoxy(x,y);
	for (int i = 0; i <= 8; i++){
		if (i == 0){
			for (int j = 0; j <= 34; j++){
				fgcolor(2);
				printf("%c", 178);
				fgcolor(15);
			}
			gotoxy(x,y+1);
		}
		else if (i==1){
			for (int j = 0; j <= 34; j++){
				fgcolor(2);
				printf("%c", 178);
				fgcolor(15);
			}
			gotoxy(x,y+2);
		}
		else if (i == 2){
			for(int j = 0; j<=34; j++ ){
				if((j>=3 && j<= 7) || (j==9) || (j==13) || (j>=15 && j<=19) || (j>=21 && j <=25) || (j==27)){
					printf("%c", 178);
				}
				else{
					fgcolor(2);
					printf("%c", 178);
					fgcolor(15);
				}
			}
			gotoxy(x,y+3);
		}
		else if(i == 3|| i==5){
			for (int j = 0; j<=34; j++){
				if((j==3)||(j==10)||(j==12)||(j==15)||(j==21)||(j==27)){
					printf("%c", 178);
				}
				else{
					fgcolor(2);
					printf("%c", 178);
					fgcolor(15);
				}
			}
			if (i==3){
				gotoxy(x,y+4);
			}
			else{
				gotoxy(x,y+6);
			}
		}
		else if(i==4){
			for (int j = 0; j<=34;j++){
				if((j>=3 && j<=6)||(j==11)||(j==15)||(j>=21&&j<=24)||(j==27)){
					printf("%c",178);
				}
				else{
					fgcolor(2);
					printf("%c", 178);
					fgcolor(15);
				}
			}
			gotoxy(x,y+5);
		}
		else if(i==6){
			for (int j = 0; j<=34; j++){
				if((j>=3 && j<= 7) || (j==9) || (j==13) || (j>=15 && j<=19) || (j>=21 && j <=25) || (j>=27 && j<=31)){
					printf("%c",178);
				}
				else{
					fgcolor(2);
					printf("%c", 178);
					fgcolor(15);
				}
			}
			gotoxy(x,y+7);
		}
		else if (i == 7){
			for (int j = 0; j <= 34; j++){
				fgcolor(2);
				printf("%c", 178);
				fgcolor(15);
			}
			gotoxy(x,y+8);
		}
		else if (i == 8){
			for (int j = 0; j <= 34; j++){
				fgcolor(2);
				printf("%c", 178);
				fgcolor(15);
			}
			gotoxy(x,y+8);
		}
	}
}
// Funktion til brug af "boss key" funktionalitet 
void boss_key_function() {
	while(1) {
    static int push_count = 0;

    // Tjekker Escape-tasten
    int boss_value = uart_get_char();

    if (boss_value == 0x1B) {
        push_count++;
	    
	// Viser regnearket
        if (push_count == 1) {
            border();
            boss_spreadsheet();
	// Viser menu
        } else if (push_count == 2) {
            push_count = 0;
            menu();
        }
    }
	}
}

