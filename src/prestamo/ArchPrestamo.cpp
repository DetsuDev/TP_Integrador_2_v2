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

void ArchPrestamo::limpiar( const char* dni ) {
    Prestamo obj;
    int cantReg = contar();
    for ( int i = 0; i < cantReg; i++ ) {
        obj = leer ( i );
        if ( strcmp( obj.get_dni(), dni ) == 0 ) {
            if ( obj.get_estado() ) {
                obj.set_estado( false );
            }
        }
    }
}

int ArchPrestamo::buscar_id( int id_prestamo ) {
    Prestamo obj;
    int cantReg = contar();
    for ( int i = 0; i < cantReg; i++ ) {
        obj = leer( i );
        if ( obj.get_id_prestamo() == id_prestamo ) {
            if ( obj.get_estado() ) {
                return i;
            } else {
                return -1;
            }
        }
    }
    return -2;
}

int ArchPrestamo::buscar( const char *dato, const char *tipo ) {
    /// Tipos de datos: "i" para isbn, "d" para DNI,
    Prestamo obj;
    int cantReg = contar();
    for ( int i = 0; i < cantReg; i++ ) {
        obj = leer( i );
            if (strcmp( "i", tipo ) == 0 && strcmp( obj.get_isbn(), dato ) == 0 ) {
                return i;
            }
            if ( strcmp( "d", tipo ) == 0 && strcmp( obj.get_dni(), dato ) == 0 ) {
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

