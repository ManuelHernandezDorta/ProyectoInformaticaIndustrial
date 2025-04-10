#include "evento.h"
#include <iostream>
#include "localizacion.h"
using namespace std;

Evento::Evento(){
    _nombreEvento = "";
    _fecha=0;
    _dia=0;
    _mes=0;
    _ano=0;
    _precio=0;
    _eventoVip=0;
    _entradasDisponibles=0;
    _entradasTotales=0;
    _creador=nullptr;

}

Evento::Evento(string nombreEvento, int fecha, int precio, bool eventoVip,Localizacion* Loc, Usuario* creador){
    _nombreEvento=nombreEvento;
    _dia=fecha % 100;
    _mes=(fecha/100)%100;
    _ano= fecha/10000;
    _fecha = fecha;
    _precio=precio;
    _eventoVip=eventoVip;
    _entradasTotales=Loc->getAforo();
    _entradasDisponibles=Loc->getAforo();
    _Loc=Loc;
    _creador=creador;

}

Evento::Evento(string nombreEvento, int dia, int mes, int ano, int precio, bool eventoVip,Localizacion* Loc, Usuario* creador){
    _nombreEvento=nombreEvento;
    _dia=dia;
    _mes=mes;
    _ano=ano;
    _fecha = _ano*1000+_mes*100+_dia;
    _precio=precio;
    _eventoVip=eventoVip;
    _entradasTotales=Loc->getAforo();
    _entradasDisponibles=Loc->getAforo();
    _Loc=Loc;
    _creador=creador;

}

Evento::Evento(const Evento& E){
    _nombreEvento=E._nombreEvento;
    _dia=E._dia;
    _mes=E._mes;
    _ano=E._ano;
    _fecha=E._fecha;
    _precio=E._precio;
    _eventoVip=E._eventoVip;
    _entradasTotales=E._entradasTotales;
    _entradasDisponibles=E._entradasDisponibles;
    _Loc=E._Loc;

}

Evento::~Evento(){
    delete _creador;
    delete _Loc;
}

void Evento::displayEvento(){

    cout<<"El evento se celebra el dia "<< _dia << "/" <<  _mes << "/" << _ano << " ,con un numero total de entradas " << _entradasTotales << ", de las cuales quedan " << _entradasDisponibles << " a un precio de " << _precio << endl;

}

void Evento::setFecha(int dia, int mes, int ano){

    _dia=dia;
    _mes=mes;
    _ano=ano;
    _fecha = _ano*1000+_mes*100+_dia;

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
