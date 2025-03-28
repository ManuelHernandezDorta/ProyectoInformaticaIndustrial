#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

using namespace std;

class Usuario{

public:
    Usuario();
    Usuario(string nombreUsuario, string contraseña);
    Usuario(const Usuario& U);
    ~Usuario();

    string getNombre();
    string getContraseña();

    void setNombre(string nombre);
    void setContraseña(string contraseña);

    virtual void displayUsuario() = 0;


protected:
    string _nombreUsuario;
    string _contraseña;
};

#endif // USUARIO_H
