#include <iostream>
#include <cstdlib>
#include "Cliente.h"
#include "ArchivoCliente.h"
#include "Reparacion.h"
#include "ArchivoReparacion.h"
#include "ArchivoEmpleado.h"
#include "Factura.h"
#include "Informes.h"
#include "ArchivoVehiculo.h"
#include "BackUp.h"
using namespace std;

void menuPrincipal();
void menuEmpleado();
void menuClientes();
void menuReparaciones();
void menuFacturas();
void menuListados();
void menuInformes();
void pausar();
void limpiarPantalla();
void menuVehiculo ();
void mostrarMenuInformes();

ArchivoVehiculo ArchivoVehiculo;
ArchivoEmpleado ArchivoEmpleado;
ArchivoCliente archivoClientes;
ArchivoReparacion archivoReparaciones;
Informes informes;

int main() {

    cout << "========================================" << endl;
    cout << "    SISTEMA DE GESTION DE TALLER       " << endl;
    cout << "          MECANICO - V1.0              " << endl;
    cout << "========================================" << endl;
    system ("pause");
    menuPrincipal();

    cout << "\nGracias por usar el Sistema de Gestion de Taller!" << endl;
   return 0;
}

void menuPrincipal() {
    int opcion;

    do {
        limpiarPantalla();
        cout << "========== MENU PRINCIPAL ==========" << endl;
        cout << "1. Gestion de Clientes" << endl;
        cout << "2. Gestion de Reparaciones" << endl;
        cout << "3. Gestion de Facturas" << endl;
        cout << "4. Gestion de Empleados" << endl;
        cout << "5. Gestion de Informes"<<endl;
        cout << "6. Gestion de Vehiculos"<< endl;
        cout << "7. Gestion de BackUps"<< endl;
        cout << "0. Salir" << endl;
        cout << "====================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuReparaciones();
                break;
            case 3:
                menuFacturas();
                break;
            case 4:
                menuEmpleado();
                break;
            case 5: {
               mostrarMenuInformes();
                break;
            }
            break;
           case 6:
            menuVehiculo();
            break;
           case 7:
            menuBackup ();
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}

void menuClientes() {
    int opcion;

    do {
        limpiarPantalla();
        cout << "========== GESTION DE CLIENTES ==========" << endl;
        cout << "1. Agregar Cliente" << endl;
        cout << "2. Mostrar Cliente" << endl;
        cout << "3. Modificar Cliente" << endl;
        cout << "4. Mostrar Cliente por ID" << endl;
        cout << "5. Eliminar Cliente" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n=== AGREGAR CLIENTE ===" << endl;
                system ("cls");
                archivoClientes.AgregarCliente();
                pausar();
                break;
            case 2:
                cout << "\n=== MOSTRAR CLIENTE ===" << endl;
                archivoClientes.MostrarCliente();
                pausar();
                break;
            case 3:
                cout << "\n=== MODIFICAR CLIENTE ===" << endl;
                archivoClientes.ModificarCliente();
                pausar();
                break;
            case 4:
                cout << "\n=== MOSTRAR CLIENTE POR ID ===" << endl;
                archivoClientes.MostrarClientePorID();
                pausar();
                break;
            case 5:
                cout << "\n=== ELIMINAR CLIENTE ===" << endl;
                archivoClientes.EliminarCliente();
                pausar();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}

void menuReparaciones() {
    int opcion;

    do {
        limpiarPantalla();
        cout << "======== GESTION DE REPARACIONES ========" << endl;
        cout << "1. Agregar Reparacion" << endl;
        cout << "2. Listar Todas las Reparaciones" << endl;
        cout << "3. Buscar Reparacion por ID" << endl;
        cout << "4. Modificar Estado de Reparacion" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
                       case 1: {
                cin.ignore();
                Reparacion reparacion;
                if (!reparacion.cargarReparacion()) {
                    pausar();
                    break;
                }

                int nuevoID = archivoReparaciones.obtenerProximoID();
                reparacion.setIDReparacion(nuevoID);

                if (archivoReparaciones.agregarRegistro(reparacion) != -1) {
                    cout << "Reparacion agregada exitosamente!" << endl;
                } else {
                    cout << "Error al agregar la reparacion." << endl;
                }
                pausar();
                break;
            }
            case 2:
                cout << "\n=== LISTAR REPARACIONES ===" << endl;
                archivoReparaciones.listarRegistros();
                pausar();
                break;
            case 3: {
                cout << "\n=== BUSCAR REPARACION ===" << endl;
                int id;
                cout << "Ingrese ID de la reparacion: ";
                cin >> id;

                int pos = archivoReparaciones.buscarReparacion(id);
                if (pos != -1) {
                    Reparacion rep = archivoReparaciones.leerRegistro(pos);
                    rep.mostrarReparacion();
                } else {
                    cout << "Reparacion no encontrada." << endl;
                }
                pausar();
                break;
            }
            case 4: {
                cout << "\n=== MODIFICAR ESTADO ===" << endl;
                int id, nuevoEstado;
                cout << "Ingrese ID de la reparacion: ";
                cin >> id;

                int pos = archivoReparaciones.buscarReparacion(id);
                if (pos != -1) {
                    Reparacion rep = archivoReparaciones.leerRegistro(pos);
                    rep.mostrarReparacion();

                    cout << "Nuevo estado (1-Pendiente, 2-En curso, 3-Finalizada): ";
                    cin >> nuevoEstado;

                    rep.setEstado(nuevoEstado);
                    if (archivoReparaciones.modificarRegistro(rep, pos) != -1) {


                        if (nuevoEstado == 3) {
                            char pagarAhora;
                            cout << "¿Desea marcar como pagado? (s/n): ";
                            cin >> pagarAhora;

                            if (pagarAhora == 's' || pagarAhora == 'S') {
                                rep.setPagado(true);
                                archivoReparaciones.modificarRegistro(rep, pos);

                                Factura factura;

                                cout << "Ingrese numero de factura: ";
                                cin >> factura.NFactura;

                                factura.NReparacion = rep.getIDReparacion();
                                factura.Importe = rep.getImporte();
                                factura.FechaEntrega = rep.getFechaEntrega();
                                strcpy(factura.NPatente, rep.getPatente());
                                factura.IDCliente = rep.getIDCliente();
                                factura.ImporteTotal = rep.getImporte();

                                FILE* archivo = fopen("facturas.dat", "ab");
                                if (archivo != NULL) {
                                    fwrite(&factura, sizeof(Factura), 1, archivo);
                                    fclose(archivo);
                                    cout << "\n¡Factura generada automáticamente!" << endl;
                                    cout << "Número de factura: " << factura.NFactura << endl;
                                } else {
                                    cout << "Error al generar la factura." << endl;
                                }
                            }
                        }
                    } else {
                        cout << "Error al actualizar el estado." << endl;
                    }
                } else {
                    cout << "Reparacion no encontrada." << endl;
                }
                pausar();
                break;
            }

            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}
void menuFacturas() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "========== GESTION DE FACTURAS ==========" << endl;
        cout << "1. Mostrar Factura por Numero" << endl;
        cout << "2. Mostrar Todas las Facturas" << endl;
        cout << "3. Mostrar Ultima Factura"<< endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1: {
                cout << "\n=== BUSCAR FACTURA POR NUMERO ===" << endl;
                Factura factura;
                factura.mostrarFactura();
                pausar();
                break;
            }
            case 2: {
                cout << "\n=== TODAS LAS FACTURAS ===" << endl;
                Factura factura;
                factura.mostrarTodasLasFacturas();
                pausar();
                break;
            }
            case 3: {
                Factura factura;
                factura.mostrarUltimaFactura ();
                pausar ();
            }
              case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}

void menuEmpleado () {
    int opcion, id;

    while (true) {
        system("cls");

        cout << "\n=== MENU EMPLEADO ===" << endl;
        cout << "1. Agregar Empleado" << endl;
        cout << "2. Listar Empleados" << endl;
        cout << "3. Modificar Empleado" << endl;
        cout << "4. Eliminar Empleados" << endl;
        cout << "5. Mostrar Empleado por ID"<< endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion) {
            case 1:
                cout << "\n=== GENERAR EMPLEADO ===" << endl;
                if (ArchivoEmpleado.agregarRegistro() == 1) {
                    cout << "Empleado agregado correctamente (ID asignado automaticamente)." << endl;
                } else {
                    cout << "Error al agregar empleado." << endl;
                }
                cout << endl;
                system("pause");
                break;
            case 2:
                cout << "\n=== MOSTRAR EMPLEADOS ===" << endl;
                ArchivoEmpleado.listarRegistros();
                cout << endl;
                system("pause");
                break;
            case 3:
                cout << "\n=== MODIFICAR EMPLEADO ===" << endl;
                cout << "Ingrese ID de empleado a modificar: ";
                cin >> id;
                if (ArchivoEmpleado.modificarEmpleado(id)) {
                    cout << "Empleado modificado correctamente." << endl;
                } else {
                    cout << "No se encontro el empleado o esta dado de baja." << endl;
                }
                system("pause");
                break;
            case 4:
                cout << "\n=== ELIMINAR EMPLEADO ===" << endl;
                cout << "Ingrese ID de empleado a dar de baja: ";
                cin >> id;
                if (ArchivoEmpleado.bajaEmpleado(id)) {
                    cout << "Empleado dado de baja correctamente." << endl;
                } else {
                    cout << "No se encontro el empleado o ya esta dado de baja." << endl;
                }
                system("pause");
                break;
            case 5:
                cout << "\n=== BUSCAR EMPLEADO POR ID ===" << endl;
                cout << "Ingrese el ID de empleado a buscar: ";
                cin >> id;
                ArchivoEmpleado.mostrarEmpleadoPorID(id);
                cout << endl;
                system("pause");
                break;
            case 0:
                return;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                system("pause");
        }
    }
}

void menuVehiculo () {


    int opcion;
    char patente [10];
    while (true) {
        system("cls");
        cout << "\n=== MENU VEHICULOS===" << endl;
        cout << "1. Agregar Vehiculos" << endl;
        cout << "2. Listar Vehiculos" << endl;
        cout << "3. Buscar Vehiculo por Patente" << endl;
        cout << "4. Modificar Vehiculo" << endl;
        cout << "5. Eliminar Vehiculo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                cout << "\n=== CARGAR VEHICULO ===" << endl;
                if (ArchivoVehiculo.AgregarRegistro() == 1) {
                    cout << "Vehiculo agregado correctamente. " << endl;
                } else {
                    cout << "Error al agregar Vehiculo." << endl;
                }
                cout << endl;
                system("pause");
                break;
            }
            case 2: {
                cout << "\n=== MOSTRAR VEHICULOS ===" << endl;
                ArchivoVehiculo.listarRegistros ();
                cout << endl;
                system("pause");
                break;
            }
        case 3: {
                char PatenteBuscar[30];
                cout << "Ingrese la patente para buscar el vehiculo: ";
                cin.ignore();
                cin.getline(PatenteBuscar, 30);
                int pos = ArchivoVehiculo.BuscarVehiculoPorPatente(PatenteBuscar);
                if (pos >= 0) {
                    Vehiculo v = ArchivoVehiculo.LeerRegistro(pos);
                    v.mostrarVehiculo();
                } else {
                    cout << "No se encontro vehiculo con la patente ingresada." << endl;
                }
                cout << endl;
                system("pause");
                break;
            }
           case 4: {
                cout << "\n=== MODIFICAR VEHICULO ===" << endl;
                cout << "Ingrese la Patente del vehiculo a modificar: ";
                cin >> patente;
                int pos = ArchivoVehiculo.BuscarVehiculo(patente);
                if (pos == -1) {
                    cout << "No se encontro el vehiculo o esta dado de baja." << endl;
                } else {
                    Vehiculo v = ArchivoVehiculo.LeerRegistro(pos);
                    v.mostrarVehiculo();
                    cout << "\nIngrese los nuevos datos (deje en blanco para no modificar):" << endl;
                    v.ModificarVehiculo();
                    if (ArchivoVehiculo.ModificarRegistro(v, pos) == 1) {
                        cout << "Vehiculo modificado correctamente." << endl;
                    } else {
                        cout << "Error al modificar el vehiculo." << endl;
                    }
                }
                system("pause");
                break;
            }
            case 5: {
                cout << "\n=== ELIMINAR VEHICULO ===" << endl;
                cout << "Ingrese la patente del vehiculo a dar de baja: ";
                cin >> patente;
                if (ArchivoVehiculo.bajaVehiculo(patente)) {
                    cout << "Vehiculo dado de baja correctamente." << endl;
                } else {
                    cout << "No se encontro el vehiculo o ya esta dado de baja." << endl;
                }
                system("pause");
                break;
            }
            case 0:
                return;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                system("pause");
        }
    }
}

 void mostrarMenuInformes(){
     int opcion;
    do {
        cout << "\n===== INFORMES =====" << endl;
        cout << "1. Recaudacion Mensual" << endl;
        cout << "2. Recaudacion Anual" << endl;
        cout << "3. Recaudacion por Cliente" << endl;
        cout << "4. Reparaciones por Vehiculo" << endl;
        cout << "5. Reparaciones por Empleado" << endl;
        cout << "6. Vehiculo Mas Reparado" << endl;
        cout << "7. Reparaciones por Estado" << endl;
        cout << "0. Volver al Menu Principal" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: informes.recaudacionMensual(); break;
            case 2: informes.recaudacionAnual(); break;
            case 3: informes.recaudacionPorCliente(); break;
            case 4: informes.reparacionesPorVehiculo(); break;
            case 5: informes.reparacionesPorEmpleado(); break;
            case 6: informes.vehiculoMasReparado(); break;
            case 7: informes.reparacionesPorEstado(); break;
            case 0: break;
            default: cout << "Opcion invalida." << endl;
        }

        if (opcion != 0) {
            cout << "\nEnter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcion != 0);
    }
void pausar() {
    cout << "\nPresione enter para continuar...";
    cin.ignore();
    cin.get();
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
