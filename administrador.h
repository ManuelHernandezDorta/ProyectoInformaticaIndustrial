#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"
#include "aplicacion.h"

class Aplicacion;

class Administrador: public Usuario{

public:
    Administrador();
    Administrador(string nombreUsuario, string contraseña);
    Administrador(const Administrador& A);
    virtual ~Administrador();
    void displayUsuario();
    string tipoUsuario();
    void crearArtista();
    void crearAsistente();
    void crearAdministrador();
    void menu(Aplicacion* App);
    Usuario* editar();
};

#endif // ADMINISTRADOR_H
