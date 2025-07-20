#include "FuncionesCuota.h"
#include "MenuCuota.h"
#include <iostream>

using namespace std;

MenuCuota::MenuCuota() {}

void MenuCuota::mostrar() {
    int opc;
    while ( true ) {
        system( "cls" );
        cout << "SISTEMA DE GESTION DE BIBLIOTECA > GESTION CUOTAS \n";
        cout << "--------------------------------------------------\n";
        cout << "[1] Registrar Cuotas\n";
        cout << "[2] Listar Cuotas\n";
        cout << "[3] Buscar Cuota\n";
        cout << "[4] Eliminar Cuota\n";
        cout << "[0] Volver\n";
        cout << "Ingrese opcion: ";
        cin >> opc;
        FuncionesCuota funcCuot;

        switch ( opc ) {
        case 1:
            system( "cls" );
            funcCuot.registrar();
            break;
        case 2:
            system( "cls" );
            funcCuot.listar();
            system( "pause" );
            break;
        case 3:
            system( "cls" );
            funcCuot.buscar();
            system( "pause" );
            break;
        case 4:
            system( "cls" );
            funcCuot.eliminar();
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
