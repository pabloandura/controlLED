 # Memoria Descriptiva Trabajo Practico de Informatica II para Daniel Corbalan y Gustavo Viard
 </br>
- El programa constantemente verifica si se esta reproduciendo música. El prototipo puede contar con una entrada de audio (micrófono/cable 1/4 pulgada TRS) y un convertidor de analógico a digital. Una vez la señal es digital, se puede devolver un valor entero a nuestro programa con la cantidad de pulsos por minuto (beats per minute en inglés). 
- Cuento con una función llamada "prender()" que imprime en consola una demonstración de la lógica del código.

</br>
</br>
</br>
</br>
</br>



![Diagrama de la maquina de estados](./maquinadeestados2.0.png)

## Archivo main.c
```c
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

```

## Archivo proto.h
```c
typedef struct memoria
{
    int leds[LED][LED];
    char n_programa[15];
}mem_t;
mem_t cL;


```
## Archivo funciones.h
```c
void ritmo(int *bpm)
{
    /**
    ritmo recibe un int que le indica cuantas
    veces de prenden y apagan las luces en un minuto

    INCOMPLETO: NECESITAMOS CONTROL DE TIEMPOS

    */
    printf("Ritmo");

}

void fijado(int *n)
{
     /**
    fijado recibe un int que le indica cuantas
    veces de prenden y apagan las luces en un segundo

    INCOMPLETO: NECESITAMOS CONTROL DE TIEMPOS

    */
    printf("Fijado\n");
}

void prender(int n, struct memoria *mem)
{
    /**
    prender cambia el estado de cada LED
    */
    // inicializamos las variables
    int i,j;
    mem_t *pm;
    pm=&mem;
    // preendemos todas
    for(i=0;i<LED;i++)
        for(j=0;j<LED;j++)
            pm->leds[i][j]=1;

    // apagamos todas
    for(i=0;i<LED;i++)
        for(j=0;j<LED;j++)
            pm->leds[i][j]-=1;
}

int tiempo(struct time_t *t)
{
    /**

    */
    time_t epoch = 0;
    printf("%s", asctime(gmtime(&epoch)));
}

int detectar(void)
{
    printf("\nDetectando\n");
    return 1;
}



```
