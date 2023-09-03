/* Clase producto
encargada de realizar activades relacionadas
con los datos de los productos de la empresa
*/
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<iostream>
using namespace std;

class Producto
{
    public:
        //Declara metodos y atributo en la parte publica
        Producto();
        virtual ~Producto();
        string TipoUsuario;
        void ValordefectoList(); //Valor por defecto a las listas.
        void menuProducto(string,string,string); /*Tres strings equivalentes a el tipo de usuari
                                                    nombre y apellido*/
    protected:
        void setNomb(); //Pide nombre
        void setMarca(); //Pide marca
        void setUnidad(); //Pide unidad
        void setEspecifi(); //Pide especificaciones
        void setCod(); //Pide codigo
        void setPrecio(); //Pide precio
        void setCantidad(); //Pide cantidad a añadir
        void setActivo(string);
        void setValoresDefect(string,string,string,string,long,long,int,bool); //asigna valores pordefec
        void creaProduc(string,string); //crear producto
        void cantProduc(string,string); //Ver cantidad
        void verPreciosProd(string,string); //Ver precios
        void verProductos(string,string); //Se refiere a todos los productos
        void buscarProducto(string,string); //Buscar por codigo
        void ActualizarProducto(string,string); //actualizar datos
        void EliminaProducto(string,string); //Para eliminar productos


        //Declaracion de metodos get que retornan diferentes valores
        string getNomb();
        string getMarca();
        string getUnidad();
        string getEspecifi();
        string getActivo();
        long getCod();
        long getPrecio();
        int getCantidad();

    private:
        //Atributos declarados en la parte privada
        string nombre, marca, unidad, especificaciones;
        long cod, precio;
        int cantidad;
        bool activo;
};

#endif // PRODUCTO_H
