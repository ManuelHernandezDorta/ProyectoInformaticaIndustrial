#ifndef ARTISTA_H
#define ARTISTA_H
#include "evento.h"
#include "usuario.h"
#include "aplicacion.h"
#include <string>
#include <vector>


using namespace std;

class Aplicacion;

class Artista : public Usuario
{
public:
    Artista();
    Artista(string nombreUsuario, string contraseña,string nombreArtista, string estiloMusical, string descripcion, vector<Evento*> listaEventosArtista);
    Artista(string nombreUsuario, string contraseña, const Artista& Art);
    virtual ~Artista();
    void actualizarNombreArtista(const string& nombre);
    void actualizarEstiloArtista(const string& estiloMusical);
    void actualizarDescripcionArtista(const string& descripcion);
    string getNombreArtista();
    string getEstiloArtista();
    string getDescripcionArtista();
    void displayUsuario();
    void eliminarEvento(Evento& E);
    void crearEvento(Aplicacion* Apli);
    void editarEvento(Evento& E,Aplicacion* Apli);

private:
    string _estiloMusical;
    string _descripcion;
    string _nombreArtista;
    vector<Evento*> _listaEventosArtista;
};

#endif // ARTISTA_H
