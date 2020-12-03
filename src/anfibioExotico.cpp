#include "anfibioExotico.hpp"
/**
 * @brief Constroi um novo objeto Anfibio Exotico:: Anfibio Exotico
 * 
 * @param nome Nome do anfibio exotico
 * @param idade Idade do anfibio exotico
 * @param sexo Sexo do anfibio exotico
 * @param tamanho Tamanho do anfibio exotico
 * @param peso Peso do anfibio exotico
 * @param valor Preço do anfibio exotico
 * @param veterinario Veterinario responsavel pelo anfibio exotico
 * @param tratador  Tratador responsavel pelo anfibio exotico
 * @param tipo_pele Tipo de pele do anfibio exotico
 * @param pais_origem Pais de origem do anfibio exotico
 */
AnfibioExotico::AnfibioExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_pele, string pais_origem):
                Anfibio(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele),
                Exotico(pais_origem) {
    setTipo(anfibioExotico);
}
/**
 * @brief Destroi o objeto Anfibio Exotico:: Anfibio Exotico
 * 
 */
AnfibioExotico::~AnfibioExotico() {}
/**
 * @brief Metodo para imprimir os dados do anfibio exotico
 * 
 * @param o Varivel para guardar impressão
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