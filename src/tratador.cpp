#include "tratador.hpp"
/**
 * @brief Constroi um novo objeto Tratador:: Tratador
 * 
 * @param nome Nome do tratador
 * @param idade Idade do tratador
 * @param telefone Numero para contato do tratador
 * @param nivel Nivel de segurança que o tratador tem
 */
Tratador::Tratador(string nome, string idade, string telefone, nivelSeguranca nivelseg):
                    Profissional(nome, idade, telefone, tipoTratador),
                    nivelseguranca(nivelseg) {}
/**
 * @brief Destroi o objeto Tratador:: Tratador
 * 
 */
Tratador::~Tratador() {}
/**
 * @brief Metodo set para definir o nivel de seguranção que o tratador tem
 * 
 * @param nivel Define o nivel de seguranção que o tratador tem
 */
void Tratador::setNivel(nivelSeguranca nivel){
    this->nivelseguranca = nivel;
}
/**
 * @brief Metodo set para definir o nivel de seguranção que o tratador tem
 * 
 * @return Retorna o nivel de seguranção que o tratador tem
 */
nivelSeguranca Tratador::getNivel() const{
    return this->nivelseguranca;
}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& Tratador::imprimeDados(ostream& o) const{

    string nivelStr;
    switch(nivelseguranca){
        case nivelVermelho: nivelStr = "Nível Vermelho";
        break;
        case nivelVerde: nivelStr = "Nível Verde";
        break;
        case nivelAzul: nivelStr = "Nível Azul";
        break;
    }

    o << left << setfill(' ') << setw(15) << this->nome
       << right << setfill(' ') << setw(7)  << this->idade << " anos"
       << right << setfill(' ') << setw(17)  << this->telefone
       << setfill(' ') << setw(15)
       << (this->tipo_profissional==tipoVeterinario ? "Veterinário" : "Tratador")
       << setfill(' ') << setw(16)  << nivelStr;

    return o;
}