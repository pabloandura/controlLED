/**
- El programa constantemente verifica si se esta reproduciendo música. El prototipo puede contar con una entrada de audio (micrófono/cable 1/4 pulgada TRS) y un convertidor de analógico a digital. Una vez la señal es digital, se puede devolver un valor entero a nuestro programa con la cantidad de pulsos por minuto (beats per minute en inglés).-
*/
#include "archivo.h"



int main(int comandoInt, char **comandoVect)
{

    int e; // declaro variable de estado, y array de leds
    float bpm=120; // declaro la variable de pulsos por minuto
    long c; // declaro el contador global
    display_t leds; // declaro un array bidimensional que en el primer
    int SET; //bandera de configuracion exitorsa
    SET = setConfiguracion(&e,&bpm,&c);
    //pregunta de estado
    while(SET)
    {
        e=p[e](bpm,&leds,&c);
        c++;
    }
    return 0;
}
