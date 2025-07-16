#ifndef ARCHSOCIO_H
#define ARCHSOCIO_H

#include "socio/Socio.h"

class ArchSocio {
private:
    char nombre[30];
public:
    ArchSocio( const char *n = "files/current/Socios.dat" );
    Socio leer( int pos );
    bool grabar( Socio obj );
    bool modificar( Socio obj, int pos );
    int contar();
    int buscar( const char* dni );
};

#endif // ARCH_SOCIO_H

