    // syArreglos_Repaso.cpp
// R.E. S�nchez Y��ez

#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>

using namespace std;

// Prototipos de funciones
int syCapturaNumDatos(void);
int syCapturaNumDatos(int &nD);






// Inicio de funci�n main()
int main(void)
{
   setlocale(LC_CTYPE,"Spanish");

   cout << "Ejemplo de \"arreglos al momento\"." << endl;

   // Mensaje sobre el programa
   cout << "\nManejo de un arreglo de datos de tipo float.\n\n";

   // Se pide el n�mero de datos a considerar
   int nD;
   syCapturaNumDatos(nD);

   // Reservamos memoria para un arreglo llamado "p", de nD datos de tipo flotante (inic. en cero)

   float *p = syArregloNuevo(nD);

   // Se fijan todos los datos a un entero aleatorio
   ArregloEnterosAleatorios(p,nD, 10, 20);

//   // Captura manual de los nD Datos
//   syArregloCaptura(p,nD);

   // Se muestran en pantalla los datos
   syArregloEnPantalla(p,nD);

   // C�lculo del promedio de los datos
   float prom;
   syArregloPromedio(p,nD,prom);
   cout << "El promedio de los datos es " << prom << ".\n\n";

   float var;
   syArregloVarianza(p,nD,var);
   cout << "La varianza de los datos es " << var << ".\n\n";


   syArregloOrdenBurbuja(p,nD);
   cout << "\n\nDespu�s de ordenar los datos:\n";
   syArregloEnPantalla(p,nD);

   // Se libera la memoria
   syArregloBorrar(p);


   cout << "\n\nPara salir, presiona <Enter>.";
   cin.get();
   return 0;
}
// Fin de funci�n main()

// Inicio de definici�n de funciones ...
int syCapturaNumDatos(void)
{
  int nD;
   do
   {
      cout << "Indica el n�mero de datos en el arreglo (al menos 1): ? ";
      cin >> nD; cin.ignore();
   } while( nD < 1 );

   return nD;
}

int syCapturaNumDatos(int &nD)
{
   do
   {
      cout << "Indica el n�mero de datos en el arreglo (al menos 1): ? ";
      cin >> nD; cin.ignore();
   } while( nD < 1 );

   return 0;
}



