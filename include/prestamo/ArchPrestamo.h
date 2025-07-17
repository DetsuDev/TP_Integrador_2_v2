#ifndef ARCHPRESTAMO_H
#define ARCHPRESTAMO_H


#include "Prestamo.h"

class ArchPrestamo {
private:
    char nombre[30];
public:
    ArchPrestamo( const char *n = "files/current/Prestamos.dat" );
    Prestamo leer( int pos );
    bool grabar( Prestamo obj );
    bool modificar( Prestamo obj, int pos );
    int contar();
    int buscar( int id_prestamo );
};

#endif // ARCHPRESTAMO_H
