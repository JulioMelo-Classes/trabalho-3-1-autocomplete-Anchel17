#ifndef INTERFACE_HPP
#define INTERFACE_HPP

/**
 * Classe responsável pela interação com o usuário
 * Vai imprimir as mensagens, receber a entrada e 
 * imprimir a saída
 */
class Interface{
    private:

        std::string interf_entrada;                  //<!Entrada recebida do usuário

        //Process exit;                             //<!Objeto para chamar o vector de termos possíveis

    public:
        /**
        *   Método para receber a entrada
        */
        void recebeEntrada();

        /**
        *   Método para retornar a entrada
        *   @return string contendo a entrada digitada
        */
        std::string getEntrada();
};

#endif
