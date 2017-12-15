#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <string>
#include <cstring>
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
        Control(vector<Aeropuerto> aeropuertos, vector<AgenciaDeViaje> agencias, vector<Aerolinea> aerolineas, vector<Representante> representantes);
        virtual ~Control();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void crearAgencia();
        Aeropuerto createAirport(); //pide informacion por consola para crear un aeropueto, por ultimo la retorna
        void crearAerolinea(); //pide información al usuario por consola para crear una aerolinea
        void addAeroliaToAirport(); //muestra y pide infoemación al usuario para agregar aerolineas a un aeropuerto
        void setAvionesDeAerolinea();
        void venderTiket(); // SIN TERMINAR, SE NECESITAN OTROS METODOS
        void setFlota(); //pide información al usuario para establecer la flota de aviones de una aerolinea


        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        int getLastAgencyId(); //retorna el ultimo id+1 de las agencias, sirve para crear un id a una nueva agencia
        int getLastAerolineaId(); //retorna el ultimo id+1 de las aerolineas
        int getLatsAirportId(); //retorna el id más grande +1 de un aeropuerto
        int getLastTiketId(); //retorna un numero para ser usado como id de un tiquete
        int getPositionAeroline(int id); //retorna la posicion de una aerolinea en el vector de aerolines, se le pasa el id de la aerolinea
        int getPositionAgency(int id); //retorna la pocision en la que se encuenta una agencia en el vector de agencias
        int getPositionAirport(int id); //retorna la pocision en la qeu se encuentra un avion 
        Representante createRepesent(); //pide datos al usuario para crear un representante, por ultimo lo retorna
        Telefono createPhone(); //pide información al usuario para crear un numeo de telefono, lo retorna.
        void listRepresnts(); //lista los representantes
        void listAgencias(); //lista las agencias
        void listAerilineas(); //lista las aerolineas
        void listAirports(); //lista los aeropuertos.
        void listThisAerolineas(vector<Aerolinea> aerolineas); //lista las aerolineas que se le pasen por parametro
        bool existAirport(int id); //verifica si el id qeu se pase pertenece a un aeropuerto
        bool existAerolinea(int id); //verifica que el id que se le pase pertenesca a una aerolina, si es asi retorna true
        bool existAgencia(int id); //verifica si el id que se le pase pertenece a una agencia
        bool existAerolineaInThis(vector<Aerolinea> aerolineas, int id); //verifica si el id que se le pase por parametro este en el vector de aerolines que tambien se le pasa por parametro
        Aeropuerto getAirport(int id); //se le pasa un id de un aeropuierto y este metodo retorna dicho Aeropuerto
        Aerolinea getAeroline(int id); //se le pasa el id de una aerolinea y este metodo lo retorna;
        AgenciaDeViaje getAgencia(int id); //se le pasa un id de una agencia y retorna esa agencia
        vector<Silla> createSilla(string tipo); //retorna un vactor de sillas de el tipo que se le pase
        Avion createPlain(); //crea un avion y lo retorna
        int listaDeVuelosDisponibles(int aerolinea_id, Cliente client); //muestra la lista de vuelos disponibles
        int getVariacionPrecio(int base, string tipo);
        vector<string> getCytiesOrigenFl(vector<Avion> flota);


        void crearClientes();


    protected:

    private:
      vector<AgenciaDeViaje> agencias;
      vector<Aerolinea> aerolineas;
      vector<Representante> representantes;
      vector<Aeropuerto> aeropuertos;
      vector<Tiquete> tiquetes;
};

#endif // CONTROL_H
