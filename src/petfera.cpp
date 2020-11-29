#include "petfera.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstring>

using std::setfill;
using std::setw;
//using std::fixed;
//using std::setprecision;
using std::cout;
using std::endl;
//using std::cin;
//using std::left;
//using std::right;
//using std::getline;

PetFera::PetFera(string telefone, string endereco):
                telefone(telefone), endereco(endereco) {
    string titulo = "Loja de Animais PetFera - ";
    titulo.append(this->telefone);
    this->printTitulo(titulo,60);
}

PetFera::~PetFera() {
//    for (auto& animal : this->animais)
//    {
//        delete animal;
//    }
//
//    for (auto& profissional : this->profissionais)
//    {
//        delete profissional;
//    }
}

vector<shared_ptr<Animal>> PetFera::getAnimais() const{
    return this->animais;
}

vector<shared_ptr<Profissional>> PetFera::getProfissionais() const{
    return this->profissionais;
}

void PetFera::cadastrarAnimal(){

    string nome;
    string idade;
    char sexo;
    double tamanho;
    double peso;
    double valor;
    tpAnimal tipo;
    bool extinto;
    //Animal* criado = nullptr;

    this->printTitulo("Cadastrar Animal",60);

    cout << "Nome: ";
    cin >> nome;
    cout << "Idade: ";
    cin >> idade;

    do {
        cout << "Sexo (M - Macho | F - Fêmea): ";
        cin >> sexo;
        if (sexo!="M" && sexo!="m"
            && sexo!="F" && sexo!="f") {
            cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (sexo!="M" && sexo!="m"
             && sexo!="F" && sexo!="f");

    cout << "Tamanho: ";
    cin >> tamanho;
    cout << "Peso: ";
    cin >> peso;
    cout << "Valor (R$): ";
    cin >> valor;

    cc_tipo = tcNormal;
    if (strTipo=="E" || strTipo=="e") {
        cc_tipo = tcEspecial;
    } else if (strTipo=="P" || strTipo=="p") {
        cc_tipo = tcPoupanca;
    }

    cc_saldo = leValor("Saldo: ");

    if (cc_tipo == tcEspecial || cc_tipo == tcNormal) {
        cc_limite = leValor("Limite: ");

        criada = new ContaCorrente(
                this->numero,
                cc_numero,
                0,
                cc_tipo,
                cc_limite);
    } else { // cc_tipo == tcPoupanca
        cc_taxa = leValor("Rendimento (%): ");

        criada = new ContaPoupanca(
                this->numero,
                cc_numero,
                0,
                cc_tipo,
                cc_taxa);
    }

    Movimentacao* mov = new Movimentacao(
            "Abertura de conta.",
            cc_saldo,tmCredito);
    criada->processarMovimentacao(mov);

    if (this->adicionarConta(criada)) {
        cout << "Operação realizada com sucesso." << endl;
    } else {
        cout << "Erro!! Operação cancelada." << endl;
    }

    Animal(string nome, string idade, bool sexo, double tamanho, double peso, double valor, tpAnimal tipo, bool extinto)
}

void PetFera::removerAnimal(){
    //implementar
}

void PetFera::alterarAnimal(){
    //implementar
}

void PetFera::listarClasseAnimal(){
    //implementar
}

void PetFera::listarDadosAnimal(){
    //implementar
}

void PetFera::listarAnimaisProfissional(){
    //implementar
}

void PetFera::cadastrarProfissional(){
    //implementar
}

void PetFera::removerProfissional(){
    //implementar
}

void PetFera::alterarProfissional(){
    //implementar
}

bool PetFera::adicionaAnimal(shared_ptr<Animal> novo){
    this->animais.push_back(novo);
    return true;
}

shared_ptr<Animal> PetFera::removeAnimal(string nome){
    int index = 0;
    for (auto& animal : this->animais)
    {
        if (animal->getNome()==nome)
        {
            shared_ptr<Animal> removido = animal;
            this->animais.erase(this->animais.begin()+index);
            return removido;
        }
        index++;
    }
    return nullptr;
}

bool PetFera::alteraAnimal(){
    //implementar
}

void PetFera::listaClasseAnimal(){
    //implementar
}

void PetFera::listaDadosAnimal(string nome_animal){
    shared_ptr<Animal> animal = this->findAnimal(nome_animal);
    if (animal!=nullptr) {
        cout << animal << endl;
    }
}

void PetFera::listaAnimaisProfissional(string nome_profissional){
    shared_ptr<Profissional> profissional = this->findProfissional(nome_profissional);
    if (profissional!=nullptr) {
        vector<shared_ptr<Animal>> meus_animais = profissional->getMeusAnimais();
        for (auto& animal : meus_animais)
        {
            cout << animal << endl;
        }

    }
}

bool PetFera::adicionaProfissional(Profissional* novo){
    this->profissionais.push_back(novo);
    return true;
}

shared_ptr<Profissional> PetFera::removeProfissional(string nome){
    int index = 0;
    for (auto& profissional : this->profissionais)
    {
        if (profissional->getNome()==nome)
        {
            shared_ptr<Profissional> removido = profissional;
            this->profissionais.erase(this->profissionais.begin()+index);
            return removido;
        }
        index++;
    }
    return nullptr;
}

bool PetFera::alteraProfissional(){
    //implementar









}

shared_ptr<Animal> PetFera::findAnimal(string nome) {
    for (auto& animal : this->animais)
    {
        if (animal->getNome()==nome)
        {
            return animal;
        }
    }
    return nullptr;
}

shared_ptr<Profissional> PetFera::findProfissional(string nome) {
    for (auto& profissional : this->profissionais)
    {
        if (profissional->getNome()==nome)
        {
            return profissional;
        }
    }
    return nullptr;
}

void PetFera::printTitulo(string titulo, int largura){
    int spaceOnLeft = (largura-titulo.length())/2;
    int spaceExtra = titulo.length()%2;
    cout << setfill('-') << setw(largura) << ""<< endl;
    cout << "###"
         << setfill(' ') << setw(spaceOnLeft-3) << ""
         << titulo
         << setfill(' ') << setw(spaceOnLeft-3+spaceExtra) << ""
         << "###" << endl;
    cout << setfill('-') << setw(largura) << "" << endl;
}