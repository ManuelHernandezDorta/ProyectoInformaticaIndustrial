#include <iostream>
#include "aplicacion.h"

using namespace std;

int main()
{
    Aplicacion App;

    Administrador Admin("Manuel", "123");
    cout << "Nombre: " << Admin.getNombre() << " contraseña: " << Admin.getContraseña() << endl;

    App.displayUsuarios();





}
