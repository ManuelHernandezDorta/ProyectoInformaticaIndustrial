#include "entrada.h"

Entrada::Entrada(){
    _entradaEvento=nullptr;
    _asistenteAsignado=nullptr;
}

Entrada::Entrada(Asistente* asistenteAsignado, Evento* entradaEvento){
    _asistenteAsignado=asistenteAsignado;
    _entradaEvento=entradaEvento;
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
