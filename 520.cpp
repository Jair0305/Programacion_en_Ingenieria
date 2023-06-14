#include <iostream>

using namespace std;


struct pista
{
	string nombre;
	string artista;
	float duracion;
	int anho;
	//...
};



//Prototipos de funciones



int main()
{
	cout <<"estructuras1"<< endl;
	
	struct pista pst;
	
//	pst.anho = 2021; // Se accede a los miembros de la estructura
//	pst.duracion = 4.6;
	
	//Captura de datos
	
	cout<<"\n\n\nCapturando datos de una pista\n\n\n";
	
	cout<<"Interprete: ";
	//cin >> pst.artista; cin.ignore();
	getline(cin,pst.artista);
	cout<<"Nombre: ";
	//cin >> pst.nombre; cin.ignore();
	getline(cin,pst.nombre);
	cout<<"Anho : ";
	cin >> pst.anho; cin.ignore();
	cout<<"Duracion : ";
	cin >> pst.duracion; cin.ignore();
	
	
	//Datos en pantalla
	cout<<"\n\n\n\n\nLos datos capturados son: \n\n\n\n";
	cout<<"El anho es: "<< pst.anho << endl;
	cout<<"La duracion es de: "<< pst.duracion << endl;	
	cout<<"Interprete: "<< pst.artista << endl;
	cout<<"Nombre: "<< pst.nombre << endl;
	
	cout<<"\n\nPara salir presione enter";
	cin.get();
	return 0;
}
