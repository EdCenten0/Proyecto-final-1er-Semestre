#include <cstdio>
#include "datos.h"
void cargarUsuarios(Usuario usuarios[],int usuarioActual);
void cargarGastos(Gasto gastos[],int gastoActual);

//se encuentran los modulos cargarDatos,cargarUsuarios,calcularCantUsuarios,cargarGastos y calcularGastos

//cargarDatos funciona para que se agreguen sus gastos dependiendo de que usuario ingrese a la aplicacion
void cargarDatos(int &usuarioActual, int tamUsuario,Usuario usuarios[],int &gastoActual, int tamGast,Gasto gastos[]){
    cargarUsuarios(usuarios,usuarioActual);
    cargarGastos(gastos,gastoActual);
}

//su funcion es cargar los datos de los usuarios en la estructura
void cargarUsuarios(Usuario usuarios[],int usuarioActual){
    if(usuarioActual>-1){
        FILE *file = fopen("usuarios.bin","r");
        int reg=0;
        while(feof(file)==0){
           fread(&usuarios[reg],sizeof(Usuario),1,file);
           reg++;            
        }
        fclose(file);
    }
    
}

//como dice su nombre funciona para calcular la cantidad de usuarios que existen
int calcularCantUsuarios(){
    FILE *archi;
    int numRegs;
    archi=fopen("usuarios.bin","a");
    fseek(archi,0,SEEK_END);
    numRegs = ftell(archi) / sizeof(Usuario);
    fclose(archi);
    return numRegs;
}

//su funcion es cargar los datos de los gastos en la estructura
void cargarGastos(Gasto gastos[],int gastoActual){
    if(gastoActual>-1){
        FILE *file = fopen("Gastos.bin","r");
        int reg=0;
        while(feof(file)==0){
           fread(&gastos[reg],sizeof(Gasto),1,file);
           reg++;            
        }
        fclose(file);
    }   
}

//su funcion es cargar los datos calculados de los gastos en la estructura
int calcularGastos(){
    FILE *archi;
    int numRegs;
    archi=fopen("Gastos.bin","a");
    fseek(archi,0,SEEK_END);
    numRegs = ftell(archi) / sizeof(Gasto);
    fclose(archi);
    return numRegs;
}