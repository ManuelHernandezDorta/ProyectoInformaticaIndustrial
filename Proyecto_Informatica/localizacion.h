#ifndef LOCALIZACION_H
#define LOCALIZACION_H
#include "evento.h"
#include <string>

using namespace std;

class Localizacion
{
public:
    Localizacion();
    Localizacion(string nombreLocalizacion, string direccion, int aforo, Evento* listaEventos);
    Localizacion(const Localizacion& Loc);
    ~Localizacion();
    void displayLocalizacion();
    bool localizacionDisponible(string fecha);

private:
    string _nombreLocalizacion;
    string _direccion;
    int _aforo;
    Evento* _listaEventos;

};

#endif // LOCALIZACION_H
