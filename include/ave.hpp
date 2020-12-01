#pragma once

#include "animal.hpp"

class Ave : public Animal
{
private:
    double tamanho_do_bico;
    double tamanho_da_envergadura;

public:
    Ave(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, double tamanho_do_bico, double tamanho_da_envergadura);
    ~Ave();

    void setTamanhoBico(double tamanho_do_bico);
    double getTamanhoBico() const;
    void setTamanhoEnvergadura(double tamanho_da_envergadura);
    double getTamanhoEnvergadura() const;

    friend ostream& operator<< (ostream& o, Ave& animal);

    virtual ostream& imprimeDados(ostream& o) const;
};

