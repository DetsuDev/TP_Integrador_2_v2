Objeto Socio: DNI, Nombre, Apellido, Email, Fecha de Nacimiento, Direccion. <br>
Objeto Libro: ISBN, Nombre del libro, Nombre del autor, Fecha de publicacion, cantidad de ejemplares. <br>
Objeto Prestamos: ID_prestamo, Libro prestado, Socio al que se le presto, fecha del prestamo, fecha de devolucion. <br>
Objeto Cuota: Numero de Socio, Fecha de pago, Importe, Mes, Año, Importe. <br>

Socio (cargar, listar, buscar dni, eliminar) ✔ <br>
Libro (cargar, listar, buscar isbn, eliminar) ✔ <br>
Prestamo (cargar, listar, buscar n_prestamo/dni/isbn , eliminar) ✔ <br>
Cuota (cargar, listar, buscar dni, mes, anio, eliminar) ✔ <br>

Verificar si al cargar cuota, socio existe ✔ <br>
Verificar si al cargar prestamo, libro existe ✔ <br>
Verificar eliminar Socio si tiene prestamos o cuotas ✔ <br>
No permitir eliminar Libro si tiene prestamos activos ✔ <br> 

CLASES/ARCHIVOS: PascalCase <br>
OBJETOS: camelCase <br>
FUNCIONES/METODOS/VARIABLES: snake_case <br>
