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
                telefone(telefone), endereco(endereco) {}

PetFera::~PetFera() {
    for (auto& animal : this->animais)
    {
        delete animal;
    }

    for (auto& profissional : this->profissionais)
    {
        delete profissional;
    }
}

string PetFera::getTelefone() const {
    return this->telefone;
}

string PetFera::getEndereco() const {
    return this->endereco;
}

vector<Animal*> PetFera::getAnimais() const{
    return this->animais;
}

vector<Profissional*> PetFera::getProfissionais() const{
    return this->profissionais;
}

void PetFera::cadastrarAnimal(){
    //implementar
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

bool PetFera::adicionaAnimal(Animal* novo){
    this->animais.push_back(novo);
    return true;
}

Animal* PetFera::removeAnimal(string nome){
    int index = 0;
    for (auto& animal : this->animais)
    {
        if (animal->getNome()==nome)
        {
            Animal* removido = animal;
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
    Animal* animal = this->findAnimal(nome_animal);
    if (animal!=nullptr) {
        cout << animal << endl;
    }
}

void PetFera::listaAnimaisProfissional(string nome_profissional){
    Profissional* profissional = this->findProfissional(nome_profissional);
    if (profissional!=nullptr) {
        vector<Animal*> meus_animais = profissional->getMeusAnimais();
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

Profissional* PetFera::removeProfissional(string nome){
    int index = 0;
    for (auto& profissional : this->profissionais)
    {
        if (profissional->getNome()==nome)
        {
            Profissional* removido = profissional;
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

Animal* PetFera::findAnimal(string nome) {
    for (auto& animal : this->animais)
    {
        if (animal->getNome()==nome)
        {
            return animal;
        }
    }
    return nullptr;
}

Profissional* PetFera::findProfissional(string nome) {
    for (auto& profissional : this->profissionais)
    {
        if (profissional->getNome()==nome)
        {
            return profissional;
        }
    }
    return nullptr;
}

void PetFera::printTitle(string title, int largura){
    int spaceOnLeft = (largura-title.length())/2;
    int spaceExtra = title.length()%2;
    cout << setfill('#') << setw(largura) << ""<< endl;
    cout << "###"
         << setfill(' ') << setw(spaceOnLeft-3) << ""
         << title
         << setfill(' ') << setw(spaceOnLeft-3+spaceExtra) << ""
         << "###" << endl;
    cout << setfill('#') << setw(largura) << "" << endl;
}