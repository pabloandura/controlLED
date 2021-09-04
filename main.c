#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//archivo de prototipos
#include "proto.h"
//archivo de funciones
#include "func.h"
// Pablo Javier Lopez Andura - 109947 DNI 38-456-394 UTN AVELLANEDA - INFORMATICA II - DAMIAN CORBALAN Y GUSTAVO VIARD


//macro setbit
#define setBit(reg,bit) reg|(1<<bit)
#define tamanoPalabra 4

int i=0;
int operador=1;



int main(int argc, char const *argv[]){

//inicializo las strings

    dat_t p;

    p.aniNro=0;
    char auxiliar[1]="\0";
    /*
    while(1)
    {
        if(operador==1){
            // archivo de memorias de animacion personalizadas
        }
    }
    */
    strcpy(p.palabra1,"0001");
    strcpy(p.palabra2,"0010");
    strcpy(p.palabra3,"0100");
    strcpy(p.palabra4,"1000");

    //comienzo de maquina de estados


        ascendente(p);

        printf("Operador( 0 sale ): \n");
        scanf("%d", &operador);

    p.aniNro=0;
    return 0;
}
