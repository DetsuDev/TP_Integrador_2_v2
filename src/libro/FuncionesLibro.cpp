#include "FuncionesLibro.h"
#include "Libro.h"
#include "Prestamo.h"
#include <iostream>
#include <cstring>
using namespace std;
FuncionesLibro::FuncionesLibro() {}

/// Carga
void FuncionesLibro::cargar( Libro &libro ) {
    Funciones f;
    char buffer[50];
    cout << "Ingrese el titulo: ";
    f.cargar_cadena( buffer, 39 );
    libro.set_titulo( buffer );
    cout << "Ingrese el autor: ";
    f.cargar_cadena( buffer, 39 );
    libro.set_autor( buffer );
    cout << "Ingrese la fecha de publicacion: ";
    int anio_publi = 0;
    cin >> anio_publi;
    libro.set_anio_publi( anio_publi );
    cout << "Ingrese la cantidad de ejemplares: ";
    int c_ejemplares = 0;
    cin >> c_ejemplares;
    libro.set_c_ejemplares( c_ejemplares );
}

/// Registro
void FuncionesLibro::registrar() {
    Libro libro;
    char isbn[20];
    cout << "Ingrese el ISBN: ";
    f.cargar_cadena( isbn, 19 );

    int pos = archLibro.buscar( isbn );
    if ( pos > -2 ) {
        if (pos > -1)
        {
            cout << "ISBN YA EXISTENTE\n";
            system( "pause" );
            return;
        } else {
            libro.set_isbn( isbn );
            cargar( libro );
            libro.set_estado( true );
            archLibro.modificar( libro, pos );
            return;
        }
    }
    cargar( libro );
    libro.set_isbn( isbn );
    libro.set_estado( true );

    archLibro.grabar( libro );
}

/// Listado
void FuncionesLibro::listar() {
    Libro libro;
    int cant_reg = archLibro.contar();

    if ( cant_reg < 1 ) {
        cout << "NO HAY DATOS.\n";
    } else {
        for ( int i = 0; i < cant_reg; i++ ) {
            libro = archLibro.leer( i );
            if ( libro.get_estado() ) {
                libro.mostrar();
            }
        }

    }

}

/// Buscar
void FuncionesLibro::buscar() {
    char isbn[20];
    cout << "Ingrese ISBN a buscar: ";
    f.cargar_cadena( isbn, 19 );

    int pos = archLibro.buscar( isbn );
    if ( pos > -1 ) {
        cout << "ISBN encontrado!: \n";
        Libro libro = archLibro.leer( pos );
        libro.mostrar();
    } else {
        cout << "ISBN no encontrado.\n";
    }
}

/// Eliminar
void FuncionesLibro::eliminar() {
    char isbn[20];
    listar();
    cout << "Ingrese ISBN a eliminar: ";
    f.cargar_cadena( isbn, 19 );

    int pos_libro = archLibro.buscar( isbn );
    if (pos_libro > -2) {
        Libro libro = archLibro.leer(pos_libro);
        int pos_prest = archPrest.buscar_isbn(isbn);
        if (pos_prest > -1)
        {
            cout << "Este libro no puede ser eliminado porque tiene un prestamo activo: \n";
        } else {

        cout << "Eliminar este Libro? (s/N): ";
        char opc;
        cin >> opc;

            if ( opc == 'S' || opc == 's' ) {
                libro.set_estado( false );
                archLibro.modificar( libro, pos_libro );
                cout << "Libro Eliminado.\n";
            } else
            {
                cout << "Operacion cancelada.\n";
            }
        }
    } else {

    cout << "libro no encontrado.\n";
    }
}
