#include "PetFera.h"

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

void menuPrincipal(PetFera* petfera) {
    char opcao;
    limpaTela();

    //implementar

}

int main()
{
    PetFera* petfera = new PetFera("(84) 4002-8922","Rua Mata Densa, 569, Bairro Floresta Encantada, Acrelândia - AC");

    menuPrincipal(petfera);

    delete petfera;

    return 0;
}