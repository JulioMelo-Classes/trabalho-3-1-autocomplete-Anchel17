#include <iostream>
#include <string>

#include "../include/interface.hpp"
#include "../include/process.hpp"

using namespace std;

void Interface::recebeEntrada(){
    cout<<">>> Digite uma palavra e tecle ENTER ou <ctrl + d> para encerrar o programa: ";
    getline(cin, interf_entrada);


    if(cin.eof()){
        cout<<"\n>>> Saindo..."<<endl;
        exit(0);
    }

    cout<<">>> Resultados para \""<<interf_entrada<<"\":"<<endl;
}

void Interface::imprimeResult(vector<pair<unsigned int, string>>& interf_Dados){
    if(interf_Dados.empty()){
        cout<<"Sem resultados..."<<endl;
    }
    
    for(int i = 0; i < interf_Dados.size(); i++){
        cout<<interf_Dados[i].first<<" ";
        cout<<interf_Dados[i].second<<endl;
    }
    cout<<"\n\n\n";
}

string Interface::getEntrada(){
    return this -> interf_entrada;
}
