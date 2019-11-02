/* 
 * File:   main.c
 * Author: <Carlos Sosa>

/* Librerias a utilizar */
#include <stdio.h>

/* Headers del sistema */
#include "system.h"
#include "calc.h"

/**
* Main Loop
*/
int main (void) {
    char *str = "Hola Mundo", *ch;
	unsigned short *vidmem = (unsigned short*) 0xb8000;
	unsigned i;
	for (ch = str, i = 0; *ch; ch++, i++) {
        vidmem[i] = (unsigned char) *ch | 0x0700;
    } 
    
    /* CALL SHELL LOOP */

	return 0;
}
