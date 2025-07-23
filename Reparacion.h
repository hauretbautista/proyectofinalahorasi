#ifndef REPARACION_H
#define REPARACION_H

#include "Fecha.h"

class Reparacion {
private:
    int IDReparacion;
    char patente[10];
    int IDCliente;
    int IDEmpleado;
    Fecha fechaIngreso;
    Fecha fechaEntrega;
    char descripcionTrabajo[200];
    char repuestosUsados[200];
    float importe;
    int estado;
    bool pagado;

public:
    Reparacion();

    bool cargarReparacion();

    void mostrarReparacion() const;

        // const en ints no es necesario

    // Getters
    int getIDReparacion() ;
    const char* getPatente() const;
    int getIDCliente() ;
    int getIDEmpleado() ;
    Fecha getFechaIngreso() const;
    Fecha getFechaEntrega() const;
    const char* getDescripcionTrabajo() const;
    const char* getRepuestosUsados() const;
    float getImporte() const;
    int getEstado() ;
    bool estaPagado() ;

    // Setters
    void setIDReparacion(int id);
    void setPatente(const char* pat);
    void setIDCliente(int id);
    void setIDEmpleado(int id);
    void setFechaIngreso(const Fecha& f);
    void setFechaEntrega(const Fecha& f);
    void setDescripcionTrabajo(const char* desc);
    void setRepuestosUsados(const char* rep);
    void setImporte(float imp);
    void setEstado(int est);
    void setPagado(bool p);
};

#endif // REPARACION_H
