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
    for (unsigned long i = 0; i < _listaEventosArtista.size(); i++){
        delete _listaEventosArtista[i];
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
    cout<<"El artista "<<_nombreArtista<<" con nombre de usuario "<<_nombreUsuario<< "y con estilo de música "<<_estiloMusical<<" posee la siguiente descripción "<<_descripcion << endl;
}

void Artista::crearEvento(Aplicacion* Apli){
    string nombreEvento;
    int dia, mes, ano, precio, index, fecha;
    bool esVip;

    Apli->displayLocalizaciones();
    cout<< "Introduce el índice de la Localizacion en la que deseas celebrar el evento: " <<endl;
    cin>>index;

    cout << "Introduce el nombre del evento: ";
    cin >> nombreEvento;

    cout << "Introduce la fecha (día, mes, año): ";
    cin >> dia >> mes >> ano;
    fecha=ano*1000+mes*100+dia;
    Apli->getLocalizacion(index)->coincideFecha(fecha);


    cout << "Introduce el precio del evento: ";
    cin >> precio;

    cout << "¿Es un evento VIP? (1 = Sí, 0 = No): ";
    cin >> esVip;

    Evento* miEvento=new Evento(nombreEvento, dia, mes, ano, precio, esVip, Apli->getLocalizacion(index), this);
    _listaEventosArtista.push_back(miEvento);                    //Añadimos el evento a la lista de eventos del artista
    Apli->getLocalizacion(index)->agregarEvento(miEvento);      //Agregamos el evento a la lista de eventos de la localización
    Apli->anadirEvento(miEvento);                              //Añadimos el evento a la lista de eventos de la aplicacion

    cout<<"Evento creado"<<endl;
}

void Artista::eliminarEvento(Evento* E, Aplicacion* Apli) {
    for (unsigned i = 0; i < _listaEventosArtista.size(); i++) {

        if (_listaEventosArtista[i] == E) {
            cout << "Se procede a eliminar el evento: " << E->getNombre() << endl;
            delete _listaEventosArtista[i];                                          //liberamos memoria dinámica
            _listaEventosArtista.erase(_listaEventosArtista.begin() + i);            //eliminamos el evento del vector del artista
            Apli->eliminarEvento(E);                                                 //eliminamos el evento del vector de la aplicación
            E->getLocalizacion()->eliminarEvento(E);                                 //eliminamos el evento asignado a su localización
            cout << "Evento eliminado correctamente." << endl;
            return;
        }
    }
    cout << "El evento no se encuentra en la lista." << endl;
}

void Artista::editarEvento(Evento* E,Aplicacion* Apli){
        for (unsigned i = 0; i < _listaEventosArtista.size(); ++i) {
            if (_listaEventosArtista[i] == E) {
                string nuevoNombre;
                int nuevoDia, nuevoMes, nuevoAno, nuevoPrecio, index;
                bool nuevoEventoVip;

                cout << "Modificar evento: " << endl;
                cout << "Ingrese el nuevo nombre del evento: "<<endl;
                cin >> nuevoNombre;
                    E->setNombre(nuevoNombre);

                cout << "Ingrese el nuevo día del evento: "<<endl;
                cin >> nuevoDia;
                cout << "Ingrese el nuevo mes del evento: "<<endl;
                cin >> nuevoMes;
                cout << "Ingrese el nuevo año del evento: "<<endl;
                cin >> nuevoAno;
                    E->setFecha(nuevoDia, nuevoMes, nuevoAno);

                cout << "Ingrese el nuevo precio del evento: ";
                cin >> nuevoPrecio;
                    E->setPrecio(nuevoPrecio);

                cout << "¿Es el evento VIP? (1 para sí, 0 para no): ";
                cin >> nuevoEventoVip;
                    E->setEventoVip(nuevoEventoVip);

                cout << "Ingrese un nuevo índice para la localizacion del evento, a continuación se muestran las disponibles: " <<endl;
                Apli->displayLocalizaciones();
                cin>>index;
                E->setLocalizacion(Apli->getLocalizacion(index));

                cout << "El evento ha sido editado correctamente." << endl;
                return;
            }
        }
        cout << "No se encontró el evento para editar." << endl;
}

void Artista::menu(Aplicacion* App){

}

