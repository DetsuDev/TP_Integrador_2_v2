#include "CSV.h"
#include "ArchSocio.h"
#include "ArchLibro.h"
#include "ArchPrestamo.h"
#include "ArchCuota.h"
#include <fstream>
#include <iostream>
using namespace std;

void CSV::exportarSocios() {
    ofstream archivo("socios.csv");
    archivo << "DNI,Nombre,Apellido,Telefono,Email,Estado\n";
    ArchSocio reg;
    Socio obj;
    for (int i = 0; i < reg.contar(); i++) {
        obj = reg.leer(i);
        archivo << obj.get_dni() << ","
                << obj.get_nombre() << ","
                << obj.get_apellido() << ","
                << obj.get_telefono() << ","
                << obj.get_email() << ","
                << (obj.get_estado() ? "Activo" : "Inactivo") << "\n";
    }
    archivo.close();
    cout << "Socios exportados a socios.csv\n";
}

void CSV::exportarLibros() {
    ofstream archivo("libros.csv");
    archivo << "ISBN,Titulo,Autor,Ejem,Estado\n";
    ArchLibro reg;
    Libro obj;
    for (int i = 0; i < reg.contar(); i++) {
        obj = reg.leer(i);
        archivo << obj.get_isbn() << ","
                << obj.get_titulo() << ","
                << obj.get_autor() << ","
                << obj.get_c_ejemplares() << ","
                << (obj.get_estado() ? "Activo" : "Inactivo") << "\n";
    }
    archivo.close();
    cout << "Libros exportados a libros.csv\n";
}

void CSV::exportarPrestamos() {
    ofstream archivo("prestamos.csv");
    archivo << "ID,ISBN,Titulo,DNI,FechaPrestamo,FechaDevolucion,Estado\n";
    ArchPrestamo reg;
    Prestamo obj;
    for (int i = 0; i < reg.contar(); i++) {
        obj = reg.leer(i);
        archivo << obj.get_id_prestamo() << ","
                << obj.get_isbn() << ","
                << obj.get_titulo() << ","
                << obj.get_dni() << ","
                << obj.get_fecha_prest().toString() << ","
                << obj.get_fecha_dev().toString() << ","
                << (obj.get_estado() ? "Activo" : "Inactivo") << "\n";
    }
    archivo.close();
    cout << "Prestamos exportados a prestamos.csv\n";
}

void CSV::exportarCuotas() {
    ofstream archivo("cuotas.csv");
    archivo << "DNI,Importe,Mes,Año,FechaPago,Estado\n";
    ArchCuota reg;
    Cuota obj;
    for (int i = 0; i < reg.contar(); i++) {
        obj = reg.leer(i);
        archivo << obj.get_dni() << ","
                << obj.get_importe() << ","
                << obj.get_mes() << ","
                << obj.get_anio() << ","
                << obj.get_fecha_pago().toString() << ","
                << (obj.get_estado() ? "Pagada" : "Impaga") << "\n";
    }
    archivo.close();
    cout << "Cuotas exportadas a cuotas.csv\n";
}
