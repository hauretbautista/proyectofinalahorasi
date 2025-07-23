#ifndef INFORMES_H
#define INFORMES_H

#include "ArchivoReparacion.h"
#include "ArchivoCliente.h"
#include "Factura.h"
#include <cstdio>

class Informes {
public:
    // Constructor
    Informes();

    void recaudacionMensual();
    void recaudacionAnual();
    void recaudacionPorCliente();
    void reparacionesPorVehiculo();
    void reparacionesPorEmpleado();
    void vehiculoMasReparado();
    void mostrarMenuInformes();
    void reparacionesPorEstado();

private:
    float calcularRecaudacionMes(int mes, int anio);
    float calcularRecaudacionAnio(int anio);
    int contarReparacionesPorVehiculo(const char* patente);
    int contarReparacionesPorEmpleado(int idEmpleado);
    void mostrarEncabezado(const char* titulo);
};

#endif // INFORMES_H
