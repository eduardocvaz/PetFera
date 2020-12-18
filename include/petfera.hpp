#pragma once

#include "animal.hpp"
#include "anfibio.hpp"
#include "anfibioNativo.hpp"
#include "anfibioExotico.hpp"
#include "mamifero.hpp"
#include "mamiferoNativo.hpp"
#include "mamiferoExotico.hpp"
#include "ave.hpp"
#include "aveNativo.hpp"
#include "aveExotico.hpp"
#include "reptil.hpp"
#include "reptilNativo.hpp"
#include "reptilExotico.hpp"

#include "profissional.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"

#include <vector>
#include <string>
#include <memory>

using std::vector;
using std::string;

class PetFera {
private:
    string telefone;
    string endereco;
    vector<Animal*> animais;
    vector<Profissional*> profissionais;

    /** Métodos internos */
    Animal* findAnimal(string nome);
    Profissional* findProfissional(string nome);
    void printTitulo(string titulo, int largura);
    bool validaVetTrat();
    bool validaNaoPerigosoVenenoso();

public:
    PetFera(string telefone, string endereco);
    ~PetFera();

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
    void consultarProfissional();


    /** Métodos internos para realizar as operações. */
    bool adicionaAnimal(Animal* novo);
    Animal* removeAnimal(string nome);
    Animal* alteraAnimal(Animal* alterado, int op);
    vector<Animal*> listaClasseAnimal(tpAnimal tipo);
    vector<Animal*> listaAnimaisProfissional(string nome_profissional,bool is_vet);
    bool adicionaProfissional(Profissional* novo);
    Profissional* removeProfissional(string nome);
    Profissional* alteraProfissional(Profissional* alterado, char op);
    void carregarArquivo();
    void escreverArquivo();

};