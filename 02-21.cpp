#include <iostream>

using namespace std;

double syFactorial(int num);

int main(void)
{
	int num1;
	int num2;
	int num3; //el tercer numero es la resta de los 2 primeros
	long double fnum1;
	long double fnum2;
	long double fnum3; //factorial de al resta de n y k
	long double c; //combinacion

	cout << "vamos a ver el numero de combinaciones que se pueden hacer entre 2 numeros de algo";
	cout << "\nintroduce el primer numero";
	cin >> num1; cin.ignore(); 
	cout << "introduce el segundo numero";
	cin >> num2; 
	cin.ignore();
	
    fnum1 = syFactorial(num1);
    fnum2 = syFactorial(num2);
    fnum3 = syFactorial(num3);

    if(num2 > num1)
    {
    cout << "El numero 1 debe ser mayor";
    }
    else
    {
    c = fnum1 / fnum3 * fnum2; 
    }
    return 0;
}

double syFactorial(int num)
{
   if(num<0)
   {
      cout << "\nEste número no tiene factorial.\n";
      return -1;
   }
   else if(num==0)
      return 1.0;

   double factorial = 1.0;
   while(num > 1)
      factorial *= num--;
   return factorial;
}


