#include "FuncionesPrestamo.h"
#include "MenuPrestamo.h"
#include <iostream>

using namespace std;

MenuPrestamo::MenuPrestamo() {}

void MenuPrestamo::mostrar() {
    int opc;
    while ( true ) {
        system( "cls" );
        cout << "SISTEMA DE GESTION DE BIBLIOTECA > GESTION PRESTAMOS \n";
        cout << "--------------------------------------------------\n";
        cout << "[1] Registrar Prestamos\n";
        cout << "[2] Listar Prestamos\n";
        cout << "[3] Buscar Prestamo\n";
        cout << "[4] Eliminar Prestamo\n";
        cout << "[0] Volver\n";
        cout << "Ingrese opcion: ";
        cin >> opc;
        FuncionesPrestamo funcPrest;

        switch ( opc ) {
        case 1:
            system( "cls" );
            funcPrest.registrar();
            break;
        case 2:
            system( "cls" );
            funcPrest.listar();
            system( "pause" );
            break;
        case 3:
            system( "cls" );
            funcPrest.buscar();
            system( "pause" );
            break;
        case 4:
            system( "cls" );
            funcPrest.eliminar();
            system( "pause" );
            break;
        case 0:
            return;
            break;
        default:
            cout << "SELECCION INCORRECTA\n";
            system("pause");
        }
    }
}
