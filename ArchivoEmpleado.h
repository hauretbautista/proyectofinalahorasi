#ifndef ARCHIVOEMPLEADO_H
#define ARCHIVOEMPLEADO_H

#include "Empleado.h"
#include <cstdio>
#include <cstring>

class ArchivoEmpleado {

private:
    char nombreArchivo [30];
    int tamRegistro;

public:
     ArchivoEmpleado(const char* n = "empleados.dat") {
     strcpy (nombreArchivo, n);
     tamRegistro = sizeof (Empleado);
     };

     int agregarRegistro ();

    bool listarRegistros();

    int buscarEmpleado(int idEmpleado);

    Empleado leerRegistro(int pos);

    bool bajaEmpleado (int idEmpleado);

    bool modificarEmpleado (int idEmpleado);

    int modificarRegistro(const Empleado& e, int pos);

   int obtenerSiguienteId();

   void mostrarEmpleadoPorID (int idEmpleado);

   void listarEmpleadosDisponibles();
};

#endif // ARCHIVOEMPLEADO_H
