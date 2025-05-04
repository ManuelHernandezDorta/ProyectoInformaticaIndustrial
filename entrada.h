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
    void displayEntrada();
    Evento* getEvento();
    Asistente* getAsistente();

private:
    Asistente* _asistenteAsignado;
    Evento* _entradaEvento;
};

#endif // ENTRADA_H
