//repaso de arreglos

#include <iostream>
#include <clocale>

using namespace std;

#define TAM 100

//prototipos
int syCapturaNumDatos(void);
int syCapturaNumDatos(int &nD);
int syArregloEnPantalla(float x[], int nD);
int syArregloCaptura(float x[]/* Mandamos la direccion de memoria del primer dato del arreglo */, int nD);
int syArregloPromedio(float x[], int nD, float &prom);
int SetValuesToCero(float*p, int nD, float val);
float *NuevoArreglo(int n);
int syArregloLiberar(float *p);
//Cuando una funcion regresa un apuntador, hace cosas diferentes a las normales
int main()
{
    setlocale(LC_CTYPE,"Spanish");
  cout << "Ejemplo de \"arreglos de momento\"." << endl;

  //Mensaje sobre el programa 
  cout << "Manejo de un arreglo de datos de tipo float.\n\n";

  // Se pide el numerod e datos a considerar
  int nD;
  
  //Reservamos memoria para un arreglo llamado p, de nDdatos de tipo flotante
  //new es para reservar espacio en memoria 
  //float* p = new float [nD];
  
  float* p;
  p = NuevoArreglo(nD);

  SetValuesToCero(p,nD,0);
  // Forma 1:
  //nD = syCapturaNumDatos();
  // Forma 2: Usando una referencia
  syCapturaNumDatos(nD);
 
  //Equivalente a float *p = &x[0];

syArregloEnPantalla(p,nD);


  // Se muestra en pantalla los datos
 
  syArregloCaptura(p,nD);
   
    //se muestran en pantalla
    
   syArregloEnPantalla(p,nD);
    //Calculo el promedio de los datos
    float prom;
syArregloPromedio(p,nD,prom);
cout << "El promedio de los datos es:" << prom << ".\n\n";
  
//Siempre que asignamos espacio a un apuntador, cuando lo terminamos de usar, liberamos la memoria.

syArregloLiberar(p);
//delete[]p es una instruccion que opera con el apuntador  
  cout <<"\n\nPara salir presiona <Enter>";
  cin.get();
  return 0;
}
int syCapturaNumDatos(int &nD){
	
	do
  {
      cout << "\n Indica el número de datos en el arreglo (al menos 1): ?";
      cin >> nD;
  } while (nD < 1);
  
  return 0;
}
int syArregloEnPantalla(float x[], int nD)
{
  	 cout<<"\n\n Los datos en el arreglo son:\n";
  for ( int k = 0; k < nD; k++)
      cout << x[k] << " ";
      cout << "\n\n";
      return 0;
}
int syArregloCaptura(float x[], int nD){
 cout<<"Captura de los " << nD << "datos:\n";
    for (int k = 0; k < nD; k++)
    {
        cout <<"Dato" << k+1 <<": ?";
        cin >> x[k];
    }
    cout << "\n\n";
    
    return 0;
}
int syArregloPromedio(float x[], int nD, float &prom)
{
    for(int k = 0; k<nD; k++)
	{	
    prom += x[k];
    }
    prom /= nD;
    
    return 0;
}

int SetValuesToCero(float*p, int nD, float val)

{
  for (int k = 0; k < nD; k++)
  {
    p[k] = val;
  }
  return 0;
}


float *NuevoArreglo(int n)//regresa un apuntador de tipo flotante
{
  float *p;

  p = new float[n];
  if(!p){
  	cout << "\n\nError de asignacion en la memoria\n\n";
  	return NULL;
  }
  //Cualquier asignacion de memoria es global
  return p;
}
int syArregloLiberar(float *p)
{
	if(p)
	delete[]p;
	else cout <<"\n\nLiberando memoria no asignada. \n\n";
	return 0;
}
