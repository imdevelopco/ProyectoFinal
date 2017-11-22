#ifndef REPRESENTANTE_H
#define REPRESENTANTE_H
#include <iostream>
#include <ctime>
#include "Persona.h"
using namespace std;

class Representante : public Persona
{
    public:
        Representante();
        Representante(string nombreCompleto, string apellidoCompleto, string direccion, string tipoDocumento, int numeroDocumento, Telefono numero, tm fechaNacimiento);
        virtual ~Representante();

    protected:

    private:
};

#endif // REPRESENTANTE_H
