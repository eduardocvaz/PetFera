#include "Veterinario.hpp"

#include <iostream>

Veterinario::Veterinario(string nome, string idade, string telefone, string cod_CRMV):
                        Profissional(nome, idade, telefone),
                        cod_CRMV(cod_CRMV) {}

Veterinario::~Veterinario() {}

void Veterinario::setCRMV(string cod_CRMV){
    this->cod_CRMV = cod_CRMV;
}

string Veterinario::getCRMV() const{
    return this->cod_CRMV;
}

ostream& Veterinario::imprimeDados(ostream& o) const{
    //implementar
    return o;
}