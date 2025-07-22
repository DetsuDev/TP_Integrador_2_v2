#ifndef FUNCIONESCUOTA_H
#define FUNCIONESCUOTA_H

#include "Cuota.h"
#include "ArchSocio.h"
#include "ArchCuota.h"
#include "Funciones.h"

class FuncionesCuota {
private:
    ArchSocio archSocio;
    ArchCuota archCuota;
    Funciones f;
public:
    FuncionesCuota();
    void cargar( Cuota &obj );
    void registrar();
    void listar( const char *dni );
    void buscar();
    void eliminar();
};

#endif // FUNCIONESCUOTA_H
