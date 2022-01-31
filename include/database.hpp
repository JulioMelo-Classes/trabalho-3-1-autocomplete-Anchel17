#ifndef DATABASE_CPP
#define DATABASE_CPP

#include <vector>
#include <string>

#include "../include/process.hpp"

/**
 * Classe responsável por processar e armazenar os dados
 */
class Database{
    private:

        unsigned int data_qtd;                      //<!Quantidade de termos a serem lidos do arquivo

        std::vector<std::string> data_dadosBrutos;                               //<<!Dados brutos do arquivo
        
        std::vector<std::pair<std::string, unsigned int>> data_dados;            //<!Dados tratados do arquivo

        Process proc_final;                           //<!Objeto para receber os resultados da busca

    public:

        /**
        *   Método construtor da classe banco de dados
        *   @param string contendo o nome do arquivo passado por linha de comando
        */
        Database(std::string arquivo);

        /**
        *   Método para buscar um termo no vector de dados
        *   @param string termo a ser procurado
        */
        void busca(std::string termo);

        /**
        * Método para retornar o vector de dados
        * @return vector com par de dados
        */
        std::vector<std::pair<std::string, unsigned int>>getDados();
};

#endif
