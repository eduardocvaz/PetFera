#pragma once

#include <string>
using namespace std;

class Animal
{
protected:
    char sexo;
    double tamanho;
    string nome;
    string nome_cientifico;
    string alimentacao;

public:
    char get_sexo();
    void set_sexo(char sexo);

    double get_tamanho();
    void set_tamanho(double tamanho);

    string get_nome();
    void set_nome(string nome);

    string get_nome_cientifico();
    void set_nome_cientifico(string nome_cientifico);

    string get_alimentacao();
    void set_alimentacao(string alimentacao);
};

class AnimalSilvestre
{
protected:
public:
    AnimalSilvestre();
    ~AnimalSilvestre();
};

class AnimalNativo : protected AnimalSilvestre
{
protected:
public:
    AnimalNativo();
    ~AnimalNativo();
};

class AnimalExotico : protected AnimalSilvestre
{
protected:
public:
    AnimalExotico();
    ~AnimalExotico();
};