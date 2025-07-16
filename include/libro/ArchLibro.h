#ifndef ARCHLIBRO_H
#define ARCHLIBRO_H

#include "Libro.h"

class ArchLibro {
private:
    char nombre[30];
public:
    ArchLibro( const char *n = "files/current/Libros.dat" );
    Libro leer( int pos );
    bool grabar( Libro obj );
    bool modificar( Libro obj, int pos );
    int contar();
    int buscar( const char* isbn );
};

#endif // ARCHLIBRO_H
