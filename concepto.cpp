/*Concepto de Arboles: 
 *
 * Un árbol consta de un conjunto finito de elementos, denominados nodos y un conjunto finito de líneas dirigidas, denominadas ramas, que conectan los nodos.
 *
 * Propiedades del Árbol:

 *
 * - Longitud de camino
 *   - Altura de un nodo
 *   - Profundidad de un nodo. Nivel
 *   - Nodos hermanos
 *   - Orden de un árbol*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

//escructura de un arbol binario:

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
};

void menu();

Nodo *crearNodo(int);

void insertarNodo(Nodo *&,int);

Nodo *arbol = NULL;

void mostrarArbol(Nodo *,int);

bool busqueda(Nodo *,int);

void preOrden(Nodo *);

void InOrden(Nodo *);

int main(){
    
    menu();

    return 0;
}

void menu(){
    int dato,opcion,cont=0;

    do{
        cout<<"\t.:MENU:."<<endl;
        cout<<"1. Insertar un nuevo nodo"<<endl;
        cout<<"2. Mostrar arbol completo"<<endl;
        cout<<"3. Buscar un elemento en el arbol"<<endl;
        cout<<"4. Recorrer el arbol completo en pre orden"<<endl;
        cout<<"5. Recorrer el arbol completo de in orden"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1: cout<<"\nDigite un numero: ";
                    cin>>dato;
                    insertarNodo(arbol,dato);
                    cout<<"\n";
                    dato=getchar();
                    break;
            case 2: cout<<"\nMostrando el arbol completo:\n\n";
                    mostrarArbol(arbol,cont);
                    cout<<"\n";
                    dato=getchar();
                    break;
            case 3: cout<<"\nDigite el elemento a buscar: ";
                    cin>>dato;
                    if(busqueda(arbol,dato) == true){
                        cout<<"\nElemento "<<dato<<" a sido encontrado en el arbol\n";
                    }
                    else{
                        cout<<"\n Elemento no encontrado\n";

                    }
                    cout<<"\n";
                    dato=getchar();
                    break;
            case 4: cout<<"\nRecorrido en pre orden: ";
                    preOrden(arbol);
                    cout<<"\n\n";
                    dato=getchar();
                    break;
            case 5: cout<<"\nRecorrido en in orden: ";
                    InOrden(arbol);
                    cout<<"\n\n";
                    dato=getchar();
                    break;
        }
        cout<<"Presione enter para continuar";
        cout<<"\n";
        dato=getchar();
        system("clear");
        

    }while(opcion != 6);
}

Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol,int n){
    if(arbol == NULL){
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else{
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertarNodo(arbol->izq,n);
        }
        else{
        insertarNodo(arbol->der,n);
        }
    }
}

void mostrarArbol(Nodo *arbol,int cont){
    if(arbol == NULL){
        return;
    }
    else{
        mostrarArbol(arbol->der,cont+1);
        for(int i=0;i<cont;i++){
            cout<<"  ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq,cont+1);
    }
}

bool busqueda(Nodo *arbol, int n){
    if(arbol == NULL){
        return false;

    }
    else if(arbol->dato == n){
        return true;

    }
    else if(n < arbol ->dato){
        return busqueda(arbol->izq,n);
    }
    else{
        return busqueda(arbol->der,n);
    }
}
void preOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }
    else{
        cout<<arbol->dato<<" - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);

    }
}

void InOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }
    else{
    InOrden(arbol->izq);
    cout<<arbol->dato<<" - ";
    InOrden(arbol->der);
    }
}



