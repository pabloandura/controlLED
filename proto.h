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


// funciones de programa
int abrir(struct datos *);//recibe un puntero a la estructura y retorna un entero el cual indica la dimension del vector
struct datos ascendente(struct datos);
