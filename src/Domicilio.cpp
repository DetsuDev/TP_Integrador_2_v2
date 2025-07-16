#include <iostream>
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

void Domicilio::mostrar() {
    cout << "Direccion: " << calle << ", " << altura << ". Localidad: " << localidad << ". Partido: " << partido << ". CP: " << codigo_postal << endl;
}
