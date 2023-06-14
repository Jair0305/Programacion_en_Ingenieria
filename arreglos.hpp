#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>

int syArregloEnPantalla(float x[], int nD);
int syArregloCaptura(float x[], int nD);
int syArregloFijar(float p[],int nD, float val);
int syArregloPromedio(float x[],int nD, float &prom);
int syArregloMaximo(float x[],int nD, float &maximo);
int syArregloVarianza(float x[],int nD, float &var);
int syArregloOrdenBurbuja(float x[],int nD);
int syArregloFijarEnteroAleatorio(float p[], int nD);
int ArregloEnterosAleatorios(float p[], int nD, int limInf, int limSup);
float *syArregloNuevo(int N);
int syArregloBorrar(float *p);
int syArregloPromedio(float x[],int nD, float &prom);
