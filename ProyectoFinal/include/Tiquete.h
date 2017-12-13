#ifndef TIQUETE_H
#define TIQUETE_H
#include <iostream>
#include "Aeropuerto.h"
#include "Aerolinea.h"
#include "Avion.h"
#include "Cliente.h"


using namespace std;

class Tiquete
{
    public:
        Tiquete();
        Tiquete(int id, Aeropuerto origen,Aeropuerto destino,int numeroTiquerte,Aerolinea aerolines,Avion avion,string silla,string estado,Cliente cliente);
        virtual ~Tiquete();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void setId(int id);
        void setOrigen(Aeropuerto origen);
        void setDestinity(Aeropuerto des);
        void setTiquetNumber(int num);
        void setAerolinea(Aerolinea aero);
        void setAirplain(Avion airplain);
        void setChair(string silla);
        void setStatus(string status);
        void setCliente(Cliente cliente);

        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        int getId();
        Aeropuerto getOrigen();
        Aeropuerto getDestinity();
        int getTiquetNumber();
        Aerolinea getAerolinea();
        Avion getAirplain();
        string getChair();
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
      string silla;
      string estado; // "No check" || Check in" 
      Cliente cliente;
};

#endif // TIQUETE_H
