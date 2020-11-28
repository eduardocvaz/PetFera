#include "nativo.hpp"

nativo::nativo(string estado):
            estado(estado){}

nativo::string getEstado() const;
{
    return this->estado;
}