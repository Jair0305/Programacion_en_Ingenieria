// syIntercambio.cpp

// R.E. Sánchez Yáñez



// Directivas de preprocesador
#include <iostream>

// Declaraciones globales
using namespace std;

// Prototipos de funciones

float syCaptura(void);
int syCaptura(float &x);
int syIntercambio(float &x, float &y);

// Inicio de función main()
int main(void){
    cout << "intercambio de dos valores";
    float a;

    a = syCaptura();

    cout << "\n\nEl dato a es:" << a << endl;

    float b;
    syCaptura( b );
    cout << "\n\nEl dato b es:" << b << endl;

    //intercambio de dos valores
    syIntercambio (a,b);
    cout << "regresando a main() \nLos datos son:" << a << ", " << b ;



    cout << "\n\nPara salir, presiona <Enter>.";
    cin.get();
    return 0;
}
// Fin de función main()

// Inicio de definición de funciones ...
int syIntercambio(float &x, float &y){
    cout << "Al ingresar a SyIntercambio(): " ;
    cout << "los datos son " << x << ", " << y << endl;

    float aux = x;
    x = y;
    y = aux;

    cout << "Al salir de SyIntercambio(): " ;
    cout << "los datos son " << x << ", " << y << endl;
    return 0;
}
int syCaptura(float &x){             //capturar con referencia
    cout << "\n\nintroduce un dato: ?";
    cin >> x; cin.ignore();
    return 0;
}
float syCaptura(void){
    float a;
    cout << "\n\nintroduce un dato: ?";
    cin >> a; cin.ignore();
    return a;
}