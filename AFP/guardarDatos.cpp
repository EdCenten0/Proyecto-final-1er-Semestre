#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <direct.h>
#include <iostream>
#include "datos.h"
using namespace std;
void guardarGastos(Gasto gastos[],int gastoActual);
void guardarDatos(Gasto gastos[],int tamGast,int &gastoActual){
    guardarGastos(gastos,tamGast);
}
//como dice su nombre funciona para el guardado de gasto que el usuario agregue

void guardarGastos(Gasto gastos[],int gastoActual){
    if(gastoActual>-1){
        FILE *file = fopen("temporal.bin","a");
        for(int i =0;i <=gastoActual;i++){
            if(gastos[i].estado!=3)
            fwrite(&gastos[i],sizeof(Gasto),1,file);
        }
           fclose(file);
           remove("Gastos.bin");
           rename("temporal.bin","Gastos.bin");

        }
        cout << "Los datos han sido guardados\n";
        system("pause");

    }   
