#include "aveExotico.hpp"
/**
 * @brief Constroi um novo objeto Ave Exotico:: Ave Exotico
 * 
 * @param nome Nome da ave exotica
 * @param idade Idade da ave exotica
 * @param sexo Sexo da ave exotica
 * @param tamanho Tamanho da ave exotica
 * @param peso Peso da ave exotica
 * @param valor Preço da ave exotica
 * @param veterinario Veterinario responsavel pela ave exotica
 * @param tratador Tratador responsavel pela ave exotica
 * @param tamanho_do_bico Tamanho do pico da ave exotica
 * @param tamanho_da_envergadura Envergadura das asas da ave exotica
 * @param pais_origem Pais de origem da ave exotica
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
 * @brief Metodo para imprimir os dados da ave exotica
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& AveExotico::imprimeDados(ostream& o) const{

    string tipoStr = "Ave Exótica";

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
      << setfill(' ') << setw(17) << right << "País: " << this->getPais_origem();

    return o;
}