#include "entrada.h"

Entrada::Entrada(){
    _entradaEvento=nullptr;
    _asistenteAsignado=nullptr;
    _precioMercadoSecundario=0;
}

Entrada::Entrada(Asistente* asistenteAsignado, Evento* entradaEvento){
    _asistenteAsignado=asistenteAsignado;
    _entradaEvento=entradaEvento;
    _precioMercadoSecundario=0;
}

Entrada::~Entrada(){
    delete _entradaEvento;
    delete _asistenteAsignado;
}

Evento* Entrada::getEvento(){
    return _entradaEvento;
}

Asistente* Entrada::getAsistente(){
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
    cout<<"Entrada registrada al evento: "<< _entradaEvento->getNombre() <<" a un precio de: "<< _precioMercadoSecundario << " vendedor: ";
    _asistenteAsignado->displayUsuario();
}
