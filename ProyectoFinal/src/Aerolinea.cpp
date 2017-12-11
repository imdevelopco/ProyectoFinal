#include "Aerolinea.h"

Aerolinea::Aerolinea()
{
    //ctor
}

Aerolinea::Aerolinea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, string matriculaAerea, int totalAvionesFlota, vector<int> aeropuertos):CompaniaAerea(id, nit, razonSocial, direccion, paginaWeb, agenda, representante){
  this->matriculaAerea     = matriculaAerea;
  this->totalAvionesFlota  = totalAvionesFlota;
  this->aeropuertos        = aeropuertos;
}

Aerolinea::~Aerolinea()
{
    //dtor
}

/* +───────────────────────────────────────────────────────────────────────+ */
/*       /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$   /$$$$$$         */
/*		 /$$__  $$| $$_____/|__  $$__/| $$_____/| $$__  $$ /$$__  $$         */
/*		| $$  \__/| $$         | $$   | $$      | $$  \ $$| $$  \__/         */
/*		|  $$$$$$ | $$$$$      | $$   | $$$$$   | $$$$$$$/|  $$$$$$          */
/*		 \____  $$| $$__/      | $$   | $$__/   | $$__  $$ \____  $$         */
/*		 /$$  \ $$| $$         | $$   | $$      | $$  \ $$ /$$  \ $$         */
/*		|  $$$$$$/| $$$$$$$$   | $$   | $$$$$$$$| $$  | $$|  $$$$$$/         */
/*		 \______/ |________/   |__/   |________/|__/  |__/ \______/          */
/* +───────────────────────────────────────────────────────────────────────+ */
/*Establece la matricula aerea de la aerolinea*/

void Aerolinea::setMatricula(string matricula){
  this->matriculaAerea = matricula;
}

/*Establece el total de aviones de la aerolinea*/

void Aerolinea::setTotalPlains(int total){
  this->totalAvionesFlota = total;
}

/*Establece la flota de aviones*/
void Aerolinea::setFlota(vector<Avion> flota){
  this->flota = flota;
}


/* +───────────────────────────────────────────────────────────────────────+ */
/*	      /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$   /$$$$$$ 	       */
/*       /$$__  $$| $$_____/|__  $$__/| $$_____/| $$__  $$ /$$__  $$		     */
/*      | $$  \__/| $$         | $$   | $$      | $$  \ $$| $$  \__/		     */
/*      | $$ /$$$$| $$$$$      | $$   | $$$$$   | $$$$$$$/|  $$$$$$  		     */
/*      | $$|_  $$| $$__/      | $$   | $$__/   | $$__  $$ \____  $$		     */
/*      | $$  \ $$| $$         | $$   | $$      | $$  \ $$ /$$  \ $$		     */
/*      |  $$$$$$/| $$$$$$$$   | $$   | $$$$$$$$| $$  | $$|  $$$$$$/         */
/*       \______/ |________/   |__/   |________/|__/  |__/ \______/          */
/* +───────────────────────────────────────────────────────────────────────+ */
/*Retorna la matricula de la aerolinea*/
string Aerolinea::getMatricula(){
  return this->matriculaAerea;
}

/*Retorna el total de aviones de la aerolinea*/
int Aerolinea::getTotal(){
  return this->totalAvionesFlota;
}

/*Retorna la flota de aviones*/
vector<Avion> Aerolinea::getFlota(){
  return this->flota;
}
//Entrada: void
//Salida: void
//Funcion: Dependiendo de lo que quiera el usuario, este metodo sera capaz
// de eliminar, agregar  aviones a determinada flota de y tambien cambiar el tamno de
//la flota en general
// Autor: Carlos Andres Cordoba Ramos
void Aerolinea::administrarAviones()
{
    int decision;
    Avion
    do{
            cout<<"Que deseas hacer?"<<endl;
            cout<<"1.reducir el tamano de la flota"<<endl;
            cout<<"2.eliminar un avion de la flota"<<endl;
            cout<<"3.agregar un avion a la flota"<<endl;
            cin>>decision;
    }while((decision != 1)&&(decision != 2)&&(decision != 3));
    switch(decision){

    case 1:{
    int reductor;
    cout<<"cuantos aviones quiere que tenga la flota?"<<endl;
    cin>>reductor;
    flota.resize(reductor);
    };
    break;
    case 2:{
            string matricula;
            bool noEsta = false;
            cout<<"Digita la matricula del avion que quieres eliminar"<<endl;
            cin>>matricula;
            for (int i=0;i<flota.size();i++)
            {
                if(matricula == flota[i].getMatricula())
                {
                    flota.erase(flota.begin()+i);
                    cout<<"Se ha eliminado el avion de la flota"<<endl;
                }else{
                  noEsta=true;
                }
            }
            if(noEsta == true)
            {
                cout<<"No se ha encontrado el avion en la flota"<<endl;
            }
        };
    break;
    case 3:{};
    break;

    }


}
