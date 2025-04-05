#include <iostream>
#include "aplicacion.h"

using namespace std;

int main()
{
    Aplicacion App;
    string continuar;

    cout << "Desea registrarse como usuario: (S/N) (Si no lo desea se cerrara el programa): " << endl;
    cin >> continuar;

    if (continuar == "S" || continuar == "s"){
        App.registrarse();
    }
    else{
        cout << "Cerrando el programa..." << endl;
        return 0;
    }
}
