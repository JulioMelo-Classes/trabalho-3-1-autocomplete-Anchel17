#ifndef DATABASE_CPP
#define DATABASE_CPP

#include <vector>
#include <string>

/**
 * Classe responsável por processar e armazenar os dados
 */
class Database{
    private:

        unsigned int data_qtd;                      //<!Quantidade de termos a serem lidos do arquivo

        std::vector<std::string> data_dadosBrutos;                               //<<!Dados brutos do arquivo
        
        std::vector<std::pair<unsigned int, std::string>> data_dados;            //<!Dados tratados do arquivo

    public:

        /**
        *   Método construtor da classe banco de dados
        *   @param string contendo o nome do arquivo passado por linha de comando
        */
        Database(std::string arquivo);
};

#endif
