#include "anfibio.hpp"

Anfibio::Anfibio(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador,string tipo_pele):
        Animal(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador, anfibioDomestico),
                tipo_pele(tipo_pele) {}

Anfibio::~Anfibio() {}

void Anfibio::setTipoPele(string tipo_pele){
    this->tipo_pele = tipo_pele;
}

string Anfibio::getTipoPele() const{
    return this->tipo_pele;
}

ostream& Anfibio::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

