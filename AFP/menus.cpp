//LIBRERIAS___________________________________________________-
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "datos.h"
#include <stdlib.h>
#include <direct.h>
#include <locale.h>
#include <string.h>

using namespace std;

//aqui se encuentran los modulos billetera,gestionGastos,menuConfiguracion y gestionCategorias

//PROTOTIPOS____________________________________________________-
void billetera(Gasto gastos[], int tamGast, int &gastoActual);
void menuConfiguracion(Usuario usuarios[],int usuarioActual);
void acercaDe();
void gestionGastos(Gasto gastos[], int tamGast, int &gastoActual);
void imprimirUsuarios(Usuario usuarios[], int usuarioActual);
void registarUsuario();
void modificarUsuario(Usuario user);
void eliminarUsuario(Usuario user);
int buscarUsuario(Usuario usuarios[],int usuarioActual,char *user);
int buscarGasto(Gasto gastos[], int &gastoActual, int idCat);
void eliminarGasto(Gasto &gastos);
void modificarGasto(Gasto &gastos);
void registrarGasto(Gasto gastos[], int &gastoActual,int tamGast);
void menuPrincipal(int &usuarioActual, int tamUsuario,int &gastoActual,int tamGast,Usuario usuarios[],Gasto gastos[]);
void guardarDatos(Gasto gastos[],int tamGast,int &gastoActual);
void imprimirGastos(Gasto gastos, int eleccion);
void ingresarSaldoCat(Gasto gastos[], int &gastoActual,int tamGast);
void reiniciarDatos();




//MODULO_________________________________________________________-
using namespace std;
void menuPrincipal(int &usuarioActual, int tamUsuario,int &gastoActual,int tamGast,Usuario usuarios[],Gasto gastos[]){
    int eleccion;
    setlocale(LC_ALL, "spanish");

    do
//El menu principal en donde se accedera a todos los demas modulos
    {
        system("cls");
        system("color 3f");
        cout << "\t\tBienvenido a AFP\n\n";
        cout << "¿Que desea hacer?"<<endl;
        cout << "(1)Gestion de Billetera\n(2)Gestion de Gastos\n(3)Ajustes\n(4)Acerca de\n(5)Salir"<<endl;
        cin >> eleccion;
        switch (eleccion)
    {
    case 1:
        billetera(gastos,tamGast,gastoActual);
        break;

    case 2:
        gestionGastos(gastos,tamGast,gastoActual);
        break;
    
    case 3:
        menuConfiguracion(usuarios,usuarioActual);
        break;
    case 4:
        acercaDe();
        break;
    
    case 5:
        exit(1);
        break;
    default:
        cout << "\nElija una opcion valida\n";
        system("pause");
        break;
    }
    } while (eleccion != 1,2,3,4);
    
    

    

}
//al ingresar a Billetera se abre un menu en el cual se podra ver el saldo total, agregar saldo-gasto a categoria, modificar,eliminar y resetear 

void billetera(Gasto gastos[], int tamGast,int &gastoActual){
    int eleccion;
    do
    {
        
        system("cls");
        cout <<"\t\tBilletera\n\n";
        cout <<"(1)Ver saldo total\n(2)Agregar saldo a categorias\n(3)Agregar gasto a una categoria\n(4)Modificar gastos\n(5)Eliminar gastos\n(6)Resetear datos\n(7)Guardar Datos\n(8)Volver al anterior..."<<endl;
        int idGast;
        int gast;
        cin >> eleccion;
        switch (eleccion)
        {
        case 1:

            break;
        case 2:
            ingresarSaldoCat(gastos,gastoActual,tamGast);
     
            break;

        case 3:
            registrarGasto(gastos,gastoActual,tamGast);
            break;

        case 4:
             system("cls");
                    printf("Digite el codigo del gasto modificar: ");
                    fflush(stdin);
                    scanf("%i", idGast);
                    gast=buscarGasto(gastos,gastoActual,idGast);
                    if(gast!=NE){
                        modificarGasto(gastos[gast]);
                    }                        
                    else{
                        printf("El gasto no existe \n");
                    }                        
                    system("pause");    
                    
            
            break;

        case 5:
            system("cls");
                    printf("Digite el codigo del gasto eliminar: ");
                    scanf("%i", idGast);
                    gast=buscarGasto(gastos,gastoActual,idGast);
                    if(gast!=NE){
                        eliminarGasto(gastos[gast]);
                    }                        
                    else{
                        printf("El gasto no existe \n");
                    }                        
                    system("pause");    
                    
            break;

        case 6:
            reiniciarDatos();
            break;

        case 7: 
        guardarDatos(gastos,tamGast,gastoActual);
        break;
        default:
        cout << "ELija una opcion valida";
       
            break;
    }
    } while (eleccion < 7);
    
    
}
//al ingresar a gestionGastos se abre un menu en el cual se pedira cual sera la categoria que desea visualizar los gastos
void gestionGastos(Gasto gastos[], int tamGast, int &gastoActual){

    int eleccion;
    
    do
    {
        system("cls");
        int gast;
        cout << "\t\tGestion de gastos\n\n";
        cout << "Cual categoria desea visualizar?"<<endl;
        cout << "(1)Entretenimiento\n(2)Vienda\n(3)Escolar\n(4)Comida\n(5)Transporte\n(6)Volver al menu anterior..."<<endl;
        cin >> eleccion;
        switch (eleccion)
        {
        case 1:
            
            
            
            gast=buscarGasto(gastos,gastoActual,eleccion);
            if(gast!=NE){
                imprimirGastos(gastos[gast],eleccion);
            }else{
                cout<< "La categoria no existe";
            }
            system("pause");
            break;


        case 2:
            gast=buscarGasto(gastos,gastoActual,eleccion);
            if(gast!=NE){
                imprimirGastos(gastos[gast],eleccion);
            }else{
                cout<< "La categoria no existe";
            }
            system("pause");
            break;

        case 3:
            gast=buscarGasto(gastos,gastoActual,eleccion);
            if(gast!=NE){
                imprimirGastos(gastos[gast],eleccion);
            }else{
                cout<< "La categoria no existe";
            }
            system("pause");
            break;
        
        case 4:
            gast=buscarGasto(gastos,gastoActual,eleccion);
            if(gast!=NE){
                imprimirGastos(gastos[gast],eleccion);
            }else{
                cout<< "La categoria no existe";
            }
            system("pause");

            break;

        case 5:
            gast=buscarGasto(gastos,gastoActual,eleccion);
            if(gast!=NE){
                imprimirGastos(gastos[gast],eleccion);
            }else{
                cout<< "La categoria no existe";
            }
            system("pause");
            break;


        default:
            cout << "ELija una opcion valida";
            system("pause");
            break;
    }
    } while (eleccion <6);
    
    



}
















//al abrir el menuConfiguracion se abre un menu en el cual se mostrara las opciones de registrar,modificar,eliminar e imprimir usuarios. 
void menuConfiguracion(Usuario usuarios[],int usuarioActual){
    int opcion;
    int usuario1;
    Usuario usuario;
    char user[15];
    do{
        system("cls");
        printf("---------- Menú de Configuraciones ----------\n");
        printf("(1)Registrar usuario\n");
        printf("(2)Modificar usuario\n");
        printf("(3)Eliminar usuario\n");
        printf("(4)Imprimir usuarios\n");
        printf("(5)Volver al menú anterior...\n");
        printf("-----------------------------------\n");
        printf("Digite su opción: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: 
                    registarUsuario();
                    break;
            case 2: 
                    system("cls");
                    printf("Digite el usuario a modificar: ");
                    scanf("%s",user);
                    usuario1=buscarUsuario(usuarios,usuarioActual,user);
                    if(usuario1!=NE){
                        modificarUsuario(usuarios[usuario1]);
                    }                        
                    else{
                        printf("El usuario no existe \n");
                    }                        
                    system("pause");    
                    
                    break;
            case 3: 
                    system("cls");
                    printf("Digite el usuario a eliminar: ");
                    scanf("%s",user);
                    usuario1=buscarUsuario(usuarios,usuarioActual,user);
                    if(usuario1!=NE){
                        eliminarUsuario(usuarios[usuario1]);
                    }                        
                    else{
                        printf("El usuario no existe \n");
                    }                        
                    system("pause");
                    break;
            case 4: 
                    imprimirUsuarios(usuarios, usuarioActual);                       
                    break;
            case 5: ;
            
        }
    }
        while(opcion<5);
        
}

// void gestionCategorias(){
//     system("cls");
//     cout << "\t\tGestion de categorias"<<endl<<endl;
//     cout <<"(1)";
// }

