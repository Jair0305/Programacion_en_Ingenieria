// syArreglos2D.cpp
// R.E. Sánchez Yáñez

#include <iostream>

using namespace std;

int syMEP(float m[], int nRen, int nCol);
int sytraza(float m[], int nRen, int nCol, float &traza);
int main(void)
{
   cout << "Arreglos de 2 (o más) dimensiones." << endl;

   // Se definen las dimensiones del arreglo:
   int nRen = 3;
   int nCol = 3;
   // Estas variables se le pueden preguntar al usuario.


   float m[nRen][nCol];

   // Captura dato por dato, de manera manual
   cout << "\n\nCaptura de los datos:\n";
   for(int r=0; r<nRen; r++)
      for(int c=0; c<nCol; c++)
      {
         cout << "Dato "<<r+1<<","<<c+1<<": ? ";
         cin >> m[r][c]; cin.ignore();
      }


   // Se muestan en pantalla los datos
   cout << "\n\nLos datos en el arreglo son:\n";
   for(int r=0; r<nRen; r++)
   {
      for(int c=0; c<nCol; c++)
         cout << m[r][c] << " ";
      cout << "\n";
   }

   // Obtención del máximo dentro del arreglo
   float maximo=m[0][0], minimo=m[0][0], promedio=0.0;

   // Su código va aquí
   for(int r=0; r<nRen; r++)
      for(int c=0; c<nCol; c++)
      {
         if(m[r][c] > maximo)
            maximo = m[r][c];
         else if(m[r][c] < minimo)
            minimo = m[r][c];
         promedio += m[r][c];
      }
   promedio /= nRen*nCol;
   
   syMEP((float *)m, nRen, nCol);
   syMEP(&m[0][0], nRen, nCol);
   syMEP(m[0], nRen, nCol);
   
   float traza;
   sytraza((float*)m, nRen, nCol, traza);
   cout<<"\n\n la traza es de: " << traza<< "\n\n";

   cout << "\n\nEl máximo de los datos es: " << maximo << endl;
   cout << "El mínimo de los datos es: " << minimo << endl;
   cout << "El promedio de los datos es: " << promedio << endl;
   
   // Usar una funcion para mostrar los datos



   cout << "\n\nPara salir, presiona <Enter>.";
   cin.get();
   return 0;
}

syMEP(float m[], int nRen, int nCol)
{
	cout <<"\n\nDatos en la matriz\n";
	for(int r=0; r < nRen; r++)
	{
		for(int c=0; c<nCol; c++)
		{
			cout << m[ r*nCol + c ] << "" ;
		}
		cout <<"\n";
	}
}
sytraza(float m[], int nRen, int nCol, float &traza)
{
	if(nRen!=nCol)
	{
		cout<<"error";
		return -1;
	}
	traza = 0;
	for(int r = 0; r<nRen; r++)
	{
		traza += m[r*nCol + r];
	}
	return 0;
}
