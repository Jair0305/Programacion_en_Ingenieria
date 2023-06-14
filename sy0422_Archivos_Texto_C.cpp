/*
   syArchivos_Texto_C.cpp

   Ejemplo de guardado de cadenas en un archivo de texto
   usando el "estilo C" (funciones propias del lenguaje C)

R.E. Sánchez Yáñez
*/

#include <iostream>
#include <cstdio>
#include <clocale>

using namespace std;

int main(void)
{
//   setlocale(LC_CTYPE, "Spanish");
   cout << "El programa guarda en disco dos cadenas introducidas por el usuario.\n";

   char cad1[80]; // Recordemos que en este ejemplo se usa "código C"
   char cad2[80];
   char cad3[80]; // Otra cadena, para luego usarla al leer desde disco

   /* Captura de las cadenas */
   cout << "\n\nIntroduce una cadena (caracteres y un <Enter> al final):\n";
   gets(cad1);
   cout << "\n\nAhora una segunda cadena:\n";
   gets(cad2);

   /* Se muestran las cadenas en pantalla */
   cout << "\nEstas son las dos cadenas: \n";
   printf("%s\n", cad1);
   printf("%s\n", cad2);

   // Este apuntador es el común en C (obviamente, también funciona en C++)
   FILE *fp;

   fp = fopen("archivo.txt", "wt"); // w-write, r-read, a-append; t-text, b-binary
//   char *filename = "archivo.txt";
//   fp = fopen(filename, "wt"); // w-write, r-read, a-append, t-text, b-binary
   if (fp == NULL)
   {
      printf("\nNo se pudo abrir el archivo...");
      return -1;
   }

   fprintf(fp,"%s\n", cad1); // Obsérvese la semejanza con printf() líneas arriba
   fprintf(fp,"%s\n", cad2);

/*
   á –> \xA0;
é –> \x82;
í –> \xA1;
ó –> \xA2;
ú –> \xA3;
ñ –> \xA4;
Ñ –> \xA5;
á -> 160;
é -> 130;
í -> 161;
ó -> 162;
ú -> 163;
ñ -> 164;
*/
   fprintf(fp,"Probando algunos caracteres especiales: \xA0 \xA5 ");



   fclose(fp); // AQUÍ YA SE TERMINÓ DE ESCRIBIR







   // Ahora vamos a leer
   fp = fopen("archivo.txt", "rt");
   if (fp == NULL)
   {
      printf("\nNo se pudo abrir el archivo de lectura...");
      return -1;
   }

   cout << "\n\nEstas son las lineas que se leyeron:\n\n";

   while ( fgets(cad3,80,fp) )
      printf("%s",cad3);

   fclose(fp);


   printf("\n\n\nPresiona <Enter> para continuar.");
   getchar();
   return 0;
}


//Si tenemos
//3,9
//¿cómo podemos extraer estos dos valores?
//int a,b;
//a<-3
//b<-9

//Desde un archivo, parece prometedora la funcion fscanf()
//Desde la cadena, atoi(), atof(), isnum(), ...
