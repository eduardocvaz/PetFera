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
    //Tratador tratador;
    //Veterinario veterinario; //acredito que e mais facil implementar associando o nome do profissional a uma string em vez de copiar o objeto
                                //implementar a lógica nos contrutores puxando da lista de vets e tratadores(que precisam ser implementadas antes)

public:
    //construtores
    Animal(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto);
    virtual ~Animal();

//    implementar: para uso na impressão que chama imprimeDados de cada uma:
    friend ostream& operator<< (ostream& o, Animal& animal);

//    virtual puro implementado somente nas derivadas para imprimir de acordo com o corpo de cada uma:
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
};