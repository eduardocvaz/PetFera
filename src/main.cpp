#include "petfera.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void pausar() {
#if defined _WIN32
    system("pause");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"");
#elif defined (__APPLE__)
    system("read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"");
#endif
}

void limpaTela()
{
#if defined (_WIN32) && !defined (DEBUG)
    system("cls");
#elif (defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)) && !defined (DEBUG)
    system("clear");
#elif defined (__APPLE__) && !defined (DEBUG)
    system("clear");
#endif
}

void menuPrincipal(const shared_ptr<PetFera>& petfera) {
    char opcao;
    limpaTela();
	
	do {	 
		cout<< endl << "=======================================";
		cout<< endl << "1 - Cadastrar animal";
		cout<< endl << "2 - Remover animal";
		cout<< endl << "3 - Editar animal";
		cout<< endl << "4 - Listar animais por classe";
		cout<< endl << "5 - Listar dados de um animal";
		cout<< endl << "6 - Listar animais de um profissional";
		cout<< endl << "7 - Cadastrar profissional";
		cout<< endl << "8 - Remover profissional";
        cout<< endl << "9 - Editar profissional";
		cout<< endl << "---------------------------------------";
		cout<< endl << "X - Encerrar.";

		cout<< endl << endl << "Selecione uma opção: ";
		cin >> opcao;

		limpaTela();
		switch(opcao)
		{
			case '1' :{ petfera->cadastrarAnimal();}
			break;
			case '2' :{ petfera->removerAnimal();}
			break;
			case '3' :{ petfera->alterarAnimal();}
			break;
			case '4' :{ petfera->listarClasseAnimal();}
			break;
			case '5' :{ petfera->listarDadosAnimal();}
			break;
			case '6' :{ petfera->listarAnimaisProfissional();}
			break;
			case '7' :{ petfera->cadastrarProfissional();}
			break;
			case '8' :{ petfera->removerProfissional();}
			break;
			case '9' :{ petfera->alterarProfissional();}
			break;
			case 'X' :
			case 'x' :{ return;}
			default : cout << endl << "Opção inválida!";
		}
		cout << endl;

		pausar();
		limpaTela();
	
	} while (opcao != 'X' && opcao !='x');
}

int main()
{
    shared_ptr<PetFera> petfera(new PetFera("(84) 4002-8922","Rua Mata Densa, 569, Bairro Floresta Encantada, Acrelândia - AC"));

    menuPrincipal(petfera);

    //delete petfera;
    return 0;
}