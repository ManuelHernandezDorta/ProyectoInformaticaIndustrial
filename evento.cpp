#include "evento.h"
#include <iostream>
#include "localizacion.h"
using namespace std;

Evento::Evento(){
    _fecha=0;
    _dia=0;
    _mes=0;
    _ano=0;
    _precio=0;
    _eventoVip=0;
    _entradasDisponibles=0;
    _entradasTotales=0;

}

Evento::Evento(string nombre, int dia, int mes, int ano, int precio, bool eventoVip, int entradasTotales,Localizacion* Loc){
    _nombre=nombre;
    _dia=dia;
    _mes=mes;
    _ano=ano;
    _fecha = _ano*1000+_mes*100+_dia;
    _precio=precio;
    _eventoVip=eventoVip;
    _entradasTotales=entradasTotales;
    _entradasDisponibles=entradasTotales;
    _Loc=Loc;

}

Evento::Evento(const Evento& E){
    _nombre=E._nombre;
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

Evento::~Evento(){}

void Evento::displayEvento(){

    cout<<"El evento se celebra el dia "<< _dia << "/"<< _mes <<"/" << _ano << " ,con un numero total de entradas " << _entradasTotales << ", de las cuales quedan " << _entradasDisponibles << "a un precio de " << _precio << endl;

}

void Evento::setFecha(int dia, int mes, int ano){

    _dia=dia;
    _mes=mes;
    _ano=ano;
    _fecha = _ano*1000+_mes*100+_dia;

}

string Evento::getNombre(){

    return _nombre;
}

int Evento::getFecha(){

    return _fecha;
}
