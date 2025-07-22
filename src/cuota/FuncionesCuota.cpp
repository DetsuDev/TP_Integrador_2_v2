#include "FuncionesCuota.h"
#include "Cuota.h"
#include "Socio.h"
#include <iostream>
#include <cstring>
using namespace std;
FuncionesCuota::FuncionesCuota() {}

/// Carga
void FuncionesCuota::cargar( Cuota &cuota ) {
    float importe;
    cout << "Ingrese el importe: ";
    cin >> importe;
    cuota.set_importe( importe );

    cout << "Ingrese la fecha de pago: " << endl;
    Fecha fPago;
    fPago.cargar();
    cuota.set_fecha_pago( fPago );
}

/// Registro
void FuncionesCuota::registrar() {

    Cuota cuota;
    char dni[10];
    cout << "Ingrese el DNI: ";
    f.cargar_cadena( dni, 9 );

    int pos_soc = archSocio.buscar( dni );
    if ( pos_soc > -1 ) {
        int mes;
        cout << "Ingrese el mes: ";
        cin >> mes;

        int anio;
        cout << "Ingrese el anio: ";
        cin >> anio;
        int pos_cuota = archCuota.buscar( dni, mes, anio );

        if ( pos_cuota > -2 ) {
            if ( pos_cuota > -1 ) {
                cout << "Cuota ya pagada.\n";
                system( "pause" );
            } else {
                cargar( cuota );
                cuota.set_dni( dni );
                cuota.set_mes( mes );
                cuota.set_anio( anio );
                cuota.set_estado( true );
                archCuota.modificar( cuota, pos_cuota );
            }
        }
        cargar( cuota );
        cuota.set_dni( dni );
        cuota.set_mes( mes );
        cuota.set_anio( anio );
        cuota.set_estado( true );
        archCuota.grabar( cuota );

    } else {
        cout << "DNI NO EXISTENTE\n";
        system( "pause" );
    }
}


/// Listado
void FuncionesCuota::listar( const char *dni ) {
    Cuota cuota;
    Socio socio;
    int cant_reg = archCuota.contar();

    if ( cant_reg < 1 ) {
        cout << "NO HAY DATOS.\n";
    } else {
        for ( int i = 0; i < cant_reg; i++ ) {
            cuota = archCuota.leer( i );
            if ( cuota.get_estado() ) {
                if ( strlen( dni ) > 1 ) {
                    if ( strcmp( cuota.get_dni(), dni ) == 0 ) {
                        cuota.mostrar();
                    }
                } else {
                    cuota.mostrar();
                }

            }
        }
    }
}

/// Buscar
void FuncionesCuota::buscar() {
    Socio socio;
    cout << "Buscar por: \n";
    cout << "[1] Dni: \n";
    cout << "[2] Dni y Fecha: \n";
    cout << "Ingrese opcion: ";
    int opc;
    cin >> opc;

    int pos;
    if ( opc > 0 && opc < 3 ) {
        char dni[10];
        cout << "Ingrese DNI a buscar: ";
        f.cargar_cadena( dni, 9 );

        int pos_socio = archSocio.buscar( dni );
        socio = archSocio.leer( pos_socio );
        if ( pos_socio > -1 ) {
            if ( opc == 1 ) {
                 pos = archCuota.buscar_dni( dni );
                cout << "Cuotas de: ";
                listar( dni );
            }
            if ( opc == 2 ) {
                int mes;
                cout << "Ingrese el mes: ";
                cin >> mes;

                int anio;
                cout << "Ingrese el anio: ";
                cin >> anio;

                pos = archCuota.buscar( dni, mes, anio );
                if ( pos > -1 ) {
                    cout << "Cuota encontrada!: \n";
                    Cuota cuota = archCuota.leer( pos );
                    cuota.mostrar();
                } else {
                    cout << "Cuota sin registrar.\n";
                }
            }

        } else {
            cout << "DNI no encontrado.\n";
        }

    } else {

        cout << "Operacion cancelada.\n";

    }
}

/// Eliminar
void FuncionesCuota::eliminar() {
    char dni[10];
    cout << "Ingrese DNI de la cuota a eliminar: ";
    f.cargar_cadena( dni, 9 );

    Cuota cuota;
    int cant_reg = archCuota.contar();
    for ( int i = 0; i < cant_reg; i++ ) {
        cuota = archCuota.leer( i );
        if ( ( cuota.get_estado() == true ) && ( strcmp( dni, cuota.get_dni() ) == 0 ) ) {
            cout << endl;
            cuota.mostrar();
        }
    }


    cout << "Ingrese el mes de la cuota a eliminar: ";
    int mes;
    cin >> mes;
    cout << "Ingrese el anio de la cuota a eliminar: ";
    int anio;
    cin >> anio;

    int pos = archCuota.buscar( dni, mes, anio );
    if ( pos != -1 ) {
        Cuota cuota = archCuota.leer( pos );
        if ( cuota.get_estado() ) {
            cout << "Eliminar este Cuota? (s/N): ";
            char opc;
            cin >> opc;
            if ( opc == 'S' || opc == 's' ) {
                cuota.set_estado( false );
                archCuota.modificar( cuota, pos );
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
