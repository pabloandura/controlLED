//lado de cuadrado bidimensional
#define LED 8

#include <stdio.h>
#include <stdlib.h>
//incluimos la libreria de tiempos time.h
#include <time.h>
//libreria de typedef definidos por autor
#include "tipos.h"
//libreria funciones
#include "funciones.h"


//prototipos
void ritmo(int *bpm);
void fijado(int *n);
void prender(int, struct memoria *mem);

int main(int comandoInt, char *comandoVect)
{
    /**
    "b_bpm" es la funcion local al main que
    almacena en dinamica el valor de bpm
    para la funcion ritmo

    "e" es la variable para cambio de estado.

    "op" dicta el fin del programa
    */

    int e=0,b_bpm=120,op=0,n=100;
    //pregunta de estado
    do{
        if(e)
            ritmo(b_bpm);
        else
            fijado(n);
        // se escucha musica?
        e=detectar();
       }while(op);
//    printf("Bienvenid@\n");
    return 0;
}
