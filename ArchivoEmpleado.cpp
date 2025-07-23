#include <iostream>
#include "Empleado.h"
#include "ArchivoEmpleado.h"
#include "Persona.h"
#include <cstring>

using namespace std;

//ABML : AGREGAR
int ArchivoEmpleado::agregarRegistro() {
    Empleado obj;
    obj.cargarEmpleado();

    int nuevoID = obtenerSiguienteId();
    obj.setIDEmpleado(nuevoID);

    FILE* pEmpleado = fopen(nombreArchivo, "ab");
    if (!pEmpleado) return -1;

    int escribio = fwrite(&obj, tamRegistro, 1, pEmpleado);
    fclose(pEmpleado);
    return escribio;
}


//FUNCION GENERAL PARA BUSCAR Y UBICAR REGISTRO EN ESPECIFICO
int ArchivoEmpleado::buscarEmpleado(int idEmpleado) {
    Empleado obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (!p) return -1;

    int pos = 0;
    while (fread(&obj, tamRegistro, 1, p)) {
        if (obj.getIDEmpleado() == idEmpleado && obj.estaActivo()) {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose (p);
    return -1;
}


//ABML: LISTAR
Empleado ArchivoEmpleado::leerRegistro (int pos) {
  Empleado obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (!p) return obj;

    fseek(p, pos * tamRegistro, SEEK_SET);
    fread(&obj, tamRegistro, 1, p);
    fclose(p);

    return obj;

}

// ABML: BAJA
bool ArchivoEmpleado::bajaEmpleado(int idEmpleado) {
    int pos = buscarEmpleado(idEmpleado);
    if (pos < 0) {
        return false;
    }
    Empleado obj = leerRegistro(pos);

    obj.eliminarEmpleado();

    FILE* p = fopen(nombreArchivo, "rb+");
    if (!p) return false;

    fseek(p, pos * tamRegistro, SEEK_SET);
    int escribio = fwrite(&obj, tamRegistro, 1, p);
    fclose(p);

    return (escribio == 1);
}

//ABML: MODIFICAR
bool ArchivoEmpleado::modificarEmpleado(int idEmpleado) {
    int pos = buscarEmpleado(idEmpleado);
    if (pos < 0) return false;


    Empleado obj = leerRegistro(pos);
    cout << "Datos actuales del empleado: ";
    obj.mostrarEmpleado();

    cout << " --- Actualizar campos --- ";
    obj.actualizarEmpleado();


    FILE* p = fopen(nombreArchivo, "rb+");
    if (!p) return false;
    fseek(p, pos * tamRegistro, SEEK_SET);
    int wrote = fwrite(&obj, tamRegistro, 1, p);
    fclose(p);

    return (wrote == 1);
}


//ABML: LISTAR
bool ArchivoEmpleado::listarRegistros () {
    Empleado obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (!p) {
        cout << "No se pudo abrir el archivo de empleados. ";
        return false;
    }

    while (fread(&obj, tamRegistro, 1, p)) {
        if (obj.estaActivo()) {
            obj.mostrarEmpleado();
            cout << "------------------------";
        }
    }

    fclose(p);

  return true;
}


// ID AUTOINCREMENTABLE
int ArchivoEmpleado::obtenerSiguienteId() {
Empleado obj;
FILE* p = fopen (nombreArchivo, "rb");
if (!p) return 1;
    int maxID = 0;
    while (fread(&obj, tamRegistro, 1, p)) {
        if (obj.getIDEmpleado() > maxID) {
            maxID = obj.getIDEmpleado();
        }
    }
    fclose(p);
    return maxID + 1;
}

// BUSCAR  EMPLEADO POR ID
void ArchivoEmpleado::mostrarEmpleadoPorID(int idEmpleado) {
    int pos = buscarEmpleado(idEmpleado);
    if (pos < 0) {
        cout << "No se encontro un empleado con ese ID." << endl;
        return;
    }
    Empleado obj = leerRegistro(pos);
    obj.mostrarEmpleado();
}


void ArchivoEmpleado::listarEmpleadosDisponibles() {
    Empleado obj;
    FILE* p = fopen(nombreArchivo, "rb");
    if (!p) {
        std::cout << "No se pudo abrir el archivo de empleados." << std::endl;
        return;
    }

    bool hayEmpleados = false;
    std::cout << "\n=== EMPLEADOS DISPONIBLES ===" << std::endl;
    while (fread(&obj, tamRegistro, 1, p)) {
        if (obj.estaActivo()) {
            obj.mostrarEmpleado();
            std::cout << "------------------------" << std::endl;
            hayEmpleados = true;
        }
    }

    fclose(p);

    if (!hayEmpleados) {
        std::cout << "No hay empleados activos cargados." << std::endl;
    }
}
