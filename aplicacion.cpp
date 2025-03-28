#include "aplicacion.h"

Aplicacion::Aplicacion(){
    Administrador root ("root", "root");
    listaUsuarios.push_back(&root);
}

void Aplicacion::displayUsuarios(){
    cout << "Tamaño de lista de usuarios: " << listaUsuarios.size() << endl;
    for (unsigned long i = 0; i < listaUsuarios.size(); i++){
        cout << "hola" << endl;
        cout << listaUsuarios[i]->getNombre();
    }
}
