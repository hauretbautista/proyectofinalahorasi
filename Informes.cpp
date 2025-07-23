#include <iostream>
#include <cstring>
#include <cstdio>
#include "Informes.h"

using namespace std;

Informes::Informes() {}

// ===== REPARACIONES POR ESTADO =====
void Informes::reparacionesPorEstado() {
    cout << "\n======== REPARACIONES POR ESTADO ========" << endl;

    cout << "Seleccione el estado:" << endl;
    cout << "1. Pendiente" << endl;
    cout << "2. En curso" << endl;
    cout << "3. Finalizada" << endl;
    cout << "Opcion: ";

    int estado;
    cin >> estado;

    if (estado < 1 || estado > 3) {
        cout << "Opcion invalida." << endl;
        return;
    }

    // muestra qué estado se busca
    if (estado == 1) cout << "\n--- REPARACIONES PENDIENTES ---" << endl;
    if (estado == 2) cout << "\n--- REPARACIONES EN CURSO ---" << endl;
    if (estado == 3) cout << "\n--- REPARACIONES FINALIZADAS ---" << endl;

    FILE* archivo = fopen("reparaciones.dat", "rb");
    if (!archivo) {
        cout << "No hay reparaciones." << endl;
        return;
    }

    Reparacion rep;
    int contador = 0;
    float total = 0;

    cout << "ID Rep | Patente    | Empleado | Importe" << endl;
    cout << "----------------------------------------" << endl;

    while (fread(&rep, sizeof(Reparacion), 1, archivo)) {
        if (rep.getEstado() == estado) {
            contador++;
            total += rep.getImporte();

            cout << rep.getIDReparacion() << "      | "
                 << rep.getPatente() << "      | "
                 << rep.getIDEmpleado() << "        | $"
                 << rep.getImporte() << endl;
        }
    }
    fclose(archivo);

    cout << "----------------------------------------" << endl;
    cout << "Total: " << contador << " reparaciones" << endl;
    cout << "Importe total: $" << total << endl;
}

// ===== RECAUDACIÓN =====
void Informes::recaudacionMensual() {
    cout << "\n======== RECAUDACION MENSUAL ========" << endl;

    int anio;
    cout << "Anio: ";
    cin >> anio;

    float total = 0;

    for (int mes = 1; mes <= 12; mes++) {
        float recaud = calcularRecaudacionMes(mes, anio);

        // Muestra nombre del mes
        if (mes == 1) cout << "Ene: $" << recaud << endl;
        if (mes == 2) cout << "Feb: $" << recaud << endl;
        if (mes == 3) cout << "Mar: $" << recaud << endl;
        if (mes == 4) cout << "Abr: $" << recaud << endl;
        if (mes == 5) cout << "May: $" << recaud << endl;
        if (mes == 6) cout << "Jun: $" << recaud << endl;
        if (mes == 7) cout << "Jul: $" << recaud << endl;
        if (mes == 8) cout << "Ago: $" << recaud << endl;
        if (mes == 9) cout << "Sep: $" << recaud << endl;
        if (mes == 10) cout << "Oct: $" << recaud << endl;
        if (mes == 11) cout << "Nov: $" << recaud << endl;
        if (mes == 12) cout << "Dic: $" << recaud << endl;

        total += recaud;
    }
    cout << "TOTAL: $" << total << endl;
}

void Informes::recaudacionAnual() {
    cout << "\n======== RECAUDACION ANUAL ========" << endl;

    int anio;
    cout << "Anio: ";
    cin >> anio;

    float total = calcularRecaudacionAnio(anio);
    cout << "Total " << anio << ": $" << total << endl;
}

void Informes::recaudacionPorCliente() {
    cout << "\n======== RECAUDACION POR CLIENTE ========" << endl;

    FILE* archivo = fopen("facturas.dat", "rb");
    if (!archivo) {
        cout << "No hay facturas." << endl;
        return;
    }

    int clientes[50];
    int cantidades[50];
    float totales[50];
    int cantClientes = 0;

    Factura factura;
    while (fread(&factura, sizeof(Factura), 1, archivo) && cantClientes < 50) {
        int pos = -1;

        for (int i = 0; i < cantClientes; i++) {
            if (clientes[i] == factura.IDCliente) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            clientes[cantClientes] = factura.IDCliente;
            totales[cantClientes] = factura.ImporteTotal;
            cantidades[cantClientes] = 1;
            cantClientes++;
        } else {
            totales[pos] += factura.ImporteTotal;
            cantidades[pos]++;
        }
    }
    fclose(archivo);

    cout << "Cliente | Total     | Facturas" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < cantClientes; i++) {
        cout << clientes[i] << "      | $" << totales[i] << "     | " << cantidades[i] << endl;
    }
}

// ===== REPARACIONES =====
void Informes::reparacionesPorVehiculo() {
    cout << "\n======== REPARACIONES POR VEHICULO ========" << endl;

    char patente[20];
    cout << "Patente: ";
    cin >> patente;

    FILE* archivo = fopen("reparaciones.dat", "rb");
    if (!archivo) {
        cout << "No hay reparaciones." << endl;
        return;
    }

    Reparacion rep;
    int contador = 0;
    float total = 0;

    while (fread(&rep, sizeof(Reparacion), 1, archivo)) {
        if (strcmp(rep.getPatente(), patente) == 0) {
            contador++;
            total += rep.getImporte();
            cout << "Rep #" << rep.getIDReparacion() << " - $" << rep.getImporte() << endl;
        }
    }
    fclose(archivo);

    cout << "Total: " << contador << " reparaciones - $" << total << endl;
}

void Informes::reparacionesPorEmpleado() {
    cout << "\n======== REPARACIONES POR EMPLEADO ========" << endl;

    int idEmpleado;
    cout << "ID Empleado: ";
    cin >> idEmpleado;

    FILE* archivo = fopen("reparaciones.dat", "rb");
    if (!archivo) {
        cout << "No hay reparaciones." << endl;
        return;
    }

    Reparacion rep;
    int contador = 0;
    float total = 0;

    while (fread(&rep, sizeof(Reparacion), 1, archivo)) {
        if (rep.getIDEmpleado() == idEmpleado) {
            contador++;
            total += rep.getImporte();
            cout << "Patente: " << rep.getPatente() << " - $" << rep.getImporte() << endl;
        }
    }
    fclose(archivo);

    cout << "Total: " << contador << " reparaciones - $" << total << endl;
}

void Informes::vehiculoMasReparado() {
    cout << "\n======== VEHICULO MAS REPARADO ========" << endl;

    FILE* archivo = fopen("reparaciones.dat", "rb");
    if (!archivo) {
        cout << "No hay reparaciones." << endl;
        return;
    }

    char patentes[50][20];
    int cantidades[50];
    int cantVehiculos = 0;

    Reparacion rep;
    while (fread(&rep, sizeof(Reparacion), 1, archivo) && cantVehiculos < 50) {
        int pos = -1;

        // Busca existe la patente
        for (int i = 0; i < cantVehiculos; i++) {
            if (strcmp(patentes[i], rep.getPatente()) == 0) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            strcpy(patentes[cantVehiculos], rep.getPatente());
            cantidades[cantVehiculos] = 1;
            cantVehiculos++;
        } else {
            cantidades[pos]++;
        }
    }
    fclose(archivo);

    int maxRep = 0;
    int indiceMax = 0;
    for (int i = 0; i < cantVehiculos; i++) {
        if (cantidades[i] > maxRep) {
            maxRep = cantidades[i];
            indiceMax = i;
        }
    }

    cout << "Vehiculo mas reparado:" << endl;
    cout << "Patente: " << patentes[indiceMax] << endl;
    cout << "Reparaciones: " << maxRep << endl;
}



// ===== FUNCIONES AUXILIARES =====
float Informes::calcularRecaudacionMes(int mes, int anio) {
    FILE* archivo = fopen("facturas.dat", "rb");
    if (!archivo) return 0;

    Factura factura;
    float total = 0;

    while (fread(&factura, sizeof(Factura), 1, archivo)) {
        if (factura.FechaEntrega.getMes() == mes && factura.FechaEntrega.getAnio() == anio) {
            total += factura.ImporteTotal;
        }
    }
    fclose(archivo);
    return total;
}

float Informes::calcularRecaudacionAnio(int anio) {
    FILE* archivo = fopen("facturas.dat", "rb");
    if (!archivo) return 0;

    Factura factura;
    float total = 0;

    while (fread(&factura, sizeof(Factura), 1, archivo)) {
        if (factura.FechaEntrega.getAnio() == anio) {
            total += factura.ImporteTotal;
        }
    }
    fclose(archivo);
    return total;
}
