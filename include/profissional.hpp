#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>
#include <memory>

using std::setfill;
using std::setw;
using std::fixed;
using std::setprecision;
using std::left;
using std::right;
using std::cout;
using std::endl;
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
    tipoProfissional tipo_profissional;

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
    void setTipo(tipoProfissional tipo);

    virtual ostream& imprimeDados(ostream& o) const = 0;
    friend ostream& operator<<(ostream& o, Profissional& p);
};
