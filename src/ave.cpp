#include "ave.hpp"
/**
 * @brief Instancia um objetivo do tipo Ave Doméstica
 * 
 * @param nome Nome da ave
 * @param idade Idade da ave
 * @param sexo Sexo da ave
 * @param tamanho Tamanho da ave
 * @param peso Peso da ave
 * @param valor Preço da ave
 * @param veterinario Veterinário responsável pela ave
 * @param tratador Tratador responsável pela ave
 * @param tamanho_do_bico Tamanho do pico da ave (cm)
 * @param tamanho_da_envergadura Envergadura das asas da ave (cm)
 */
Ave::Ave(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, double tamanho_do_bico,double tamanho_da_envergadura):
                Animal(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,aveDomestico),
                tamanho_do_bico(tamanho_do_bico),
                tamanho_da_envergadura(tamanho_da_envergadura) {}
/**
 * @brief Destroi o objeto do tipo Ave Doméstica
 * 
 */
Ave::~Ave() {}
/**
 * @brief Método set para definir o tamanho do bico da ave
 * 
 * @param tamanho_do_bico Define o tamanho do bico da ave
 */
void Ave::setTamanhoBico(double tamanho_do_bico){
    this->tamanho_do_bico = tamanho_do_bico;
}
/**
 * @brief Método get para obter o tamanho do bico da ave
 * 
 * @return Retorna o tamanho do bico da ave
 */
double Ave::getTamanhoBico() const{
    return this->tamanho_do_bico;
}
/**
 * @brief Metodo set para definir a envergadura das asas da ave
 * 
 * @param tamanho_da_envergadura Define a envergadura das asas da ave
 */
void Ave::setTamanhoEnvergadura(double tamanho_da_envergadura){
    this->tamanho_da_envergadura = tamanho_da_envergadura;
}
/**
 * @brief Metodo get para obter a envergadura das asas da ave
 * 
 * @return Retorna a envergadura das asas da ave
 */
double Ave::getTamanhoEnvergadura() const{
    return this->tamanho_da_envergadura;
}
/**
 * @brief Método para imprimir os dados da ave
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& Ave::imprimeDados(ostream& o) const{

    string tipoStr = "Ave Doméstica";

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
      << setfill(' ') << setw(15)
      << fixed << setprecision(2) << right << "Bico (cm):" << this->tamanho_do_bico
      << setfill(' ') << setw(20)
      << fixed << setprecision(2) << right << "Envergadura (cm):" << this->tamanho_da_envergadura;

    return o;
}

