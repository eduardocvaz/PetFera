#include "veterinario.hpp"
/**
 * @brief Constroi um novo objeto Veterinario:: Veterinario
 * 
 * @param nome Nome do veterinario
 * @param idade Idade do veterinario
 * @param telefone Numero de contato do veterinario
 * @param cod_CRMV Codigo emitido pelo Conselho Federal de Medicina Veterinária do veterinario
 */
Veterinario::Veterinario(string nome, string idade, string telefone, string cod_CRMV):
                        Profissional(nome, idade, telefone, tipoVeterinario),
                        cod_CRMV(cod_CRMV) {}
/**
 * @brief Destroi o objeto Veterinario:: Veterinario
 * 
 */
Veterinario::~Veterinario() {}
/**
 * @brief Metodo set para definir o codigo CRMV do veterinario
 * 
 * @param cod_CRMV Define o codigo CRMV do veterinario
 */
void Veterinario::setCRMV(string cod_CRMV){
    this->cod_CRMV = cod_CRMV;
}
/**
 * @brief Metodo get para obter o codigo CRMV do veterinario
 * 
 * @return Retorna o codigo CRMV do veterinario
 */
string Veterinario::getCRMV() const{
    return this->cod_CRMV;
}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& Veterinario::imprimeDados(ostream& o) const{

    string nivelStr;

    o << left << setfill(' ') << setw(15) << this->nome
      << setfill(' ') << setw(9) << this->idade
      << setfill(' ') << setw(17) << this->telefone
      << setfill(' ') << setw(12)
      << (this->tipo_profissional==tipoVeterinario ? "Veterinário" : "Tratador")
      << setfill(' ') << setw(15) << this->cod_CRMV;
    return o;
}