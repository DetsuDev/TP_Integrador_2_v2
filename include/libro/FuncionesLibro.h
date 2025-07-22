#ifndef FUNCIONESLIBRO_H
#define FUNCIONESLIBRO_H

#include "Libro.h"
#include "ArchLibro.h"
#include "ArchPrestamo.h"
#include "Funciones.h"

class FuncionesLibro {
private:
    ArchLibro archLibro;
    ArchPrestamo archPrest;
    Funciones f;
public:
    FuncionesLibro();
    void cargar( Libro &obj );
    void registrar();
    void listar();
    void buscar();
    void eliminar();
};


#endif // FUNCIONESLIBRO_H
