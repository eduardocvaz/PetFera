#include "exotico.hpp"

Exotico::Exotico(string pais_origem):
            pais_origem(pais_origem){}

Exotico::~Exotico() {}

string Exotico::getPais_origem() const
{
    return this->pais_origem;
}

void Exotico::setPais_origem(string pais_origem){
    this->pais_origem = pais_origem;
}