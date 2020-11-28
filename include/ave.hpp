#pragma once

#include "animal.hpp"
#include <string>

class Ave : public Animal //usar public pra ter acesso externo
{
private:
    double tamanho_do_bico;
    double tamanho_da_envergadura;

public:
    Ave(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,double tamanho_do_bico,double tamanho_da_envergadura);
    ~Ave();

    void setTamanhoBico(double tamanho_do_bico);
    double getTamanhoBico() const;
    void setTamanhoEnvergadura(double tamanho_da_envergadura);
    double getTamanhoEnvergadura() const;

    friend ostream& operator<< (ostream& o, Ave& Ave);

    ostream& imprimeDados(ostream& o) const;
};

