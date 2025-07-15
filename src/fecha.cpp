#include <iostream>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::set_dia(int d) { dia = d; }
void Fecha::set_mes(int m) { mes = m; }
void Fecha::set_anio(int a) { anio = a; }
int Fecha::get_dia() { return dia; }
int Fecha::get_mes() { return mes; }
int Fecha::get_anio() { return anio; }

void Fecha::cargar() {
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
}
void Fecha::mostrar() { cout<<dia<<"/"<<mes<<"/"<<anio<<endl; }
