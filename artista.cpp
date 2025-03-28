#include "artista.h"

Artista::Artista(){}

Artista::Artista(string nombreArtista, string estiloMusical, string descripcion, vector<Evento*> listaEventosArtista){
    _nombreArtista=nombreArtista;
    _estiloMusical=estiloMusical;
    _descripcion=descripcion;
    vector<Evento*> _listaEventosArtista = listaEventosArtista;

}
