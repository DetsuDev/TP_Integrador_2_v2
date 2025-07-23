#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

class Domicilio{
    private:
        char calle[30];
        int altura;
        char localidad[30];
        char partido[30];
        char codigo_postal[6];
    public:
        void cargar();
        void mostrar();

    /// Setters
    void set_calle( const char* );
    void set_altura( int );
    void set_partido( const char* );
    void set_localidad(const char*);
    void set_codigo_postal( const char*);

    /// Getters
    const char* get_calle();
    int get_altura();
    const char* get_partido();
    const char* get_localidad();
    const char* get_codigo_postal();
};

#endif // CLASE_DOMICILIO_H_INCLUDED
