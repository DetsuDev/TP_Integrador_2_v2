#include <iostream>

#include "MenuPrincipal.h"
using namespace std;

/// Objeto Socio: DNI, Nombre, Direccion, Email, Fecha de Nacimiento
/// Objeto Libro: ISBN, Nombre del libro, Nombre del autor, Fecha de publicacion, cantidad de ejemplares
/// Objeto Prestamos: Libro prestado, Socio al que se le presto, fecha del prestamo, fecha de devolucion
/// Objeto Cuota: Numero de Socio, Fecha de pago, Importe, Mes, Año, Importe

/// COSAS A HACER

/// LIBROS
/// NO PERMITIR ELIMINAR UN LIBRO SI TIENE UN PRESTAMO ACTIVO
/// SOCIOS
/// CALCULAR CUANTAS CUOTAS DEBE Y EL IMPORTE
/// AGREGAR DEDUDA SI SE VUELVE A CARGAR EL MISMO DNI
/// SOLICITUD POR NOMBRE Y CUOTAS

/// CLASES/ARCHIVOS: PascalCase
/// OBJETOS: camelCase
/// FUNCIONES/METODOS/VARIABLES: snake_case

int main()
{
    MenuPrincipal menu;
    menu.mostrar();
    return 0;
}
