#include "anfibio.hpp"

Anfibio::Anfibio(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, int mudas_total,string ultima_muda):
        Animal(nome,idade,sexo,tamanho,peso,valor,anfibioDomestico,extinto),
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

