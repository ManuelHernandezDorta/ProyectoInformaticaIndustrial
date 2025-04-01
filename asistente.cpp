#include "asistente.h"

Asistente::Asistente() : Usuario(), _listaEntradas(){
    _dni=0;
    _cartera=0;
}

Asistente::Asistente(string nombreUsuario, string contraseña, int dni, int cartera, vector<Entrada*> listaEntradas) : Usuario(nombreUsuario,contraseña){
    _dni=dni;
    _cartera=cartera;
    _listaEntradas=listaEntradas;
}

Asistente::Asistente(string nombreUsuario, string contraseña,const Asistente& Asst) : Usuario(nombreUsuario, contraseña){
    _dni=Asst._dni;
    _cartera=Asst._cartera;
    _listaEntradas=Asst._listaEntradas;
}

void Asistente::setCartera(const int &cartera){
    _cartera=cartera;
}

void Asistente::setDni(const int &dni){
    _dni=dni;
}

int Asistente::getDni(){
    return _dni;
}

int Asistente::getCartera(){
    return _cartera;
}

void Asistente::displayUsuario(){

}
