#include <iostream>
#include <string>
using namespace std;

// Definicion de nodo ------------------------
struct capa{
    string tiposuelo;
    float grosor;
    int dureza;
};
typedef struct capa Capa;

struct nodo{
    capa elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;



// Prototipos de funciones ------------------------
void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, Capa e);
Capa pop(Pila *s);
int size(Pila *s);
float promedio(Pila *s);

// Programa principal ------------------------
int main(){
    // 1) Creando pila de platos vacia -------------
    Pila pilaSuelos;
    initialize(&pilaSuelos);
    
    int opcion;
    bool continuar=true;
    Capa capaAux;

    do{
        cout << endl << "*****MENU OPCIONES PILA***" << endl;
        cout << "1: Agregar capas" << endl;
        cout << "2: Eliminar ultima capa" << endl;
        cout << "3: Eliminar todas las capas" << endl;
        cout << "4: Calcular promedio de la dureza" << endl;
        cout << "5: Salir" << endl;
        cout <<"Ingrese la opcion: ";
        cin >> opcion; cin.ignore();
        cout <<endl;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese los datos del la capa a agregar:" << endl;
            cout << "Tipo de suelo: ";
            getline(cin,capaAux.tiposuelo);
            do{
                cout <<"Grosor (No puede ser negativo o cero): ";
                cin >> capaAux.grosor;
            }while(capaAux.grosor<=0);
            do{
                cout <<"Dureza (No puede ser negativo o cero): ";
                cin>>capaAux.dureza;
            }while(capaAux.dureza<=0);
            
            push(&pilaSuelos,capaAux);

            break;
        
        case 2:
            if(!empty(&pilaSuelos)){
                pop(&pilaSuelos);
                cout << "Capa eliminada correctamente!" << endl;
            }else{
                cout << "Underflow! No se pudo eliminar la capa" << endl;
            }
            break;
        case 3:
            if(!empty(&pilaSuelos)){
                while(!(pilaSuelos==NULL)){
                    pop(&pilaSuelos);
                }
                cout << "Todas las capas eliminada correctamente!" << endl;
            }else{
                cout << "Underflow! No se pudo eliminar las capas" << endl;
            }
            break;
        case 4:
            if(!empty(&pilaSuelos)){
               cout << "El promedio de la dureza de las capas es: " << promedio(&pilaSuelos) << endl;
            }else{
                cout << "El promedio es cero porque no hay capas en la columna litologica" << endl;
            }
            break;
        case 5:
            cout << "Fin del programa..." << endl;
            continuar=false;
            break;
        default:
            cout << "Opcion no validad!" << endl;
            break;
        }

    }while(continuar);
    

    return 0;
}

// Implementacion de funciones ------------------------
void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, Capa e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

Capa pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        Capa e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else // Underflow!
        return {{" "},{ },{ }};
}

int size(Pila *s){
    int contador=0;
    if(*s==NULL){
        return contador;
    }
    // Struct nodo el nombre va a cambiar segun el nombre del registro
    struct nodo *unNodo = *s;

    while (unNodo != NULL) {
		contador++;
        unNodo = unNodo->siguiente;
    }
    return contador;
}

float promedio(Pila *s){

    float prom, suma=0;

    struct nodo *unNodo = *s;

    while (unNodo != NULL) {
		suma+=unNodo->elemento.dureza;
        unNodo = unNodo->siguiente;
    }
    prom= suma/size(s);

    return prom;
}