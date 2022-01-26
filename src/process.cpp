#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#include "../include/process.hpp"

using namespace std;

void Process::troca(unsigned int x, unsigned int y){
    pair<string, unsigned int> l_tmp = proc_result[x];
	proc_result[x] = proc_result[y];
	proc_result[y] = l_tmp;
}

void Process::ordena(){
	for(int i = proc_result.size()-1; i >= 0; i--){
		for(int j = i; j < proc_result.size()-1; j++){
			if(proc_result[j].second < proc_result[j + 1].second){
				troca(j, j+1);
			}
			else{
				break;
			}
		}
	}
}

void Process::achouArmazena(unsigned int &ocorr, string &termo){
    this -> proc_result.push_back({termo, ocorr});
}

void Process::busca(vector<pair<string, unsigned int>> dados, string termo){
    //função lambda para deixar tudo com lowercase
    transform(termo.begin(), termo.end(), termo.begin(),
    [](char c){return tolower(c);});

    for(int i = 0; i < dados.size(); i++){
        while(dados[i].first.find_first_of("\t") != string::npos){
            size_t start = dados[i].first.find_first_of("\t");    ///tirar tabulação
            dados[i].first.erase(dados[i].first.begin() + start);
        }
        
        auto prefix = mismatch(termo.begin(), termo.end(), dados[i].first.begin());
        if(prefix.first == termo.end()){
            achouArmazena(dados[i].second, dados[i].first);
        }
    }

    ordena();
    proc_Interface.imprimeResult(proc_result);
}

void Process::limpa(){
    proc_result.clear();
}
