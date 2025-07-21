#include "FuncionesSocio.h"
#include "ArchSocio.h"
#include "Socio.h"
#include "Funciones.h"
#include "Prestamo.h"
#include "ArchPrestamo.h"
#include <iostream>
#include <cstring>
using namespace std;
FuncionesSocio::FuncionesSocio() {}

/// Carga
void FuncionesSocio::cargar( Socio &obj )
{
    Funciones f;
    char buffer[40];
    cout << "Ingrese el nombre: ";
    f.cargar_cadena( buffer, 29 );
    obj.set_nombre( buffer );
    cout << "Ingrese el apellido: ";
    f.cargar_cadena( buffer, 29 );
    obj.set_apellido( buffer );
    cout << "Ingrese la fecha de nacimiento: " << endl;
    Fecha fNac;
    fNac.cargar();
    obj.set_fecha_nac( fNac );
    cout << "Ingrese el email: ";
    f.cargar_cadena( buffer, 39 );
    obj.set_email( buffer );
    cout << "Ingrese el domicilio: " << endl;
    Domicilio dom;
    dom.cargar();
    obj.set_domicilio( dom );
}

/// Registro
void FuncionesSocio::registrar()
{

    Funciones f;
    Socio obj;
    ArchSocio reg;
    char dni[10];
    cout << "Ingrese el DNI: ";
    f.cargar_cadena( dni, 9 );

    int pos = reg.buscar( dni );
    if ( pos != -1 )
    {
        Socio existente = reg.leer( pos );
        if ( existente.get_estado() )
        {
            cout << "DNI YA EXISTENTE\n";
            system( "pause" );
            return;
        }
        else
        {
            obj.set_dni( dni );
            cargar( obj );
            obj.set_estado( true );
            reg.modificar( obj, pos );
            return;
        }
    }
    cargar( obj );
    obj.set_dni( dni );
    obj.set_estado( true );
    reg.grabar( obj );
}

/// Listado
void FuncionesSocio::listar()
{
    Socio obj;
    ArchSocio reg;
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
void FuncionesSocio::buscar()
{
    Funciones f;
    ArchSocio reg;

    char dni[10];
    cout << "Ingrese DNI a buscar: ";
    f.cargar_cadena( dni, 9 );

    int pos = reg.buscar( dni );
    if ( pos < 0 )
    {
        cout << "DNI no encontrado.\n";
    }
    else
    {
        cout << "DNI encontrado!: \n";
        Socio obj = reg.leer( pos );
        obj.mostrar();
    }
}

/// Eliminar
void FuncionesSocio::eliminar()
{
    Funciones f;
    ArchSocio reg;
    listar();
    char dni[10];
    cout << "Ingrese DNI a eliminar: ";
    f.cargar_cadena( dni, 9 );

    int pos = reg.buscar( dni );
    if ( pos != -1 )
    {
        Socio obj = reg.leer( pos );
        if ( obj.get_estado() )
        {
            Prestamo prest;
            ArchPrestamo archPrest;
            bool existe_registro = false;
            int cant_reg = archPrest.contar();
            int pos_socio;

            for(int i = 0; i < cant_reg; i++){
                    prest = archPrest.leer(i);
                if(strcmp(dni,prest.get_dni()) == 0){
                    pos_socio = i;
                    existe_registro = true;
                }
            }
            cout << obj.get_apellido() << ", " << obj.get_nombre() << endl;
            if(existe_registro){
                cout << "ATENCION: hay cuotas/prestamos asociados a este socio." << endl;
            }
            cout << "Eliminar este socio? (s/N): ";
            char opc;
            cin >> opc;
            if ( opc == 'S' || opc == 's' )
            {
                obj.set_estado( false );
                if(existe_registro){
                    for(int i = 0; i < cant_reg; i++){
                            prest = archPrest.leer(i);
                        if(strcmp(dni,prest.get_dni()) == 0){
                                prest.set_estado(false);
                                archPrest.modificar(prest,i);
                        }
                    }
                }
                reg.modificar( obj, pos );
                cout << "Socio Eliminado.\n";
            }
        }
    }
    else
    {
        cout << "Dni no encontrado!\n";
    }
}
