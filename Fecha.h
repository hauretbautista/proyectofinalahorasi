#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:

    Fecha();

    Fecha(int d, int m, int a);

    void cargarFecha();

    void mostrarFecha() const;

        // const en ints no es necesario

    // Getters
    int getDia() ;
    int getMes();
    int getAnio() ;

    // Setters
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    bool esMayorA(const Fecha& otra) const;

    bool esIgualA(const Fecha& otra) const;
};

#endif
