#ifndef BACKUP_H_INCLUDED
#define BACKUP_H_INCLUDED

void backupArchivo(const char* origen, const char* destino);
void menuBackup();

void mostrarEmpleados(const char* nombreArchivo);
void mostrarClientes(const char* nombreArchivo);
void mostrarReparaciones(const char* nombreArchivo);
void mostrarVehiculos(const char* nombreArchivo);

#endif // BACKUP_H_INCLUDED
