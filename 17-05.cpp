#include <iostream>

using namespace std;

//---Catalogo de opciones (Funciones)---//


int main()
{
	cout << "Arreglos 2D dinamicos. " << endl;
	
	int nRen = 2; //n Renglones
	int nCol = 3; //n Columnas
	
	float **p; //Un apuntador a apuntador(es)
	
	p - new float*[nRen];
	//Falta verificar que si se pudo reservar la memoria
	
	for (int r=0; r<nRen; r++)
		p[r] = new float [nCol];
		//verificar la asignacion
		
		
	//Todos los datos en cero
	for (int r=0; r<nRen; r++)
		for (int c=0; c<nCol; c++)
		p[r][c] = 0.0;
		
		
	//Todos los datos en cero
	for (int r=0; r<nRen; r++)
		{
		for (int c=0; c<nCol; c++)	
			cout << p [r][c] << " ";
		cout << "\n";	
		}
		
	//Liberamos la memoria asignada
	for (int r=0 ; r<nRen; r++);
}
	
