#pragma once

#include "anfibio.hpp"
#include "mamifero.hpp"
#include "ave.hpp"
#include "reptil.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class PetFera {
public:
    PetFera(string telefone, string endereco);
    ~PetFera();
    string getTelefone() const;
    string getEndereco() const;
    vector<Animal*> getAnimais() const;
    vector<Profissional*> getProfissionais() const;

    /** Métodos de interação com o usuário */
    void cadastrarAnimal();
    void removerAnimal();
    void alterarAnimal();
    void listarClasseAnimal();
    void listarDadosAnimal();
    void listarAnimaisProfissional();
    void cadastrarProfissional();
    void removerProfissional();
    void alterarProfissional();


    /** Métodos internos para realizar as operações. */
    bool adicionaAnimal(Animal* novo);
    Animal* removeAnimal(string nome);
    bool alteraAnimal();
    void listaClasseAnimal();
    void listaDadosAnimal(string nome_animal);
    void listaAnimaisProfissional(string nome_profissional);
    bool adicionaProfissional(Profissional* novo);
    Profissional* removeProfissional(string nome);
    bool alteraProfissional();

private:

    string telefone;
    string endereco;
    vector<Animal*> animais;
    vector<Profissional*> profissionais;

    /** Métodos internos */
    Animal* findAnimal(string nome);
    Profissional* findProfissional(string nome);
    void printTitle(string title, int largura);
};