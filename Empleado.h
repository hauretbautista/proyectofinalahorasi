#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona {
    public:
    Empleado ();

     Empleado(const char* nombre, const char* apellido, int dni, int telefono, int idEmpleado, const char* especialidad);


    void cargarEmpleado ();

    void  mostrarEmpleado ();

    void actualizarEmpleado ();

    void eliminarEmpleado ();

    //Getters
    int getIDEmpleado() ;
    const char* getEspecialidad();
    bool estaActivo();

    //Setters
    void setIDEmpleado(int id);
    void setEspecialidad(const char* esp);
    void setActivo(bool a);

private:
    int  _idEmpleado;
    char _especialidad [50];
    bool _activo;


};

#endif // EMPLEADO_H
