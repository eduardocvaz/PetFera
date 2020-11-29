#include "mamifero.hpp"

Mamifero::Mamifero(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, string cor_da_pelagem):
                Animal(nome,idade,sexo,tamanho,peso,valor,mamiferoDomestico,extinto),
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

