#ifndef FUNCIONESSOCIO_H
#define FUNCIONESSOCIO_H

#include "socio/Socio.h"

class FuncionesSocio {
public:
    FuncionesSocio();
    void cargar( Socio &obj );
    void registrar();
    void listar();
    void buscar();
    void eliminar();
protected:

private:
};

#endif // FUNCIONESSOCIO_H
