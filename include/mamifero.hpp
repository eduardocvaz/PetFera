#pragma once

#include "animal.hpp"
#include "string"

class Mamifero : public Animal
{
private:
    string cor_da_pelagem;

public:
    Mamifero(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,string cor_da_pelagem);
    ~Mamifero();

    void setCorPelagem(string cor_da_pelagem);
    string getCorPelagem() const;

    friend ostream& operator<< (ostream& o, Mamifero& Mamifero);

    ostream& imprimeDados(ostream& o) const;
};

