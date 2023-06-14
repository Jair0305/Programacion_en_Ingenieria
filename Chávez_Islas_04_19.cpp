//Hecho por Jair Chávez Islas 

#include <iostream>
#include <math.h>
using namespace std;

//prototipos

int syCapturaNumDatos(int &nD);
int syArregloCaptura(float x[], int nD);
float *NuevoArreglo(int n);
int syArregloPromedio(float x[], int nD, float &prom);
void Varianza(float x[], float prom, int nD, float &var);
int moda(float *dato, int &nD);
int asimetria(int &nD, float &prom, float x[], float &var );
int curtosis(int &nD, float &prom, float x[], float &var);
int main()
{

float var = 0;
float var2 = 0;
int nD;
float x[nD];
float *p;
float dato[nD];


float prom ;

p= NuevoArreglo(nD);

syCapturaNumDatos(nD);

syArregloCaptura(p,nD);

syArregloPromedio(p, nD, prom);

Varianza(p, prom, nD, var);

asimetria(nD, prom, x, var );
//moda(dato, nD);

curtosis(nD,prom, x, var);

cout <<"Press <enter>";
	cin.get();
return 0;	
}

int syCapturaNumDatos(int &nD){
	
	do
  {
      cout << "\n Ingresa el numero de datos (al menos 1): ?";
      cin >> nD;
  } while (nD < 1);
  
  return 0;
}
int syArregloCaptura(float x[], int nD){
 cout<<"Captura de los " << nD << "datos:\n";
    for (int k = 0; k < nD; k++)
    {
    	int suma;
        cout <<"Dato" << k+1 <<": ?";
        cin >> x[k];
        if(x[k] == x[k])
        {
        	suma = suma +1;
		}
    }
    cout << "\n\n";
    
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
int syArregloPromedio(float x[], int nD, float &prom)
{
    for(int k = 0; k<nD; k++)
	{	
    prom += x[k];
    }
    prom /= nD;
    
    cout <<"\n\nEl promedio es: " << prom << ".\n\n";
    
    return 0;
}
void Varianza(float x[], float prom, int nD, float &var)
{
	for(int i=0;i < nD; i++)
	{
		var += pow(x[i]  - prom,2);
	}
	var /= nD;
	
	cout <<"\n\nLa varianza es:"<< var <<".\n\n";
}
void asimetria(float x[], float prom, int nD, float var)
{
	
}
int moda(float *dato, int &nD)
	{
		int elemento;
		int contador;
		
		for(size_t i=0; i< nD; i++)
		{
		   int tempelement = dato[i];
		   int tempcount = 0;
		   
		    for(size_t ib = 0; ib <nD; ib++)
		    {
		   	if (dato[ib] == tempelement)
		   	   {
		   	   	tempcount ++;
			   }
		    }
			if(tempcount > contador)
			{
			   elemento = tempelement;
			   contador = tempcount;	
			}	
		}
		cout <<"La moda es:"<<contador<<".";
		return elemento;
	}
int asimetria(int &nD, float &prom, float x[], float &var )
{
	//Formula N/(N-1)(N-2) * (X1 - promedio)^3 + (Xn - promedio)^3/ desviacion estandar^3
	
	float resultado;
	float suma;
	float de;
	float desi;
	float si2;
	float nose;
	
	for(int i=0;i < nD; i++)
	{
		suma += x[i]  - prom;
	}
	nose = pow(suma,3);
	de = sqrt(var);
	desi = pow(de,3);
	suma = suma/desi;
	si2 = (nD-1)*(nD-2);
	resultado = (nD/si2)* (suma);
	
	cout<<"\n\nLa asimetria es de: "<< resultado << ".\n\n";
	//cout<<"\n\nLa desvaicion estandar es de: "<< de << ".\n\n";
}

int curtosis(int &nD, float &prom, float x[], float &var)
{
//Formula (((N (N+1))/(N-1)(N-2)(N-3))*((X1 - promedio)^4 + (Xn- promedio)^4)/desviacion estandar^4) - ((3(N-1)^2)/(N-2)(N-3))

    float de;
    float parte4;
    float r1;
    float r2;
    float r3;
    float r4;
    float parte12;
    float nose;
    float parte34;
    float parte56;
    float parte5;
    float parte6;
    float suma;
    float parte52;
	for(int i=0;i < nD; i++)
	{
		
		suma += pow(x[i]  - prom,4);
	}
	
    de = sqrt(var);
    parte4 = pow(de,4);
    parte34 = (nose/parte4);
    parte12 = ((nD*(nD+1))/((nD-1)*(nD-2)*(nD-3)));
    parte5 = 3*(nD-1);
    parte52 = pow(parte5,2);
    parte6 = ((nD-2)*(nD-3));
    r1 = parte12 * parte34;
    r2 = r1 - parte56;
    
    cout<<"\n\nLa curtosis es de:"<< r2 <<".\n\n";
    
}
