#include <iostream>

using namespace std;

int main()
{
    cout << "Ejercicios con arreglos" << endl;

    //Declaracion de una array
    //<tipo><identificador>[size];

    float x[10] = { }; //Arreglo de diez datos de tipo flotante e inicializacion en 0


    //Los datos tienen un nombre en comun, en este caso "x"
    //Los datos tienen un tipo de dato comun, flotante en este caso
    //Podemos acceder a cada uno de los datos mediante un indice, el cual va desde 0 hasta size-1
    //Usualmente usamos ciclos para la manipulacion de datos del arreglo

    //Datos en en el arreglo
    cout << "Los datos en el arreglo son: \n" << endl;
    for(int k = 0; k<10; k++)
    {
        cout << x[k] << " ";
    }
    
    //fijacion de unos

    for ( int k=0 ; k < 10; k++)
    {
        x[k] = 1;
    }

    //datos en la pantalla

    cout << "\n\n Los datos en el arreglo:\n";
    for ( int k = 0; k < 10; k++)
    {
        cout << x[k] << " " ;
    }
    
    
    cout << "\nPara salir presione <Enter>" << endl;
    cin.get();
    return 0;
}