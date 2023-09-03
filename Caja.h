/* Clase caja
Encargada de manejar el flujo de dinero
En este archivo se declaran los metodos y atributos
a usar, junto con sus respectivos modificadores de acceso.
*/
#ifndef CAJA_H
#define CAJA_H
#include"Fecha.h"

#include <iostream>
using namespace std;

class Caja
{
    public: //Metodos en la parte publica
        Caja();
        virtual ~Caja();
        void ValoresDefecList(); //Para crear valores por defecto y meterlos al vector
        void menuCaja(string,string); //Funcion que basicamente es el menú.

    protected:
        //Metodos protegidos
        //Declaracion de metodos set y otras acciones a usar.
        void setConsignar(); //Pide el valor a consignar
        void setFechaConsignar(); //Pide fecha de consignacion
        void setRetirar(); //Pide valor a retirar
        void setFechaRetirar(); //Pide fecha de retiro
        void consigna(string,string); //Funcion para consignar dinero
        void retirar(string,string); //Funcion para retirar dinero
        void ConsultarDinero(string,string); //Funcion para consultar dinero en cuenta

        //Metodos get que retornen valores
        long getSaldo();
        long getConsignar();
        string getFechaConsignar();
        long getRetirar();
        string getFechaRetiro();

    private:
        //Atributos en parte privada
        long cantidadRe, cantidadCo, saldo;
        //Composicion hecha por la clase fecha.
        Fecha fecha_consignar;
        Fecha fecha_retirar;
};

#endif // CAJA_H
