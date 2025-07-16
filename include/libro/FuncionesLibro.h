#ifndef FUNCIONESLIBRO_H
#define FUNCIONESLIBRO_H

#include "Libro.h"

class FuncionesLibro {
public:
    FuncionesLibro();
    void cargar( Libro &obj );
    void registrar();
    void listar();
    void buscar();
    void eliminar();
protected:

private:
};


#endif // FUNCIONESLIBRO_H
