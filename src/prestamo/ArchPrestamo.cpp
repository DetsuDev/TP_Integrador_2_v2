#include <iostream>
#include <cstring>
#include "ArchPrestamo.h"
#include "Prestamo.h"
#include "Funciones.h"

using namespace std;

ArchPrestamo::ArchPrestamo( const char *n ) {
    strcpy( nombre, n );
}

bool ArchPrestamo::grabar( Prestamo obj ) {
    FILE *p = fopen( nombre, "ab" );
    if ( p == nullptr ) {
        return false;
    }
    bool escribio = fwrite( &obj, sizeof obj, 1, p );
    fclose( p );
    return escribio;
}

Prestamo ArchPrestamo::leer( int pos ) {
    Prestamo obj;

    FILE *p = fopen( nombre, "rb" );
    fseek( p, pos * sizeof obj, 0 );
    fread( &obj, sizeof obj, 1, p );
    fclose( p );
    return obj;
}


int ArchPrestamo::buscar( int id_prestamo ) {
    Prestamo obj;
        int cantReg = contar();
        for ( int i = 0; i < cantReg; i++ ) {
            obj = leer( i );
            if ( obj.get_estado() && obj.get_id_prestamo() == id_prestamo ) {
                return i;
            }
        }
    return -1;
}

bool ArchPrestamo::modificar( Prestamo obj, int pos ) {
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

int ArchPrestamo::contar() {
    FILE *p = fopen( nombre, "rb" );
    if ( p == nullptr ) {
        return -1;
    }
    fseek( p, 0, 2 );
    int tam = ftell( p );
    fclose( p );
    return tam / sizeof ( Prestamo );
}

