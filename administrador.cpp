#include "administrador.h"

Administrador::Administrador(): Usuario(){}


Administrador::Administrador(string nombreUsuario, string contraseña): Usuario(nombreUsuario, contraseña){}


Administrador::Administrador(const Administrador& A): Usuario(A){}


Administrador::~Administrador(){}

string Administrador::tipoUsuario(){
    string tipo;
    tipo="administrador";
    return tipo;
}

void Administrador::displayUsuario(){
    cout << "Tipo: Administrador, nombreUsuario: " << _nombreUsuario << ", contraseña: " << _contraseña << endl;
}

void Administrador::menu(Aplicacion* App){
    int eleccion;
    string continuar = "S";

    while (continuar == "S" || continuar == "s") {

        cout << "Menu: " << endl << "0. Mostrar lista de usuarios" << endl << "1. Crear Usuario" << endl << "2. Editar Usuario" << endl << "3. Borrar Usuario" << endl << "4. Crear una localizacion" << endl << "5. Mostrar lista de localizaaciones" << endl;
    cin >> eleccion;


    switch(eleccion){

        case(0):
            App->displayUsuarios();
            break;

        case(1):
            App->crearUsuarioRoot();
            break;

        case(2):
            App->editarUsuario();
            break;

        case(3):
            App->borrarUsuario();
            break;

        case(4):
            App->crearLocalizacion();
            break;

        case(5):
            App->displayLocalizaciones();
            break;

        default:
            cout << "Esa no es una opcion valida, selecciona una nuevamente: " << endl;
            break;
        }
    cout << "Desea realizar otra acion: (S/N): " << endl;
    getline(cin >> ws, continuar);
    }

        cout << "Cerrando sesion..." << endl;
        return;
}


Usuario* Administrador::editar(){
    int eleccion;
    cout << "Que campo desea editar: " << endl << "0. nombre de usuario" << endl << "1. contraseña" << endl;
    cin >> eleccion;

    switch (eleccion) {

    case 0:{
        string nuevoNombre;
        cout << "Introduce el nuevo nombre: " << endl;
        cin >> nuevoNombre;

        Usuario* nuevoAdmin = new Administrador(nuevoNombre, _contraseña);
        return nuevoAdmin;

        break;
        }

    case 1:{
        string nuevaContraseña;
        cout << "Introduce la nueva contraseña: " << endl;
        cin >> nuevaContraseña;

        Usuario* nuevoAdmin = new Administrador(_nombreUsuario, nuevaContraseña);
        return nuevoAdmin;

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

string Administrador::guardarUsuario(){

    stringstream cadena;

    cadena << "administrador," << _nombreUsuario << "," << _contraseña;

    return cadena.str();

}
