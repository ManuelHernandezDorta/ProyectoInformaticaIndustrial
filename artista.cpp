#include "artista.h"

Artista::Artista() : Usuario(),_listaEventosArtista(){
    _nombreArtista="";
    _estiloMusical="";
    _descripcion="";
}

Artista::Artista(string nombreUsuario, string contraseña,string nombreArtista, string estiloMusical, string descripcion): Usuario(nombreUsuario,contraseña){
    _nombreArtista=nombreArtista;
    _estiloMusical=estiloMusical;
    _descripcion=descripcion;

}


Artista::Artista(string nombreUsuario, string contraseña, const Artista& Art) : Usuario(nombreUsuario,contraseña){
    _nombreArtista=Art._nombreArtista;
    _estiloMusical=Art._estiloMusical;
    _descripcion=Art._descripcion;
    _listaEventosArtista=Art._listaEventosArtista;
}



Artista::~Artista(){}

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
    cout << "Tipo: Artista, nombreUsuario: " << _nombreUsuario << ", contraseña: " << _contraseña << ", nombre de artista: " << _nombreArtista << ", estilo musical: " << _estiloMusical << ",  descripccion: " << _descripcion << "con lista de eventos:" << endl;
    this->displayListaEventos();
}

void Artista::displayListaEventos(){
    cout << "Número de Eventos totales: " << _listaEventosArtista.size() << endl;
    for (unsigned long i = 0; i< _listaEventosArtista.size(); i++){
        _listaEventosArtista[i]->displayEvento();
    }
}

void Artista::crearEvento(Aplicacion* Apli){
    string nombreEvento;
    int precio, index, fecha;
    bool esVip;

    Apli->displayLocalizaciones();
    cout<< "Introduce el índice de la Localizacion en la que deseas celebrar el evento: " <<endl;
    cin>>index;

    cout << "Introduce el nombre del evento: ";
    cin >> nombreEvento;

    cout << "Introduce la fecha (año,mes,dia): ";
    cin >> fecha;
    Apli->getLocalizacion(index)->coincideFecha(fecha);


    cout << "Introduce el precio del evento: ";
    cin >> precio;

    cout << "¿Es un evento VIP? (1 = Sí, 0 = No): ";
    cin >> esVip;

    Evento* miEvento=new Evento(nombreEvento, fecha, precio, esVip, Apli->getLocalizacion(index), this);
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
                int nuevaFecha, nuevoPrecio, index;
                bool nuevoEventoVip;

                cout << "Modificar evento: " << endl;
                cout << "Ingrese el nuevo nombre del evento: "<<endl;
                cin >> nuevoNombre;
                    E->setNombre(nuevoNombre);

                cout << "Ingrese el nueva fecha del evento (año,mes,dia) incluyendo ceros si son menores a 2 digitos: "<<endl;
                cin>> nuevaFecha;
                    E->setFecha(nuevaFecha);

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
    int eleccion;
    string continuar;

    cout << "Menu: " << endl << "0. Crear evento" << endl << "1. Modificar evento" <<endl<< "2. Eliminar evento "<<endl<< "3. Actualizar descripción"<<endl<< "4. Actualizar estilo"<<endl;
    cin >> eleccion;

    switch (eleccion){

    case 0: {
        this->crearEvento(App);
        break;
    }
    case 1: {
        int index;
        cout<<"Debe seleccionar un índice de evento para editar de su lista que se muestra a continuación:"<<endl;
        this->displayListaEventos();
        cin>>index;
        this->editarEvento(this->getEventoArtista(index),App);
        break;
    }
    case 2: {
        int index;
        cout<<"Debe seleccionar un índice de evento para eliminar de su lista que se muestra a continuación:"<<endl;
        this->displayListaEventos();
        cin>>index;
        this->eliminarEvento(this->getEventoArtista(index),App);
        break;
    }
    case 3: {
        string nuevaDescripcion;
        cout<<"Introduce una nueva descripción:"<<endl;
        cin>>nuevaDescripcion;
        this->actualizarDescripcionArtista(nuevaDescripcion);
        break;
    }
    case 4: {
        string nuevoEstilo;
        cout<<"Introduce un nuevo estilo musical:"<<endl;
        cin>>nuevoEstilo;
        this->actualizarEstiloArtista(nuevoEstilo);
        break;
    }
    default: {
            cout << "Esa opccion no existe, selecciona una opccion posible" << endl;
            break;
    }
    }

    cout << "Desea realizar otra acion: (S/N): " << endl;
    cin >> continuar;

    if (continuar == "S" || continuar == "s"){
        this->menu(App);
    }
    else{
        cout << "Cerrando sesion..." << endl;
        return;
    }

}

Evento* Artista::getEventoArtista(int index){
    int aux = _listaEventosArtista.size();
    while (index < 0 || index >= aux){
        cout<< "El índice se encuentra fuera de rango, debe estar entre 0 y el numero de localizaciones ((" << aux << ") para que sea válido. Introduce el indice de nuevo: " << endl;
        cin >> index;
    }
    return _listaEventosArtista[index];
}

string Artista::tipoUsuario(){
    string tipo;
    tipo="artista";
    return tipo;
}

Usuario* Artista::editar(){

}
