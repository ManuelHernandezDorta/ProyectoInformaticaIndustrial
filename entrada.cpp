#include "entrada.h"

Entrada::Entrada(){
    _entradaEvento=nullptr;
    _asistenteAsignado=nullptr;
    _precioMercadoSecundario=0;
}

Entrada::Entrada(Usuario* asistenteAsignado, Evento* entradaEvento){
    _asistenteAsignado=asistenteAsignado;
    _entradaEvento=entradaEvento;
    _precioMercadoSecundario=0;
}

Entrada::Entrada(Usuario* asistenteAsignado, Evento* entradaEvento, int precioSecundario){
    _asistenteAsignado = asistenteAsignado;
    _entradaEvento = entradaEvento;
    _precioMercadoSecundario = precioSecundario;
}


Entrada::~Entrada(){}

Evento* Entrada::getEvento(){
    return _entradaEvento;
}

Usuario* Entrada::getAsistente(){
    return _asistenteAsignado;
}

int Entrada::getPrecioMercadoSecundario(){
    return _precioMercadoSecundario;
}

void Entrada::setPrecioMercadoSecundario(const int precio){
    _precioMercadoSecundario=precio;
}

void Entrada::setAsistente(Asistente *asistente){
    _asistenteAsignado=asistente;
}

void Entrada::displayEntrada(){
    cout<<"Entrada registrada al evento: "<< _entradaEvento->getNombre() <<endl;
}

void Entrada::displayEntradaMercadoSecundario(){
    cout<<"Entrada registrada al evento: "<< _entradaEvento->getNombre() <<" a un precio de: "<< _precioMercadoSecundario << " vendedor: "<< _asistenteAsignado->getNombre()<<endl;
}

string Entrada::guardarEntrada(){

    stringstream cadena;

    cadena << _asistenteAsignado->getNombre() << "," << _entradaEvento->getNombre()<< "," << _precioMercadoSecundario;

    return cadena.str();

}
