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
