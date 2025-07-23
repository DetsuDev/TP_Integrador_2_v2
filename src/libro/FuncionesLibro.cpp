#include "FuncionesLibro.h"
#include "Libro.h"
#include "Prestamo.h"
#include <iostream>
#include <cstring>
using namespace std;
FuncionesLibro::FuncionesLibro() {}

/// Carga
void FuncionesLibro::cargar( Libro &libro )
{
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
void FuncionesLibro::registrar()
{
    Libro libro;
    char isbn[20];
    cout << "Ingrese el ISBN: ";
    f.cargar_cadena( isbn, 19 );

    int pos = archLibro.buscar( isbn, "i");
    if ( pos > -1 )
    {

        libro = archLibro.leer(pos);
        if (libro.get_estado())
        {
            cout << "ISBN YA EXISTENTE\n";
            system( "pause" );
            return;
        }
        else
        {
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
void FuncionesLibro::listar()
{
    Libro libro;
    int cant_reg = archLibro.contar();

    if ( cant_reg < 1 )
    {
        cout << "NO HAY DATOS.\n";
    }
    else
    {
        for ( int i = 0; i < cant_reg; i++ )
        {
            libro = archLibro.leer( i );
            if ( libro.get_estado() )
            {
                libro.mostrar();
            }
        }

    }

}

/// Buscar
void FuncionesLibro::buscar()
{
    int opc = -1;
    int pos = -1;
    char isbn[20];
    char titulo[50];
    cout << "Buscar por: \n";
    cout << "[1] ISBN \n";
    cout << "[2] Titulo \n";
    cout << "[0] Volver. \n";
    cout << "Ingrese opcion: ";
    cin >> opc;
    if ( opc == 1 )
    {

        cout << "Ingrese ISBN a buscar: ";
        f.cargar_cadena( isbn, 19 );

        pos = archLibro.buscar( isbn, "i");
    }
    else if ( opc == 2 )
    {

        cout << "Ingrese el Titulo a buscar: ";
        f.cargar_cadena( titulo, 49 );
        pos = archLibro.buscar( titulo, "t");
    }
    else
    {

        cout << "Opcion invalida.\n";
    }

    if ( pos > -1 )
    {
        Libro libro = archLibro.leer( pos );
        if (libro.get_estado())
        {
            cout << "Libro encontrado!: \n";
            libro.mostrar();

        }
        else
        {

            cout << "Libro no encontrado.\n";
        }
    }
    else
    {
        cout << "Libro no encontrado.\n";
    }
}

/// Eliminar
void FuncionesLibro::eliminar()
{
    Prestamo prest;
    char isbn[20];
    listar();
    cout << "Ingrese ISBN a eliminar: ";
    f.cargar_cadena( isbn, 19 );

    int pos_libro = archLibro.buscar( isbn, "i");
    if ( pos_libro > -1 )
    {
        Libro libro = archLibro.leer( pos_libro );

        if (libro.get_estado())
        {
            int pos_prest = archPrest.buscar( isbn, "i");
            prest = archPrest.leer(pos_prest);
            if (prest.get_estado())
            {

                cout << "Este libro no puede ser eliminado porque tiene un prestamo activo.\n";
            }
            else
            {
                cout << "Eliminar este Libro? (s/N): ";
                char opc;
                cin >> opc;

                if ( opc == 'S' || opc == 's' )
                {
                    libro.set_estado( false );
                    archLibro.modificar( libro, pos_libro );
                    cout << "Libro Eliminado.\n";
                }
                else
                {
                    cout << "Operacion cancelada.\n";
                }
            }
        }
        else
        {
            cout << "libro no encontrado.\n";
        }

    }
    else
    {
        cout << "libro no encontrado.\n";
    }

}
