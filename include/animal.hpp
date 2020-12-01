#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <iostream>
#include <iomanip>

#include "profissional.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"

using std::string;
using std::ostream;

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
    string sexo;
    double tamanho;
    double peso;
    double valor;
    Veterinario* veterinario;
    Tratador* tratador;
    tpAnimal tipo_animal;

public:
    
    Animal(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, tpAnimal tipo);
    virtual ~Animal();

    friend ostream& operator<< (ostream& o, Animal& animal);
    virtual ostream& imprimeDados(ostream& o) const = 0;

    string getNome() const;
    void setNome(string nome);
    string getIdade() const;
    void setIdade(string idade);
    string getSexo() const;
    void setSexo(string sexo);
    double getTamanho() const;
    void setTamanho(double tamanho);
    double getPeso() const;
    void setPeso(double peso);
    double getValor() const;
    void setValor(double valor);
    tpAnimal getTipo() const;
    void setTipo(tpAnimal tipo);
    Veterinario* getVeterinario() const;
    void setVeterinario(Veterinario* veterinario);
    Tratador* getTratador() const;
    void setTratador(Tratador* tratador);
};