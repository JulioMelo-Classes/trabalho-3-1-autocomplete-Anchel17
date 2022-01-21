#include "../include/database.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void Database::teste(){
    for(int i = 0; i < 10; i++){
        cout<<data_dados[i].first<<" ";
        cout<<data_dados[i].second<<endl;
    }
}

Database::Database(string arquivo){
    ifstream arq;
    string l_string;                        //<!Variável para pegar os termos 
    string l_str2;                          //<!Variável para guardar a segunda metade da string

    arq.open(arquivo, ios::in);

    if(arq.is_open()){
        /*TA APAGANDO TODOS OS ESPAÇOS EM BRANCO, ASSIM ELE FUNCIONA*/
        while(getline(arq, l_string)){
            while(l_string.find_first_of("' '\n") != string::npos){
                size_t start = l_string.find_first_of("' '\n");    
                l_string.erase(l_string.begin() + start);
            }
            data_dadosBrutos.push_back(l_string);
        }

        //ISSO AQUI SÓ TÁ FUNCIONANDO PQ AS PALAVRAS N TEM ESPAÇO.
        for(int i = 1; i <= stoi(data_dadosBrutos[0]); i += 2){
            //Acha onde existe tabulação e cria uma substring a partir dessa tabulação
            //Assim, fica separado a ocorrência e o termo
            size_t pos = data_dadosBrutos[i].find("\t");
            l_str2 = data_dadosBrutos[i].substr(pos);
            
            //função lambda para deixar tudo com lowercase
            transform(l_str2.begin(), l_str2.end(), l_str2.begin(),
            [](char c){return tolower(c);});

            data_dados.push_back({stoul(data_dadosBrutos[i]), l_str2});
        }
        
        /*só para verificar se está armazenando corretamente
        for(auto it : data_dados){
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

//CRIAR AQUI O ALGORITMO PARA ORDENAR OS TERMOS POR ORDEM ALFABÉTICA

vector<pair<unsigned int, string>> Database::getDados(){
    return this -> data_dados;
}
