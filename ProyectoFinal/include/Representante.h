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
        Representante(string _primerNombre, string _segundoNombre, string _primerApellido, string _segundoApellido, string _direccion, string _tipoDocumento, int _numeroDocumento, Telefono number, tm BornDate);
        virtual ~Representante();

    protected:

    private:
};

#endif // REPRESENTANTE_H
