#ifndef EVENTO_H
#define EVENTO_H
#include "localizacion.h"
#include "usuario.h"
#include <string>
using namespace std;

class Localizacion;
class Artista;

class Evento
{
public:
    Evento();
    Evento(string nombreEvento, int dia, int mes,int ano, int precio, bool eventoVip,Localizacion* Loc, Usuario* creador);
    Evento(string nombreEvento, int fecha, int precio, bool eventoVip,Localizacion* Loc, Usuario* creador);
    Evento(const Evento& E);
    ~Evento();
    void displayEvento();
    void setFecha(int dia, int mes, int ano);
    void setNombre(string nombreEvento);
    void setPrecio(int precio);
    void setEventoVip(bool eventoVip);
    void setLocalizacion(Localizacion* Loc);
    Localizacion* getLocalizacion();
    bool getEventoVip();
    string getNombre();
    int getFecha();
    Usuario* getCreador();
    int getPrecio();
    bool comprobarVip();

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
    Usuario* _creador;
};

#endif // EVENTO_H
