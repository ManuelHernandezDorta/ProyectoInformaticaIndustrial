#ifndef APLICACION_H
#define APLICACION_H

#include "usuario.h"
#include "administrador.h"
#include "artista.h"
#include "asistente.h"
#include "asistentevip.h"
#include "evento.h"
#include "localizacion.h"

#include <vector>

class Localizacion;


class Aplicacion{

public:
    Aplicacion();
    ~Aplicacion();
    void crearArtista();
    void crearAsistente();
    void crearAdministrador();
    void displayUsuarios();
    void displayEventos();
    void displayLocalizaciones() const;
    Localizacion* getLocalizacion(int index) const;

private:
    vector<Usuario*> _listaUsuarios;
    vector<Evento*> _listaEventos;
    vector<Localizacion*> _listaLocacizaciones;


};

#endif // APLICACION_H
