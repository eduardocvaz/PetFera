#pragma once

#include <string>
#include <iostream>

#include "tratador.hpp"
#include "veterinario.hpp"

using namespace std;
enum tpAnimal
{
	anfibioExotico,
	anfibioNativo,
    anfibioDomestico,
    aveExotico,
	aveNativo,
    aveDomestico,
	mamiferoExotico,
	mamiferoNativo,
    mamiferoDomestico,
    reptilExotico,
	reptilNativo,
    reptilDomestico
};

class Animal {
protected:
    char sexo;
    double tamanho;
    double peso;
    string nome;
    string nome_cientifico;
    string alimentacao;
    bool extinto;
    tpAnimal tipo;

public:
    //construtores
    Animal(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto);
    virtual ~Animal();

    friend ostream& operator<< (ostream& o, Animal& animal);
    virtual ostream& imprimeDados(ostream& o) const = 0;

    //gets & sets
    char getSexo() const;
    void setSexo(char sexo);
    double getTamanho() const;
    void setTamanho(double tamanho);
    double getPeso() const;
    void setPeso(double peso);
    string getNome() const;
    void setNome(string nome);
    string getNomeCientifico() const;
    void setNomeCientifico(string nome_cientifico);
    string getAlimentacao() const;
    void setAlimentacao(string alimentacao);
    bool getExtinto() const;
    void setExtinto(bool extinto);
    tpAnimal getTipo();
};