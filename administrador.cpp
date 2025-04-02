#include "administrador.h"


Administrador::Administrador(): Usuario(){}



Administrador::Administrador(string nombreUsuario, string contraseña): Usuario(nombreUsuario, contraseña){}



Administrador::Administrador(const Administrador& A): Usuario(A){}



Administrador::~Administrador(){}

void Administrador::displayUsuario(){
    cout << "Tipo: Administrador, nombreUsuario: " << _nombreUsuario << ", contraseña: " << _contraseña << endl;
}
