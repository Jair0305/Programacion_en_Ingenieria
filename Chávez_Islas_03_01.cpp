//Propiedad de Jair Chávez Islas

#include <iostream>
#include <math.h>

using namespace std;

long double fibonacci(long double n);
int syPausa(void);
int verificaciondesalida(void);
void fibonacci2(void);
void fibonacci3(void);

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
         cout << "Hecho por Jair Chávez Islas";
         cout << "\nIngrese el numero que desee, segun la accion que quiera hacer \n";
         cout << "1. saber el n-esimo numero de la serie fibonacci.\n";
         cout << "2. dentro de la serie fubonacci, hay mas numeros apres que impares?\n";
         cout << "3. Cada cuantos numeros hay uno que es multiplo de 5?.\n";

         cout << "0. Salir.\n";

         cout << "\n\n\n";


         cin >> eleccion; cin.ignore();
      } while( eleccion<0 || eleccion>4 );

      switch(eleccion)
      {
         case 1:
            cout << "\nejecutando la accion 1\n";
            cout << "\nIngrese el numero de la serie fibonacci que quiere saber\n";
            cin >> n1;
            cout << fibonacci(n1);
            syPausa();
            break;
         case 2:
            cout << "\n\nejecutando la accion 2\n";
            fibonacci2();
            break;
         case 3:
            cout << "\n\nEjecutando la accion 3.\n";
            fibonacci3();
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

long double fibonacci(long double n)
{
    long double f = 0;
    long double a = 0;
    long double b = 0;
    long double c = 0;
a = pow(((1 + sqrt(5))/2),n);
b = pow(((1 - sqrt(5))/2),n);
c = sqrt(5);

f = (a-b)/c;

return f;
}
void fibonacci2(void)
{
   long double conversion = 0;
   long double contador2 = 0;
   long double contador3 = 0;
   int resultado = 0;
   for ( int contador = 1; contador < 101; contador++)
   {
      
      cout << fibonacci(contador) << " " ;  
        resultado = fibonacci(contador);
       if (resultado%2 == 0)
       {
          contador2 = contador2 + 1;

          //resultado = conversion;
       }
       else{
          if (resultado%2 != 0)
          {
             contador3 = contador3 + 1;
             
             //resultado = conversion;
          }
          
       }
   }
   cout << "\n\nla cantidad de numeros pares que hay dentro de los primeros 100 numeros de la seria fibonacci son: " << contador2;
   cout << "\n\nla cantidad de numeros impares que hay dentro de los primeros 100 numeros de la seria fibonacci son: " << contador3;   
   if(contador2 > contador3){
      cout << "\n\nla cantidad de numeros pares es mayor";
   }
      else{
         if (contador2 < contador3){
      cout << "\n\nla cantidad de numeros impares es mayor\n\n";
         }
         else{
            if (contador2 = contador3){
            cout << "\n\nla cantidad de numeros impares y pares es la misma\n\n";
            }
         }
      }
   
     syPausa();
}
void fibonacci3(void)
{

	long double contador4 = 0;
	long double mul5;
	int resultado;
	for ( int contador = 1; contador < 101; contador++)
	{
		resultado = fibonacci(contador);
	   	cout << resultado << " " ;
	   	if (resultado%5 == 0)
	   	{
	      contador4 = contador4 + 1;
	      cout <<"\n" << contador4;
	   	}
   
	}
   	mul5 = 100/contador4;
   	cout << "\n\ncada " << mul5 << " numeros, encontraras un multiplo de 5";
	syPausa();
}
