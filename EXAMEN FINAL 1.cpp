//Arboles//
#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

void menu();
Nodo *crearNodo(int n);
void insertarNodo(Nodo *&arbol, int n);
void mostrarArbol(Nodo *arbol, int contador);
bool busquedad(Nodo *arbol, int n);
void preOrden(Nodo *arbol);
void inOrden(Nodo *arbol); 
void postOrden(Nodo *arbol);

Nodo *arbol = NULL;

int main(){
	
	menu();
	
	
	getch();
	return 0;
}
void menu(){
	
	int dato,opcion;
	int contador=0;
	bool x = true;
	do{
		x = true;
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar Arbol"<<endl;
		cout<<"3. Buscar nodo de Arbol"<<endl;
		cout<<"4. Recorrido preOrden"<<endl;
		cout<<"5. Recorrido inOrden"<<endl;
		cout<<"6. Recorrido PostOrden"<<endl;
		cout<<"7. Salir"<<endl;
		cout<<"Opcion a elegir: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: 
				cout<<"\nINSERTANDO ARBOL"<<endl;
				cout<<"\nDigite un numero: ";
				cin>>dato;
				insertarNodo(arbol,dato);
				cout<<"\n";
				system("pause"); 
			break;
			case 2: 
				cout<<"\nMOSTRANDO ARBOL"<<endl;
				mostrarArbol(arbol,contador);
				cout<<"\n";
				system("pause");
			break;
			case 3: 
				cout<<"\nBUSCANDO ELEMENTO ARBOL"<<endl;
				cout<<"Digite el elemento a buscar: ";
				cin>>dato; 
				
				if(busquedad(arbol,dato)==true){
					cout<<"Elemento encotrado"<<endl;
				}
				else{
					cout<<"Elemento no encontrado"<<endl;
				}
				cout<<"\n";
				system("pause");
			break;
			case 4:
				cout<<"\nRecorriendo PreOrden"<<endl; 
				preOrden(arbol);	
				cout<<"\n";
				system("pause");
			break;
			case 5:
				cout<<"\nRecorriendo InOrden"<<endl;
				inOrden(arbol);
				cout<<"\n";
				system("pause");
			break;
			case 6:
				cout<<"\nRecorrido PostOrden"<<endl;
				postOrden(arbol);
				cout<<"\n";
				system("pause");
			break;
			case 7:
			break;
		}
		system("cls");
	}while(opcion!=7);
}
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}
void insertarNodo(Nodo *&arbol, int n){
	if(arbol==NULL){
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	
	}
	else{
		int valorRaiz = arbol->dato;
		if(n<valorRaiz){
			insertarNodo(arbol->izq,n);
		}
		else{
			insertarNodo(arbol->der,n);
		}
	}
}
void mostrarArbol(Nodo *arbol, int contador){
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,contador+1);
		for(int i=0;i<contador;i++){
			cout<<"<< >>";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,contador+1);
		
	}
	
}
bool busquedad(Nodo *arbol, int n){
	if(arbol==NULL){
		return false;
	}
	else if(arbol->dato==n){
		return true;
	}
	else if(n<arbol->dato){
		return busquedad(arbol->izq,n);
	}
	else if(n>arbol->dato){
		return busquedad(arbol->der,n); 
	}
}
void preOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		cout<<arbol->dato<<">> <<";
		preOrden(arbol->izq);
		preOrden(arbol->der); 
	}
	
}
void inOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<">> <<";
		inOrden(arbol->der);
	}
	
}
void postOrden(Nodo *arbol){
	if(arbol==NULL){
		return;	
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<">> <<";
	}
			
	
}
