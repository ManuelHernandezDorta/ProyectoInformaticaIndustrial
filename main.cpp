#include <iostream>
#include "aplicacion.h"

using namespace std;

int main(){

    Aplicacion App;
    string desicion;
    bool continuar = false;

    do{
        App.cargarUsuarios();

        App.menuPrincipal();

        cout << "Desea volver a abrir el menu principal: (S/N) (Si no lo desea se cerrara el programa): " << endl;
        cin >> desicion;

        if (desicion == "S" || desicion == "s"){
            continuar =  true;
        }

        else{

            App.guardarUsuarios();

            cout << "Cerrando el programa..." << endl;
            continuar =  false;
        }

    }while(continuar);


    return 0;
}
