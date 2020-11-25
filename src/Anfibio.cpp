#include "Anfibio.hpp"

Anfibio::Anfibio(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,int mudas_total,string ultima_muda):
                Animal(sexo,tamanho,peso,nome,nome_cientifico,alimentacao,extinto,mudas_total,ultima_muda) {}

Anfibio::~Anfibio() {}


ostream& Anfibio::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

