#include "Anfibio.hpp"

Anfibio::Anfibio(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto):
                Animal(sexo,tamanho,peso,nome,nome_cientifico,alimentacao,extinto) {}

Anfibio::~Anfibio() {}


ostream& Anfibio::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

