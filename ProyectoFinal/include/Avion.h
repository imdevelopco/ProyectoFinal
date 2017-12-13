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
        Avion(vector<Silla> preferencial, vector<Silla> normal, vector<Silla> bajoCosto, string matricula, Aeropuerto origen, Aeropuerto destino, int cantidadGasolina, int tiempoMaximo, int precioSillaNormal);
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
        void setPrecioSillNormal(int precio);
        //Settea los valores por defecto de una instancia de la Clase avion
        void llenarDatos();
        //establece un silla como vendida (ocupada)
        string ocuparSilla(string tipo);

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
        int getPrecioNormal();
        // Retorna la cantidad de sillas disponibles, sin tener en cuenta el tipo de silla
        int getSillasDisponibles();
        // Retorna la cantidad de sillas disponibles por categoria
        void getSillasDisponiblesPorCategoria();
        //retorna el total de sillas disponiblrs de un tipo en particular
        int getTotalBy(string tipoSilla);


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
      int precioSillaNormal;
};

#endif // AVION_H
