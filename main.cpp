#include <iostream>
#include "aplicacion.h"

using namespace std;

int main(){

    Aplicacion App;
    string desicion;
    bool continuar = false;

    App.cargarUsuarios();
    App.cargarLocalizaciones();
    App.cargarEventos();

    do{

        App.menuPrincipal();

        cout << "Desea volver a abrir el menu principal: (S/N) (Si no lo desea se cerrara el programa): " << endl;
        cin >> desicion;

        if (desicion == "S" || desicion == "s"){
            continuar =  true;
        }

        else{

            App.guardarUsuarios();
            App.guardarLocalizaciones();
            App.guardarEventos();

            cout << "Cerrando el programa..." << endl;
            continuar =  false;
        }

    }while(continuar);


    return 0;
}
