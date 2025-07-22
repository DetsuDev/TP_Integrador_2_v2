#include <iostream>
#include <cstring>
#include "ArchCuota.h"
#include "Cuota.h"
#include "Funciones.h"

using namespace std;

ArchCuota::ArchCuota( const char *n ) {
    strcpy( nombre, n );
}

bool ArchCuota::grabar( Cuota obj ) {
    FILE *p = fopen( nombre, "ab" );
    if ( p == nullptr ) {
        return false;
    }
    bool escribio = fwrite( &obj, sizeof obj, 1, p );
    fclose( p );
    return escribio;
}

Cuota ArchCuota::leer( int pos ) {
    Cuota obj;


    FILE *p = fopen( nombre, "rb" );
    fseek( p, pos * sizeof obj, 0 );
    fread( &obj, sizeof obj, 1, p );
    fclose( p );
    if ( obj.get_estado() ) {
        return obj;
    }
}
void ArchCuota::limpiar( const char* dni ) {
    Cuota obj;
    int cantReg = contar();
    for ( int i = 0; i < cantReg; i++ ) {
        obj = leer ( i );
        if ( strcmp( obj.get_dni(), dni ) == 0 ) {
            if ( obj.get_estado() ) {
                obj.set_estado(false);
            }
        }
    }
}

int ArchCuota::buscar( const char *dni, int mes, int anio ) {
    Cuota obj;
    int cantReg = contar();
    for ( int i = 0; i < cantReg; i++ ) {
        obj = leer( i );

        if (strcmp( obj.get_dni(), dni ) == 0 && obj.get_mes() == mes && obj.get_anio() == anio)
        {
            if (obj.get_estado())
            {
                return i;
            }
            else
            {
                return -1;
            }
        }
    }
    return -2;
}

int ArchCuota::buscar_dni( const char *dni ) {
    Cuota obj;
    int cantReg = contar();
    for ( int i = 0; i < cantReg; i++ ) {
        obj = leer( i );
        if ( strcmp( obj.get_dni(), dni ) == 0 ) {
            if ( obj.get_estado() ) {
                return i;
            } else {
                return -1;
            }
        }
    }
    return -2;
}
bool ArchCuota::modificar( Cuota obj, int pos ) {
    FILE *p;
    p = fopen( nombre, "rb+" );
    if ( p == nullptr ) {
        return false;
    }
    fseek( p, pos * sizeof obj, 0 );
    bool escribio = fwrite( &obj, sizeof obj, 1, p );
    fclose( p );
    return escribio;
}

int ArchCuota::contar() {
    FILE *p = fopen( nombre, "rb" );
    if ( p == nullptr ) {
        return -1;
    }
    fseek( p, 0, 2 );
    int tam = ftell( p );
    fclose( p );
    return tam / sizeof ( Cuota );
}
