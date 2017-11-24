#ifndef AEROLINEA_H
#define AEROLINEA_H
#include <iostream>
#include <vector>
#include "CompaniaAerea.h"
#include "Representante.h"
#include "Tiquete.h"
#include "Telefono.h"
#include "Cliente.h"
#include "Aeropuerto.h"

using namespace std;

class Aerolinea : public CompaniaAerea
{
    public:
        Aerolinea();
        Aerolinea(string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, vector<Tiquete> transaciones, vector<Cliente> clientesGolden, string matriculaAerea, int totalAvionesFlota, vector<Aeropuerto> aeropuertos);
        virtual ~Aerolinea();

    protected:

    private:
      string matriculaAerea;
      int totalAvionesFlota;
      vector<Aeropuerto> aeropuertos;

};

#endif // AEROLINEA_H
