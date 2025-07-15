
#include <iostream>
#include "Domicilio.h"
#include "Funciones.h"

using namespace std;

void Domicilio::cargar() {
    Funciones f;
    cout<<"INGRESE LA CALLE: ";
    f.cargar_cadena(calle, 29);
    cout<<"INGRESE LA ALTURA: ";
    cin>>altura;
    cout<<"INGRESE LA LOCALIDAD: ";
    f.cargar_cadena(localidad, 29);
    cout<<"INGRESE EL PARTIDO: ";
    f.cargar_cadena(partido, 29);
    cout<<"INGRESE EL CODIGO POSTAL: ";
    f.cargar_cadena(codigoPostal,5);
}

void Domicilio::mostrar() {
    cout<<"DIRECCION: "<<calle<<" "<<altura<<endl;
    cout<<"LOCALIDAD: "<<localidad<<endl;
    cout<<"PARTIDO: "<<partido<<endl;
    cout<<"CODIGO POSTAL: "<<codigoPostal<<endl;
}
