#pragma once

#include "Animal.hpp"

class Anfibio : public Animal //usar public pra ter acesso externo
{
protected:
    //atributos específicos

public:
    Anfibio(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto);
    ~Anfibio();

    friend ostream& operator<< (ostream& o, Anfibio& anfibio);

    ostream& imprimeDados(ostream& o) const; // implementar de acordo com os atributos próprios
};

