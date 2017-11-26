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
        CompaniaAerea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, vector<int> transaciones, vector<Cliente> clientesGolden);
        virtual ~CompaniaAerea();

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
