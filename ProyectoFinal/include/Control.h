#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <string>
#include <vector>
#include "Aerolinea.h"
#include "Aeropuerto.h"
#include "AgenciaDeViaje.h"
#include "Avion.h"
#include "Cliente.h"
#include "Representante.h"
#include "Silla.h"
#include "Telefono.h"
#include "Tiquete.h"

using namespace std;

class Control
{
    public:
        Control();
        Control(vector<Aeropuerto> aeropuertos, vector<AgenciaDeViaje> agencias, vector<Aerolinea> aerolineas);
        virtual ~Control();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void crearAgencia();
        Aeropuerto createAirport(); //pide informacion por consola para crear un aeropueto, por ultimo la retorna
        void crearAerolinea(); //pide información al usuario por consola para crear una aerolinea
        void addAeroliaToAirport(); //muestra y pide infoemación al usuario para agregar aerolineas a un aeropuerto
        void setAvionesDeAerolinea();
        void venderTiket();

        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        int getLastAgencyId(); //retorna el ultimo id+1 de las agencias, sirve para crear un id a una nueva agencia
        int getLastAerolineaId(); //retorna el ultimo id+1 de las aerolineas
        int getLatsAirportId(); //retorna el id más grande +1 de un aeropuerto
        Representante createRepesent(); //pide datos al usuario para crear un representante, por ultimo lo retorna
        Telefono createPhone(); //pide información al usuario para crear un numeo de telefono, lo retorna.
        void listRepresnts(); //lista los representantes
        void listAgencias(); //lista las agencias
        void listAerilineas(); //lista las aerolineas
        void listAirports(); //lista los aeropuertos.
        bool existAirport(int id); //verifica si el id qeu se pase pertenece a un aeropuerto
        bool existAerolinea(int id); //verifica que el id que se le pase pertenesca a una aerolina, si es asi retorna true
        bool existAgencia(int id); //verifica si el id que se le pase pertenece a una agencia
        Aeropuerto getAirport(int id); //se le pasa un id de un aeropuierto y este metodo retorna dicho Aeropuerto
        Aerolinea getAeroline(int id); //se le pasa el id de una aerolinea y este metodo lo retorna;




    protected:

    private:
      vector<AgenciaDeViaje> agencias;
      vector<Aerolinea> aerolineas;
      vector<Representante> representantes;
      vector<Aeropuerto> aeropuertos;
};

#endif // CONTROL_H
