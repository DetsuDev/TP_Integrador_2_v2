#ifndef FUNCIONESCUOTA_H
#define FUNCIONESCUOTA_H

#include "Cuota.h"

class FuncionesCuota
{
    public:
    FuncionesCuota();
    void cargar( Cuota &obj );
    void registrar();
    void listar();
    void buscar();
    void eliminar();
};

#endif // FUNCIONESCUOTA_H
