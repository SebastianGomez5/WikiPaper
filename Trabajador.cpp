/* implementacion de la clase Trabajador:
Encargada de gestionar a los usuarios, informacion
y menú correspondiente.
Tambien se encuentra el login
la clase hereda los metodos de las demas clases.
*/
#include "Trabajador.h"
#include"Producto.h"
#include"Proveedor.h"
#include"Cliente.h"
#include"Caja.h"
#include <iostream>
#include<vector>
using namespace std;

//Iniciar valores por defector en el constructor.
Trabajador::Trabajador(){
    nombre = apellido = sexo = cargo = ciudad = "-";
    cod = numId = 0;
    salario = edad = 0;
    activo = true;
    nomUsuario = contra = "***";

    //Atributos del login
    usuario = password = "-";
    contador = 0;
    ingresa = false;

}

Trabajador::~Trabajador()
{
    //dtor
}
/*Metodo que permite indicar la ruta para poder efectuar
valores por defectos */
void Trabajador::setValoresDefecto(string name, string ape, string sex, string carg,string ciu,
                                long codi, int salar, int eda, bool acti, string usuari, string contri){

        nombre = name;
        apellido = ape;
        sexo = sex;
        cargo = carg;
        ciudad = ciu;
        cod = codi;
        numId = codi;
        salario = salar;
        edad = eda;
        activo = acti;
        nomUsuario = usuari;
        contra = contri;
}

/* metodo que solicita el nombre de usuario
  para el login.
*/
void Trabajador::setNomUsuario(){
    cout<<"Ingrese Nombre de usuario: ";
    fflush(stdin);
    getline(cin, nomUsuario);
}

// Metodo que pide la contraseña para el login

void Trabajador::setContrasena(){
    cout<<"Ingrese contrasenia: ";
    fflush(stdin);
    getline(cin, contra);
}

int validar2(string);
//metodo que solicita el nombre de un trabajador.
void Trabajador::setNom(){
	REGRESO1:
    cout<<"Ingrese Nombre del Trabajador: ";
    fflush(stdin);
    getline(cin, nombre);
    if(validar2(nombre)==1){
		cout<<"El Dato Ingresado No Es Valido\n";
		goto REGRESO1;
	}
}

//metodo que pide el apellido de dicho trabajador
void Trabajador::setApe(){
	REGRESO1:
    cout<<"Ingrese Apellido del Trabajador: ";
    fflush(stdin);
    getline(cin, apellido);
    if(validar2(apellido)==1){
		cout<<"El Dato Ingresado No Es Valido\n";
		goto REGRESO1;
	}
}

//Metodo que pide el sexo del trabajador
void Trabajador::setSexo(){
	REGRESO1:
    cout<<"Ingrese Sexo del Trabajador: ";
    fflush(stdin);
    getline(cin, sexo);
    if(validar2(sexo)==1){
		cout<<"El Dato Ingresado No Es Valido\n";
		goto REGRESO1;
	}
}

//Metodo que solicita la edad del trabajador
void Trabajador::setEdad(){
    cout<<"Ingrese la Edad del Trabajador: ";
    cin>>edad;
}

//Metodo que solicita el numero id del trabajador
void Trabajador::setNumId(){
	REGRESO:
    cout<<"Ingrese Numero de Identificiacion del Trabajador: ";
    cin>>numId;
    if(numId<= 0){
    	cout<<"Ingrese Un Numero Valido"<<endl;
    	goto REGRESO;
	}
	else{
    	cod = numId;
	}
}

/*Metodo que solicita el cargo de un trabajador
 mediante un menu. */
void Trabajador::setCargo(){
    int opc;
    do{
        cout<<"CARGO DEL TRABAJADOR\n";
        cout<<"1. Gerente\n";
        cout<<"2. Vendedor\n";
        cout<<"3. Contador\n";
        cout<<"4. Compras\n";
        cout<<"5. Bodega\n";
        cout<<"Seleccione opcion: ";
        cin>>opc;
        switch(opc){
            case 1: cargo = "Gerente"; break;
            case 2: cargo = "Vendedor"; break;
            case 3: cargo = "Contador"; break;
            case 4: cargo = "Compras"; break;
            case 5: cargo = "Bodega"; break;
            default:cout<<"Opcion Fuera de Rango.\n\n";
        }
    }while((opc < 1) || (opc > 5));
}

//metodo que pide el salario del empleado
void Trabajador::setSalario(){
    cout<<"Ingrese Salario Mensual del Trabajador: $";
    cin>>salario;
}

//metodo que pide la ciudad de residencia del trabajador
void Trabajador::setCiuda(){
	REGRESO:
    cout<<"Ingrese Lugar de Residencia del Trabajador: ";
    fflush(stdin);
    getline(cin,ciudad);
    if(validar2(ciudad)==1){
		cout<<"El Dato Ingresado No Es Valido\n";
		goto REGRESO;
	}
}

/* Metodo que cambia el estado de un usuario.
recibo dos strings para poder mencionar el nombre del trabajador
al que se le realizo la accion.
*/
void Trabajador::setActivo(string name, string lastName){
    if(activo == false){
        activo = true;
        cout<<"El estado de "<<name<<" "<<lastName<<" ahora sera 'Activo' \n";
    }
    else{
    activo = false;
    cout<<"El estado de "<<name<<" "<<lastName<<" ahora sera 'No Activo' \n";
    }
}

//Metodos get, retornan valores ingresados
string Trabajador::getNom(){
    return nombre;
}

string Trabajador::getApe(){
    return apellido;
}

string Trabajador::getSexo(){
    return sexo;
}

int Trabajador::getEdad(){
    return edad;
}


long Trabajador::getNumId(){
    return numId;
}

long Trabajador::getCod(){
    return cod;
}

string Trabajador::getCargo(){
    return cargo;
}

int Trabajador::getSalario(){
    return salario;
}
string Trabajador::getCiuda(){
    return ciudad;
}

//Metodo get que retorna en texto el estado del usuario
string Trabajador::getActivo(){
    string m;
    if(activo == 1) m = "Activo";
    else m = "No Activo";
    return m;
}

string Trabajador::getNomUsuario(){
    return nomUsuario;
}

string Trabajador::getContrasena(){
    return contra;
}

vector<Trabajador>vecTrabajador; //Creo el vector

//Acomodar los valores por defecto y añadirlos al vector.
void Trabajador::ValoresDefecList(){
    Trabajador obj;
    obj.setValoresDefecto("Sebastian", "Gomez", "Hombre","Gerente",
                   "Tulua",2259474, 1000000, 18, true, "s","g");
    /*usuario 1*/
    vecTrabajador.push_back(obj);

    obj.setValoresDefecto("Andres", "Narvaez", "Hombre","Gerente",
                   "Tulua",2259545, 1000000, 20, true, "a","n");
    /*usuario 2*/
    vecTrabajador.push_back(obj);


    obj.setValoresDefecto("Dwight", "Schrute", "Hombre","Vendedor","Scranton",555,
                          90000000, 56, true, "d","s");
    /*usuario 3 */
    vecTrabajador.push_back(obj);

    obj.setValoresDefecto("Andy", "Bernard", "Hombre","Compras","Scranton",111,
                          90000000, 36, false, "a","b");
    /*usuario 4 */
    vecTrabajador.push_back(obj);

    obj.setValoresDefecto("Kevin", "Malone", "Hombre","Contador",
                   "Scranton",666, 80000000, 49, true, "k","m");
    /*usuario 5 */
    vecTrabajador.push_back(obj);

    obj.setValoresDefecto("Darryl", "Philbin", "Hombre","Bodega",
                   "Scranton",333, 6000000, 40, true, "d","p");
    /*usuario 6 */
    vecTrabajador.push_back(obj);

}

/*Metodo que permite adicionar un los datos de un usuario al vector
mediante los metodos set.
Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Trabajador::CreaUsuario(string name, string lastName){
   Trabajador obj;
   char opc;
    cout<<"Usuario: "<<name<<" "<<lastName<<endl;
    cout<<"======= | ADICIONAR USUARIO | =======\n";
    obj.setNom();
    obj.setApe();
    obj.setEdad();
    obj.setSexo();
    obj.setNumId();
    obj.setCargo();
    obj.setSalario();
    obj.setCiuda();
    obj.getActivo();
    obj.setNomUsuario();
    obj.setContrasena();

    do{    //Mensaje de confirmacion de datos
        cout<<"\nDesea Guardar Usuario? [S = si, N = no]: ";
        fflush(stdin);
        cin>>opc;
        }while((opc != 'S' && opc != 's') && (opc != 'N' && opc != 'n'));
    if(opc == 'S' || opc == 's'){
        vecTrabajador.push_back(obj);
        cout<<"\nUSUARIO ANIADIDO CON EXITO\n\n";
        fflush(stdin);
        cout<<"\nPresione para volver al menu anterior\n";
        cin.get();

    }else {cout<<"El usuario no se guardo...\n";
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();}
}

/* metodo que permite realizar una busqueda de los datos
   de un trabajador mediante su codigo/id.
    Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Trabajador::BuscarUsuario(string name, string lastName){
    Trabajador obj;
    bool existe = false;
    long buscar = 0;
    cout<<"Usuario: "<<name<<" "<<lastName<<endl;
    cout<<"======= | BUSCAR TRABAJADOR | =======\n";
    cout<<"Ingrese el codigo/id a buscar: ";
    cin>>buscar;
    for(int i = 0; i < vecTrabajador.size();i++){
        obj = vecTrabajador[i];
        if(obj.getCod() == buscar){
            existe = true;
            cout<<"\nUsuario "<<(i+1)<<endl;
            cout<<"Nombre: "<<obj.getNom()<<" "<<obj.getApe()<<endl;
            cout<<"Edad: "<<obj.getEdad()<<endl;
            cout<<"Codigo: "<<obj.getCod()<<endl;
            cout<<"Cargo: "<<obj.getCargo()<<endl;
            cout<<"Salario: "<<obj.getSalario()<<endl;
            cout<<"Sexo: "<<obj.getSexo()<<endl;
            cout<<"Id: "<<obj.getNumId()<<endl;
            cout<<"Lugar de Residencia: "<<obj.getCiuda()<<endl;
            cout<<"Estado: "<<obj.getActivo()<<endl;
            cout<<"Nombre de Usuario: "<<obj.getNomUsuario()<<endl;
            cout<<"Contrasena: "<<obj.getContrasena()<<endl<<endl;
            fflush(stdin);
            cout<<"\nPresione para volver al menu anterior\n";
            cin.get();
            break;
        }
    }
    if(!existe){
            cout<<"El Trabajador con codigo "<<buscar<<
              " no existe"<<endl<<endl;
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
    }
}

/* metodo que permite actualizar los datos de un trabajador mediante
el cogido/id.
  Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Trabajador::ActualizarUsuario(string name, string lastName){
    Trabajador obj;
    int opc;
    char opci;
    bool existe = false;
    long buscar = 0;
    cout<<"Usuario: "<<name<<" "<<lastName<<endl;
    cout<<"======= | EDITAR INFORMACION DE USUARIO | =======\n";
    cout<<"Ingrese el codigo del trabajador: ";
    cin>>buscar;
    for(int i = 0; i < vecTrabajador.size();i++){
        obj = vecTrabajador[i];
        if(obj.getCod() == buscar){
            existe = true;
            do{
                cout<<"\nUsuario "<<(i+1)<<endl;
                cout<<"1. Nombre: "<<obj.getNom()<<endl;
                cout<<"2. Apellido: "<<obj.getApe()<<endl;
                cout<<"3. Cargo: "<<obj.getCargo()<<endl;
                cout<<"4. Salario: $"<<obj.getSalario()<<endl;
                cout<<"5. Sexo: "<<obj.getSexo()<<endl;
                cout<<"6. Id: "<<obj.getNumId()<<endl;
                cout<<"7. Lugar de Residencia: "<<obj.getCiuda()<<endl;
                cout<<"8. Edad: "<<obj.getEdad()<<endl;
                cout<<"9. Nombre de usuario: "<<obj.getNomUsuario()<<endl;
                cout<<"10. Contrasena: "<<obj.getContrasena()<<endl<<endl;
                cout<<"Ingrese opcion a editar: ";
                cin>>opc;
            }while((opc < 1) || (opc > 10));

            switch(opc){
                case 1: obj.setNom(); break;
                case 2: obj.setApe(); break;
                case 3: obj.setCargo(); break;
                case 4: obj.setSalario(); break;
                case 5: obj.setSexo(); break;
                case 6: obj.setNumId(); break;
                case 7: obj.setCiuda(); break;
                case 8: obj.setEdad(); break;
                case 9: obj.setNomUsuario(); break;
                case 10: obj.setContrasena(); break;

            }
            do{  //Confirmacion de datos
                cout<<"\nDesea Guardar Dato? [S = si, N = no]: ";
                fflush(stdin);
                cin>>opci;
            }while((opci != 'S' && opci != 's') && (opci != 'N' && opci != 'n'));
            if(opci == 'S' || opci == 's'){
                vecTrabajador[i] = obj;
                cout<<"\nDATO ACTUALIZADO\n\n";
                fflush(stdin);
                cout<<"\nPresione para volver al menu anterior\n";
                cin.get();
                break;
            }else {cout<<"El dato no se guardo...\n";
                fflush(stdin);
                cout<<"\nPresione para volver al menu anterior\n";
                cin.get();}
        }
    } //Fuera del for
    if(!existe){
            cout<<"El Usuario con Codigo "<<buscar<<
              " no existe"<<endl<<endl;

    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
              }
}

/* metodo que permite consultar la informacion los datos de todos
los usuarios adicionados.
  Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Trabajador::VerUsuarios(string name, string lastName){
    Trabajador obj;
    cout<<"Usuario: "<<name<<" "<<lastName<<endl;
    cout<<"======= | INFORMACION DE TODOS LOS USUARIOS | =======\n";
    for(int i = 0; i < vecTrabajador.size(); i++){
        obj = vecTrabajador[i];

        cout<<"\nUsuario "<<(i+1)<<endl;
        cout<<"Nombre: "<<obj.getNom()<<endl;
        cout<<"Apellido: "<<obj.getApe()<<endl;
        cout<<"Cargo: "<<obj.getCargo()<<endl;
        cout<<"Salario: $"<<obj.getSalario()<<endl;
        cout<<"Sexo: "<<obj.getSexo()<<endl;
        cout<<"Id: "<<obj.getNumId()<<endl;
        cout<<"Lugar de Residencia: "<<obj.getCiuda()<<endl;
        cout<<"Estado: "<<obj.getActivo()<<endl;
        cout<<"Edad: "<<obj.getEdad()<<endl;
        cout<<"Nombre de usuario: "<<obj.getNomUsuario()<<endl;
        cout<<"Contrasena: "<<obj.getContrasena()<<endl<<endl;
    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
}

/*  metodo que permite eliminar (cambiar de estado) a un usuario mediante
 su respectivo codigo/id.
   Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Trabajador::EliminarUsuario(string name, string lastName){
    Trabajador obj;
    bool existe = false;
    long buscar = 0;
    cout<<"Usuario: "<<name<<" "<<lastName<<endl;
    cout<<"======= | ACTIVA/DESACTIVA USUARIO | =======\n";
    cout<<"Ingrese el codigo/id a eliminar: ";
    cin>>buscar;
    for(int i = 0; i < vecTrabajador.size();i++){
        obj = vecTrabajador[i];
        if(obj.getCod() == buscar){
            existe = true;
            obj.setActivo(obj.getNom(),obj.getApe());
            vecTrabajador[i] = obj;
            break;
        }
    }
    if(!existe){
            cout<<"El Trabajador con codigo "<<buscar<<
              " no existe"<<endl<<endl;
    }
    fflush(stdin);
    cout<<"\nPresione para volver al menu anterior\n";
    cin.get();
    cout<<"\n\n";
}

/* metodo que muestra un menú con las actividades realizables con
los usuarios.
  Recibe dos cadenas para poder mostrar el nombre del usuario presente.
*/
void Trabajador::menuTrabajador(string name, string lastName){
    int opc;
    do{
        system("cls");
        cout<<"Usuario: "<<name<<" "<<lastName<<endl;
        cout<<"======= | USUARIOS | =======\n";
        cout<<"1. Crear Usuario\n";
        cout<<"2. Buscar Usuario\n";
        cout<<"3. Actualizar Datos\n";
        cout<<"4. Consultar Listado General\n";
        cout<<"5. Activar/Desactivar Usuario\n";
        cout<<"0. Salir\n";
        cout<<"===========================\n";
        cout<<"\nSeleccione una opcion: ";
        cin>>opc;
        system("cls"); //Limpia el historial
        switch(opc){
        case 1: CreaUsuario(name,lastName); break;
        case 2: BuscarUsuario(name,lastName); break;
        case 3: ActualizarUsuario(name,lastName); break;
        case 4: VerUsuarios(name,lastName);break;
        case 5: EliminarUsuario(name,lastName); break;
        case 0: cout<<"Gracias por usar mi App\n\n";
                break;
        default:cout<<"Opcion incorrecta\n\n";
        }
    }while(opc != 0);
}


/*  metodo que permite que los usuarios se logueen
    para poder entrar a la aplicacion, no dejando ingresar
    a usuarios inactivos y posteriormente distribuye los submenus
    de las clases a cada tipo de usuario.
*/
void Trabajador::login(){
    //Declarar objetos a las demas clases
    Trabajador obj;
    Producto obj2;
    Cliente obj3;
    Proveedor obj4;
    Caja obj5;
    contador = 0; //el contador para permitir tener 3 oportunidades de ingresar
    do{
        ingresa = false;
        system("cls");
        cout<<"\t\t\tLOGIN DE USUARIO\n";
        cout<<"\t\t\t----------------\n";
        cout<<"\n\tUsuario: ";
        fflush(stdin);
        getline(cin, usuario);
        cout<<"\tPassword: ";
        fflush(stdin);
        getline(cin, password);
        for(int i = 0; i < vecTrabajador.size();i++){
            obj = vecTrabajador[i];
            if((usuario == obj.getNomUsuario())&& (password == obj.getContrasena())){
                if(obj.getActivo() == "Activo"){
                    ingresa = true;
                    contador = 0; //Reiniciar el contador
                    //cin.get();
                    break;
                }else{
                    cout<<"\n\tEl Usuario se Encuentra Inactivo\n\n";
                    contador ++;
                    cin.get();
                    break;
                }
            }
        }//Fin del for
        if((usuario != obj.getNomUsuario())&& (password != obj.getContrasena())){
                cout<<"\n\tUSUARIO NO EXISTE\n";
                ingresa = false;
                cin.get(); //No avanza hasta que le dé enter
                contador ++;
        }
    }while(ingresa == false && contador < 3);


    //Los menus de cada usuario
    if(ingresa == true){
        if(obj.getCargo() == "Gerente"){
            int opc;
            do{
                    /*Menú del administrador pudiendo
                    realizar todas la acciones */

                system("cls");
                cout<<"Usuario: "<<obj.getNom()<<" "<<obj.getApe()<<endl;
                cout<<"------- ADMIN --------\n";
                cout<<"1. Usuarios\n";
                cout<<"2. Productos\n";
                cout<<"3. Clientes\n";
                cout<<"4. Proveedores\n";
                cout<<"5. Caja\n";
                cout<<"0. Salir\n";
                cout<<"Seleccione una opcion: ";
                cin>>opc;
                system("cls"); //Limpia el historial
                switch(opc){
                //A cada submenú se le envia el nombre y apellido del usuario presente
                case 1: menuTrabajador(obj.getNom(),obj.getApe()); break;
                case 2: obj2.menuProducto(obj.getCargo(),obj.getNom(),obj.getApe()); break;
                case 3: obj3.menuCliente(obj.getNom(),obj.getApe()); break;
                case 4: obj4.menuProveedor(obj.getNom(),obj.getApe()); break;
                case 5: obj5.menuCaja(obj.getNom(),obj.getApe()); break;
                case 0: cout<<"\n";
                        break;
                default:cout<<"Opcion incorrecta\n\n";
                }
            }while(opc != 0);
        }
        if(obj.getCargo() == "Vendedor"){
                int opc;
                do{
                    // menu del vendedor con las actividades permitidas
                    system("cls");
                    cout<<"Usuario: "<<obj.getNom()<<" "<<obj.getApe()<<endl;
                    cout<<"------- VENDEDOR --------\n";
                    cout<<"1. Productos\n";
                    cout<<"2. Clientes\n";
                    cout<<"0. Salir\n";
                    cout<<"Seleccione una opcion: ";
                    cin>>opc;
                    system("cls"); //Limpia el historial
                    switch(opc){
                    //A cada submenú se le envia el nombre y apellido del usuario presente
                    case 1: obj2.menuProducto(obj.getCargo(),obj.getNom(),obj.getApe()); break;
                    case 2: obj3.menuCliente(obj.getNom(),obj.getApe()); break;
                    case 0: cout<<"\n";
                            break;
                    default:cout<<"Opcion incorrecta\n\n";
                    }
                }while(opc != 0);

        }
        if(obj.getCargo() == "Contador"){
            int opc;
            do{
                    //Menu del contador con su respectivo ingreso.
                system("cls");
                cout<<"Usuario: "<<obj.getNom()<<" "<<obj.getApe()<<endl;
                cout<<"------- CONTADOR --------\n";
                cout<<"1. Caja\n";
                cout<<"0. Salir\n";
                cout<<"Seleccione una opcion: ";
                cin>>opc;
                system("cls"); //Limpia el historial
                switch(opc){
                //Se le envia el nombre y apellido del usuario presente
                case 1: obj5.menuCaja(obj.getNom(),obj.getApe()); break;
                case 0: cout<<"\n";
                        break;
                default:cout<<"Opcion incorrecta\n\n";
                }
            }while(opc != 0);

        }
        if(obj.getCargo() == "Compras"){
                int opc;
                do{
                    //Menú del encargado de compras.
                    system("cls");
                    cout<<"Usuario: "<<obj.getNom()<<" "<<obj.getApe()<<endl;
                    cout<<"------- COMPRAS --------\n";
                    cout<<"1. Proveedores\n";
                    cout<<"2. Productos\n";
                    cout<<"0. Salir\n";
                    cout<<"Seleccione una opcion: ";
                    cin>>opc;
                    system("cls"); //Limpia el historial
                    switch(opc){
                    //A cada submenu se le envia el nombre y apellido de usuario presente
                    case 1: obj4.menuProveedor(obj.getNom(),obj.getApe()); break;
                    case 2: obj2.menuProducto(obj.getCargo(),obj.getNom(),obj.getApe()); break;
                    case 0: cout<<"\n";
                            break;
                    default:cout<<"Opcion incorrecta\n\n";
                    }
                }while(opc != 0);

        }
        if(obj.getCargo() == "Bodega"){
            int opc;
                do{
                    //Menu del encargado de bodega
                    system("cls");
                    cout<<"Usuario: "<<obj.getNom()<<" "<<obj.getApe()<<endl;
                    cout<<"------- BODEGA --------\n";
                    cout<<"1. Productos\n";
                    cout<<"0. Salir\n";
                    cout<<"Seleccione una opcion: ";
                    cin>>opc;
                    system("cls"); //Limpia el historial
                    switch(opc){
                    //A cada submenu se le envia el nombre y apellido de usuario presente
                    case 1: obj2.menuProducto(obj.getCargo(),obj.getNom(),obj.getApe()); break;
                    case 0: cout<<"\n";
                            break;
                    default:cout<<"Opcion incorrecta\n\n";
                    }
                }while(opc != 0);

        }
    } //Termina el if de ingresa
}//Termina funcion login
//Funcion para validar cadenas
int validar2(string x){
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

