#include "reptilExotico.hpp"
/**
 * @brief Constroi um novo objeto Reptil Exotico:: Reptil Exotico
 * 
 * @param nome Nome do reptil exotico
 * @param idade Idade do reptil exotico
 * @param sexo Sexo do reptil exotico
 * @param tamanho Tamanho do reptil exotico
 * @param peso Peso do reptil exotico
 * @param valor Preço do reptil exotico
 * @param veterinario Veterinario responsavel pelo reptil exotico
 * @param tratador Tratador responsavel pelo reptil exotico
 * @param tipo_veneno Tipo de veneno do Réptil
 * @param pais_origem Pais de origem do reptil exotico
 */
ReptilExotico::ReptilExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno,string pais_origem):
                Reptil(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador,tipo_veneno),
                Exotico(pais_origem) {
    setTipo(reptilExotico);
}
/**
 * @brief Destroi o objeto Reptil Exotico:: Reptil Exotico
 * 
 */
ReptilExotico::~ReptilExotico() {}
/**
 * @brief Metodo para imprimir os dados do reptil exotico
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& ReptilExotico::imprimeDados(ostream& o) const{

    string tipoStr = "Réptil Exótico";

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
      << fixed << setprecision(2) << right << "Veneno: " << this->getTipo()
      << setfill(' ') << setw(17) << right << "País: " << this->getPais_origem();

    return o;
}