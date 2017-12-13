#ifndef COMPANIAAEREA_H
#define COMPANIAAEREA_H
#include <iostream>
#include <vector>
#include "Telefono.h"
#include "Representante.h"
#include "Cliente.h"


using namespace std;

class CompaniaAerea
{
    public:
        CompaniaAerea();
        CompaniaAerea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante);
        CompaniaAerea(int _id,string _nit,string _razonSocial,string _direccion,string _paginaWeb,Representante representante);
        virtual ~CompaniaAerea();

        /* Setters */
        void addTransacion(int id); //agrega un id de tiquete a las transaciones
        void addClient(Cliente client);
        void tiketToClient(int tiket_id, int pos_client); //le pone el tiquete a un cliente

        /* Getters*/
        int getId();
        string getNit();
        string getRazonSocial();
        string getDireccion();
        string getPaginaWeb();
        vector<Cliente> getClients();
        void listClients(); //lsita los clientes;
        bool clientExist(int pos);


    protected:

    private:
      int id;
      string nit;
      string razonSocial;
      string direccion;
      string paginaWeb;
      vector<Telefono> agenda;
      Representante representante;
      vector<int> transaciones; //guarda los ids de los tiquetes, de esta forma conocemos las transaciones
      vector<Cliente> clientesTotal;
};
#endif // COMPANIAAEREA_H
