#pragma once

#include "Animal.hpp"
#include "string"

class Reptil : public Animal //usar public pra ter acesso externo
{
protected:
    bool peconheto;
    string tipo_veneno;

public:
    Reptil(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,Tratador& tratador, Veterinario& veterinario,bool peconheto,string tipo_veneno);
    ~Reptil();

    friend ostream& operator<< (ostream& o, Reptil& Reptil);

    ostream& imprimeDados(ostream& o) const; // implementar de acordo com os atributos próprios
};

