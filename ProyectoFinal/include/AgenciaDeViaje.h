#ifndef AGENCIADEVIAJE_H
#define AGENCIADEVIAJE_H
#include <vector>
#include <iostream>
#include "Representante.h"
#include "Telefono.h"
#include "CompaniaAerea.h"
#include "Cliente.h"

using namespace std;

class AgenciaDeViaje:public CompaniaAerea
{
    public:
        AgenciaDeViaje();
        AgenciaDeViaje(int _id,string _nit,string _razonSocial,string _direccion,string _paginaWeb, vector<Telefono> agenda, Representante representante);
        virtual ~AgenciaDeViaje();
        /* Getters*/

    protected:

    private:

};

#endif // AGENCIADEVIAJE_H
