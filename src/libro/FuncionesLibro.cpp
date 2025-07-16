#include "FuncionesLibro.h"
#include "ArchLibro.h"
#include "Libro.h"
#include "Funciones.h"
#include <iostream>
#include <cstring>
using namespace std;
FuncionesLibro::FuncionesLibro() {}

/// Carga
void FuncionesLibro::cargar( Libro &obj ) {
    Funciones f;
    char buffer[50];
    cout << "Ingrese el titulo: ";
    f.cargar_cadena( buffer, 39 );
    obj.set_titulo( buffer );
    cout << "Ingrese el autor: ";
    f.cargar_cadena( buffer, 39 );
    obj.set_autor( buffer );
    cout << "Ingrese la fecha de publicacion: ";
    int anio_publi = 0;
    cin >> anio_publi;
    obj.set_anio_publi( anio_publi );
    cout << "Ingrese la cantidad de ejemplares: ";
    int c_ejemplares = 0;
    cin >> c_ejemplares;
    obj.set_c_ejemplares( c_ejemplares );
}

/// Registro
void FuncionesLibro::registrar() {

    Funciones f;
    Libro obj;
    ArchLibro reg;
    char isbn[20];
    cout << "Ingrese el ISBN: ";
    f.cargar_cadena( isbn, 19 );

    int pos = reg.buscar( isbn );
    if ( pos != -1 ) {
        Libro existente = reg.leer( pos );
        if ( existente.get_estado() ) {
            cout << "ISBN YA EXISTENTE\n";
            system( "pause" );
            return;
        } else {
            obj.set_isbn( isbn );
            cargar( obj );
            obj.set_estado( true );
            reg.modificar( obj, pos );
            return;
        }
    }
    cargar( obj );
    obj.set_isbn( isbn );
    obj.set_estado( true );
    reg.grabar( obj );
}

/// Listado
void FuncionesLibro::listar() {
    Libro obj;
    ArchLibro reg;
    int cant_reg = reg.contar();

    for ( int i = 0; i < cant_reg; i++ ) {
        obj = reg.leer( i );
        if ( obj.get_estado() ) {
            obj.mostrar();
        }
    }

}

/// Buscar
void FuncionesLibro::buscar() {
    Funciones f;
    ArchLibro reg;

    char isbn[20];
    cout << "Ingrese DNI a buscar: ";
    f.cargar_cadena( isbn, 19 );

    int pos = reg.buscar( isbn );
    if ( pos < 0 ) {
        cout << "DNI no encontrado.\n";
    } else {
        cout << "DNI encontrado!: \n";
        Libro obj = reg.leer( pos );
        obj.mostrar();
    }
}

/// Eliminar
void FuncionesLibro::eliminar() {
    Funciones f;
    ArchLibro reg;
    char isbn[20];
    cout << "Ingrese DNI a eliminar: ";
    f.cargar_cadena( isbn, 19 );

    int pos = reg.buscar( isbn );
    if ( pos != -1 ) {
        Libro obj = reg.leer( pos );
        if ( obj.get_estado() ) {
            cout << "Eliminar este Libro? (s/N): ";
            char opc;
            cin >> opc;
            if ( opc == 'S' || opc == 's' ) {
                obj.set_estado( false );
                reg.modificar( obj, pos );
                cout << "Libro Eliminado.\n";
            }
        }
    } else {
        cout << "ISBN no encontrado!\n";
    }
}
