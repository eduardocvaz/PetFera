#include "exotico.hpp"

exotico::exotico(string pais_origem):
            pais_origem(pais_origem){}

exotico::string getPais_origem() const;
{
    return this->pais_origem;
}