#ifndef BACKUP_H
#define BACKUP_H


class Backup
{
    public:
        bool backup(const char* archivoOriginal, const char* archivoBackup);
        bool backup_general();
        bool restaurar_general();
    private:
};

#endif // BACKUP_H
