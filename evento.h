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
    Evento(string nombre, int dia, int mes,int ano, int precio, bool eventoVip, int entradasTotales,Localizacion* Loc);
    Evento(const Evento& E);
    ~Evento();
    void displayEvento();
    void setFecha(int dia, int mes, int ano);
    string getNombre();
    int getFecha();

private:
    string _nombre;
    int _fecha;
    int _dia;
    int _mes;
    int _ano;
    int _precio;
    bool _eventoVip;
    int _entradasDisponibles;
    int _entradasTotales;
    Localizacion* _Loc;
};

#endif // EVENTO_H
