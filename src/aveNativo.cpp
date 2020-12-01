#include "aveNativo.hpp"
/**
 * @brief Constroi um novo objeto Ave Nativo:: Ave Nativo
 * 
 * @param nome Nome do animal
 * @param idade Idade do animal
 * @param sexo Sexo do animal
 * @param tamanho Tamanho do animal
 * @param peso Peso do animal
 * @param valor Preço do animal
 * @param veterinario Veterinario responsavel pelo animal
 * @param tratador Tratador responsavel pelo animal
 * @param tamanho_do_bico Tamanho do pico da ave
 * @param tamanho_da_envergadura Envergadura das asas da ave
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
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& AveNativo::imprimeDados(ostream& o) const{

    string tipoStr = "Ave Nativa";

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
      << setfill(' ') << setw(15) << right << "Trat.:" << this->tratador->getNome()
      << setfill(' ') << setw(22) << right << tipoStr
      << setfill(' ') << setw(15)
      << fixed << setprecision(2) << right << "Bico (cm):" << this->getTamanhoBico()
      << setfill(' ') << setw(20)
      << fixed << setprecision(2) << right << "Envergadura (cm):" << this->getTamanhoEnvergadura()
      << setfill(' ') << setw(17) << right << "Estado: " << this->getEstado();

    return o;
}