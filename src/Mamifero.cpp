#include "Mamifero.hpp"

#include <string>

Mamifero::Mamifero(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto, string cor_da_pelagem):
                Animal(sexo,tamanho,peso,nome,nome_cientifico,alimentacao,extinto),
                cor_da_pelagem(cor_da_pelagem) {}

Mamifero::~Mamifero() {}

void Mamifero::setCorPelagem(string cor_da_pelagem) {
    this->cor_da_pelagem = cor_da_pelagem;
}

string Mamifero::getCorPelagem() const{
    return this->cor_da_pelagem;
}


ostream& Mamifero::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

