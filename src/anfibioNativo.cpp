#include "anfibioNativo.hpp"
/**
 * @brief Constroi um novo objeto Anfibio Exotico:: Anfibio Exotico
 * 
 * @param nome Nome do animal
 * @param idade Idade do animal
 * @param sexo Sexo do animal
 * @param tamanho Tamanho do animal
 * @param peso Peso do animal
 * @param valor Preço do animal
 * @param veterinario Veterinario responsavel pelo animal
 * @param tratador  Tratador responsavel pelo animal
 * @param tipo_pele Tipo de pele do anfibio
 * @param estado Estado do animal
 */
AnfibioNativo::AnfibioNativo(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_pele, string estado):
                Anfibio(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele),
                Nativo(estado) {
    setTipo(anfibioNativo);
}
/**
 * @brief Destroi o objeto Anfibio Nativo:: Anfibio Nativo
 * 
 */
AnfibioNativo::~AnfibioNativo() {}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& AnfibioNativo::imprimeDados(ostream& o) const{

    string tipoStr = "Anfíbio Nativo";

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
      << setfill(' ') << setw(15) << right << "Pele: " << this->tipo_pele
      << setfill(' ') << setw(17) << right << "Estado: " << this->getEstado();

    return o;
}