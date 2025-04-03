#include "aplicacion.h"

Aplicacion::Aplicacion(){
    Administrador* root =  new Administrador ("root", "root");
    _listaUsuarios.push_back(root);
}

Aplicacion::~Aplicacion(){
    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){
        delete _listaUsuarios[i];
    }
}

void Aplicacion::displayUsuarios(){
    cout << "Numero total de usuarios: " << _listaUsuarios.size() << endl;
    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){
        _listaUsuarios[i]->displayUsuario();
    }
}

void Aplicacion::displayLocalizaciones() const{
        cout << "Número de localizaciones totales: " << _listaLocacizaciones.size() << endl;
        for (unsigned long i = 0; i< _listaLocacizaciones.size(); i++){
            _listaLocacizaciones[i]->displayLocalizacion();
        }
}

Localizacion* Aplicacion::getLocalizacion(int index) const{
    int aux=_listaLocacizaciones.size();
    while (index<0 || index>=aux){
        cout<< "El índice se encuentra fuera de rango, debe estar entre 0 y " << aux << " para que sea válido"<<endl;
        cin>>index;
    }
    return _listaLocacizaciones[index];
}
