/* 
 * File:   main.c
 * Author: <Ary Hernandez>
 *
 * Created:     <--/--/2017>
 * Modified:    <--/--/---->
 */

/* Librerias a utilizar */
#include <stdio.h>

/* Headers del sistema */
#include "system.h"
#include "calc.h"

/**
* Main Loop
*/
int main (void) {
    char *str = "Hola Mundo \n\n Somos los Debian: \n\t -Ary Hernandez \n\t -Marc Guzman \n\t -Carlos Sosa \n\t -Jose Araujo \n\t -Andres Alvarez", *ch;
	unsigned short *vidmem = (unsigned short*) 0xb8000;
	unsigned i;
	for (ch = str, i = 0; *ch; ch++, i++) {
        vidmem[i] = (unsigned char) *ch | 0x0700;
    } 
    
    /* CALL SHELL LOOP */

	return 0;
}