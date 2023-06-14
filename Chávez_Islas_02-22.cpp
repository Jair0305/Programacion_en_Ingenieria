#include <iostream>

using namespace std;

long double syFactorial(int num);
int main(void)
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
    