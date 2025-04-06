#include "asistente.h"

Asistente::Asistente() : Usuario(), _listaEntradas(){
    _dni="";
    _cartera=0;
    _App = nullptr;
}

Asistente::Asistente(string nombreUsuario, string contraseña, string dni, int cartera) : Usuario(nombreUsuario,contraseña){
    _dni=dni;
    _cartera=cartera;
    _App = nullptr;

}

Asistente::Asistente(string nombreUsuario, string contraseña, string dni, int cartera, Aplicacion* App): Usuario(nombreUsuario, contraseña){
    _dni=dni;
    _cartera=cartera;
    _App = App;
}


Asistente::Asistente(string nombreUsuario, string contraseña,const Asistente& Asst) : Usuario(nombreUsuario, contraseña){
    _dni=Asst._dni;
    _cartera=Asst._cartera;
    _listaEntradas=Asst._listaEntradas;
    _App = Asst._App;
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

void Asistente::displayUsuario(){
    cout << "Tipo: Asistente, nombreUsuario: " << _nombreUsuario << ", contraseña: " << _contraseña << ", DNI: " << _dni << ", cartera: " <<_cartera << endl;
}

void Asistente::menu(){
    int eleccion;
    string continuar;

    cout << "Menu: " << endl << "0. Mostrar lista de eventos" << endl;
    cin >> eleccion;


    if (eleccion == 0){
        _App->displayEventos();
    }

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
