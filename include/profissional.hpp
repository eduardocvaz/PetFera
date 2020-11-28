#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>

#include "animal.hpp"

using std::string;
using std::ostream;

class Profissional {
protected:
    string nome;
    string idade;
    string telefone;
    vector<Animal*> meus_animais;

public:
    Profissional(string nome, string idade, string telefone);
    virtual ~Profissional();

    string getNome() const;
    string getIdade() const;
    string getTelefone() const;
    vector<Animal*> getMeusAnimais() const;

    void setNome(string nome);
    void setIdade(string idade);
    void setTelefone(string telefone);

    virtual ostream& imprimeDados(ostream& o) const = 0;
    friend ostream& operator<<(ostream& o, Profissional& p);
};
