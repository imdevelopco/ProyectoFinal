#ifndef AVION_H
#define AVION_H
#include <iostream>
#include <vector>
#include "Silla.h"
#include "Aeropuerto.h"

using namespace std;

class Avion
{
    public:
        Avion();
        Avion(vector<Silla> preferencial, vector<Silla> normal, vector<Silla> bajoCosto, string matricula, Aeropuerto origen, Aeropuerto destino, int cantidadGasolina, int tiempoMaximo);
        virtual ~Avion();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void setSillasPreferencial(vector<Silla> sillas);
        void setSillasNormal(vector<Silla> sillas);
        void setSillasBajoCosto(vector<Silla> sillas);
        void setMatricula(string matricula);
        void setStatus(string status);
        void setTotalDisponiblePreferencial(int tot);
        void setTotalDisponibleNormal(int tot);
        void setTotalDisponibleBajo(int tot);
        void setAeropuertoOrigen(Aeropuerto origen);
        void setAeropuertoDestino(Aeropuerto destino);
        void setCantidadGasolina(int cant);
        void setTiempoMaximo(int tiempo);
        //Settea los valores por defecto de una instancia de la Clase avion
        void llenarDatos();

        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        vector<Silla> getSillasPreferencial();
        vector<Silla> getSillasNormal();
        vector<Silla> getSillasBajoCosto();
        string getMatricula();
        string getStatus();
        int getTotalDisponiblePreferencial();
        int getTotalDisponibleNormal();
        int getTotalDisponibleBajo();
        Aeropuerto getAeropuertoOrigen();
        Aeropuerto getAeropuertoDestino();
        int getCantidadGasolina();
        int getTiempoMaximo();
        // Retorna la cantidad de sillas disponibles, sin tener en cuenta el tipo de silla
        int getSillasDisponibles();
        // Retorna la cantidad de sillas disponibles por categoria
        string getSillasDisponiblesPorCategoria();


    protected:

    private:
      vector<Silla> preferencial;
      vector<Silla> normal;
      vector<Silla> bajoCosto;
      string matricula;
      string estado;
      int disponiblePreferencial;
      int disponibleNormal;
      int disponibleBajoCosto;
      Aeropuerto origen;
      Aeropuerto destino;
      int cantidadGasolina;
      int tiempoMaximo;
};

#endif // AVION_H
