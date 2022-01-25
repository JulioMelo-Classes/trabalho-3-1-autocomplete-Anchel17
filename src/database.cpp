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
        while(getline(arq, l_string)){ //se vc vai fazer assim, melhor não ler a primeira string e apenas usar o size deste vetor!
            data_dadosBrutos.push_back(l_string);
        }

        for(int i = 1; i <= stoi(data_dadosBrutos[0]); i ++){ //se não lesse a primeira string apenas dadosBrutos.size() era suficiente, vc até pode usar dadosBrutos.size()-1
            /*aqui vc poderia usar um stringstream, assim os dados das cidades também funcionariam se iniciasse com número*/
            size_t pos = data_dadosBrutos[i].find_first_not_of("1 2 3 4 5 6 7 8 9 0");      //procura o primeiro caractere a não ser número
            l_str2 = data_dadosBrutos[i].substr(pos);                  //faz uma substring a partir da primeira posição a não ser um número
            data_dadosBrutos[i].erase(data_dadosBrutos[i].begin() + pos);           //apaga o conteúdo da string a partir da posição que não é número
    
            //função lambda para deixar tudo com lowercase
            transform(l_str2.begin(), l_str2.end(), l_str2.begin(),
            [](char c){return tolower(c);});

            data_dados.push_back({stoul(data_dadosBrutos[i]), l_str2});
        }

        //teste();
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
