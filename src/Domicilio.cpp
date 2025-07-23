#include <iostream>
#include <cstring>
#include "Domicilio.h"
#include "Funciones.h"

using namespace std;

void Domicilio::cargar() {
    Funciones f;
    cout << "Ingrese la calle: ";
    f.cargar_cadena( calle, 29 );
    cout << "Ingrese la altura (num): ";
    cin >> altura;
    cout << "Ingrese la localidad: ";
    f.cargar_cadena( localidad, 29 );
    cout << "Ingrese el partido: ";
    f.cargar_cadena( partido, 29 );
    cout << "Ingrese el codigo postal (num): ";
    f.cargar_cadena( codigo_postal, 5 );
}

/// Setters
void Domicilio::set_calle(const char *c) {  strcpy(calle,c); }
void Domicilio::set_altura(int a) { altura = a; }
void Domicilio::set_localidad(const char *l) {  strcpy(localidad,l); }
void Domicilio::set_partido(const char *p) {  strcpy(partido,p); }
void Domicilio::set_codigo_postal(const char *cp) {  strcpy(codigo_postal,cp); }

/// Getters
const char* Domicilio::get_calle() { return calle; }
int Domicilio::get_altura() { return altura; }
const char* Domicilio::get_localidad() { return localidad; }
const char* Domicilio::get_partido() { return partido; }
const char* Domicilio::get_codigo_postal() { return codigo_postal; }

void Domicilio::mostrar() {
    cout << "Direccion: " << calle << ", " << altura << ". Localidad: " << localidad << ". Partido: " << partido << ". CP: " << codigo_postal << endl;
}
