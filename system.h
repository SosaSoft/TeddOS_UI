#ifndef SYSTEM_H
#define SYSTEM_H

    /* Funciones */
        // Interfaz
        void clear(void);
        void systemTag(void);

        // Hardware
        void powerOff(void);
        void bep(void);

    /* Constantes */
    // EMPTY

    /* Funciones Shell */
    void shLoop(void);
    char *shReadLine(void);
    char **shParseLine(char *line);
    int shExecute(char **tokens);

    /* Constantes Shell */
    #define TOKEN_BUF_SIZE 64
    #define TOKEN_DELIMITER " \t\r\n\a"

#endif