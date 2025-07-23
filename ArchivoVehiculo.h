#ifndef ARCHIVOVEHICULO_H_INCLUDED
#define ARCHIVOVEHICULO_H_INCLUDED

#include "Vehiculo.h"
#include <cstring>

class ArchivoVehiculo {
private:
    char nombreArchivo[30];
    int tamRegistro;
public:
   ArchivoVehiculo(const char* n="vehiculos.dat");

    int AgregarRegistro();
    bool listarRegistros();
    bool bajaVehiculo (const char *patente);
    int ModificarRegistro (const Vehiculo veh, int pos);
    int BuscarVehiculoPorPatente(const char* PatenteBuscar);
    void listarPatentesDisponibles ();

    int BuscarVehiculo(const char* patente);
    Vehiculo LeerRegistro(int pos);

};
#endif // ARCHIVOVEHICULO_H_INCLUDED
