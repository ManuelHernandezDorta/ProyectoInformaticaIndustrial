#include "evento.h"
#include <iostream>
#include "localizacion.h"
using namespace std;

Evento::Evento(){
    _fecha="";
    _precio=0;
    _eventoVip=0;
    _entradasDisponibles=0;
    _entradasTotales=0;

}

Evento::Evento(string fecha, int precio, bool eventoVip, int entradasTotales, const Localizacion& Loc){
    _fecha=fecha;
    _precio=precio;
    _eventoVip=eventoVip;
    _entradasTotales=entradasTotales;
    _entradasDisponibles=entradasTotales;
    _Loc=Loc;

}

Evento::Evento(const Evento& E){
    _fecha=E._fecha;
    _precio=E._precio;
    _eventoVip=E._eventoVip;
    _entradasTotales=E._entradasTotales;
    _entradasDisponibles=E._entradasDisponibles;
    _Loc=E._Loc;

}

Evento::~Evento(){}

void Evento::displayEvento(){

    cout<<"El evento se celebra el dia "<< _fecha << " ,con un numero total de entradas " << _entradasTotales << ", de las cuales quedan " << _entradasDisponibles << "a un precio de " << _precio << endl;

}

void Evento::setFecha(string fecha){

    _fecha=fecha;

}

string Evento::getFecha(){

    return _fecha;
}
