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
        Aerolinea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, string matriculaAerea, int totalAvionesFlota, vector<int> aeropuertos);
        virtual ~Aerolinea();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void setMatricula(string matricula);
        void setTotalPlains(int total);
        void setFlota(vector<Avion> flota);

        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        string getMatricula();
        int getTotal();
        vector<Avion> getFlota();
        void administrarAviones();
    protected:

    private:
      string matriculaAerea;
      int totalAvionesFlota;
      vector<int> aeropuertos; //ids de los aeropuertos a los que puede viajar la aerolinea
      vector<Avion> flota;
};

#endif // AEROLINEA_H
