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
        virtual ~Control();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void crearAgencia();


        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        int getLastAgencyId(); //retorna el ultimo id+1 de las agencias, sirve para crear un id a una nueva agencia
        Representante createRepesent(); //pide datos al usuario para crear un representante, por ultimo lo retorna
        Telefono createPhone(); //pide información al usuario para crear un numeo de telefono, lo retorna.
        void listRepresnts(); //lista los representantes
        void listAgencias(); //lista las agencias

    protected:

    private:
      vector<AgenciaDeViaje> agencias;
      vector<Aerolinea> aerolineas;
      vector<Representante> representantes;
};

#endif // CONTROL_H
