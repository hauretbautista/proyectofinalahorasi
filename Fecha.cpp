#include "Fecha.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Fecha::Fecha() {
    dia = 1;
    mes = 1;
    anio = 2024;
}

// Constructor con parámetros
Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

// Cargar fecha
void Fecha::cargarFecha() {
    cout << "INGRESAR DIA: ";
    cin >> dia;
    cout << "INGRESAR MES: ";
    cin >> mes;
    cout << "INGRESAR ANIO: ";
    cin >> anio;
}

// Mostrar fecha
void Fecha::mostrarFecha() const {
    cout << dia << "/" << mes << "/" << anio;
}

// Getters
int Fecha::getDia() {
    return dia;
}

int Fecha::getMes() {
    return mes;
}

int Fecha::getAnio() {
    return anio;
}

// Setters
void Fecha::setDia(int d) {
    dia = d;
}

void Fecha::setMes(int m) {
    mes = m;
}

void Fecha::setAnio(int a) {
    anio = a;
}

// Métodos de comparación
bool Fecha::esMayorA(const Fecha& otra) const {
    if (anio > otra.anio) return true;
    if (anio < otra.anio) return false;
    if (mes > otra.mes) return true;
    if (mes < otra.mes) return false;
    return dia > otra.dia;
}

bool Fecha::esIgualA(const Fecha& otra) const {
    return (dia == otra.dia && mes == otra.mes && anio == otra.anio);
}
