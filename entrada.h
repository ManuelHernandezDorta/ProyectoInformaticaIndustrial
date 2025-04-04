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
    Entrada(Asistente* asistenteAsignado, Evento* entradaEvento);
    ~Entrada();
    Evento* getEvento();
    Asistente* getAsistente();

protected:
    Asistente* _asistenteAsignado;
    Evento* _entradaEvento;
};

#endif // ENTRADA_H
