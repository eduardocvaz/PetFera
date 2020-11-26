#include "PetFera.h"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstring>

PetFera::PetFera(string telefone, string endereco):
                telefone(telefone), endereco(endereco) {}

PetFera::~PetFera() {
    for (auto& animal : this->animais)
    {
        delete animal;
    }

    for (auto& profissional : this->profissionais)
    {
        delete profissional;
    }
}

string PetFera::getTelefone() const {
    return this->telefone;
}

string PetFera::getEndereco() const {
    return this->endereco;
}

vector<Animal*> PetFera::getAnimais() const{
    return this->animais;
}

vector<Profissional*> PetFera::getProfissionais() const{
    return this->profissionais;
}








