#include <iostream>
#include <cmath>
using namespace std;

int mainFibo(void), n;
int mainpr1(void);
int mainpr2(void);
long double h;
int main(void)
{
//    cout << "Ingrese el enesimo numero deseado de la serie: ";
//    cin >> n;
    mainFibo ();
    mainpr1 ();
    mainpr2 ();
   /*  cout << "El enesimo numero de la serie de Fibonacci es... " << h; */

    return 0;
}
   int mainFibo(void)
{
    long double h=0, x=1, rf=1, e1, e2, r5=sqrt(5);
    int i, n;
    e1=(1+r5)/2;
    e2=(1-r5)/2;
/*     cout << e1 << endl;
    cout << e2 << endl; */
//    for(i = 0; i < n-1; i++)
//    {
//        x=rf;
//        rf += h;
//        h = x;
//    }

    cout << "Ingrese el enesimo numero deseado de la serie: ";
    cin >> n;
       if (n< 0)
    {
        cout << "\nHaga lo que se indica arriba en el texto";
        return 0;
    }
//for (i=1; i<=n; i++)
{
    e1=pow(e1,n);
    e2=pow(e2,n);
/*     cout << e1 << endl;
    cout << e2 << endl; */
}
//cout << e1 << endl;
//cout << e2 << endl;

h=(e1-e2)/r5;
cout << "El enesimo numero de la serie de Fibonacci es... " << h <<"\n";


    return 0;
    }
    int mainpr1(void)
    {
        long double h=0, e1, e2, r5=sqrt(5);
        int cont1 = 0, cont2 = 0, con = 0, pr = 0, cont3 = 0;
/*     int i, n; */
    
    for ( int cont = 1; cont < 101; cont++)
   {
/*       cout << cont << " "; */
    e1=(1+r5)/2;
    e2=(1-r5)/2;
    e1=pow(e1,cont);
    e2=pow(e2,cont);
    h=(e1-e2)/r5;
      cout << h << "\n"; 
      h = con;
      if(con%2==0){
          cont1 = cont1 + 1;
      }
      else{
          if(con%2 != 0){
            cont2 = cont2 + 1;
            
            
          }
          
      } 
   }
   if(cont1 > cont2){
    cout <<"el numero de pares es mayor";
   }
   else{
       if(cont1 == cont2){
       cout <<"el numero de pares e impares es igual";
       }
       else{
           if (cont1 < cont2)
           {
               cout <<"el numero de impares es mayor";
           }
           
       }
   }
   
   return 0;
   }

 int mainpr2(void)
{
    long double e1, e2, r5=sqrt(5), pr = 0, con1 = 0;
        int con = 0, h = 0;
for ( int cont = 1; cont < 101; cont++)
   {
    
    
    e1=(1+r5)/2;
    e2=(1-r5)/2;
    e1=pow(e1,cont);
    e2=pow(e2,cont);
    h=(e1-e2)/r5;
    
    if(h%5 == 0)
    {
    con1 = con1 + 1;
    /* cout <<"\n" << con1; */
    }
          
      
   }
   pr = 45/con1;
   cout <<"\n cada "<< pr << " numeros, hay un multiplo de 5";
   return 0;
} 


