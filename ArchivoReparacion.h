#ifndef ARCHIVOREPARACION_H
#define ARCHIVOREPARACION_H

#include "Reparacion.h"
#include <cstdio>

class ArchivoReparacion {
private:
    char nombreArchivo[30];
    int tamRegistro;

public:
    // Constructor
    ArchivoReparacion(const char* nombre = "reparaciones.dat");

    // Métodos básicos del archivo
    bool generarNuevo();
    int agregarRegistro(const Reparacion r);
    bool listarRegistros();
    int buscarReparacion(int id);
    Reparacion leerRegistro(int pos);
    int modificarRegistro(const Reparacion r, int pos);
    int contarRegistros();

    // Métodos auxiliares
    bool existeReparacion(int id);
    int obtenerProximoID();

    // Métodos de consulta específicos
    bool listarReparacionesPorCliente(int idCliente);
    bool listarReparacionesPorEstado(int estado);
    bool listarReparacionesPendientesPago();
};

#endif // ARCHIVOREPARACION_H
