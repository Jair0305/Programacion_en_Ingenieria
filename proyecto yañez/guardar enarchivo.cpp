// syArchivos_Texto_1_cpp
// Escritura de datos en un archivo
// R.E. Sánchez Yáñez

// Directivas de preprocesador
#include <iostream>
#include <fstream> // Para funciones de lectura/escritura en archivos

// Declaraciones globales
using namespace std;





// Prototipos de funciones

float *syArregloNuevo(int N);
int syArregloMostrar(float v[], int N);
int syArregloCaptura(float v[], int N);

int syArregloDisco(float v[], int N);
int syArregloDiscoAgregar(float v[], int N);





// Inicio de función main()
int main(void)
{
   cout << "Escritura de datos en un archivo en disco.\n";

   int n;
   do
   {
      cout << "Num de datos: \n";
      cin >> n; cin.ignore();
   } while (n<1);

   float *x;
   x = syArregloNuevo(n);
   syArregloMostrar(x,n);

   syArregloCaptura(alb.duran,alb.nombre);
   syArregloMostrar(x,n);

   // LO IMPORTANTE DE ESTE PROGRAMITA:
   //syArregloDisco(x,n);
   syArregloDiscoAgregar(x,n);


   delete[] x; // También, muy importante

   cout << "\n\nPresiona <Enter para salir>. ";
   cin.get(); return 0;
}
// Fin de función main()


// Inicio de definición de funciones

float *syArregloNuevo(int N)
{
   float *v = new float[N];
   if(!v)
   {
      cout << "\nError al asignar memoria.\n";
      return NULL;
   }

   for (int k=0; k<N; k++)
      v[k] = 0.0;
   return v;
}

int syArregloMostrar(float v[], int N)
{
    cout << "\n\nDATOS:" << endl;
    for (int k=0; k<N; k++) cout << v[k] << " ";
    return 0;
}

int syArregloCaptura(float v[], int N)
{
    cout << "\n\nCAPTURA DE " << N << " DATOS:" << endl;
    for (int k=0; k<N; k++)
    {
        cout << "Dato " << k+1 << ": ? ";
        cin >> v[k]; cin.ignore(256,'\n');
    }
    return 0;
}

int syArregloDisco(float v[], int N)
{
   cout << "\n\nEscritura de estos datos (y sus cuadrados) en el archivo \"datos.csv\":" <<  endl;
   for (int k=0; k<N; k++)
      cout << v[k] << "," << v[k]*v[k] << "\n" ; // Una tabla de datos y datos al cuadrado

   // LO NECESARIO PARA ESCRITURA (además de la cabecera):
   ofstream outfile("datos.csv"); //Así se sobreescribe el archivo

   for (int k=0; k<N; k++)
      outfile << v[k] << "," << v[k]*v[k] << "\n" ; // El archivo csv puede ser abierto en Excel

   outfile.close();
   // FIN DE LA ESCRITURA

   return 0;
}

int syArregloDiscoAgregar(float v[], int N)
{
   cout << "\n\nSe agrega la escritura de estos datos (y sus cuadrados) al archivo csv:" <<  endl;
   for (int k=0; k<N; k++)
      cout << v[k] << "," << v[k]*v[k] << "\n" ; // Una tabla de datos (y datos al cuadrado, sólo para ver el resultado)

   // LO NECESARIO PARA ESCRITURA (además de la cabecera):
   ofstream outfile("datos.csv", ios_base::app); //Así se agrega la información al final del archivo

   for (int k=0; k<N; k++)
      outfile << v[k] << "," << v[k]*v[k] << "\n" ; // El archivo csv puede ser abierto en Excel

   outfile.close();
   // FIN DE LA ESCRITURAd

   return 0;
}

