#include<iostream>
#include<conio.h>
using namespace std;

struct lista
{
    int numero;
    lista *next;
};

lista *orden = NULL ;
void eleccion();
void agregaralista(lista*&,int);
void show(lista*);

int main(){

eleccion();
getch();
return 0;
}


void agregaralista(lista *&orden,int i){
    lista * nuevo_nodo = new lista();

    nuevo_nodo->numero = i;

    lista * nodo1 = orden;
    lista * nodo2;

while((nodo1 !=NULL )&&(nodo1->numero < i)){
    nodo2 = nodo1;
    nodo1 = nodo1->next;    
}

if(orden == nodo1 ){

orden = nuevo_nodo;

}
else {
    nodo2->next = nuevo_nodo;
}
nuevo_nodo->next = nodo1;

cout<<"\ndato ingresado\n";
}

void show(lista *orden){

    lista * mostrar = new lista();
    mostrar = orden;

    while(mostrar != NULL){
        cout<<mostrar->numero<<" -- ";
        mostrar = mostrar->next;
    }

}

void busqueda(lista *orden,int num){
    bool p= false;
    int i = 0;
   lista * bus = new lista();
    bus=orden;


    while((bus !=NULL)&&(bus->numero <=num)){

        if (bus->numero == num)
        {
            p=true;
        }
         i++;
         bus=bus->next;
    }

    if (p==true)
    {
        cout<<"el numero  "<<num<<"  Se encuentra en la lista en la posicion "<<i<<endl;
    }
    else{
        cout<<"el numero   "<<num<<"   No se ha encontrado\n"<<endl;
    }


}

void quick(lista *cabeza){
    if(cabeza == NULL || cabeza->next == NULL){
        return;
    }
    lista * pivote = cabeza;
    lista * menor = NULL;
    lista * mayor = NULL;
    lista * mid = NULL;
    
    
    while(cabeza != NULL){
        if(cabeza->numero < pivote->numero){
            agregaralista(menor,cabeza->numero);
        }else if(cabeza->numero == pivote->numero){
            agregaralista(mid, cabeza->numero);
        }else{
            agregaralista(mayor, cabeza->numero);
        }
        lista *temp = cabeza;
        cabeza = cabeza->next;
        delete temp;
    }
    
    quick(menor);
    quick(mayor);
    
    cabeza = menor;
    while(menor != NULL && menor->next != NULL){
        menor= menor->next;
    }
    if(mid != NULL){
        if(cabeza = NULL){
            cabeza = mid;
        }else{
            menor->next=mid;
        }
    }
    if(mayor !=NULL){
        if(cabeza == NULL){
            cabeza = mayor;
        }else{
            menor->next = mayor;
        }
    }
}




void eleccion(){
    int opcion,numero;

    do
    {
        cout<<"\n 1. Agregar numeros:  "<<endl;
        cout<<"2. Agregar ver lista "<<endl;
        cout<<"3. Buscar numero "<<endl;
        cout<<"4. QuickSort "<<endl;
        cout<<"5. salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1 : cout<<"Numero a digitar:   ";
        cin>>numero;
        agregaralista(orden,numero);
            break;


        case 2 : show(orden);
        cout<<"   "<<endl;
            break;

        case 3 :cout<<"\nDigitar numro a buscar ";
        cin>>numero;
         busqueda(orden,numero);
         break;
         
         case 4 : 
         quick(orden);
         cout<<"Lista ordenada con quicksort"<<endl;
         show(orden);
         break;
         
        }

    } while (opcion !=5);
    
}
