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
    Entrada(Usuario* asistenteAsignado, Evento* entradaEvento);
    Entrada(Usuario* asistenteAsignado, Evento* entradaEvento, int precioSecundario);
    ~Entrada();
    void displayEntrada();
    void displayEntradaMercadoSecundario();
    void setAsistente(Asistente* asistente);
    Evento* getEvento();
    Usuario* getAsistente();
    int getPrecioMercadoSecundario();
    void setPrecioMercadoSecundario(const int precio);
    string guardarEntrada();

private:
    Usuario* _asistenteAsignado;
    Evento* _entradaEvento;
    int _precioMercadoSecundario;
};

#endif // ENTRADA_H
