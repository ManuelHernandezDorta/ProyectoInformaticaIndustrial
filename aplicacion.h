#ifndef APLICACION_H
#define APLICACION_H

#include "usuario.h"
#include "administrador.h"
#include "artista.h"
#include "asistente.h"
#include "evento.h"
#include "localizacion.h"

#include <vector>

class Localizacion;


class Aplicacion{

public:
    Aplicacion();
    ~Aplicacion();
    void displayUsuarios();
    void displayEventos();
    void displayEventosVip();
    void displayLocalizaciones();
    void anadirUsuario(Usuario* U);
    void anadirEvento(Evento* E);
    void anadirLocalizacion(Localizacion* Loc);
    void eliminarUsuario(Usuario* U);
    void eliminarEvento(Evento* E);
    void eliminarLocalizacion(Localizacion* Loc);
    Localizacion* getLocalizacion(int index);
    Evento* getEvento(int index);
    int buscarUsuario(const string& nombreUsuario);
    bool comprobarContraseña(const string& nombreUsuario, const string& contraseña);
    void menuPrincipal();
    void iniciarSesion();
    void crearUsuario();
    void crearAsistente();
    void crearArtista();
    int getfechaActual();

private:
    vector<Usuario*> _listaUsuarios;
    vector<Evento*> _listaEventos;
    vector<Localizacion*> _listaLocalizaciones;


};

#endif // APLICACION_H
