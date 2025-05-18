#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <sstream>

using namespace std;

class Aplicacion;
class Evento;

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
    virtual string tipoUsuario()=0;
    virtual Usuario* editar() = 0;
    virtual string guardarUsuario() = 0;
    virtual void añadirEvento(Evento* E){typeid(E).name();} //la funcion es solamente para que no salten warnings


protected:
    string _nombreUsuario;
    string _contraseña;
};

#endif // USUARIO_H
