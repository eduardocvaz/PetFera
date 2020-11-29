#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>
#include <memory>

using std::string;
using std::ostream;
using std::vector;
using std::shared_ptr;

enum tipoProfissional
{
    tipoVeterinario,
    tipoTratador
};

class Profissional {
protected:
    string nome;
    string idade;
    string telefone;
    tipoProfissional tipo;

public:
    Profissional(string nome, string idade, string telefone, tipoProfissional tipo);
    virtual ~Profissional();

    string getNome() const;
    string getIdade() const;
    string getTelefone() const;
    tipoProfissional getTipo() const;
    void setNome(string nome);
    void setIdade(string idade);
    void setTelefone(string telefone);

    virtual ostream& imprimeDados(ostream& o) const = 0;
    friend ostream& operator<<(ostream& o, Profissional& p);
};
