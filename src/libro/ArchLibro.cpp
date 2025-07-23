#include <iostream>
#include <cstring>
#include "ArchLibro.h"
#include "Libro.h"
#include "Funciones.h"

using namespace std;

ArchLibro::ArchLibro( const char *n )
{
    strcpy( nombre, n );
}

bool ArchLibro::grabar( Libro obj )
{
    FILE *p = fopen( nombre, "ab" );
    if ( p == nullptr )
    {
        return false;
    }
    bool escribio = fwrite( &obj, sizeof obj, 1, p );
    fclose( p );
    return escribio;
}

Libro ArchLibro::leer( int pos )
{
    Libro obj;

    FILE *p = fopen( nombre, "rb" );
    fseek( p, pos * sizeof obj, 0 );
    fread( &obj, sizeof obj, 1, p );
    fclose( p );
    return obj;
}
int ArchLibro::buscar( const char *dato, const char *tipo )
{
    /// Tipos de datos: i para isbn, t para titulo,
    Libro obj;
    int cantReg = contar();
    for ( int i = 0; i < cantReg; i++ )
    {
        obj = leer( i );
        if (strcmp( "i", tipo ) == 0 && strcmp( obj.get_isbn(), dato ) == 0 )
        {
            return i;
        }
        if ( strcmp( "t", tipo ) == 0 && strcmp( obj.get_titulo(), dato ) == 0 )
        {
            return i;
        }
    }
    return -1;
}

bool ArchLibro::modificar( Libro obj, int pos )
{
    FILE *p;
    p = fopen( nombre, "rb+" );
    if ( p == nullptr )
    {
        return false;
    }
    fseek( p, pos * sizeof obj, 0 );
    bool escribio = fwrite( &obj, sizeof obj, 1, p );
    fclose( p );
    return escribio;
}

int ArchLibro::contar()
{
    FILE *p = fopen( nombre, "rb" );
    if ( p == nullptr )
    {
        return -1;
    }
    fseek( p, 0, 2 );
    int tam = ftell( p );
    fclose( p );
    return tam / sizeof ( Libro );
}

