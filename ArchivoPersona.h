#ifndef ARCHIVOPERSONA_H
#define ARCHIVOPERSONA_H

#include "Persona.h"
#include <cstdio>

class ArchivoPersona {
private:
    char nombreArchivo[30];
    int tamRegistro;

public:

    ArchivoPersona(const char* nombre = "personas.dat");

    bool generarNuevo();

    int agregarRegistro(Persona p);

    bool listarRegistros();

    int buscarPersona(int dni);

    Persona leerRegistro(int pos);

    int modificarRegistro(Persona p, int pos);

    int contarRegistros();
};

#endif // ARCHIVOPERSONA_H
