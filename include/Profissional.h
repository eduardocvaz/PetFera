#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>

using std::string;
using std::ostream;

class Profissional {
protected:
    string nome;
    string idade;
    string telefone;

public:
    Profissional(string nome, string idade, string telefone);
    virtual ~Profissional();

    //get e set
    string getNome() const;
    string getIdade() const;
    string getTelefone() const;

    void setNome(string nome);
    void setIdade(string idade);
    void setTelefone(string telefone);

    virtual ostream& imprimeDados(ostream& o) const = 0;
    friend ostream& operator<<(ostream& o, Profissional& p);
};
