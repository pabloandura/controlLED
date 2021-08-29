 # Memoria Descriptiva Trabajo Practico de Informatica II para Daniel Corbalan y Gustavo Viard
*Este programa es una representacion en software de un diseno con luces LED que corren en un microcomputador*<br>
- Usare variables unsigned char porque son correctos en la utilizacion de microcontroladores.
- La parte analogica se conceptualiza como luces de animacion escalable. Por razones de enfocarme en desarrollar el motor y estructura de la maquina de estados dejare las animaciones a un nivel basico.

## Archivo main.c
```c
//archivo de prototipos
#include "proto.h"
//archivo de funciones
#include "func.h"
// Pablo Javier Lopez Andura - 109947 DNI 38-456-394 UTN AVELLANEDA - INFORMATICA II - DAMIAN CORBALAN Y GUSTAVO VIARD


//macro setbit
#define setBit(reg,bit) reg|(1<<bit)


int i=0;
char operador;
char auxiliar[tamanoPalabra+2]="\0";



// Limpieza de memoria para el simulador de LEDs con cadenas.

int main(int argc, char const *argv[]){

//inicializo las strings
    memset(dest, '\0', sizeof(dest));
    strcpy(datosAnimacion_t.palabra1,"\0");
    strcpy(datosAnimacion_t.palabra2,"\0");
    strcpy(datosAnimacion_t.palabra3,"\0");
    strcpy(datosAnimacion_t.palabra4,"\0");

    //comienzo de maquina de estados

    do{

        printf("%s\n",datosAnimacion_t.palabra1);
        printf("%s\n",datosAnimacion_t.palabra2);
        printf("%s\n",datosAnimacion_t.palabra3);
        printf("%s\n",datosAnimacion_t.palabra4);

        operador='0';
        system("pause");
        system("cls");
    //inicio funcion de animacion
        ascendente(datosAnimacion_t);
        datosAnimacion_t.aniNro++;
    }while(operador!='0');
    datosAnimacion_t.aniNro=0;
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


//defino estructura de datos de las funciones de animacion
typedef struct datos
    {
    int aniNro;
    char palabra1[tamanoPalabra+2];
    char palabra2[tamanoPalabra+2];
    char palabra3[tamanoPalabra+2];
    char palabra4[tamanoPalabra+2];
    }datosAnimacion_t;


datosAnimacion_t ascendente(datosAnimacion_t);

```
## Archivo func.h
```c
// archivo de funciones locales al software

//animacion de desplazamiento de palabras de LED en una direccion
datosAnimacion_t ascendente(datosAnimacion_t){
    char auxiliar="\0";
    strcpy(auxiliar,datosAnimacion_t.palabra1);
    strcpy(datosAnimacion_t.palabra1,datosAnimacion_t.palabra2);
    strcpy(datosAnimacion_t.palabra2,datosAnimacion_t.palabra3);
    strcpy(datosAnimacion_t.palabra3,datosAnimacion_t.palabra4);
    strcpy(datosAnimacion_t.palabra4,auxiliar);

    return datosAnimacion_t;
}

```
![Image text](fotoEstados.jpg)
