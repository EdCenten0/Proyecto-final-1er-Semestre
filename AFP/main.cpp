/*
AFP
Version 2.0
Universidad Centroamericana UCA
Facultad de ciencia, tecnologia y ambiente 
Ingenieria en sistemas de la informacion 
Carlos Eduardo Chavarria Centeno
Rene Nicolas Sandoval Lagos*/
#include <stdio.h>
#include "datos.h"
#include <iostream>
#include <locale.h>
using namespace std;
#include <string.h>

bool usuariosExiste();
void autenticarUsuario(int &usuarioActual, int tamUsuario,Usuario usuarios[],int &gastoActual, int tamGast,Gasto gastos[]);
int calcularCantUsuarios();
void registarUsuario();
int calcularGastos();
int main()
{
    setlocale(LC_ALL, "spanish");
    int usuarioActual, tamUsuario;
    int gastoActual, tamGast;
    tamUsuario = calcularCantUsuarios() + 10;
    usuarioActual=calcularCantUsuarios()-1;
    Usuario usuarios[tamUsuario];

    tamGast = calcularGastos() + 10;
    gastoActual=calcularGastos() - 1;

    Gasto gastos[tamGast];
     
//el primer menu donde se podra elegir si quiere registrar una nueva cuenta o iniciar sesion con una cuenta ya existente
    int eleccion;
    cout<<"Elija una opcion\n(1)Iniciar Sesion\n(2)Registrar cuenta\n";
    cin >> eleccion;
    switch (eleccion)
    {
    case 1:
        autenticarUsuario(usuarioActual,tamUsuario,usuarios,gastoActual,tamGast,gastos);
        break;
    case 2:
        
        registarUsuario();
        break;
    default:
    cout << "Haga algo";
        break;
    }

    
    
    return 0;
}
