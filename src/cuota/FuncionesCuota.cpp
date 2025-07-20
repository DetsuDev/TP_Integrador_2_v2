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
        //existenteSoc.set_deuda( existenteSoc.get_deuda() + cuota.get_importe());
        //regSoc.modificar(existenteSoc, pos_soc);
        return;
    }
    cargar( cuota );
    cuota.set_dni( dni );
    cuota.set_mes( mes );
    cuota.set_anio( anio );
    cuota.set_estado( true );
    regCuot.grabar( cuota );
    //existenteSoc.set_deuda( existenteSoc.get_deuda() + cuota.get_importe());
    //regSoc.modificar(existenteSoc, pos_soc);

}


/// Listado
void FuncionesCuota::listar() {
    Cuota obj;
    Socio socio;
    ArchSocio regSocio;
    ArchCuota reg;
    int cant_reg = reg.contar();

    if ( cant_reg < 1 ) {
        cout << "NO HAY DATOS.\n";
    } else {
        for ( int i = 0; i < cant_reg; i++ ) {
            obj = reg.leer( i );
            if ( obj.get_estado()) {
                obj.mostrar();
                //if ((strcmp(socio.get_dni(),obj.get_dni()) == 0)){

                //cout << "Deuda: " << socio.get_deuda() << endl;
                //}
            }
        }

    }

}

/// Buscar
void FuncionesCuota::buscar() {
    Funciones f;
    ArchCuota reg;

    ArchSocio regSoc;

    char dni[10];
    cout << "Ingrese DNI a buscar: ";
    f.cargar_cadena( dni, 9 );

    int pos_socio = regSoc.buscar(dni);
    Socio socio = regSoc.leer(pos_socio);
    if (pos_socio != -1) {
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
    } else {
    cout << "DNI no encontrado.\n";
    }



}

/// Eliminar
void FuncionesCuota::eliminar() {
    Funciones f;
    ArchCuota reg;
    ArchSocio regSocio;
    char dni[10];
    cout << "Ingrese DNI de la cuota a eliminar: ";
    f.cargar_cadena( dni, 9 );

    Cuota obj;
    int cant_reg = reg.contar();
    for(int i = 0; i < cant_reg; i++){
        obj = reg.leer(i);
        if((obj.get_estado() == true) && (strcmp(dni,obj.get_dni()) == 0)){
            cout << endl;
            obj.mostrar();
        }
    }


    cout << "Ingrese el mes de la cuota a eliminar: ";
    int mes;
    cin >> mes;
    cout << "Ingrese el anio de la cuota a eliminar: ";
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
                /*int pos_socio = regSocio.buscar(dni);
                Socio socio = regSocio.leer (pos_socio);
                socio.set_deuda( socio.get_deuda() - obj.get_importe());
                regSocio.modificar (socio, pos_socio);*/
                reg.modificar( obj, pos );
                cout << "Cuota Eliminada.\n";
            } else {
                cout << "Operacion cancelada.\n";
            }
        } else {
            cout << "Cuota inactiva!\n";
        }
    } else {
        cout << "Cuota no encontrada!\n";
    }
    system( "pause" );

}
