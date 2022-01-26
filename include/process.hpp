#ifndef PROCESS_HPP
#define PROCESS_HPP

#include "../include/interface.hpp"

#include <vector>
#include <iostream>

/**
 * Classe responsável por processar o resultado da busca
 * do autocomplete e devolver os termos já ordenados para
 * serem exibidos ao usuário
 */
class Process{
    private:
        std::vector<std::pair<std::string, unsigned int>>proc_result;             //<!O Vector resultante da busca

        Interface proc_Interface;                   //<!Objeto para chamar a função de imprimir os resultados
        
    public:

        /**
        *   método que faz a troca entre elementos a serem ordenados
        *   @param unsigned int x e y são as posições a serem trocadas entre si
        */
        void troca(unsigned int x, unsigned int y);

        /**
        *   Método responsável por ordenar os resultados
        *   O algoritmo utilizado foi o de ordenação por seleção
        */
        void ordena();


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
        void busca(std::vector<std::pair<std::string, unsigned int>> dados, std::string termo);

        /**
        *   Método para apenas limparo vector de resultados
        */
        void limpa();
};

#endif
