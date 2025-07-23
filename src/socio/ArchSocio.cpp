#include <iostream>
#include <cstring>
#include "ArchSocio.h"
#include "Socio.h"
#include "Funciones.h"

using namespace std;

ArchSocio::ArchSocio( const char *n ) {
    strcpy( nombre, n );
}

bool ArchSocio::grabar( Socio obj ) {
    FILE *p = fopen( nombre, "ab" );
    if ( p == nullptr ) {
        return false;
    }
    bool escribio = fwrite( &obj, sizeof obj, 1, p );
    fclose( p );
    return escribio;
}

Socio ArchSocio::leer( int pos ) {
    Socio obj;
    FILE *p = fopen( nombre, "rb" );
    fseek( p, pos * sizeof obj, 0 );
    fread( &obj, sizeof obj, 1, p );
    fclose( p );
    return obj;
}

int ArchSocio::buscar( const char *dni ) {
    Socio obj;
    int cantReg = contar();
    for ( int i = 0; i < cantReg; i++ ) {
        obj = leer( i );
        if ( strcmp( obj.get_dni(), dni ) == 0 ) {
            if ( obj.get_estado() ) {
                return i;
            }
        }
    }
    return -1;
}

bool ArchSocio::modificar( Socio obj, int pos ) {
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

int ArchSocio::contar() {
    FILE *p = fopen( nombre, "rb" );
    if ( p == nullptr ) {
        return -1;
    }
    fseek( p, 0, 2 );
    int tam = ftell( p );
    fclose( p );
    return tam / sizeof ( Socio );
}
