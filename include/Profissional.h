#pragma once

#include <string>
#include <iostream>

using std::string;

class Profissional {
protected:
    string nome;
    string id;
    string idade;
    string telefone;

public:
    Profissional(string nome, string id, string idade, string telefone);
    ~Profissional();

    //get e set
    string getNome() const;
    string getId() const;
    string getIdade() const;
    string getTelefone() const;

    void setNome(string nome);
    void setId(string id);
    void setIdade(string idade);
    void setTelefone(string telefone);

};
