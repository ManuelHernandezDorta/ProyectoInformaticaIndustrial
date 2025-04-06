#ifndef ASISTENTE_H
#define ASISTENTE_H
#include "usuario.h"
#include "entrada.h"
#include "evento.h"
#include "aplicacion.h"
#include <vector>

class Evento;
class Artista;
class Entrada;


class Asistente : public Usuario
{
public:
    Asistente();
    Asistente(string nombreUsuario, string contraseña, string dni, int cartera);
    Asistente(string nombreUsuario, string contraseña, string dni, int cartera, Aplicacion* App);
    Asistente(string nombreUsuario, string contraseña, const Asistente& Asst);
    virtual ~Asistente();
    void setDni(const string& dni);
    void setCartera(const int& cartera);
    string getDni();
    int getCartera();
    void comprarEntrada(Evento& E);
    void eventosDisponibles();
    void verArtista(Artista& Art);
    void displayUsuario();
    void menu();
protected:
    vector<Entrada*> _listaEntradas;
    string _dni;
    int _cartera;
    Aplicacion* _App;

};

#endif // ASISTENTE_H
