#include "aveExotico.hpp"
/**
 * @brief Constroi um novo objeto Ave Exotico:: Ave Exotico
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
 * @param pais_origem Pais de origem do animal
 */
AveExotico::AveExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor,Veterinario* veterinario, Tratador* tratador,double tamanho_do_bico,double tamanho_da_envergadura,string pais_origem):
                Ave(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tamanho_do_bico,tamanho_da_envergadura),
                Exotico(pais_origem) {
    setTipo(aveExotico);
}
/**
 * @brief Destroi o objeto Ave Exotico:: Ave Exotico
 * 
 */
AveExotico::~AveExotico() {}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& AveExotico::imprimeDados(ostream& o) const{

    string tipoStr = "Ave Exótica";

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
      << setfill(' ') << setw(17) << right << "País: " << this->getPais_origem();

    return o;
}