#include "usuario.h"

Usuario::Usuario(){
    _nombreUsuario = "";
    _contraseña = "";
}

Usuario::Usuario(string nombreUsuario, string contraseña){
    _nombreUsuario = nombreUsuario;
    _contraseña = contraseña;
}

Usuario::Usuario(const Usuario& U){
    _nombreUsuario = U._nombreUsuario;
    _contraseña = U._contraseña;
}

Usuario::~Usuario(){}

string Usuario::getNombre(){
    return _nombreUsuario;
}

string Usuario::getContraseña(){
    return _contraseña;
}

void Usuario::setNombre(string nombre){
    _nombreUsuario = nombre;
}

void Usuario::setContraseña(string contraseña){
    _contraseña = contraseña;
}


