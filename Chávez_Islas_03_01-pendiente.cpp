//Propiedad de Jair Chávez Islas

#include <iostream>
#include <math.h>

using namespace std;

int fibonacci(int n);
int syPausa(void);
int verificaciondesalida(void);
int fibonacci2(int n2);
int fibonacci1(int n1);

int main(void)
{


	setlocale(LC_CTYPE, "Spanish"); // Para caracteres en Español
	cout << "\nEjemplo de un menú básico.\n\n";
	syPausa();

   // un menú muy básico
   int eleccion = 0;
   int n = 0;
   int n1 = 0;
   int n2 = 0;
   do
   {
      do
      {
         system("cls");
        
         cout << "\n\n\n\nIngrese el numero que desee, segun la accion que quiera hacer \n";
         cout << "1. saber el n-esimo numero de la serie fibonacci.\n";
         cout << "2. Ejecutar la tarea 2: numeros primos.\n";
         cout << "3. Ejecutar la tarea 3: combinaciones.\n";

         cout << "0. Salir.\n";

         cout << "\n\n\n";


         cin >> eleccion; cin.ignore();
      } while( eleccion<0 || eleccion>4 );

      switch(eleccion)
      {
         case 1:
            cout << "\nIngrese el numero de la serie fibonacci que quiere saber\n";
            cin >> n1;
            fibonacci1(n1);
            break;
         case 2:
            cout << "\n\nDentro de los 100 primeros numeros de la serie fibonacci, hay mas numeros impares que pares?\n";
            fibonacci2(n2);
            break;
         case 3:
            cout << "\n\nEjecutando la tarea 3.\n";
            break;
         case 0:
            eleccion = verificaciondesalida();
            break;
         default:
            cout << "\n\nTarea indefinida, al menos por el momento.\n";

            syPausa();
      }
   } while( eleccion );

   return 0;
}



int syPausa(void)
{
    cout << "\nPresione <enter> para continuar";
    cin.get(); cin.ignore();
    return 0;
}
int verificaciondesalida(void)
{
   int decision;
   do
   {
      cout << "\n\nConfirmas tu deseo de salir 0=SALIR 1=CONTINUAR: ? ";
      cin >> decision; cin.ignore();
   } while(decision < 0 || decision > 1);

   // Regresar un 1 si NO QUIERE SALIR; un 0 si SI QUIERE SALIR
   return decision;
}

int fibonacci(int n)
{
    double f = 0;
    double a = 0;
    double b = 0;
    double c = 0;
a = pow(((1 + sqrt(5))/2),n);
b = pow(((1 - sqrt(5))/2),n);
c = sqrt(5);

f = (a-b)/c;

return f;
}
int fibonacci1(int n1)
{
double f = 0;
    double a = 0;
    double b = 0;
    double c = 0;
a = pow(((1 + sqrt(5))/2),n1);
b = pow(((1 - sqrt(5))/2),n1);
c = sqrt(5);

f = (a-b)/c;

cout <<"el resultado es" << f;
syPausa();
return 0;
}

int fibonacci2(int n2)
{
   do
   {
      fibonacci(n2);
      cout << fibonacci(n2) << " " ;
   } while (fibonacci(n2) == 100);
   
     syPausa();
    return 0;
}

