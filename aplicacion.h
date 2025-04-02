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




class Aplicacion{

public:
    Aplicacion();
    ~Aplicacion();
    void displayUsuarios();
    void displayEventos();
private:
    vector<Usuario*> listaUsuarios;
    vector<Evento*> listaEventos;
    vector<Localizacion*> listaLocacizacion;


};

#endif // APLICACION_H
