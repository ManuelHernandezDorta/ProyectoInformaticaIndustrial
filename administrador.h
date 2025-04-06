#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"
#include "aplicacion.h"

class Aplicacion;

class Administrador: public Usuario{

public:
    Administrador();
    Administrador(string nombreUsuario, string contraseña);
    Administrador(string nombreUsuario, string contraseña, Aplicacion* App);
    Administrador(const Administrador& A);
    virtual ~Administrador();
    void displayUsuario();
    void crearArtista();
    void crearAsistente();
    void crearAdministrador();
    void menu();

private:
    Aplicacion* _App;
};

#endif // ADMINISTRADOR_H
