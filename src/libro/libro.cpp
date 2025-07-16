#include <iostream>
#include <cstring>
#include "Libro.h"

using namespace std;

void Libro::mostrar() {
    cout << "ISBN: " << isbn << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Anio publicacion: " << anio_publi << endl;
    cout << "Ejemplares: " << c_ejemplares << endl;
    cout << "---------------------------------------------------------------------\n";
}

/// Setters
void Libro::set_estado(bool e) { estado = e; }
void Libro::set_isbn(const char *i) { strcpy(isbn, i); }
void Libro::set_titulo(const char *t) { strcpy(titulo, t); }
void Libro::set_autor(const char *a) { strcpy(autor, a); }
void Libro::set_anio_publi(int a) { anio_publi = a; }
void Libro::set_c_ejemplares(int c) { c_ejemplares = c; }

/// Getters
bool Libro::get_estado() { return estado; }
const char* Libro::get_isbn() { return isbn; }
const char* Libro::get_titulo() { return titulo; }
const char* Libro::get_autor() { return autor; }
int Libro::get_anio_publi() { return anio_publi; }
int Libro::get_c_ejemplares() { return c_ejemplares; }
