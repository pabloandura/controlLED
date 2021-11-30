 # Memoria Descriptiva Trabajo Practico de Informatica II para Daniel Corbalan y Gustavo Viard
 </br>
- El programa constantemente verifica si se esta reproduciendo música. El prototipo puede contar con una entrada de audio (micrófono/cable 1/4 pulgada TRS) y un convertidor de analógico a digital. Una vez la señal es digital, se puede devolver un valor entero a nuestro programa con la cantidad de pulsos por minuto (beats per minute en inglés). 

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
int ritmo(float , int **, long * );
int fijado(float , int **, long * );
int detectar(void);

//declaro puntero a funciones para los dos estados
int (*p[])(float, int **, long c)={ritmo,fijado};


int main(int comandoInt, char **comandoVect)
{
    /**
    "bpm" es la cantidad de ciclos de prendido y apagado por minuto
    "e" es la variable para cambio de estado.
    */

    int e=0,leds[LED][LED];
    float bpm=120;
    long c=0L;
    //pregunta de estado
    while(1)
    {
        e=p[e](bpm,leds,&c);
        c++;
    }
    return 0;
}


```

## Archivo funciones.h
```c
int ritmo(float bpm,int **leds, long * c)
{
    /**
    ritmo recibe: 
    un int que le indica cuantas
    veces de prenden y apagan las luces en un minuto
    un array que tiene los estados de las luces
    un contador  
    */

    printf("Ritmo\n");
        // inicializamos las variables
    int i,j;
    printf("*** Demonstracion *** \n\n");

    //impresion
        if(*c%2) // si es par o !=0 entra
        {
            // apagamos todas
            for(i=0;i<LED;i++)
            {
                for(j=0;j<LED;j++)
                {
                leds[i][j]=0;
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
                leds[i][j]=1;
                }
            }
        }
    for(i=0;i<LED;i++)
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n"
                ,leds[i][0],leds[i][1],leds[i][2],leds[i][3]
                ,leds[i][4],leds[i][5],leds[i][6],leds[i][7]);
    /* Seccion de sincronizacion de prendido y apagado
                Ya que el bpm es la cantidad de pulso por segundo
                la operacion matematica para llevar a microsegundos es la siguiente.

                ( bpm x 1/60 )^(-1) = 1 ciclo de prendido y apagado

                para llevarlo a microsegundos, lo multiplico por 1.000.000

                Utilizo microsegundos porque me permite tener mas definicion.
    */
    usleep((useconds_t)((pow(bpm/60.0,-1)*1000000)));
    system("cls");
    return detectar();
}

int fijado(float n,int **leds, long * c)
{
     /**
    fijado recibe:
    un int que le indica cuantas
    veces de prenden y apagan las luces en un segundo
    un array que tiene los estados de las luces
    un contador    
    */
    printf("Fijado\n");
        // inicializamos las variables
    int i,j;
    printf("*** Demonstracion *** \n\n");

    //impresion
        if(*c%2) // si es par o !=0 entra
        {
            // apagamos todas
            for(i=0;i<LED;i++)
            {
                for(j=0;j<LED;j++)
                {
                leds[i][j]=0;
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
                leds[i][j]=1;
                }
            }
        }
    for(i=0;i<LED;i++)
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n"
                ,leds[i][0],leds[i][1],leds[i][2],leds[i][3]
                ,leds[i][4],leds[i][5],leds[i][6],leds[i][7]);
    /* Seccion de prendido y apagado en intervalos fijos

                para llevarlo a microsegundos, lo multiplico por 10.000 ya que n es un numero relativo
                desde el punto de vista practico

                Utilizo microsegundos porque me permite tener mas definicion.
    */
    usleep((useconds_t)(n*10000));
    return detectar();
}

int detectar(void)
{
    printf("\nDetectando...\n");
    return 0;
}
```
