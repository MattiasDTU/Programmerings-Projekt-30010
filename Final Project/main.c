#include "Header_file.h"
int main(void) {
	uart_init(115200); // Initialiserer UART-kommunikation med en baudrate på 115200
	lcd_init(); // Initialiserer LCD-skærmen
	config_timer(); // Konfigurerer timeren
	inittim2(); // Initialiserer timer 2
	hideCursor(); // Skjuler kursor på skærmen
	blink(0); // Aktiverer blink-effekten på skærmen.
	ClearScreen(); // Rydder skærmen
	setFreq(0); // Indstiller frekvensen til 0
	
	while (1) {
		ChooseUserInput(); // Udfører et loop, hvor brugeren kan vælge input.
	}
	return 0; // Afslutter programmet.
}
