#ifndef ARCH_SOCIO_H
#define ARCH_SOCIO_H

#include "socio/socio.h"

class ArchSocio
{
private:
    char nombre[30];
public:
    ArchSocio(const char *n="files/current/Socios.dat");
    Socio leer(int pos);
    bool grabar(Socio obj);
    bool modificar(Socio obj, int pos);
    int contar();
    int buscar(const char* dni);
    void cargar(Socio &obj);
    void registrar();
    void listar();
};

#endif // ARCH_SOCIO_H

