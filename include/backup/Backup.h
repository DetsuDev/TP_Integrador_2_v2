#ifndef BACKUP_H
#define BACKUP_H


class Backup
{
    public:
        Backup();
        bool generar_backup(const char* archivoOriginal, const char* archivoBackup);
    private:
};

#endif // BACKUP_H
