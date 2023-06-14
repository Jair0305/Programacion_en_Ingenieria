//Programa hecho por Jair Chávez Islas

#include <iostream>
#include <clocale>
#include <fstream>
#include<string.h>
using namespace std;

typedef struct
{
   string nombre;
   string interprete;
   float duracion;
   int anio;
}pista;

typedef struct
{
   string nombre;
   float duracion;
   int nPistas; // El máximo deberá de ser 100
   pista pst[100];
   // ...
} album;

int syVerificacionDeSalida(void);
int syPausa(void);
int Capturar(pista &p);
int syEsprimo(int num);
int mainPrimos(void);
pista 
Capturar(void);
int Mostrar(pista p);
int Mostrarn(pista p, int &n);
int syArregloDiscoAgregar(album & pst);
void archtxt(pista p);
void leer();

int main(void)
{
   int eleccion = 0;
   int nPistas, i=0;
   album alb;
   do
   {
      do
      {
         system("cls");
         // se muestran las opciones
         cout<<"Programa hecho por Jair Chavez Islas\n\n\n\n\n\n\n";
         cout << "que desea hacer?\n";
         cout << "1. Capturar los datos de un album y sus canciones.\n";
         cout << "2. Mostrar en pantalla los registros.\n";
         cout << "3. Mostrar datos forma numerica.\n";
         cout << "4. Mostrar datos forma alfabetica.(Incompleto)\n";
         cout << "5. Generar archivo.\n";
         cout << "6. Leer archivo de base de datos.\n";
         cout << "7. Modificar registro.(Incompleto)\n";
         cout << "8. Eliminar registro.(Incompleto)\n";

         cout << "0. Salir.\n";

         cout << "\ndigite el numero y presione <enter> segun la opcion que quiera: ";

         cin >> eleccion; cin.ignore();
      } while( eleccion<0 || eleccion>9 );

      switch(eleccion)
      {
        case 1:
        cout << "Nombre del album:      ";
        getline(cin,alb.nombre);
        cout << "Duracion:    ";
        cin >> alb.duracion; cin.ignore();
   
        do
        {
        cout << "Num pistas:  ";
        cin >> alb.nPistas; cin.ignore();
        } while (alb.nPistas<1 || alb.nPistas>20);

        for(int k=0; k<alb.nPistas; k++)
		{
        Capturar( alb.pst[k] );
        }
        	syPausa();
            break;
        case 2:
        	cout << "\n\n Datos el album \n";
            cout << "Nombre:     " << alb.nombre << endl;
            cout << "Duracion:   " << alb.duracion << endl;
            cout << "Num pistas: " << alb.nPistas << endl;
            for(int k=0; k<alb.nPistas; k++)
			{
				int n = k+1;
                Mostrar( alb.pst[k]);
            }
        	syPausa();
            break;
        case 3:
        	
        	for(int k=0; k<alb.nPistas; k++)
			{
				int n = k+1;
                Mostrarn( alb.pst[k], n );
            }
        	
        	syPausa();
            break;
        case 4:
        	cout<<"incompleto";
        	syPausa();
            break;
        case 5:
        	for(int k=0; k<alb.nPistas; k++)
			{
                archtxt( alb.pst[k]);
            }
            cout<<"lo unico que se manda al archivo es la ultima cancion guardada y no pude ahcer que se guardara todo";
        	syPausa();
            break;
        case 6:
        	leer();
        	syPausa();
            break;
        case 7:
        	syPausa();
            break;
        case 8:
        	cout<<"cola";
        	syPausa();
            break;
            
        case 0:
            cout << "\n\nRutina de salida.\n";
            eleccion = syVerificacionDeSalida();
            break;
        default:
            cout << "\n\nTarea indefinida, al menos por el momento.\n";
            syPausa();
      }
   } while( eleccion );

   return 0;
}

int syVerificacionDeSalida(void)
{
   int decision;
   do
   {
      cout << "\n\nConfirmas tu deseo de salir 0=SALIR 1=CONTINUAR: ? ";
      cin >> decision; cin.ignore();
   } while(decision < 0 || decision > 1);

   // Regresar un 1 si NO QUIERE SALIR; un 0 si SI QUIERE SALIR
   return decision;
}

int syPausa(void)
{
   cout << "\n\nPara continuar, presiona <Enter>.";
   cin.get();
   return 0;
}
int Mostrar(pista p)
{
	
   cout << "\n\nDatos de la pista\n";
   cout << "Nombre:     " << p.nombre << endl;
   cout << "Interprete: " << p.interprete << endl;
   cout << "Año:        " << p.anio << endl;
   cout << "Duracion:   " << p.duracion << endl;
   return 0;
}
int Mostrarn(pista p, int &n)
{
	
   cout << "\n\nDatos de la pista numero " << n <<"\n";
   cout << "Nombre:     " << p.nombre << endl;
   cout << "Interprete: " << p.interprete << endl;
   cout << "Año:        " << p.anio << endl;
   cout << "Duracion:   " << p.duracion << endl;
   return 0;
}

pista Capturar(void)
{
   pista p;

   cout << "\n\n\nCapturando datos de una pista.\n";
   cout << "Nombre:      ";
   getline(cin,p.nombre);
   cout << "Interprete:  ";
   getline(cin,p.interprete);
   cout << "Año:         ";
   cin >> p.anio; cin.ignore();
   cout << "Duracion:    ";
   cin >> p.duracion; cin.ignore();

   return p;
}

int Capturar(pista &p)
{
	
   cout << "\n\n\nCapturando datos de una pista.\n";
   cout << "Nombre:      ";
   getline(cin,p.nombre);
   cout << "Interprete:  ";
   getline(cin,p.interprete);
   cout << "Año:         ";
   cin >> p.anio; cin.ignore();
   cout << "Duracion:    ";
   cin >> p.duracion; cin.ignore();
   return 0;
}
void archtxt(pista p)
{
	ofstream archivo;
	
	archivo.open("registros.txt",ios::out);
	if(archivo.fail())
	{
		cout<<"nosepuede";
		exit(1);
	}
	archivo << "\n\nDatos de la pista\n";
   archivo << "Nombre:     " << p.nombre << endl;
   archivo << "Interprete: " << p.interprete << endl;
   archivo << "Año:        " << p.anio << endl;
   archivo << "Duracion:   " << p.duracion << endl;
	archivo.close();
}
void leer()
{
	ifstream archivo;
	string texto;
	
	archivo.open("Registro.csv",ios::in);
	
	if(archivo.fail())
	{
		cout<<"nosepuede";
		exit(1);
	}
	while(!archivo.eof())
	{
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
}
