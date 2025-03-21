#include "localizacion.h"
#include <iostream>
using namespace std;

Localizacion::Localizacion(){
    _nombreLocalizacion="";
    _direccion="";
    _aforo=0;
    _listaEventos=NULL;

}

Localizacion::Localizacion(string nombreLocalizacion, string direccion, int aforo, Evento* listaEventos){
    _nombreLocalizacion=nombreLocalizacion;
    _direccion=direccion;
    _aforo=aforo;
    _listaEventos=listaEventos;

}

Localizacion::Localizacion(const Localizacion& Loc){

    _nombreLocalizacion=Loc._nombreLocalizacion;
    _direccion=Loc._direccion;
    _aforo=Loc._aforo;
    _listaEventos=Loc._listaEventos;

}

void Localizacion::displayLocalizacion(){

    cout<<"El nombre de la localizacion es "<< _nombreLocalizacion << " con dirección " << _direccion << "y un aforo máximo de: " << _aforo << "personas " << endl;

}

bool Localizacion::localizacionDisponible(string fecha){

}
