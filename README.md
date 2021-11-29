 # Memoria Descriptiva Trabajo Practico de Informatica II para Daniel Corbalan y Gustavo Viard
 </br>
- El programa constantemente verifica si se esta reproduciendo música. El prototipo puede contar con una entrada de audio (micrófono/cable 1/4 pulgada TRS) y un convertidor de analógico a digital. Una vez la señal es digital, se puede devolver un valor entero a nuestro programa con la cantidad de pulsos por minuto (beats per minute en inglés). 
- La proxima implementacion seria siempre trabajar sobre una estructura de leds para que el estado del led sea unico y no una copia. (en el codigo: *matriz leds vs matriz lux*)
 </br>

</br>
</br>
</br>
</br>
</br>



![Diagrama de la maquina de estados](./maquinadeestados2.0.png)

## Archivo main.c
```c

//luces por fila, nuestro cuadrado de luces
#define LED 8

#include <stdio.h>
#include <stdlib.h>
//incluimos la libreria de POSIX para las funciones sleep() y usleep()
#include <unistd.h>
//libreria funciones
#include "funciones.h"

//prototipos
void ritmo(float , int **);
void fijado(float , int**);

//declaro puntero a funciones para los dos estados
void (*p[])(float, int **)={ritmo,fijado};


int main(int comandoInt, char **comandoVect)
{
    /**
    "bpm" es la cantidad de ciclos de prendido y apagado por minuto
    "e" es la variable para cambio de estado.

    "op" dicta el fin del programa
    */

    int e=0,op=0,leds[LED][LED];
    float bpm=120;
    //pregunta de estado
    do{
        p[e](bpm,leds);
        // se escucha musica?
        e=detectar(); // e=detectar() es el lugar donde mi programa verificaria si la parte de procesamiento detecta musica sonando
       }while(op);
//    printf("Bienvenid@\n");
    return 0;
}

```

## Archivo funciones.h
```c
void ritmo(float bpm,int **leds)
{
    /**
    ritmo recibe un int que le indica cuantas
    veces de prenden y apagan las luces en un minuto
    */

    printf("Ritmo\n");
        // inicializamos las variables
    int i,j,c=0;
    int lux[LED][LED];
    printf("*** Demonstracion *** \n\n");

    //impresion
    for(c=0;c<20;c++)
    {
        if(c%2) // si es par o !=0 entra
        {
            // apagamos todas
            for(i=0;i<LED;i++)
            {
                for(j=0;j<LED;j++)
                {
                lux[i][j]=0;
                }
            }
        }
        else
        {
            // prendemos todas
            for(i=0;i<LED;i++)
            {
                for(j=0;j<LED;j++)
                {
                lux[i][j]=1;
                }
            }
        }
    for(i=0;i<LED;i++)
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n"
                ,lux[i][0],lux[i][1],lux[i][2],lux[i][3]
                ,lux[i][4],lux[i][5],lux[i][6],lux[i][7]);
    /* Seccion de sincronizacion de prendido y apagado
                Ya que el bpm es la cantidad de pulso por segundo
                la operacion matematica para llevar a microsegundos es la siguiente.

                ( bpm x 1/60 )^(-1) = 1 ciclo de prendido y apagado

                para llevarlo a microsegundos, lo multiplico por 1.000.000

                Utilizo microsegundos porque me permite tener mas definicion.
    */
    usleep((useconds_t)((pow(bpm/60.0,-1)*1000000)));

    system("cls");
    printf("*** Demonstracion *** \n\n");
    }
    printf("Fin de la simulacion\n");
}

void fijado(float n,int **leds)
{
     /**
    fijado recibe un int que le indica cuantas
    veces de prenden y apagan las luces en un segundo

    INCOMPLETO: NECESITAMOS CONTROL DE TIEMPOS

    */
    printf("Fijado\n");
        // inicializamos las variables
    int i,j,c=0;
    int lux[LED][LED];
    printf("*** Demonstracion *** \n\n");

    //impresion
    for(c=0;c<20;c++)
    {
        if(c%2) // si es par o !=0 entra
        {
            // apagamos todas
            for(i=0;i<LED;i++)
            {
                for(j=0;j<LED;j++)
                {
                lux[i][j]=0;
                }
            }
        }
        else
        {
            // prendemos todas
            for(i=0;i<LED;i++)
            {
                for(j=0;j<LED;j++)
                {
                lux[i][j]=1;
                }
            }
        }
    for(i=0;i<LED;i++)
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n"
                ,lux[i][0],lux[i][1],lux[i][2],lux[i][3]
                ,lux[i][4],lux[i][5],lux[i][6],lux[i][7]);
    /* Seccion de prendido y apagado en intervalos fijos

                para llevarlo a microsegundos, lo multiplico por 10.000 ya que n es un numero relativo
                desde el punto de vista practico

                Utilizo microsegundos porque me permite tener mas definicion.
    */
    usleep((useconds_t)(n*10000));

    system("cls");
    printf("*** Demonstracion *** \n\n");
    }
    printf("Fin de la simulacion\n");
}

int detectar(void)
{
    printf("\nDetectando...\n");
    return 1;
}
```
