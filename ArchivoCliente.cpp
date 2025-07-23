#include <iostream>
#include <cstring>
#include "ArchivoCliente.h"

using namespace std;

ArchivoCliente::ArchivoCliente(const char* nombre) {
    strcpy(NombreArchivo, nombre);
    TamRegistro = sizeof(Cliente);
}

int ArchivoCliente::ObtenerProximoID() {
    FILE* archivo = fopen(NombreArchivo, "rb");
    if (!archivo) return 1;

    Cliente cliente;
    int maxID = 0;

    while (fread(&cliente, TamRegistro, 1, archivo) == 1) {
        if (cliente.getIDCliente() > maxID) {
            maxID = cliente.getIDCliente();
        }
    }

    fclose(archivo);
    return maxID + 1;
}

bool ArchivoCliente::GenerarNuevo() {
    FILE* archivo = fopen(NombreArchivo, "wb");
    if (!archivo) {
        cout << "Error al crear archivo" << endl;
        return false;
    }
    fclose(archivo);
    cout << "Archivo creado exitosamente" << endl;
    return true;
}

void ArchivoCliente::AgregarCliente() {
    Cliente cliente;
    cliente.cargarCliente();
    cliente.setIDCliente(ObtenerProximoID());

    FILE* archivo = fopen(NombreArchivo, "ab");
    if (!archivo) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    if (fwrite(&cliente, TamRegistro, 1, archivo) == 1) {
        cout << "Cliente agregado! ID: " << cliente.getIDCliente() << endl;
    } else {
        cout << "Error al guardar cliente" << endl;
    }
    fclose(archivo);
}

void ArchivoCliente::MostrarClientePorID() {
    int id;
    cout << "Ingrese ID del cliente a mostrar: ";
    cin >> id;

    FILE* archivo = fopen(NombreArchivo, "rb");
    if (!archivo) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    Cliente cliente;
    bool encontrado = false;

    while (fread(&cliente, TamRegistro, 1, archivo) == 1) {
        if (cliente.getIDCliente() == id && cliente.getEstado()) {
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        cout << "\n========================================" << endl;
        cout << "           DATOS DEL CLIENTE" << endl;
        cout << "========================================" << endl;
        cliente.mostrarCliente();
        cout << "========================================\n" << endl;
    } else {
        cout << "Cliente con ID " << id << " no encontrado o inactivo" << endl;
    }

    fclose(archivo);
}

void ArchivoCliente::MostrarCliente() {
    FILE* archivo = fopen(NombreArchivo, "rb");
    if (!archivo) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    Cliente cliente;
    int contador = 0;

    cout << "\n========================================" << endl;
    cout << "           LISTA DE CLIENTES" << endl;
    cout << "========================================" << endl;

    while (fread(&cliente, TamRegistro, 1, archivo) == 1) {
        if (cliente.getEstado()) {
            contador++;
            cout << "\nCliente #" << contador << ":" << endl;
            cout << "----------------------------------------" << endl;
            cliente.mostrarCliente();
        }
    }

    cout << "\n========================================" << endl;
    if (contador == 0) {
        cout << "     No hay clientes registrados" << endl;
    } else {
        cout << "     Total de clientes: " << contador << endl;
    }
    cout << "========================================\n" << endl;

    fclose(archivo);
}


void ArchivoCliente::ModificarCliente() {
    int id;
    cout << "Ingrese ID del cliente a modificar: ";
    cin >> id;

    FILE* archivo = fopen(NombreArchivo, "r+b");
    if (archivo == nullptr) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    Cliente cliente;
    bool encontrado = false;
    long posicion = 0;

    while (fread(&cliente, TamRegistro, 1, archivo) == 1) {
        if (cliente.getIDCliente() == id && cliente.getEstado()) {
            encontrado = true;
            break;
        }
        posicion = ftell(archivo); // LÍNEA MOVIDA AQUÍ - DESPUÉS DEL IF
    }

    if (!encontrado) {
        cout << "Cliente no encontrado o inactivo." << endl;
        fclose(archivo);
        return;
    }

    cout << "Cliente encontrado:" << endl;
    cliente.mostrarCliente();

    char confirma;
    cout << "Desea modificar este cliente? (s/n): ";
    cin >> confirma;

    if (confirma == 's' || confirma == 'S') {
        cliente.actualizarCliente();
        fseek(archivo, posicion, SEEK_SET);

        int resultado = fwrite(&cliente, TamRegistro, 1, archivo);

        if (resultado == 1) {
            cout << "Cliente modificado exitosamente!" << endl;
        } else {
            cout << "Error: No se pudo modificar el cliente." << endl;
        }
    }

    fclose(archivo);
}

void ArchivoCliente::EliminarCliente() {
    int id;
    cout << "ID del cliente a eliminar: ";
    cin >> id;

    FILE* archivo = fopen(NombreArchivo, "r+b");
    if (!archivo) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    Cliente cliente;
    bool encontrado = false;
    long pos = 0;

    while (fread(&cliente, TamRegistro, 1, archivo) == 1) {
        pos = ftell(archivo); // MOVER ESTA LÍNEA AQUÍ
        if (cliente.getIDCliente() == id && cliente.getEstado()) {
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Cliente no encontrado" << endl;
        fclose(archivo);
        return;
    }

    cout << "Cliente a eliminar:" << endl;
    cliente.mostrarCliente();

    char confirma;
    cout << "¿Está seguro que desea eliminar este cliente? (s/n): ";
    cin >> confirma;

    if (confirma == 's' || confirma == 'S') {
        cliente.eliminarCliente(); // Cambia estado a false

        // POSICIONARSE CORRECTAMENTE EN EL ARCHIVO
        fseek(archivo, pos - TamRegistro, SEEK_SET);

        if (fwrite(&cliente, TamRegistro, 1, archivo) == 1) {
            cout << "Cliente eliminado exitosamente" << endl;
        } else {
            cout << "Error al eliminar cliente" << endl;
        }
    }

    fclose(archivo);
}


bool ArchivoCliente::ExisteCliente(int id) {
    FILE* archivo = fopen(NombreArchivo, "rb");
    if (!archivo) return false;
    Cliente cliente;
    while (fread(&cliente, TamRegistro, 1, archivo) == 1) {
        if (cliente.getIDCliente() == id && cliente.getEstado()) {
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}
