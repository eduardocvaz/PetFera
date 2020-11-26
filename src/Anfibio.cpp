#include "Anfibio.hpp"

Anfibio::Anfibio(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,int mudas_total,string ultima_muda):
                Animal(sexo,tamanho,peso,nome,nome_cientifico,alimentacao,extinto),
                mudas_total(mudas_total),
                ultima_muda(ultima_muda) {}

Anfibio::~Anfibio() {}

void Anfibio::setMudas(int mudas_total){
    this->mudas_total = mudas_total;
}

int Anfibio::getMudas() const{
    return this->mudas_total;
}
void Anfibio::setUltimaMuda(string ultima_muda){
    this->ultima_muda = ultima_muda;
}

string Anfibio::getUltimaMuda() const{
    return this->ultima_muda;
}

ostream& Anfibio::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

