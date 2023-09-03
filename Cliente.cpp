// Implementación de la clase cliente:
//Incluir librerias necesarias
#include "Cliente.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

Cliente::Cliente(){
    //Atributos de la clase en sus valores por defecto
     nombre = ciudad = apellido = tipoCliente = nomEmpresa = tel ="-";
     cod =  Id = 0;
     activo = true;

}

Cliente::~Cliente()
{
    //dtor
}


/* Metodo que acomoda los valores para poder
crear valores por defecto
*/
void Cliente::setValoresDefecto(string name, string ape,string ciu,
                    long codi, bool acti, string tell, string tipoC, string empre){

    nombre = name;
    apellido = ape;
    cod = codi;
    ciudad = ciu;
    tipoCliente = tipoC;
    nomEmpresa = empre;
    tel = tell;
    Id = codi;
    activo = acti;
}

int validar(string);
void Cliente::setNom(){ //metodo que Pide el nombre
		REGRESO1:
	    cout<<"Ingrese Nombre: ";
	    fflush(stdin);
	    getline(cin, nombre);
	    if(validar(nombre)==1){
            cout<<"El Dato Ingresado No Es Valido\n";
            goto REGRESO1;
	    }
}

void Cliente::setApe(){  //metodo que Pide el apellido
    REGRESO1:
	cout<<"Ingrese Apellido: ";
    fflush(stdin);
    getline(cin, apellido);
    if(validar(apellido)==1){
		cout<<"El Dato Ingresado No Es Valido\n";
		goto REGRESO1;
    }
}

void Cliente::setNumId(){ //Metodo que pide numero id
    cout<<"Ingrese Numero de identificacion: ";
    cin>>Id;
}

void Cliente::setCod(){  // metodo que asigna a codigo el numero id
    cod = Id;
}

void Cliente::setTel(){  //Pide un numero de telefono fijo
    cout<<"Ingrese Telefono: ";
    fflush(stdin);
    getline(cin,tel);
}

void Cliente::setCiu(){  //Pide la ciudad
    cout<<"Ingrese Ciudad: ";
    fflush(stdin);
    getline(cin, ciudad);
}

void Cliente::setTipo(){ //Para saber que tipo de cliente es.
    int opc;
    do{
        cout<<"TIPO DE CLIENTE\n";
        cout<<"1. Natural\n";
        cout<<"2. Empresa\n";
        cout<<"Seleccione opcion: ";
        cin>>opc;
        if((opc < 1) || (opc > 2)){ //Evalua que la opcion está en el rango
           cout<<"Error\n\n";
           }
    }while((opc < 1) || (opc > 2));

    if(opc == 1){
        tipoCliente = "Natural";
    }if(opc == 2){
        tipoCliente = "Empresa";
        cout<<"Ingrese Nombre de la empresa: ";  //En case de ser empresa se pide el nombre de la empresa
        fflush(stdin);
        getline(cin, nomEmpresa);

    }
}
/* Metodo que cambia el estado de un cliente,
recibe dos cadenas para poder mostrar por pantalla
el nombre del cliente
*/
void Cliente::setActivo(string name, string ape){
    if(activo == false){
        activo = true;
        cout<<"El estado de "<<name<<" "<<ape<<" ahora sera 'Activo' \n";
    }
    else{
    activo = false;
    cout<<"El estado de "<<name<<" "<<ape<<" ahora sera 'No Activo' \n";
    }
}

//Metodos get que retornan valores ingresados
string Cliente::getNom(){
    return nombre;
}

string Cliente::getApe(){
    return apellido;
}

long Cliente::getNumId(){
    return Id;
}

long Cliente::getCod(){
    return cod;
}

string Cliente::getTel(){
    return tel;
}

string Cliente::getCiu(){
    return ciudad;
}

string Cliente::getTipo(){
    return tipoCliente;
}

string Cliente::getNomEmpre(){
    return nomEmpresa;
}

string Cliente::getActivo(){ //Este metodo solo retorna el mensaje
    string m;
    if(activo == 1) m = "Activo";
    else m = "No Activo";
    return m;
}

vector<Cliente>vecCliente; //Vector en donde se guardan los datos.

void Cliente::ValoresDefecList(){ //Metodo en el cual se mandan valores al metodo set y se
    Cliente obj;                              // guarda en el vector

    obj.setValoresDefecto("Walter", "White", "Albuquerque",111, true, "3269143152", "Natural","-");
    /*Cliente 1*/
    vecCliente.push_back(obj);

    obj.setValoresDefecto("Jesse", "Pinkman", "Albuquerque",222, true, "3479501122", "Natural","-");
    /*Cliente 2*/
    vecCliente.push_back(obj);

    obj.setValoresDefecto("Gustavo", "Fring", "Albuquerque",333, true, "3086924884", "Empresa","Los pollos Hermanos");
    /*Cliente 3*/
    vecCliente.push_back(obj);

    obj.setValoresDefecto("Saul", "Goodman", "Albuquerque",444, true, "(505) 503-4455", "Empresa","Ice Station Zebra");
    /*Cliente 4*/
    vecCliente.push_back(obj);


    obj.setValoresDefecto("Hank", "Schrader", "Albuquerque",555, false, "3001239806", "Natural","-");
    /*Cliente 5*/
    vecCliente.push_back(obj);

}


void Cliente::creacliente(string name,string ape){ //Funcion para cuando se va registrar un cliente nuevo
    Cliente obj;
    char opc;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"=====| ADICIONAR CLIENTE | =====\n";
    obj.setNom();
    obj.setApe();
    obj.setNumId();
    obj.setCod();
    obj.setTel();
    obj.setCiu();
    obj.setTipo();
    obj.getActivo();

     do{        //Mensaje de confirmacion de datos
        cout<<"\nDesea Guardar Cliente? [S = si, N = no]: ";
        fflush(stdin);
        cin>>opc;
        }while((opc != 'S' && opc != 's') && (opc != 'N' && opc != 'n'));
    if(opc == 'S' || opc == 's'){
        vecCliente.push_back(obj);
        cout<<"\nCLIENTE ANIADIDO CON EXITO\n\n";
        fflush(stdin);
        cout<<"\nPresione para volver al menu anterior\n";
        cin.get();
        }else {cout<<"El Cliente No Se Guardo...\n";
        fflush(stdin);
        cout<<"\nPresione para volver al menu anterior\n";
        cin.get();}
}

/* metodo que permite buscar los datos de un cliente
mediante al numero id.
recibe dos cadenas para poder nombrar al usuario presente
*/
void Cliente::BuscaCliente(string name,string ape){
    Cliente obj;
    bool existe = false;
    long buscar = 0;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"===== | BUSCAR CLIENTE POR CODIGO/ID | =====\n";
    cout<<"Ingrese el codigo/id a buscar: ";
    cin>>buscar;
    for(int i = 0; i < vecCliente.size(); i++){
        obj = vecCliente[i];
        if(obj.getCod() == buscar){
            existe = true;
            cout<<"\nCliente "<<(i+1);
            cout<<"\nNombre: "<<obj.getNom()<<endl;
            cout<<"Apellido: "<<obj.getApe()<<endl;
            cout<<"Numero Id: "<<obj.getNumId()<<endl;
            cout<<"Codigo: "<<obj.getCod()<<endl;
            cout<<"Telefono: "<<obj.getTel()<<endl;
            cout<<"Ciudad: "<<obj.getCiu()<<endl;
            cout<<"Estado: "<<obj.getActivo()<<endl;
            cout<<"Tipo de cliente: "<<obj.getTipo()<<endl;
            if(obj.getTipo() == "Empresa"){
                cout<<"Nombre de la empresa: "<<obj.getNomEmpre()<<endl<<endl;
                break;
            }else{cout<<endl<<endl;
            break;
            }

        }
    }if(!existe){
            cout<<"El Cliente con Codigo "<<buscar<<" no existe"<<endl<<endl; }

    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
}

/*
Metodo que permite actualizar datos de un cliente
Recibe dos cadenas para poder mostrar el nombre del usuario presente
*/
void Cliente::actualizadatos(string name,string ape){
    Cliente obj;
    int opc;
    char opci;
    bool existe = false;
    long buscar = 0;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"===== | EDITAR INFORMACION DE CLIENTE | =====\n";
    cout<<"Ingrese el Codigo del Cliente: ";
    cin>>buscar;
    for(int i = 0; i < vecCliente.size();i++){
        obj = vecCliente[i];
        if(obj.getCod() == buscar){
            existe = true;
            do{
                cout<<"\nCliente "<<(i+1)<<endl;
                cout<<"1. Nombre: "<<obj.getNom()<<endl;
                cout<<"2. Apellido: "<<obj.getApe()<<endl;
                cout<<"3. Numero Id: "<<obj.getNumId()<<endl;
                cout<<"4. Telefono: "<<obj.getTel()<<endl;
                cout<<"5. Ciudad: "<<obj.getCiu()<<endl;
                cout<<"6. Tipo de cliente: "<<obj.getTipo()<<endl;
                if(obj.getTipo() == "Empresa"){ //Evalua si es cliente empresa para mostrar el nombre
                    cout<<"7. Nombre de la empresa: "<<obj.getNomEmpre()<<endl<<endl;}
                cout<<"Ingrese opcion a editar: ";
                cin>>opc;
                }while((opc < 1) || (opc > 7));

                switch(opc){
                    case 1: obj.setNom(); break;
                    case 2: obj.setApe(); break;
                    case 3: obj.setNumId(); break;
                    case 4: obj.setTel(); break;
                    case 5: obj.setCiu(); break;
                    case 6: obj.setTipo(); break;
                    case 7: obj.getNomEmpre(); break;
                    default:cout<<"Opcion incorrecta\n\n";
                }

                //Confirmacion de datos
                do{
                    cout<<"\nDesea Guardar Dato? [S = si, N = no]: ";
                    fflush(stdin);
                    cin>>opci;
                }while((opci != 'S' && opci != 's') && (opci != 'N' && opci != 'n'));
                if(opci == 'S' || opci == 's'){
                    vecCliente[i] = obj;
                    cout<<"DATO ACTUALIZADO\n\n";
                    fflush(stdin);
                    cout<<"\nPresione para volver al menu anterior\n";
                    cin.get();
                    break;
                }else {cout<<"El Dato No Se Guardo...\n";
                fflush(stdin);
                cout<<"\nPresione para volver al menu anterior\n";
                cin.get();}


            }

        }if(!existe){
            cout<<"El Cliente con Codigo "<<buscar<<
              " no existe"<<endl<<endl;
            fflush(stdin);
            cout<<"\nPresione para volver al menu anterior\n";
            cin.get();
        }
}



void Cliente::mostrarcliente(string name,string ape){  //Funcion para cuando se quiere ver la lista de los clientes
    Cliente obj;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"===== | INFORMACION DE TODOS LOS CLIENTES | =====\n";
    for(int i = 0; i < vecCliente.size(); i++){
    obj = vecCliente[i];
    cout<<"\nCliente "<<(i+1);
    cout<<"\nNombre: "<<obj.getNom()<<endl;
    cout<<"Apellido: "<<obj.getApe()<<endl;
    cout<<"Codigo: "<<obj.getCod()<<endl;
    cout<<"Telefono: "<<obj.getTel()<<endl;
    cout<<"Ciudad: "<<obj.getCiu()<<endl;
    cout<<"Estado: "<<obj.getActivo()<<endl;
    cout<<"Tipo de cliente: "<<obj.getTipo()<<endl;
    if(obj.getTipo() == "Empresa"){
        cout<<"Nombre de la empresa: "<<obj.getNomEmpre()<<endl<<endl;
    }else{cout<<endl<<endl;}

    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
}

/*  metodo que permite cambiar el estado de un cliente solicitando
su numero id.
recibe dos cadenas para poder mostrar el nombre del usuario presente
*/
void Cliente::EliminaCliente(string name,string ape){
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    Cliente obj;
    bool existe = false;
    long buscar = 0;
    cout<<"===== | ELIMINA USUARIO | =====\n";
    cout<<"Ingrese el codigo/id a eliminar: ";
    cin>>buscar;
    for(int i = 0; i < vecCliente.size();i++){
        obj = vecCliente[i];
        if(obj.getCod() == buscar){
            existe = true;
            obj.setActivo(obj.getNom(),obj.getApe());
            vecCliente[i] = obj;
            break;
        }
    }
    if(!existe){
            cout<<"El Cliente con Codigo "<<buscar<<
              " No Existe"<<endl<<endl;
    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
    cout<<"\n\n";
}

void Cliente::menuCliente(string name,string ape){
     //Menu para seleccionar que opcion quiere ejecutar.
     int opc;
    do{
        system("cls");
        cout<<"Usuario: "<<name<<" "<<ape<<endl;
        cout<<"========== | CLIENTES | =========\n";
        cout<<"1. Adicionar un Cliente\n";
        cout<<"2. Buscar Cliente\n";
        cout<<"3. Actualizar Datos de Clientes\n";
        cout<<"4. Consultar Listado General\n";
        cout<<"5. Activar/Desactivar Cliente\n";
        cout<<"0. Salir\n";
        cout<<"=================================\n";
        cout<<"\nSeleccione una opcion: ";
        cin>>opc;
        system("cls"); //Limpia el historial
        switch(opc){
        case 1: creacliente(name,ape); break;
        case 2: BuscaCliente(name,ape); break;
        case 3: actualizadatos(name,ape); break;
        case 4: mostrarcliente(name,ape); break;
        case 5: EliminaCliente(name,ape); break;
        case 0: cout<<"";
                break;
        default:cout<<"Opcion incorrecta\n\n";
        }
    }while(opc != 0);
}

//Metodo usado para validar las cadenas
int validar(string x){
	char c;
	for(int i=0; i<x.size(); i++){
		c= x[i];
		if(isalpha(c)==0){
		if(isspace(c)==0){
			return 1;
		}
		}
	}
}
