/* Clase proveedor:
encargada de poder gestionar diferentes activades
con informacion de proveedores
*/
#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include<iostream>
using namespace std;


class Proveedor
{
    public:
        //Declaracion de metodos en la parte publica
        Proveedor();
        virtual ~Proveedor();

        void ValoresDefecList();
        void menuProveedor(string,string); //2 string equivalentes a nombres y apellidos



    protected:
        //Declaracion de metodos set y demas en la parte protegida
        void set_nom();
        void set_ape();
        void set_empre();
        void set_prod();
        void set_cod();
        void set_tel();
        void set_activo(string, string); //Para poner ' activo'
        void CreaProveedor(string,string);
        void BuscarProveedor(string,string);
        void ActualizarDatos(string,string);
        void VerProveedors(string,string);
        void EliminaProveedor(string,string);
        void setValoresDefecto(string, string, string, string,string,
        /*Creará valores por defecto */ long, bool);

        string get_nom();
        string get_ape();
        string get_empre();
        string get_prod();
        long get_cod();
        string get_tel();
        string getActivo();


    private:
        //Declaracion de atributos en la parte privada
        string nombre, apellido, empresa, producto, tel;
        long cod;
        bool activo;
};

#endif // PROVEEDOR_H
