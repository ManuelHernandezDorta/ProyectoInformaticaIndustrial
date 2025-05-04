#include "asistente.h"

Asistente::Asistente() : Usuario(), _listaEntradas(){
    _dni="";
    _cartera=0;
    _vip=false;
}

Asistente::Asistente(string nombreUsuario, string contraseña, string dni, int cartera, bool vip) : Usuario(nombreUsuario,contraseña){
    _dni=dni;
    _cartera=cartera;
    _vip=vip;

}


Asistente::Asistente(string nombreUsuario, string contraseña,const Asistente& Asst) : Usuario(nombreUsuario, contraseña){
    _dni=Asst._dni;
    _cartera=Asst._cartera;
    _listaEntradas=Asst._listaEntradas;
}

Asistente::~Asistente(){
    for (unsigned i = 0; i < _listaEntradas.size(); i++){
        delete _listaEntradas[i];
    }
}

void Asistente::setCartera(const int &cartera){
    _cartera=cartera;
}

void Asistente::setDni(const string &dni){
    _dni=dni;
}

string Asistente::getDni(){
    return _dni;
}

int Asistente::getCartera(){
    return _cartera;
}

bool Asistente::getVip(){
    return _vip;
}

void Asistente::displayUsuario(){
    string auxvip;
    if(_vip){
        auxvip="vip";
    }else{
        auxvip= "no vip";
    }
    cout << "Tipo: Asistente " << auxvip << ", con nombreUsuario: " << _nombreUsuario << ", contraseña: " << _contraseña << ", DNI: " << _dni << ", cartera: " <<_cartera << endl;
}

void Asistente::mostrarEntradas(){
    cout << "Número de Entradas totales: " << _listaEntradas.size() << endl;
    for (unsigned long i = 0; i< _listaEntradas.size(); i++){
            _listaEntradas[i]->displayEntrada();
        }
}

void Asistente::menu(Aplicacion* App){
    int eleccion;
    string continuar;

    cout << "Menu: " << endl << "0. Modificar fondos de la cartera" << endl << "1. Ver entradas" <<endl<< "2. Comprar entradas "<<endl<< "3. Ver eventos disponibles"<<endl<< "4. Ver información artista"<<endl;
    cin >> eleccion;

    switch (eleccion){

    case 0: {
        int nuevaCartera;
        cout<<"Ingrese los fondos para actualizar su cartera:"<<endl;
        cin>>nuevaCartera;
        this->setCartera(nuevaCartera);
        break;
    }
    case 1: {
        this->mostrarEntradas();
        break;
    }
    case 2: {
        this->comprarEntrada(App);
        break;
    }
    case 3: {
        App->displayEventos();
        break;
    }
    case 4: {
        this->informaciónArtista(App);
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

void Asistente::comprarEntrada(Aplicacion* Apli){
    int index;

    if (_vip){
        int eleccion;
        cout << "Selecciona que tipo de compra quieres realizar: " << endl << "0. Canal oficial de venta  " << endl << "1. Mercado de segunda mano " << endl;
        cin >> eleccion;

        switch (eleccion){

        case 0: {
            cout<<"A continuación se muestra la lista de eventos:"<<endl;
            Apli->displayEventos();
            cout<<"Seleccione el índice del evento del que quiere comprar una entrada"<<endl;
            cin>>index;
            if(Apli->fechaConcluida(Apli->getEvento(index)->getFecha())){
                cout<<"El evento seleccionado ya ha concluido y no se pueden comprar entradas";
                this->comprarEntrada(Apli);                                                 //o meter un bucle while para que siga introduciendo índices
            }
            if(_cartera<Apli->getEvento(index)->getPrecio()){
                cout<<"No hay dinero suficiente en la cartera para poder comprar la entrada"<<endl;
                this->comprarEntrada(Apli);
            }else{
                _cartera=_cartera-Apli->getEvento(index)->getPrecio();
                cout<<"Se le ha descontado de la cartera el precio de la entrada: "<< Apli->getEvento(index)->getPrecio() <<endl;
            }
            Entrada* miEntrada=new Entrada(this, Apli->getEvento(index));
            _listaEntradas.push_back(miEntrada);
                break;
        }

        case 1: {
            cout<<"A continuación se muestra las entradas disponibles en el mercado secundario:"<<endl;
                break;
        }

        default: {
                cout << "Esa opccion no existe, selecciona una opccion posible" << endl;
                break;
        }
        }

    }else{
        cout<<"A continuación se muestra la lista de eventos:"<<endl;
        Apli->displayEventos();
        cout<<"Seleccione el índice del evento del que quiere comprar una entrada"<<endl;
        cin>>index;
        if(Apli->getEvento(index)->getEventoVip()){
            cout<<"El evento seleccionado es VIP y no puede comprar entradas"<<endl;
            this->comprarEntrada(Apli);
        }
        if(Apli->fechaConcluida(Apli->getEvento(index)->getFecha())){
            cout<<"El evento seleccionado ya ha concluido y no se pueden comprar entradas";
            this->comprarEntrada(Apli);                                                //o meter un bucle while para que siga introduciendo índices
        }
        if(Apli->fechaAsistenteUnMes(Apli->getEvento(index)->getFecha())){
            cout<<"No es posible comprar entradas con más de un mes de antelación"<<endl;
            this->comprarEntrada(Apli);                                                 //o meter un bucle while para que siga introduciendo índices
        }
        if(_cartera<Apli->getEvento(index)->getPrecio()){
            cout<<"No hay dinero suficiente en la cartera para poder comprar la entrada"<<endl;
            this->comprarEntrada(Apli);
        }else{
            _cartera=_cartera-Apli->getEvento(index)->getPrecio();
            cout<<"Se le ha descontado de la cartera el precio de la entrada: "<< Apli->getEvento(index)->getPrecio() <<endl;
        }
        Entrada* miEntrada=new Entrada(this, Apli->getEvento(index));
        _listaEntradas.push_back(miEntrada);

    }

}

string Asistente::tipoUsuario(){
    string tipo;
    tipo="asistente";
    return tipo;
}

void Asistente::informaciónArtista(Aplicacion *Apli){
    string nombre;
    cout << "Introduce el nombre de un artista del que se quiera ver la información: " << endl;
    cin >>  nombre;
    int indiceUsuario = Apli->buscarUsuario(nombre);
    if (indiceUsuario < 0){
        cout << "No existe ningun usuario con ese nombre" << endl;
        this->informaciónArtista(Apli);
    }
    if(Apli->getUsuario(indiceUsuario)->tipoUsuario()=="artista"){
        Apli->getUsuario(indiceUsuario)->displayUsuario();
    }else{
        cout<<"El nombre introducido no pertenece a un artista, introduce otro: "<<endl;
        this->informaciónArtista(Apli);
    }
}

Usuario* Asistente::editar(){

}
