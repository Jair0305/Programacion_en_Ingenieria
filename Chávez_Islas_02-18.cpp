#include <iostream>

using namespace std;


// Propiedad de Jair Chávez Islas
int main()
{
     float si = 0; //se guardan los numeros
     int numdusuario = 0;
     int contador = 0;
     float promedio = 0;
     int syEsprimo(int num);

     cout << "Ingresa un numero entre 1 y 1000\n";
     cin >> numdusuario;
     cin.ignore();

     //cantidad de numeros primos
     for(int i = 2; numdusuario > 0; i++)
     {
         if (syEsprimo(i) == 1)
         {
             cout << i << " " ;
             contador ++;
             si = si  + i;
         }
         if (contador == numdusuario)
         {
             break;
         }
     }
     promedio = si/contador;
     cout <<"\nel promedio es " << promedio << endl; 
    return 0;
}

//funcion del codigo del maestro



// Inicio de definición de funciones ...
int syEsprimo(int num)
{
   int esPrimo = 1;
   // Verificación de si num es primo o no
   if (num < 2)
   {
      esPrimo = 0;
   }
   else
   {
      if (num == 2 || num == 3)
         esPrimo = 1;
      else
      {
         if(num%2==0)
         esPrimo = 0;
         else
         {
            for(int k=3; k < num/2 ; k+=2 )
               if( num%k == 0)
               {
                  esPrimo = 0;
                  break;
               }
         }
      }
   }
   return esPrimo;
}
