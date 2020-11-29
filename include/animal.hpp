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
    string nome;
    string idade;
    bool sexo;
    double tamanho;
    double peso;
    double valor;
    tpAnimal tipo;
    bool extinto;

public:
    Animal(string nome, string idade, bool sexo, double tamanho, double peso, double valor, tpAnimal tipo, bool extinto);
    virtual ~Animal();

    friend ostream& operator<< (ostream& o, Animal& animal);
    virtual ostream& imprimeDados(ostream& o) const = 0;

    string getNome() const;
    void setNome(string nome);
    string getIdade() const;
    void setIdade(string idade);
    bool getSexo() const;
    void setSexo(bool sexo);
    double getTamanho() const;
    void setTamanho(double tamanho);
    double getPeso() const;
    void setPeso(double peso);
    double getValor() const;
    void setValor(double valor);
    tpAnimal getTipo() const;
    void setTipo(tpAnimal tipo);
    bool getExtinto() const;
    void setExtinto(bool extinto);
};