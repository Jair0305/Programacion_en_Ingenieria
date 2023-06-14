
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;


typedef struct Libro{ 
    char titulo[50];
    char autor[50];
    char isbn[13];
}Libro;

typedef struct Nodo{
    Libro libro;
    struct Nodo *siguiente;
}Nodo;

typedef struct Lista{
    Nodo *cabeza ;
    int longitud;
}Lista;

Nodo *crearNodo(Libro *libro){

    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));

    strncpy_s(nodo->libro.titulo, libro->titulo, 50);
    strncpy_s(nodo->libro.autor, libro->autor, 50);
    strncpy_s(nodo->libro.isbn, libro->isbn, 13);
    nodo->siguiente = NULL;
    return nodo;
}

void destruirNodo(Nodo *nodo){
    free(nodo);
}

void insertarPrincipio(Lista *lista, Libro *libro){
    Nodo *nodo = crearNodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void insertarFinal(Lista *lista, Libro *libro){
    Nodo *nodo = crearNodo(libro);
    if(lista->cabeza == NULL)
        lista->cabeza = nodo;
    else{
        Nodo *puntero = lista->cabeza;

        while(puntero->siguiente)
            puntero = puntero->siguiente;

        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

void insertarDespues(int n, Lista *lista, Libro *libro){
    Nodo *nodo = crearNodo(libro);
    if(lista->cabeza == NULL)
        lista->cabeza = nodo;
    else{
        Nodo *puntero = lista->cabeza;
        int posicion = 0;
        while(posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

Libro *obtener(int n, Lista *lista){
    if(lista->cabeza = NULL)
        return NULL;
    else{
        Nodo *puntero = lista->cabeza;
        int posicion = 0;
        while(posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }
        if(posicion != n)
            return NULL;
        else
            return &puntero->libro;
    }
}

int contar(Lista *lista){
    return lista->longitud;
}

bool estaVacia(Lista *lista){
    return lista->cabeza == NULL;
}

void eliminarPrincipio(Lista *lista){
    if(lista->cabeza){
        Nodo *eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        destruirNodo(eliminado);
        lista->longitud--;
    }
}

void eliminarUltimo(Lista *lista){
    if(lista->cabeza){
        if(lista->cabeza->siguiente){
            Nodo *puntero = lista->cabeza;
            while(puntero->siguiente->siguiente)
                puntero = puntero->siguiente;
            Nodo *eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            destruirNodo(eliminado);
            lista->longitud--;
        }

    } else{
        Nodo *eliminado = lista->cabeza;
        lista->cabeza = NULL;
        destruirNodo(eliminado);
        lista->longitud--;
    }
}

void eliminarElemento(int n, Lista *lista){
    if(lista->cabeza){
        if(n == 0){
            Nodo *eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            destruirNodo(eliminado);
            lista->longitud--;
        } else if(n < lista->longitud){
            Nodo *puntero = lista->cabeza;
            int posicion = 0;
            while(posicion < (n - 1)){
                puntero = puntero->siguiente;
                posicion++;
            }
            Nodo *eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            destruirNodo(eliminado);
            lista->longitud;
        }
    }
}


int main() {
    char op = 'n';
    Lista *lista=new Lista;
    Libro *libro=new Libro;
    do {
        cout << "Ingrese el titulo del libro: " << endl;
        //fgets(libro->titulo, 50, stdin);
        cin >> libro->titulo;
        cout << "Ingrese el autor del libro: " << endl;
        //fgets(libro->autor, 50, stdin);
        cin >> libro->autor;
        cout << "Ingrese el ISBN del libro: " << endl;
        //fgets(libro->isbn,13 , stdin);
        cin >> libro->isbn;

        insertarPrincipio(lista, libro);
        printf("%s\n", libro->titulo);
        printf("%s\n", libro->autor);
        printf("%s\n", libro->isbn);
        cout << "Quiere ingresar otro libro (1 = si, 2 = no): ";
        cin >> op;
    } while (op == 's');
    
   

    return 0;
}
