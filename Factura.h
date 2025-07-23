#ifndef FACTURA_H
#define FACTURA_H

#include "Fecha.h"

class Factura {
public:
    int NFactura;
    int NReparacion;
    int Importe;
    Fecha FechaEntrega;
    char NPatente[20];
    int IDCliente;
    int ImporteTotal;

    // Constructores
    Factura();
    Factura(int nFact, int nRep, int imp, Fecha fecha, const char* pat, int idCli, int impTotal);

    void generarFactura();
    void mostrarFactura();
    void mostrarTodasLasFacturas();
    void mostrarUltimaFactura ();
private:
    void guardarEnArchivo();
};

#endif // FACTURA_H
