/**** UTILITARIOS PARA AUTENTICACIÓN *****/
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <direct.h>
#include <iostream>
#include "datos.h"
using namespace std;
void menuPrincipal(int &usuarioActual, int tamUsuario,int &gastoActual,int tamGast,Usuario usuarios[],Gasto gastos[]);
void cargarDatos(int &usuarioActual, int tamUsuario,Usuario usuarios[],int &gastoActual, int tamGast,Gasto gastos[]); 

//aqui se encuentras los modulos autenticarUsuario, registrarUsuario, modificarUsuario, eliminarUsuario, archivoExiste, usuarioExiste y crearDirecto

// valida que los valores user/pass son correctos
void autenticarUsuario(int &usuarioActual, int tamUsuario,Usuario usuarios[],int &gastoActual, int tamGast,Gasto gastos[])
{
    FILE *file;
    Usuario user,temp;
    bool flag = false;

       do{
        system("cls");
        printf("Digite su usuario: ");
        scanf("%s",user.user);
        printf("Digite su contraseña: ");
        scanf("%s",user.pass);

        file = fopen("usuarios.bin","r");
  
        while(feof(file)==0){
            fread(&temp,sizeof(Usuario),1,file);
            if((strcmp(temp.user,user.user)==0)&&(strcmp(temp.pass,user.pass)==0)){
                flag=true;
            }
        fread(&temp,sizeof(Usuario),1,file);
        }
     fclose(file);
     if(flag==false){
        printf("Usuario o clave incorrectos, intente nuevamente...\n");
        system("pause");
      }
    }while(flag==false);
    
    cargarDatos(usuarioActual,tamUsuario,usuarios,gastoActual,tamGast,gastos);
    menuPrincipal(usuarioActual,tamUsuario,gastoActual,tamGast,usuarios,gastos);
}

// solicita un nuevo usuario y se almacena en el fichero correspondiente
void registarUsuario(){
    Usuario user;
    printf("Digite el usuario: ");
    scanf("%s",user.user);
    printf("Digite la contraseña: ");
    scanf("%s",user.pass);

    FILE* usuarios;
    usuarios = fopen("usuarios.bin","a");

    
    fwrite(&user,sizeof(Usuario),1,usuarios);
    fclose(usuarios);

    
}

// realizar cambio en la contraseña de un usuario
void modificarUsuario(Usuario user){
    printf("Digite la nueva contraseña: ");
    scanf("%s",user.pass);

    FILE *usuarios, *temporal;
    Usuario temp;

    usuarios = fopen("usuarios.bin","r");
    temporal = fopen ("temporal.bin","a");

    while(feof(usuarios)==0){
        fread(&temp,sizeof(Usuario),1,usuarios);
        if(strcmp(temp.user,user.user)!=0){
            fwrite(&temp,sizeof(Usuario),1,temporal);
        }
        else{
             printf("son iguales");
             fwrite(&user,sizeof(Usuario),1,temporal);
        }
    fread(&temp,sizeof(Usuario),1,usuarios);
    }

    fclose(usuarios);
    fclose(temporal);

    remove("usuarios.bin");
    rename("temporal.bin","usuarios.bin");   

}

// eliminar un usuario de la aplicación
void eliminarUsuario(Usuario user){
    
    FILE *usuarios, *temporal;
    Usuario temp;

    usuarios = fopen("usuarios.bin","r");
    temporal = fopen ("temporal.bin","a");

    while(feof(usuarios)==0){
        fread(&temp,sizeof(Usuario),1,usuarios);
        if(strcmp(temp.user,user.user)!=0){
            fwrite(&temp,sizeof(Usuario),1,temporal);
        }
    fread(&temp,sizeof(Usuario),1,usuarios);
    }

    fclose(usuarios);
    fclose(temporal);

    remove("usuarios.bin");
    rename("temporal.bin","usuarios.bin");
}

int buscarUsuario(Usuario usuarios[],int usuarioActual,char *user){
    int encontrado=NE;
    for(int i=0; i<=usuarioActual;i++){
        if(strcmp(user,usuarios[i].user)==0)
            encontrado=i;
    }
    return encontrado;
}



//**********UTILIDADES DE COMPROBACION DE ARCHIVOS*************



bool usuariosExiste(){
    FILE *archivo;
    if(archivo = fopen("usuarios.bin", "r")){
        fclose(archivo);
        return true;
    }else{
        return false;
    }
}

//******Eliminar datos*******
void reiniciarDatos(){
    system("cls");
    remove("Gastos.bin");
    cout <<"Datos borrados"<<endl;
    system("pause");
}

