#include "FuncionesSocio.h"
#include "Socio.h"
#include "Cuota.h"
#include "Prestamo.h"
#include <iostream>
#include <cstring>
using namespace std;
FuncionesSocio::FuncionesSocio() {}

/// Carga
void FuncionesSocio::cargar( Socio &socio ) {
    char buffer[40];
    cout << "Ingrese el nombre: ";
    f.cargar_cadena( buffer, 29 );
    socio.set_nombre( buffer );
    cout << "Ingrese el apellido: ";
    f.cargar_cadena( buffer, 29 );
    socio.set_apellido( buffer );
    cout << "Ingrese la fecha de nacimiento: " << endl;
    Fecha fNac;
    fNac.cargar();
    socio.set_fecha_nac( fNac );
    cout << "Ingrese el email: ";
    f.cargar_cadena( buffer, 39 );
    socio.set_email( buffer );
    cout << "Ingrese el domicilio: " << endl;
    Domicilio dom;
    dom.cargar();
    socio.set_domicilio( dom );
}

/// Registro
void FuncionesSocio::registrar() {
    Socio socio;
    char dni[10];
    cout << "Ingrese el DNI: ";
    f.cargar_cadena( dni, 9 );

    int pos = archSocio.buscar( dni );
    if ( pos > -1 ) {
        socio = archSocio.leer( pos );
        if ( socio.get_estado() ) {
            cout << "DNI YA EXISTENTE\n";
            system( "pause" );
            return;
        } else {
            socio.set_dni( dni );
            cargar( socio );
            socio.set_estado( true );
            archSocio.modificar( socio, pos );
            return;
        }
    }
    cargar( socio );
    socio.set_dni( dni );
    socio.set_estado( true );
    archSocio.grabar( socio );
}

/// Listado
void FuncionesSocio::listar() {
    Socio socio;
    int cant_reg = archSocio.contar();

    if ( cant_reg < 1 ) {
        cout << "NO HAY DATOS.\n";
    } else {
        for ( int i = 0; i < cant_reg; i++ ) {
            socio = archSocio.leer( i );
            if ( socio.get_estado() ) {
                socio.mostrar();
            }
        }
    }
}

/// Buscar
void FuncionesSocio::buscar() {
    char dni[10];
    cout << "Ingrese DNI a buscar: ";
    f.cargar_cadena( dni, 9 );

    int pos = archSocio.buscar( dni );
    if ( pos > -1 ) {
        Socio socio = archSocio.leer( pos );
        if ( socio.get_estado() ) {
            socio.mostrar();
            cout << "DNI encontrado!: \n";
        } else {
            cout << "DNI no encontrado.\n";
        }
    } else {
        cout << "DNI no encontrado.\n";
    }
}

/// Eliminar
void FuncionesSocio::eliminar() {
    Socio socio;
    listar();
    char dni[10];
    cout << "Ingrese DNI a eliminar: ";
    f.cargar_cadena( dni, 9 );

    int pos_socio = archSocio.buscar( dni );
    if ( pos_socio > -1 ) {
        Socio socio = archSocio.leer( pos_socio );
        if ( socio.get_estado() ) {
            int pos_prest =  archPrest.buscar( dni, "d" );
            Prestamo prest = archPrest.leer(pos_prest);
            int pos_cuota =  archCuota.buscar( dni, 0, 0, "d" );
            Cuota cuota  = archCuota.leer(pos_cuota);
            if ( pos_prest > -1 && pos_cuota > -1 && cuota.get_estado() && prest.get_estado()) {

                cout << socio.get_apellido() << ", " << socio.get_nombre() << endl;
                cout << "ATENCION: hay cuotas/prestamos asociados a este socio, si lo elimina, sus prestamos y cuotas se eliminaran." << endl;
            }
            cout << "Eliminar este socio? (s/N): ";
            char opc;
            cin >> opc;
            if ( opc == 'S' || opc == 's' ) {
                socio.set_estado( false );
                archSocio.modificar( socio, pos_socio );

                archPrest.limpiar( dni );
                archCuota.limpiar( dni );

                cout << "El Socio fue eliminado.\n";
            } else {
                cout << "Operacion cancelada.\n";
            }
        }
    } else {
        cout << "Dni no encontrado!\n";
    }
}
