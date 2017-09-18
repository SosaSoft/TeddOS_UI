/* 
 * File:   System.c
 * Author: <Carlos Sosa>
 *
 * Created:     <17/09/2017>
 * Modified:    <--/--/---->
 */
 
/* Librerias a utilizar */
#include <stdio.h>

/* Headers del sistema */
#include "system.h"
#include "calc.h"

/**
*   Funcion que apaga el equipo
*/
void powerOff(void){
    // Code to power off
}

/**
*   Funcion que limpia la pantalla
*/
void clear(void){
    printf("\e[2J\e[H");
}

/**
*   Funcion que muestra el tag del sistema
*/
void systemTag(void){
    printf('$ TeddOS>');
}

/**
*   Funcion que reproduce un 'bep'
*/
void bep(void){
    // Code to make a bep sounds
}