#include "CSV.h"
#include "ArchSocio.h"
#include "ArchLibro.h"
#include "ArchPrestamo.h"
#include "ArchCuota.h"
#include <fstream>
#include <iostream>
using namespace std;

void CSV::exp_socios() {
    ofstream archivo("CSV/socios.csv");
    archivo << "DNI,Nombre,Apellido,Email\n";
    ArchSocio reg;
    Socio obj;
    for (int i = 0; i < reg.contar(); i++) {
        obj = reg.leer(i);
        archivo << obj.get_dni() << ","
                << obj.get_nombre() << ","
                << obj.get_apellido() << ","
                << obj.get_email() << ",";
    }
    archivo.close();
    cout << "Socios exportados a socios.csv\n";
}

void CSV::exp_libros() {
    ofstream archivo("CSV/libros.csv");
    archivo << "ISBN,Titulo,Autor,Ejem\n";
    ArchLibro reg;
    Libro obj;
    for (int i = 0; i < reg.contar(); i++) {
        obj = reg.leer(i);
        archivo << obj.get_isbn() << ","
                << obj.get_titulo() << ","
                << obj.get_autor() << ","
                << obj.get_c_ejemplares() << ",";
    }
    archivo.close();
    cout << "Libros exportados a libros.csv\n";
}

void CSV::exp_prestamos() {
    ofstream archivo("CSV/prestamos.csv");
    archivo << "ID,ISBN,Titulo,DNI,FechaPrestamo,FechaDevolucion\n";
    ArchPrestamo reg;
    Prestamo obj;
    for (int i = 0; i < reg.contar(); i++) {
        obj = reg.leer(i);
        archivo << obj.get_id_prestamo() << ","
                << obj.get_isbn() << ","
                << obj.get_titulo() << ","
                << obj.get_dni() << ","
                << obj.get_fecha_prest().get_dia() << "/"
                << obj.get_fecha_prest().get_mes() << "/"
                << obj.get_fecha_prest().get_anio() << ","
                << obj.get_fecha_dev().get_dia() << "/"
                << obj.get_fecha_dev().get_mes() << "/"
                << obj.get_fecha_dev().get_anio() << ",";
    }
    archivo.close();
    cout << "Prestamos exportados a prestamos.csv\n";
}

void CSV::exp_cuotas() {
    ofstream archivo("CSV/cuotas.csv");
    archivo << "DNI,Importe,Fecha,FechaPago\n";
    ArchCuota reg;
    Cuota obj;
    for (int i = 0; i < reg.contar(); i++) {
        obj = reg.leer(i);
        archivo << obj.get_dni() << ","
                << obj.get_importe() << ","
                << obj.get_mes() << "/"
                << obj.get_anio() << ","
                << obj.get_fecha_pago().get_dia() << "/"
                << obj.get_fecha_pago().get_mes() << "/"
                << obj.get_fecha_pago().get_anio() << ",";
    }
    archivo.close();
    cout << "Cuotas exportadas a cuotas.csv\n";
}
