#include "asistente.h"

Asistente::Asistente() : Usuario(), _listaEntradas(){
    _dni="";
    _cartera=0;
    _vip=false;
}

Asistente::Asistente(string nombreUsuario, string contraseña, string dni, int cartera, bool vip) : Usuario(nombreUsuario,contraseña){
    _dni=dni;
    _cartera=cartera;
    _vip=vip;

}


Asistente::Asistente(string nombreUsuario, string contraseña,const Asistente& Asst) : Usuario(nombreUsuario, contraseña){
    _dni=Asst._dni;
    _cartera=Asst._cartera;
    _listaEntradas=Asst._listaEntradas;
}

Asistente::~Asistente(){
    for (unsigned i = 0; i < _listaEntradas.size(); i++){
        delete _listaEntradas[i];
    }
}

void Asistente::setCartera(const int &cartera){
    _cartera=cartera;
}

void Asistente::setDni(const string &dni){
    _dni=dni;
}

string Asistente::getDni(){
    return _dni;
}

int Asistente::getCartera(){
    return _cartera;
}

bool Asistente::getVip(){
    return _vip;
}

void Asistente::displayUsuario(){
    string auxvip;
    if(_vip){
        auxvip="vip";
    }else{
        auxvip= "no vip";
    }
    cout << "Tipo: Asistente " << auxvip << ", con nombreUsuario: " << _nombreUsuario << ", contraseña: " << _contraseña << ", DNI: " << _dni << ", cartera: " <<_cartera << endl;
}

void Asistente::menu(Aplicacion* App){
    int eleccion;
    string continuar;

    cout << "Menu: " << endl << "0. Mostrar lista de eventos" << endl;
    cin >> eleccion;


    if (eleccion == 0){
        App->displayEventos();
    }

    cout << "Desea realizar otra acion: (S/N): " << endl;
    cin >> continuar;

    if (continuar == "S" || continuar == "s"){
        this->menu(App);
    }
    else{
        cout << "Cerrando sesion..." << endl;
        return;
    }

}
