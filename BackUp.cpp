#include "Backup.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include "ArchivoEmpleado.h"
#include "ArchivoCliente.h"
#include "ArchivoReparacion.h"
#include "ArchivoVehiculo.h"
using namespace std;

// CREA BACKUP DE ARCHIVO
void backupArchivo(const char* origen, const char* destino) {
    FILE* f1 = fopen(origen, "rb");
    if (!f1) {
        cout << "No se pudo abrir el archivo de origen: " << origen << endl;
        return;
    }
    FILE* f2 = fopen(destino, "wb");
    if (!f2) {
        cout << "No se pudo crear el archivo de backup: " << destino << endl;
        fclose(f1);
        return;
    }
    char datosLeidos[4096];
    int cantidadLeida;

    while ((cantidadLeida = fread(datosLeidos, 1, sizeof(datosLeidos), f1)) > 0) {
        fwrite(datosLeidos, 1, cantidadLeida, f2);
    }
    fclose(f1);
    fclose(f2);
    cout << "Backup realizado: " << destino << endl;
}

void menuBackup() {
    int opcion;
    do {
        system("cls");
        cout << "\n=== MENU DE BACKUP ===" << endl;
        cout << "1. Backup empleados.dat" << endl;
        cout << "2. Backup clientes.dat" << endl;
        cout << "3. Backup reparaciones.dat" << endl;
        cout << "4. Backup vehiculos.dat" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                backupArchivo("empleados.dat", "empleados.bak");
                cout << "\n--- Contenido del backup empleados ---\n";
                {
                    ArchivoEmpleado archivoBackup("empleados.bak");
                    archivoBackup.listarRegistros();
                 cout << endl;
                }
                break;
            case 2:
                backupArchivo("clientes.dat", "clientes.bak");
                cout << "\n--- Contenido del backup clientes ---\n";
                {
                    ArchivoCliente archivoBackup("clientes.bak");
                    archivoBackup.MostrarCliente();
                    cout << endl;
                }
                break;
            case 3:
                backupArchivo("reparaciones.dat", "reparaciones.bak");
                cout << "\n--- Contenido del backup reparaciones ---\n";
                {
                    ArchivoReparacion archivoBackup("reparaciones.bak");
                    archivoBackup.listarRegistros();
                    cout << endl;
                }
                break;
            case 4:
                backupArchivo("vehiculos.dat", "vehiculos.bak");
                cout << "\n--- Contenido del backup vehiculos ---\n";
                {
                    ArchivoVehiculo archivoBackup("vehiculos.bak");
                    archivoBackup.listarRegistros();
                    cout << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        if (opcion != 0) {
            system("pause");
        }
    } while (opcion != 0);
}
