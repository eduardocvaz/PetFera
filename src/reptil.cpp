#include "reptil.hpp"
/**
 * @brief Constroi um novo objeto Reptil:: Reptil
 * 
 * @param nome Nome do reptil
 * @param idade Idade do reptil
 * @param sexo Sexo do reptil
 * @param tamanho Tamanho do reptil
 * @param peso Peso do reptil
 * @param valor Preço do reptil
 * @param veterinario Veterinario responsavel pelo reptil
 * @param tratador Tratador responsavel pelo reptil
 * @param tipo_veneno Tipo de veneno do Réptil
 */
Reptil::Reptil(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno) :
            Animal(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,reptilDomestico),
            tipo_veneno(tipo_veneno) {}
/**
 * @brief Destroi o objeto Reptil:: Reptil
 * 
 */
Reptil::~Reptil() {}
/**
 * @brief Metodo set para definir o tipo de veneno do réptil
 * 
 * @param tipo_veneno Define o tipo de veneno do réptil
 */
void Reptil::setTipoVeneno(string tipo_veneno){
    this->tipo_veneno = tipo_veneno;
}
/**
 * @brief  Metodo get para obter o tipo de veneno do réptil
 * 
 * @return Retorna o tipo de veneno do réptil
 */
string Reptil::getTipoVeneno() const{
    return this->tipo_veneno;
}
/**
 * @brief Metodo para imprimir os dados do reptil
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& Reptil::imprimeDados(ostream &o) const
{
    string tipoStr = "Réptil Doméstico";

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
      << fixed << setprecision(2) << right << "Veneno: " << this->tipo_veneno;

    return o;
}
