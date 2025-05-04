#include "localizacion.h"
#include <iostream>
using namespace std;

Localizacion::Localizacion() : _listaEventos(){
    _nombreLocalizacion="";
    _direccion="";
    _aforo=0;

}

Localizacion::Localizacion(string nombreLocalizacion, string direccion, int aforo) : _listaEventos(){
    _nombreLocalizacion=nombreLocalizacion;
    _direccion=direccion;
    _aforo=aforo;

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

Localizacion::~Localizacion(){}

void Localizacion::displayLocalizacion(){

    cout<<"El nombre de la localizacion es "<< _nombreLocalizacion << " con dirección " << _direccion << "y un aforo máximo de: " << _aforo << "personas " << endl;

}

vector<Evento*> Localizacion::getListaEventos(){
    return _listaEventos;
}

int Localizacion::getAforo(){
    return _aforo;
}

void Localizacion::agregarEvento(Evento* E){
    _listaEventos.push_back(E);
}

void Localizacion::eliminarEvento(Evento* E){
    for(unsigned i=0;i<_listaEventos.size();i++){
        if (_listaEventos[i] == E) {
            _listaEventos.erase(_listaEventos.begin() + i);
            cout << "Evento eliminado correctamente de la localizacion: " <<_nombreLocalizacion<< endl;
            }else{
            cout<<"El evento no se encuentra en la lista"<<endl;
        }
    }
}

void Localizacion::coincideFecha(int& fecha){
    bool fechaOcupada;
    do {
        fechaOcupada=false;
        for (unsigned long i=0; i<_listaEventos.size();i++){
            if(_listaEventos[i]->getFecha()==fecha){
                cout<<"La fecha está ocupada por el evento: " << _listaEventos[i]->getNombre()<<endl;
                cout<< "Introduce la nueva fecha con el formato dia,mes,año. Por ejemplo 04092025"<<endl;
                cin>>fecha;
                fechaOcupada=true;
                break;
            }
     }
    }while(fechaOcupada);

}
