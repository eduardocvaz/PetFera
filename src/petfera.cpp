#include "petfera.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstring>
#include <fstream>
#include <sstream>

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
using std::ostream;
using std::istream;
using std::ios;
using std::stringstream;
using std::ifstream;
using std::ofstream;

/**
 * @brief Constroi um novo objeto Pet Fera:: Pet Fera
 *
 * @param telefone Telefone da Loja
 * @param endereco Endereço da loja
 */
PetFera::PetFera(string telefone, string endereco):
                telefone(telefone), endereco(endereco) {

    string titulo = "🐆 Loja de Animais PetFera - ";
    titulo.append(this->telefone);
    this->printTitulo(titulo,60);
}

/**
 * @brief Destroi o objeto Pet Fera:: Pet Fera
 *
 */
PetFera::~PetFera() {
    for (auto& animal : this->animais) {
        delete animal;
    }
    for (auto& profissional : this->profissionais) {
        delete profissional;
    }
}

/**
 * @brief Metodo get para obter o vetor de animais da loja
 *
 * @return Retorna o vetor de animais
 */
vector<Animal*> PetFera::getAnimais() const{
    return this->animais;
}

/**
 * @brief Metodo get para obter o vetor de profissionais que trabalham na loja
 *
 * @return Retorna o vetor de profissionais que trabalham na loja
 */
vector<Profissional*> PetFera::getProfissionais() const{
    return this->profissionais;
}

/**
 * @brief Metodo para cadastrar um animal na loja
 *@details Metodo tem varias varieveis temporarios, e basicamente vai perguntando ao usuario o dado, depois valida o dado e usa o metodo para atribuir ao animal
 */
void PetFera::cadastrarAnimal(){

    int tipo;
    string nome;
    string extinto;
    string idade;
    string sexo;
    double tamanho;
    double peso;
    double valor;
    int silvestre;
    string vet;
    string trat;
    Veterinario* veterinario;
    Tratador* tratador;
    Animal* criado = nullptr;

    if(!validaVetTrat()){
        return;
    }

    this->printTitulo("Cadastrar Animal",60);

    do {
        cout << "(1)  Anfibio" << endl
             << "(2)  Ave" << endl
             << "(3)  Mamífero" << endl
             << "(4)  Reptil" << endl;
        cin >> tipo;
        if (tipo!=1 && tipo!=2 && tipo!=3 && tipo!=4) {
            cout << endl << "Opção inválida! Tente novamente!" << endl;
        }
    } while (tipo!=1 && tipo!=2 && tipo!=3 && tipo!=4);

    do {
        cout << "(1)  Doméstico" << endl
             << "(2)  Silvestre Nativo" << endl
             << "(3)  Silvestre Exótico" << endl;
        cin >> silvestre;
        if (silvestre!=1 && silvestre!=2 && silvestre!=3) {
            cout << endl << "Opção inválida! Tente novamente!" << endl;
        }
    } while (silvestre!=1 && silvestre!=2 && silvestre!=3);

    do {
            cout << "Nome: ";
            cin >> nome;
            if (this->findAnimal(nome)!=nullptr) {
                cout << endl << "Este nome já existe!" << endl;
            }
    } while (this->findAnimal(nome)!=nullptr);

    do {
        cout << "Em Extinção? (S|N): ";
        cin >> extinto;
        if (extinto!="s" && extinto!="S" && extinto!="n" && extinto!="N") {
            cout << endl << "Opção inválida! Tente novamente!" << endl;
        }
    } while (extinto!="s" && extinto!="S" && extinto!="n" && extinto!="N");
    if (extinto=="s" || extinto=="S") {
        cout << endl << "A comercialização de animais em extinção é proibida!" << endl;
        return;
    }

    cout << "Idade: ";
    cin >> idade;

    do {
        cout << "Sexo (M|F): ";
        cin >> sexo;
        if (sexo!="M" && sexo!="m" && sexo!="F" && sexo!="f") {
            cout << endl << "Opção inválida! Tente novamente!" << endl;
        }
    } while (sexo!="M" && sexo!="m" && sexo!="F" && sexo!="f");

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

        if(vet=="x" || vet=="X"){
            cout << endl << "Operação cancelada!" << endl;
            return;
        }

        if (this->findProfissional(vet)==nullptr) {
            cout << endl << "Veterinário não encontrado!" << endl;
            flag = false;
        } else if (this->findProfissional(vet)->getTipo()!=tipoVeterinario){
            cout << endl << "Este profissional não é um veterinário. Tente novamente!" << endl;
            flag = false;
        }
    } while (!flag);
    veterinario = dynamic_cast<Veterinario *>(findProfissional(vet));

    do {
        flag = true;
        cout << "Tratador Responsável: ";
        cin >> trat;

        if(trat=="x" || trat=="X"){
            cout << endl << "Operação cancelada!" << endl;
            return;
        }

        if (this->findProfissional(trat)==nullptr){
            cout << endl << "Tratador não encontrado. Tente novamente!" << endl;
            flag = false;
        } else if (this->findProfissional(trat)->getTipo()!=tipoTratador){
            cout << endl << "Este profissional não é um tratador. Tente novamente!" << endl;
            flag = false;
        } else if((dynamic_cast<Tratador *>(findProfissional(trat))->getNivel())==nivelVerde) {

            flag = validaNaoPerigosoVenenoso();
            if(!flag){
                cout << endl << "Este tratador não pode manipular animais venenosos/perigosos. Tente Novamente!" << endl;

            }else if (tipo!=2){
                cout << endl << "Este tratador só pode manipular aves. Tente novamente!" << endl;
                flag = false;
            }
        } else if ((dynamic_cast<Tratador *>(findProfissional(trat))->getNivel())==nivelAzul){

            flag = validaNaoPerigosoVenenoso();
            if(!flag){
                cout << endl << "Este tratador não pode manipular animais venenosos/perigosos. Tente Novamente!" << endl;

            }else if (tipo==1){
                cout << endl << "Este tratador não pode tratar um anfíbio. Tente novamente!" << endl;
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

    switch (tipo) {
        case 1: {
            if (silvestre == 1) {
                cout << "Tipo de pele: ";
                cin >> tipo_pele;
                criado = new Anfibio(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele);
            }
            else if (silvestre == 2) {
                cout << "Tipo de pele: ";
                cin >> tipo_pele;
                cout << "Estado nativo: ";
                cin >> estado;
                criado = new AnfibioNativo(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele,estado);
            }
            else if (silvestre == 3) {
                cout << "Tipo de pele: ";
                cin >> tipo_pele;
                cout << "País de origem: ";
                cin >> pais_origem;
                criado = new AnfibioExotico(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele,pais_origem);
            }
        }
            break;

        case 2: {
            if (silvestre == 1) {
                cout << "Tamanho do bico (cm): ";
                cin >> tamanho_bico;
                cout << "Envergadura (cm): ";
                cin >> tamanho_envergadura;
                criado = new Ave(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tamanho_bico,tamanho_envergadura);
            }
            else if (silvestre == 2) {
                cout << "Tamanho do bico (cm): ";
                cin >> tamanho_bico;
                cout << "Envergadura (cm): ";
                cin >> tamanho_envergadura;
                cout << "Estado nativo: ";
                cin >> estado;
                criado = new AveNativo(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tamanho_bico,tamanho_envergadura,estado);
            }
            else if (silvestre == 3) {
                cout << "Tamanho do bico (cm): ";
                cin >> tamanho_bico;
                cout << "Envergadura (cm): ";
                cin >> tamanho_envergadura;
                cout << "País de origem: ";
                cin >> pais_origem;
                criado = new AveExotico(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tamanho_bico,tamanho_envergadura,pais_origem);
            }
        }
            break;

        case 3: {
            if (silvestre == 1) {
                cout << "Cor da pelagem: ";
                cin >> cor_pelo;
                criado = new Mamifero(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,cor_pelo);
            }
            else if (silvestre == 2) {
                cout << "Cor da pelagem: ";
                cin >> cor_pelo;
                cout << "Estado nativo: ";
                cin >> estado;
                criado = new MamiferoNativo(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,cor_pelo,estado);
            }
            else if (silvestre == 3) {
                cout << "Cor da pelagem: ";
                cin >> cor_pelo;
                cout << "País de origem: ";
                cin >> pais_origem;
                criado = new MamiferoExotico(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,cor_pelo,pais_origem);
            }
        }
            break;

        case 4: {
            if (silvestre == 1) {
                cout << "Veneno: ";
                cin >> veneno;
                criado = new Reptil(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,veneno);
            }
            else if (silvestre == 2) {
                cout << "Veneno: ";
                cin >> veneno;
                cout << "Estado nativo: ";
                cin >> estado;
                criado = new ReptilNativo(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,veneno,estado);
            }
            else if (silvestre == 3) {
                cout << "Veneno: ";
                cin >> veneno;
                cout << "País de origem: ";
                cin >> pais_origem;
                criado = new ReptilExotico(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,veneno,pais_origem);
            }
        }
            break;

        default : cout << endl << "Erro Interno!";
    }

    if (this->adicionaAnimal(criado)) {
        cout << endl << "Operação realizada com sucesso!" << endl;
    } else {
        cout << endl << "Erro!! Operação cancelada!" << endl;
    }
}

/**
 * @brief Metodo para remover um animal ja cadastrado da loja
 * @details Metodo recebe o animal valida se ele existe e depois remove ele 
 */
void PetFera::removerAnimal(){

    if(this->animais.empty()){
        cout << endl << "Nenhum animal cadastrado!" << endl;
        return;
    } else {cout << "tem";}

    this->printTitulo("Remover Animal",60);

    string nome;
    do {
        cout << "Nome: ";
        cin >> nome;

        if(nome=="x" || nome =="X"){
            cout << endl << "Operação cancelada!" << endl;
            return;
        }

        if (this->findAnimal(nome)==nullptr) {
            cout << endl << "Nome não encontrado! Tente novamente!" << endl;
        }
    } while (this->findAnimal(nome)==nullptr);

    if (this->removeAnimal(nome)) {
        cout << endl << "Operação realizada com sucesso!" << endl;
    } else {
        cout << endl << "Erro!! Operação cancelada!" << endl;
    }
}

/**
 * @brief Metodo para alterar os dados cadastrados de um animal
 *
 */
void PetFera::alterarAnimal(){

    Animal* alterado;
    string nome;
    string op;
    bool flag;

    if(this->animais.empty()){
        cout << endl << "Nenhum animal cadastrado!" << endl;
        return;
    }

    this->printTitulo("Alterar Animal",60);

    do {
        cout << "Nome do animal: ";
        cin >> nome;

        if(nome=="x" || nome =="X"){
            cout << endl << "Operação cancelada!" << endl;
            return;
        }

        if (this->findAnimal(nome)==nullptr) {
            cout << "Animal não encontrado! Tente novamente." << endl;
        }
    } while (this->findAnimal(nome)==nullptr);

    do {
        flag=true;
        cout << endl << "Selecione um campo para alterar:" << endl
             << "(0)  Nome" << endl
             << "(1)  Idade" << endl
             << "(2)  Sexo" << endl
             << "(3)  Tamanho" << endl
             << "(4)  Peso" << endl
             << "(5)  Valor" << endl
             << "(6)  Veterinário responsável" << endl
             << "(7)  Tratador responsável" << endl;

        switch(this->findAnimal(nome)->getTipo()) {

            case anfibioDomestico:{
                cout << "(8)  Tipo de pele" << endl;
            }
            break;
            case anfibioNativo:{
                cout << "(8)  Tipo de pele" << endl
                     << "(9)  Estado nativo" << endl;
            }
                break;
            case anfibioExotico:{
                cout << "(8)  Tipo de pele" << endl
                     << "(9)  País de origem" << endl;
            }
                break;
            case aveDomestico:{
                cout << "(8)  Tamanho do bico" << endl
                     << "(9)  Envergadura" << endl;
            }
                break;
            case aveNativo:{
                cout << "(8)  Tamanho do bico" << endl
                     << "(9)  Envergadura" << endl
                     << "(10) Estado nativo: " << endl;
            }
                break;
            case aveExotico:{
                cout << "(8)  Tamanho do bico" << endl
                     << "(9)  Envergadura" << endl
                     << "(10) País de origem" << endl;
            }
                break;
            case mamiferoDomestico:{
                cout << "(8)  Cor da pelagem" << endl;
            }
                break;
            case mamiferoNativo:{
                cout << "(8)  Cor da pelagem" << endl
                     << "(9)  Estado nativo" << endl;
            }
                break;
            case mamiferoExotico:{
                cout << "(8)  Cor da pelagem" << endl
                     << "(9)  País de origem" << endl;
            }
                break;
            case reptilDomestico:{
                cout << "(8)  Tipo de veneno" << endl;
            }
                break;
            case reptilNativo:{
                cout << "(8)  Tipo de veneno" << endl
                     << "(9)  Estado nativo" << endl;
            }
                break;
            case reptilExotico:{
                cout << "(8)  Tipo de veneno" << endl
                     << "(9)  País de origem" << endl;
            }
                break;
        }

        cin >> op;

        if (op!="0" && op!="1" && op!="2" && op!="3" && op!="4" && op!="5" && op!="6" && op!="7" && op!="8" && op!="9" && op!="10") {
            cout << endl << "Opção inválida! Tente novamente!" << endl;
            flag=false;
        }
    } while (!flag);


    alterado = this->alteraAnimal(this->findAnimal(nome), stoi(op));

    if (alterado) {
        cout << endl << *(alterado) << endl;
        cout << endl << "Operação realizada com sucesso!" << endl;
    } else {
        cout << endl << "Erro!! Operação cancelada!" << endl;
    }
}

/**
 * @brief Metodo para listar os animais de uma determinada classe
 * @details Metodo da as opções para o usuario escolher a classe de animais, depois chama o metodo para listar eles
 */
void PetFera::listarClasseAnimal(){

    int classe;
    int tipo;

    if(this->animais.empty()){
        cout << "Nenhum animal cadastrado" << endl;
        return;
    }

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

    switch (classe) {
        case 1: {
            if (tipo == 1) { auto lista = listaClasseAnimal(anfibioDomestico); }
            else if (tipo == 2) { auto lista = listaClasseAnimal(anfibioNativo); }
            else if (tipo == 3) { auto lista = listaClasseAnimal(anfibioExotico); }
        }
            break;

        case 2: {
            if (tipo == 1) { auto lista = listaClasseAnimal(aveDomestico); }
            else if (tipo == 2) { auto lista = listaClasseAnimal(aveNativo); }
            else if (tipo == 3) { auto lista = listaClasseAnimal(aveExotico); }
        }
            break;

        case 3: {
            if (tipo == 1) { auto lista = listaClasseAnimal(mamiferoDomestico); }
            else if (tipo == 2) { auto lista = listaClasseAnimal(mamiferoNativo); }
            else if (tipo == 3) { auto lista = listaClasseAnimal(mamiferoExotico); }
        }
            break;

        case 4: {
            if (tipo == 1) { auto lista = listaClasseAnimal(reptilDomestico); }
            else if (tipo == 2) { auto lista = listaClasseAnimal(reptilNativo); }
            else if (tipo == 3) { auto lista = listaClasseAnimal(reptilExotico); }
        }
            break;

        default : cout << endl << "Erro Interno!";
        //atribuição para lista para posterior utilização em extração de dados
    }
}

/**
 * @brief Metodo para listar os dados de uma determinado animal
 * @details Metodo recebe nome do animal para listar os dados, valida se ele exite depois imprime os dados
 */
void PetFera::listarDadosAnimal(){

    if(this->animais.empty()){
        cout << "Nenhum animal cadastrado" << endl;
        return;
    }

    this->printTitulo("Listar dados de animal",60);

    string nome;
    do {
        cout << "Digite o nome do animal: ";
        cin >> nome;

        if(nome=="x" || nome =="X"){
            cout << "Operação cancelada." << endl;
            return;
        }

        if (this->findAnimal(nome)==nullptr) {
            cout << "Animal não encontrado" << endl;
        }
    } while (this->findAnimal(nome)==nullptr);

    cout << *(this->findAnimal(nome)) << endl;
}

/**
 * @brief Metodo para listar animais de um determinado profissional(veterinario ou tratador)
 * @details Metodo recebe o nome do profissional valida se ele existe e caso exista imprime os animais que ele esta responsavel
 */
void PetFera::listarAnimaisProfissional(){

    if(this->animais.empty()){
        cout << endl << "Nenhum animal cadastrado!" << endl;
        return;
    }

    if(this->profissionais.empty()){
        cout << endl << "Nenhum profissional cadastrado!" << endl;
        return;
    }

    this->printTitulo("Listar animais por profissional",60);

    string nome;
    do {
        cout << endl << "Digite o nome do profissional: ";
        cin >> nome;

        if(nome=="x" || nome =="X"){
            cout << endl << "Operação cancelada!" << endl;
            return;
        }

        if (this->findProfissional(nome)==nullptr) {
            cout << endl << "Profissional não encontrado!" << endl;
        }
    } while (this->findProfissional(nome)==nullptr);

    if (this->findProfissional(nome)->getTipo()==tipoVeterinario) {
        auto lista = listaAnimaisProfissional(nome,true);
    } else {
        auto lista = listaAnimaisProfissional(nome,false);
    }
}

/**
 * @brief Metodo para cadastrar um novo profissional(veterinario ou tratador)
 * @details Metodo primeir pede os dados inicias como nome,idade,telefone, e vai atribuindo, depois pergunta o tipo de profissional, dependendo do tipo, ele pede informações referente a cada um.
 */
void PetFera::cadastrarProfissional(){
    string nome;
    string idade;
    string fone;
    string op;
    char nivel;
    string crmv;
    Profissional* criado = nullptr;

    this->printTitulo("Cadastrar Profissional",60);

    do {
        cout << "Nome: ";
        cin >> nome;

        if(nome=="x" || nome =="X"){
            cout << endl << "Operação cancelada!" << endl;
            return;
        }

        if (this->findProfissional(nome)!=nullptr) {
            cout << endl << "Este nome já existe!" << endl;
        }
    } while (this->findProfissional(nome)!=nullptr);

    cout << "Idade: ";
    cin >> idade;

    cout << "Telefone: ";
    cin >> fone;

    do {
        cout << "(1) Veterinário | (2) Tratador: ";
        cin >> op;

        if (op!="1" && op!="2") {

            cout << endl << "Opção inválida! Tente novamente!" << endl;
        }
    } while (op!="1" && op!="2");

    if (op=="1") {

        cout << "Registro CRMV: ";
        cin >> crmv;

        criado = new Veterinario(nome, idade, fone, crmv);

    } else {
        do {
            cout << "Nível de Segurança:" << endl
                 << "(1) Verde" << endl
                 << "(2) Azul" << endl
                 << "(3) Vermelho" << endl;
            cin >> nivel;

            if (nivel!='1' && nivel!='2' && nivel!='3') {

                cout << endl << "Opção inválida! Tente novamente." << endl;
            }
        } while (nivel!='1' && nivel!='2'  && nivel!='3');

        switch(nivel){
            case '1': {
                criado = new Tratador(nome, idade, fone, nivelVerde);}
                break;
            case '2': {
                criado = new Tratador(nome, idade, fone, nivelAzul);}
                break;
            case '3': {criado = new Tratador(nome, idade, fone, nivelVermelho);}
                break;
        }
    }

    if (this->adicionaProfissional(criado)) {
        cout << endl << "Operação realizada com sucesso!" << endl;
    } else {
        cout << endl << "Erro!! Operação cancelada!" << endl;
    }
}

/**
 * @brief Metodo para remover um determinado profissional da loja
 * @details metodo recebe o nome do profissional valida se ele existe e se for o caso ele remove ele do vetor
 */
void PetFera::removerProfissional(){

    if(this->profissionais.empty()){
        cout << "Nenhum profissional cadastrado!" << endl;
        return;
    }

    this->printTitulo("Remover Profissional",60);

    string nome;
    do {
        cout << "Nome: ";
        cin >> nome;

        if(nome=="x" || nome =="X"){
            cout << "Operação cancelada." << endl;
            return;
        }

        if (this->findProfissional(nome)==nullptr) {
            cout << "Profissional não encontrado! Tente novamente." << endl;
        }
    } while (this->findProfissional(nome)==nullptr);

    if (this->removeProfissional(nome)) {
        cout << endl << "Operação realizada com sucesso." << endl;
    } else {
        cout << endl << "Erro!! Operação cancelada." << endl;
    }
}
/**
 * @brief Metodo para alterar os dados de um profissional
* @details Metodo recebe o nome do profissional valida se ele existe e se for o caso pergunta qual dado vai se alterado, e dependendo do tipo do profissional ele adiciona no menu os dados referente a cada tipo.
 */
void PetFera::alterarProfissional(){

    Profissional* alterado = nullptr;
    string nome;
    char op;

    if(this->profissionais.empty()){
        cout << "Nenhum profissional cadastrado!" << endl;
        return;
    }

    this->printTitulo("Alterar Profissional",60);

    do {
        cout << "Nome do profissional: ";
        cin >> nome;

        if(nome=="x" || nome =="X"){
            cout << endl << "Operação cancelada!" << endl;
            return;
        }

        if (this->findProfissional(nome)==nullptr) {
            cout << endl << "Profissional não encontrado! Tente novamente!" << endl;
        }
    } while (this->findProfissional(nome)==nullptr);

    do {
        cout << endl << "Selecione um campo para alterar:" << endl
             << "(1) Nome" << endl
             << "(2) Idade" << endl
             << "(3) Telefone" << endl;

        if (this->findProfissional(nome)->getTipo() == tipoVeterinario) {
            cout << "(4) Registro CRMV" << endl;
        } else {
            cout << "(4) Nível de Segurança" << endl;
        }
        cin >> op;
        if (op!='1' && op!='2' && op!='3' && op!='4') {
            cout << endl << "Opção inválida! Tente novamente!" << endl;
        }
    } while (op!='1' && op!='2' && op!='3' && op!='4');

    alterado = this->alteraProfissional(this->findProfissional(nome), op);

    if (alterado) {
        cout << endl << *(alterado) << endl;
        cout << endl << "Operação realizada com sucesso!" << endl;
    } else {
        cout << endl << "Erro!! Operação cancelada." << endl;
    }
}

/**
 * @brief Metodo para consultar dados de um profissional ja cadastrador
 * @details Metodo receebe o nome do profissional valida, e se for o caso imprime os dados do profissional
 */
void PetFera::consultarProfissional() {

    if(this->profissionais.empty()) {
        cout << endl << "Nenhum profissional cadastrado!" << endl;
        return;
    }

    this->printTitulo("Consultar profissional",60);

    string nome;
    do {
        cout << "Digite o nome do profissional: ";
        cin >> nome;

        if(nome=="x" || nome =="X"){
            cout << endl << "Operação cancelada!" << endl;
            return;
        }

        if (this->findProfissional(nome)==nullptr) {
            cout << endl << "Profissional não encontrado!" << endl;
        }
    } while (this->findProfissional(nome)==nullptr);

    cout << endl << endl << *(this->findProfissional(nome)) << endl;
}

/**
 * @brief Metodo interno para adicionar animal no vetor
 *
 * @param novo
 * @return true
 * @return false
 */
bool PetFera::adicionaAnimal(Animal* novo){
    this->animais.push_back(novo);
    return true;
}

/**
 * @brief Metodo interno para Remover um animal da loja
 * @details Metodo recebe nome do animal depois tirar ele do vetor
 * @param nome Nome do animal
 */
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
/**
 * @brief Metodo interno para alterar o animal
 *@details metodo recebe os dados a serem alterados, e as alterações e aplica
 */
Animal* PetFera::alteraAnimal(Animal* alterado, int op){

    string auxStr;
    double auxDouble;
    string sexo;

    switch(op) {
        case 0:{
            cout << endl << "Digite o novo nome: ";
            cin >> auxStr;
            alterado->setNome(auxStr);
        }
            break;

        case 1:{
            cout << endl << "Digite a nova idade: ";
            cin >> auxStr;
            alterado->setIdade(auxStr);
        }
            break;

        case 2:{
            do {
                cout << "Digite o novo sexo (M|F): ";
                cin >> sexo;
                if (sexo!="m" && sexo!="M" && sexo!="f" && sexo!="F") {
                    cout << "Opção inválida! Tente novamente." << endl << endl;
                }
            } while (sexo!="m" && sexo!="M" && sexo!="f" && sexo!="F");

            alterado->setSexo(sexo);
        }
            break;

        case 3:{
            cout << endl << "Digite o novo tamanho (cm): ";
            cin >> auxDouble;
            alterado->setTamanho(auxDouble);
        }
            break;

        case 4:{
            cout << endl << "Digite o novo peso (kg): ";
            cin >> auxDouble;
            alterado->setPeso(auxDouble);
        }
            break;

        case 5:{
            cout << endl << "Digite o novo valor (R$): ";
            cin >> auxDouble;
            alterado->setValor(auxDouble);
        }
            break;

        case 6:{

            do {
                cout << endl << "Digite o nome do novo Veterinário: ";
                cin >> auxStr;
                if (this->findProfissional(auxStr)==nullptr || this->findProfissional(auxStr)->getTipo()!=tipoVeterinario) {
                        cout << "Não encontrado! Tente novamente." << endl;
                }
            } while (this->findProfissional(auxStr)==nullptr || this->findProfissional(auxStr)->getTipo()!=tipoVeterinario);

            alterado->setVeterinario(dynamic_cast<Veterinario *>(this->findProfissional(auxStr)));
        }
            break;

        case 7:{

            do {
                cout << endl << "Digite o nome do novo Tratador: ";
                cin >> auxStr;
                if (this->findProfissional(auxStr)==nullptr || this->findProfissional(auxStr)->getTipo()!=tipoTratador) {
                    cout << "Não encontrado! Tente novamente." << endl;
                }
            } while (this->findProfissional(auxStr)==nullptr || this->findProfissional(auxStr)->getTipo()!=tipoTratador);

            alterado->setTratador(dynamic_cast<Tratador *>(this->findProfissional(auxStr)));
        }
            break;


        case 8:{

            auto tipo = alterado->getTipo();

            if (tipo==anfibioNativo || tipo==anfibioDomestico || tipo==anfibioExotico) {

                cout << endl << "Digite o novo tipo de pele: ";
                cin >> auxStr;
                dynamic_cast<Anfibio*>(alterado)->setTipoPele(auxStr);

            } else if (tipo==aveNativo || tipo==aveDomestico || tipo==aveExotico){

                cout << endl << "Digite o novo tamanho do bico: ";
                cin >> auxDouble;
                dynamic_cast<Ave*>(alterado)->setTamanhoBico(auxDouble);

            } else if (tipo==mamiferoNativo || tipo==mamiferoDomestico || tipo==mamiferoExotico){

                cout << endl << "Digite a nova cor da pelagem: ";
                cin >> auxStr;
                dynamic_cast<Mamifero*>(alterado)->setCorPelagem(auxStr);
            } else if (tipo==reptilNativo || tipo==reptilDomestico || tipo==reptilExotico){

                cout << endl << "Digite o novo tipo de veneno: ";
                cin >> auxStr;
                dynamic_cast<Reptil*>(alterado)->setTipoVeneno(auxStr);
            }
        }
            break;

        case 9:{

            auto tipo = alterado->getTipo();

            if (tipo==anfibioNativo) {

                cout << endl << "Digite o novo estado: ";
                cin >> auxStr;
                dynamic_cast<AnfibioNativo*>(alterado)->setEstado(auxStr);

            } else if (tipo==anfibioExotico){

                cout << endl << "Digite o novo país: ";
                cin >> auxStr;
                dynamic_cast<AnfibioExotico*>(alterado)->setPais_origem(auxStr);

            } else if (tipo==aveNativo || tipo==aveDomestico || tipo==aveExotico){

                cout << endl << "Digite a envergadura (cm): ";
                cin >> auxDouble;
                dynamic_cast<Ave*>(alterado)->setTamanhoEnvergadura(auxDouble);

            } else if (tipo==mamiferoNativo){

                cout << endl << "Digite o novo estado: ";
                cin >> auxStr;
                dynamic_cast<MamiferoNativo*>(alterado)->setEstado(auxStr);

            } else if (tipo==mamiferoExotico){

                cout << endl << "Digite o novo país: ";
                cin >> auxStr;
                dynamic_cast<MamiferoExotico*>(alterado)->setPais_origem(auxStr);

            } else if (tipo==reptilNativo){

                cout << endl << "Digite o novo estado: ";
                cin >> auxStr;
                dynamic_cast<ReptilNativo*>(alterado)->setEstado(auxStr);

            } else if (tipo==reptilExotico){

                cout << endl << "Digite o novo país: ";
                cin >> auxStr;
                dynamic_cast<ReptilExotico*>(alterado)->setPais_origem(auxStr);

            } else cout << "Erro interno! Opção inválida" << endl;
        }
            break;

        case 10:{

            auto tipo = alterado->getTipo();

            if (tipo==aveNativo){

                cout << endl << "Digite o novo estado: ";
                cin >> auxStr;
                dynamic_cast<AveNativo*>(alterado)->setEstado(auxStr);

            } else if (tipo==aveExotico){

                cout << endl << "Digite o novo país: ";
                cin >> auxStr;
                dynamic_cast<AveExotico*>(alterado)->setPais_origem(auxStr);

            } else cout << "Erro interno! Opção inválida" << endl;
        }
            break;
    }
    return alterado;
}

/**
 * @brief Metodo interno para listar animais de uma classe
 *
 * @param tipo
 * @return vector<Animal*>
 */
vector<Animal*> PetFera::listaClasseAnimal(tpAnimal tipo){

    vector<Animal*> classe;
    for (auto& animal : this->animais)
    {
        if (animal->getTipo()==tipo)
        {
            classe.push_back(animal);
        }
    }

    for (auto& animal : classe)
    {
        cout << (*animal) << endl;
    }

    return classe;
}

/**
 * @brief Metodo interno para listar animais de um determinado profissional
 * @details metodo recebeo nome do profissional e o tipo depois imprime os animais que ele esta responsavel
 */
vector<Animal*> PetFera::listaAnimaisProfissional(string nome_profissional,bool is_vet){

    vector<Animal*> lista;
    for (auto& animal : this->animais)
    {
        if(is_vet) {
            if (animal->getVeterinario()->getNome() == nome_profissional) {
                lista.push_back(animal);
            }
        } else {
            if (animal->getTratador()->getNome() == nome_profissional) {
                lista.push_back(animal);
            }
        }
    }
    cout << endl << endl;
    for (auto& animal : lista)
    {
        cout << (*animal) << endl;
    }

    return lista;

}

/**
 * @brief Metodo interno para adicionar profissional
 * @details Metodo recebe informações do novo profissional depois adiciona no vetor de profissionais
 *
 * @param novo
 * @return true
 * @return false
 */
bool PetFera::adicionaProfissional(Profissional* novo){
    this->profissionais.push_back(novo);
    return true;
}

/**
 * @brief Metodo para remover profissional
 * @details metodo recebe nome do profissional e remove ele 
 * @param nome Nome do profissional
 */
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

/**
 * @brief Metodo interno para alterar dados de um profissional
 * @details metodo recebe nome do profissional a ser alterado depois vai recebendo os dados e alterando
 *
 */
Profissional* PetFera::alteraProfissional(Profissional* alterado, char op){

    string aux;
    int nivel;

    switch(op){
        case '1':{
            cout << endl << "Digite o novo nome: ";
            cin >> aux;
            alterado->setNome(aux);
        }
        break;

        case '2':{
            cout << endl << "Digite a nova idade: ";
            cin >> aux;
            alterado->setIdade(aux);
        }
        break;

        case '3':{
            cout << endl << "Digite o novo telefone: ";
            cin >> aux;
            alterado->setTelefone(aux);
        }
        break;

        case '4':{
            if (alterado->getTipo()==tipoVeterinario) {
                cout << endl << "Digite o novo CRMV: ";
                cin >> aux;
                dynamic_cast<Veterinario*>(alterado)->setCRMV(aux);
            } else {
                do {
                    cout << "Novo nível de Segurança:" << endl
                         << "(1) Verde" << endl
                         << "(2) Azul" << endl
                         << "(3) Vermelho" << endl;
                    cin >> nivel;
                    if (nivel!=1 && nivel!=2 && nivel!=3) {
                        cout << "Opção inválida! Tente novamente." << endl;
                    }
                } while (nivel!=1 && nivel!=2 && nivel!=3);

                switch(nivel){
                    case 1: dynamic_cast<Tratador*>(alterado)->setNivel(nivelVerde);
                    case 2: dynamic_cast<Tratador*>(alterado)->setNivel(nivelAzul);
                    case 3: dynamic_cast<Tratador*>(alterado)->setNivel(nivelVermelho);
                }

            }
        }
        break;
        default: cout << "Erro interno!"<< endl;
    }
    return alterado;
}

/**
 * @brief Metodo interno para procurar um animal no vetor de animais
 *
 * @param nome
 * @return Animal*
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

/**
 * @brief Metodo interno para procurar um profissional no vetor de profissionais
 *
 * @param nome
 * @return Profissional*
 */
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

/**
 * @brief Metodo para imprimir titulo
 *
 * @param titulo
 * @param largura
 */
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

/**
 * @brief Metodo para confirmar se o tem funcionarios cadastrados antes de adicionar animal
 *
 * @return true
 * @return false
 */
bool PetFera::validaVetTrat() {

    int vet=0;
    int trat=0;

    if (profissionais.empty()){
        cout << endl << "Necessário cadastro prévio de ao menos 1 Veterinário e 1 Tratador.";
        return false;
    }

    for (auto& profissional : this->profissionais) {
        if (profissional->getTipo() == tipoVeterinario)  vet++;
        else trat++;
    }
    if (vet==0 ) {
        cout << endl << "Necessário cadastro prévio de ao menos 1 Veterinário.";
        return false;
    }
    if (trat==0 ) {
        cout << endl << "Necessário cadastro prévio de ao menos 1 Tratador.";
        return false;
    }

    return true;
}

/**
 * @brief Metodo para verificar se o animal é venenoso para atribuir apenas a tratadores com permissão
 *
 * @return true
 * @return false
 */
bool PetFera::validaNaoPerigosoVenenoso() {
    string op;
    do {
        cout << "O animal é perigoso ou venenoso? (S|N)";
        cin >> op;
        if (op!="s" && op!="S" && op!="n" && op!="N") {
            cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (op!="s" && op!="S" && op!="n" && op!="N");
    if (op=="s" || op=="S") {
        return false;
    } else return true;
}
void PetFera::carregarArquivo(){
    ifstream arqDados2("profissionais.csv");
    string linha;
	string palavra;
    Profissional* criado = nullptr;
	while(getline(arqDados2,linha)) {
        stringstream s(linha);
        vector <string> tokens; 
        while (getline(s, palavra, ',')) {
        	tokens.push_back(palavra); 
        }
        if(tokens.at(0)=="0"){
            criado = new Veterinario(tokens.at(1), tokens.at(2), tokens.at(3), tokens.at(4));
        }
        if(tokens.at(0)=="1"){
            switch(stoi(tokens.at(4))){
                case 0: {
                    criado = new Tratador(tokens.at(1), tokens.at(2), tokens.at(3), nivelVerde);}
                    break;
                case 1: {
                    criado = new Tratador(tokens.at(1), tokens.at(2), tokens.at(3), nivelAzul);}
                    break;
                case 2: {
                    criado = new Tratador(tokens.at(1), tokens.at(2), tokens.at(3), nivelVermelho);}
                    break;
            }
        }
        this->adicionaProfissional(criado);

    }
    cout << endl << "Arquivo dos Profissionais Carregado";

    ifstream arqDados1("animais.csv");
    string linha1;
	string palavra1;
    Animal* criado1 = nullptr;
	while(getline(arqDados1,linha1)) {
        stringstream s(linha1);
        vector <string> tokens1; 
        while (getline(s, palavra1, ',')) {
        	tokens1.push_back(palavra1); 
        }
        switch(stoi(tokens1.at(0))){
                case 0: {
                    criado1 = new AnfibioExotico(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),tokens1.at(9),tokens1.at(10));}
                    break;
                case 1: {
                    criado1 = new AnfibioNativo(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),tokens1.at(9),tokens1.at(10));}
                    break;
                case 2: {
                    criado1 = new Anfibio(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),tokens1.at(9));}
                    break;
                case 3: {
                    criado1 = new AveExotico(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),stod(tokens1.at(9)),stod(tokens1.at(10)),tokens1.at(11));}
                    break;
                case 4: {
                    criado1 = new AveNativo(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),stod(tokens1.at(9)),stod(tokens1.at(10)),tokens1.at(11));}
                    break;
                case 5: {
                    criado1 = new Ave(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),stod(tokens1.at(9)),stod(tokens1.at(10)));}
                    break;
                case 6: {
                    criado1 = new MamiferoExotico(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),tokens1.at(9),tokens1.at(10));}
                    break;
                case 7: {
                    criado1 = new MamiferoNativo(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),tokens1.at(9),tokens1.at(10));}
                    break;
                case 8: {
                    criado1 = new Mamifero(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),tokens1.at(9));}
                    break;
                case 9: {
                    criado1 = new ReptilExotico(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),tokens1.at(9),tokens1.at(10));}
                    break;
                case 10: {
                    criado1 = new ReptilNativo(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),tokens1.at(9),tokens1.at(10));}
                    break;
                case 11: {
                    criado1 = new Reptil(tokens1.at(1), tokens1.at(2), tokens1.at(3), stod(tokens1.at(4)),stod(tokens1.at(5)),stod(tokens1.at(6)),(dynamic_cast<Veterinario*>(findProfissional(tokens1.at(7)))),(dynamic_cast<Tratador*>(findProfissional(tokens1.at(8)))),tokens1.at(9));}
                    break;
        }
        this->adicionaAnimal(criado1);
        

    }
    cout << endl << "Arquivo dos Animais Carregado";
}
    

void PetFera::escreverArquivo(){
    ofstream arqDados2("profissionais.csv");
    for (auto profissional : this->profissionais)
    {
        arqDados2 << (profissional->getTipo()) << "," << (profissional->getNome())  << "," << (profissional->getIdade()) << "," << (profissional->getTelefone()) << ",";
        if ((profissional->getTipo())==1)
        {
            arqDados2 << (dynamic_cast<Tratador*>(profissional)->getNivel()) << endl;
        }
        if ((profissional->getTipo())==0)
        {
            arqDados2 << (dynamic_cast<Veterinario*>(profissional)->getCRMV()) << endl;
        }
    }
    ofstream arqDados("animais.csv");
    for (auto animal : this->animais)
    {   
        arqDados << (animal->getTipo()) << "," << (animal->getNome())  << "," << (animal->getIdade()) << "," << (animal->getSexo()) << "," << (animal->getTamanho()) << "," << (animal->getPeso()) << "," << (animal->getValor()) << "," << (animal->getVeterinario()->getNome()) << "," << (animal->getTratador()->getNome()) << ",";
        switch(animal->getTipo()){
            case 2: {
                arqDados << (dynamic_cast<Anfibio*>(animal)->getTipoPele()) << endl;
                break;
            }
            case 1: {
                arqDados << (dynamic_cast<Anfibio*>(animal)->getTipoPele()) << "," << (dynamic_cast<AnfibioNativo*>(animal)->getEstado()) << endl;
                break;
            }
            case 0: {
                arqDados << (dynamic_cast<Anfibio*>(animal)->getTipoPele()) << "," << (dynamic_cast<AnfibioExotico*>(animal)->getPais_origem())<< endl;
                break;
            }
            case 5: {
                arqDados << (dynamic_cast<Ave*>(animal)->getTamanhoBico()) << "," << (dynamic_cast<Ave*>(animal)->getTamanhoEnvergadura()) << endl;
                break;
            }
            case 4: {
                arqDados << (dynamic_cast<Ave*>(animal)->getTamanhoBico()) << "," << (dynamic_cast<Ave*>(animal)->getTamanhoEnvergadura()) << "," << (dynamic_cast<AveNativo*>(animal)->getEstado()) << endl;
                break;
            }
            case 3: {
                arqDados << (dynamic_cast<Ave*>(animal)->getTamanhoBico()) << "," << (dynamic_cast<Ave*>(animal)->getTamanhoEnvergadura()) << "," << (dynamic_cast<AveExotico*>(animal)->getPais_origem())<< endl;
                break;
            }
            case 8: {
                arqDados << (dynamic_cast<Mamifero*>(animal)->getCorPelagem()) <<  endl;
                break;
            }
            case 7: {
                arqDados << (dynamic_cast<Mamifero*>(animal)->getCorPelagem()) << "," << (dynamic_cast<MamiferoNativo*>(animal)->getEstado()) << endl;
                break;
            }
            case 6: {
                arqDados << (dynamic_cast<Mamifero*>(animal)->getCorPelagem()) << "," << (dynamic_cast<MamiferoExotico*>(animal)->getPais_origem())<< endl;
                break;
            }
            case 11: {
                arqDados << (dynamic_cast<Reptil*>(animal)->getTipoVeneno()) << endl;
                break;
            }
            case 10: {
                arqDados << (dynamic_cast<Reptil*>(animal)->getTipoVeneno()) << "," << (dynamic_cast<ReptilNativo*>(animal)->getEstado()) << endl;
                break;
            }
            case 9: {
                arqDados << (dynamic_cast<Reptil*>(animal)->getTipoVeneno()) << "," << (dynamic_cast<ReptilExotico*>(animal)->getPais_origem())<< endl;
                break;
            }
        }
    }
}   