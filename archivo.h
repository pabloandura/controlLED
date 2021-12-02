//luces por fila, nuestro cuadrado de luces
#define LED 8
//librerias estandar
#include <stdio.h>
#include <stdlib.h>
//incluimos string.h para manipular archivo de configuracion
#include <string.h>
//incluimos conio.h para tener la funcion kbhit()
#include <conio.h>
//incluimos la libreria de POSIX para las funciones sleep() y usleep()
#include <unistd.h>
//incluir tipo de datos byte para control de Led
#include "tipos.h"
//libreria funciones
#include "funciones.h"

//prototipos
int ritmo(float , display_t *, long * );
int fijado(float , display_t *, long * );
int detectar(void);
char * getKey(char *);
int setConfiguracion(int*,float*,long*);

//declaro puntero a funciones para los dos estados
int (*p[])(float, display_t *, long c)={fijado,ritmo};
