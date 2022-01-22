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
}

void Interface::imprimeResult(){
    cout<<">>> Resultados para \""<<interf_entrada<<"\":"<<endl;
}

string Interface::getEntrada(){
    return this -> interf_entrada;
}
