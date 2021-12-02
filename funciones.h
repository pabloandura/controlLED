int ritmo(float bpm, display_t *leds, long * c)
{
    /**
    ritmo recibe un float que le indica cuantas
    veces de prenden y apagan las luces en un minuto
    */

    printf("Ritmo\n");
    printf("*** Demonstracion *** \n\n");

    //impresion
        if(*c%2) // si es par o !=0 entra
        {
            // apagamos todas
            leds->fila1=0;
            leds->fila2=0;
            leds->fila3=0;
            leds->fila4=0;
            leds->fila5=0;
            leds->fila6=0;
            leds->fila7=0;
            leds->fila8=0;

        }
        else
        {
            // prendemos todas
            leds->fila1=255;
            leds->fila2=255;
            leds->fila3=255;
            leds->fila4=255;
            leds->fila5=255;
            leds->fila6=255;
            leds->fila7=255;
            leds->fila8=255;
        }
    // imprimimos en pantalla la
        printf("\nEl valor de la 1ra fila es: %d",leds->fila1);
        printf("\nEl valor de la 2nd fila es: %d",leds->fila2);
        printf("\nEl valor de la 3ra fila es: %d",leds->fila3);
        printf("\nEl valor de la 4ta fila es: %d",leds->fila4);
        printf("\nEl valor de la 5ta fila es: %d",leds->fila5);
        printf("\nEl valor de la 6ta fila es: %d",leds->fila6);
        printf("\nEl valor de la 7ma fila es: %d",leds->fila7);
        printf("\nEl valor de la 8va fila es: %d",leds->fila8);

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

int fijado(float n,display_t *leds, long * c)
{
     /**
    fijado recibe un float que le indica cuantas
    veces de prenden y apagan las luces en un segundo

    */
    printf("Fijado\n");
        // inicializamos las variables
    printf("*** Demonstracion *** \n\n");

    //impresion
        if(*c%2) // si es par o !=0 entra
        {
            // apagamos todas
            leds->fila1=0;
            leds->fila2=0;
            leds->fila3=0;
            leds->fila4=0;
            leds->fila5=0;
            leds->fila6=0;
            leds->fila7=0;
            leds->fila8=0;

        }
        else
        {
            // prendemos todas
            leds->fila1=255;
            leds->fila2=255;
            leds->fila3=255;
            leds->fila4=255;
            leds->fila5=255;
            leds->fila6=255;
            leds->fila7=255;
            leds->fila8=255;
        }
    // imprimimos en pantalla la
        printf("\nEl valor de la 1ra fila es: %d",leds->fila1);
        printf("\nEl valor de la 2nd fila es: %d",leds->fila2);
        printf("\nEl valor de la 3ra fila es: %d",leds->fila3);
        printf("\nEl valor de la 4ta fila es: %d",leds->fila4);
        printf("\nEl valor de la 5ta fila es: %d",leds->fila5);
        printf("\nEl valor de la 6ta fila es: %d",leds->fila6);
        printf("\nEl valor de la 7ma fila es: %d",leds->fila7);
        printf("\nEl valor de la 8va fila es: %d",leds->fila8);

    /* Seccion de prendido y apagado en intervalos fijos

                para llevarlo a microsegundos, lo multiplico por 10.000 ya que n es un numero relativo
                desde el punto de vista practico

                Utilizo microsegundos porque me permite tener mas definicion.
    */
    usleep((useconds_t)(n*10000));
    system("cls");
    return detectar();
}

int detectar(void)
{
    int cont=0;
    printf("\nDetectando...\n");
    if(kbhit()) //simulamos deteccion de musica
        return 1;
    return 0;
}

char * getKey(char *key)
{
    char i=0;
    while(*(key+i)!=' ')
    {
        i++;
    }
    *(key+1)=0;
    return key+i+1;
}
int setConfiguracion(int *e,float *bpm,long *c)
{
    //    Codigo de lectura de archivo de configuracion.
    FILE *conf;
    char variables[3][20]={"e","c","bpm"},i; // declaro e inicializo una matriz para guardar los datos de configuracion
    char cadena[40], *key, *val; // declaro la cadena auxiliar, los punteros a valores key y val, y la variable que guardara el nombre de las configuraciones
    if((conf = fopen("config.conf","rb"))==NULL){
        printf("\n ERROR: No se encontro el archivo de configuracion.\n");
        return 0;
    }
    fgets(cadena,40,conf);
    do
    {
        key = cadena;
        if((*key)!= '#' && strlen(key) >= 0) //ignoramos comentario
        {
            val = getKey(key); // modifica a key para que solo contenga la clave y devuelve
            // printf("%s: %s\n",key, val); // Imprime resultado
            for(i=0;i<3;i++)
            {
                if(!strcmp(key,variables[i]))
                {
                    switch(i)
                    {
                        case 0: *e=atoi(val); // usamos funcion atoi
                            break;
                        case 1: *c=(long)atoi(val);
                            break;
                        case 2: *bpm=(float)atoi(val);
                            break;

                    }
                }
            }
        }
        fgets(cadena,40,conf);
    }while(!feof(conf));
    // FIN DE ARCHIVO DE CONFIGURACION
return 1;
}
