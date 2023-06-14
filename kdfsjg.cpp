#include <iostream>

using namespace std;
int main(void)
{
int N;

cout << "Introduce un numero entero:  ";
cin >> N; cin.ignore();
cout << "El numero que introdujo tiene los siguientes valores: \n\n";

//el siguiente codigo es apra deterinar si es negativo, positivo o identico a cero
if(N==0)
    {
    cout <<"Es cero\n";
    return 0;
    }
else
    {
        if(N>0)
        {
            cout<<"Es positivo\n";
            if(N%2==0)
            {
                cout<<"Es par\n";
                if(N%3==0)
                {
                    cout<<"Es divisible entre 3\n";
                    if(N<10)
                    {
                        cout<<"Es de un digito\n";
                    }
                    else
                    {
                        cout<<"No es de un digito\n";
                    }
                }
                else
                {
                    cout<<"No es divisible entre 3\n";
                    if(N<10)
                    {
                        cout<<"Es de un digito\n";
                    }
                    else
                    {
                        cout<<"No es de un digito\n";
                    }
                }
            }
            else
            {
                cout<<"Es impar\n";
                if(N%3==0)
                {
                    cout<<"Es divisible entre 3\n";
                    if(N<10)
                    {
                        cout<<"Es de un digito\n";
                    }
                    else
                    {
                        cout<<"No es de un digito\n";
                    }
                }
                else
                {
                    cout<<"No es divisible entre 3\n";
                    if(N<10)
                    {
                        cout<<"Es de un digito\n";
                    }
                    else
                    {
                        cout<<"No es de un digito\n";
                    }
                }

            }
        }
        else
        {
            cout<<"Es negativo\n";
            if(N%2==0)
            {
                cout<<"Es par\n";
                if(N%3==0)
                {
                    cout<<"Es divisible entre 3\n";
                    if(N>-10)
                    {
                        cout<<"Es de un digito\n";
                    }
                    else
                    {
                        cout<<"No es de un digito\n";
                    }
                }
                else
                {
                    cout<<"No es divisible entre 3\n";
                    if(N>-10)
                    {
                        cout<<"Es de un digito\n";
                    }
                    else
                    {
                        cout<<"No es de un digito\n";
                    }
                }
            }
            else
            {
                cout<<"Es impar\n";
                if(N%3==0)
                {
                    cout<<"Es divisible entre 3\n";
                    if(N>-10)
                    {
                        cout<<"Es de un digito\n";
                    }
                    else
                    {
                        cout<<"No es de un digito\n";
                    }
                }
                else
                {
                    cout<<"No es divisible entre 3\n";
                    if(N>-10)
                    {
                        cout<<"Es de un digito\n";
                    }
                    else
                    {
                        cout<<"No es de un digito\n";
                    }
                }

            }
        }
    }
}
