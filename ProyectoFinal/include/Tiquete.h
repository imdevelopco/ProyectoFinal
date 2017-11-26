#ifndef TIQUETE_H
#define TIQUETE_H
#include <iostream>
#include "Aeropuerto.h"
#include "Aerolinea.h"
#include "Avion.h"
#include "Silla.h"
#include "Cliente.h"


using namespace std;

class Tiquete
{
    public:
        Tiquete();
        Tiquete(int id, Aeropuerto origen,Aeropuerto destino,int numeroTiquerte,Aerolinea aerolines,Avion avion,Silla silla,string estado,Cliente cliente);
        virtual ~Tiquete();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void setOrigen(Aeropuerto origen);
        void setDestinity(Aeropuerto des);
        void setTiquetNumber(int num);
        void setAerolinea(Aerolinea aero);
        void setAirplain(Avion Airplain);
        void setChair(Silla silla);
        void setStatus(string status);
        void setCliente(Cliente cliente);

        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        Aeropuerto getOrigen();
        Aeropuerto getDestinity();
        int getTiquetNumber();
        Aerolinea getAerolinea();
        Avion getAirplain();
        Silla getChair();
        string getStatus();
        Cliente getCliente();


    protected:

    private:
      int id;
      Aeropuerto origen;
      Aeropuerto destino;
      int numeroTiquerte;
      Aerolinea aerolines;
      Avion avion;
      Silla silla;
      string estado;
      Cliente cliente;
};

#endif // TIQUETE_H
