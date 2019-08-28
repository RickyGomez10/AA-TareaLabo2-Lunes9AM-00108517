#include <iostream>



using namespace std;
struct Nodo{
    int dato;
    Nodo *Siguiente;
};

Nodo *lista = NULL;
Nodo *lista2 = NULL;


void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    Nodo *aux1 = lista;
    Nodo *aux2;
    while((aux1 != NULL)&&(aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->Siguiente;
    }
    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->Siguiente = nuevo_nodo;
    }
    nuevo_nodo->Siguiente = aux1;
}

void mostrarLista(Nodo *&lista){
    Nodo *actual = new Nodo();
    actual = lista;
    if(actual == NULL){
        cout<<"La lista esta vacia"<<endl;
    }
    while(actual !=NULL){
        cout<<actual->dato<<"->";
        actual = actual->Siguiente;

    }
}
void mostrarPromedio(Nodo *&lista, Nodo *&lista2){
    Nodo *actual = new Nodo();
    Nodo *actual2 = new Nodo();
    actual = lista;
    actual2 = lista;
    int promedio = 0;
    int suma=0;
    int n=0;
    //Se recorre la lista 1, y se obtienen los datos para obtener el promedio
    while(actual !=NULL){
        n++;
        suma+=actual->dato;
        actual = actual->Siguiente;

    }
    //Se obtiene el promedio
    promedio = suma/n;
    cout<<"promedio: "<<promedio<<endl;
    //Se recorre de nuevo la lista y se verifica si los datos son mayores al promedio, en caso de cumplir la condicion se insertan en la lista 2
    while(actual2 !=NULL) {
        if(actual2->dato >promedio){
            insertarLista(lista2,actual2->dato);
        }

        actual2 = actual2->Siguiente;
    }

}

int main() {
    //Insertar elementos a la lista
    insertarLista(lista,11);
    insertarLista(lista,22);
    insertarLista(lista,33);
    cout<<"lista 1:"<<endl;
    //Mostrar la lista 1
    mostrarLista(lista);
    cout<<endl;
    //Funcion que muestra el promedio y de inmediato inserta en la segunda lista
    mostrarPromedio(lista,lista2);
    cout<<"lista 2 con los datos mayores al promedio de la lista 1:"<<endl;
    //Mostrar lista 2
    mostrarLista(lista2);
}