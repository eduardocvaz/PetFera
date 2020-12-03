#include "anfibioNativo.hpp"
/**
 * @brief Constroi um novo objeto Anfibio Nativo:: Anfibio Nativo
 * @param nome Nome do anfibio nativo
 * @param idade Idade do anfibio nativo
 * @param sexo Sexo do anfibio nativo
 * @param tamanho Tamanho do anfibio nativo
 * @param peso Peso do anfibio nativo
 * @param valor Preço do anfibio nativo
 * @param veterinario Veterinario responsavel pelo anfibio nativo
 * @param tratador  Tratador responsavel pelo anfibio nativo
 * @param tipo_pele Tipo de pele do anfibio nativo
 * @param estado Estado do anfibio nativo
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
 * @brief Metodo para imprimir os dados do anfibio nativo
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& AnfibioNativo::imprimeDados(ostream& o) const{

    string tipoStr = "Anfíbio Nativo";

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
      << setfill(' ') << setw(15) << right << "Pele: " << this->tipo_pele
      << setfill(' ') << setw(17) << right << "Estado: " << this->getEstado();

    return o;
}