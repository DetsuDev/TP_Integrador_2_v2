#include <iostream>

#include "MenuPrincipal.h"
#include "MenuSocio.h"
#include "MenuLibro.h"
#include "MenuPrestamo.h"
#include "MenuCuota.h"
#include "MenuBackup.h"
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
        cout << "[5] Gestionar Backup\n";
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
            break;
        }
        case 3: {
            MenuPrestamo menuPrest;
            menuPrest.mostrar();
            break;
        }
        case 4: {
            MenuCuota menuCuota;
            menuCuota.mostrar();
            break;
        }
        case 5: {
            MenuBackup menuBackup;
            menuBackup.mostrar();
        }
        break;
        case 0:
            activo = false;
            break;
        default:
            cout << "SELECCION INCORRECTA\n";
            system("pause");
        }
    }
}

