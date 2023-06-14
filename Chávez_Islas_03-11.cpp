#include <iostream>

using namespace std;

int main(){
    
    //Maestro, estuve viendo varios videos y me quedó la idea de como hacerlo bien, pero no fue del todo claro el ejercicio, se me complicó 
    //un poco, aquí está la que menos complicada se me hizo, pero hay un problema y es que muestra 8 numeros, sin importar si el binario del 
    //numero ocupa solo 4, sin embargo, me pareció interesante y quiero terminar de hacerlo bien, solo que por falta de tiempo, no pude en
    //estos momentos, pero es algo que seguiré investigando para hacerlo mejor
    //Jair Chávez Islas


    int numero;
    short binario[8];

    cout <<"Escribe el numero que se desea cnvertir a binario\n";
    cin >> numero;
    
    for (int i = 0; i < 8; i++)
    {
        binario[i] = numero%2;
        numero /= 2;
    }
    
    cout <<"El numero convertido a binario es:" << endl;

    for (int i = 7; i >= 0; i--)
    {
        cout <<binario[i];
    }
    

    return 0;
}