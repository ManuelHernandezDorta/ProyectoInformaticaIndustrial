#ifndef EVENTO_H
#define EVENTO_H
#include "localizacion.h"
#include "artista.h"
#include <string>
using namespace std;

class Localizacion;
class Artista;

class Evento
{
public:
    Evento();
    Evento(string nombreEvento, int dia, int mes,int ano, int precio, bool eventoVip,Localizacion* Loc, Artista* creador);
    Evento(const Evento& E);
    ~Evento();
    void displayEvento();
    string getNombre();
    int getFecha();
    Artista* getCreador();
    void setFecha(int dia, int mes, int ano);
    void setNombre(string nombreEvento);
    void setPrecio(int precio);
    void setEventoVip(bool eventoVip);
    void setLocalizacion(Localizacion* Loc);

private:
    string _nombreEvento;
    int _fecha;
    int _dia;
    int _mes;
    int _ano;
    int _precio;
    bool _eventoVip;
    int _entradasDisponibles;
    int _entradasTotales;
    Localizacion* _Loc;
    Artista* _creador;
};

#endif // EVENTO_H
