// archivo de funciones locales al software

//animacion de desplazamiento de palabras de LED en una direccion
struct datos ascendente(struct datos p){
    int operador=1;
    int i=0;
    for(i=0;i<4;i++){
    char auxiliar[10]="\0";
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
        }
return p;
}

int abrir(struct datos *V)//abre el archivo y vuelca los datos en un vector
{
    FILE *fp;
    struct datos aux;
    char direccion[100];
    int i=0;

    printf("\nIngrese la ubicacion del archivo: ");
    fflush(stdin);
    gets(direccion);

    while(!(fp=fopen(direccion, "rb")))//El bucle se repite mientras el archivo no se pueda abrir
        {
        printf("No se pudo abrir el archivo en la ubicacion %s....\n",direccion);
        printf("\nRevise la ubicacion y vuelva a intentarlo...");

        printf("\nIngrese la ubicacion del archivo: ");
        fflush(stdin);
        gets(direccion);
        }
    system("CLS");

    fread(&aux,sizeof(aux), 1, fp);
    while(!feof(fp)) //Paso los datos del archivo al programa
    {
        V[i]=aux;
        i++;//Lo uso como contador para luego leer e imprimir el vector
        fread(&aux,sizeof(aux), 1, fp);
    }
    fclose(fp);//cierro el archivo
    return i;
}

