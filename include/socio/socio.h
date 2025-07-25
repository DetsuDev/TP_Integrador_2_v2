#ifndef SOCIO_H
#define SOCIO_H

#include "Fecha.h"
#include "Domicilio.h"

/// Objeto Socio: DNI, Nombre, Direccion, Email, Fecha de Nacimiento

class Socio {
private:
    bool estado = false;
    char dni[10];
    char nombre[30];
    char apellido[30];
    Fecha fecha_nac;
    char email[40];
    Domicilio domicilio;

public:
    /// Setters
    void set_estado( bool );
    void set_dni( const char* );
    void set_nombre( const char* );
    void set_apellido( const char* );
    void set_fecha_nac( Fecha );
    void set_email( const char* );
    void set_domicilio( Domicilio );

    /// Getters
    bool get_estado();
    const char* get_dni();
    const char* get_nombre();
    const char* get_apellido();
    Fecha get_fecha_nac();
    const char* get_email();
    Domicilio get_domicilio();

    /// Funciones
    void mostrar();
};

#endif // SOCIO_H
