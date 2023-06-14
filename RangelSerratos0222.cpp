/*
        COMBINACIONES 0222
Angel Julian Rangel Serratos
NUA: 147661
Programación en ingeniería
*/
//directivas del procesador
#include <iostream>
#include <clocale>

//declaraciones globales
using namespace std;
int rsFactorial(int num);
int main (void)
{
    int x =0;
    int y =0;
    int z = 0;
    long double n ;
    long double m ;
    long double w ;
    cout << "Vamos a calcular las combinaciones posibles de los numeros enteros usando xCy \n\n" << endl;
    cout << "||||| USA SOLO NUMEROS ENTEROS |||||\n\n";
    cout << "introduce X: " << endl;
    cin >> x; cin.ignore();
    cout << "\n\n introduce Y: " << endl;
    cin >> y; cin.ignore();
    if (x > y)
    {
        z = (x-y);
        w = rsFactorial(z);
        n = rsFactorial(x);
        m = rsFactorial(y);
        long double combinaciones = 0;
        combinaciones = ( n /( m * w ));
        cout << "Existen " << combinaciones << " combinaciones para xCy";
    }
    else
    {
        cout << " X tiene que ser mayor a Y";
    }
}

int rsFactorial(int num)
{
    long double factorial;  //esperamos que esto nos de valores más grandes a pesar de que no sean tan precisos
    factorial = 1;
    int i ;
    i = 1;
    while (i <= num )
    {
        factorial *= i;
        i++;
    }


return factorial;
}

/* no podemos estar del todo seguros de que los numero calculados para valores
grandes que sean otorgados por el usuario sean correctos, más que nada debido a las limiticaciones que
tiene el lenguaje respecto al número de dígitos*/
