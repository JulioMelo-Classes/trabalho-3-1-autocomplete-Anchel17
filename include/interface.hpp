#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <vector>
#include <string>

/**
 * Classe responsável pela interação com o usuário
 * Vai imprimir as mensagens, receber a entrada e 
 * imprimir a saída
 */
class Interface{
    private:

        std::string interf_entrada;                  //<!Entrada recebida do usuário

    public:
        /**
        *   Método para receber a entrada
        */
        void recebeEntrada();
        
        
        /**
        *   Método para imprimir o vetor resultado
        *   @param vector referências ao vector a ser impresso
        */
        void imprimeResult(std::vector<std::pair<std::string, unsigned int>>& interf_Dados);

        /**
        *   Método para retornar a entrada
        *   @return string contendo a entrada digitada
        */
        std::string getEntrada();
};

#endif
