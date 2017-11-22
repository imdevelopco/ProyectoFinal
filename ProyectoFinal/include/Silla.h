#ifndef SILLA_H
#define SILLA_H
#include <iostream>

using namespace std;

class Silla
{
    public:
        Silla();
        Silla(string numero, string tipo);
        virtual ~Silla();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void setNumber(string num);
        void setType(string tipo);

        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        string getNumber();
        string getType();
    protected:

    private:
      string numero;
      string tipo; // opciones ["preferencial", "normal", "bajoCosto"]
};

#endif // SILLA_H
