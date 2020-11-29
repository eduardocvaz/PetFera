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
public:
    PetFera(string telefone, string endereco);
    ~PetFera();

    vector<shared_ptr<Animal>> getAnimais() const;
    vector<shared_ptr<Profissional>> getProfissionais() const;

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
    bool adicionaAnimal(shared_ptr<Animal> novo); // conferir upcast make_shared
    shared_ptr<Animal> removeAnimal(string nome); // conferir upcast make_shared
    bool alteraAnimal();
    void listaClasseAnimal();
    void listaDadosAnimal(string nome_animal);
    void listaAnimaisProfissional(string nome_profissional);
    bool adicionaProfissional(shared_ptr<Profissional> novo);
    shared_ptr<Profissional> removeProfissional(string nome);
    bool alteraProfissional();

private:
    string telefone;
    string endereco;
    vector<shared_ptr<Animal>> animais;
    vector<shared_ptr<Profissional>> profissionais;

    /** Métodos internos */
    shared_ptr<Animal> findAnimal(string nome);
    shared_ptr<Profissional> findProfissional(string nome);
    void printTitulo(string titulo, int largura);
};