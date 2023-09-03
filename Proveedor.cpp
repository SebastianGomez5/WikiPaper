//Implementacion de la clase Proveedor
#include "Proveedor.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

//Iniciacion de valores por defecto en el constructor
Proveedor::Proveedor(){
    nombre = apellido = empresa = producto = tel = "-";
    cod = 0;
    activo = true;
}

Proveedor::~Proveedor()
{
    //dtor
}

//Metodo que acomoda los valores para crear valores por defecto
void Proveedor::setValoresDefecto(string name, string ape, string empre, string prod, string tell,
        /*Creará valores por defecto */ long codi, bool acti){
    nombre = name;
    apellido = ape;
    empresa = empre;
    producto = prod;
    tel = tell;
    cod = codi;
    activo = acti;
}

int validar1(string);
//Metodo que pide el nombre del proveedor con validacion

void Proveedor::set_nom(){
	REGRESO1:
    cout<<"Ingrese Nombre del trabajador encargado: ";
    fflush(stdin);
    getline(cin, nombre);
    if(validar1(nombre)==1){
		cout<<"el dato ingresado no es valido\n";
		goto REGRESO1;
	}
}

//Metodo que pide el apellido con validacion
void Proveedor::set_ape(){
	REGRESO1:
    cout<<"Ingrese Apellido: ";
    fflush(stdin);
    getline(cin, apellido);
    if(validar1(apellido)==1){
		cout<<"El Dato Ingresado No Es Valido\n";
		goto REGRESO1;
	}
}

//Metodo que pide el nombre de la empresa con su respectiva validacion
void Proveedor::set_empre(){
    REGRESO1:
    cout<<"Ingrese Nombre de la empresa: ";
    fflush(stdin);
    getline(cin, empresa);
    if(validar1(empresa)==1){
		cout<<"El Dato Ingresado No Es Valido\n";
		goto REGRESO1;
	}
}

//Metodo que pide el nombre del producto que provee
void Proveedor::set_prod(){
    REGRESO1:
    cout<<"Ingrese nombre del producto: ";
    fflush(stdin);
    getline(cin, producto);
    if(validar1(producto)==1){
		cout<<"El Dato Ingresado No Es Valido";
		goto REGRESO1;
	}
}

//metodo que pide el codigo
void Proveedor::set_cod(){
    cout<<"Ingrese Codigo del proveedor: ";
    cin>>cod;
}

//Metodo que pide el telefono
void Proveedor::set_tel(){
    cout<<"Ingrese Telefono: ";
    fflush(stdin);
    getline(cin, tel);

}

/*Metodo que cambia el estado del proveedor.
 recibe dos cadenas para informar sobre el nombre de la persona*/
void Proveedor::set_activo(string name,string ape){
    if(activo == false){
        activo = true;
        cout<<"El estado de "<<name<<" "<<ape<<" ahora sera 'Activo' \n";
    }
    else{
        activo = false;
        cout<<"El estado de "<<name<<" "<<ape<<" ahora sera 'No Activo' \n";
    }
}

//Metodos get, retornan valores ingresados
string Proveedor::get_nom(){
    return nombre;
}

string Proveedor::get_ape(){
    return apellido;
}

string Proveedor::get_empre(){
    return empresa;
}

string Proveedor::get_prod(){
    return producto;
}

long Proveedor::get_cod(){
    return cod;
}

string Proveedor::get_tel(){
    return tel;
}

//Metodo que retorna en texto el estado actual
string Proveedor::getActivo(){
    string m;
    if(activo == 1) m = "Activo";
    else m = "No Activo";
    return m;
}

vector<Proveedor>vecProveedor; //Vector para guardar proveedores

void Proveedor::ValoresDefecList(){ //Metodo por el cual se asignan valores por defectos
    Proveedor obj;

    obj.setValoresDefecto("Tommy","Shelby","Shelby Company Limited","Papel Fotografico",
                          "3408551973",999,true);
    /*Proveedor 1*/
    vecProveedor.push_back(obj);

    obj.setValoresDefecto("Harvey","Specter","Pearson Specter Litt","Papel Periodico",
                          "3978506671",888,true);
    /*Proveedor 2*/
    vecProveedor.push_back(obj);


    obj.setValoresDefecto("Owen","Wilson","AVT","Papel Bond",
                          "3110103015",777,false);
    /*Proveedor 3*/
    vecProveedor.push_back(obj);


    obj.setValoresDefecto("Blake","Carrington","Carrington Atlantic","Papel Kraft",
                          "3860596374",666,true);
    /*Proveedor 4*/
    vecProveedor.push_back(obj);


    obj.setValoresDefecto("Daniel","LaRusso","LaRusso Auto Group","Papel Propalcote",
                          "1-818-72",555,true);
    /*Proveedor 5*/
    vecProveedor.push_back(obj);
}

/* Metodo que permite adicionar datos de proveedores llamando
a metodos set y posteriormente realizando una confirmacion de datos.
Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Proveedor::CreaProveedor(string name, string ape){
    Proveedor obj;
    char opc;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======== | ADICIONAR PROVEEDOR | =======\n";
    obj.set_empre();
    obj.set_nom();
    obj.set_ape();
    obj.set_prod();
    obj.set_cod();
    obj.set_tel();

    do{
        cout<<"\nDesea Guardar Proveedor? [S = si, N = no]: ";
        fflush(stdin);
        cin>>opc;
        }while((opc != 'S' && opc != 's') && (opc != 'N' && opc != 'n'));
    if(opc == 'S' || opc == 's'){
        vecProveedor.push_back(obj);
        cout<<"\nPROVEEDOR ANIADIDO CON EXITO\n\n";
        fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
    }else {cout<<"El Proveedor No Se Guardo...\n";
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();}
}

/* metodo que permite buscar un proveedor mediante su codigo.
Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Proveedor::BuscarProveedor(string name, string ape){
    Proveedor obj;
    bool existe = false;
    long buscar = 0;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
        cout<<"======= | BUSCAR PROVEEDOR POR CODIGO | =======\n";
        cout<<"Ingrese el codigo a buscar: ";
        cin>>buscar;
        for(int i = 0; i < vecProveedor.size();i++){
            obj = vecProveedor[i];
            if(obj.get_cod() == buscar){
                existe = true;
                cout<<"\nProveedor "<<(i+1)<<endl;
                cout<<"Nombre de la Empresa: "<<obj.get_empre()<<endl;
                cout<<"Nombre del trabajador encargado: "<<obj.get_nom()<<" "<<obj.get_ape()<<endl;
                cout<<"codigo del proveedor: "<<obj.get_cod()<<endl;
                cout<<"Telefono: "<<obj.get_tel()<<endl;
                cout<<"Estado: "<<obj.getActivo()<<endl<<endl;
            }
        } if(!existe){
                cout<<"El Proveedor con Codigo "<<buscar<<
                " no existe"<<endl<<endl; }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();

}

/* metodo que permite actualizar los datos de un proveedor.
Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Proveedor::ActualizarDatos(string name, string ape){
    Proveedor obj;
    int opc;
    char opci;
    bool existe = false;
    long buscar = 0;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | EDITAR INFORMACION DE PROVEEDOR | =======\n";
    cout<<"Ingrese el Codigo del Proveedor: ";
    cin>>buscar;
    for(int i = 0; i < vecProveedor.size();i++){
        obj = vecProveedor[i];
        if(obj.get_cod() == buscar){
            existe = true;
            do{
                cout<<"\nProveedor "<<(i+1)<<endl;
                cout<<"1. Nombre de la Empresa: "<<obj.get_empre()<<endl;
                cout<<"2. Nombre del trabajador encargado: "<<obj.get_nom()<<endl;
                cout<<"3. Apellido del trabajador encargado: "<<obj.get_ape()<<endl;
                cout<<"4. codigo del proveedor: "<<obj.get_cod()<<endl;
                cout<<"5. Telefono: "<<obj.get_tel()<<endl<<endl;
                cout<<"Ingrese opcion a editar: ";
                cin>>opc;
                }while((opc < 1) || (opc > 5));

                switch(opc){
                    case 1: obj.set_empre(); break;
                    case 2: obj.set_nom(); break;
                    case 3: obj.set_ape(); break;
                    case 4: obj.set_cod(); break;
                    case 5: obj.set_tel(); break;
                    default:cout<<"Opcion incorrecta\n\n";
                }
                do{ //Mensaje de confirmacion de guardado de datos
                    cout<<"\nDesea Guardar Dato? [S = si, N = no]: ";
                    fflush(stdin);
                    cin>>opci;
                }while((opci != 'S' && opci != 's') && (opci != 'N' && opci != 'n'));
                if(opci == 'S' || opci == 's'){
                    vecProveedor[i] = obj;
                    cout<<"DATO ACTUALIZADO\n\n";
                    fflush(stdin);
                    cout<<"\nPresione para volver al menu anterior\n";
                    cin.get();
                    break;
                }else {cout<<"El Proveedor No Se Guardo...\n";
                    fflush(stdin);
                    cout<<"\nPresione para volver al menu anterior\n";
                    cin.get();}

            }

        }if(!existe){
            cout<<"El Proveedor con Codigo "<<buscar<<
              " no existe"<<endl<<endl;
            fflush(stdin);
            cout<<"\nPresione para volver al menu anterior\n";
            cin.get();
        }
}

/* metodo que permite consultar listado general de toda la informacion
de los proveedores registrados.
Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Proveedor::VerProveedors(string name, string ape){
    Proveedor obj;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | INFORMACION DE PROVEEDORES | =======\n";
    for(int i = 0; i < vecProveedor.size();i++){
        obj = vecProveedor[i];

        cout<<"\nProveedor "<<(i+1)<<endl;
        cout<<"Nombre de la empresa: "<<obj.get_empre()<<endl;
        cout<<"Producto que provee: "<<obj.get_prod()<<endl;
        cout<<"Nombre del trabajador encargado: "<<obj.get_nom()<<" "<<obj.get_ape()<<endl;
        cout<<"codigo del proveedor: "<<obj.get_cod()<<endl;
        cout<<"Telefono: "<<obj.get_tel()<<endl;
        cout<<"Estado: "<<obj.getActivo()<<endl<<endl;
    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
}

/*Metodo que permite eliminar un proveedor.
Recibe dos cadenas para poder mostrar el nombre del usuario presente. */
void Proveedor::EliminaProveedor(string name, string ape){
    Proveedor obj;
    bool existe = false;
    long buscar = 0;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | ACTIVAR/DESACTIVAR PROVEEDOR | =======\n";
    cout<<"Ingrese el Codigo a Eliminar: ";
    cin>>buscar;
    for(int i = 0; i < vecProveedor.size();i++){
        obj = vecProveedor[i];
        if(obj.get_cod() == buscar){
            existe = true;
            obj.set_activo(obj.get_nom(),obj.get_ape());
            vecProveedor[i] = obj;
            break;
        }
    }
    if(!existe){
            cout<<"El Proveedor con Codigo "<<buscar<<
              " No Existe"<<endl<<endl;
    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
    cout<<"\n\n";
}
//Recibe dos cadenas para poder mostrar el nombre del usuario presente.
void Proveedor::menuProveedor(string name, string ape){ //Menu para seleccionar que opcion quiere.
    //ValoresDefecList();
    int opc;
    do{
        system("cls");
        cout<<"Usuario: "<<name<<" "<<ape<<endl;
        cout<<"========= | PROVEEDOR | =========\n";
        cout<<"1. Adicionar un proveedor\n";
        cout<<"2. Buscar Proveedor\n";
        cout<<"3. Actualizar Datos de Proveedor\n";
        cout<<"4. Consultar Listado General\n";
        cout<<"5. Activar/Desactivar Proveedor\n";
        cout<<"0. Salir\n";
        cout<<"=================================\n";
        cout<<"\nSeleccione una opcion: ";
        cin>>opc;
        system("cls"); //Limpia el historial
        switch(opc){
        case 1: CreaProveedor(name,ape); break;
        case 2: BuscarProveedor(name,ape); break;
        case 3: ActualizarDatos(name,ape); break;
        case 4: VerProveedors(name,ape); break;
        case 5: EliminaProveedor(name,ape); break;
        case 0: cout<<"\n";
                break;
        default:cout<<"Opcion incorrecta\n\n";
        }
    }while(opc != 0);
}
//Metodo para validar las cadenas de texto
int validar1(string x){
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
