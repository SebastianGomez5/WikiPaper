// implementacion de la clase producto:
#include "Producto.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

Producto::Producto(){
    //Declaracion de atributos en el constructor con valore pordefeto
    nombre = marca = unidad = especificaciones = "-";
    cod = precio = cantidad = 0;
    activo = true;
}

Producto::~Producto()
{
    //dtor
}

/*No se que hace, pero sé me deja acomodar
variables para poder ponerle valores por defecto */
void Producto::setValoresDefect(string name,string marc,string unid,
                                string especi,long codi,long preci,int canti,bool acti){
    nombre = name;
    cod = codi;
    marca = marc;
    unidad = unid;
    cantidad = canti;
    precio = preci;
    especificaciones = especi;
    activo = acti;
}

//Metodo que solicita nombre del producto
void Producto::setNomb(){
    cout<<"Nombre del producto: ";
    fflush(stdin);
    getline(cin, nombre);
}

//Metodo que solicita la marca del producto
void Producto::setMarca(){
    cout<<"Marca del producto: ";
    fflush(stdin);
    getline(cin, marca);
}

//Metodo que pide la unidad de venta del producto
void Producto::setUnidad(){
    cout<<"Unidad de venta: ";
    fflush(stdin);
    getline(cin, unidad);
}

//Metodo que pide especificaciones del producto
void Producto::setEspecifi(){
    cout<<"Especificaciones del producto: ";
    fflush(stdin);
    getline(cin, especificaciones);
}

//Metodo que solicita codigo del producto
void Producto::setCod(){
    cout<<"Ingrese Codigo del producto: ";
    cin>>cod;
}

// metodo que solicita el precio del producto
void Producto::setPrecio(){
    cout<<"Ingrese Precio del producto: $";
    cin>>precio;
}

//Metodo que solicita la cantidad del producto
void Producto::setCantidad(){
    cout<<"Cantidad de productos: ";
    cin>>cantidad;
}

//Metodo que cambia el estado del producto:
//Solicita una cadena para poder nombrar el nombre del producto
void Producto::setActivo(string name){
    if(activo == false){
        activo = true;
        cout<<"El Estado Del Producto "<<name<<" "<<" Ahora Sera 'Activo' \n";
    }
    else{
    activo = false;
    cout<<"El Estado Del Producto "<<name<<" "<<" Ahora Sera 'No Activo' \n";
    }
}

//Metodos get que retornan informacion solicitada
string Producto::getNomb(){
    return nombre;
}

string Producto::getMarca(){
    return marca;
}

string Producto::getUnidad(){
    return unidad;
}

string Producto::getEspecifi(){
    return especificaciones;
}

long Producto::getCod(){
    return cod;
}

long Producto::getPrecio(){
    return precio;
}

int Producto::getCantidad(){
    return cantidad;
}

//Metodo get, retorna en texto el estado del producto
string Producto::getActivo(){
    string m;
    if(activo == 1) m = "Activo";
    else m = "No Activo";
    return m;
}

vector<Producto>vecProducto; //Crea vector donde se guardará los datos

void Producto::ValordefectoList(){ //Funcion asigna productos valores por defecto
    Producto obj;
    obj.setValoresDefect("Papel Fotografico","INKCOLORS","Unidad",
    /*Producto 1*/      "Papel A4, high glossy photo paper 135 g",123,23000,50,true);

    vecProducto.push_back(obj);

    obj.setValoresDefect("Papel Periodico","Generico","Millar",
    /*Producto 2*/     "Papel Periódico X 50 Pliegos de 70x100 cm cada uno",
                        456,45000,50,true);

    vecProducto.push_back(obj);

    obj.setValoresDefect("Papel Bond","Copel","Rollo",
    /*Producto 3*/     "papel fabricado con fibra de eucalipto 100% blanqueada"
                        ,789,40000,50,true);

    vecProducto.push_back(obj);

    obj.setValoresDefect("Papel Kraft","Upper colors","Pack",
    /*Producto 4*/     "Vinilo adhesivo kraft dark, tam A4 180 g"
                        ,147,21500,50,true);

    vecProducto.push_back(obj);

    obj.setValoresDefect("Papel Propalcote","Propal","Pack",
    /*Producto 5*/     "Esmaltado, tam carta 200 g"
                        ,258,40000,50,true);

    vecProducto.push_back(obj);

}

/* metodo que permite adicionar un producto al vector
llama a sus respectivos metodos set.
recibe dos cadenas para mostrar el nombre del usuario actual.
tambien evalua si el tipo de usuario es apto para realizar esta accion
*/
void Producto::creaProduc(string name,string ape){
    Producto obj;
    char opc;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    if(TipoUsuario == "Gerente" || TipoUsuario == "Bodega"){
    cout<<"======= | REGISTRAR PRODUCTO | =======\n";
    obj.setNomb();
    obj.setMarca();
    obj.setCod();
    obj.setPrecio();
    obj.setCantidad();
    obj.setUnidad();
    obj.setEspecifi();

    //Procedimiento para confirmar datos
    do{
        cout<<"\nDesea Guardar Producto? [S = si, N = no]: ";
        fflush(stdin);
        cin>>opc;
    }while((opc != 'S' && opc != 's') && (opc != 'N' && opc != 'n'));
    if(opc == 'S' || opc == 's'){
        vecProducto.push_back(obj);
        cout<<"Producto Aniadido con exito!\n\n";
        fflush(stdin);
        cout<<"\nPresione para volver al menu anterior\n";
        cin.get();
        }else {cout<<"El Producto No Se Guardo...\n";
        fflush(stdin);
        cout<<"\nPresione para volver al menu anterior\n";
        cin.get();}
    } else{
       cout<<"No Tienes Acceso a esta Area.....\n\n";
        fflush(stdin);
        cout<<"\nPresione para volver al menu anterior\n";
        cin.get();
        }
}

/* metodo que muestra por pantalla la cantidad de los productos
unicamente que se encuentren activos
recibe dos cadenas para mostrar por pantalla el nombre del usuario presente
*/
void Producto::cantProduc(string name,string ape){
    Producto obj;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | CANTIDAD DE PRODUCTOS | =======\n\n";
    for(int i = 0; i < vecProducto.size();i++){
        obj = vecProducto[i];
        if(obj.getActivo() == "Activo"){
            cout<<obj.getNomb()<<" marca "<<obj.getMarca()<<": "<<obj.getCantidad()<<endl;
        }
    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
    cout<<"\n\n";
}

/* Metodo que deja ver los precios de los productos que se
   encuentren activos.
   recibe dos cadenas para mostrar por pantalla el nombre del usuario presente
*/
void Producto::verPreciosProd(string name,string ape){
    Producto obj;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | PRECIOS DE CADA PRODUCTO | =======\n\n";
    for(int i = 0; i < vecProducto.size();i++){
        obj = vecProducto[i];
        if(obj.getActivo() == "Activo"){
            cout<<obj.getNomb()<<" marca "<<obj.getMarca()<<": $"<<obj.getPrecio()<<endl;
        }
    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
    cout<<"\n\n";

}

/* metodo que permite mostrar la informacion de todos lo productos adicionados.
recibe dos cadenas para mostrar por pantalla el nombre del usuario presente
*/
void Producto::verProductos(string name,string ape){
    Producto obj;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | INFORMACIO DE TODOS LOS PRODUCTOS | =======\n";
    for(int i = 0; i < vecProducto.size(); i++){
        obj = vecProducto[i];

        cout<<"\nProducto "<<(i+1)<<endl;
        cout<<"Nombre: "<<obj.getNomb()<<endl;
        cout<<"Codigo: "<<obj.getCod()<<endl;
        cout<<"Marca: "<<obj.getMarca()<<endl;
        cout<<"unidad de venta: "<<obj.getUnidad()<<endl;
        cout<<"Especificaciones: "<<obj.getEspecifi()<<endl;
        cout<<"Estado: "<<obj.getActivo()<<endl<<endl;
    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
}

/* metodo que permite buscar la informacion de un producto
mediante a su codigo.
recibe dos cadenas para mostrar por pantalla el nombre del usuario presente.

*/
void Producto::buscarProducto(string name,string ape){
    bool existe = false;
    long buscar = 0;
    Producto obj;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    cout<<"======= | BUSCAR PRODUCTO POR CODIGO | =======\n";
    cout<<"Ingrese el codigo a buscar: ";
    cin>>buscar;
    for(int i = 0;i < vecProducto.size();i++){
        obj = vecProducto[i];
        if(obj.getCod() == buscar){
            existe = true;
        cout<<"\nProducto "<<(i+1)<<endl;
        cout<<"Nombre: "<<obj.getNomb()<<endl;
        cout<<"Codigo: "<<obj.getCod()<<endl;
        cout<<"Marca: "<<obj.getMarca()<<endl;
        cout<<"unidad de venta: "<<obj.getUnidad()<<endl;
        cout<<"Especificaciones: "<<obj.getEspecifi()<<endl;
        cout<<"Estado: "<<obj.getActivo()<<endl<<endl;
        break;
            } //Termina el if
        } //Termina el for.
        if(!existe){
            cout<<"El producto con codigo "<<buscar<<
              " no existe"<<endl<<endl;
    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
}

/* metodo que deja actualizar informacion de productos.
recibe dos cadenas para mostrar por pantalla el nombre del usuario presente.
tambien evalua si el tipo de usuario es apto para realizar esta accion.
*/
void Producto::ActualizarProducto(string name,string ape){ //Validar si es bodega o admin
    bool existe = false;
    long buscar = 0;
    Producto obj;
    int opc;
    char opci;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    if((TipoUsuario == "Bodega") || ( TipoUsuario == "Gerente")){
        cout<<"======= | ACTUALIZAR PRODUCTO | =======\n";
        cout<<"Ingrese el codigo del producto: ";
        cin>>buscar;
        for(int i = 0;i < vecProducto.size();i++){
            obj = vecProducto[i];
            if(obj.getCod() == buscar){
                existe = true;
                do{
                    cout<<"\nProducto "<<(i+1)<<endl;
                    cout<<"\n1. Nombre: "<<obj.getNomb()<<endl;
                    cout<<"2. Codigo: "<<obj.getCod()<<endl;
                    cout<<"3. Marca: "<<obj.getMarca()<<endl;
                    cout<<"4. Precio: $"<<obj.getPrecio()<<endl;
                    cout<<"5. Cantidad de producto: "<<obj.getCantidad()<<endl;
                    cout<<"6. Especificaciones: "<<obj.getEspecifi()<<endl;
                    cout<<"7. Unidad de venta: "<<obj.getUnidad()<<endl<<endl;
                    cout<<"Ingrese opcion a editar: ";
                    cin>>opc;
                }while((opc < 1) || (opc > 7));

                switch(opc){
                    case 1: obj.setNomb(); break;
                    case 2: obj.setCod(); break;
                    case 3: obj.setMarca(); break;
                    case 4: obj.setPrecio(); break;
                    case 5: obj.setCantidad(); break;
                    case 6: obj.setEspecifi(); break;
                    case 7: obj.setUnidad(); break;
                }
                do{
                cout<<"\nDesea Guardar Dato? [S = si, N = no]: ";
                fflush(stdin);
                cin>>opci;
                }while((opci != 'S' && opci != 's') && (opci != 'N' && opci != 'n'));
                if(opci == 'S' || opci == 's'){
                    vecProducto[i] = obj;
                    cout<<"DATO ACTUALIZADO\n\n";
                    fflush(stdin);
                    cout<<"\nPresione Para Volver Al Menu Anterior\n";
                    cin.get();
                    break;
                }else {cout<<"El Dato No Se Guardo...\n";
                    fflush(stdin);
                    cout<<"\nPresione Para Volver Al Menu Anterior\n";
                    cin.get();}
                }

        }if(!existe){
            cout<<"El producto con codigo "<<buscar<<
              " no existe"<<endl<<endl;
            fflush(stdin);
            cout<<"\nPresione para volver al menu anterior\n";
            cin.get();
        }
    }else{
       cout<<"No Tienes Acceso a esta Area.....\n\n";
        fflush(stdin);
        cout<<"\nPresione para volver al menu anterior\n";
        cin.get();
    }
}

/* metodo que permite cambiar el estado de un producto mediante a su codigo.
recibe dos cadenas para mostrar por pantalla el nombre del usuario presente.
tambien evalua si el tipo de usuario es apto para realizar esta accion.
*/
void Producto::EliminaProducto(string name,string ape){
    Producto obj;
    bool existe = false;
    cout<<"Usuario: "<<name<<" "<<ape<<endl;
    long buscar = 0;
    if(TipoUsuario == "Gerente" || TipoUsuario == "Bodega"){
        cout<<"======= | ACTIVA/DESACTIVA PRODUCTO | =======\n";
        cout<<"Ingrese el codigo a eliminar: ";
        cin>>buscar;
        for(int i = 0; i < vecProducto.size();i++){
            obj = vecProducto[i];
            if(obj.getCod() == buscar){
                existe = true;
                obj.setActivo(obj.getNomb());
                vecProducto[i] = obj;
                break;
            }
        }
        if(!existe){
                cout<<"El Producto con codigo "<<buscar<<
                " no existe"<<endl<<endl;
        }
        cout<<"\n\n";
    } else{
       cout<<"No Tienes Acceso a esta Area.....\n\n";
        }
        fflush(stdin);
        cout<<"\nPresione para volver al menu anterior\n";
        cin.get();
}

/* metodo que muestra el menu con opciones a realizar
con los productos.
recibe tres cadenas para mostrar por pantalla el nombre del usuario presente
y detectar el tipo de usuario presente
*/
void Producto::menuProducto(string usuari,string name,string ape){
    TipoUsuario = usuari;
    int opc;
    do{
        system("cls"); //limpia historial
        cout<<"Usuario: "<<name<<" "<<ape<<endl; //muestra nombre de usuario
        cout<<"================ | PRODUCTO | =================\n";
        cout<<"1. Registrar un producto\n";
        cout<<"2. Consultar Precios\n";
        cout<<"3. consultar cantidad de productos\n";
        cout<<"4. Consultar informacion de todos los productos\n";
        cout<<"5. Buscar producto por codigo\n";
        cout<<"6. Editar informacion de un producto\n";
        cout<<"7. Activar/Desactivar Producto\n";
        cout<<"0. Salir\n";
        cout<<"===============================================\n";
        cout<<"\nSeleccione una opcion: ";
        cin>>opc;
        system("cls"); //Limpia el historial
        switch(opc){
        case 1: creaProduc(name,ape); break;
        case 2: verPreciosProd(name,ape); break;
        case 3: cantProduc(name,ape); break;
        case 4: verProductos(name,ape); break;
        case 5: buscarProducto(name,ape); break;
        case 6: ActualizarProducto(name,ape); break;
        case 7: EliminaProducto(name,ape); break;
        case 0: cout<<"\n";
                break;
        default:cout<<"Opcion incorrecta\n\n";
        }
    }while(opc != 0);
}
