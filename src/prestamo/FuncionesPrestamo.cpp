#include "FuncionesPrestamo.h"

#include "FuncionesPrestamo.h"
#include "Prestamo.h"
#include "Libro.h"
#include "Socio.h"

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
FuncionesPrestamo::FuncionesPrestamo() {}

/// Carga
void FuncionesPrestamo::cargar( Prestamo &obj ) {
    cout << "Ingrese fecha de prestamo: ";
    Fecha fecha;
    fecha.cargar();
    obj.set_fecha_prest( fecha );
    cout << "Ingrese fecha de devolucion: ";
    fecha.cargar();
    obj.set_fecha_dev( fecha );
}

/// Registro
void FuncionesPrestamo::registrar() {
    Libro libro;
    Socio socio;
    Prestamo prest;
    char isbn[20];
    cout << "Ingrese el ISBN: ";
    f.cargar_cadena( isbn, 19 );

    int pos_libro = archLibro.buscar( isbn, "i" );
    if ( pos_libro > -1 ) {
        Libro libro = archLibro.leer ( pos_libro );
        if ( libro.get_c_ejemplares() > 0 ) {
            char dni[10];
            cout << "Ingrese el DNI: ";
            f.cargar_cadena( dni, 9 );

            int pos_socio = archSocio.buscar( dni );
            if ( pos_socio > -1 ) {
                socio = archSocio.leer( pos_socio );
                cargar( prest );
                srand( time( 0 ) );
                prest.set_id_prestamo( rand() % 100000 + 1 );
                prest.set_isbn( isbn );
                prest.set_titulo( libro.get_titulo() );
                prest.set_dni( dni );
                prest.set_estado( true );
                archPrest.grabar( prest );
                libro.set_c_ejemplares( libro.get_c_ejemplares() - 1 );
                archLibro.modificar( libro, pos_libro );
            } else {
                cout << "Socio no encontrado.\n";
            }
        } else {
            cout << "No hay ejemplares disponibles.\n";
        }
    } else {
        cout << "Libro no encontrado.\n";
    }
    system( "pause" );
}

/// Listado
void FuncionesPrestamo::listar( const char* dato, const char* tipo ) {

    Prestamo prestamo;
    int cant_reg = archPrest.contar();

    if ( cant_reg < 1 ) {
        cout << "NO HAY DATOS.\n";
    } else {
        for ( int i = 0; i < cant_reg; i++ ) {
            prestamo = archPrest.leer( i );
            if ( prestamo.get_estado() ) {
                if ( strcmp( dato, "0" ) == 0 ) {
                    prestamo.mostrar();
                } else {
                    if ( strcmp( "d", tipo ) == 0 && strcmp( prestamo.get_dni(), dato ) == 0 ) {
                        prestamo.mostrar();
                    }
                    if ( strcmp( "i", tipo ) == 0 && strcmp( prestamo.get_isbn(), dato ) == 0 ) {
                        prestamo.mostrar();
                    }
                }
            }
        }
    }
}


/// Buscar
void FuncionesPrestamo::buscar() {

    int id_prestamo = -1;
    int opc = -1;
    int pos = -1;
    char dni[10];
    char isbn[20];
    Prestamo obj;
    cout << "Buscar por: \n";
    cout << "[1] ID \n";
    cout << "[2] DNI \n";
    cout << "[3] ISBN \n";
    cout << "[0] Volver. \n";
    cout << "Ingrese opcion: ";
    cin >> opc;

    switch ( opc ) {
    case 1: {
        cout << "Ingrese ID del prestamo a buscar: ";
        cin >> id_prestamo;
        pos = archPrest.buscar_id( id_prestamo );

        if ( pos > -1 ) {
            obj = archPrest.leer( pos );
            if ( obj.get_estado() ) {
                cout << "Prestamo encontrado!: \n";
                obj.mostrar();

            } else {
                cout << "Prestamo no encontrado.\n";
            }
        } else {
            cout << "Prestamo no encontrado.\n";
        }
    break;
    }
    case 2: {
        cout << "Ingrese DNI a buscar: ";
        f.cargar_cadena( dni, 9 );
        listar( dni, "d" );
    break;
    }
    case 3: {
        cout << "Ingrese el ISBN a buscar: ";
        f.cargar_cadena( isbn, 19 );
        listar( isbn, "i" );
    break;
    }
    case 0:
        opc = -1;
        break;
    default:
        cout << "Opcion invalida.\n";
        break;
    }

}

/// Eliminar
void FuncionesPrestamo::eliminar() {
    listar( "0", "0" );
    Libro libro;
    int pos_libro = -1;
    int id_prestamo;
    cout << "Ingrese Id del prestamo a eliminar: ";
    cin >> id_prestamo;

    int pos_prest = archPrest.buscar_id( id_prestamo );
    if ( pos_prest > -1 ) {
        Prestamo prest = archPrest.leer( pos_prest );
        if ( prest.get_estado() ) {

            cout << "Eliminar este Prestamo? (s/N): ";
            char opc;
            cin >> opc;
            if ( opc == 'S' || opc == 's' ) {
                prest.set_estado( false );
                pos_libro = archLibro.buscar( prest.get_isbn(), "i" );
                libro = archLibro.leer( pos_libro );
                libro.set_c_ejemplares( libro.get_c_ejemplares() + 1 );
                archLibro.modificar( libro, pos_libro );
                archPrest.modificar( prest, pos_prest );
                cout << "Prestamo Eliminado.\n";
            } else {
                cout << "Operacion Cancelada.\n";
            }
        } else {
            cout << "Prestamo no encontrado!\n";
        }
    } else {
        cout << "Prestamo no encontrado!\n";
    }
}
