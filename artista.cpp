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
    cout << "Tipo: Artista, nombreUsuario: " << _nombreUsuario << ", contraseña: " << _contraseña << ", nombre de artista: " << _nombreArtista << ", estilo musical: " << _estiloMusical << ",  descripccion: " << _descripcion << "lista de eventos: " << endl;
    this->displayListaEventos();
}

void Artista::displayListaEventos(){
    cout << "Número de Eventos totales: " << _listaEventosArtista.size() << endl;
    for (unsigned long i = 0; i< _listaEventosArtista.size(); i++){
        cout<<i<<"-";
        _listaEventosArtista[i]->displayEvento();
    }
}

ostream& operator<<(ostream& os, Artista& artista){
    artista.displayListaEventos();
    return os;
}

void Artista::crearEvento(Aplicacion* Apli){
    string nombreEvento;
    int precio, index, fecha;
    bool esVip;

    Apli->displayLocalizaciones();
    cout<< "Introduce el índice de la Localizacion en la que deseas celebrar el evento: " <<endl;
    cin>>index;
    Localizacion* loc=Apli->getLocalizacion(index);
    if(loc==nullptr){
        cout<<"Volviendo al menú"<<endl;
        return;
    }

    cout << "Introduce el nombre del evento: ";
    cin >> nombreEvento;

    cout << "Introduce la fecha (año,mes,dia) con formato (AAAA/MM/DD): ";
    cin >> fecha;
    loc->coincideFecha(fecha);


    cout << "Introduce el precio del evento: ";
    cin >> precio;

    cout << "¿Es un evento VIP? (1 = Sí, 0 = No): ";
    cin >> esVip;

    Evento* miEvento=new Evento(nombreEvento, fecha, precio, esVip, loc, this);
    _listaEventosArtista.push_back(miEvento);                    //Añadimos el evento a la lista de eventos del artista
    loc->agregarEvento(miEvento);      //Agregamos el evento a la lista de eventos de la localización
    Apli->anadirEvento(miEvento);                              //Añadimos el evento a la lista de eventos de la aplicacion

    cout<<"Evento creado"<<endl;
}

void Artista::eliminarEvento(Evento* E, Aplicacion* Apli) {
    for (unsigned i = 0; i < _listaEventosArtista.size(); i++) {

        if (_listaEventosArtista[i] == E) {
            cout << "Se procede a eliminar el evento: " << E->getNombre() << endl;
            Apli->eliminarEvento(E);                                                 //eliminamos el evento del vector de la aplicación
            E->getLocalizacion()->eliminarEvento(E);                                 //eliminamos el evento asignado a su localización
            _listaEventosArtista.erase(_listaEventosArtista.begin() + i);            //eliminamos el evento del vector del artista
            cout << "Evento eliminado correctamente." << endl;
            return;
        }
    }
    cout << "El evento no se encuentra en la lista." << endl;
}

void Artista::editarEvento(Evento* E,Aplicacion* Apli){
        for (unsigned i = 0; i < _listaEventosArtista.size(); ++i) {
            if (_listaEventosArtista[i] == E) {
                int eleccion;
                cout << "Menu Modificar: " << endl << "0. Nombre evento" << endl << "1. Fecha" <<endl<< "2. Precio" << endl << "3. Localizacion" <<endl;
                cin >> eleccion;

                switch (eleccion){

                case 0: {
                    string nuevoNombre;
                    cout << "Introduce el nuevo nombre: " << endl;
                    cin >> nuevoNombre;
                    E->setNombre(nuevoNombre);
                    break;
                }
                case 1: {
                    int nuevaFecha;
                    cout << "Introduce la nueva fecha: " << endl;
                    cin >> nuevaFecha;
                    E->setFecha(nuevaFecha);
                    break;
                }
                case 2: {
                    int nuevoPrecio;
                    cout<<"Introduce un nuevo precio:"<<endl;
                    cin>>nuevoPrecio;
                    E->setPrecio(nuevoPrecio);
                    break;
                }
                case 3: {
                    int index;
                    cout << "Ingrese un nuevo índice para la localizacion del evento, a continuación se muestran las disponibles: " <<endl;
                    Apli->displayLocalizaciones();
                    cin>>index;
                    Localizacion* loc=Apli->getLocalizacion(index);
                    if(loc==nullptr){
                        cout<<"Volviendo al menú"<<endl;
                        return;
                    }
                    E->setLocalizacion(loc);
                    break;
                }

                default:{
                    cout << "Esa no es una opcion valida, vuelve a intentarlo" << endl;
                    this->editarEvento(E,Apli);
                    break;
                    }
                }
            }
        }
}


void Artista::menu(Aplicacion* App){
    int eleccion;
    string continuar = "S";

    while (continuar == "S" || continuar == "s") {

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
        cout<<*this;
        cin>>index;
        Evento* Ev=this->getEventoArtista(index);
        if(Ev==nullptr){
            cout<<"Volviendo al menú"<<endl;
            continue;
        }
        this->editarEvento(Ev,App);
        break;
    }
    case 2: {
        int index;
        cout<<"Debe seleccionar un índice de evento para eliminar de su lista que se muestra a continuación:"<<endl;
        this->displayListaEventos();
        cin>>index;
        Evento* Ev=this->getEventoArtista(index);
        if(Ev==nullptr){
            cout<<"Volviendo al menú"<<endl;
            continue;
        }
        this->eliminarEvento(Ev,App);
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
    }
        cout << "Cerrando sesion..." << endl;
        return;
}

Evento* Artista::getEventoArtista(int index){
    int aux = _listaEventosArtista.size();
    if(aux==0){
        cout<<"No hay eventos propios disponibles"<<endl;
        return nullptr;
    }
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
    int eleccion;

    cout << "Menu: " << endl << "0. Nombre usuario" << endl << "1. Contraseña" <<endl<< "2. Modificar estilo musical" << endl << "3. Modificar descripción" <<endl<< "4. Modificar nombre "<<endl;
    cin >> eleccion;

    switch (eleccion){


    case 0: {
        string nuevoNombre;
        cout << "Introduce el nuevo nombre: " << endl;
        cin >> nuevoNombre;

        Usuario* nuevoArtista = new Artista(nuevoNombre, _contraseña, _nombreArtista, _estiloMusical, _descripcion);
        return nuevoArtista;
        break;
    }
    case 1: {
        string nuevaContraseña;
        cout << "Introduce la nueva contraseña: " << endl;
        cin >> nuevaContraseña;

        Usuario* nuevoArtista = new Artista(_nombreUsuario, nuevaContraseña, _nombreArtista, _estiloMusical, _descripcion);
        return nuevoArtista;
        break;
    }
    case 2: {
        string nuevoEstilo;
        cout<<"Introduce un nuevo estilo musical:"<<endl;
        cin>>nuevoEstilo;
        this->actualizarEstiloArtista(nuevoEstilo);
        return this;
        break;
    }
    case 3: {
        string nuevaDescripcion;
        cout<<"Introdruce la nueva descripcion del artista: "<<endl;
        cin>>nuevaDescripcion;
        this->actualizarDescripcionArtista(nuevaDescripcion);
        return this;
        break;
    }
    case 4: {
        string nuevoNombre;
        cout<<"Introduce un nuevo nombre para el artista:"<<endl;
        cin>>nuevoNombre;
        this->actualizarNombreArtista(nuevoNombre);
        return this;
        break;
    }
    default:{
        cout << "Esa no es una opcion valida, vuelve a intentarlo" << endl;
        return this;
        this->editar();
        break;
        }
    }
}

