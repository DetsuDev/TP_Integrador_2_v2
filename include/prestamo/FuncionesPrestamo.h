#ifndef FUNCIONESPRESTAMO_H
#define FUNCIONESPRESTAMO_H

#include "Prestamo.h"
#include "ArchSocio.h"
#include "ArchLibro.h"
#include "ArchPrestamo.h"
#include "Funciones.h"

class FuncionesPrestamo {
private:
    ArchLibro archLibro;
    ArchSocio archSocio;
    ArchPrestamo archPrest;
    Funciones f;
public:
    FuncionesPrestamo();
    void cargar( Prestamo &obj );
    void registrar();
    void listar();
    void buscar();
    void eliminar();
};


#endif // FUNCIONESPrestamo_H
