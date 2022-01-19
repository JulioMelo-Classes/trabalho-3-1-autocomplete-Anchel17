#include "../include/database.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Database::Database(string arquivo){
    ifstream arq;
    string l_string;                        //<!Variável para pegar a quantidade de termos 

    arq.open(arquivo, ios::in);

    if(arq.is_open()){
        while(getline(arq, l_string)){
            data_dadosBrutos.push_back(l_string);
        }

        //ISSO AQUI SÓ TÁ FUNCIONANDO PQ AS PALAVRAS N TEM ESPAÇO.
        /*for(int i = 1; i < stoi(data_dadosBrutos[0]); i += 2){
            data_dados.push_back({stoul(data_dadosBrutos[i]), data_dadosBrutos[i+1]});
        }*/

        /*for(auto it : data_dados){
            cout<<it.first<<" ";
            cout<<it.second<<endl;
        }*/
    }
    else{
        /*
        TALVEZ TRANSFORME ISSO EM UM MÉTODO PARA IMPRIMIR ESSA MENSAGEM
        NA CLASSE INTERFACE
        */
        cout<<"Erro! Verifique se digitou corretamente o destino do arquivo para leitura"<<endl;
        exit(0);
    }
}