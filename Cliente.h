/* Clase Cliente
Encargada de poder realizar diferentes actividades
con la informacion de los clientes

*/
#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>
using namespace std;


class Cliente
{
    public:
        //Declaracion de metodos en la parte publica
        Cliente();
        virtual ~Cliente();
        void ValoresDefecList();
        void menuCliente(string,string);


    protected:
        //Declarar metodos en la parte protegida

        void setNom(); //Pide nombre
        void setApe(); //Pide apellido
        void setNumId(); //Pide id
        void setCod(); //efectua cod = id
        void setTel(); //Pide telefono
        void setCiu(); //Pide ciudad
        void setTipo(); //Pide tipo de cliente
        void setNomEmpre(); //Pide nombre de la empresa
        void setActivo(string,string); //Para poner un cliente en 'No activo'
        void creacliente(string,string); //para crear un cliente
        void BuscaCliente(string,string); //Para buscar cliente
        void mostrarcliente(string,string); //Para mostrar todos los datos de los clientes
        void actualizadatos(string,string); //Para actualizar datos de clientes
        void EliminaCliente(string,string); //Para eliminar cliente
        void setValoresDefecto(string, string,string, //Para crear valores por defecto
                    long, bool, string, string, string);


        string getNom(); //Retorna nombre
        string getApe(); //Retorna apellido
        long getCod(); //Retorna codigo
        long getNumId(); //Retorna numero id
        string getTel(); //Retorna telefono
        string getCiu(); //Retorna ciudad
        string getTipo(); //Retorna el tipo de cliente
        string getNomEmpre(); //nombre de la empresa
        string getActivo(); //Retorna el estado


    private:
        //Declaracion de atributos en parte protegida
        string nombre, apellido, ciudad, tipoCliente,nomEmpresa, tel;
        bool activo;
        long cod, Id;
};

#endif // CLIENTE_H
