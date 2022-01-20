#include <string>
#include "../include/process.hpp"

using namespace std;

void Process::achouArmazena(unsigned int &ocorr, string &termo){
    this -> proc_result.push_back({ocorr, termo});
}

void Process::busca(vector<pair<unsigned int, string>> dados, string termo){
    //Algoritmo para buscar os termos
}
