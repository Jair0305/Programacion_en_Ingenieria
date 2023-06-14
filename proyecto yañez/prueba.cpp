#include <iostream>
#include <conio.h>
#include <clocale>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

void CapturaDatos (int& NumCD);
void MostrarDatos(int& NumCD);
void escribirFrases(int& NumCD);
void modificarEliminar(int &NumCD);
vector<vector<string> > leer(char* filename);
void leerOld();
void DrawTable(vector<vector<string> > database);
int Pausa(void);

struct persona{
	char nombre[30];
	int edad;
	char Sexo[15];
};

struct coleccion_CD {
	char titulo [50];
	char artista [40];
	int numCanciones;
	float precio;
	struct persona info_persona;
} CDS[100];
////////////////////////////////////////////////////////////////////////////////////////
int main(){	
	vector<vector<string> > database;
	
	int i=0, NumCD;
	cout <<"Bienvenido al programa [sy0607] Base de Datos de un Hombre Pobre!"<<endl;
	cout <<"Creado por: Diego Perez Perez"<<endl;
											//CAPTURA DATOS USUARIO
	cout <<"\n\nPor favor, Ingresa tu Nombre: ";
	cin.getline(CDS[i].info_persona.nombre,30,'\n'); 
		
	cout << "Ingresa tu edad: ";
	cin >> CDS[i].info_persona.edad; cin.ignore();
		
	cout << "Sexo?: ";
	cin.getline(CDS[i].info_persona.Sexo,15,'\n');

	
	int eleccion=0;
	// setlocale(LC_ALL, "Spanish");
	setlocale(LC_ALL, "UTF8");
	

	
	do{
		do{
	        system("cls");
	        cout << "\n\n\n\n MENÚ \n";
	        cout << "1. Capturar tu Colección de CD's!!\n";
	        cout << "2. Mostrar los Registros.\n";
	        cout << "3. Ordenar la información (numerica o alfabeticamente).\n";
	        cout << "4. Generar archivo de texto.\n";
	        cout << "5. Leer un archivo con Registros.\n";
	        cout << "6. Modificar o eliminar un registro en especifico";
	        cout << "\n\n0. Salir.\n";
	
	        cout << "\nElección: ";
	        cin >> eleccion; cin.ignore();
	         
		}while( eleccion<0 || eleccion>6 );
		
		switch(eleccion){
	        case 1:
	        	system("cls");
	        	cout <<"Capturar tu Coleccion de CD's!!\n";
	        	CapturaDatos(NumCD);
	        	Pausa();
	        	break;
	        case 2:
	        	system("cls");
	        	cout << "\n\nMostrar los Registros.\n";
	        	MostrarDatos(NumCD);
				Pausa();
	        	break;
	        case 3:
	        	system("cls");
		        cout << "\n\nOrdenar la informacion (Numerica o alfabeticamente).\n";
		        
		        Pausa();
	        	break;
	        case 4:
	        	system("cls");
	        	cout <<"Generar archivo de texto.\n";
	        	escribirFrases(NumCD);
	        	Pausa();
	        	break;
	        case 5:
	        	system("cls");
	        	cout <<"Leer un archivo con Registros.\n";
				DrawTable(leer("Registro.csv"));
	        	Pausa();
	        	break;
	        case 6:
	        	system("cls");
	        	cout <<"Modificar o eliminar un registro en especifico\n";
	        	modificarEliminar(NumCD);
	        	Pausa();
	        	break;
	        case 0:
		        cout << "\n\nRutina de salida.\n";
	        	break;
	        default:
		        cout << "\n\nTarea indefinida, al menos por el momento.\n";
		        Pausa();
		}
	}while(eleccion);
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void CapturaDatos(int& NumCD){
	int i = 0;
	do{
	cout << "\n\nIngresa la cantidad de CD's que quieres Registrar: ";
	cin >> NumCD; cin.ignore();
	
	if (NumCD > 100){
		cout <<"ERROR. No puedes agregar mas de 100 Registros!!";
	}else if (NumCD < 0) {
		cout <<"ERROR. No puedes agregar valores Negativos!!";
	}else if (NumCD == 0) {
		cout <<"ERROR. Debes agregar almenos 1 registro!!";
	}else{
		cout << "\nAlmacenando " << NumCD << " Registro(s)!";
	}
	}while (NumCD < 1 || NumCD > 100 || NumCD == 0);
	for(i=0 ; i<NumCD ; i++){
	int k = i+1;
		cout << "\n\nCD " << " " << k ;
		cout << "\nIngresa el Titulo del CD: ";
		cin.getline(CDS[i].titulo,50,'\n');
		
		cout << "Ingresa el Artista: ";
		cin.getline(CDS[i].artista,40,'\n');
		
		cout << "Ingresa el numero de canciones que contiene el CD: ";
		cin >> CDS[i].numCanciones; cin.ignore();
		
		cout << "Ingresa el precio del CD: ";
		cin >> CDS[i].precio; cin.ignore();
	}
	
	if (NumCD < 2 && NumCD > 0){
		cout << "\n\nRegistro Guardado!";
	}else if(NumCD > 1 && NumCD > 0){
		cout << "\n\nRegistros Guardados!";
	}
}
//////////////////////////////////////////////////////////////////////////////////////
void MostrarDatos(int& NumCD){
	
	int i = 0;
	cout << "Mostrando Registro de datos almacenados: \n";
	cout << "\n\nNombre: " << CDS[i].info_persona.nombre;
	cout << "\nEdad: " << CDS[i].info_persona.edad;
	cout << "\nSexo: " << CDS[i].info_persona.Sexo;
	
	for (int k=0; k < NumCD ; k++){
	int j = k+1;
	cout << "\n\nCD " << j << "\n";
	cout << "\nTitulo: " << CDS[k].titulo;
	cout << "\nArtista: " << CDS[k].artista;
	cout << "\nNumero de Canciones: " << CDS[k].numCanciones;
	cout << "\nPrecio:$ " << CDS[k].precio;
	}
}
/////////////////////////////////////////////////////////////////////////////////////
void escribirFrases(int& NumCD){
	ofstream archivo;
	string nombreArchivo,frase;
	
	cout<<"Digite el nombre del archivo: ";
	getline(cin,nombreArchivo);
	
	archivo.open(nombreArchivo.c_str(),ios::out); //Creamos el archivo
	
	if( archivo.fail() ){ 
		cout<<"No se pudo abrir el archivo";
	}
	cout <<"Registros Guardados: ";
	MostrarDatos(NumCD);
	int i = 0;
	archivo << "\n\nNombre: " << CDS[i].info_persona.nombre << ", ";
	archivo << "Edad: " << CDS[i].info_persona.edad << ", ";
	archivo << "Sexo: " << CDS[i].info_persona.Sexo << ", ";
	
	for (int k=0; k < NumCD ; k++){
	int j = k+1;
	archivo << "\nCD " << j << ", ";
	archivo << "Titulo: " << CDS[k].titulo << ", ";
	archivo << "Artista: " << CDS[k].artista << ", ";
	archivo << "Numero de Canciones: " << CDS[k].numCanciones << ", ";
	archivo << "Precio:$ " << CDS[k].precio;
	}
	archivo.close();
}

void modificarEliminar(int &NumCD){
	int decision;
	MostrarDatos(NumCD);
	cout << "\n\nIndica que registro quieres modificar o eliminar: " ;
	cin >> decision; cin.ignore();
	
	cout << "\n\n Modificando el registro: " << decision;
	cout << "\n\nCD " << " " << decision ;
	decision = decision - 1;
	
	cout << "\nIngresa el Titulo del CD: ";
	cin.getline(CDS[decision].titulo,50,'\n');
		
	cout << "Ingresa el Artista: ";
	cin.getline(CDS[decision].artista,40,'\n');
		
	cout << "Ingresa el numero de canciones que contiene el CD: ";
	cin >> CDS[decision].numCanciones; cin.ignore();
		
	cout << "Ingresa el precio del CD: ";
	cin >> CDS[decision].precio; cin.ignore();
	
	
	cout << "\n\nRegistro Guardado!";
}

void leerOld(){
	
	ifstream infile("Registro.csv");
	string line = "";
	vector<string> datos_csv;
	while (getline(infile, line)){
		stringstream strstr(line);
		string word ="";
		while(getline(strstr,word, ';')){
			datos_csv.push_back(word);
		}
	}
	for (int i=0; i<datos_csv.size(); i++){
		cout << datos_csv.at(i) << "\n";
	}
}
void DrawTable(vector<vector<string> > database) {
	vector<int> line_sizes;
	line_sizes.resize(database[0].size());
	
	for(int i = 0; i < database.size(); i++) {
		vector<string> row = database.at(i);
		for(int j = 0; j < row.size(); j++) {
			string word = row.at(j);
			int max_lenght = line_sizes.at(j);
			int word_len = word.length();
			if(max_lenght < word_len) {
				line_sizes.at(j) = word_len;
			}
		}
	}
	
	for (int i=0; i<database.size(); i++){
		vector<string> line = database.at(i);
		if(i == 0) {
			cout << "\n";
			for(int j=0; j<line.size(); j++) {
				cout << (j==0 ? (char)218  : (char)194) << setfill((char)196) << setw(line_sizes.at(j)) << "";
			}
			cout << (char)191;
			cout << "\n";
		}
		for(int j=0; j<line.size(); j++) {
			cout << (char)179 << setfill(' ') << setw(line_sizes.at(j)) << line.at(j);
		}
		cout << (char)179;
		if(i == 0) {
			cout << "\n";
			for(int j=0; j<line.size(); j++) {
				cout << (j==0 ? (char)195  : (char)197) << setfill((char)196) << setw(line_sizes.at(j)) << "";
			}
			cout << (char)180;
		}
		if(i == database.size() - 1) {
			cout << "\n";
			for(int j=0; j<line.size(); j++) {
				cout << (j==0 ? (char)192  : (char)193) << setfill((char)196) << setw(line_sizes.at(j)) << "";
			}
			cout << (char)217;
			cout << "\n";
		}
		cout << "\n";
	}
}
vector<vector<string> > leer(char* filename){
	
	ifstream infile(filename);
	string line = "";
	
	vector<vector<string> > datos_csv;
	vector<int> line_sizes;
	while (getline(infile, line)){
		stringstream strstr(line);
		string word ="";
		vector<string> line_data;
		while(getline(strstr,word, ',')) {
			line_data.push_back(word);
		}
		datos_csv.push_back(line_data);
	}
	return datos_csv;
	
}

///////////////////////////////////////////////////////////////////////////////////
int Pausa (void){
	cout << "\n\nPara salir, presiona <Enter>.";
	cin.get();
	return 0;
}
