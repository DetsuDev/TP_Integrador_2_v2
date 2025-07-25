#include "CSV.h"
#include <fstream>
#include <iostream>
using namespace std;

void CSV::exp_socios() {
    ofstream archivo("files/CSV/socios.csv");
    archivo << "DNI,Nombre,Apellido,FechaNac,Calle,Altura,Localidad,Partido, CP,Email\n";
    Socio socio;
    for (int i = 0; i < archSocio.contar(); i++) {
        socio = archSocio.leer(i);
        if (socio.get_estado()){

        archivo << socio.get_dni() << ","
                << socio.get_nombre() << ","
                << socio.get_apellido() << ","
                << socio.get_fecha_nac().get_dia() << "/"
                << socio.get_fecha_nac().get_mes() << "/"
                << socio.get_fecha_nac().get_anio() << ","
                << socio.get_domicilio().get_calle() << ","
                << socio.get_domicilio().get_altura() << ","
                << socio.get_domicilio().get_localidad() << ","
                << socio.get_domicilio().get_partido() << ","
                << socio.get_domicilio().get_codigo_postal() << ","
                << socio.get_email() << "\n";
        }
    }
    archivo.close();
    cout << "Socios exportados a socios.csv\n";
}

void CSV::exp_libros() {
    ofstream archivo("files/CSV/libros.csv");
    archivo << "ISBN,Titulo,Autor,Ejemplares\n";
    Libro libro;
    for (int i = 0; i < archLibro.contar(); i++) {
        libro = archLibro.leer(i);
        if (libro.get_estado()){
        archivo << libro.get_isbn() << ","
                << libro.get_titulo() << ","
                << libro.get_autor() << ","
                << libro.get_c_ejemplares() << "\n";
        }
    }
    archivo.close();
    cout << "Libros exportados a libros.csv\n";
}

void CSV::exp_prestamos() {
    ofstream archivo("files/CSV/prestamos.csv");
    archivo << "ID,ISBN,Titulo,DNI,FechaPrestamo,FechaDevolucion\n";
    Prestamo prestamo;
    for (int i = 0; i < archPrest.contar(); i++) {
        prestamo = archPrest.leer(i);
        if (prestamo.get_estado()){
        archivo << prestamo.get_id_prestamo() << ","
                << prestamo.get_isbn() << ","
                << prestamo.get_titulo() << ","
                << prestamo.get_dni() << ","
                << prestamo.get_fecha_prest().get_dia() << "/"
                << prestamo.get_fecha_prest().get_mes() << "/"
                << prestamo.get_fecha_prest().get_anio() << ","
                << prestamo.get_fecha_dev().get_dia() << "/"
                << prestamo.get_fecha_dev().get_mes() << "/"
                << prestamo.get_fecha_dev().get_anio() << "\n";
                }
    }
    archivo.close();
    cout << "Prestamos exportados a prestamos.csv\n";
}

void CSV::exp_cuotas() {
    ofstream archivo("files/CSV/cuotas.csv");
    archivo << "DNI,Importe,Fecha,FechaPago\n";
    Cuota cuota;
    for (int i = 0; i < archCuota.contar(); i++) {
        cuota = archCuota.leer(i);
        if (cuota.get_estado()){
        archivo << cuota.get_dni() << ","
                << cuota.get_importe() << ","
                << cuota.get_mes() << "/"
                << cuota.get_anio() << ","
                << cuota.get_fecha_pago().get_dia() << "/"
                << cuota.get_fecha_pago().get_mes() << "/"
                << cuota.get_fecha_pago().get_anio() << "\n";
        }
    }
    archivo.close();
    cout << "Cuotas exportadas a cuotas.csv\n";
}
