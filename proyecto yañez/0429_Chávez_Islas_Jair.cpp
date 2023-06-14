#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int syArregloMostrar(float v[], int N);
int ArregloSuma ( float p[], int nD, float&suma);
int ArregloMaximo ( float p[], int nD, float &maxVal, int &maxIdx);
int ArregloMinimo ( float p[], int nD, float &minVal, int &minIdx);
int minimoMaximoCombinados(float p[], float q[], int nD, float &minVal, int &minIdx, float &maxVal, int &maxIdx);
int pendienteM(int &n, float &dm);
int pendienteH(int &n, float &dm);
int ordenadaH(int &n, float &dm);
int ordenadaM(int &n, float &dm);

int main ()
{
	int m = 0;
    char cad[80];
    char filename[80] = "Nacional_Defunciones_Covid19_20210405-20210419.csv";
    FILE *archivo = fopen(filename, "rt");
    if(archivo == NULL)
    {
        cout << "No se pudo realizar la lectura" << endl;
        return -1;
    }
    //Verificamos cuantos renglones tenemos
    int nRenglones = 0;
    while (fgets(cad,80,archivo) != NULL && cad[0] != '\n')
    {
        nRenglones ++;
        
    }
	
	//Volvemos al inicio del archivo
	rewind(archivo);
	
	//Reservamos memoria para los arreglos
	float *x = new float [nRenglones]; //Defunciones hombres
	float *y = new float [nRenglones]; //Defunciones mujeres
	
	//Releemos los renglones
	for(int k = 0; k <nRenglones; k++)
	{
		
		fgets(cad,80,archivo);
		sscanf(cad,"%f%*c%f%\n", &x[k], &y[k]); //El *c es para descartar caracteres
	}
	
    cout << "Se leyeron " << nRenglones << " renglones" << endl;
    
    cout << "\n\nDefunciones por Covid:\n";
    cout << "Abril\tHombres\tMujeres\n";
    
    for(int k = 0; k < nRenglones; k++)
    {
    	printf("%2d \t%5.0f %5.0f\n", k+5, x[k],y[k]);
	}
	
	float totalH, totalM;
	
	ArregloSuma(x,nRenglones, totalH);
	ArregloSuma(y,nRenglones, totalM);
	cout << "\n\nDefunciones durante los " << nRenglones << " dias: \nHombres: " << totalH << ", Mujeres: " << totalM << endl;
	
	float maxH, maxM, minH, minM;
	int maxIdxH, maxIdxM, minIdxH, minIdxM;
	ArregloMaximo(x, nRenglones, maxH, maxIdxM);
	ArregloMaximo(y, nRenglones, maxM, maxIdxH);
	
	cout << "\nEl maximo de defunciones de hombres fue de: " << maxH << "el dia: " << maxIdxM + 5<< " abril" << endl;
	cout << " y para mujeres fue de " << maxM << " el dia: " << maxIdxH + 5 << " de abril" << endl;
	
	
	ArregloMinimo(x, nRenglones, minH, minIdxH);
	ArregloMinimo(y, nRenglones, minM, minIdxM);
	
	cout << "\nEl minimo de defunciones de hombres fue de " << minH << " el dia: " << minIdxH+5 << " de abril" << endl;
	cout << " y para mujeres fue de " << minM << " el dia: " << minIdxM + 5 << " de abril" << endl;
	
	
	float minComb, maxComb;
	int minIdx, maxIdx;
	float maxVal; 
	minimoMaximoCombinados(x,y, nRenglones,minComb,minIdx,maxComb,maxIdx);
	cout << "\n\nEl maximo de defunciones combinado fue de: " << maxComb << " y de minimo combinado es de: " << minComb << endl;
	
//	float totalH, totalM;
//	ArregloSuma(x,nRenglones, totalH);
//	ArregloSuma(y, nRenglones, totalM);
//	cout << "\n\nDefunciones durante los " << nRenglones << " dias\nHombres" << totalH << ", Mujeres" << totalM << endl;	
			
	pendienteH(nRenglones, totalH);
	pendienteM(nRenglones, totalM);
	
	ordenadaH(nRenglones, totalH);
	ordenadaM(nRenglones, totalM);
    fclose(archivo);
    delete [] x;
    delete [] y;
}



int ArregloSuma ( float p[], int nD, float&suma)
{
	suma = 0.0;
	for(int k = 0; k<nD; k++)
	{
		suma += p[k];
		
	}
	return 0;
}
//suma, maximo, 

int ArregloMaximo ( float p[], int nD, float &maxVal, int &maxIdx)
{
	maxVal = p[0];
	maxIdx = 0;
	for(int k = 0; k <nD; k++)
	{
		if(p[k] > maxVal)
		{
			maxVal = p[k];
			maxIdx = k;
		}
	}
	return 0;
}

int ArregloMinimo ( float p[], int nD, float &minVal, int &minIdx)
{
	minVal = p[0];
	minIdx = 0;
	for(int k = 0; k <nD; k++)
	{
		if(p[k] < minVal)
		{
			minVal = p[k];
			minIdx = k;
		}
	}
	return 0;
}

int minimoMaximoCombinados(float p[], float q[], int nD, float &minVal, int &minIdx, float &maxVal, int &maxIdx)
{
	minVal = maxVal = p[0] +q[0];
	minIdx = maxIdx = 0;
	
	for(int k = 1; k <nD; k++)
	{
		if(p[k] + q[k] < minVal)
		{
			minVal = p[k] + q[k];
			minIdx = k;
		}
		else if (p[k] + q[k] > maxVal)
		{
			maxVal = p[k] + q[k];
			maxIdx = k;
		}
	}
	return 0;
}
int pendienteH(int &n, float &dm)
{   
    float x = 0;
    int n1=0;
    int n2=0;
    int n3 = 0;
    int n4 = 0;
    int n5 = 0;
    int n6 = 0;
    int n7 = 0;
    int n8 = 0;
    int n9 = 0;
    int n10 = 0;
    float res = 0;
    for(int k =0;k<n+1;k++)
    {
    	n1 += k;
    	x = n;
	
	   n2 = (n1 *x);
    }  
	cout<<"\n\nel valor de 1 es: "<<n2;
	
	for(int k =0;k<n+1;k++)
    {
    	n3 = (dm*k);
    	n4 += n1;
	}
	cout<<"\n\nel valor de 2 es: "<<n4;
	
	for(int k =0;k<n+1;k++)
    {
    	x = k;
    	k +=k;
    	n6 = (dm*k)*(x*k);
    	
	}
	cout<<"\n\nel valor de 3 es: "<<n6;
	

	n8 = pow(n2,2);
	cout<<"\n\nel valor de 4 es: "<<n8;
	
	for(int k =0;k<n+1;k++)
    {
    	x = k;
    	n9 = (pow(x,2))*k;
    	n10 += n9;
	}
	cout<<"\n\nel valor de 5 es: "<<n10;
	
	res = ((n2)*(n4)-(n*n6))/((n8)-(n*n10));
	cout<<"\n\n La pendiente de hombres es de: "<<res;
	
	return 0;
}

int pendienteM(int &n, float &dm)
{   
    float x = 0;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;
    int n5 = 0;
    int n6 = 0;
    int n7 = 0;
    int n8 = 0;
    int n9 = 0;
    int n10 = 0;
    float res = 0;
    for(int k =0;k<n+1;k++)
    {
    	n1 += k;
    	x = n;
	
	   n2 = n1 *x;
    }  
	cout<<"\n\nel valor de 1 es: "<<n2;
	
	for(int k =0;k<n+1;k++)
    {
    	n3 = (dm*k);
    	n4 += n1;
	}
	cout<<"\n\nel valor de 2 es: "<<n4;
	
	for(int k =0;k<n+1;k++)
    {
    	x = k;
    	k +=k;
    	n6 = (dm*k)*(x*k);
    	
	}
	cout<<"\n\nel valor de 3 es: "<<n6;
	

	n8 = pow(n2,2);
	cout<<"\n\nel valor de 4 es: "<<n8;
	
	for(int k =0;k<n+1;k++)
    {
    	x = n;
    	k += k;
    	n9 = (pow(x,2));
    	n9 = n9 * k;
	}
	cout<<"\n\nel valor de 5 es: "<<n10;
	
	res = ((n2)*(n4)-(n*n6))/((n8)-(n*n10));
	cout<<"\n\n La pendiente en mujeres es de:"<<res;
	
	return 0;
}
int ordenadaH(int &n, float &dm)
{
	float x = 0;
    int n1=0;
    int n2=0;
    int n3 = 0;
    int n4 = 0;
    int n5 = 0;
    int n6 = 0;
    int n7 = 0;
    int n8 = 0;
    int n9 = 0;
    int n10 = 0;
    int n11 = 0;
    int n12 = 0;
    float res = 0;
    
    for(int k =0;k<n+1;k++)
    {
    	n1 += k;
    	x = n;
	
	   n2 = n1 *x;
    }  
	cout<<"\n\nel valor de 1 es: "<<n2;
	
	for(int k =0;k<n+1;k++)
    {
    	x = k;
    	k +=k;
    	n6 = (dm*k)*(x*k);
    	
	}
	cout<<"\n\nel valor de 3 es: "<<n6;
	for(int k =0;k<n+1;k++)
    {
    	x = k;
    	n9 = (pow(x,2))*k;
    	n10 += n9;
	}
	cout<<"\n\nel valor de 3 es: "<<n10;
	for(int k =0;k<n+1;k++)
    {
    	n3 = (dm*k);
    	n4 += n1;
	}
	cout<<"\n\nel valor de 4 es: "<<n4;
	
	n8 = pow(n2,2);
	cout<<"\n\nel valor de 5 es: "<<n8;
	
	for(int k =0;k<n+1;k++)
    {
    	x = k;
    	n11 = (pow(x,2))*k;
    	n12 += n11;
	}
	cout<<"\n\nel valor de 6 es: "<<n12;
	
	res = (((n2)*(n6))-(n*(n10)*(n4)))/((n8)-(n*n12));
	cout<< "\n\n La ordenada de Hombres es de:"<<res;
	
}
int ordenadaM(int &n, float &dm)
{
	float x = 0;
    int n1=0;
    int n2=0;
    int n3 = 0;
    int n4 = 0;
    int n5 = 0;
    int n6 = 0;
    int n7 = 0;
    int n8 = 0;
    int n9 = 0;
    int n10 = 0;
    int n11 = 0;
    int n12 = 0;
    float res = 0;
    
    for(int k =0;k<n+1;k++)
    {
    	n1 += k;
    	x = n;
	
	   n2 = n1 *x;
    }  
	cout<<"\n\nel valor de 1 es: "<<n2;
	
	for(int k =0;k<n+1;k++)
    {
    	x = k;
    	k +=k;
    	n6 = (dm*k)*(x*k);
    	
	}
	cout<<"\n\nel valor de 3 es: "<<n6;
	for(int k =0;k<n+1;k++)
    {
    	x = k;
    	n9 = (pow(x,2))*k;
    	n10 += n9;
	}
	cout<<"\n\nel valor de 3 es: "<<n10;
	for(int k =0;k<n+1;k++)
    {
    	n3 = (dm*k);
    	n4 += n1;
	}
	cout<<"\n\nel valor de 4 es: "<<n4;
	
	n8 = pow(n2,2);
	cout<<"\n\nel valor de 5 es: "<<n8;
	
	for(int k =0;k<n+1;k++)
    {
    	x = k;
    	n11 = (pow(x,2))*k;
    	n12 += n11;
	}
	cout<<"\n\nel valor de 6 es: "<<n12;
	
	res = (((n2)*(n6))-(n*(n10)*(n4)))/((n8)-(n*n12));
	cout<< "\n\nLa ordenada de muejres es de: "<<res;
	
}

