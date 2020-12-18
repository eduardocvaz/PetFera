#include "mamifero.hpp"
/**
 * @brief Constrói um novo objeto Mamífero Doméstico
 * 
 * @param nome Nome do mamifero
 * @param idade Idade do mamifero
 * @param sexo Sexo do mamifero
 * @param tamanho Tamanho do mamifero
 * @param peso Peso do mamifero
 * @param valor Preço do mamifero
 * @param veterinario Veterinario responsavel pelo mamifero
 * @param tratador Tratador responsavel pelo mamifero
 * @param cor_da_pelagem Cor da pelagem do mamifero
 */
Mamifero::Mamifero(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem):
                Animal(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,mamiferoDomestico),
                cor_da_pelagem(cor_da_pelagem) {}
/**
 * @brief Destroi o objeto Mamifero Doméstico
 * 
 */
Mamifero::~Mamifero() {}
/**
 * @brief Metodo set para definir c
 * 
 * @param cor_da_pelagem Define a cor da pelagem do mamífero
 */
void Mamifero::setCorPelagem(string cor_da_pelagem) {
    this->cor_da_pelagem = cor_da_pelagem;
}
/**
 * @brief Metodo get para obter Metodo get para obter a cor da pelagem do mimefero
 * 
 * @return Retorna a cor da pelagem do mimefero
 */
string Mamifero::getCorPelagem() const{
    return this->cor_da_pelagem;
}
/**
 * @brief Metodo para imprimir os dados do mamifero
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& Mamifero::imprimeDados(ostream& o) const{

    string tipoStr = "Mamífero Doméstico";

    string sexo = this->getSexo();
    if(sexo=="M" || sexo=="m") {
        sexo = "Macho";
    } else{
        sexo = "Fêmea";
    }

    o << left << setfill(' ') << setw(15) << this->nome
      << left << setfill(' ') << setw(7) << right << this->idade << " anos"
      << setfill(' ') << setw(7) << sexo
      << setfill(' ') << setw(8)
      << fixed << setprecision(0) << right << this->tamanho << "cm"
      << setfill(' ') << setw(8)
      << fixed << setprecision(2) << right << this->peso << "kg"
      << setfill(' ') << setw(6) << right << "R$"
      << fixed << setprecision(2) << this->valor
      << setfill(' ') << setw(15) << right << "Vet.: " << this->veterinario->getNome()
      << setfill(' ') << setw(15) << right << "Trat.: " << this->tratador->getNome()
      << right << setfill(' ') << setw(22) << right << tipoStr
      << setfill(' ') << setw(18)
      << fixed << setprecision(2) << right << "Pelagem: " << this->cor_da_pelagem;

    return o;
}

