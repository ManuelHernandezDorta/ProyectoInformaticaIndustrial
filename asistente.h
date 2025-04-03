#ifndef ASISTENTE_H
#define ASISTENTE_H
#include "usuario.h"
#include "entrada.h"
#include "evento.h"
#include <vector>

class Evento;
class Artista;


class Asistente : public Usuario
{
public:
    Asistente();
    Asistente(string nombreUsuario, string contraseña, int dni, int cartera, vector<Entrada*> listaEntradas);
    Asistente(string nombreUsuario, string contraseña, const Asistente& Asst);
    virtual ~Asistente();
    void setDni(const int& dni);
    void setCartera(const int& cartera);
    int getDni();
    int getCartera();
    void comprarEntrada(Evento& E);
    void eventosDisponibles();
    void verArtista(Artista& Art);
    void displayUsuario();
protected:
    vector<Entrada*> _listaEntradas;
    int _dni;
    int _cartera;

};

#endif // ASISTENTE_H
