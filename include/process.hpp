#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <vector>
#include <iostream>
/**
 * Classe responsável por processar o resultado da busca
 * do autocomplete e devolver os termos já ordenados para
 * serem exibidos ao usuário
 */
class Process{
    private:
        std::vector<std::pair<unsigned int, std::string>>proc_result;             //<!O Vector resultante da busca

    public:

    void teste();


        /**
        *   Método que vai armazenar no vector caso sejam encontrados termos
        *   compatíveis com a entrada
        *   @param string contendo o termo a ser armazenado
        *   @param int contendo a ocorrência do termo
        */
        void achouArmazena(unsigned int &ocorr, std::string &termo);

        /**
        *   Método para buscar um termo no vector de dados
        *   @param vector com referências aos dados
        *   @param string termo a ser procurado
        */
        void busca(std::vector<std::pair<unsigned int, std::string>> dados, std::string termo);

        /**
        *   Método para apenas limparo vector de resultados
        */
        void limpa();
};

#endif
