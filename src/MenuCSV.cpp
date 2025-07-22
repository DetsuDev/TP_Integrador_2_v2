#include "MenuCSV.h"
#include "CSV.h"
#include <iostream>
using namespace std;

void MenuCSV::mostrar() {
    CSV csv;
    int opc;
    do {
        cout << "\n--- MENU CSV ---\n";
        cout << "1) Exportar Socios\n";
        cout << "2) Exportar Libros\n";
        cout << "3) Exportar Prestamos\n";
        cout << "4) Exportar Cuotas\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> opc;
        switch (opc) {
            case 1: csv.exportarSocios(); break;
            case 2: csv.exportarLibros(); break;
            case 3: csv.exportarPrestamos(); break;
            case 4: csv.exportarCuotas(); break;
        }
    } while (opc != 0);
}
