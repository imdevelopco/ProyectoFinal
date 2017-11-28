#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <ctime>
#include "Telefono.h"

using namespace std;

class Persona
{
    public:
        Persona();
        Persona(string primerNombre,string segundoNombre,string primerApellido,string segundoApellido, string direccion, string tipoDocumento, int numeroDocumento, Telefono numero, tm fechaNacimiento);
        virtual ~Persona();
        void crearPersona();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void setName(string nombre);
        void setLastName(string apellido);
        void setAddress(string direccion);
        void setTypeDocument(string type);
        void setNumDocument(int num);
        void setPhone(Telefono tel);
        void setBirthday(tm nacimiento);


        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        string getName();
        string getLastName();
        string getAddress();
        string getTypeDocument();
        int getNumDocument();
        Telefono getPhone();
        tm getBirthday();

    protected:
      string primerNombre,segundoNombre, primerApellido,segundoApellido, direccion;
      string tipoDocumento; // Opciones [CC, CE, PT, TI, RC]
      int numeroDocumento;
      Telefono numero;
      tm fechaNacimiento;

    private:

};

#endif // PERSONA_H
