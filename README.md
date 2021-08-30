 # Memoria Descriptiva Trabajo Practico de Informatica II para Daniel Corbalan y Gustavo Viard
*Este programa es una representacion en software de un diseno con luces LED que corren en un microcomputador*<br>
- Usare variables char porque son correctos en la utilizacion de microcontroladores.
- La parte analogica se conceptualiza como luces de animacion escalable. Por razones de enfocarme en desarrollar el motor y estructura de la maquina de estados dejare las animaciones a un nivel basico.

## Archivo main.c
```c
int main(int argc, char const *argv[]){

//inicializo las strings
    dat_t p;

    p.aniNro=0;
    char auxiliar[tamanoPalabra+1]="\0";

    strcpy(p.palabra1,"0001");
    strcpy(p.palabra2,"0010");
    strcpy(p.palabra3,"0100");
    strcpy(p.palabra4,"1000");

    //comienzo de maquina de estados

    do{
        ascendente(p);

        printf("Operador( 0 sale ): \n");

        fflush(stdin);
        scanf("%d", &operador);
    }while(operador!=0);
    p.aniNro=0;
    return 0;
}

```

## Archivo proto.h
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define del tamano de una palabra LED horizontal
#define tamanoPalabra 4


//defino estructura de dat_tos de las funciones de animacion
typedef struct datos
    {
    int aniNro;
    char palabra1[10]; //hace un vector de palabras de led
    char palabra2[10];
    char palabra3[10];
    char palabra4[10];
    }dat_t;


struct datos ascendente(struct datos);

```
## Archivo func.h
```c
// archivo de funciones locales al software

//animacion de desplazamiento de palabras de LED en una direccion
struct datos ascendente(struct datos p){
    char auxiliar="\0";
        printf("%s\n",p.palabra1);
        printf("%s\n",p.palabra2);
        printf("%s\n",p.palabra3);
        printf("%s\n",p.palabra4);
    //pasamos al primer fotograma
        system("pause");
        system("cls");

    //inicio funcion de animacion
        strcpy(auxiliar,p.palabra1);
        strcpy(p.palabra1,p.palabra2);
        strcpy(p.palabra2,p.palabra3);
        strcpy(p.palabra3,p.palabra4);
        strcpy(p.palabra4,auxiliar);
        p.aniNro++;
return p;
}
 ascendente(struct datos);

```
