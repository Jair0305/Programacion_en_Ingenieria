/*****************************************************************
    								      Programacion en Ingenieria
                  Marco Antonio Escobar Carmona    NUA:147740

*****************************************************************/
#include <iostream>
#include <clocale>
#include <sstream>
#include <fstream>

//Prototipos de Funciones

using namespace std;

int main(){

	int listaHombres[15];
	int listaMujeres[15];
	int listaGeneral[15];

	ifstream archivo;
	string datos;

	int sumaHombres=0;
	int sumaMujeres=0;
	int sumaTotal=0;




	archivo.open("Nacional_Defunciones_Covid19_20210405-20210419.csv", ios::in);

	if(!archivo){
		cout <<"\nError, no se pudo abrir el archivo ";
		exit(1);
	}

	int i=0;

	cout <<"Datos sobre muertes por COVID-19:  ";
	cout <<"\n\n\t\t\t\t\tD\241a \tM Hombres \tM Mujeres  \tM Totales" << "\n";
	for(i=0; getline(archivo, datos); i++){

		stringstream fila(datos);
		string campo;

		for(int c=0; getline(fila, campo, ','); ++c){
			if(c==0){
				listaHombres[i]=stoi(campo);
				sumaHombres+=listaHombres[i];

			} else if(c==1){

				listaMujeres[i]=stoi(campo);
				sumaMujeres+=listaMujeres[i];
			}

		}

		listaGeneral[i]=listaHombres[i]+listaMujeres[i];

		cout << "\n\t\t\t\t\t" << i+5 << "\t\t" << listaHombres[i] << "\t\t" << listaMujeres[i] << "\t\t" <<listaGeneral[i];

	}

	sumaTotal=sumaHombres+sumaMujeres;
	cout <<"\nTotal muertes: " << sumaTotal;
	cout <<"\nNumero de muertes registrado en hombres: " << sumaHombres;
	cout <<"\nNumero de muertes registrado en mujeres: " << sumaMujeres;

	//Determinar cifra mayor
	int dia1, dia2, dia3, dia4, dia5, dia6;
	int mayorHombres=0, menorHombres=0;
	int mayorMujeres=0, menorMujeres=0;
	int mayorGeneral=0, menorGeneral=0;

	int tamano=15;

	for(int k=0; k<tamano; k++){
		if(listaHombres[k]>mayorHombres){
			mayorHombres=listaHombres[k];
			dia1=k+5;
		}

		if(listaMujeres[k]>mayorMujeres){
		 	mayorMujeres=listaMujeres[k];
		 	dia2=k+5;
		}

		if(listaGeneral[k]>mayorGeneral){
			mayorGeneral=listaGeneral[k];
			dia3=k+5;
		}
	}

	menorHombres=mayorHombres;
	menorMujeres=mayorMujeres;
	menorGeneral=mayorGeneral;

	//Determinar la cifra menor
	for(int j=0; j<tamano; j++){
		if(listaHombres[j]<menorHombres){
			menorHombres=listaHombres[j];
			dia4=j+5;
		}
		if(listaMujeres[j]<menorMujeres){
			menorMujeres=listaMujeres[j];
			dia5=j+5;
		}
		if(listaGeneral[j]<menorGeneral){
			menorGeneral=listaGeneral[j];
			dia6=j+5;
		}
	}

	cout <<"\n\nMaxima cifra de defunciones en hombres registradas en un d\241a: " << mayorHombres << "\tFecha: " << dia1 << " de Abril";
	cout <<"\nMinima cifra de defunciones en hombres registradas en un d\241a: " << menorHombres << "\tFecha: " << dia4 << " de Abril";

	cout <<"\n\nMaxima cifra de defunciones en mujeres registradas en un d\241a: " << mayorMujeres << "\tFecha: " << dia2 << " de Abril";
	cout <<"\nMinima cifra de defunciones en mujeres registradas en un d\241a: " << menorMujeres << "\tFecha: " << dia5 << " de Abril";

	cout <<"\n\nMaxima cifra de defunciones en total registradas en un d\241a: " << mayorGeneral << "\t\tFecha: " << dia3 << " de Abril";
	cout <<"\nMinima cifra de defunciones en total registradas en un d\241a: " << menorGeneral << "\t\tFecha: " << dia6 << " de Abril";

		cout << "\n\nPulsa <Enter> para continuar";
		cin.get();

		return 0;
}
