#include <iostream>
#include <cstring>
#include "Cliente.h"

using namespace std;

// Constructor por defecto
Cliente::Cliente() : Persona() {
    IDCliente = 0;
    strcpy(CUIT, "");
    strcpy(Email, "");
    TipoCliente = 1;
    strcpy(Direccion, "");
    estado = true;
}

// Constructor parametrizado
Cliente::Cliente(const char* nom, const char* ape, int dni, int tel, int idCliente,
                 const char* cuit, const char* email, int tipo, const char* dir, bool est)
    : Persona(nom, ape, dni, tel) {
    IDCliente = idCliente;
    strcpy(CUIT, cuit);
    strcpy(Email, email);
    TipoCliente = tipo;
    strcpy(Direccion, dir);
    estado = est;
}

void Cliente::cargarCliente() {
    char nombre[50], apellido[50], email[50], cuit[15], direccion[100];
    int dni, telefono, tipo;

    cout << "=== CARGAR CLIENTE ===" << endl;

    cout << "Ingrese el nombre: ";
    cin >> nombre;
    setNombre(nombre);

    cout << "Ingrese el apellido: ";
    cin >> apellido;
    setApellido(apellido);

    cout << "Ingrese DNI: ";
    cin >> dni;
    setDNI(dni);

    cout << "Ingrese teléfono: ";
    cin >> telefono;
    setTelefono(telefono);

    cout << "Ingrese email: ";
    cin >> email;
    setEmail(email);

    cout << "Ingrese tipo (1-Particular, 2-Empresa): ";
    cin >> tipo;
    setTipoCliente(tipo);

    cout << "Ingrese CUIT: ";
    cin >> cuit;
    setCUIT(cuit);

    cout << "Ingrese dirección: ";
    cin >> direccion;
    setDireccion(direccion);

    setEstado(true);
}

void Cliente::mostrarCliente() const {
    cout << "ID: " << getIDCliente () << endl;
    mostrarDatosPersona();
    cout << "EMAIL: " <<getEstado ()<< endl;
    cout << "CUIT: " << (CUIT[0] != '\0' ? CUIT : "No especificado") << endl;
    cout << "TIPO: " << getTipoClienteTexto() << endl;
    cout << "DIRECCION: " << getDireccion() << endl;
    cout << "ESTADO: " << (getEstado () ? "ACTIVO" : "INACTIVO") << endl;
}


void Cliente::actualizarCliente() {
    int opcion;
    char nuevoTexto[100];
    char nuevoCUIT[15];
    int nuevoTelefono, nuevoTipo;
    bool editar = true;

    while (editar) {
        cout << "\n=== ACTUALIZAR CLIENTE ===" << endl;
        cout << "1. Editar nombre (actual: " << getNombre() << ")" << endl;
        cout << "2. Editar apellido (actual: " << getApellido() << ")" << endl;
        cout << "3. Editar teléfono (actual: " << getTelefono() << ")" << endl;
        cout << "4. Editar email (actual: " << getEmail() << ")" << endl;
        cout << "5. Editar direccion (actual: " << getDireccion() << ")" << endl;
        cout << "6. Editar CUIT (actual: " << getCUIT() << ")" << endl;
        cout << "7. Cambiar tipo de cliente (actual: " << getTipoClienteTexto() << ")" << endl;
        cout << "8. Salir y guardar cambios" << endl;
        cout << "---------------------------------" << endl;
        cout << "DNI [" << getDNI() << "] (NO MODIFICABLE)" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Nuevo nombre: ";
                cin >> nuevoTexto;
                setNombre(nuevoTexto);
                break;
            case 2:
                cout << "Nuevo apellido: ";
                cin >> nuevoTexto;
                setApellido(nuevoTexto);
                break;
            case 3:
                cout << "Nuevo teléfono: ";
                cin >> nuevoTelefono;
                setTelefono(nuevoTelefono);
                break;
            case 4:
                cout << "Nuevo email: ";
                cin >> nuevoTexto;
                setEmail(nuevoTexto);
                break;
            case 5:
                cout << "Nueva dirección: ";
                cin >> nuevoTexto;
                setDireccion(nuevoTexto);
                break;
            case 6:
                cout << "Nuevo CUIT: ";
                cin >> nuevoCUIT;
                setCUIT(nuevoCUIT);
                break;
            case 7:
                cout << "Nuevo tipo (1-Particular, 2-Empresa): ";
                do {
                    cin >> nuevoTipo;
                    if (nuevoTipo < 1 || nuevoTipo > 2) {
                        cout << "Tipo inválido. Ingrese 1 o 2: ";
                    }
                } while (nuevoTipo < 1 || nuevoTipo > 2);
                setTipoCliente(nuevoTipo);
                break;
            case 8:
                editar = false;
                break;
            default:
                cout << "Opción inválida, intente nuevamente." << endl;
        }
    }
}


void Cliente::eliminarCliente() {
    setEstado(false);
}

// Getters
int Cliente::getIDCliente() const { return IDCliente; }
const char* Cliente::getCUIT() const { return CUIT; }
const char* Cliente::getEmail() const { return Email; }
int Cliente::getTipoCliente() const { return TipoCliente; }
const char* Cliente::getDireccion() const { return Direccion; }
bool Cliente::getEstado() const { return estado; }

// Setters
void Cliente::setIDCliente(int id) { IDCliente = id; }
void Cliente::setCUIT(const char* cuit) { strcpy(CUIT, cuit); }
void Cliente::setEmail(const char* email) { strcpy(Email, email); }
void Cliente::setTipoCliente(int tipo) { TipoCliente = tipo; }
void Cliente::setDireccion(const char* dir) { strcpy(Direccion, dir); }
void Cliente::setEstado(bool est) { estado = est; }

const char* Cliente::getTipoClienteTexto() const {
    return (TipoCliente == 1) ? "Particular" : "Empresa";
}
