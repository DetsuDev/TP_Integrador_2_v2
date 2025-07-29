#include "CSV.h"
#include <iostream>
using namespace std;

void CSV::exp_socios() {
    FILE* archivo = fopen("files/CSV/socios.csv", "w");
    if (!archivo) {
        cout << "No se pudo abrir socios.csv para escritura.\n";
        return;
    }
    fprintf(archivo, "DNI,Nombre,Apellido,FechaNac,Calle,Altura,Localidad,Partido,CP,Email\n");
    Socio socio;
    for (int i = 0; i < archSocio.contar(); i++) {
        socio = archSocio.leer(i);
        if (socio.get_estado()) {
            fprintf(archivo, "%s,%s,%s,%02d/%02d/%04d,%s,%d,%s,%s,%s,%s\n",
                socio.get_dni(),
                socio.get_nombre(),
                socio.get_apellido(),
                socio.get_fecha_nac().get_dia(),
                socio.get_fecha_nac().get_mes(),
                socio.get_fecha_nac().get_anio(),
                socio.get_domicilio().get_calle(),
                socio.get_domicilio().get_altura(),
                socio.get_domicilio().get_localidad(),
                socio.get_domicilio().get_partido(),
                socio.get_domicilio().get_codigo_postal(),
                socio.get_email());
        }
    }
    fclose(archivo);
    cout << "Socios exportados a socios.csv\n";
}

void CSV::exp_libros() {
    FILE* archivo = fopen("files/CSV/libros.csv", "w");
    if (!archivo) {
        cout << "No se pudo abrir libros.csv para escritura.\n";
        return;
    }
    fprintf(archivo, "ISBN,Titulo,Autor,Ejemplares\n");
    Libro libro;
    for (int i = 0; i < archLibro.contar(); i++) {
        libro = archLibro.leer(i);
        if (libro.get_estado()) {
            fprintf(archivo, "%s,%s,%s,%d\n",
                libro.get_isbn(),
                libro.get_titulo(),
                libro.get_autor(),
                libro.get_c_ejemplares());
        }
    }
    fclose(archivo);
    cout << "Libros exportados a libros.csv\n";
}

void CSV::exp_prestamos() {
    FILE* archivo = fopen("files/CSV/prestamos.csv", "w");
    if (!archivo) {
        cout << "No se pudo abrir prestamos.csv para escritura.\n";
        return;
    }
    fprintf(archivo, "ID,ISBN,Titulo,DNI,FechaPrestamo,FechaDevolucion\n");
    Prestamo prestamo;
    for (int i = 0; i < archPrest.contar(); i++) {
        prestamo = archPrest.leer(i);
        if (prestamo.get_estado()) {
            fprintf(archivo, "%d,%s,%s,%s,%02d/%02d/%04d,%02d/%02d/%04d\n",
                prestamo.get_id_prestamo(),
                prestamo.get_isbn(),
                prestamo.get_titulo(),
                prestamo.get_dni(),
                prestamo.get_fecha_prest().get_dia(),
                prestamo.get_fecha_prest().get_mes(),
                prestamo.get_fecha_prest().get_anio(),
                prestamo.get_fecha_dev().get_dia(),
                prestamo.get_fecha_dev().get_mes(),
                prestamo.get_fecha_dev().get_anio());
        }
    }
    fclose(archivo);
    cout << "Prestamos exportados a prestamos.csv\n";
}

void CSV::exp_cuotas() {
    FILE* archivo = fopen("files/CSV/cuotas.csv", "w");
    if (!archivo) {
        cout << "No se pudo abrir cuotas.csv para escritura.\n";
        return;
    }
    fprintf(archivo, "DNI,Importe,Fecha,FechaPago\n");
    Cuota cuota;
    for (int i = 0; i < archCuota.contar(); i++) {
        cuota = archCuota.leer(i);
        if (cuota.get_estado()) {
            fprintf(archivo, "%s,%.2f,%02d/%04d,%02d/%02d/%04d\n",
                cuota.get_dni(),
                cuota.get_importe(),
                cuota.get_mes(),
                cuota.get_anio(),
                cuota.get_fecha_pago().get_dia(),
                cuota.get_fecha_pago().get_mes(),
                cuota.get_fecha_pago().get_anio());
        }
    }
    fclose(archivo);
    cout << "Cuotas exportadas a cuotas.csv\n";
}
