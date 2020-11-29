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
using std::cin;
//using std::left;
//using std::right;
//using std::getline;

PetFera::PetFera(string telefone, string endereco):
                telefone(telefone), endereco(endereco) {
    string titulo = "🐆 Loja de Animais PetFera - ";
    titulo.append(this->telefone);
    this->printTitulo(titulo,60);
}

PetFera::~PetFera() {
    for (auto& animal : this->animais) {
        delete animal;
    }
    for (auto& profissional : this->profissionais) {
        delete profissional;
    }
}

vector<Animal*> PetFera::getAnimais() const{
    return this->animais;
}

vector<Profissional*> PetFera::getProfissionais() const{
    return this->profissionais;
}

void PetFera::cadastrarAnimal(){

    int tipo;
    string nome;
    char extinto;
    string idade;
    char sexo;
    double tamanho;
    double peso;
    double valor;
    int silvestre;
    string vet;
    string trat;
    Veterinario* veterinario;
    Tratador* tratador;
    Animal* criado = nullptr;

    this->printTitulo("Cadastrar Animal",60);


    if(!validaVetTrat()){
        return;
    }

    do {
        cout << "(1) Anfibio" << endl
             << "(2) Ave" << endl
             << "(3) Mamífero" << endl
             << "(4) Reptil" << endl;
        cin >> tipo;
        if (tipo!=1 && tipo!=2 && tipo!=3 && tipo!=4) {
            cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (tipo!=1 && tipo!=2 && tipo!=3 && tipo!=4);

    do {
        cout << "(1) Doméstico" << endl
             << "(2) Silvestre Nativo" << endl
             << "(3) Silvestre Exótico" << endl;
        cin >> silvestre;
        if (silvestre!=1 && silvestre!=2 && silvestre!=3) {
            cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (silvestre!=1 && silvestre!=2 && silvestre!=3);

    do {
            cout << "Nome: ";
            cin >> nome;
            if (this->findAnimal(nome)!=nullptr) {
                cout << "Este nome já existe" << endl;
            }
    } while (this->findAnimal(nome)!=nullptr);

    do {
        cout << "Em Extinção? (S|N)";
        cin >> extinto;
        if (extinto!='s' && extinto!='S' && extinto!='n' && extinto!='N') {
            cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (extinto!='s' && extinto!='S' && extinto!='n' && extinto!='N');
    if (extinto=='s' || extinto=='S') {
        cout << "A comercialização de animais em extinção é proibida!" << endl;
        return;
    }

    cout << "Idade: ";
    cin >> idade;

    do {
        cout << "Sexo (M|F): ";
        cin >> sexo;
        if (sexo!='M' && sexo!='m' && sexo!='F' && sexo!='f') {
            cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (sexo!='M' && sexo!='m' && sexo!='F' && sexo!='f');

    cout << "Tamanho (cm): ";
    cin >> tamanho;
    cout << "Peso (kg): ";
    cin >> peso;
    cout << "Valor (R$): ";
    cin >> valor;

    bool flag;
    do {
        flag = true;
        cout << "Veterinário Responsável: ";
        cin >> vet;
        if (this->findProfissional(vet)==nullptr || this->findProfissional(vet)->getTipo()!=tipoVeterinario) {
            cout << "Veterinário não encontrado." << endl;
            flag = false;
        } else if (this->findProfissional(vet)->getTipo()!=tipoVeterinario){
            cout << "Este profissional não é um veterinário. Tente novamente." << endl;
            flag = false;
        }
    } while (!flag);
    veterinario = dynamic_cast<Veterinario *>(findProfissional(vet));

    do {
        flag = true;
        cout << "Tratador Responsável: ";
        cin >> trat;
        if (this->findProfissional(trat)==nullptr){
            cout << "Tratador não encontrado. Tente novamente." << endl;
            flag = false;
        } else if (this->findProfissional(trat)->getTipo()!=tipoTratador){
            cout << "Este profissional não é um tratador. Tente novamente." << endl;
            flag = false;
        } else if((dynamic_cast<Tratador *>(findProfissional(trat))->getNivel())==nivelVerde) {

            flag = validaNaoPerigosoVenenoso();
            if(!flag){
                cout << "Este tratador não pode manipular animais venenosos ou perigosos. Tente Novamente" << endl;

            }else if (tipo!=2){
                cout << "Este tratador só pode manipular aves. Tente novamente." << endl;
                flag = false;
            }
        } else if ((dynamic_cast<Tratador *>(findProfissional(trat))->getNivel())==nivelAzul){

            flag = validaNaoPerigosoVenenoso();
            if(!flag){
                cout << "Este tratador não pode manipular animais venenosos ou perigosos. Tente Novamente" << endl;

            }else if (tipo==1){
                cout << "Este tratador não pode tratar um anfíbio. Tente novamente." << endl;
                flag = false;
            }
        }
    } while (!flag);
    tratador = dynamic_cast<Tratador *>(findProfissional(trat));


    string estado;
    string pais_origem;
    string tipo_pele;
    double tamanho_bico;
    double tamanho_envergadura;
    string cor_pelo;
    string veneno;

    if (tipo==1 && silvestre==1) {
        cout << "Tipo de pele: ";
        cin >> tipo_pele;
        criado = new Anfibio(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele);

    } else if (tipo==1 && silvestre==2) {
        cout << "Tipo de pele: ";
        cin >> tipo_pele;
        cout << "Estado nativo: ";
        cin >> estado;
        criado = new AnfibioNativo(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele,estado);

    } else if (tipo==1 && silvestre==3) {
        cout << "Tipo de pele: ";
        cin >> tipo_pele;
        cout << "País de origem: ";
        cin >> pais_origem;
        criado = new AnfibioExotico(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele,pais_origem);

    } else if (tipo==2 && silvestre==1) {
        cout << "Tamanho do bico (cm): ";
        cin >> tamanho_bico;
        cout << "Envergadura (cm): ";
        cin >> tamanho_envergadura;
        criado = new Ave(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tamanho_bico,tamanho_envergadura);

    } else if (tipo==2 && silvestre==2) {
        cout << "Tamanho do bico (cm): ";
        cin >> tamanho_bico;
        cout << "Envergadura (cm): ";
        cin >> tamanho_envergadura;
        cout << "Estado nativo: ";
        cin >> estado;
        criado = new AveNativo(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tamanho_bico,tamanho_envergadura,estado);

    } else if (tipo==2 && silvestre==3) {
        cout << "Tamanho do bico (cm): ";
        cin >> tamanho_bico;
        cout << "Envergadura (cm): ";
        cin >> tamanho_envergadura;
        cout << "País de origem: ";
        cin >> pais_origem;
        criado = new AveExotico(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tamanho_bico,tamanho_envergadura,pais_origem);

    } else if (tipo==3 && silvestre==1) {
        cout << "Cor da pelagem: ";
        cin >> cor_pelo;
        criado = new Mamifero(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,cor_pelo);

    } else if (tipo==3 && silvestre==2) {
        cout << "Cor da pelagem: ";
        cin >> cor_pelo;
        cout << "Estado nativo: ";
        cin >> estado;
        criado = new MamiferoNativo(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,cor_pelo,estado);

    } else if (tipo==3 && silvestre==3) {
        cout << "Cor da pelagem: ";
        cin >> cor_pelo;
        cout << "País de origem: ";
        cin >> pais_origem;
        criado = new MamiferoExotico(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,cor_pelo,pais_origem);

    } else if (tipo==4 && silvestre==1) {
        cout << "Veneno: ";
        cin >> veneno;
        criado = new Reptil(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,veneno);

    } else if (tipo==4 && silvestre==2) {
        cout << "Veneno: ";
        cin >> veneno;
        cout << "Estado nativo: ";
        cin >> estado;
        criado = new ReptilNativo(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,veneno,estado);

    } else if (tipo==4 && silvestre==3) {
        cout << "Veneno: ";
        cin >> veneno;
        cout << "País de origem: ";
        cin >> pais_origem;
        criado = new ReptilExotico(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,veneno,pais_origem);
    }

    if (this->adicionaAnimal(criado)) {
        cout << "Operação realizada com sucesso." << endl;
    } else {
        cout << "Erro!! Operação cancelada." << endl;
    }
}

void PetFera::removerAnimal(){
    this->printTitulo("Remover Animal",60);
    if(this->animais.empty()){
        cout << "Nenhum animal cadastrado" << endl;
        return;
    }
    string nome;
    do {
        cout << "Nome: ";
        cin >> nome;
        if (this->findAnimal(nome)==nullptr) {
            cout << "Nome não encontrado! Tente novamente." << endl;
        }
    } while (this->findAnimal(nome)==nullptr);

    if (this->removeAnimal(nome)) {
        cout << "Operação realizada com sucesso." << endl;
    } else {
        cout << "Erro!! Operação cancelada." << endl;
    }
}

//void PetFera::alterarAnimal(){
//    //implementar
//}

void PetFera::listarClasseAnimal(){

    int classe;
    int tipo;

    this->printTitulo("Listar classe de animais",60);

    do {
        cout << "(1) Anfibio" << endl
             << "(2) Ave" << endl
             << "(3) Mamífero" << endl
             << "(4) Reptil" << endl;
        cin >> classe;
        if (classe!=1 && classe!=2 && classe!=3 && classe!=4) {
            cout << "Opção inválida! Tente novamente." << endl << endl;
        }
    } while (classe!=1 && classe!=2 && classe!=3 && classe!=4);

    do {
        cout << endl << "(1) Doméstico" << endl
             << "(2) Silvestre Nativo" << endl
             << "(3) Silvestre Exótico" << endl;
        cin >> tipo;
        if (tipo!=1 && tipo!=2 && tipo!=3) {
            cout << "Opção inválida! Tente novamente." << endl << endl;
        }
    } while (tipo!=1 && tipo!=2 && tipo!=3);

    if (classe==1 && tipo==1){

        auto lista = listaClasseAnimal(anfibioDomestico);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==1 && tipo==2){

        auto lista = listaClasseAnimal(anfibioNativo);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==1 && tipo==3){

        auto lista = listaClasseAnimal(anfibioExotico);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==2 && tipo==1){

        auto lista = listaClasseAnimal(aveDomestico);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==2 && tipo==2){

        auto lista = listaClasseAnimal(aveNativo);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==2 && tipo==3){

        auto lista = listaClasseAnimal(aveExotico);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==3 && tipo==1){

        auto lista = listaClasseAnimal(mamiferoDomestico);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==3 && tipo==2){

        auto lista = listaClasseAnimal(mamiferoNativo);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==3 && tipo==3){

        auto lista = listaClasseAnimal(mamiferoExotico);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==4 && tipo==1){

        auto lista = listaClasseAnimal(reptilDomestico);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==4 && tipo==2){

        auto lista = listaClasseAnimal(reptilNativo);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else if (classe==4 && tipo==3){

        auto lista = listaClasseAnimal(reptilExotico);

        for (auto& animal : lista)
        {
            cout << animal;
        }
    } else cout << "Erro no sistema" << endl;
}

//void PetFera::listarDadosAnimal(){
//    //implementar
//}
//
//void PetFera::listarAnimaisProfissional(){
//    //implementar
//}

void PetFera::cadastrarProfissional(){
    string nome;
    string idade;
    string telefone;
    int op;
    int nivel;
    string crmv;
    Profissional* criado = nullptr;

    this->printTitulo("Cadastrar Profissional",60);

    do {
        cout << "Nome: ";
        cin >> nome;
        if (this->findProfissional(nome)!=nullptr) {
            cout << "Este nome já existe" << endl;
        }
    } while (this->findProfissional(nome)!=nullptr);

    cout << "Idade: ";
    cin >> idade;

    cout << "Telefone: ";
    cin >> telefone;

    do {
        cout << "(1) Veterinário | (2) Tratador: ";
        cin >> op;
        if (op!=1 && op!=2) {
            cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (op!=1 && op!=2);

    if (op==1) {

        cout << "Registro CRMV: ";
        cin >> crmv;
        criado = new Veterinario(nome, idade, telefone, crmv);

    } else {
        do {
            cout << "Nível de Segurança:" << endl
                 << "(1) Verde" << endl
                 << "(2) Azul" << endl
                 << "(3) Vermelho" << endl;
            cin >> nivel;
            if (nivel!=1 && nivel!=2 && nivel!=3) {
                cout << "Opção inválida! Tente novamente." << endl;
            }
        } while (nivel!=1 && nivel!=2 && nivel!=3);

        criado = new Tratador(nome, idade, telefone, static_cast<nivelSeguranca>(nivel));
    }

    if (this->adicionaProfissional(criado)) {
        cout << "Operação realizada com sucesso." << endl;
    } else {
        cout << "Erro!! Operação cancelada." << endl;
    }
}

void PetFera::removerProfissional(){

    this->printTitulo("Remover Profissional",60);

    if(this->animais.empty()){
        cout << "Nenhum profissional cadastrado" << endl;
        return;
    }

    string nome;
    do {
        cout << "Nome: ";
        cin >> nome;
        if (this->findProfissional(nome)==nullptr) {
            cout << "Nome não encontrado! Tente novamente." << endl;
        }
    } while (this->findProfissional(nome)==nullptr);

    if (this->removeProfissional(nome)) {
        cout << "Operação realizada com sucesso." << endl;
    } else {
        cout << "Erro!! Operação cancelada." << endl;
    }
}

//void PetFera::alterarProfissional(){
//    //implementar
//}

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

//bool PetFera::alteraAnimal(){
//    //implementar
//}

vector<Animal*> PetFera::listaClasseAnimal(tpAnimal tipo){

    vector<Animal*> classe;
    for (auto& animal : this->animais)
    {
        if (animal->getTipo()==tipo)
        {
            classe.push_back(animal);
        }
    }
    return classe;
}

/*
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
*/
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

/*
bool PetFera::alteraProfissional(){
    //implementar


}
*/

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

bool PetFera::validaVetTrat() {

    int vet=0;
    int trat=0;

    if (profissionais.empty()){
        cout << endl << "Necessário cadastro prévio de ao menos 1 Veterinário e 1 Tratador.";
        return false;
    }

    for (auto& profissional : this->profissionais) {
        if (profissional->getTipo() == tipoVeterinario) { vet++; }
        if (profissional->getTipo() == tipoTratador) { trat++; }
    }
    if (vet>=1 && trat>=1) return true;

    return false;
}

bool PetFera::validaNaoPerigosoVenenoso() {
    char op;
    do {
        cout << "O animal é perigoso ou venenoso? (S|N)";
        cin >> op;
        if (op != 's' && op != 'S' && op != 'n' && op != 'N') {
            cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (op != 's' && op != 'S' && op != 'n' && op != 'N');
    if (op == 's' || op == 'S') {
        return false;
    } else return true;
}