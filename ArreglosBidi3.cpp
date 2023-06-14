// MedinaHernandez0225.cpp : Practica ¿Cuál es el Menú?
// Programa creado por Juan Luis Medina Hernández
// Ing. en Sistemas computacionales

#include <iostream>

using namespace std;


//---Catalogo de opciones (Funciones)---//
int syMatrizEnPantalla(float m[] , int nRen, int nCol);

int main()
{
	int nRen=3, nCol=2;
	cout << "Arreglos de 2 (o mas) dimenciones." << endl;
	
	float m [nRen][nCol]; 
	
	//Se fijan los datos al valor 
	
	for (int r=0; r<nRen; r++)
		for (int c=0; c<nCol; c++)
			m[r][c] = 1.5;
			
	//Se muestra en pantalla los datos
	cout << "\nLos datos en el arreglo son: \n";
	for (int r=0; r<nRen; r++)
	{
		for (int c=0; c<nCol; c++)
		cout << m [r][c] << " ";
		cout << "\n";
	}
			
			
	//captura de datos por el ususario
	cout << "\n\nCaputura de los datos: \n";
	for (int r=0; r<nRen; r++)
		for (int c=0; c<nCol; c++)
		{
			cout << "Datos " << r+1 << "," << c+1 << ": ? ";
			cin >> m[r][c]; cin.ignore(); 
		}
	
	/*
	//capturar del 0, 1,2,3, ... n en el arreglo
	int indice = 0;
	for (int r=0; r<nRen; r++)
	{
		
		for (int c=0; c<nCol; c++)
		{
			m[nRen][nCol] = indice;
			indice++;
		}	
	}
	*/
	
	//obtencion del maximo, dentro del arreglo
	float maximo=m[0][0], minimo= m[0][0], promedio=0.0;
	
	for (int r=0; r<nRen; r++)
		for (int c=0; c<nCol; c++)
		{
			if (m[r][c] > maximo)
				maximo = m[r][c];
			else if (m[r][c] < minimo)
				minimo = m[r][c];
				
			promedio += m[r][c];	
		}
		promedio /= nRen * nCol;
			
	
	cout << "El valor maxiomo es: " << maximo;
	cout << "El valor minimo es: " << minimo;	
	cout << "El promedio es: " << promedio;
	
	//Se muestra en pantalla los datos
	cout << "\nLos datos en el arreglo son: \n";
	for (int r=0; r<nRen; r++)
	{
		for (int c=0; c<nCol; c++)
		cout << m [r][c] << " ";
		cout << "\n";
	}
	syMatrizEnPantalla((float *)m,nRen , nCol);
	syMatrizEnPantalla(&m[0][0],nRen , nCol);
	syMatrizEnPantalla(m[0],nRen , nCol);

} 
int syMatrizEnPantalla(float m[] , int nRen, int nCol)
{
	cout <<"\nDatos en la matriz\n";
	for (int r=0; r<nRen; r++ )
	{
		for (int c=0; c<nCol; c++ )
			cout << m[ r*nCol+c ] << " ";
		cout << "\n";
	}
	return 0;
	
}
int syMatrizTraza(float m[] , int nRen, int nCol)
{
	
}





