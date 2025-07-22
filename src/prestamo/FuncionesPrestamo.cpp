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
void FuncionesPrestamo::cargar( Prestamo &obj )
{
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
void FuncionesPrestamo::registrar()
{

    Funciones f;

    Libro libro;
    ArchLibro regLibro;

    Socio socio;
    ArchSocio regSocio;

    Prestamo prest;
    ArchPrestamo regPrest;

    char isbn[20];
    cout << "Ingrese el ISBN: ";
    f.cargar_cadena( isbn, 19 );

    int pos_libro = regLibro.buscar( isbn ); /// Busca el libro en el registro
    if ( pos_libro != -1 )   /// Verifica que exista
    {
        Libro existente_libro = regLibro.leer( pos_libro ); /// Guarda para su lectura de estado
        if ( existente_libro.get_estado() )   /// Si existe y esta activo, continua
        {
            char dni[10];
            cout << "Ingrese el DNI: ";
            f.cargar_cadena( dni, 9 );
            int pos_socio = regSocio.buscar( dni ); /// Busca el socio en el registro
            if ( pos_socio != -1 )   /// Verifica que exista
            {
                Socio existente_socio = regSocio.leer ( pos_socio ); /// Guarda para su lectura de estado
                if ( existente_socio.get_estado() )   // Si existe y esta activo, continua
                {
                    cargar( prest );
                    srand( time( 0 ) );
                    prest.set_id_prestamo( rand() % 100000 + 1 );
                    existente_libro.set_c_ejemplares( existente_libro.get_c_ejemplares() - 1 );
                    prest.set_isbn( isbn );
                    prest.set_titulo( existente_libro.get_titulo() );
                    prest.set_dni( dni );
                    prest.set_estado( true );
                    regPrest.grabar( prest );
                }
                else
                {
                    cout << "Socio Inactivo\n";
                    system( "pause" );
                }
            }
            else
            {
                cout << "Socio Inexistente\n";
                system( "pause" );
            }
        }
        else
        {
            cout << "Libro Inactivo\n";
            system( "pause" );

        }
    }
    else
    {
        cout << "Libro Inexistente\n";
        system( "pause" );
    }
}

/// Listado
void FuncionesPrestamo::listar()
{
    Prestamo obj;
    ArchPrestamo reg;
    int cant_reg = reg.contar();

    if ( cant_reg < 1 )
    {
        cout << "NO HAY DATOS.\n";
    }
    else
    {
        for ( int i = 0; i < cant_reg; i++ )
        {
            obj = reg.leer( i );
            if ( obj.get_estado() )
            {
                obj.mostrar();
            }
        }

    }

}

/// Buscar
void FuncionesPrestamo::buscar()
{
    Funciones f;
    ArchPrestamo reg;

    int id_prestamo;
    cout << "Ingrese ID del prestamo a buscar: ";
    cin >> id_prestamo;
    int pos = reg.buscar( id_prestamo );
    if ( pos < 0 )
    {
        cout << "Prestamo no encontrado.\n";
    }
    else
    {
        cout << "Prestamo encontrado!: \n";
        Prestamo obj = reg.leer( pos );
        obj.mostrar();
    }
}

/// Eliminar
void FuncionesPrestamo::eliminar()
{
    Funciones f;
    ArchPrestamo reg;
    listar();
    int id_prestamo;
    cout << "Ingrese Id del prestamo a eliminar: ";
    cin >> id_prestamo;

    int pos = reg.buscar( id_prestamo );
    if ( pos != -1 )
    {
        Prestamo obj = reg.leer( pos );
        if ( obj.get_estado() )
        {
            cout << "Eliminar este Prestamo? (s/N): ";
            char opc;
            cin >> opc;
            if ( opc == 'S' || opc == 's' )
            {
                obj.set_estado( false );
                reg.modificar( obj, pos );
                cout << "Prestamo Eliminado.\n";
            }
        }
    }
    else
    {
        cout << "Prestamo no encontrado!\n";
    }
}
