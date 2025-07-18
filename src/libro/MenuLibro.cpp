#include "FuncionesLibro.h"
#include "MenuLibro.h"
#include <iostream>

using namespace std;

MenuLibro::MenuLibro() {}

void MenuLibro::mostrar() {
    int opc;
    while ( true ) {
        system( "cls" );
        cout << "SISTEMA DE GESTION DE BIBLIOTECA > GESTION LIBROS \n";
        cout << "--------------------------------------------------\n";
        cout << "[1] Registrar Libro\n";
        cout << "[2] Listar Libro\n";
        cout << "[3] Buscar Libro\n";
        cout << "[4] Eliminar Libro\n";
        cout << "[0] Volver\n";
        cout << "Ingrese opcion: ";
        cin >> opc;
        FuncionesLibro funcLibro;

        switch ( opc ) {
        case 1:
            system( "cls" );
            funcLibro.registrar();
            break;
        case 2:
            system( "cls" );
            funcLibro.listar();
            system( "pause" );
            break;
        case 3:
            system( "cls" );
            funcLibro.buscar();
            system( "pause" );
            break;
        case 4:
            system( "cls" );
            funcLibro.eliminar();
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
