#include "aplicacion.h"
#include <typeinfo>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>


Aplicacion::Aplicacion(){

    Administrador* root =  new Administrador ("root", "root");
    _listaUsuarios.push_back(root);

}

Aplicacion::~Aplicacion(){
    for (unsigned long i = 0; i < _listaEventos.size(); i++){
        delete _listaEventos[i];
    }
    for (unsigned long i = 0; i < _listaLocalizaciones.size(); i++){
        delete _listaLocalizaciones[i];
    }
    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){
        delete _listaUsuarios[i];
    }
    for (unsigned long i = 0; i < _listaEntradasMercadoSecundario.size(); i++){
        delete _listaEntradasMercadoSecundario[i];
    }
}

void Aplicacion::displayUsuarios(){
    cout << "Numero total de usuarios: " << _listaUsuarios.size() << endl;
    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){
        cout<<i<<"-";
        _listaUsuarios[i]->displayUsuario();
    }
}

void Aplicacion::displayLocalizaciones(){
        cout << "Número de localizaciones totales: " << _listaLocalizaciones.size() << endl;
        for (unsigned long i = 0; i< _listaLocalizaciones.size(); i++){
            cout<<i<<"-";
            _listaLocalizaciones[i]->displayLocalizacion();
        }
}

void Aplicacion::displayEventos(){
    cout << "Número de Eventos totales: " << _listaEventos.size() << endl;
    for (unsigned long i = 0; i< _listaEventos.size(); i++){
        cout<<i<<"-";
        _listaEventos[i]->displayEvento();
    }
}

void Aplicacion::displayEntradasMercadoSecundario(){
    cout << "Número de Entradas totales: " << _listaEntradasMercadoSecundario.size() << endl;
    for (unsigned long i = 0; i< _listaEntradasMercadoSecundario.size(); i++){
        cout<<i<<"-";
        _listaEntradasMercadoSecundario[i]->displayEntradaMercadoSecundario();
    }
}

void Aplicacion::anadirEvento(Evento* E){
    _listaEventos.push_back(E);
}

void Aplicacion::anadirLocalizacion(Localizacion *Loc){
    _listaLocalizaciones.push_back(Loc);
}

void Aplicacion::anadirUsuario(Usuario *U){
    _listaUsuarios.push_back(U);
}

void Aplicacion::anadirEntrada(Entrada *entrada){
    _listaEntradasMercadoSecundario.push_back(entrada);
}

void Aplicacion::eliminarEvento(Evento* E){
    for(unsigned i=0;i<_listaEventos.size();i++){
        if (_listaEventos[i] == E) {
            delete _listaEventos[i];
            _listaEventos.erase(_listaEventos.begin() + i);
            cout << "Evento eliminado correctamente de la lista de eventos globales"<< endl;
            return;
         }
    }
    cout<<"El evento no se encuentra en la lista"<<endl;
}

void Aplicacion::eliminarLocalizacion(Localizacion* Loc){
    for(unsigned i=0;i<_listaLocalizaciones.size();i++){
        if (_listaLocalizaciones[i] == Loc) {
            delete _listaLocalizaciones[i];
            _listaLocalizaciones.erase(_listaLocalizaciones.begin() + i);
            cout << "Localizacion eliminada correctamente de la lista de Localizaciones" << endl;
            return;
            }
    }
    cout<<"El evento no se encuentra en la lista"<<endl;
}

void Aplicacion::eliminarUsuario(Usuario* U){
    for(unsigned i=0;i<_listaUsuarios.size();i++){
        if (_listaUsuarios[i] == U) {
            delete _listaUsuarios[i];
            _listaUsuarios.erase(_listaUsuarios.begin() + i);
            cout << "Usuario eliminado correctamente de la lista de Usuarios"<< endl;
            return;
            }
    }
    cout<<"El evento no se encuentra en la lista"<<endl;
}

void Aplicacion::eliminarEntradaMercado(Entrada *entrada){
    for(unsigned i=0;i<_listaEntradasMercadoSecundario.size();i++){
        if (_listaEntradasMercadoSecundario[i] == entrada) {
            _listaEntradasMercadoSecundario.erase(_listaEntradasMercadoSecundario.begin() + i);
            cout << "Entrada eliminada correctamente del mercado secundario"<< endl;
            return;
            }
    }
    cout<<"La entrada no se encuentra en el mercado secundario"<<endl;
}

bool Aplicacion::contieneEntrada(Entrada *entrada){
    for(unsigned i=0;i<_listaEntradasMercadoSecundario.size();i++){
        if (_listaEntradasMercadoSecundario[i] == entrada) {
            cout << " La entrada ya ha sido añadida al mercado secundario"<< endl;
            return true;
            }
    }
    cout<<"La entrada no se encuentra en el mercado secundario y se procederá a añadirla"<<endl;
    return false;
}

Localizacion* Aplicacion::getLocalizacion(int index){
    int aux = _listaLocalizaciones.size();
    if(aux==0){
        cout<<"No hay localizacion disponibles"<<endl;
        return nullptr;
    }
    while (index < 0 || index >= aux){
        cout<< "El índice se encuentra fuera de rango, debe estar entre 0 y el numero de localizaciones ((" << aux << ") para que sea válido. Introduce el indice de nuevo: " << endl;
        cin >> index;
    }
    return _listaLocalizaciones[index];
}

Evento* Aplicacion::getEvento(int index){
    int aux = _listaEventos.size();
    if(aux==0){
        cout<<"No hay eventos disponibles"<<endl;
        return nullptr;
    }
    while (index < 0 || index >= aux){
        cout<< "El índice se encuentra fuera de rango, debe estar entre 0 y el numero de localizaciones ((" << aux << ") para que sea válido. Introduce el indice de nuevo: " << endl;
        cin >> index;
    }
    return _listaEventos[index];
}

Usuario* Aplicacion::getUsuario(int index){
    int aux = _listaUsuarios.size();
    if(aux==0){
        cout<<"No hay usuarios disponibles"<<endl;
        return nullptr;
    }
    while (index < 0 || index >= aux){
        cout<< "El índice se encuentra fuera de rango, debe estar entre 0 y el numero de usuarios ((" << aux << ") para que sea válido. Introduce el indice de nuevo: " << endl;
        cin >> index;
    }
    return _listaUsuarios[index];
}

Entrada* Aplicacion::getEntradaMercadoSecundario(int index){
    int aux = _listaEntradasMercadoSecundario.size();
    if(aux==0){
        cout<<"No hay entradas disponibles"<<endl;
        return nullptr;
    }
    while (index < 0 || index >= aux){
        cout<< "El índice se encuentra fuera de rango, debe estar entre 0 y el numero de usuarios ((" << aux << ") para que sea válido. Introduce el indice de nuevo: " << endl;
        cin >> index;
    }
    return _listaEntradasMercadoSecundario[index];
}

int Aplicacion::buscarUsuario(const string& nombreUsuario){
    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){
        if (_listaUsuarios[i]->getNombre() == nombreUsuario){
            return i;
        }
    }
    return (-1);
}

int Aplicacion::buscarLocalizacion(const string& nombreLocalizacion){
    for (unsigned long i = 0; i < _listaLocalizaciones.size(); i++){
        if (_listaLocalizaciones[i]->getNombre() == nombreLocalizacion){
            return i;
        }
    }
    return (-1);
}

int Aplicacion::buscarEvento(const string& nombreEvento){
    for (unsigned long i = 0; i < _listaEventos.size(); i++){
        if (_listaEventos[i]->getNombre() == nombreEvento){
            return i;
        }
    }
    return (-1);
}

bool Aplicacion::comprobarContraseña(const string& nombreUsuario, const string& contraseña){
    int indiceUsuario = buscarUsuario(nombreUsuario);

    if (_listaUsuarios[indiceUsuario]->getContraseña() == contraseña){
        return true;
    }
    else{
        return false;
    }
}

void Aplicacion::menuPrincipal(){

    int eleccion;
    cout << "Selecciona una opccion: " << endl << "0. Registrarse " << endl << "1. Iniciar Sesion " << endl;
    cin >> eleccion;

    switch (eleccion){

        case 0:
            this->crearUsuario();
            break;

        case 1:
            this->iniciarSesion();
                    break;

                default:
                    cout << "Esa opccion no existe, selecciona una opccion posible" << endl;
                    this->menuPrincipal();
                    break;
        }
}

void Aplicacion::iniciarSesion(){

    string nombre, contraseña;
    cout << "Introduce el nombre de usuario para iniciar sesión: " << endl;
    cin >>  nombre;

    int indiceUsuario = buscarUsuario(nombre);

    if (indiceUsuario < 0){
        cout << "No existe ningun usuario con ese nombre, prueba de nuevo" << endl;
        this->iniciarSesion();
    }
    else{
        bool contraseñaCorrecta = false;

        do{
        cout << "Usuario encontrado" << endl << "Introduce la contraseña para el usuario (" << nombre << "): " << endl;
        cin >> contraseña;

        if (this->comprobarContraseña(nombre, contraseña)){
            cout << "Contraseña correcta, se ha iniciado sesión de forma correcta" << endl;
            _listaUsuarios[indiceUsuario]->menu(this);
            contraseñaCorrecta = true;
        }

        }while(!contraseñaCorrecta);
    }
}

void Aplicacion::crearUsuario(){

    int eleccion;
    cout << "Selecciona que tipo de ususario quieres crear: " << endl << "0. asistente " << endl << "1. artista " << endl;
    cin >> eleccion;

    switch (eleccion){

        case 0:
            this->crearAsistente();
            break;

        case 1:
            this->crearArtista();
            break;

        default:
            cout << "Esa opccion no existe, selecciona una opccion posible" << endl;
            this->crearUsuario();
            break;

    }
}

void Aplicacion::crearUsuarioRoot(){

    int eleccion;
    cout << "Selecciona que tipo de ususario quieres crear: " << endl << "0. asistente " << endl << "1. artista " << endl << "2. administrador" << endl;
    cin >> eleccion;

    switch (eleccion){

    case 0:
        this->crearAsistente();
        break;

    case 1:
        this->crearArtista();
        break;

    case 2:
        this->crearAdministrador();
        break;

    default:
        cout << "Esa opccion no existe, selecciona una opccion posible" << endl;
        this->crearUsuario();
        break;

    }
}

void Aplicacion::crearAsistente(){
    string nombre, contraseña, dni, eleccion;
    int cartera;
    bool vip;
    cout << "Introduce los datos que se piden" << endl;

    cout << "nombre: " << endl;
    cin >> nombre;

    cout << "contraseña: " << endl;
    cin >> contraseña;

    cout << "dni: " << endl;
    cin >> dni;

    cout << "fondos de la cuenta: " << endl;
    cin >> cartera;

    cout << "Es cuenta VIP (S/N): " << endl;
    cin >> eleccion;

    if (eleccion == "S" || eleccion == "s"){
        vip = true;
    }
    else{
        vip = false;
    }

     Asistente* asistente =  new Asistente (nombre, contraseña, dni,cartera, vip);
     this->anadirUsuario(asistente);

}

void Aplicacion::crearArtista(){
    string nombre, contraseña, estilo, descripccion, nombreArtista;

    cout << "Introduce los datos que se piden" << endl;

    cout << "nombre: " << endl;
    cin >> nombre;

    cout << "contraseña: " << endl;
    cin >> contraseña;

    cout << "nombre de artista: " << endl;
    cin >> nombreArtista;

    cout << "estilo de musica: " << endl;
    cin >> estilo;

    cout << "descripccion: " << endl;
    cin >> descripccion;

     Artista* artista =  new Artista (nombre, contraseña, nombreArtista, estilo, descripccion);
     this->anadirUsuario(artista);

}

void Aplicacion::crearLocalizacion(){
    string nombre, direccion;
    int aforo;

    cout << "Introduce los datos que se piden" << endl;

    cout << "nombre: " << endl;
    cin >> nombre;

    cout << "dirección: " << endl;
    cin >> direccion;

    cout << "aforo: " << endl;
    cin >> aforo;

    Localizacion* localizacion =  new Localizacion (nombre, direccion, aforo);
    this->anadirLocalizacion(localizacion);

}

void Aplicacion::crearAdministrador(){
    string nombre, contraseña;

    cout << "Introduce los datos que se piden" << endl;

    cout << "nombre: " << endl;
    cin >> nombre;

    cout << "contraseña: " << endl;
    cin >> contraseña;

    Administrador* administrador =  new Administrador (nombre, contraseña);
    this->anadirUsuario(administrador);

}

void Aplicacion::editarUsuario(){

    string nombre;
    cout << "Introduce el nombre de usuario que desea editar: " << endl;
    cin >>  nombre;

    if (nombre == "root"){
        cout << "El usuario root no se puede modificar" << endl;
        this->editarUsuario();
    }

    int indiceUsuario = buscarUsuario(nombre);

    Usuario* usuarioEditado = _listaUsuarios[indiceUsuario]->editar();

    _listaUsuarios.erase(_listaUsuarios.begin() + indiceUsuario);
    _listaUsuarios.insert(_listaUsuarios.begin() + indiceUsuario, usuarioEditado);



}

int Aplicacion::getfechaActual(){

    time_t tiempo_actual = time(nullptr);
    tm* fecha_actual = localtime(&tiempo_actual);

    int dia = fecha_actual->tm_mday;
    int mes = fecha_actual->tm_mon + 1;
    int ano = fecha_actual->tm_year + 1900;

    stringstream fecha_stream;

    fecha_stream << setw(4) << setfill('0') << ano
                 << setw(2) << setfill('0') << mes
                 << setw(2) << setfill('0') << dia;

    int fecha_actual_entero = std::stoi(fecha_stream.str());
    return fecha_actual_entero;
}

bool Aplicacion::fechaConcluida(int fecha){
    int fechaActual= this->getfechaActual();
    return fechaActual>fecha;
}

bool Aplicacion::fechaAsistenteUnMes(int fecha){
    int fechaActual=this->getfechaActual();
    int mes = (fechaActual / 100) % 100;
    int ano = fechaActual / 10000;
    int dia = fechaActual % 100;
    mes = mes + 1;
    if (mes > 12) {
        mes = 1;
        ano=ano+1;
            }
    fechaActual = ano * 10000 + mes * 100 + dia;
    return fecha>fechaActual;
}

void Aplicacion::borrarUsuario(){

    string nombre;
    int indiceUsuario;

    do{
        cout << "Introduce el nombre de usuario que desea borrar: " << endl;
        cin >>  nombre;

        indiceUsuario = buscarUsuario(nombre);

    }while(indiceUsuario == -1);

    if (nombre == "root"){
        cout << "No se puede eliminar el usuario root" << endl;
        this->borrarUsuario();
    }

    else{
        cout << "Se ha borrado el usuario correctamente" << endl;
        _listaUsuarios.erase(_listaUsuarios.begin() + indiceUsuario);
    }
}

void Aplicacion::guardarUsuarios(){

    ofstream archivo ("usuarios.txt", ios::out|ios::trunc);

    if (!archivo.is_open()){
        cerr << "Se ha producido un error al abrir el archvio para guardar los usuarios" << endl;
        cerr << "No se han podido guardar los datos" << endl;
        return;
    }

    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){

        archivo << _listaUsuarios[i]->guardarUsuario() << endl;

    }

    archivo.close();
}

void Aplicacion::cargarUsuarios(){

    ifstream archivo ("usuarios.txt", ios::in);

    if (!archivo.is_open()){
        cerr << "No se ha econtrado ningun archvo para cargar usuarios" << endl;
        return;
    }

    string linea;


    while (getline(archivo, linea)){
        stringstream info (linea);

        string dato;
        vector <string> datos;

        while(getline(info, dato, ',')){
            datos.push_back(dato);
        }

        if (datos[0] == "administrador"){
            if (datos[1] == "root"){}
            else{
                Usuario* nuevoAdmin = new Administrador(datos[1], datos[2]);
                _listaUsuarios.push_back(nuevoAdmin);
            }
        }

        if (datos[0] == "asistente"){
            Usuario* nuevoAsistente = new Asistente(datos[1], datos[2], datos[3], stoi(datos[4]), stoi(datos[5]));
            _listaUsuarios.push_back(nuevoAsistente);
        }

        if (datos[0] == "artista"){
            Usuario* nuevoArtista = new Artista(datos[1], datos[2], datos[3], datos[4], datos[5]);
            _listaUsuarios.push_back(nuevoArtista);
        }

    }

    archivo.close();

}

void Aplicacion::guardarLocalizaciones(){

    ofstream archivo ("localizaciones.txt", ios::out|ios::trunc);

    if (!archivo.is_open()){
        cerr << "Se ha producido un error al abrir el archvio para guardar las localizaciones" << endl;
        cerr << "No se han podido guardar los datos" << endl;
        return;
    }

    for (unsigned long i = 0; i < _listaLocalizaciones.size(); i++){

        archivo << _listaLocalizaciones[i]->guardarLocalizacion() << endl;

    }

    archivo.close();
}

void Aplicacion::cargarLocalizaciones(){

    ifstream archivo ("localizaciones.txt", ios::in);

    if (!archivo.is_open()){
        cerr << "No se ha econtrado ningun archvo para cargar localizaciones" << endl;
        return;
    }

    string linea;


    while (getline(archivo, linea)){
        stringstream info (linea);

        string dato;
        vector <string> datos;

        while(getline(info, dato, ',')){
            datos.push_back(dato);
        }

        Localizacion* nuevaLocalizacion = new Localizacion(datos[0], datos[1], stoi(datos[2]));
        _listaLocalizaciones.push_back(nuevaLocalizacion);

    }

    archivo.close();

}

void Aplicacion::guardarEventos(){

    ofstream archivo ("eventos.txt", ios::out|ios::trunc);

    if (!archivo.is_open()){
        cerr << "Se ha producido un error al abrir el archvio para guardar los eventos" << endl;
        cerr << "No se han podido guardar los datos" << endl;
        return;
    }

    for (unsigned long i = 0; i < _listaEventos.size(); i++){

        archivo << _listaEventos[i]->guardarEvento() << endl;

    }

    archivo.close();

}

void Aplicacion::cargarEventos(){

    ifstream archivo ("eventos.txt", ios::in);

    if (!archivo.is_open()){
        cerr << "No se ha econtrado ningun archvo para cargar eventos" << endl;
        return;
    }

    string linea;


    while (getline(archivo, linea)){
        stringstream info (linea);

        string dato;
        vector <string> datos;

        while(getline(info, dato, ',')){
            datos.push_back(dato);
        }

        Evento* nuevoEvento = new Evento(datos[0], stoi(datos[1]), stoi(datos[2]), stoi(datos[3]), stoi(datos[4]), _listaLocalizaciones[buscarLocalizacion(datos[5])], _listaUsuarios[buscarUsuario(datos[6])]);
        _listaLocalizaciones[buscarLocalizacion(datos[5])]->agregarEvento(nuevoEvento);

        _listaUsuarios[buscarUsuario(datos[6])]->añadirEvento(nuevoEvento);

        _listaEventos.push_back(nuevoEvento);

    }

    archivo.close();

}

void Aplicacion::guardarEntradas(){

    ofstream archivo ("entradas.txt", ios::out|ios::trunc);

    if (!archivo.is_open()){
        cerr << "Se ha producido un error al abrir el archvio para guardar las entradas" << endl;
        cerr << "No se han podido guardar los datos" << endl;
        return;
    }

    for (unsigned long i = 0; i < _listaUsuarios.size(); i++){

        vector<Entrada*> listaEntradas = _listaUsuarios[i]->getListaEntradas();

        if (listaEntradas.empty()){}

        else{

            for (unsigned long j = 0; j < listaEntradas.size(); j++){

                archivo << listaEntradas[j]->guardarEntrada() << endl;

            }
        }
    }

    archivo.close();

}

void Aplicacion::cargarEntradas(){

    ifstream archivo ("entradas.txt", ios::in);

    if (!archivo.is_open()){
        cerr << "No se ha econtrado ningun archvo para cargar entradas" << endl;
        return;
    }

    string linea;


    while (getline(archivo, linea)){
        stringstream info (linea);

        string dato;
        vector <string> datos;

        while(getline(info, dato, ',')){
            datos.push_back(dato);
        }

        Entrada* nuevaEntrada = new Entrada(_listaUsuarios[buscarUsuario(datos[0])], _listaEventos[buscarEvento(datos[1])], stoi(datos[2]));

        _listaUsuarios[buscarUsuario(datos[0])]->añadirEntrada(nuevaEntrada);

    }

    archivo.close();

}
