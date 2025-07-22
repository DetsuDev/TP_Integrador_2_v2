#include <iostream>
using namespace std;

#include "Backup.h"
#include "MenuBackup.h"

MenuBackup::MenuBackup()
{
    //ctor
}

void MenuBackup::mostrar()
{
    Backup backup;
    int opc;
    while ( true )
    {
        system( "cls" );
        cout << "SISTEMA DE GESTION DE BIBLIOTECA > GESTION BACKUP \n";
        cout << "--------------------------------------------------\n";
        cout << "[1] Generar backup\n";
        cout << "[2] Restaurar backup\n";
        cout << "[0] Volver\n";
        cout << "Ingrese opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
                if(backup.backup_general()){
                    cout << "Hecho." << endl;
                }
                else{
                    cout << "Hubo errores en el backup." << endl;
                }
                    system("pause");
            break;

        case 2:
                if(backup.restaurar_general()){
                    cout << "Hecho." << endl;
                }
                else{
                    cout << "Hubo errores en el restaurado." << endl;
                }
                    system("pause");
            break;

        case 0:
            return;
            break;
        }


    }

}
