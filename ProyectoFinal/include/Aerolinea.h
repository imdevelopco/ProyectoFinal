#ifndef AEROLINEA_H
#define AEROLINEA_H
#include <iostream>
#include <vector>
#include <CompaniaAerea.h>
#include "Avion.h"

using namespace std;

class Aerolinea : public CompaniaAerea
{
    public:
        Aerolinea();
        Aerolinea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, string matriculaAerea);
        virtual ~Aerolinea();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void setMatricula(string matricula);
        void setTotalPlains(int total);
        void setFlota(vector<Avion> flota);
        string sellTicket(string tipoSilla, int id_avion, int precio);

        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        string getMatricula();
        int getTotal();
        vector<Avion> getFlota();
        void administrarAviones();
        vector<string> getCytiesOrigenFl();
        void showVuelosDisponibles(string cyti);
        int showVuelosDisponibles(string cyti, bool golden);
        bool verifyDisponiilidad(int pos);
        void imprimirTicket(int id_avion, string num_silla, int precio);
        string getOrigenPlain(int pos); //retorna el nombre del aeropuerto de origen, del avion que se encuentre en la posicion que s epase por parametro
        string getDestinoPlain(int pos);
    protected:

    private:
      string matriculaAerea;
      int totalAvionesFlota;
      vector<Avion> flota;
};

#endif // AEROLINEA_H
