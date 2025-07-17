#include "Prestamo.h"

#include <iostream>
#include <cstring>

using namespace std;

void Prestamo::mostrar(){
    cout << "ID: " << id_prestamo << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "DNI Socio: " << dni << endl;
    cout << "Fecha Prestamo: ";
    fecha_prest.mostrar();
    cout << "Fecha Devolucion: ";
    fecha_dev.mostrar();
    cout << "---------------------------------------------------------------------\n";
}

/// Setters
void Prestamo::set_estado(bool e) { estado = e; }
void Prestamo::set_id_prestamo(int id) { id_prestamo = id; }
void Prestamo::set_isbn(const char *i) { strcpy(isbn, i); }
void Prestamo::set_titulo(const char *t) { strcpy(titulo, t); }
void Prestamo::set_dni(const char *d) { strcpy(dni, d); }
void Prestamo::set_fecha_prest(Fecha f) { fecha_prest = f; }
void Prestamo::set_fecha_dev(Fecha f) { fecha_dev = f; }

/// Getters
bool Prestamo::get_estado() { return estado; }
int Prestamo::get_id_prestamo() { return id_prestamo; }
const char* Prestamo::get_isbn() { return isbn; }
const char* Prestamo::get_titulo() { return titulo; }
const char* Prestamo::get_dni() { return dni; }
Fecha Prestamo::get_fecha_prest() { return fecha_prest; }
Fecha Prestamo::get_fecha_dev() { return fecha_dev; }
