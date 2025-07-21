#include <iostream>
using namespace std;

#include "Backup.h"

Backup::Backup()
{
    //ctor
}

bool Backup::generar_backup(const char* archivoOriginal, const char* archivoBackup){

    ifstream origen(archivoOriginal, ios::binary);
    ofstream destino(archivoBackup, ios::binary);

    if (!origen || !destino)
    {
        cout << "Error al abrir archivos para backup: " << archivoOriginal << endl;
        return false;
    }

    destino << origen.rdbuf();
    origen.close();
    destino.close();
    return true;
}


Backup::~Backup()
{
    //dtor
}
