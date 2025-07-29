#include <iostream>
using namespace std;

#include "backup/Backup.h"

bool Backup::backup(const char* archivoOrigen, const char* archivoDestino) {
    FILE* origen = fopen(archivoOrigen, "rb");
    FILE* destino = fopen(archivoDestino, "wb");
    if (!origen || !destino) {
        cout << "Error al abrir archivos para backup." << endl;
        if (origen) fclose(origen);
        if (destino) fclose(destino);
        return false;
    }

    const size_t bufferSize = 4096;
    char buffer[bufferSize];
    size_t bytesleidos;
    while ((bytesleidos = fread(buffer, 1, bufferSize, origen)) > 0) {
        fwrite(buffer, 1, bytesleidos, destino);
    }

    fclose(origen);
    fclose(destino);
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
