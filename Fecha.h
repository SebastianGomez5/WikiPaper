//Clase fecha, encargada de solicitar fecha
#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
    public:
        //Declaracion de atributos
        int dia, mes, year;
        Fecha();
        virtual ~Fecha();

        //declaracion de metodos set y get
        void setFecha();
        string getFecha();

    protected:

    private:
};

#endif // FECHA_H
