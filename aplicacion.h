#ifndef APLICACION_H
#define APLICACION_H

#include "usuario.h"
#include "administrador.h"
#include "evento.h"
#include <vector>




class Aplicacion{

public:
    Aplicacion();
    void displayUsuarios();
    void displayEventos();
private:
    vector<Usuario*> listaUsuarios;
    vector<Evento*> listaEventos;


};

#endif // APLICACION_H
