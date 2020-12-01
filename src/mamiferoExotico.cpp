#include "mamiferoExotico.hpp"
/**
 * @brief Constroi um novo objeto Mamifero Exotico:: Mamifero Exotico
 * 
 * @param nome Nome do animal
 * @param idade Idade do animal
 * @param sexo Sexo do animal
 * @param tamanho Tamanho do animal
 * @param peso Peso do animal
 * @param valor Preço do animal
 * @param veterinario Veterinario responsavel pelo animal
 * @param tratador Tratador responsavel pelo animal
 * @param cor_da_pelagem Cor da pelagem do mamifero
 * @param pais_origem Pais de origem do animal
 */
MamiferoExotico::MamiferoExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem,string pais_origem):
                Mamifero(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador, cor_da_pelagem),
                Exotico(pais_origem) {
    setTipo(mamiferoExotico);
}
/**
 * @brief Destroi o objeto Mamifero Exotico:: Mamifero Exotico
 * 
 */
MamiferoExotico::~MamiferoExotico() {}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& MamiferoExotico::imprimeDados(ostream& o) const{

    string tipoStr = "Mamífero Exótico";

    o << left << setfill(' ') << setw(15) << this->nome
      << setfill(' ') << setw(7) << right << this->idade << " anos"
      << setfill(' ') << setw(5) << this->sexo
      << setfill(' ') << setw(8)
      << fixed << setprecision(1) << right << this->tamanho << "cm"
      << setfill(' ') << setw(8)
      << fixed << setprecision(2) << right << this->peso << "kg"
      << setfill(' ') << setw(8)
      << fixed << setprecision(2) << right << "R$" << this->valor
      << setfill(' ') << setw(15) << right << "Vet.: " << this->veterinario->getNome()
      << setfill(' ') << setw(15) << right << "Trat.: " << this->tratador->getNome()
      << setfill(' ') << setw(22) << right << tipoStr
      << setfill(' ') << setw(18)
      << fixed << setprecision(2) << right << "Pelagem: " << this->getCorPelagem()
      << setfill(' ') << setw(17) << right << "País: " << this->getPais_origem();

    return o;
}