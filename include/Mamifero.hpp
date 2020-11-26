#pragma once

#include "Animal.hpp"
#include "string"

class Mamifero : public Animal //usar public pra ter acesso externo
{
protected:
    string cor_da_pelagem;
    bool glandulas_sudoriparas;

public:
    Mamifero(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,Tratador& tratador, Veterinario& veterinario,string cor_da_pelagem,bool glandulas_sudoriparas);
    ~Mamifero();

    friend ostream& operator<< (ostream& o, Mamifero& Mamifero);

    ostream& imprimeDados(ostream& o) const; // implementar de acordo com os atributos próprios
};

