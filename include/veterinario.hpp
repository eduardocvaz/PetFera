#pragma once

#include "profissional.hpp"

#include <string>
#include <iostream>

using std::string;

class Veterinario : public Profissional {
private:
    string cod_CRMV;
public:
    Veterinario(string nome, string idade, string telefone, string cod_CRMV);
    ~Veterinario();

    void setCRMV(string cod_CRMV);
    string getCRMV() const;

    friend ostream& operator<< (ostream& o, Veterinario& p);
    ostream& imprimeDados(ostream& o) const;
};