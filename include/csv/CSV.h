#ifndef CSV_H
#define CSV_H

#include "ArchSocio.h"
#include "ArchLibro.h"
#include "ArchPrestamo.h"
#include "ArchCuota.h"

class CSV {
private:
    ArchCuota archCuota;
    ArchSocio archSocio;
    ArchPrestamo archPrest;
    ArchLibro archLibro;
public:
    void exp_socios();
    void exp_libros();
    void exp_prestamos();
    void exp_cuotas();
};

#endif // CSV_H
