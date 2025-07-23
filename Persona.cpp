#include <cstring>
#include <iostream>
#include "Persona.h"
using namespace std;

//CONSTRUCTOR POR DEFECTO
Persona::Persona() {
    strcpy(_Nombre, "");
    strcpy(_Apellido, "");
    _dni = 0;
    _Telefono = 0;
}

//CONSTRUCTOR PARAMETRIZADO
Persona::Persona(const char* nom, const char* ape, int dni, int tel) {
    setNombre(nom);
    setApellido(ape);
    setDNI(dni);
    setTelefono(tel);
}

//CARGA DE DATOS DE UNA PERSONA
void Persona::cargarDatosPersona() {
    char nombre[50], apellido[50];
    int dni, telefono;

    cout << "INGRESAR NOMBRE: ";
    cin.ignore();
    cin >> nombre;
    setNombre(nombre);

    cout << "INGRESAR APELLIDO: ";
    cin>> apellido;
    setApellido(apellido);

    cout << "INGRESAR DNI: ";
    cin >> dni;
    setDNI(dni);

    cout << "INGRESAR TELEFONO: ";
    cin >> telefono;
    setTelefono(telefono);
}

// MOSTRAR LOS DATOS DE PERSONA
void Persona::mostrarDatosPersona() const {
    cout << "NOMBRE: " << getNombre() << endl;
    cout << "APELLIDO: " << getApellido() << endl;
    cout << "DNI: " << getDNI() << endl;
    cout << "TELEFONO: " << getTelefono() << endl;
}

void Persona::actualizarNombreApellido() {
    char nuevoNombre[50];
    int nuevoTelefono;
    cout << "Nuevo nombre [" << _Nombre << "]: ";
    cin.ignore();
    cin.getline(nuevoNombre, 50);
    setNombre(nuevoNombre);

    cout << "Nuevo apellido [" << _Apellido << "]: ";
    cin.getline(nuevoNombre, 50);
    setApellido(nuevoNombre);

   cout << "Nuevo Telefono [" << _Telefono<< "]: ";
    cin>> nuevoTelefono;
    setTelefono(nuevoTelefono);
}


//setters
void Persona::setNombre(const char* nombre) {
    strcpy(_Nombre, nombre);
}
void Persona::setApellido(const char* apellido) {
    strcpy(_Apellido, apellido);
}
void Persona::setDNI(int d) {
    _dni = d;
}
void Persona::setTelefono(int t) {
    _Telefono = t;
}

//getters
const char* Persona::getNombre() const {
    return _Nombre;
}
const char* Persona::getApellido() const {
    return _Apellido;
}
int Persona::getDNI() const {
    return _dni;
}
int Persona::getTelefono() const {
    return _Telefono;
}
