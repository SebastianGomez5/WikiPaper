/*
Implementacion de la clase caja encargada de manjerar el flujo
de dinero constante en la empresa Dunder Mifflin paper company.
*/
//Incluir librerias necesarias
#include "Caja.h"
#include"Fecha.h"
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include <iostream>
using namespace std;
//Metodo constructor que crea valores por defecto
Caja::Caja()
{
    cantidadCo = cantidadRe = saldo = 0;
}
//Metdodo destructor
Caja::~Caja()
{
    //dtor
}
/*Metodo que solicita la cantidad
de dinero a consignar y valida si esa cantidad es posible,
esto con el fin de que no se digite valores negativos
*/
void Caja::setConsignar(){
    do{//Ciclo que evalua si es posible retirar la cantidad
        cout<<"Digite la cantidad de dinero a consignar: $";
        cin>>cantidadCo;
        if(cantidadCo < 0){
            cout<<"\nValor Incorrecto!\n";
        }
    }while(cantidadCo < 0);
    saldo += cantidadCo; //A saldo se le agrega valor
}
/* Metodo que llama a la clase fecha que se encarga
de pedir una fecha que se usará para la fecha de consignacion.
*/
void Caja::setFechaConsignar(){
    cout<<"FECHA DE CONSIGNACION\n";
    fflush(stdin);
    fecha_consignar.setFecha();
}

/*Metodo que solicita la cantidad
de dinero a retirar y valida si esa cantidad es posible de retirar
esto con el fin de que no se pueda retirar dinero que no se encuentre almacenado
*/
void Caja::setRetirar(){
        //Ciclo que evalua si esa cantidad es posible de retirar
    do{
        cout<<"Digite la cantidad de dinero a retirar: $";
        cin>>cantidadRe;
        if(cantidadRe > saldo){
            cout<<"\nSaldo Insuficiente!\n";
        }
    }while(cantidadRe > saldo);
    saldo -= cantidadRe; //a saldo se le resta el valor
}

/* Metodo que llama a la clase fecha que se encarga
de pedir una fecha que se usará para la fecha de retiro bancario.
*/
void Caja::setFechaRetirar(){
    cout<<"FECHA DEL RETIRO.\n";
    fflush(stdin);
    fecha_retirar.setFecha();
}
/*
Metodos get que retornan el valor ingresado por los
metodos set*/
long Caja::getConsignar(){
    return cantidadCo;
}

string Caja::getFechaConsignar(){
    return fecha_consignar.getFecha();
}

long Caja::getRetirar(){
    return cantidadRe;
}

string Caja::getFechaRetiro(){
    return fecha_retirar.getFecha();
}
long Caja::getSaldo(){
    return saldo;
}

vector<Caja>vecCaja; //Se crea vector para almacenar los datos
//Metodo que crea valores por defecto
void Caja::ValoresDefecList(){
    Caja obj;
    /*
    Se crea un espacio en el vector
    se crean los valores por defecto.
    */
    obj.getSaldo();
    obj.getConsignar();
    obj.getFechaConsignar();
    obj.getRetirar();
    obj.getFechaRetiro();

    //Guarda los datos
    vecCaja.push_back(obj);
}

/* Metodo consignar que pide dos cadenas, esto con el fin de decorar el programa
poniendo el nombre del usuario.
el metod llama a setConsignar y setFechaConsignar, posteriormente
solicita confirmacion de datos.
*/
void Caja::consigna(string name, string ape){
    Caja obj;
    char opc;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | CONSIGNAR DINERO A CAJA | =======\n";
    for(int i = 0; i < vecCaja.size();i++){
        obj = vecCaja[i];
        obj.setConsignar(); //Pide el valor a consignar
        obj.setFechaConsignar(); //Pide fecha de consignacion

        do{
            cout<<"\nDesea Confirmar la Consignacion? [S = si, N = no]: ";
            fflush(stdin);
            cin>>opc;
        }while((opc != 'S' && opc != 's') && (opc != 'N' && opc != 'n'));
        if(opc == 'S' || opc == 's'){
            vecCaja[i] = obj;
            cout<<"Consignacion Exitosa!!";
            cout<<endl<<endl;
            fflush(stdin);
            cout<<"\nPresione para volver al menu anterior\n";
            cin.get();
            break;
        }else {cout<<"No Se Realizo la Consignacion...\n";
            fflush(stdin);
            cout<<"\nPresione para volver al menu anterior\n";
            cin.get();}
    }

}
/* Metodo retirar que llama a setRetirar y setFEchaRetirar
para poder realizar un retiro de dinero en caja
Pide confirmacion de datos
y solicita dos strings para poder poner el nombre y apellido
del usuario en la parte superior de la ventana
*/
void Caja::retirar(string name, string ape){
    Caja obj;
    char opc;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | RETIRAR DINERO | =======\n";
    for(int i = 0; i < vecCaja.size();i++){
        obj = vecCaja[i];
        obj.setRetirar(); //Pide valor a retirar
        obj.setFechaRetirar(); //Pide fecha de retiro

        do{
            cout<<"\nDesea Confirmar la Retirada de Dinero? [S = si, N = no]: ";
            fflush(stdin);
            cin>>opc;
        }while((opc != 'S' && opc != 's') && (opc != 'N' && opc != 'n'));
        if(opc == 'S' || opc == 's'){
            vecCaja[i] = obj;
            cout<<"Retiro Exitoso!!";
            cout<<endl<<endl;
            fflush(stdin);
            cout<<"\nPresione para volver al menu anterior\n";
            cin.get();
            break;
        }else {cout<<"No Se Realizo la Consignacion...\n";
            fflush(stdin);
            cout<<"\nPresione para volver al menu anterior\n";
            cin.get();}

    }
}
/* metodo que permite consultar el saldo actual
junto con las ultimas fechas de retiro y consignacion respectivas
Recibe dos string con el fin de mostrar en la parte superior
de la ventana el nombre del usuario presente
*/
void Caja::ConsultarDinero(string name, string ape){
    Caja obj;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | DINERO EN CAJA | =======\n";
    for(int i = 0;i < vecCaja.size();i++){
        obj = vecCaja[i];
        cout<<"Saldo: $"<<obj.getSaldo()<<endl;
        cout<<"Fecha de ultima consignacion: "<<obj.getFechaConsignar()<<endl;
        cout<<"Fecha de ultima Retirada: "<<obj.getFechaRetiro()<<endl<<endl;
        fflush(stdin);
        cout<<"\nPresione para volver al menu anterior\n";
        cin.get();
        break;
    }
}
/* metodo que muestra el menu con las acciones que se pueden realizar
en la clase.
asimismo manda al usuario a cada uno.
Tambien recibe dos string con el fin de mostrar en la parte superior
de la ventana el nombre del usuario presente
*/
void Caja::menuCaja(string name,string ape){
    //ValoresDefecList();
    int opc;
    do{
        system("cls");
        cout<<"Usuario: "<<name<<" "<<ape<<endl;
        cout<<"========= | CAJA | =========\n";
        cout<<"1. Consultar Dinero en Caja.\n";
        cout<<"2. Retirar Dinero de Caja.\n";
        cout<<"3. Consignar Dinero en Caja.\n";
        cout<<"0. Salir\n";
        cout<<"============================\n";
        cout<<"\nSeleccione una opcion: ";
        cin>>opc;
        system("cls"); //Limpia el historial
        switch(opc){
        case 1: ConsultarDinero(name,ape); break;
        case 2: retirar(name,ape); break;
        case 3: consigna(name,ape); break;
        case 0: cout<<"Gracias por usar mi App\n\n";
                break;
        default:cout<<"Opcion incorrecta\n\n";
        }
    }while(opc != 0);
}
