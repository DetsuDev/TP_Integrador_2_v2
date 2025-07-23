#ifndef ARCHCUOTA_H
#define ARCHCUOTA_H


#include "Cuota.h"

class ArchCuota {
private:
    char nombre[30];
public:
    ArchCuota( const char *n = "files/current/Cuotas.dat" );
    Cuota leer( int pos );
    bool grabar( Cuota obj );
    bool modificar( Cuota obj, int pos );
    int contar();
    int buscar( const char* dni, int mes, int anio, const char* tipo );
    void limpiar(const char* dni);
};

#endif // ARCHCUOTA_H
