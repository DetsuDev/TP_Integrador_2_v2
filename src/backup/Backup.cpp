#include <iostream>
using namespace std;

#include "backup/Backup.h"
#include <fstream>

bool Backup::backup(const char* archivoOrigen, const char* archivoDestino){

    ifstream origen(archivoOrigen, ios::binary);
    ofstream destino(archivoDestino, ios::binary);

    if (!origen || !destino)
    {
        cout << "Error al abrir archivos para backup. " << endl;
        return false;
    }

    destino << origen.rdbuf();
    origen.close();
    destino.close();
    return true;
}

bool Backup::backup_general(){
    if((backup("files/current/Cuotas.dat","files/backup/Cuotas.bckp") == false) ||
       (backup("files/current/Prestamos.dat","files/backup/Prestamos.bckp") == false) ||
        (backup("files/current/Socios.dat","files/backup/Socios.bckp") == false) ||
        (backup("files/current/Libros.dat","files/backup/Libros.bckp") == false)){
                return false;
            }
            else{
                return true;
            }
}

bool Backup::restaurar_general(){
    if((backup("files/backup/Cuotas.bckp","files/current/Cuotas.dat") == false) ||
       (backup("files/backup/Prestamos.bckp","files/current/Prestamos.dat") == false) ||
        (backup("files/backup/Socios.bckp","files/current/Socios.dat") == false) ||
        (backup("files/backup/Libros.bckp","files/current/Libros.dat") == false)){
                return false;
            }
            else{
                return true;
            }
}
