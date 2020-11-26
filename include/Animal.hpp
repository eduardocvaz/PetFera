#pragma once

#include <string>
#include <iostream>

#include "Tratador.hpp"
#include "Veterinario.hpp"

using namespace std;

class Animal {
protected:
    char sexo;
    double tamanho;
    double peso;
    string nome;
    string nome_cientifico;
    string alimentacao;
    bool extinto;
    Tratador& tratador;
    Veterinario& veterinario;

public:
    //construtores
    Animal(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto, Tratador& tratador, Veterinario& veterinario);
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
    Tratador& getTratador() const;
    void setTratador(Tratador& tratador);
    Veterinario& getVeterinario() const;
    void setVeterinario(Veterinario& veterinario);
};