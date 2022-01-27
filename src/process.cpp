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
    proc_Interface.imprimeResult(proc_result);
}

void Process::achouArmazena(unsigned int &ocorr, string &termo){
    this -> proc_result.push_back({termo, ocorr});
}

void Process::limpa(){
    proc_result.clear();
}
