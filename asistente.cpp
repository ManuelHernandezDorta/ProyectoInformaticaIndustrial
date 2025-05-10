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
    cout << "Tipo: Asistente " << auxvip << ", nombreUsuario: " << _nombreUsuario << ", contraseña: " << _contraseña << ", DNI: " << _dni << ", cartera: " <<_cartera << endl;
}

void Asistente::mostrarEntradas(){
    cout << "Número de Entradas totales: " << _listaEntradas.size() << endl;
    for (unsigned long i = 0; i< _listaEntradas.size(); i++){
            _listaEntradas[i]->displayEntrada();
        }
}

void Asistente::menu(Aplicacion* App){
    int eleccion;
    string continuar = "S";

    while (continuar == "S" || continuar == "s") {
    cout << "Menu: " << endl << "0. Modificar fondos de la cartera" << endl << "1. Ver entradas" <<endl<< "2. Comprar entradas al canal oficial "<<endl<< "3. Ver eventos disponibles"<<endl<< "4. Ver información artista"<<endl<< "5. Mercado secundario"<<endl;
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
    case 5: {
        this->mercadoSecundario(App);
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

void Asistente::mercadoSecundario(Aplicacion* Apli){
    if (_vip){
    int eleccionsecundario;
    int index;
    int precio;
    cout << "Selecciona el tipo de proceso que quieres realizar en el mercado secundario: " << endl << "0. Vender entrada en el mercado secundario  " << endl << "1. Comprar entrada en el mercado secundario " << endl << "2. Mostrar entradas disponibles en el mercado secundario"<<endl;
    cin >> eleccionsecundario;

    switch (eleccionsecundario){

    case 0: {
        cout<<"A continuación se muestra la lista de entradas propia:"<<endl;
        this->mostrarEntradas();
        cout<<"Seleccione el índice de la entrada que quiere vender"<<endl;
        cin>>index;
        Entrada* En=this->getEntrada(index);
        if(En==nullptr){
            cout<<"Volviendo al menú"<<endl;
            return;
        }
        cout<<"Seleccione el precio de reventa de la entrada:"<<endl;
        cin>>precio;
        En->setPrecioMercadoSecundario(precio);
        Apli->anadirEntrada(En);
        break;
    }
    case 1: {
        cout<<"A continuación se muestra la lista de entradas en reventa:"<<endl;
        Apli->displayEntradasMercadoSecundario();
        cout<<"Seleccione el índice de la entrada que quiere comprar"<<endl;
        cin>>index;
        Entrada* En2=Apli->getEntradaMercadoSecundario(index);
        if(En2==nullptr){
            cout<<"Volviendo al menú"<<endl;
            return;
        }
        if(_cartera<En2->getPrecioMercadoSecundario()){
            cout<<"No hay dinero suficiente en la cartera para poder comprar la entrada"<<endl;
            return;
        }else{
            _cartera=_cartera-En2->getPrecioMercadoSecundario();
            cout<<"Se le ha descontado de la cartera el precio de la entrada: "<< En2->getPrecioMercadoSecundario() <<endl;
        }
        int carteraVendedor=En2->getAsistente()->getCartera();                //Cartera vendedor
        carteraVendedor=carteraVendedor+En2->getPrecioMercadoSecundario();    //Sumar dinero al vendedor
        En2->getAsistente()->setCartera(carteraVendedor);                     //Actualizar cartera
        En2->setAsistente(this);                                              //Se asigna la entrada al nuevo usuario
        Apli->eliminarEntradaMercado(En2);                                    //Se elimina la entrada del mercado secundario
        break;
    }
    case 2: {
        cout<<"A continuación se muestra la lista de entradas en reventa:"<<endl;
        Apli->displayEntradasMercadoSecundario();
        break;
    }

    default: {
        cout << "Esa opccion no existe, selecciona una opccion posible" << endl;
        break;
    }

   }
   }else{
        cout<<"El mercado secundario únicamente está disponible para asistentes VIP"<<endl;
    }
}

Entrada* Asistente::getEntrada(int index){
    int aux = _listaEntradas.size();
    if(aux==0){
        cout<<"No hay entradas disponibles"<<endl;
        return nullptr;
    }
    while (index < 0 || index >= aux){
        cout<< "El índice se encuentra fuera de rango, debe estar entre 0 y el numero de usuarios ((" << aux << ") para que sea válido. Introduce el indice de nuevo: " << endl;
        cin >> index;
    }
    return _listaEntradas[index];
}

void Asistente::comprarEntrada(Aplicacion* Apli){
    int index;

    if (_vip){
            cout<<"A continuación se muestra la lista de eventos:"<<endl;
            Apli->displayEventos();
            cout<<"Seleccione el índice del evento del que quiere comprar una entrada"<<endl;
            cin>>index;
            Evento* Ev=Apli->getEvento(index);
            if(Ev==nullptr){
                cout<<"Volviendo al menú"<<endl;
                return;
            }
            if(Apli->fechaConcluida(Ev->getFecha())){
                cout<<"El evento seleccionado ya ha concluido y no se pueden comprar entradas";
                return;
            }
            if(_cartera<Ev->getPrecio()){
                cout<<"No hay dinero suficiente en la cartera para poder comprar la entrada"<<endl;
                return;
            }else{
                _cartera=_cartera-Ev->getPrecio();
                cout<<"Se le ha descontado de la cartera el precio de la entrada: "<< Ev->getPrecio() <<endl;
            }
            Apli->getEvento(index)->comprarEntrada();                      //-1 entrada
            Entrada* miEntrada=new Entrada(this, Apli->getEvento(index));
            _listaEntradas.push_back(miEntrada);

    }else{
        cout<<"A continuación se muestra la lista de eventos:"<<endl;
        Apli->displayEventos();
        cout<<"Seleccione el índice del evento del que quiere comprar una entrada"<<endl;
        cin>>index;
        Evento* Ev=Apli->getEvento(index);
        if(Ev==nullptr){
            cout<<"Volviendo al menú"<<endl;
            return;
        }
        if(Ev->getEventoVip()){
            cout<<"El evento seleccionado es VIP y no puede comprar entradas"<<endl;
            return;
        }
        if(Apli->fechaConcluida(Ev->getFecha())){
            cout<<"El evento seleccionado ya ha concluido y no se pueden comprar entradas";
            return;
        }
        if(Apli->fechaAsistenteUnMes(Ev->getFecha())){
            cout<<"No es posible comprar entradas con más de un mes de antelación"<<endl;
            return;
        }
        if(_cartera<Ev->getPrecio()){
            cout<<"No hay dinero suficiente en la cartera para poder comprar la entrada"<<endl;
            return;
        }else{
            _cartera=_cartera-Ev->getPrecio();
            cout<<"Se le ha descontado de la cartera el precio de la entrada: "<< Apli->getEvento(index)->getPrecio() <<endl;
        }
        Ev->comprarEntrada();                          //-1 entrada
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
    }
    if(Apli->getUsuario(indiceUsuario)->tipoUsuario()=="artista"){
        Apli->getUsuario(indiceUsuario)->displayUsuario();
    }else{
        cout<<"El nombre introducido no pertenece a un artista "<<endl;

    }
}

Usuario* Asistente::editar(){
    int eleccion;
    cout << "Que campo desea editar: " << endl << "0. nombre de usuario" << endl << "1. contraseña" << endl <<"2. DNI" << endl << "3. cartera" << endl << "4. estado VIP" << endl;
    cin >> eleccion;

    switch (eleccion) {

    case 0:{
        string nuevoNombre;
        cout << "Introduce el nuevo nombre: " << endl;
        cin >> nuevoNombre;

        Usuario* nuevoAsistente = new Asistente(nuevoNombre, _contraseña, _dni, _cartera, _vip);
        return nuevoAsistente;

        break;
        }

    case 1:{
        string nuevaContraseña;
        cout << "Introduce la nueva contraseña: " << endl;
        cin >> nuevaContraseña;

        Usuario* nuevoAsistente = new Asistente(_nombreUsuario, nuevaContraseña, _dni, _cartera, _vip);
        return nuevoAsistente;

        break;
        }

    case 2:{
        string nuevoDni;
        cout << "Introduce el nuevo DNI: " << endl;
        cin >> nuevoDni;

        Usuario* nuevoAsistente = new Asistente(_nombreUsuario, _contraseña, nuevoDni, _cartera, _vip);
        return nuevoAsistente;

        break;
        }

    case 3:{
        int nuevaCartera;
        cout << "Introduce el nuevo valor de la cartera: " << endl;
        cin >> nuevaCartera;

        Usuario* nuevoAsistente = new Asistente(_nombreUsuario, _contraseña, _dni, nuevaCartera, _vip);
        return nuevoAsistente;

        break;
        }

    case 4:{
        string eleccion;
        bool nuevoVip;
        cout << "Introduce el nuevo estado de Vip: (S/N)" << endl;
        cin >> eleccion;

        if (eleccion == "S" || eleccion == "s"){
            nuevoVip = true;
        }
        else{
            nuevoVip= false;
        }

        Usuario* nuevoAsistente = new Asistente(_nombreUsuario, _contraseña, _dni, _cartera, nuevoVip);
        return nuevoAsistente;

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
