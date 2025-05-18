#ifndef LOCALIZACION_H
#define LOCALIZACION_H
#include "evento.h"
#include <string>
#include <vector>

using namespace std;

class Evento;

class Localizacion
{
public:
    Localizacion();
    Localizacion(string nombreLocalizacion, string direccion, int aforo, vector<Evento*> listaEventos);
    Localizacion(string nombreLocalizacion, string direccion, int aforo);
    Localizacion(const Localizacion& Loc);
    ~Localizacion();
    void displayLocalizacion();
    bool localizacionDisponible(int dia, int mes, int ano);
    int getAforo();
    vector<Evento*> getListaEventos();
    void agregarEvento(Evento* E);
    void eliminarEvento(Evento* E);
    void coincideFecha(int& fecha);
    string guardarLocalizacion();

private:
    string _nombreLocalizacion;
    string _direccion;
    int _aforo;
    vector<Evento*> _listaEventos;

};

#endif // LOCALIZACION_H
