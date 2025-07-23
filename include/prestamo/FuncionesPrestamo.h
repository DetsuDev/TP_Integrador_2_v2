#ifndef FUNCIONESPRESTAMO_H
#define FUNCIONESPRESTAMO_H

#include "Prestamo.h"
#include "ArchSocio.h"
#include "ArchLibro.h"
#include "ArchPrestamo.h"
#include "ArchCuota.h"
#include "Funciones.h"

class FuncionesPrestamo {
private:
    ArchLibro archLibro;
    ArchSocio archSocio;
    ArchCuota archCuota;
    ArchPrestamo archPrest;
    Funciones f;
public:
    FuncionesPrestamo();
    void cargar( Prestamo &obj );
    void registrar();
    void listar(const char* dato, const char* tipo);
    void buscar();
    void eliminar();
};


#endif // FUNCIONESPrestamo_H
