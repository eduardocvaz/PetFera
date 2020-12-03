#include "aveNativo.hpp"
/**
 * @brief Constroi um novo objeto Ave Nativo:: Ave Nativo
 * 
 * @param nome Nome da ave nativa
 * @param idade Idade da ave nativa
 * @param sexo Sexo da ave nativa
 * @param tamanho Tamanho da ave nativa
 * @param peso Peso da ave nativa
 * @param valor Preço da ave nativa
 * @param veterinario Veterinario responsavel pela ave nativa
 * @param tratador Tratador responsavel pela ave nativa
 * @param tamanho_do_bico Tamanho do pico da ave nativa
 * @param tamanho_da_envergadura Envergadura das asas da ave nativa
 * @param estado 
 */
AveNativo::AveNativo(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, double tamanho_do_bico,double tamanho_da_envergadura,string estado):
                Ave(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tamanho_do_bico,tamanho_da_envergadura),
                Nativo(estado) {
    setTipo(aveNativo);
}
/**
 * @brief Destroi o objeto Ave Nativo:: Ave Nativo
 * 
 */
AveNativo::~AveNativo() {}
/**
 * @brief Metodo para imprimir os dados da ave nativa
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& AveNativo::imprimeDados(ostream& o) const{

    string tipoStr = "Ave Nativa";

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
      << fixed << setprecision(2) << right << "Bico (cm):" << this->getTamanhoBico()
      << setfill(' ') << setw(20)
      << fixed << setprecision(2) << right << "Envergadura (cm):" << this->getTamanhoEnvergadura()
      << setfill(' ') << setw(17) << right << "Estado: " << this->getEstado();

    return o;
}