#ifndef EVENTO_H
#define EVENTO_H
#include "localizacion.h"
#include <string>
using namespace std;

class Localizacion;

class Evento
{
public:
    Evento();
    Evento(string fecha, int precio, bool eventoVip, int entradasTotales,Localizacion* Loc);
    Evento(const Evento& E);
    ~Evento();
    void displayEvento();
    void setFecha(string fecha);
    string getFecha();

private:
    string _fecha;
    int _precio;
    bool _eventoVip;
    int _entradasDisponibles;
    int _entradasTotales;
    Localizacion* _Loc;
};

#endif // EVENTO_H
