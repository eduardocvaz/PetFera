#include "Anfibio.hpp"

Anfibio::Anfibio(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao,int mudas_total,date ultima_muda):
                Animal(sexo,tamanho,peso,nome,nome_cientifico,alimentacao,mudas_total,ultima_muda) {}

Anfibio::~Anfibio() {}


ostream& Anfibio::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

