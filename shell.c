/* 
 * File:   Shell.c
 * Author: <Carlos Sosa>
 *
 * Created:     <28/08/2017>
 * Modified:    <17/09/2017>
 */

/* Librerias a utilizar */
#include <stdio.h>

/* Headers del sistema */
#include "system.h"
#include "calc.h"

/**
* Loop que administra el funcionamiento del shell
*/
void shLoop(void)
{
    char *line;
    char **tokens;
    int status;

    do {

        /*Texto en pantalla*/
        printf("$ TeddOS> ");

        /*Leer una linea ingresada por el usuario*/
        line = shReadLine();

        /*Volver la linea ingresada en tokens*/
        tokens = shParseLine(line);

        /*Ejecutar las acciones requeridas por el usuario*/
        status = shExecute(tokens);

        /*Limpia los valores en memoria*/
        free(line);
        free(tokens);

        /*Mientras el proceso no se concluya*/
    } while (!status);
}

/**
* Funcion que lee una linea escrita por 
* el usuario
*/
char *shReadLine(void)
{
    /*Inicializar el contenedor de la linea*/
    char *line = NULL;
    ssize_t bufferSize = 0;

    /*Obtener linea ingresada*/
    getline(&line, &bufferSize, stdin);

    /*Retornar conjunto de caracteres*/
    return line;
}

/**
* Funcion que parsea la linea ingresada 
* y la convierte en un conjunto de tokens
*/
char **shParseLine(char *line)
{
    // Inicializar el espacio en memoria del arreglo
    int bufferSize = TOKEN_BUF_SIZE, position = 0;
    char **tokens = malloc(bufferSize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "ERROR\n");
        exit(EXIT_FAILURE);
    }

    /*Divide la linea en tokens*/
    token = strtok(line, TOKEN_DELIMITER);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        /*Asigna mas especio en memoria al arreglo*/
        if (position >= bufferSize) {
            bufferSize += TOKEN_BUF_SIZE;
            tokens = realloc(tokens, bufferSize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "ERROR\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITER);
    }

    /*Llena el arreglo*/
    tokens[position] = NULL;

    /*Retorna el arreglo*/
    return tokens;
}

/**
* Funcion que realiza acciones en base a los tokens
*/
int shExecute(char **tokens)
{
    char *cmd = tokens[0];
    char *executor = tokens[1];

    switch (cmd)
    {
        case "calc":
            // Limpia la pantalla
            clear();
            
            // Ejecuta segun argumentos
            switch (switch_on)
            {
                case "-i":
                    /*RUN LOOP*/
                    break;

                // Mostrar la version
                case "-v":
                    /*Show Version*/
                    break;

                default:
                    printf("Ingresa un argumento valido");
                    break;
            }
            break;

        case "sound":
            // Limpia la pantalla
            clear();
            
            // Ejecuta segun argumentos
            switch (switch_on)
            {
                case "-a":
                    bep(1);
                    break;
                
                case "-b":
                    bep(2);
                    break;

                case "-c":
                    bep(3);
                    break;

                // Mostrar la version
                case "-v":
                    /*Show Version*/
                    break;

                default:
                    printf("Ingresa un argumento valido");
                    break;
            }
            break;

        case "shtdown":
            // Ejecuta la funcion que apaga la computadora
            powerOff();
            break;

        default:
            // Limpia la pantalla
            clear();

            // Muestra mensaje de no reconocer el comando
            printf("- No se reconoce el comando ingresado -");
            
            // Retorna 0 para continuar con la lectura de comandos
            return 0;

            break;
    }
}