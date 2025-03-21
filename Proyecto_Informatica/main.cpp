#include <iostream>
#include "usuario.h"
#include "administrador.h"

using namespace std;

int main()
{
    Usuario Mikel;
    Usuario Manuel("Manuel", "1234");
    Usuario Masa(Manuel);

    Administrador Admin;
    Administrador Pepe("pepe", "7777");
    Administrador Copia(Pepe);


    cout << "Nombre: " << Manuel.getNombre() << " contraseña: " << Manuel.getContraseña();

    cout << "Nombre: " << Admin.getNombre() << " contraseña: " << Admin.getContraseña();
    cout << "Nombre: " << Pepe.getNombre() << " contraseña: " << Pepe.getContraseña();
    cout << "Nombre: " << Copia.getNombre() << " contraseña: " << Copia.getContraseña();




}
