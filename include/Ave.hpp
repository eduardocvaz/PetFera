#pragma once

#include "Animal.hpp"
#include "string"

class Ave : public Animal //usar public pra ter acesso externo
{
private:
    double tamanho_do_bico;
    double tamanho_da_envergadura;

public:
    Ave(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,double tamanho_do_bico,double tamanho_da_envergadura);
    ~Ave();

    void setTamanhoBico(double tamanho_do_bico);
    double getTamanhoBico() const;
    void setTamanhoEnvergadura(double tamanho_da_envergadura);
    double getTamanhoEnvergadura() const;

    friend ostream& operator<< (ostream& o, Ave& Ave);

    ostream& imprimeDados(ostream& o) const;
};

