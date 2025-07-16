#include <iostream>
#include <cstring>
#include "Fecha.h"
#include "Domicilio.h"
#include "Socio.h"
using namespace std;

void Socio::mostrar() {
    cout << "DNI: " << dni << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Fecha Nac: ";
    fecha_nac.mostrar();
    cout << "Email: " << email << endl;
    cout << "Domicilio: \n";
    domicilio.mostrar();
    cout << "---------------------------------------------------------------------\n";
}


/// Setters
void Socio::set_estado(bool e) { estado = e; }
void Socio::set_dni(const char *i) { strcpy(dni, i); }
void Socio::set_nombre(const char *e) { strcpy(nombre, e); }
void Socio::set_apellido(const char *e) { strcpy(apellido, e); }
void Socio::set_fecha_nac(Fecha f) { fecha_nac = f; }
void Socio::set_email(const char *e) { strcpy(email, e); }
void Socio::set_domicilio(Domicilio d) { domicilio = d; }

/// Getters
bool Socio::get_estado() { return estado; }
const char* Socio::get_dni() { return dni; }
const char* Socio::get_nombre() { return nombre; }
const char* Socio::get_apellido() { return apellido; }
Fecha Socio::get_fecha_nac() { return fecha_nac; }
const char* Socio::get_email() { return email; }
Domicilio Socio::get_domicilio() { return domicilio; }
