#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include <iostream>
#include <vector>
#include "Aerolinea.h"


using namespace std;

class Aeropuerto
{
    public:
        /* Constructores */
        Aeropuerto();
        Aeropuerto(int _id,string _nombre,string _abreviatura,int _totalAvionesOperacion, int _volumenMaximoPersonas);
        virtual ~Aeropuerto();
        /* Setters */
        void setNombre(string nuevoNombre);
        void setAbreviatura(string nuevoAbreviatura);
        void setFlotaAviones(int nuevaCantidad);
        void setVolumenMaximoPersonas(int nuevaCantidad);
        /* Getters */
        int getId();
        string getNombre ();
        string getAbreviatura();
        int getCantidadFlota ();
        int getMaximoPersonas ();

    protected:

    private:
      int id; //id unico del aeropuerto
      string nombre;
      string abreviatura;
      int totalAvionesOperacion;
      vector<Aerolinea> aerolineas;
      int volumenMaximoPersonas;
      vector<Aeropuerto> aeropuertosDestino;
};

#endif // AEROPUERTO_H
