#include "anfibio.hpp"
/**
 * @brief Instancia um novo objeto do tipo Anfíbio Doméstico
 * @param nome Nome do anfíbio
 * @param idade Idade do anfíbio
 * @param sexo Sexo do anfíbio
 * @param tamanho Tamanho do anfíbio
 * @param peso Peso do anfíbio
 * @param valor Preço do anfíbio
 * @param veterinario Veterinário responsável pelo anfíbio
 * @param tratador Tratador responsável pelo anfíbio
 * @param tipo_pele Tipo de pele do anfíbio
 */
Anfibio::Anfibio(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador,string tipo_pele):
        Animal(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador, anfibioDomestico),
                tipo_pele(tipo_pele) {}

/**
 * @brief Destrói um objeto do tipo Anfíbio Doméstico
 */
Anfibio::~Anfibio() {}

/**
 * @brief Método set para atribuir o tipo de pele do anfíbio
 * @param tipo_pele Define o valor do tipo de pele do anfíbio
 */
void Anfibio::setTipoPele(string tipo_pele){
    this->tipo_pele = tipo_pele;
}
/**
 * @brief Método get para obter o tipo de pele do anfíbio
 * @return Retorna o tipo de pele do animal
 */
string Anfibio::getTipoPele() const{
    return this->tipo_pele;
}
/**
 * @brief Método para imprimir os dados do anfibio
 * 
 * @param o Variável para guardar o stream da impressão
 * @return Retorna a impressão
 */
ostream& Anfibio::imprimeDados(ostream& o) const{

    string tipoStr = "Anfíbio Doméstico";

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
      << setfill(' ') << setw(15) << right << "Trat.:" << this->tratador->getNome()
      << right << setfill(' ') << setw(22)  << tipoStr
      << setfill(' ') << setw(15) << right << "Pele: " << this->tipo_pele;

    return o;
}

