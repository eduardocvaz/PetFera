/**
 * @file main.cpp
 * @author Eduardo C. Vaz & Leandro S. Ferreira (https://github.com/eduardocvaz/Projeto-PARTE-I)
 * @version 1.1
 * @date 2020-11-29
 */
#include "petfera.hpp"
#include <iostream>
/**
 * @mainpage Página Principal
 * 
 * @section intro_sec Documentação do Projeto PetFera
 * 
 * Documentação gerada com Doxygen
 *
 * @section proj_sec Projeto PetFera
 * 
 * Projeto de Linguagem de Programação 1
 * 
 * Cadastro de animais e profissionais de uma loja de animais.
 *
 * @section group_sec Grupo
 * Silvestre Estalonge
 *
 * @section aut_sec Autores
 * Dawerton Eduardo Carlos Vaz
 * Leandro Silva Ferreira Junior
 */
using std::cout;
using std::cin;
using std::endl;

/**
 * @brief Função para pausar a tela no terminal
 * @details
 * @param
 * @return void
 */
void pausar() {
    #if defined _WIN32
        system("pause");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
         system("read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"");
    #elif defined (__APPLE__)
        system("read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"");
    #endif
}

/**
 * @brief Função para limpar a tela no terminal
 * @details
 * @return void
 */
void limpaTela() {
    #if defined (_WIN32) && !defined (DEBUG)
        system("cls");
    #elif (defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)) && !defined (DEBUG)
        system("clear");
    #elif defined (__APPLE__) && !defined (DEBUG)
        system("clear");
    #endif
}

/**
 * @brief Função para gerar o menu principal para as ações disponíveis
 * @details
 * @param petfera Loja passada por parâmetro
 * @return void
 */
void menuPrincipal(shared_ptr<PetFera> petfera) {
    char opcao;
	petfera->carregarArquivo();
	do {
		cout<< endl << "-----------------------------------";
		cout<< endl << "(0) Cadastrar animal";
		cout<< endl << "(1) Remover animal";
		cout<< endl << "(2) Editar animal";
		cout<< endl << "(3) Listar classe de animais";
		cout<< endl << "(4) Listar dados de um animal";
		cout<< endl << "(5) Listar animais por profissional";
		cout<< endl << "(6) Cadastrar profissional";
		cout<< endl << "(7) Remover profissional";
        cout<< endl << "(8) Editar profissional";
        cout<< endl << "(9) Consultar profissional";
		cout<< endl << "-----------------------------------";
		cout<< endl << "(X) Encerrar.";

		cout<< endl << endl << "Selecione uma opção: ";
		cin >> opcao;

		limpaTela();
		switch(opcao)
		{
			case '0' :{ petfera->cadastrarAnimal();}
			break;
			case '1' :{ petfera->removerAnimal();}
			break;
			case '2' :{ petfera->alterarAnimal();}
			break;
			case '3' :{ petfera->listarClasseAnimal();}
			break;
			case '4' :{ petfera->listarDadosAnimal();}
			break;
			case '5' :{ petfera->listarAnimaisProfissional();}
			break;
			case '6' :{ petfera->cadastrarProfissional();}
			break;
			case '7' :{ petfera->removerProfissional();}
			break;
			case '8' :{ petfera->alterarProfissional();}
			break;
			case '9' :{ petfera->consultarProfissional();}
			break;
			case 'X' :
			case 'x' :{ return;}
			default : cout << endl << "Opção inválida!";
		}
		cout << endl;

//		pausar();
//		limpaTela();
	
	} while (opcao != 'X' && opcao !='x');
}

int main () {

    shared_ptr<PetFera> petfera(new PetFera("(84) 4002-8922","Rua Mata Densa, 569, Bairro Floresta Encantada, Amazônia - BR"));

    menuPrincipal(petfera);
	petfera->escreverArquivo();

    return 0;
}