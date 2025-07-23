#ifndef PERSONA_H
#define PERSONA_H
class Persona {
public:
    Persona();
    Persona(const char* nom, const char* ape, int dni, int tel);
    void cargarDatosPersona();
    void mostrarDatosPersona() const;

    // Getters
    const char* getNombre() const;
    const char* getApellido() const ;
    int getDNI() const;
    int getTelefono() const;

    // Setters
    void setNombre(const char* nom);
    void setApellido(const char* ape);
    void setDNI(int d);
    void setTelefono(int t);
     void actualizarNombreApellido();

private:
    char _Nombre[50];
    char _Apellido[50];
    int _dni;
    int _Telefono;
};
#endif // PERSONA_H
