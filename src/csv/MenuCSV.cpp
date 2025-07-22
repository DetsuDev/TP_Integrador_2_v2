#include "MenuCSV.h"
#include "CSV.h"
#include <iostream>
using namespace std;

void MenuCSV::mostrar() {
    CSV csv;
    int opc;
    while ( true ) {
        system( "cls" );
        cout << "SISTEMA DE GESTION DE BIBLIOTECA > GESTION CSV \n";
        cout << "[1] Exportar Socios\n";
        cout << "[2] Exportar Libros\n";
        cout << "[3] Exportar Prestamos\n";
        cout << "[4] Exportar Cuotas\n";
        cout << "[0] Volver\n";
        cout << "Opcion: ";
        cin >> opc;
        switch ( opc ) {
        case 1:
            csv.exp_socios();
            system("pause");
            break;
        case 2:
            csv.exp_libros();
            system("pause");
            break;
        case 3:
            csv.exp_prestamos();
            system("pause");
            break;
        case 4:
            csv.exp_cuotas();
            system("pause");
            break;
        case 0:
            return;
            break;
        }

    }
}
