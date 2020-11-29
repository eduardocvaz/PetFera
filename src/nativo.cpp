#include "nativo.hpp"

Nativo::Nativo(string estado):
            estado(estado){}

Nativo::~Nativo() {}

string Nativo::getEstado() const
{
    return this->estado;
}

void Nativo::setEstado(string estado){
    this->estado = estado;
}