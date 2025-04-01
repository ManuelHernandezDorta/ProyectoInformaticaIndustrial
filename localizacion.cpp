#include "localizacion.h"
#include <iostream>
using namespace std;

Localizacion::Localizacion(){
    _nombreLocalizacion="";
    _direccion="";
    _aforo=0;
    //_listaEventos=NULL;

}

Localizacion::Localizacion(string nombreLocalizacion, string direccion, int aforo, vector<Evento*> listaEventos){
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

bool Localizacion::localizacionDisponible(int dia, int mes, int ano){
    int fecha=ano*1000+mes*100+dia;
    for(unsigned i=0; i<_listaEventos.size();i++){
        if(fecha==_listaEventos[i]->getFecha()){
            cout<<"La fecha está ocupada por el evento:" << _listaEventos[i]->getNombre()<<endl;
            return false;
         }
    }
    return true;
}

int Localizacion::getAforo(){
    return _aforo;
}

void Localizacion::agregarEvento(Evento* E){
    _listaEventos.push_back(E);
}

void Localizacion::eliminarEvento(Evento *E){
    int auxtam=_listaEventos.size();
    for(int i=0;i<auxtam;i++){
        if (_listaEventos[i] == E) {
            _listaEventos.erase(_listaEventos.begin() + i);
            cout << "Evento eliminado correctamente de la localizacion: " <<_nombreLocalizacion<< endl;
            }else{
            cout<<"El evento no se encuentra en la lista"<<endl;
        }
    }
}
