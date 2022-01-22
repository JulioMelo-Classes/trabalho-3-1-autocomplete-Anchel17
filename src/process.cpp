#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#include "../include/process.hpp"

using namespace std;

void Process::teste(){
    for(int i = 0; i < proc_result.size(); i++){
        cout<<proc_result[i].first<<" ";
        cout<<proc_result[i].second<<endl;
    }
}

void Process::achouArmazena(unsigned int &ocorr, string &termo){
    this -> proc_result.push_back({ocorr, termo});
}

void Process::busca(vector<pair<unsigned int, string>> dados, string termo){
    //Algoritmo para buscar os termos
    //função lambda para deixar tudo com lowercase
    transform(termo.begin(), termo.end(), termo.begin(),
    [](char c){return tolower(c);});
        for(int i = 0; i < dados.size(); i++){
            while(dados[i].second.find_first_of("\t") != string::npos){
                size_t start = dados[i].second.find_first_of("\t");    ///tirar tabulação
                dados[i].second.erase(dados[i].second.begin() + start);
            }
            
            auto prefix = mismatch(termo.begin(), termo.end(), dados[i].second.begin());
            if(prefix.first == termo.end()){
                achouArmazena(dados[i].first, dados[i].second);
            }
    }
}

void Process::limpa(){
    proc_result.clear();
}
