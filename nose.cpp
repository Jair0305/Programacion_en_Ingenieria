/* Maestro buen d�a, intent� ahcer el c�digo muchas veces,
escrib� y borr� muchas cosas, al final no pude lograrlo
pero me interesa saber como hacerlo, por el momento
tampoco pude completarlo por que tengo ex�menes para estos
d�as. El problema espec�ficamente fue que no supe como sumar
los datos del excel. De lo que hice esto fue todo lo que 
qued�.

Jair Ch�vez Islas, programacion en ingenieria*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
float op(float token);
void lectura();
int main()
{
cout<<"DH,DM,   fecha\n";
	lectura();
	float *suma;
	op(*suma);
	
	return 0;
}

void lectura()
{
	ifstream archivo;
	archivo.open("Nacional_Defunciones_Covid19_20210405-20210419.csv",ios::in);
	if(archivo.fail()){
		cout << "no se encontro el archivo";
		exit(1);
	}
	
	string num;
	char str[256];
	int dia = 5;
	while(!archivo.eof()){
		getline(archivo,num);
		cout<<num<< "  " <<dia << "/04/2021"<<endl;
		dia++;
		strcpy(str,num.c_str());
	//	char str[] = "Geeks-for-Geeks";
 
    // Returns first token
    char *token = strtok(str, ",");
   
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        //printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    
	}
	archivo.close();
}
float op(float token)
{
		
//	float num = std::stof(token);
	float suma;
	suma += token;
	cout << suma ;
}
