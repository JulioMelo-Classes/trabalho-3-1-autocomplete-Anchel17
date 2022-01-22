#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#include "../include/process.hpp"

using namespace std;

void Process::imprime(){
    if(proc_result.empty()){
        cout<<"Sem resultados..."<<endl;
    }
    
    for(int i = 0; i < proc_result.size(); i++){
        cout<<proc_result[i].first<<" ";
        cout<<proc_result[i].second<<endl;
    }
    cout<<"\n\n";
}

void Process::troca(unsigned int x, unsigned int y){
    pair<unsigned int, string> l_tmp = proc_result[x];
	proc_result[x] = proc_result[y];
	proc_result[y] = l_tmp;
}

void Process::ordena(){
	for(int i = proc_result.size()-1; i >= 0; i--){
		for(int j = i; j < proc_result.size()-1; j++){
			if(proc_result[j].first < proc_result[j + 1].first){
				troca(j, j+1);
			}
			else{
				break;
			}
		}
	}
}

void Process::achouArmazena(unsigned int &ocorr, string &termo){
    this -> proc_result.push_back({ocorr, termo});
}

void Process::busca(vector<pair<unsigned int, string>> dados, string termo){
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

    ordena();
}

void Process::limpa(){
    proc_result.clear();
}
