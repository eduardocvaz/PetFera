#include "anfibioExotico.hpp"
/**
 * @brief Instancia um novo objeto Anfibio Exótico
 * 
 * @param nome Nome do anfíbio exótico
 * @param idade Idade do anfíbio exótico
 * @param sexo Sexo do anfíbio exótico
 * @param tamanho Tamanho do anfíbio exótico
 * @param peso Peso do anfíbio exótico
 * @param valor Preço do anfíbio exótico
 * @param veterinario Veterinário responsavel pelo anfíbio exótico
 * @param tratador  Tratador responsavel pelo anfíbio exótico
 * @param tipo_pele Tipo de pele do anfíbio exótico
 * @param pais_origem Pais de origem do anfíbio exótico
 */
AnfibioExotico::AnfibioExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_pele, string pais_origem):
                Anfibio(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele),
                Exotico(pais_origem) {
    setTipo(anfibioExotico);
}
/**
 * @brief Destrói o objeto Anfibio Exótico
 */
AnfibioExotico::~AnfibioExotico() {}
/**
 * @brief Método para imprimir os dados do anfíbio exótico.
 * 
 * @param o Variável para guardar o stream da impressão
 * @return Retorna a impressão
 */
ostream& AnfibioExotico::imprimeDados(ostream& o) const{

    string tipoStr = "Anfíbio Exótico";

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
      << right << setfill(' ') << setw(22) << tipoStr
      << setfill(' ') << setw(15) << right << "Pele: " << this->tipo_pele
      << setfill(' ') << setw(17) << right << "País: " << this->getPais_origem();

    return o;
}