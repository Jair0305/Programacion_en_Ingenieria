// syCiclos_do-while.cpp
// R.E. Sánchez Yáñez

// Directivas de preprocesador
#include <iostream>
#include <clocale>

// Declaraciones globales
using namespace std;

// Prototipos de funciones
int syVerificacionDeSalida(void);
int syPausa(void);

int syEsprimo(int num);
int mainPrimos(void);
int maintarea1(void);
int maintarea2(void);
int maintarea3(void);



int main(void)
{
	setlocale(LC_CTYPE, "Spanish"); // Para caracteres en Español
	cout << "\nEjemplo de un menú básico.\n\n";
	syPausa();

   // un menú muy básico
   int eleccion = 0;

   do
   {
      do
      {
         system("cls");
         // se muestran las opciones
         cout << "\n\n\n\nEl menú es \n";
         cout << "1. #jecutar la tarea 1: Descripcion de un numero.\n";
         cout << "2. Ejecutar la tarea 2: numeros primos.\n";
         cout << "3. Ejecutar la tarea 3: combinaciones.\n";

         cout << "0. Salir.\n";

         cout << "\nElección ? ";

         // se captura la opción deseada
         cin >> eleccion; cin.ignore();
      } while( eleccion<0 || eleccion>4 );

      switch(eleccion)
      {
         case 1:
            cout << "\n\nEjecutaremos la tarea 1.\n";
            maintarea1();
            break;
         case 2:
            cout << "\n\nEjecutaremos la tarea 2.\n";
            maintarea2();
            break;
         case 3:
            cout << "\n\nEjecutando la tarea 3.\n";
            maintarea3();
            break;
         case 0:
            cout << "\n\nRutina de salida.\n";
            eleccion = syVerificacionDeSalida();
            break;
         default:
            cout << "\n\nTarea indefinida, al menos por el momento.\n";
            syPausa();
      }
   } while( eleccion );

   return 0;
}

int syVerificacionDeSalida(void)
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

int syPausa(void)
{
   cout << "\n\nPara salir, presiona <Enter>.";
   cin.get();
   return 0;
}

// Fin de función main()

// Inicio de definición de funciones ...



//tarea 2 02/18 Numeros primos----------------------------------------------------------------------------------

// Propiedad de Jair Chávez Islas
int maintarea2(void)
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
     syPausa();
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
//tarea 1 02/11 descripcion de un numero-------------------------------------


int maintarea1(void) {

int N;

cout << "Introduce un numero entero:  ";
cin >> N; cin.ignore();
cout << "El numero que introdujo tiene los siguientes valores: \n\n";

//el siguiente codigo es apra deterinar si es negativo, positivo o identico a cero
if(N > 0){
    cout <<"Es positivo \n";
}
else if(N == 0){
    cout <<"Es igual a cero \n";
}
else{
    cout <<"Es negativo \n";
}

//el siguiente codigo es para saber si el codigo es par o inpar

if(N%2 == 0){
    cout<<"Es par \n";
}
else{
    cout<<"Es inpar \n";
}
//el siguiente codigo es para saber si el numero es multiplo de 3
if(N%3 == 0){
    cout<<"Es multiplo de tres \n";
}
else{
    cout<<"No es multiplo de 3 \n";
}
//el sigueinte codigo es apra saber si es un digito
if(N > -1  && N<10){
    cout<<"Es un digito \n";
}
else{
    cout<<"No es un digito \n";
}
syPausa();
return 0;
}

//tarea 3 02/22 combinaciones---------------------------------------------------------------------
long double syFactorial(int num);
int maintarea3(void)
{

int num1;
int num2;
int num3; //el tercer numero es la resta de los 2 primeros
long double fnum1;
long double fnum2;
long double fnum3; //factorial de al resta de n y k
long double c = 0; //combinacion

cout << "Vamos a ver el numero de combinaciones que se pueden hacer entre dos numeros\nPropiedad de Jair Chavez Islas" << endl;
cout << "introduce el primer numero" << endl;
cin >> num1; cin.ignore(); 
cout << "introduce el segundo numero" << endl;
cin >> num2; cin.ignore();


    if(num2 > num1)
    {
    cout << "El numero 1 debe ser mayor" << endl;
    return 0;
    }
    else
    {
    num3 = num1 - num2;
    fnum1 = syFactorial(num1);
    fnum2 = syFactorial(num2);
    fnum3 = syFactorial(num3);
    c = (fnum1 / (fnum3 * fnum2)); 
    }
    cout << "existen " <<  c  << " combinaciones" << endl;
    syPausa();
    return 0;
}
//codigo del maestro
    long double syFactorial(int num)
{
   if(num<0)
   {
      cout << "\nEste número no tiene factorial.\n";
      return -1;
   }
   else if(num==0)
      return 1.0;

   long double factorial = 1.0;
   while(num > 1)
      factorial *= num--;
   return factorial;
}