#include "arreglos.hpp"


using namespace std;

int syArregloEnPantalla(float a[], int nD)
{
   cout << "\n\nLos datos en el arreglo son:\n";
   for(int k=0; k<nD; k++)
      cout << a[k] << " ";
   cout << "\n\n";
   return 0;
}

int syArregloCaptura(float x[], int nD)
{
   cout << "Captura de los " << nD << " datos:\n";
   for(int k=0; k<nD; k++)
   {
      cout << "Dato " << k+1 << ": ? ";
      cin >> x[k]; cin.ignore();
   }
   cout << "\n\n";

   return 0;
}
int syArregloPromedio(float x[],int nD, float &prom)
{
   prom = 0.0;
   for(int k=0; k<nD; k++)
      prom += x[k];
   prom /= nD;

   return 0;
}

int syArregloFijar(float p[],int nD, float val)
{
   for(int k=0; k<nD; k++)
      p[k] = val;
   return 0;
}

float *syArregloNuevo(int N)
{
   float *p = new float[N];
   if( !p )
   {
      cout << "\n\nError de asignación de memoria.\n";
      return NULL; // return NULL;
   }
   return p;
}

int syArregloBorrar(float *p)
{
   if(p)
      delete[] p;
   else cout << "\n\nIntento de liberar memoria no asignada.\n";
   return 0;
}

int syArregloMaximo(float x[],int nD, float &maximo)
{
   maximo = x[0];
   for(int k=1; k<nD; k++)
      if(x[k]>maximo)
         maximo=x[k];
   return 0;
}

int syArregloVarianza(float x[],int nD, float &var)
{
   float prom = 0.0;
//   for(int k=0; k<nD; k++)
//      prom += x[k];
//   prom /= nD;

   syArregloPromedio(x,nD,prom);

   var = 0.0;
   for(int k=0; k<nD; k++)
      var += (x[k]-prom)*(x[k]-prom);
   var /= nD;

   return 0;
}

int syArregloOrdenBurbuja(float x[],int nD)
{
   float aux;
   int huboCambio;

   do
   {
      huboCambio = 0;
      for(int k=0; k < nD-1; k++) // Comparación de datos adyacentes
      {
         if( x[k] > x[k+1] ) // Intercambio de los datos
         {
            aux = x[k];
            x[k] = x[k+1];
            x[k+1] = aux;
            huboCambio = 1;
         }
      }
//      cout << "Paso intermedio:";
//      syArregloEnPantalla(x,nD);
   } while(huboCambio);
   return 0;
}

int syArregloFijarEnteroAleatorio(float p[], int nD)
{
   // A cada dato se le asignará un número aleatorio entero
   srand(time(NULL)); // Semilla para el generador de números aleatorios

   for(int k=0; k<nD; k++)
      p[k] = rand()%101; // Enteros entre 0 y 100

   return 0;
}

int ArregloEnterosAleatorios(float p[], int nD, int limInf, int limSup)
{
    if (limInf > limSup)
    {
        int aux = limInf;
        limInf = limSup;
        limSup = aux;
    }


    int delta = limSup - limInf + 1;



   // A cada dato se le asignará un número aleatorio entero entre limInf y limSup, estos inclusive
   srand(time(NULL)); // Semilla para el generador de números aleatorios


   for(int k=0; k<nD; k++)
      p[k] = rand()%delta + limInf; // Enteros entre 0 y 100
                //sin +limInf tendremos datos entre el 0 y el superior, no toma en cuenta el inferior
   return 0;
}
