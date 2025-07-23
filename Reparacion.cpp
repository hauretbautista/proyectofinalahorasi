#include <iostream>
#include <cstring>
#include "Reparacion.h"
#include "ArchivoVehiculo.h"
#include "ArchivoCliente.h"
#include "ArchivoEmpleado.h"

using namespace std;

Reparacion::Reparacion() {
    IDReparacion = 0;
    strcpy(patente, "");
    IDCliente = 0;
    IDEmpleado = 0;
    fechaIngreso = Fecha();
    fechaEntrega = Fecha();
    strcpy(descripcionTrabajo, "");
    strcpy(repuestosUsados, "");
    importe = 0.0;
    estado = 1; // 1: Pendiente 2: curso 3: Finalizada
    pagado = false;
}

 ArchivoVehiculo archivoVehiculos;


bool Reparacion::cargarReparacion() {
    cout << "=== CARGAR NUEVA REPARACION ===" << endl;


    archivoVehiculos.listarPatentesDisponibles();

    cout << "Ingrese patente del vehiculo: ";
    cin >> patente;

    // VALIDACION DE PATENTE
    int posVehiculo = archivoVehiculos.BuscarVehiculoPorPatente(patente);
    if (posVehiculo == -1) {
        cout << "Patente no encontrada, por favor registre primero el vehiculo." << endl;
        return false;
    }
    system ("cls");
 ArchivoCliente archivoClientes;
    archivoClientes.MostrarCliente ();
    cout << "Ingrese ID del cliente: ";
    cin >> IDCliente;

    // VALIDACION DE CLIENTE
    ArchivoCliente ArchivoCliente;
    if (!ArchivoCliente.ExisteCliente(IDCliente)) {
        cout << "ID de cliente no encontrado, por favor registre primero el cliente." << endl;
        return false;
    }
    system ("cls");

ArchivoEmpleado archivoEmpleados;
archivoEmpleados.listarEmpleadosDisponibles();
    cout << "Ingrese ID del empleado: ";
    cin >> IDEmpleado;

    // VALIDA DE EMPLEADO
    ArchivoEmpleado ArchivoEmpleado;
    if (ArchivoEmpleado.buscarEmpleado(IDEmpleado) == -1) {
        cout << "ID de empleado no encontrado, por favor registre primero el empleado." << endl;
        return false;
    }

    cout << "Ingrese fecha de ingreso:" << endl;
    fechaIngreso.cargarFecha();

    cout << "Ingrese fecha de entrega estimada:" << endl;
    fechaEntrega.cargarFecha();

    cin.ignore();
    cout << "Ingrese descripcion del trabajo: ";
    cin.getline(descripcionTrabajo, 200);

    cout << "Ingrese repuestos utilizados: ";
    cin.getline(repuestosUsados, 200);

    cout << "Ingrese importe: $";
    cin >> importe;
    cin.ignore();

    return true;
}

void Reparacion::mostrarReparacion() const {
    cout << "=== DATOS DE LA REPARACION ===" << endl;
    cout << "ID REPARACION: " << IDReparacion << endl;
    cout << "PATENTE: " << patente << endl;
    cout << "ID CLIENTE: " << IDCliente << endl;
    cout << "ID EMPLEADO: " << IDEmpleado << endl;
    cout << "FECHA INGRESO: ";
    cout << endl;
    fechaIngreso.mostrarFecha();
    cout << endl;
    cout << "FECHA ENTREGA: ";
     cout << endl;
    fechaEntrega.mostrarFecha();
     cout << endl;
    cout << "DESCRIPCION: " << descripcionTrabajo << endl;
    cout << "REPUESTOS: " << repuestosUsados << endl;
    cout << "IMPORTE: $" << importe << endl;
    cout << "ESTADO: ";
    switch (estado) {
        case 1: cout << "PENDIENTE"; break;
        case 2: cout << "EN CURSO"; break;
        case 3: cout << "FINALIZADA"; break;
        default: cout << "DESCONOCIDO"; break;
    }
    cout << endl;
    cout << "PAGADO: " << (pagado ? "SI" : "NO") << endl;
    cout << "==============================" << endl;
}

// Getters
int Reparacion::getIDReparacion() {
    return IDReparacion;
}

const char* Reparacion::getPatente() const {
    return patente;
}

int Reparacion::getIDCliente() {
    return IDCliente;
}

int Reparacion::getIDEmpleado() {
    return IDEmpleado;
}

Fecha Reparacion::getFechaIngreso() const {
    return fechaIngreso;
}

Fecha Reparacion::getFechaEntrega() const {
    return fechaEntrega;
}

const char* Reparacion::getDescripcionTrabajo() const {
    return descripcionTrabajo;
}

const char* Reparacion::getRepuestosUsados() const {
    return repuestosUsados;
}

float Reparacion::getImporte() const {
    return importe;
}

int Reparacion::getEstado() {
    return estado;
}

bool Reparacion::estaPagado() {
    return pagado;
}

// Setters
void Reparacion::setIDReparacion(int id) {
    IDReparacion = id;
}

void Reparacion::setPatente(const char* pat) {
    strncpy(patente, pat, sizeof(patente) - 1);
    patente[sizeof(patente) - 1] = '\0';
}

void Reparacion::setIDCliente(int id) {
    IDCliente = id;
}

void Reparacion::setIDEmpleado(int id) {
    IDEmpleado = id;
}

void Reparacion::setFechaIngreso(const Fecha& f) {
    fechaIngreso = f;
}

void Reparacion::setFechaEntrega(const Fecha& f) {
    fechaEntrega = f;
}

void Reparacion::setDescripcionTrabajo(const char* desc) {
    strncpy(descripcionTrabajo, desc, sizeof(descripcionTrabajo) - 1);
    descripcionTrabajo[sizeof(descripcionTrabajo) - 1] = '\0';
}

void Reparacion::setRepuestosUsados(const char* rep) {
    strncpy(repuestosUsados, rep, sizeof(repuestosUsados) - 1);
    repuestosUsados[sizeof(repuestosUsados) - 1] = '\0';
}

void Reparacion::setImporte(float imp) {
    if (imp >= 0) {
        importe = imp;
    }
}

void Reparacion::setEstado(int est) {
    if (est >= 1 && est <= 3) {
        estado = est;
    }
}

void Reparacion::setPagado(bool p) {
    pagado = p;
}
