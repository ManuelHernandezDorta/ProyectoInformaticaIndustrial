#include "administrador.h"

Administrador::Administrador(): Usuario(){}



Administrador::Administrador(string nombreUsuario, string contraseña): Usuario(nombreUsuario, contraseña){}


Administrador::Administrador(string nombreUsuario, string contraseña, Aplicacion* App): Usuario(nombreUsuario, contraseña){
    _App = App;
}


Administrador::Administrador(const Administrador& A): Usuario(A){}



Administrador::~Administrador(){}

void Administrador::displayUsuario(){
    cout << "Tipo: Administrador, nombreUsuario: " << _nombreUsuario << ", contraseña: " << _contraseña << endl;
}

void Administrador::menu(){
    int eleccion;
    string continuar;

    cout << "Menu: " << endl << "0. Mostrar lista de usuarios" << endl;
    cin >> eleccion;


    if (eleccion == 0){
        _App->displayUsuarios();

        cout << "Desea realizar otra acion: (S/N): " << endl;
        cin >> continuar;

        if (continuar == "S" || continuar == "s"){
            this->menu();
        }
        else{
            cout << "Cerrando sesion..." << endl;
            return;
        }

    }

}
