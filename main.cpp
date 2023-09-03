/* Main principal de la aplicacion
programadores:
              Juan Sebastian Gomez - 2259474
              Andres Eduardo Narvaez - 2259545
version: 1.0
fecha: 12/12/2022
*/
//Incluir clases
#include <iostream>
#include"Trabajador.h"
#include"Cliente.h"
#include"Proveedor.h"
#include"Caja.h"
#include"Producto.h"
using namespace std;

//Declaracion de clases como objetos
Trabajador obj1;
Producto obj2;
Cliente obj3;
Proveedor obj4;
Caja obj5;

//Declaracion de funciones
void menu();
void acercaDe();
//Metodo que muestra informacion de los programadores
void acercaDe(){
    system("cls");
    cout<<"\t PROGRAMADORES\n";
    cout<<"Programador 1\n";
    cout<<"Juan Sebastian Gomez Agudelo - 2259474\n";
    cout<<"Programador 2\n";
    cout<<"Andres Eduardo Narvaez Canas - 2259545\n\n";
    fflush(stdin);
    cout<<"Presione para volver al menu anterior\n";
    cin.get();
}
//Menu que puede redireccionar al usario al login y
//Informacion de los programadores
void menu(){
    int opc;
    do{
        system("cls");
        cout<<"\t    ------------------\n";
        cout<<"\t    |\tWIKI PAPER   |\n";
        cout<<"\t    ------------------\n";
        cout<<"\n\t1. Iniciar Seccion";
        cout<<"\n\t2. Acerca de...\n";
        cout<<"\t0. Salir\n";
        cout<<"\tSeleccione una opcion: ";
        cin>>opc;
        system("cls"); //Limpia el historial
        switch(opc){
        case 1: obj1.login() ; break;
        case 2: acercaDe(); break;
        case 0: cout<<"\n";
                break;
        default:cout<<"Opcion incorrecta\n\n";
        }
    }while(opc != 0);
}

int main(){
    obj1.ValoresDefecList(); //Crea Valores por defecto usuario
    obj2.ValordefectoList(); //Crea Valores por defecto productos
    obj3.ValoresDefecList(); //Crea valores por defecto clientes
    obj4.ValoresDefecList(); //Crea valores por defecto proveedor
    obj5.ValoresDefecList(); //Crea valor por defecto a la caja
    menu(); //Menu
    return 0;
}
