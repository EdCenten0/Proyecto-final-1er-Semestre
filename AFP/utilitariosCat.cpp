#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <direct.h>
#include <iostream>
#include "datos.h"
#include <time.h>
using namespace std;

//aqui se encuentran los modulos registrarGasto, modificarGasto, eliminarGasto, buscarGasto y conteoGas

void registrarGasto(Gasto gastos[], int &gastoActual,int tamGast){
system("cls");
    // gastoActual funciona para mostrar una descripcion del gasto que el usuario hizo en una de las categorias
    gastoActual++;
    if(gastoActual<=tamGast){
    cout << "Descripcion del gasto: "<<endl;
    fflush(stdin);
    cin.getline(gastos[gastoActual].descripcion,400,'\n');
    fflush(stdin);
    cout << "\nMonto del gasto: "<<endl;
    cin >> gastos[gastoActual].monto;
    system("cls");
    cout << "Ingrese el codigo del gasto\n";
    cin >>  gastos[gastoActual].idGast;
    cout << "\nIngrese el numero de categoria\n";
    cout <<"(1)Entretenimiento\n(2)Vienda\n(3)Escolar\n(4)Comida\n(5)Transporte\n";
    cin >> gastos[gastoActual].idcat;

    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);  
    gastos[gastoActual].fecha.day = fecha->tm_mday;
    gastos[gastoActual].fecha.month = fecha->tm_mon+1;
    gastos[gastoActual].fecha.year = fecha->tm_year+1900;

    if(gastos[gastoActual].idcat >6 || gastos[gastoActual].idcat < 1){
        cout<< "\nNo puede ingresar una categoria que no existe\n";
        cout << "Reinicie el programa.\n";
        system("pause");
        exit(1);
    }
    gastos[gastoActual].estado=1;
    cout << "\nEl gasto ha sido agregado\n";
    }
    
    
    system("pause");


}
//modificarGasto funciona para modificar cuanto seria el monto y le daria una nueva descripcion al gasto.
void modificarGasto(Gasto &gastos){
   system("cls");
   cout << "CODIGO DE GASTO: " << gastos.idGast;
   cout << "----------------------------------\n"; 
   cout << "\nNueva descripcion: \n"<<endl;
   cin >> gastos.descripcion;
   cout << "\nNuevo monto: "<<endl;
   cin >> gastos.monto;
   gastos.estado=2;

   system("pause");

}
//como dice su nombre es para eliminar un gasto 
void eliminarGasto(Gasto &gastos){
    
   system("cls");
   

   
   cout << "CODIGO DE GASTO: " << gastos.idGast;
   cout << "----------------------------------\n"; 
   cout << "\nDescripcion: \n"<<gastos.descripcion<<endl;
   cout << "\nMonto: "<<gastos.monto<<endl;

   gastos.estado=3;
   cout <<"\nEl gasto ha sido eliminado\n";
   
   system("pause");

}

//buscarGasto buscara el id de la categoria para poder encontrar el gasto que esta buscando la persona
int buscarGasto(Gasto gastos[], int &gastoActual, int idCat){
    int encontrado=NE;
    for(int i=0; i<=gastoActual;i++){
        if(idCat==gastos[i].idcat)
        if(gastos[i].estado!=3)
            encontrado=i;
    }
    return encontrado;
}


//su funcion es cargar los gastos que se han contado en la estructura
int conteoGastos(){

    FILE *archi;
    int numRegs;
    archi=fopen("Gastos.bin","a");
    fseek(archi,0,SEEK_END);
    numRegs = ftell(archi) / sizeof(Gasto);
    fclose(archi);
    return numRegs; 

}