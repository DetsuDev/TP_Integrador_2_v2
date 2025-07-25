#ifndef CUOTA_H
#define CUOTA_H

#include "Fecha.h"

class Cuota {
private:
    bool estado = false;
    char dni[10];
    Fecha fecha_pago;
    float importe;
    int mes;
    int anio;
public:
    /// Setters
    bool get_estado();
    const char* get_dni();
    Fecha get_fecha_pago();
    float get_importe();
    int get_mes();
    int get_anio();

    /// Setters
    void set_estado( bool );
    void set_dni( const char* );
    void set_fecha_pago( Fecha f );
    void set_importe( float imp );
    void set_mes( int m );
    void set_anio( int a );

    /// Funciones
    void mostrar();

};

#endif // CUOTA_H
