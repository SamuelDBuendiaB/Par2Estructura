#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

struct nodo
{
    int numero;
    nodo * izquierda;
    nodo * derecha;
    nodo * padre;
};

nodo *arbol = NULL ;
void menu();

int main(){

    menu();
    getch();
    return 0;
}


nodo *crear(int n, nodo * padre){
    nodo *nuevo = new nodo();

    nuevo->numero = n;
    nuevo->derecha = NULL;
    nuevo->izquierda = NULL;
    nuevo->padre = padre;

    return nuevo;
}

void insertar(nodo *&arbol,int n, nodo * padre){
    if (arbol == NULL)
    {
        nodo * nuevo2 = crear(n,padre);
        arbol = nuevo2;
    }
    else
    {
        int raiz = arbol->numero;
        if (n > raiz)
        {
            insertar(arbol->derecha,n,arbol);
        }
        else{
            insertar(arbol->izquierda,n,arbol);
        }
        
    }

}

void hoja(nodo *arbol,int c, int&mayor, int&profundo){
    if(arbol==NULL){
        return;
    }else {
        if(c>mayor){
            mayor =c;
            profundo = arbol->numero;
        }
        hoja(arbol->derecha, c+1,mayor,profundo);
        hoja(arbol->izquierda, c+1,mayor,profundo);
    }
}
void show(nodo *arbol,int c){

    if (arbol == NULL){
        return;
    }
    else
    {
        show(arbol->derecha,c+1);
        for (int i = 0; i < c; i++)
        {
            cout<<"-->";
        }
        cout<<arbol->numero<<endl;
        show(arbol->izquierda,c+1);
        
  
    }
 
}


void menu(){
int opcion, numero,cont=0,cam;
    do
    {
        cout<<"\n"<<endl;
        cout<<"1. Ingresar datos al arbol"<<endl;
        cout<<"2. Mostrar arbol"<<endl;
        cout<<"2. numero mas alejado"<<endl;

        cout<<"Numero:  ";
        cout<<"\n"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1: cout<<"Numero a insertar"<<endl;
        cin>>numero;
        insertar(arbol,numero,NULL);
            break;
        
        case 2:
        cout<<"\nArbol:\n";
        show(arbol,cont);
        cout<<"\n";
            break;
        case 3:
        int mayor = 0;
    int profundo = 0;
    
    hoja(arbol,0,mayor,profundo);
    cout<<"El numero mas alejado es: "<<profundo<<endl;
}
    } while (opcion<9);

}
