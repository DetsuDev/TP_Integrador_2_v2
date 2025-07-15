#include <iostream>
#include <cstring>
#include "socio/arch_socio.h"
#include "socio/socio.h"
#include "Funciones.h"

using namespace std;

ArchSocio::ArchSocio(const char *n) {
    strcpy(nombre, n);
}

bool ArchSocio::grabar(Socio obj) {
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

Socio ArchSocio::leer(int pos) {
    Socio obj;

    FILE *p = fopen(nombre, "rb");
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchSocio::buscar(const char *dni) {
    Socio obj;
    int cantReg = contar();
    for(int i=0; i<cantReg; i++) {
        obj = leer(i);
        if(strcmp(obj.get_dni(), dni) == 0) {
            return i;
        }
    }
    return -1;
}

bool ArchSocio::modificar(Socio obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if(p == nullptr) {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchSocio::contar() {
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) {
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Socio);
}



/// Carga
void ArchSocio::cargar(Socio &obj) {
    Funciones f;
    char buffer[40];
    /// VERIFICAR EL ESTADO TAMBIEN

        cout<<"INGRESE EL NOMBRE: ";
        f.cargar_cadena(buffer,29);
        obj.set_nombre(buffer);
        cout<<"INGRESE EL APELLIDO: ";
        f.cargar_cadena(buffer,29);
        obj.set_apellido(buffer);
        cout<<"INGRESE LA FECHA DE NACIMIENTO: " << endl;
        Fecha fnac;
        fnac.cargar();
        obj.set_fecha_nac(fnac);
        cout<<"INGRESE EL DOMICILIO: " << endl;
        Domicilio dom;
        dom.cargar();
        obj.set_domicilio(dom);
        cout<<"INGRESE EL EMAIL: ";
        f.cargar_cadena(buffer, 39);
        obj.set_email(buffer);
}

/// Registro
void ArchSocio::registrar() {

    Funciones f;
    Socio obj;
    char dni[10];
    cout << "Ingrese el DNI: ";
    f.cargar_cadena(dni, 9);

    int pos = buscar(dni);
    if (pos != -1) {
        Socio existente = leer(pos);
        if (existente.get_estado()) {
            cout << "DNI YA EXISTENTE\n";
            system("pause");
            return;
        } else {
            obj.set_dni(dni);
            cargar(obj);
            obj.set_estado(true);
            modificar(obj, pos);
            return;
        }
    }
    obj.set_dni(dni);
    cargar(obj);
    obj.set_estado(true);
    grabar(obj);
}
