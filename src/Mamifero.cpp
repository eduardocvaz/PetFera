#include "Mamifero.hpp"

Mamifero::Mamifero(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,Tratador& tratador, Veterinario& veterinario,string cor_da_pelagem,bool glandulas_sudoriparas):
                Animal(sexo,tamanho,peso,nome,nome_cientifico,alimentacao,extinto,tratador,veterinario), 
                cor_da_pelagem(cor_da_pelagem), 
                glandulas_sudoriparas(glandulas_sudoriparas) {}

Mamifero::~Mamifero() {}


ostream& Mamifero::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

