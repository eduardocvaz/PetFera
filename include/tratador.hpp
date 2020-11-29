#pragma once

#include "profissional.hpp"

#include <string>
#include <iostream>

using std::string;

enum nivelSeguranca
{
    nivelVerde = 1,
    nivelAmarelo = 2,
    nivelVermelho = 3
};

class Tratador : public Profissional {
private:
    nivelSeguranca nivel;
public:
    Tratador(string nome, string idade, string telefone, nivelSeguranca nivel);
    ~Tratador();

    void setNivel(nivelSeguranca nivel);
    nivelSeguranca getNivel() const;

    friend ostream& operator<< (ostream& o, Tratador& p);
    ostream& imprimeDados(ostream& o) const;
};