#include <iostream>
#include <cstring>
#include "Cuota.h"

using namespace std;

void Cuota::mostrar() {
cout << "DNI: " << dni << endl;
cout << "Mes: " << mes << endl;
cout << "Anio: " << anio << endl;
cout << "Importe: " << importe << endl;
cout << "Fecha de pago: ";
fecha_pago.mostrar();
cout << "---------------------------------------------------------------------\n";
}


/// Setters
void Cuota::set_estado(bool e) { estado = e; }
void Cuota::set_dni(const char *i){ strcpy(dni, i); }
void Cuota::set_mes(int m) { mes = m; }
void Cuota::set_anio(int a) { anio = a; }
void Cuota::set_importe(float imp) { importe = imp; }
void Cuota::set_fecha_pago(Fecha f) { fecha_pago = f; }

/// Getters
bool Cuota::get_estado() { return estado; }
const char* Cuota::get_dni(){ return dni; }
int Cuota::get_mes() { return mes; }
int Cuota::get_anio() { return anio; }
float Cuota::get_importe() { return importe; }
Fecha Cuota::get_fecha_pago() { return fecha_pago; }
