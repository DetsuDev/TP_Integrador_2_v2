#include <iostream>

#include "arch_socio.h"
#include "socio.h"
#include "menu.h"


/// Objeto Socio: DNI, Nombre, Direccion, Email, Fecha de Nacimiento
/// Objeto Libro: ISBN, Nombre del libro, Nombre del autor, Fecha de publicacion, cantidad de ejemplares
/// Objeto Prestamos: Libro prestado, Socio al que se le presto, fecha del prestamo, fecha de devolucion
/// Objeto Cuota: Numero de Socio, Fecha de pago, Importe, Mes, Año, Importe

/// COSAS A HACER

/// LIBROS
/// NO PERMITIR ELIMINAR UN LIBRO SI TIENE UN PRESTAMO ACTIVO
/// SOCIOS
/// CALCULAR CUANTAS CUOTAS DEBE Y EL IMPORTE
/// AGREGAR DEDUDA SI SE VUELVE A CARGAR EL MISMO DNI
/// SOLICITUD POR NOMBRE Y CUOTAS

using namespace std;

Menu::Menu() {
    int opc;
    bool Menu = true;
    while(Menu) {
        system("cls");
        cout << "SISTEMA DE GESTION DE BIBLIOTECA\n";
        cout << "--------------------------------\n";
        cout << "1. Gestionar Socios\n";
        cout << "2. Gestionar Libros\n";
        cout << "3. Gestionar Prestamos\n";
        cout << "4. Gestionar Cuotas\n";
        cout << "0. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opc;
        switch(opc) {
        case 1:
            menu_socios();
            break;
        case 2:
            menu_libros();
            break;
        case 0:
            Menu = false;
            break;
        default:
            cout << "SELECCION INCORRECTA\n";
        }
    }
}


void Menu::menu_socios() {

        int opc;
        while(true) {
        system("cls");
        cout << "SISTEMA DE GESTION DE BIBLIOTECA > GESTION SOCIOS \n";
        cout << "--------------------------------------------------\n";
        cout << "1. Registrar Socios\n";
        cout << "2. Listar Socios\n";
        cout << "3. Buscar Socio\n";
        cout << "4. Eliminar Socio\n";
        cout << "0. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opc;
        ArchSocio reg;
        Socio obj;

        switch(opc) {
        case 1:
            reg.registrar();
            break;
        case 2:
            obj.mostrar();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout << "SELECCION INCORRECTA\n";
        }
    }
}

void Menu::menu_libros() {


}

