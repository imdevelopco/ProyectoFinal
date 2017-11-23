#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include <iostream>
#include <vector>
#include "Aerolinea.h"

using namespace std;

class Aeropuerto
{
    public:
        Aeropuerto();
        virtual ~Aeropuerto();

    protected:

    private:
      string nombre;
      string abreviatura;
      int totalAvionesOperacion;
      vector<Aerolinea> aerolineas;
      int volumenMaximoPasajeros;
      vector<Aeropuerto> aeropuertosDestino;
};

#endif // AEROPUERTO_H
