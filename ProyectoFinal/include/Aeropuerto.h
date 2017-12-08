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
        Aeropuerto(int _id,string _nombre,string _abreviatura,int _totalAvionesOperacion, int _volumenMaximoPersonas, vector<Aerolinea> aerolineas, vector<Aeropuerto> aeropuertosDestino);
        virtual ~Aeropuerto();
        /* Setters */
        void setNombre(string nuevoNombre);
        void setAbreviatura(string nuevoAbreviatura);
        void setFlotaAviones(int nuevaCantidad); // seter de totalAvionesOperacion
        void setAerolineas(vector<Aerolinea> aerolineas);
        void setVolumenMaximoPersonas(int nuevaCantidad);
        void setAeropuertosDestino(vector<Aeropuerto> aeropuertos);
        void addAerolinea(Aerolinea aerolinea); //agreh¿ga una aerolinea al vector aerolineas
        /* Getters */
        int getId();
        string getNombre ();
        string getAbreviatura();
        int getCantidadFlota ();
        vector<Aerolinea> getAerolineas();
        int getMaximoPersonas ();
        vector<Aeropuerto> getAeropuertosDestino();
        bool verifyIfAerolineExist(int id); //retorna true si una aerolinea ya esta en el vactor de aerolineas

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
