#include "exotico.hpp"

Exotico::Exotico(string pais_origem):
            pais_origem(pais_origem){}

string Exotico::getPais_origem() const
{
    return this->pais_origem;
}