#include "Mamifero.hpp"

Mamifero::Mamifero(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,string cor_da_pelagem,bool glandulas_sudoriparas):
                Animal(sexo,tamanho,peso,nome,nome_cientifico,alimentacao,extinto,cor_da_pelagem,glandulas_sudoriparas) {}

Mamifero::~Mamifero() {}


ostream& Mamifero::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

