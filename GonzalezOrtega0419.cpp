/*
Jennifer Gonzalez Ortega
Programacion en Ingenieria
Tarea practica: "Datos estadisticos".
19 de Abril de 2021
*/

#include <iostream>
#include <clocale>
#include <cmath>
#include <math.h>

using namespace std;

int menu(int& opc);
int repetir(int& rep);
int repi(int& rep);
int capturadenumerodedatos(int& numdatos);
int capturadatos(float p[], int numdatos);
int imprimirdatos(float p[], int numdatos);
int mediaaritmetica(float p[], int numdatos);
int lavarianza(float p[], int numdatos);
int momentodeasimetria(float p[], int numdatos);
int momentodecurtosis(float p[], int numdatos);

int main(void)
{
    setlocale(LC_CTYPE, "Spanish");
    int opc, rep, numdatos;
    opc=0; rep=1;
    do{
       menu(opc);
       if(opc==1){
            system("cls");
            cout << "\n Opción 1. La media aritmética o promedio. ";
            capturadenumerodedatos(numdatos);
            float x[numdatos]={};
            float *p =x;
            capturadatos(p,numdatos);
            imprimirdatos(p,numdatos);
            mediaaritmetica(p,numdatos);
            repetir(rep);
       }else if(opc==2){
            system("cls");
            cout << "\n Opción 2. La varianza. ";
            capturadenumerodedatos(numdatos);
            float x[numdatos]={};
            float *p =x;
            capturadatos(p,numdatos);
            imprimirdatos(p,numdatos);
            lavarianza(p,numdatos);
            repetir(rep);
       }else if(opc==3){
            system("cls");
            cout << "\n Opción 3. Momento de asimetría. ";
            capturadenumerodedatos(numdatos);
            float x[numdatos]={};
            float *p =x;
            capturadatos(p,numdatos);
            imprimirdatos(p,numdatos);
            momentodeasimetria(p,numdatos);
            repetir(rep);
       }else if(opc==4){
            system("cls");
            cout << "\n Opción 4. Momento de curtosis. ";
            //delete[] p;
            repetir(rep);
       }else if(opc==5){
            system("cls");
            cout << "\n Opción 5. Todas las anteriores. ";
            capturadenumerodedatos(numdatos);
            float x[numdatos]={};
            float *p =x;
            capturadatos(p,numdatos);
            imprimirdatos(p,numdatos);
            mediaaritmetica(p,numdatos);
            lavarianza(p,numdatos);
            momentodeasimetria(p,numdatos);
            repetir(rep);
       }else if(opc==6){
            system("cls");
            cout << "\n Opción 6. Salir.";
            repi(rep);
       }
    }while(rep);

    return 0;
}

//FUNCION QUE MUESTRA EL MENU.
int menu(int& opc){
    do{
        system("cls");
        cout <<"\n MENÚ:";
        cout <<"\n 1. La media aritmética o promedio.";
        cout <<"\n 2. La varianza.";
        cout <<"\n 3. Momento de asimetría.";
        cout <<"\n 4. Momento de curtosis.";
        cout <<"\n 5. Todas las anteriores.";
        cout <<"\n 6. Salir.";
        cout <<"\n Introduce la opcion que deseas: ";
        cin >>opc; cin.ignore();
    }while(opc<1 ||opc>6);
    return 0;
}

//FUNCION PARA REPETIR.
int repetir(int& rep){
    do{
        cout << "\n 0. Salir   1.Volver al Menú";
        cout <<"\n Introduce lo que quieres hacer a continuación: ";
        cin >>rep; cin.ignore();
    }while(rep<0 || rep>1);
    return 0;
}

//FUNCION PARA CONFIRMAR LA SALIDA.
int repi(int& rep){
    do{
        cout << "\n 0. Salir   1.Menú";
        cout <<"\n Confirma tu salida: ";
        cin >>rep; cin.ignore();
    }while(rep<0 || rep>1);
    return 0;
}

//FUNCION PARA CAPTURAR DATOS.
int capturadenumerodedatos(int& numdatos){
    do{
        cout <<"\n Indica el número de datos que deseas ingresar (al menos 1, maximo 1000): ";
        cin >>numdatos; cin.ignore();
    }while(numdatos<1||numdatos>1000);
    return 0;
}

//CAPTURA DE DATOS EN EL ARREGLO.
int capturadatos(float p[], int numdatos){
    cout <<"\n Captura de " <<numdatos <<" datos: \n";
    for(int k=0; k<numdatos; k++){
        cout << " Dato " << k+1 << ": ";
        cin >> p[k]; cin.ignore();
    }
    return 0;
}

//IMPRIME LOS DATOS.
int imprimirdatos(float p[], int numdatos){
    cout << "\n Los datos son: \n";
    for(int k=0; k<numdatos; k++){
        cout << " " << p[k];
    }
    cout <<"\n";
    return 0;
}

//FUNCION DE LA MEDIA ARITMETICA O PROMEDIO.
int mediaaritmetica(float p[], int numdatos){
    float promedio=0.0;
    for(int k=0; k<numdatos; k++){
        promedio=promedio+p[k];
    }
    promedio=promedio/numdatos;
    cout <<"\n El promedio de los datos es: " <<promedio <<".";
    cout <<"\n";
    return 0;
}

//FUNCION DE LA VARIANZA.
int lavarianza(float p[], int numdatos){
    // PROMEDIO
    double promedio=0.0;
    for(int k=0; k<numdatos; k++){
        promedio=promedio+p[k];
    }
    promedio=promedio/numdatos;

    //VARIANZA
    float suma=0.0;
    for(int k=0; k<numdatos; k++){
        suma=suma+(pow((p[k]-promedio),2));
    }
    long double varianza=0.0;
    varianza=suma/numdatos;
    cout <<"\n La varianza de los datos es: " <<varianza <<".";
    cout <<"\n";
    return 0;
}

//FUNCION DE MOMENTO DE ASIMETRIA.
int momentodeasimetria(float p[], int numdatos){
    //PROMEDIO
    float promedio=0.0;
    for(int k=0; k<numdatos; k++){
        promedio=promedio+p[k];
    }
    promedio=promedio/numdatos;

    //DESVIACION ESTANDAR
    float suma=0.0;
    for(int k=0; k<numdatos; k++){
        suma=suma+(pow((p[k]-promedio),2));
    }
    float division=0.0;
    division=suma/(numdatos);
    float desviacion=0.0;
    desviacion=sqrt(division);

    //ASIMETRIA
    float suma2=0.0;
    for(int k=0; k<numdatos; k++){
        suma2+=(pow((p[k]-promedio),3));
        cout <<"\n DATO: " << p[k] << " PROMEDIO: " <<promedio;
        cout << "\n SUMA: " << suma2 << "\n";
    }
    float frac1=0.0;
    float abajo=0.0;
    abajo=(numdatos-1)*(numdatos-2);
    frac1=(numdatos)/(abajo);
    float frac2=0.0;
    float desviacionexpo=0.0;
    desviacionexpo=pow(desviacion,3);
    frac2=suma2/desviacionexpo;
    float asimetria=0.0;
    asimetria=frac1*frac2;
    return 0;
}

//FUNCION DE MOMENTO DE CURTOSIS.
int momentodecurtosis(float p[], int numdatos){
    return 0;
}
