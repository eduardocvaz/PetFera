#include "Tratador.hpp"

#include <iostream>

Tratador::Tratador(string nome, string idade, string telefone, nivelSeguranca nivel):
                    Profissional(nome, idade, telefone),
                    nivel(nivel) {}

Tratador::~Tratador() {}

void Tratador::setNivel(nivelSeguranca nivel){
    this->nivel = nivel;
}

nivelSeguranca Tratador::getNivel() const{
    return this->nivel;
}


ostream& Tratador::imprimeDados(ostream& o) const{
    //implementar
    return o;
}