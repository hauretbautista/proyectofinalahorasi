#ifndef VEHICULO_H
#define VEHICULO_H

#include "Fecha.h"

class Vehiculo {
private:
    char patente[10];
    char marca[30];
    char modelo[30];
    int anio;
    char falla[200];
    Fecha fechaIngreso;
    int tipoVehiculo;
    int IDCliente;
    bool estado;

public:
    Vehiculo();
    Vehiculo (const char *patente, const char *marca, const char *modelo, int anio, const char* falla, int tipoVehiculo, int IDCliente);

    void cargarVehiculo();
    void mostrarVehiculo();
    void ModificarVehiculo ();


        // const en ints no es necesario

    // Getters
    const char* getPatente() const;
    const char* getMarca() const;
    const char* getModelo() const;
    int getAnio() ;
    const char* getFalla() const;
    Fecha getFechaIngreso() const;
    int getTipoVehiculo() ;
    int getIDCliente() ;
    bool getEstado() const;

    // Setters
    void setPatente(const char* pat);
    void setMarca(const char* m);
    void setModelo(const char* mod);
    void setAnio(int a);
    void setFalla(const char* f);
    void setFechaIngreso(const Fecha& f);
    void setTipoVehiculo(int t);
    void setIDCliente(int id);
    void setEstado(bool e);
};

#endif // VEHICULO_H
