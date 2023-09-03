/* Clase fecha encargada de solicitar una fecha
se usará como composicion con la clase caja.
*/
//Librerias a usar
#include "Fecha.h"
#include <iostream>
using namespace std;

//Valores por defecto en el constructor
Fecha::Fecha()
{
    dia = mes = year = 0;
}

Fecha::~Fecha()
{
    //dtor
}

//metodo que solicita fecha: numero del mes, dia, y año
//posterior mente evalua que la fecha sea valida
void Fecha::setFecha(){
	REGRESO:
    cout<<"ingrese mes: ";
    cin>>mes;
    if(mes<1 || mes>12){
    	cout<<"digite un numero de mes valido\n";
    	goto REGRESO;
	}else{
		REGRESO1:
		cout<<"ingrese dia: ";
    	cin>>dia;
    	if(dia>=1){

    	//Valida que la fecha ingresada sea correcta
	    	if((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && (dia<1 || dia>31)){
	    		cout<<"digite un numero de dia valido para el mes\n";
	    		goto REGRESO1;
	    	}
			if((mes==4 || mes==6 || mes==9 || mes==11) && (dia<1 || dia>30)){
	    			cout<<"digite un numero de dia valido para el mes\n";
	    			goto REGRESO1;
			}
			if((mes==2) && (dia<1 || dia>28)){
					cout<<"digite un numero de dia valido para el mes\n";
	    			goto REGRESO1;
			}
		}else{
			cout<<"digite un numero de dia válido para el mes\n";
			goto REGRESO1;
		}

		REGRESO2:
		cout<<"ingrese anio: ";
    	cin>>year;
    	if(year<0){
    	cout<<"digite un anio valido\n";
    	goto REGRESO2;
    	}

	}
}
/*Metodo que retorna en un mensaje
toda la fecha en formato dia/mes/año
mediante el metodo to_string */
string Fecha::getFecha(){
    string f = to_string(dia) + "/" +
               to_string(mes) + "/" +
               to_string(year);
    return f;
}


