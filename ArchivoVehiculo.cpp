#include <iostream>
#include "Vehiculo.h"
#include "ArchivoVehiculo.h"
#include <cstring>

using namespace std;

//ABML: ALTA
int ArchivoVehiculo::AgregarRegistro() {
    Vehiculo obj;
    obj.cargarVehiculo();

    FILE* archivo = fopen(nombreArchivo, "ab");
    if (!archivo) {
        cout << "No se pudo abrir el archivo para agregar." << endl;
        return -1;
    }
    int escribio = fwrite(&obj, tamRegistro, 1, archivo);
    fclose(archivo);
    return escribio;
}

//ABML: BAJA LOGICA
bool ArchivoVehiculo::bajaVehiculo(const char* patenteBuscada) {
    FILE* archivo = fopen(nombreArchivo, "rb+");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de vehiculos." << endl;
        return false;
    }
    Vehiculo obj;
    int pos = 0;
    bool encontrado = false;
    while (fread(&obj, tamRegistro, 1, archivo)) {
        if (obj.getEstado() && strcmp(obj.getPatente(), patenteBuscada) == 0) {
            obj.setEstado(false); // baja lógica
            fseek(archivo, pos * tamRegistro, SEEK_SET);
            int escribio = fwrite(&obj, tamRegistro, 1, archivo);
            fclose(archivo);
            return (escribio == 1);
        }
        pos++;
    }
    fclose(archivo);
    return false;
}


//ABML: MODIFICACION
int ArchivoVehiculo::ModificarRegistro(const Vehiculo veh, int pos) {
    FILE* archivo = fopen(nombreArchivo, "rb+");
    if (!archivo) return -1;
    fseek(archivo, pos * tamRegistro, SEEK_SET);
    int escribio = fwrite(&veh, tamRegistro, 1, archivo);
    fclose(archivo);
    return escribio;
}


//ABML: LISTADOS
bool ArchivoVehiculo::listarRegistros() {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de vehiculos para listar." << endl;
        return false;
    }

    Vehiculo obj;
    bool hayDatos = false;
    while (fread(&obj, tamRegistro, 1, archivo)) {
        if (obj.getEstado()) { // Solo muestra los activos
            obj.mostrarVehiculo();
            cout << "-----------------------------" << endl;
            hayDatos = true;
        }
    }

    fclose(archivo);

    if (!hayDatos) {
        cout << "No hay vehculos activos para mostrar." << endl;
    }

    return hayDatos;
}


//FUNCION GENERAL PARA BUSCAR Y UBICAR REGISTRO EN ESPECIFICO
int ArchivoVehiculo::BuscarVehiculo(const char* patenteBuscada) {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (!archivo) return -1;
    Vehiculo obj;
    int pos = 0;
    while (fread(&obj, tamRegistro, 1, archivo)) {
        if (obj.getEstado() && strcmp(obj.getPatente(), patenteBuscada) == 0) {
            fclose(archivo);
            return pos;
        }
        pos++;
    }
    fclose(archivo);
    return -1;
}


//FUNCION GENERAL PARA MANEJAR REGISTROS INDIVIDUALES
Vehiculo ArchivoVehiculo::LeerRegistro(int pos) {
    Vehiculo obj;
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (!archivo) return obj;
    fseek(archivo, pos * tamRegistro, SEEK_SET);
    fread(&obj, tamRegistro, 1, archivo);
    fclose(archivo);
    return obj;
}


int ArchivoVehiculo::BuscarVehiculoPorPatente(const char* PatenteBuscar) {
    Vehiculo obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (!p) return -1;

    int pos = 0;
    while (fread(&obj, tamRegistro, 1, p)) {
        if (strcmp(obj.getPatente(), PatenteBuscar) == 0 && obj.getEstado()) { // Solo activos
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1; // No encontrado
}



void ArchivoVehiculo::listarPatentesDisponibles() {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de vehiculos." << endl;
        return;
    }

    Vehiculo obj;
    bool hayPatentes = false;
    cout << "=== Vehiculos Disponibles ===" << endl;
    while (fread(&obj, tamRegistro, 1, archivo)) {
        if (obj.getEstado()) {
            cout << "Patente: " << obj.getPatente() << endl;
            cout << "Marca: " << obj.getMarca() << endl;
            cout << "Modelo: " << obj.getModelo() << endl;
            cout << "Anio: " << obj.getAnio() << endl;
            cout << "Falla: " << obj.getFalla() << endl;
            cout << "-----------------------------" << endl;
            hayPatentes = true;
        }
    }
    fclose(archivo);

    if (!hayPatentes) {
        cout << "No hay vehiculos activos cargados." << endl;
    }
}

