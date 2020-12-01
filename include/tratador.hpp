#pragma once

#include "profissional.hpp"

#include <string>
#include <iostream>

using std::string;

enum nivelSeguranca
{
    nivelVerde,
    nivelAzul,
    nivelVermelho
};

class Tratador : public Profissional {
private:
    nivelSeguranca nivelseguranca;
public:
    Tratador(string nome, string idade, string telefone, nivelSeguranca nivelseg);
    ~Tratador();

    void setNivel(nivelSeguranca nivelseguranca);
    nivelSeguranca getNivel() const;

    friend ostream& operator<< (ostream& o, Tratador& p);
    ostream& imprimeDados(ostream& o) const;
};