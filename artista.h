#ifndef ARTISTA_H
#define ARTISTA_H
#include "evento.h"
#include "usuario.h"
#include <string>


using namespace std;

class Artista : public Usuario
{
public:
    Artista();
    Artista(string nombreArtista, string estiloMusical, string descripcion, vector<Evento*> _listaEventosArtista);
    Artista(const Artista& Art);
    ~Artista();
    void actualizarNombreArtista(const string& nombre);
    void actualizarEstiloArtista(const string& estiloMusical);
    void actualizarDescripcionArtista(const string& descripcion);
    string getNombreArtista();
    string getEstiloArtista();
    string getDescripcionArtista();
    void displayUsuario();
    void eliminarEvento(Evento& E);
    void crearEvento(Evento& E);
    void editarEvento(Evento& E);



private:
    string _estiloMusical;
    string _descripcion;
    string _nombreArtista;
    vector<Evento*> _listaEventosArtista;
};

#endif // ARTISTA_H
