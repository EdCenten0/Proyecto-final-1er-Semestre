#include <stdio.h>
#include "datos.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


//imprimirGastos funciona para dar a detalle un gasto que el usuario ingreso y en que dia

void imprimirGastos(Gasto gastos,int eleccion){
    system("cls");
    switch (eleccion)
    {
    case 1:
        cout <<"Saldo de la categoria: "<<gastos.cat1<<endl;
        break;

    case 2:
        cout <<"Saldo de la categoria: "<<gastos.cat2<<endl;
        break;

    case 3:
        cout <<"Saldo de la categoria: "<<gastos.cat3<<endl;
        break;

    case 4: 
        cout <<"Saldo de la categoria: "<<gastos.cat4<<endl;
        break;

    case 5:
        cout <<"Saldo de la categoria: "<<gastos.cat5<<endl;
        break;
    
    default:
        break;
    }
    cout << "Codigo del gasto: " << gastos.idGast<<endl;
    cout << "\n------------------\n";
    fflush(stdout);
    cout << "Descripcion: " <<gastos.descripcion<<endl;
    fflush(stdout);
    cout << "\n------------------\n";
    cout << "Monto: " <<gastos.monto<<endl;
    cout << "\n------------------\n";
    cout << "Fecha: " << gastos.fecha.day<<"/"<<gastos.fecha.month<<"/"<<gastos.fecha.year<<endl;
    system("pause");
}
 