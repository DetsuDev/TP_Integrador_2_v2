#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

class Domicilio{
    private:
        char calle[30];
        int altura;
        char localidad[30];
        char partido[30];
        char codigoPostal[6];
    public:
        void cargar();
        void mostrar();
};

#endif // CLASE_DOMICILIO_H_INCLUDED
