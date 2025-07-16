#include <iostream>
#include "Funciones.h"

using namespace std;

Funciones::Funciones() {}
/// Esta funcion carga los caracteres recibidios en un vector "palabra", con el tamaño indicado en la variable "tamano".
void Funciones::cargar_cadena( char *palabra, int tamano ) {
    int i = 0;

    fflush( stdin );
    for ( i = 0; i < tamano; i++ ) {
        palabra[i] = cin.get();
        if ( palabra[i] == '\n' ) {
            break;
        }
    }
    palabra[i] = '\0';
    fflush( stdin );
}
