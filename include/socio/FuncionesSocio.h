#ifndef FUNCIONESSOCIO_H
#define FUNCIONESSOCIO_H

#include "Socio.h"
#include "ArchSocio.h"
#include "ArchPrestamo.h"
#include "ArchCuota.h"
#include "Funciones.h"

class FuncionesSocio {
private:
    Funciones f;
    ArchSocio archSocio;
    ArchPrestamo archPrest;
    ArchCuota archCuota;

public:
    FuncionesSocio();
    void cargar( Socio &obj );
    void registrar();
    void listar();
    void buscar();
    void eliminar();

};

#endif // FUNCIONESSOCIO_H
