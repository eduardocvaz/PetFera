#include "nativo.hpp"

Nativo::Nativo(string estado):
            estado(estado){}

string Nativo::getEstado() const
{
    return this->estado;
}