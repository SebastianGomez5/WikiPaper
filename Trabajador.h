/* Clase trabajador:
encargada de poder gestionar diferentes activades
con informacion de usuarios
*/

#ifndef TRABAJADOR_H
#define TRABAJADOR_H
#include"Producto.h"
#include"Proveedor.h"
#include"Cliente.h"
#include"Caja.h"
#include <iostream>
using namespace std;
//implementacion de la herencia
class Trabajador: public Caja, public Proveedor, public Cliente, public Producto
{
    public:
        //declaracion de metodos en la parte publica
        Trabajador();
        virtual ~Trabajador();

        void login(); //El login
        void ValoresDefecList(); //Acomoda los valores por defecto el vector
        void menuTrabajador(string,string); //Menu que tendrá la clase

    protected:

        //Declaracion de metodos set y demas en la parte protegida
        void setNomUsuario();
        void setContrasena();

        void setNom();
        void setApe();
        void setSexo();
        void setEdad();
        void setNumId();
        void setCargo();
        void setSalario();
        void setCiuda();
        void setActivo(string,string);//Cambiara activo = false
        void setValoresDefecto(string, string, string, string,string,
        /*Creará valores por defecto */ long, int, int, bool,string,string);

        void CreaUsuario(string,string);
        void BuscarUsuario(string,string);
        void ActualizarUsuario(string,string); //Actualizar informacion
        void VerUsuarios(string,string); //Para ver un listado general
        void EliminarUsuario(string,string); //Lo pone en activo = false

        //Declaracion de metodos get que retornan valores
        string getNom();
        string getApe();
        string getSexo();
        int getEdad();
        long getNumId();
        long getCod();
        string getTel();
        string getCargo();
        string getCiuda();
        string getActivo();
        int getSalario();

        //Para el login
        string getNomUsuario();
        string getContrasena();

        //Atributos para el login
        string usuario, password, TipoUsuario;
        int contador; //Para el login
        bool ingresa;

    private:
        //Declaracion de atributos de la clase en la parte privada
        string nombre, apellido, sexo, cargo, ciudad,nomUsuario,contra;
        long cod, numId;
        int salario, edad;
        bool activo;

};

#endif // TRABAJADOR_H

