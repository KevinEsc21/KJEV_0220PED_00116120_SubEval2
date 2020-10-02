#include <iostream>
#include <stack>
using namespace std;

struct plato{
    string material;
    string color;
    bool estado=true;
};
typedef struct plato Plato;

int main(){
    stack<Plato>platosLimpios;
    stack<Plato> platosSucios;

    int n;
    Plato platotemporal;
    do{
        cout << "Cuantos platos limpios tiene?: ";
        cin >> n; cin.ignore();
    }while(n<1);

    for (int i = 0; i < n; i++)
    {
        Plato platotemporal;

        cout << endl << "Igrese los datos del plato" << endl;
        cout << "Material: ";
        getline(cin,platotemporal.material);
        cout << "Color: ";
        getline(cin,platotemporal.color);
        cout << "Plato apilado..." << endl;
        platosLimpios.push(platotemporal);
    }
    
    bool continuar = true;
    do{
        int opcion;
        
        cout << endl << "Cantidad de platos limpios actual: " << platosLimpios.size() << endl;
        cout << "Cantidad de platos sucios actual: " << platosSucios.size() << endl;
        cout << "****MENU OPCIONES****" << endl;
        cout << "1: Ensuciar un plato" << endl;
        cout << "2: Ensuciar N platos" << endl;
        cout << "3: Limpiar un plato" << endl;
        cout << "4: Limpiar N platos" << endl;
        cout << "5: Mostrar pila limpia" << endl;
        cout << "6: Mostrar pila sucia" << endl;
        cout << "7: Salir" << endl;
        cout << "Escriba la opcion: ";
        cin >> opcion; cin.ignore();
        cout << endl;
        
        switch(opcion)
        {
            case 1:
                if(!platosLimpios.empty()){
                    platotemporal=platosLimpios.top();
                    platosLimpios.pop();
                    platotemporal.estado=false;
                    platosSucios.push(platotemporal);
                    cout <<"El plato se ha ensuciado..." << endl;
                }else{
                    cout << "Underflow! La pila de platos limpios esta vacia" << endl;
                }
                break;
            case 2:
            if(!platosLimpios.empty()){
                int cant;
                do{
                    cout << "Cuantos platos quiere ensuciar (No pueden ser mas de los que tiene limpios)?: ";
                    cin >> cant;
                }while(cant>platosLimpios.size() || cant<1);
            
                for(int i=0; i<cant; i++){
                    platotemporal=platosLimpios.top();
                    platosLimpios.pop();
                    platotemporal.estado=false;
                    platosSucios.push(platotemporal);
                    cout <<"El plato se ha ensuciado..." << endl;
                }
                }else{
                    cout << "Underflow! La pila de platos limpios esta vacia" << endl;
                }
                break;
            case 3:
                if(!platosSucios.empty()){
                    platotemporal=platosSucios.top();
                    platosSucios.pop();
                    platotemporal.estado=true;
                    platosLimpios.push(platotemporal);
                    cout <<"El plato se ha limpiado..." << endl;
                }else{
                    cout << "Underflow! La pila de platos sucios esta vacia" << endl;
                }
                break;
            case 4:
                if(!platosSucios.empty()){
                int cant;
                do{
                    cout << "Cuantos platos quiere limpiar (No pueden ser mas de los que tiene sucios)?: ";
                    cin >> cant;
                }while(cant>platosSucios.size() || cant<1);
            
                for(int i=0; i<cant; i++){
                    platotemporal=platosSucios.top();
                    platosSucios.pop();
                    platotemporal.estado=true;
                    platosLimpios.push(platotemporal);
                    cout <<"El plato se ha limpiado..." << endl;
                }
                }else{
                    cout << "Underflow! La pila de platos sucios esta vacia" << endl;
                }
                break;
            case 5:
                if(!platosLimpios.empty()){
                stack<Plato>clone=platosLimpios;
                while(!clone.empty()){
                platotemporal = clone.top();
                cout << "Plato [ Material: " << platotemporal.material << ", Color: ";
                cout << platotemporal.color << ", Estado: ";
                if(platotemporal.estado==false){
                    cout << "sucio";
                }else{
                    cout << "limpio";
                }
                cout << "]" << endl;
                clone.pop();
                }
                }else{
                    cout << "Underflow! La pila de platos limpios esta vacia" << endl;
                }
                break;
            case 6:
            if(!platosSucios.empty()){
                stack<Plato>clone=platosSucios;
                while(!clone.empty()){
                platotemporal = clone.top();
                cout << "Plato [ Material: " << platotemporal.material << ", Color: ";
                cout << platotemporal.color << ", Estado: ";
                if(platotemporal.estado==false){
                    cout << "sucio";
                clone.pop();
                }else{
                    cout << "limpio";
                }
                cout << "]" << endl;
                }
                
                }else{
                    cout << "Underflow! La pila de platos sucios esta vacia" << endl;
                }
                break;
            case 7:
                cout << "Fin del programa..." << endl;
                continuar=false;
                break;
            default:
                cout << "Opcion no valida!" << endl;
                break;
        }
    }while(continuar);
    return 0;
}
