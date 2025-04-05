#include "aplicacion.h"
#include <typeinfo>

Aplicacion::Aplicacion(){
    Administrador* root =  new Administrador ("root", "root", this);
    _listaUsuarios.push_back(root);
}

Aplicacion::~Aplicacion(){
    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){
        delete _listaUsuarios[i];
    }
    for (unsigned long i = 0; i < _listaEventos.size(); i++){
        delete _listaEventos[i];
    }
    for (unsigned long i = 0; i < _listaLocalizaciones.size(); i++){
        delete _listaLocalizaciones[i];
    }
}

void Aplicacion::displayUsuarios(){
    cout << "Numero total de usuarios: " << _listaUsuarios.size() << endl;
    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){
        _listaUsuarios[i]->displayUsuario();
    }
}

void Aplicacion::displayLocalizaciones(){
        cout << "Número de localizaciones totales: " << _listaLocalizaciones.size() << endl;
        for (unsigned long i = 0; i< _listaLocalizaciones.size(); i++){
            _listaLocalizaciones[i]->displayLocalizacion();
        }
}

void Aplicacion::displayEventos(){
    cout << "Número de Eventos totales: " << _listaEventos.size() << endl;
    for (unsigned long i = 0; i< _listaEventos.size(); i++){
        _listaEventos[i]->displayEvento();
    }
}

void Aplicacion::anadirEvento(Evento* E){
    _listaEventos.push_back(E);
}

void Aplicacion::anadirLocalizacion(Localizacion *Loc){
    _listaLocalizaciones.push_back(Loc);
}

void Aplicacion::anadirUsuario(Usuario *U){
    _listaUsuarios.push_back(U);
}

void Aplicacion::eliminarEvento(Evento* E){
    for(unsigned i=0;i<_listaEventos.size();i++){
        if (_listaEventos[i] == E) {
            delete _listaEventos[i];
            _listaEventos.erase(_listaEventos.begin() + i);
            cout << "Evento eliminado correctamente de la lista de eventos globales"<< endl;
            return;
         }
    }
    cout<<"El evento no se encuentra en la lista"<<endl;
}

void Aplicacion::eliminarLocalizacion(Localizacion* Loc){
    for(unsigned i=0;i<_listaLocalizaciones.size();i++){
        if (_listaLocalizaciones[i] == Loc) {
            delete _listaLocalizaciones[i];
            _listaLocalizaciones.erase(_listaLocalizaciones.begin() + i);
            cout << "Localizacion eliminada correctamente de la lista de Localizaciones" << endl;
            return;
            }
    }
    cout<<"El evento no se encuentra en la lista"<<endl;
}

void Aplicacion::eliminarUsuario(Usuario* U){
    for(unsigned i=0;i<_listaUsuarios.size();i++){
        if (_listaUsuarios[i] == U) {
            delete _listaUsuarios[i];
            _listaUsuarios.erase(_listaUsuarios.begin() + i);
            cout << "Usuario eliminado correctamente de la lista de Usuarios"<< endl;
            return;
            }
    }
    cout<<"El evento no se encuentra en la lista"<<endl;
}

Localizacion* Aplicacion::getLocalizacion(int index){
    int aux = _listaLocalizaciones.size();
    while (index < 0 || index >= aux){
        cout<< "El índice se encuentra fuera de rango, debe estar entre 0 y el numero de localizaciones ((" << aux << ") para que sea válido. Introduce el indice de nuevo: " << endl;
        cin >> index;
    }
    return _listaLocalizaciones[index];
}

int Aplicacion::buscarUsuario(const string& nombreUsuario){
    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){
        if (_listaUsuarios[i]->getNombre() == nombreUsuario){
            return i;
        }
    }
    return (-1);
}

bool Aplicacion::comprobarContraseña(const string& nombreUsuario, const string& contraseña){
    int indiceUsuario = buscarUsuario(nombreUsuario);

    if (_listaUsuarios[indiceUsuario]->getContraseña() == contraseña){
        return true;
    }
    else{
        return false;
    }
}

void Aplicacion::registrarse(){
    string nombre, contraseña;
    cout << "Introduce el nombre de usuario para registrarte: " << endl;
    cin >>  nombre;

    int indiceUsuario = buscarUsuario(nombre);

    if (indiceUsuario < 0){
        cout << "No existe ningun usuario con ese nombre, prueba de nuevo" << endl;
        this->registrarse();
    }
    else{
        cout << "Usuario encontrado" << endl << "Introduce la contraseña para el usuario (" << nombre << "): " << endl;
        cin >> contraseña;

        if (this->comprobarContraseña(nombre, contraseña)){
            cout << "Contraseña correcta, te has registrado de forma correcta" << endl;
            _listaUsuarios[indiceUsuario]->menu();
        }

    }

}

