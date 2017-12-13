#ifndef CLIENTE_H
#define CLIENTE_H
#include  "Persona.h"
#include <iostream>
#include <vector>

using namespace std;

class Cliente:public Persona
{
    public:
        Cliente();
        Cliente(string _primerNombre, string _segundoNombre, string _primerApellido, string _segundoApellido, string _direccion, string _tipoDocumento, int _numeroDocumento, Telefono number, tm BornDate, bool golden);
        virtual ~Cliente();

        /* Setters*/

        void setFirstName(string nombre);
        void setSecondName(string nombre);
        void setFirstLastName(string apellido);
        void setSecondLastName(string apellido);
        void setAddress(string direccion);
        void setTypeDocument(string type);
        void setNumDocument(int num);
        void setPhone(Telefono tel);
        void setBirthday(tm nacimiento);
        void addTiquete(int id);
        void setGolden(bool gold);

        /* Getters */

        string getName();
        string getLastName();
        string getAddress();
        string getTypeDocument();
        int getNumDocument();
        Telefono getPhone();
        tm getBirthday();
        bool getGolden();



    protected:

    private:
      string primerNombre,segundoNombre, primerApellido,segundoApellido, direccion;
      string tipoDocumento; // Opciones [CC, CE, PT, TI, RC]
      int numeroDocumento;
      Telefono numero;
      tm fechaNacimiento;
      vector<int> tiquetes;
      bool golden;

};

#endif // CLIENTE_H
