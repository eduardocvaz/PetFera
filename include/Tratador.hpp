#pragma once

#include "Profissional.h"

#include <string>
#include <iostream>

using std::string;

enum nivelSeguranca
{
    nivelVerde,
    nivelAmarelo,
    nivelVermelho
};

class Tratador : public Profissional {
private:
    nivelSeguranca nivel;

public:
    Tratador(string nome, string idade, string telefone, nivelSeguranca nivel);
    ~Tratador();

    void setNivel(nivelSeguranca nivel);
    nivelSeguranca getNivel() const;

    friend ostream& operator<< (ostream& o, Tratador& vet);
    ostream& imprimeDados(ostream& o) const;
};