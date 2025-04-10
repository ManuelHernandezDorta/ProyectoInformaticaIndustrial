#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

using namespace std;

class Aplicacion;

class Usuario{

public:
    Usuario();
    Usuario(string nombreUsuario, string contraseña);
    Usuario(const Usuario& U);
    virtual ~Usuario();

    string getNombre();
    string getContraseña();

    void setNombre(string nombre);
    void setContraseña(string contraseña);

    virtual void displayUsuario() = 0;
    virtual void menu(Aplicacion* App) = 0;


protected:
    string _nombreUsuario;
    string _contraseña;
};

#endif // USUARIO_H
