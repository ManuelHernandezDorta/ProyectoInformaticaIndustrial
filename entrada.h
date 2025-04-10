#ifndef ENTRADA_H
#define ENTRADA_H
#include "asistente.h"
#include "evento.h"

class Asistente;
class Evento;

class Entrada
{
public:
    Entrada();
    Entrada(Asistente* asistenteAsignado, Evento* entradaEvento, bool vip);
    ~Entrada();
    Evento* getEvento();
    Asistente* getAsistente();

private:
    Asistente* _asistenteAsignado;
    Evento* _entradaEvento;
    bool _vip;
};

#endif // ENTRADA_H
