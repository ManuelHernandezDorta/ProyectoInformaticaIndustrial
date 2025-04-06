#include <iostream>
#include "aplicacion.h"

using namespace std;

int main()
{
    Aplicacion App;

    string desicion;
    bool continuar = false;

    do{

        App.registrarse();

        cout << "Desea volver a registrarse como usuario: (S/N) (Si no lo desea se cerrara el programa): " << endl;
        cin >> desicion;

        if (desicion == "S" || desicion == "s"){
            continuar =  true;
        }

        else{
            cout << "Cerrando el programa..." << endl;
            continuar =  false;
        }

    }while(continuar);


    return 0;
}
