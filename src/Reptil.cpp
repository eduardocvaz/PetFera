#include "Reptil.hpp"

Reptil::Reptil(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,bool peconheto,string tipo_veneno):
                Animal(sexo,tamanho,peso,nome,nome_cientifico,alimentacao,extinto,peconheto,tipo_veneno) {}

Reptil::~Reptil() {}


ostream& Reptil::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

