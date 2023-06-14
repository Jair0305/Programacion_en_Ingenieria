//repaso de arreglos

#include <iostream>
#include <clocale>

using namespace std;


//prototipos
int syCapturaNumDatos(void);
int syCapturaNumDatos(int &nD);
int syArregloEnPantalla(float x[], int nD);
int syArregloCaptura(float x[], int nD);
int syArregloPromedio(float x[], int nD, float &prom);

int main()
{
    setlocale(LC_CTYPE,"Spanish");
  cout << "Ejemplo de \"arreglos de momento\"." << endl;

  //Mensaje sobre el programa 
  cout << "Manejo de un arreglo de datos de tipo float.\n\n";

  // Se pide el numerod e datos a considerar
  int nD;
  
  // Forma 1:
  //nD = syCapturaNumDatos();
  // Forma 2: Usando una referencia
  syCapturaNumDatos(nD);
  
  //Declaramos un arreglo llamado "x", de nD datos de tipo flotante (inicializo en cero)
  float x[nD] = {};

syArregloEnPantalla(x,nD);


  // Se muestra en pantalla los datos
 
  syArregloCaptura(x,nD);
   
    //se muestran en pantalla
    
   syArregloEnPantalla(x,nD);
    //Calculo el promedio de los datos
    float prom;
syArregloPromedio(x,nD,prom);
cout << "El promedio de los datos es:" << prom << ".\n\n";

    
      /* code */
  
  



  cout <<"\n\nPara salir presiona <Enter>";
  cin.get();
  return 0;
}
syCapturaNumDatos(int &nD){
	
	do
  {
      cout << "\n Indica el número de datos en el arreglo (al menos 1): ?";
      cin >> nD;
  } while (nD < 1);
  
  return 0;
}
syArregloEnPantalla(float x[], int nD)
{
  	 cout<<"\n\n Los datos en el arreglo son:\n";
  for ( int k = 0; k < nD; k++)
      cout << x[k] << " ";
      cout << "\n\n";
      return 0;
}
syArregloCaptura(float x[], int nD){
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
