#include "mamiferoExotico.hpp"
/**
 * @brief Constroi um novo objeto Mamifero Exotico:: Mamifero Exotico
 * 
 * @param nome Nome do mamifero exotico
 * @param idade Idade do mamifero exotico
 * @param sexo Sexo do mamifero exotico
 * @param tamanho Tamanho do mamifero exotico
 * @param peso Peso do mamifero exotico
 * @param valor Preço do mamifero exoticol
 * @param veterinario Veterinario responsavel pelo mamifero exotico
 * @param tratador Tratador responsavel pelo mamifero exotico
 * @param cor_da_pelagem Cor da pelagem do mamifero exotico
 * @param pais_origem Pais de origem do mamifero exotico
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
 * @brief Metodo para imprimir os dados do mamifero exotico
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& MamiferoExotico::imprimeDados(ostream& o) const{

    string tipoStr = "Mamífero Exótico";

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
      << fixed << setprecision(2) << right << "Pelagem: " << this->getCorPelagem()
      << setfill(' ') << setw(17) << right << "País: " << this->getPais_origem();

    return o;
}