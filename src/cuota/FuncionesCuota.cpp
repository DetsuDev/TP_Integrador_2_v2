#include "FuncionesCuota.h"
#include "ArchCuota.h"
#include "Cuota.h"
#include "Socio.h"
#include "ArchSocio.h"
#include "Funciones.h"
#include <iostream>
#include <cstring>
using namespace std;
FuncionesCuota::FuncionesCuota() {}

/// Carga
void FuncionesCuota::cargar( Cuota &obj ) {
    Funciones f;
    float importe;
    cout << "Ingrese el importe: ";
    cin >> importe;
    obj.set_importe( importe );

    cout << "Ingrese la fecha de pago: " << endl;
    Fecha fPago;
    fPago.cargar();
    obj.set_fecha_pago( fPago );
}

/// Registro
void FuncionesCuota::registrar() {

    Funciones f;

    Cuota cuota;
    ArchCuota regCuot;

    Socio socio;
    ArchSocio regSoc;

    char dni[10];
    cout << "Ingrese el DNI: ";
    f.cargar_cadena( dni, 9 );

    int pos_soc = regSoc.buscar( dni );
    if ( pos_soc == -1 ) {
        cout << "DNI NO EXISTENTE\n";
        system( "pause" );
        return;
    }

    Socio existenteSoc = regSoc.leer( pos_soc );
    if ( !existenteSoc.get_estado() ) {
        cout << "Socio inactivo.\n";
        system( "pause" );
        return;
    }

    int mes;
    cout << "Ingrese el mes: ";
    cin >> mes;

    int anio;
    cout << "Ingrese el anio: ";
    cin >> anio;
    int pos_cuot = regCuot.buscar( dni, mes, anio );

    if ( pos_cuot != -1 ) {
        Cuota existenteCuot = regCuot.leer( pos_cuot );
        cout << "\nDEBUG:\n";
        cout << "Cuota encontrada en posici�n: " << pos_cuot << endl;
        cout << "DNI: " << existenteCuot.get_dni() << endl;
        cout << "Mes: " << existenteCuot.get_mes() << endl;
        cout << "Anio: " << existenteCuot.get_anio() << endl;
        cout << "Estado: " << existenteCuot.get_estado() << endl;
        if ( existenteCuot.get_estado() ) {
            cout << "Cuota ya pagada.\n";
            system( "pause" );
            return;
        }

        cargar( cuota );
        cuota.set_dni( dni );
        cuota.set_mes( mes );
        cuota.set_anio( anio );
        cuota.set_estado( true );
        regCuot.modificar( cuota, pos_cuot );
        return;
    }
    cargar( cuota );
    cuota.set_dni( dni );
    cuota.set_mes( mes );
    cuota.set_anio( anio );
    cuota.set_estado( true );
    regCuot.grabar( cuota );

}


/// Listado
void FuncionesCuota::listar() {
    Cuota obj;
    ArchCuota reg;
    int cant_reg = reg.contar();

    if ( cant_reg < 1 ) {
        cout << "NO HAY DATOS.\n";
    } else {
        for ( int i = 0; i < cant_reg; i++ ) {
            obj = reg.leer( i );
            if ( obj.get_estado() ) {
                obj.mostrar();
            }
        }

    }

}

/// Buscar
void FuncionesCuota::buscar() {
    Funciones f;
    ArchCuota reg;

    char dni[10];
    cout << "Ingrese DNI a buscar: ";
    f.cargar_cadena( dni, 9 );

    int mes;
    cout << "Ingrese el mes: ";
    cin >> mes;

    int anio;
    cout << "Ingrese el anio: ";
    cin >> anio;


    int pos = reg.buscar( dni, mes, anio );
    if ( pos < 0 ) {
        cout << "Cuota sin pagar.\n";
    } else {
        cout << "Cuota pagada!: \n";
        Cuota obj = reg.leer( pos );
        obj.mostrar();
    }
}

/// Eliminar
void FuncionesCuota::eliminar() {
    Funciones f;
    ArchCuota reg;
    char dni[10];
    cout << "Ingrese DNI de la cuota a eliminar: ";
    f.cargar_cadena( dni, 9 );

    cout << "Ingrese el mes: ";
    int mes;
    cin >> mes;
    cout << "Ingrese el anio: ";
    int anio;
    cin >> anio;

    int pos = reg.buscar( dni, mes, anio );
    if ( pos != -1 ) {
        Cuota obj = reg.leer( pos );
        if ( obj.get_estado() ) {
            cout << "Eliminar este Cuota? (s/N): ";
            char opc;
            cin >> opc;
            if ( opc == 'S' || opc == 's' ) {
                obj.set_estado( false );
                reg.modificar( obj, pos );
                cout << "Cuota Eliminado.\n";
            } else {
                cout << "Operacion cancelada.\n";
            }
        } else {
            cout << "Cuota inactiva!\n";
        }
    } else {
        cout << "Cuota no encontrado!\n";
    }
    system( "pause" );

}
