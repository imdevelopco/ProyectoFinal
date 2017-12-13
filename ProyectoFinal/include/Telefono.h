#ifndef TELEFONO_H
#define TELEFONO_H
#include <iostream>

using namespace std;

class Telefono
{
    public:
        Telefono();
        Telefono(string tipo, int indicativo, int numero);
        virtual ~Telefono();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void setType(string type);
        void setIndicativo(int indicativo);
        void setNumber(int num);


        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        string getType();
        int getIndicativo();
        int getNumber();

        /* Crear Telefonos por pantalla*/

        void llenarTelefono();
    protected:

    private:
      string tipo;
      int indicativo;
      int numero;
};

#endif // TELEFONO_H
