#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente : public Persona {
private:
    int IDCliente;
    char CUIT[15];
    char Email[50];
    int TipoCliente; // 1: Particular, 2: Empresa
    char Direccion[100];
    bool estado;

public:
    // Constructores
    Cliente();
    Cliente(const char* nom, const char* ape, int dni, int tel, int idCliente,
            const char* cuit, const char* email, int tipo, const char* dir, bool est = true);

    // Métodos principales
    void cargarCliente();
    void mostrarCliente() const;
    void actualizarCliente();
    void eliminarCliente();

    // Getters
    int getIDCliente() const ;
    const char* getCUIT() const;
    const char* getEmail() const;
    int getTipoCliente() const;
    const char* getDireccion() const;
    bool getEstado() const;

    // Setters
    void setIDCliente(int id);
    void setCUIT(const char* cuit);
    void setEmail(const char* email);
    void setTipoCliente(int tipo);
    void setDireccion(const char* dir);
    void setEstado(bool est);

    // Métodos auxiliares
    const char* getTipoClienteTexto() const;
    bool esEmpresa() const;
    bool esParticular() const;
};

#endif // CLIENTE_H
