#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int d=1, int m=1, int a=1900);
        void set_dia(int);
        void set_mes(int);
        void set_anio(int);
        int get_dia();
        int get_mes();
        int get_anio();
        void cargar();
        void mostrar();
};

#endif // FECHA_H_INCLUDED
