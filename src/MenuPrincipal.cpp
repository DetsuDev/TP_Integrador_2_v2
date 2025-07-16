#include <iostream>

#include "MenuPrincipal.h"
#include "MenuSocio.h"
#include "MenuLibro.h"
using namespace std;

MenuPrincipal::MenuPrincipal() {}

void MenuPrincipal::mostrar() {
    int opc;
    bool activo = true;
    while ( activo ) {
        system( "cls" );
        cout << "SISTEMA DE GESTION DE BIBLIOTECA\n";
        cout << "--------------------------------\n";
        cout << "[1] Gestionar Socios\n";
        cout << "[2] Gestionar Libros\n";
        cout << "[3] Gestionar Prestamos\n";
        cout << "[4] Gestionar Cuotas\n";
        cout << "[0] Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opc;
        switch ( opc ) {
        case 1: {
            MenuSocio menuSocio;
            menuSocio.mostrar();
            break;
        }
        case 2: {
            MenuLibro menuLibro;
            menuLibro.mostrar();
        }
        break;
        case 0:
            activo = false;
            break;
        default:
            cout << "SELECCION INCORRECTA\n";
        }
    }
}

