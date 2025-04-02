#include "aplicacion.h"

Aplicacion::Aplicacion(){
    Administrador* root =  new Administrador ("root", "root");
    listaUsuarios.push_back(root);
}

Aplicacion::~Aplicacion(){
    for (unsigned long i = 0; i < listaUsuarios.size(); i++){
        delete listaUsuarios[i];
    }
}

void Aplicacion::displayUsuarios(){
    cout << "Numero total de usuarios: " << listaUsuarios.size() << endl;
    for (unsigned long i = 0; i < listaUsuarios.size(); i++){
        listaUsuarios[i]->displayUsuario();
    }
}
