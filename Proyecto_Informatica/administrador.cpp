#include "administrador.h"

Administrador::Administrador(): Usuario(){}

Administrador::Administrador(string nombreUsuario, string contraseña): Usuario(nombreUsuario, contraseña){}

Administrador::Administrador(const Administrador& A): Usuario(A){}

Administrador::~Administrador(){}
