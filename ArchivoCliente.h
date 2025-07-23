#ifndef ARCHIVO_CLIENTE_H
#define ARCHIVO_CLIENTE_H

#include "Cliente.h"
#include <cstdio>

class ArchivoCliente {
    char NombreArchivo[30];
    int TamRegistro;

public:
    ArchivoCliente(const char* nombre = "Clientes.dat");
    bool GenerarNuevo();
    void AgregarCliente();
    void MostrarCliente();
    void ModificarCliente();
    void EliminarCliente();
    void MostrarClientePorID();
    bool ExisteCliente(int id);
    int ObtenerProximoID();
};

#endif // ARCHIVO_CLIENTE_H
