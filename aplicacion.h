#ifndef APLICACION_H
#define APLICACION_H

#include "usuario.h"
#include "administrador.h"
#include "artista.h"
#include "asistente.h"
#include "evento.h"
#include "localizacion.h"
#include "entrada.h"

#include <vector>
#include <fstream>

class Localizacion;
class Entrada;

class Aplicacion{

public:
    Aplicacion();
    ~Aplicacion();
    void displayUsuarios();
    void displayEventos();
    void displayLocalizaciones();
    void displayEntradasMercadoSecundario();
    void anadirUsuario(Usuario* U);
    void anadirEvento(Evento* E);
    void anadirLocalizacion(Localizacion* Loc);
    void anadirEntrada(Entrada* entrada);
    void eliminarUsuario(Usuario* U);
    void eliminarEvento(Evento* E);
    void eliminarLocalizacion(Localizacion* Loc);
    void eliminarEntradaMercado(Entrada* entrada);
    bool contieneEntrada(Entrada* entrada);
    Localizacion* getLocalizacion(int index);
    Evento* getEvento(int index);
    Usuario* getUsuario(int index);
    Entrada* getEntradaMercadoSecundario(int index);
    int buscarUsuario(const string& nombreUsuario);
    bool comprobarContraseña(const string& nombreUsuario, const string& contraseña);
    void menuPrincipal();
    void iniciarSesion();
    void crearUsuario();
    void crearUsuarioRoot();
    void crearAsistente();
    void crearArtista();
    void crearLocalizacion();
    void crearAdministrador();
    int getfechaActual();
    bool fechaConcluida(int fecha);
    bool fechaAsistenteUnMes(int fecha);
    void borrarUsuario();
    void editarUsuario();
    void guardarUsuarios();
    void cargarUsuarios();

private:
    vector<Usuario*> _listaUsuarios;
    vector<Evento*> _listaEventos;
    vector<Localizacion*> _listaLocalizaciones;
    vector<Entrada*> _listaEntradasMercadoSecundario;


};

#endif // APLICACION_H
