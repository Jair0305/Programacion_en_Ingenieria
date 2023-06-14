// En el código provisto, ¿cuántas variables k diferentes existen?
#include <iostream>
using namespace std;
int main(void)
{
   int k = 0;
   for (int k = 0 ; k < 10; k++ )
      cout << k << " ";
   cout << "\n";
   for (int k = 0 ; k < 10; k++ )
      cout << k << " ";
   cout << "\n";
   for ( k = 0 ; k < 10; k++ )
      cout << k << " ";
   cout << "\n";
   for ( ; k < 20 ; )
      cout << k++ << " ";
   cout <<"\n";
   return 0;
}