#ifndef LIBRO_H
#define LIBRO_H

class Libro {

private:
    bool estado = false;
    char isbn[20];
    char titulo[50];
    char autor[50];
    int anio_publi;
    int c_ejemplares;

public:
    /// Setters
    void set_estado( bool );
    void set_isbn( const char * );
    void set_titulo( const char * );
    void set_autor( const char * );
    void set_anio_publi( int );
    void set_c_ejemplares( int );

    /// Getters
    bool get_estado();
    const char* get_isbn();
    const char* get_titulo();
    const char* get_autor();
    int get_anio_publi();
    int get_c_ejemplares();

    /// Funciones
    void mostrar();
};

#endif // LIBRO_H
