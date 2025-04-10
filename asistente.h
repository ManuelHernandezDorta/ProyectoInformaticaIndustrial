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
    Asistente(string nombreUsuario, string contraseña, string dni, int cartera, bool vip);
    Asistente(string nombreUsuario, string contraseña, const Asistente& Asst);
    virtual ~Asistente();
    void setDni(const string& dni);
    void setCartera(const int& cartera);
    string getDni();
    int getCartera();
    bool getVip();
    void comprarEntrada(Evento& E);
    void eventosDisponibles();
    void verArtista(Artista& Art);
    void displayUsuario();
    void menu(Aplicacion* App);
private:
    vector<Entrada*> _listaEntradas;
    string _dni;
    int _cartera;
    bool _vip;

};

#endif // ASISTENTE_H
