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
        CompaniaAerea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, vector<Cliente> clientesGolden);
        CompaniaAerea(int _id,string _nit,string _razonSocial,string _direccion,string _paginaWeb,Representante representante);
        virtual ~CompaniaAerea();
        /* Getters*/
        string getNit();
        string getRazonSocial();
        string getDireccion();
        string getPaginaWeb();

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
      vector<Cliente> clientesGolden;
};
#endif // COMPANIAAEREA_H
