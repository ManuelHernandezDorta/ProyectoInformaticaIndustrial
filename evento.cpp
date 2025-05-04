#include "evento.h"
#include <iostream>
#include "localizacion.h"
using namespace std;

Evento::Evento(){
    _nombreEvento = "";
    _fecha=0;
    _precio=0;
    _eventoVip=0;
    _entradas=0;
    _creador=nullptr;

}

Evento::Evento(string nombreEvento, int fecha, int precio, bool eventoVip,Localizacion* Loc, Usuario* creador){
    _nombreEvento=nombreEvento;
    _fecha = fecha;
    _precio=precio;
    _eventoVip=eventoVip;
    _entradas=Loc->getAforo();
    _Loc=Loc;
    _creador=creador;

}


Evento::Evento(const Evento& E){
    _nombreEvento=E._nombreEvento;
    _fecha=E._fecha;
    _precio=E._precio;
    _eventoVip=E._eventoVip;
    _entradas=E._entradas;
    _Loc=E._Loc;

}

Evento::~Evento(){}

void Evento::displayEvento(){
    string auxvip;
    if(_eventoVip){
        auxvip="El evento vip";
    }else{
        auxvip="El evento no vip";
    }

    cout<< auxvip <<" se celebra en la fecha:" << _fecha << " ,con un numero total de entradas disponibles de " << _entradas << " a un precio de " << _precio << endl;

}

void Evento::setFecha(int fecha){
    _fecha=fecha;

}

string Evento::getNombre(){

    return _nombreEvento;
}

int Evento::getFecha(){

    return _fecha;
}

Usuario* Evento::getCreador(){
    return _creador;
}

void Evento::setEventoVip(bool eventoVip){
    _eventoVip=eventoVip;
}

void Evento::setLocalizacion(Localizacion* Loc){
    _Loc=Loc;
}

void Evento::setNombre(string nombreEvento){
    _nombreEvento=nombreEvento;
}

void Evento::setPrecio(int precio){
    _precio=precio;
}

Localizacion* Evento::getLocalizacion(){
    return _Loc;
}

bool Evento::getEventoVip(){
    return _eventoVip;
}

int Evento::getPrecio(){
    return _precio;
}

void Evento::comprarEntrada(){
    _entradas=_entradas-1;
}
