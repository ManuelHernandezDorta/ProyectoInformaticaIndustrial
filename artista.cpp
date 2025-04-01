#include "artista.h"

Artista::Artista(){
    _nombreArtista="";
    _estiloMusical="";
    _descripcion="";
}

Artista::Artista(string nombreArtista, string estiloMusical, string descripcion, vector<Evento*> listaEventosArtista){
    _nombreArtista=nombreArtista;
    _estiloMusical=estiloMusical;
    _descripcion=descripcion;
    _listaEventosArtista=listaEventosArtista;

}

Artista::~Artista(){}

void Artista::displayUsuario(){

}
