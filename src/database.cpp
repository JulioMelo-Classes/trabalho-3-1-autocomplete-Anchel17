#include "../include/database.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

Database::Database(string arquivo){
    ifstream l_arq;
    string l_string;                        //<!Variável para pegar os termos 
    string l_str2;                          //<!Variável para guardar a segunda metade da string

    l_arq.open(arquivo, ios::in);

    if(l_arq.is_open()){
        while(getline(l_arq, l_string)){
            data_dadosBrutos.push_back(l_string);
        }

        for(int i = 1; i <= stoi(data_dadosBrutos[0]); i ++){
            size_t pos = data_dadosBrutos[i].find_first_not_of("1 2 3 4 5 6 7 8 9 0");      //procura o primeiro caractere a não ser número
            l_str2 = data_dadosBrutos[i].substr(pos);                  //faz uma substring a partir da primeira posição a não ser um número
            data_dadosBrutos[i].erase(data_dadosBrutos[i].begin() + pos);           //apaga o conteúdo da string a partir da posição que não é número
    
            //função lambda para deixar tudo com lowercase
            transform(l_str2.begin(), l_str2.end(), l_str2.begin(),
            [](char c){return tolower(c);});

            data_dados.push_back({l_str2, stoul(data_dadosBrutos[i])});
        }

        sort(data_dados.begin(), data_dados.end());

        l_arq.close();
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

void Database::busca(string termo){
    //função lambda para deixar tudo com lowercase
    transform(termo.begin(), termo.end(), termo.begin(),
    [](char c){return tolower(c);});

    for(int i = 0; i < data_dados.size(); i++){
        while(data_dados[i].first.find_first_of("\t") != string::npos){
            size_t start = data_dados[i].first.find_first_of("\t");    ///tirar tabulação
            data_dados[i].first.erase(data_dados[i].first.begin() + start);
        }
        
        auto prefix = mismatch(termo.begin(), termo.end(), data_dados[i].first.begin());
        if(prefix.first == termo.end()){
            proc_final.achouArmazena(data_dados[i].second, data_dados[i].first);
        }
    }

    proc_final.ordena();
}


vector<pair<string, unsigned int>> Database::getDados(){
    return this -> data_dados;
}
