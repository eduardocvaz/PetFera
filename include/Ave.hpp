#pragma once

#include "Animal.hpp"
#include "string"

class Ave : public Animal //usar public pra ter acesso externo
{
protected:
    double tamanho_do_bico;
    double tamanho_da_invergadura;

public:
    Ave(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,double tamanho_do_bico,double tamanho_da_invergadura);
    ~Ave();

    friend ostream& operator<< (ostream& o, Ave& Ave);

    ostream& imprimeDados(ostream& o) const; // implementar de acordo com os atributos próprios
};

