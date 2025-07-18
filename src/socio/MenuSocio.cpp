#include "FuncionesSocio.h"
#include "MenuSocio.h"
#include <iostream>

using namespace std;

MenuSocio::MenuSocio() {}

void MenuSocio::mostrar() {
    int opc;
    while ( true ) {
        system( "cls" );
        cout << "SISTEMA DE GESTION DE BIBLIOTECA > GESTION SOCIOS \n";
        cout << "--------------------------------------------------\n";
        cout << "[1] Registrar Socios\n";
        cout << "[2] Listar Socios\n";
        cout << "[3] Buscar Socio\n";
        cout << "[4] Eliminar Socio\n";
        cout << "[0] Volver\n";
        cout << "Ingrese opcion: ";
        cin >> opc;
        FuncionesSocio funcSoc;

        switch ( opc ) {
        case 1:
            system( "cls" );
            funcSoc.registrar();
            break;
        case 2:
            system( "cls" );
            funcSoc.listar();
            system( "pause" );
            break;
        case 3:
            system( "cls" );
            funcSoc.buscar();
            system( "pause" );
            break;
        case 4:
            system( "cls" );
            funcSoc.eliminar();
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
