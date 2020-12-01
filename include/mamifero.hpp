#pragma once

#include "animal.hpp"

class Mamifero : public Animal
{
private:
    string cor_da_pelagem;

public:
    Mamifero(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem);
    ~Mamifero();

    void setCorPelagem(string cor_da_pelagem);
    string getCorPelagem() const;

    friend ostream& operator<< (ostream& o, Mamifero& animal);

    virtual ostream& imprimeDados(ostream& o) const;
};

