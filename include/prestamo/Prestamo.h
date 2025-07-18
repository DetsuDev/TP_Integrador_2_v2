#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Fecha.h"

class Prestamo {
private:
    bool estado = false;
    int id_prestamo;
    char isbn[20];
    char titulo[50];
    char dni[10];
    Fecha fecha_prest;
    Fecha fecha_dev;
public:
    /// Setters
    void set_estado( bool );
    void set_id_prestamo( int );
    void set_isbn( const char* );
    void set_titulo( const char* );
    void set_dni( const char* );
    void set_fecha_prest( Fecha );
    void set_fecha_dev( Fecha );

    /// Getters
    bool get_estado();
    int get_id_prestamo();
    const char* get_isbn();
    const char* get_titulo();
    const char* get_dni();
    Fecha get_fecha_prest();
    Fecha get_fecha_dev();

    /// Funciones
    void mostrar();

};

#endif // PRESTAMO_H
