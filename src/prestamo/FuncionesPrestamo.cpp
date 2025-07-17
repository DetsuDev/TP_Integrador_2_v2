#include "FuncionesPrestamo.h"

#include "Funciones.h"
#include "FuncionesPrestamo.h"

#include "Prestamo.h"
#include "ArchPrestamo.h"

#include "Libro.h"
#include "ArchLibro.h"

#include "Socio.h"
#include "ArchSocio.h"

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
FuncionesPrestamo::FuncionesPrestamo() {}

/// Carga
void FuncionesPrestamo::cargar( Prestamo &obj ) {
    Funciones f;
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

    Funciones f;

    Libro libro;
    ArchLibro reg_libro;

    Socio socio;
    ArchSocio reg_socio;

    Prestamo prest;
    ArchPrestamo reg_prest;

    char isbn[20];
    cout << "Ingrese el ISBN: ";
    f.cargar_cadena( isbn, 19 );
    int pos_libro = reg_libro.buscar( isbn );
    if ( pos_libro != -1 ) {
        Libro existente_libro = reg_libro.leer( pos_libro );
        if ( existente_libro.get_estado() ) {
            char dni[10];
            cout << "Ingrese el DNI: ";
            f.cargar_cadena( dni, 9 );
            int pos_socio = reg_socio.buscar( dni );
            if ( pos_socio != -1 ) {
                Socio existente_socio = reg_socio.leer ( pos_socio );
                if ( existente_socio.get_estado() ) {
                    cargar( prest );
                    srand( time( 0 ) );
                    prest.set_id_prestamo( rand() % 100000 + 1 );
                    libro.set_c_ejemplares( libro.get_c_ejemplares() - 1 );
                    prest.set_isbn( isbn );
                    prest.set_titulo( libro.get_titulo() );
                    prest.set_dni( dni );
                    prest.set_estado( true );
                    reg_prest.grabar( prest );
                }
            } else {
                cout << "Socio Inexistente\n";
                system( "pause" );
            }
        }
    } else {
        cout << "Libro Inexistente\n";
        system( "pause" );
    }
}

/// Listado
void FuncionesPrestamo::listar() {
    Prestamo obj;
    ArchPrestamo reg;
    int cant_reg = reg.contar();

    for ( int i = 0; i < cant_reg; i++ ) {
        obj = reg.leer( i );
        if ( obj.get_estado() ) {
            obj.mostrar();
        }
    }

}

/// Buscar
void FuncionesPrestamo::buscar() {
    Funciones f;
    ArchPrestamo reg;

    int id_prestamo;
    cout << "Ingrese ID del prestamo a buscar: ";
    cin >> id_prestamo;
    int pos = reg.buscar( id_prestamo );
    if ( pos < 0 ) {
        cout << "Prestamo no encontrado.\n";
    } else {
        cout << "Prestamo encontrado!: \n";
        Prestamo obj = reg.leer( pos );
        obj.mostrar();
    }
}

/// Eliminar
void FuncionesPrestamo::eliminar() {
    Funciones f;
    ArchPrestamo reg;
    int id_prestamo;
    cout << "Ingrese Id del prestamo a eliminar: ";
    cin >> id_prestamo;

    int pos = reg.buscar( id_prestamo );
    if ( pos != -1 ) {
        Prestamo obj = reg.leer( pos );
        if ( obj.get_estado() ) {
            cout << "Eliminar este Prestamo? (s/N): ";
            char opc;
            cin >> opc;
            if ( opc == 'S' || opc == 's' ) {
                obj.set_estado( false );
                reg.modificar( obj, pos );
                cout << "Prestamo Eliminado.\n";
            }
        }
    } else {
        cout << "Prestamo no encontrado!\n";
    }
}

