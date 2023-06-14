#include <iostream>

using namespace std;
int main(void) {

int N;

cout << "Introduce un numero entero: ";
cin >> N; cin.ignore();
cout << "El numero que introdujo tiene los siguientes valores: \n\n";

//el siguiente codigo es apra deterinar si es negativo, positivo o identico a cero
if(N == 0){
    cout <<"Es cero";
    if(N > 0){
    cout <<"Es positivo \n";
}
else{
    cout <<"Es negativo \n";
}

//el siguiente codigo es para saber si el codigo es par o inpar

if(N%2 == 0){
    cout<<"Es par \n";
}
else{
    cout<<"Es impar \n";
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
}
else
return 0;
}
