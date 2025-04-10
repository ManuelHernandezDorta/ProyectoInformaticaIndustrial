#include "entrada.h"

Entrada::Entrada(){
    _entradaEvento=nullptr;
    _asistenteAsignado=nullptr;
    _vip=false;
}

Entrada::Entrada(Asistente* asistenteAsignado, Evento* entradaEvento, bool vip){
    _asistenteAsignado=asistenteAsignado;
    _entradaEvento=entradaEvento;
    _vip=vip;
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
