#include "artista.h"

Artista::Artista() : Usuario(),_listaEventosArtista(){
    _nombreArtista="";
    _estiloMusical="";
    _descripcion="";
}

Artista::Artista(string nombreUsuario, string contraseña,string nombreArtista, string estiloMusical, string descripcion, vector<Evento*> listaEventosArtista) : Usuario(nombreUsuario,contraseña){
    _nombreArtista=nombreArtista;
    _estiloMusical=estiloMusical;
    _descripcion=descripcion;
    _listaEventosArtista=listaEventosArtista;

}

Artista::Artista(string nombreUsuario, string contraseña, const Artista& Art) : Usuario(nombreUsuario,contraseña){
    _nombreArtista=Art._nombreArtista;
    _estiloMusical=Art._estiloMusical;
    _descripcion=Art._descripcion;
    _listaEventosArtista=Art._listaEventosArtista;
}

Artista::~Artista(){
    for (Evento* evento : _listaEventosArtista) {
        delete evento;
    }
}

void Artista::actualizarNombreArtista(const string &nombre){
    _nombreArtista=nombre;
}

void Artista::actualizarEstiloArtista(const string &estiloMusical){
    _estiloMusical=estiloMusical;
}

void Artista::actualizarDescripcionArtista(const string &descripcion){
    _descripcion=descripcion;
}

string Artista::getDescripcionArtista(){
    return _descripcion;
}

string Artista::getEstiloArtista(){
    return _estiloMusical;
}

string Artista::getNombreArtista(){
    return _nombreArtista;
}

void Artista::displayUsuario(){
    cout<<"El artista "<<_nombreArtista<<" con nombre de usuario "<<_nombreUsuario<< "y con estilo de música "<<_estiloMusical<<" posee la siguiente descripción "<<_descripcion;
}

void Artista::crearEvento(){
    string nombreEvento;
    int dia, mes, ano, precio;
    bool esVip;
    Localizacion* loc=nullptr; //Tenemos que mirar como hacemos para que el artista seleccione una localizacion para el evento ¿Lista de Localizaciones?

    cout << "Introduce el nombre del evento: ";
    cin >> nombreEvento;

    cout << "Introduce la fecha (día, mes, año): ";
    cin >> dia >> mes >> ano;

    cout << "Introduce el precio del evento: ";
    cin >> precio;

    cout << "¿Es un evento VIP? (1 = Sí, 0 = No): ";
    cin >> esVip;

    Evento* miEvento=new Evento(nombreEvento, dia, mes, ano, precio, esVip, loc, this);
    _listaEventosArtista.push_back(miEvento);

    cout<<"Evento creado exitosamente"<<endl;
}
