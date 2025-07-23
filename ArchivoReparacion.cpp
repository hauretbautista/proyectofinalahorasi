#include <iostream>
#include <cstring>
#include "ArchivoReparacion.h"

using namespace std;

ArchivoReparacion::ArchivoReparacion(const char* nombre) {
    strcpy(nombreArchivo, nombre);
    tamRegistro = sizeof(Reparacion);
}

bool ArchivoReparacion::generarNuevo() {
    FILE* archivo = fopen(nombreArchivo, "wb");
    if (archivo == nullptr) {
        cout << "Error: No se pudo crear el archivo " << nombreArchivo << endl;
        return false;
    }
    fclose(archivo);
    cout << "Archivo " << nombreArchivo << " creado exitosamente." << endl;
    return true;
}

int ArchivoReparacion::agregarRegistro(const Reparacion r) {
    FILE* archivo = fopen(nombreArchivo, "ab");
    if (archivo == nullptr) {
        cout << "Error: No se pudo abrir el archivo para escritura." << endl;
        return -1;
    }

    int resultado = fwrite(&r, tamRegistro, 1, archivo);
    fclose(archivo);

    if (resultado == 1) {
        cout << "Reparacion agregada exitosamente!" << endl;
        return 0; // exito
    } else {
        cout << "Error: No se pudo guardar la reparacion." << endl;
        return -1; // Error
    }
}

bool ArchivoReparacion::listarRegistros() {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == nullptr) {
        cout << "Error: No se pudo abrir el archivo para lectura." << endl;
        return false;
    }

    Reparacion reparacion;
    int contador = 0;

    cout << "\n=== LISTADO DE REPARACIONES ===" << endl;
    cout << "===============================" << endl;

    while (fread(&reparacion, tamRegistro, 1, archivo) == 1) {
        cout << "\n--- Reparacion #" << (contador + 1) << " ---" << endl;
        reparacion.mostrarReparacion();
        contador++;
    }

    fclose(archivo);

    if (contador == 0) {
        cout << "No hay reparaciones registradas." << endl;
        return false;
    } else {
        cout << "\nTotal de reparaciones: " << contador << endl;
        return true;
    }
}

int ArchivoReparacion::buscarReparacion(int id) {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == nullptr) {
        cout << "Error: No se pudo abrir el archivo para lectura." << endl;
        return -1;
    }

    Reparacion reparacion;
    int posicion = 0;

    while (fread(&reparacion, tamRegistro, 1, archivo) == 1) {
        if (reparacion.getIDReparacion() == id) {
            fclose(archivo);
            return posicion;
        }
        posicion++;
    }

    fclose(archivo);
    return -1; // No encontrado
}

Reparacion ArchivoReparacion::leerRegistro(int pos) {
    Reparacion reparacion;

    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == nullptr) {
        cout << "Error: No se pudo abrir el archivo para lectura." << endl;
        return reparacion;
    }

    if (fseek(archivo, pos * tamRegistro, SEEK_SET) != 0) {
        cout << "Error: No se pudo acceder a la posicion especificada." << endl;
        fclose(archivo);
        return reparacion;
    }

    // Lee el registro
    if (fread(&reparacion, tamRegistro, 1, archivo) != 1) {
        cout << "Error: No se pudo leer el registro." << endl;
    }

    fclose(archivo);
    return reparacion;
}

int ArchivoReparacion::modificarRegistro(const Reparacion r, int pos) {
    FILE* archivo = fopen(nombreArchivo, "r+b");
    if (archivo == nullptr) {
        cout << "Error: No se pudo abrir el archivo para modificacion." << endl;
        return -1;
    }

    if (fseek(archivo, pos * tamRegistro, SEEK_SET) != 0) {
        cout << "Error: No se pudo acceder a la posicion especificada." << endl;
        fclose(archivo);
        return -1;
    }

    // Escribe el registro modificado
    int resultado = fwrite(&r, tamRegistro, 1, archivo);
    fclose(archivo);

    if (resultado == 1) {
        cout << "Reparacion modificada exitosamente!" << endl;
        return 0; // Éxito
    } else {
        cout << "Error: No se pudo modificar la reparacion." << endl;
        return -1; // Error
    }
}

int ArchivoReparacion::contarRegistros() {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == nullptr) {
        return 0;
    }

    fseek(archivo, 0, SEEK_END);
    long tamanioArchivo = ftell(archivo);
    fclose(archivo);

    return tamanioArchivo / tamRegistro;
}



bool ArchivoReparacion::existeReparacion(int id) {
    return buscarReparacion(id) != -1;
}

int ArchivoReparacion::obtenerProximoID() {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == nullptr) {
        return 1;
    }

    Reparacion reparacion;
    int maxID = 0;

    while (fread(&reparacion, tamRegistro, 1, archivo) == 1) {
        if (reparacion.getIDReparacion() > maxID) {
            maxID = reparacion.getIDReparacion();
        }
    }

    fclose(archivo);
    return maxID + 1;
}

bool ArchivoReparacion::listarReparacionesPorCliente(int idCliente) {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == nullptr) {
        cout << "Error: No se pudo abrir el archivo para lectura." << endl;
        return false;
    }

    Reparacion reparacion;
    int contador = 0;

    cout << "\n=== REPARACIONES DEL CLIENTE ID: " << idCliente << " ===" << endl;
    cout << "================================================" << endl;

    while (fread(&reparacion, tamRegistro, 1, archivo) == 1) {
        if (reparacion.getIDCliente() == idCliente) {
            cout << "\n--- Reparacion #" << (contador + 1) << " ---" << endl;
            reparacion.mostrarReparacion();
            contador++;
        }
    }

    fclose(archivo);

    if (contador == 0) {
        cout << "No hay reparaciones registradas para este cliente." << endl;
        return false;
    } else {
        cout << "\nTotal de reparaciones del cliente: " << contador << endl;
        return true;
    }
}

bool ArchivoReparacion::listarReparacionesPorEstado(int estado) {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == nullptr) {
        cout << "Error: No se pudo abrir el archivo para lectura." << endl;
        return false;
    }

    Reparacion reparacion;
    int contador = 0;

    const char* estadoTexto;
    switch (estado) {
        case 1: estadoTexto = "PENDIENTES"; break;
        case 2: estadoTexto = "EN CURSO"; break;
        case 3: estadoTexto = "FINALIZADAS"; break;
        default: estadoTexto = "DESCONOCIDO"; break;
    }

    cout << "\n=== REPARACIONES " << estadoTexto << " ===" << endl;
    cout << "================================" << endl;

    while (fread(&reparacion, tamRegistro, 1, archivo) == 1) {
        if (reparacion.getEstado() == estado) {
            cout << "\n--- Reparacion #" << (contador + 1) << " ---" << endl;
            reparacion.mostrarReparacion();
            contador++;
        }
    }

    fclose(archivo);

    if (contador == 0) {
        cout << "No hay reparaciones " << estadoTexto << "." << endl;
        return false;
    } else {
        cout << "\nTotal de reparaciones " << estadoTexto << ": " << contador << endl;
        return true;
    }
}

bool ArchivoReparacion::listarReparacionesPendientesPago() {
    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == nullptr) {
        cout << "Error: No se pudo abrir el archivo para lectura." << endl;
        return false;
    }

    Reparacion reparacion;
    int contador = 0;
    float totalPendiente = 0;

    cout << "\n=== REPARACIONES PENDIENTES DE PAGO ===" << endl;
    cout << "=======================================" << endl;

    while (fread(&reparacion, tamRegistro, 1, archivo) == 1) {
        if (!reparacion.estaPagado()) {
            cout << "\n--- Reparacion #" << (contador + 1) << " ---" << endl;
            reparacion.mostrarReparacion();
            totalPendiente += reparacion.getImporte();
            contador++;
        }
    }

    fclose(archivo);

    if (contador == 0) {
        cout << "No hay reparaciones pendientes de pago." << endl;
        return false;
    } else {
        cout << "\nTotal de reparaciones pendientes: " << contador << endl;
        cout << "Importe total pendiente: $" << totalPendiente << endl;
        return true;
    }
}
