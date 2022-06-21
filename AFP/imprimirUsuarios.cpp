#include <cstdio>
#include <cstdlib>
#include "datos.h"
// se encuentra el modulo imprimir usuarios
//manda a pantalla todos los usuarios y contraseñas que se han creado 

void imprimirUsuarios(Usuario usuarios[], int usuarioActual){
    system("cls");
    for(int i=0; i<=usuarioActual; i++){
        printf("Usuario: %s Password: %s \n",usuarios[i].user,usuarios[i].pass);
    }
    system("pause");
}                      