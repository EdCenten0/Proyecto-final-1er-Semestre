#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <direct.h>
#include <iostream>
#include "datos.h"
#include <time.h>
using namespace std;

//aqui se encuentran los modulos imprimirSaldo e ingresarSaldo


//ingresarSaldo funciona para ingresar el saldo a una categoria que el usuario elegira dependiendo de lo que necesite
void ingresarSaldoCat(Gasto gastos[], int &gastoActual,int tamGast){
    system("cls");
    int eleccion;
    int suma;
    cout<<"Elija la categoria a la cual quiere fijar saldo: "<<endl;
    cout << "(1)Entretenimiento\n(2)Vienda\n(3)Escolar\n(4)Comida\n(5)Transporte\n(6)Volver al menu anterior..."<<endl;
    cin >> eleccion;
    system("cls");
    switch (eleccion)
    {
    case 1:
        gastoActual++;
        if(gastoActual<=tamGast){
        cout << "Ingrese la cantidad : ";
        cin >> gastos[gastoActual].cat1;
        
        }

        break;
    case 2:
        gastoActual++;
        if(gastoActual<=tamGast){
        cout << "Ingrese la cantidad : ";
        cin >> gastos[gastoActual].cat2;
        
        }
        break;    

    case 3:
        gastoActual++;
        if(gastoActual<=tamGast){
        cout << "Ingrese la cantidad : ";
        cin >> gastos[gastoActual].cat3;
        
        }
        break;

    case 4:
        gastoActual++;
        if(gastoActual<=tamGast){
        cout << "Ingrese la cantidad : ";
        cin >> gastos[gastoActual].cat4;
        
        }
        break;

    case 5: 
         gastoActual++;
        if(gastoActual<=tamGast){
        cout << "Ingrese la cantidad : ";
        cin >> gastos[gastoActual].cat5;
        
        }
        break;
    default:
        cout << "Introduzca una categoria existente";
        break;
    }


}