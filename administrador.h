#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"

class Administrador: public Usuario{

public:
    Administrador();
    Administrador(string nombreUsuario, string contraseña);
    Administrador(const Administrador& A);
    ~Administrador();
    void displayUsuario();
};

#endif // ADMINISTRADOR_H
