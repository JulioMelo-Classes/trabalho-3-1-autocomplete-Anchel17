#include <iostream>
#include <string>

#include "../include/interface.hpp"

using namespace std;

void Interface::recebeEntrada(){
    cout<<"Digite uma palavra e tecle ENTER ou <ctrl + d> para encerrar o programa"<<endl;
    getline(cin, interf_entrada); 

    if(cin.eof()){
        cout<<"Saindo..."<<endl;
        exit(0);
    }
}

string Interface::getEntrada(){
    return this -> interf_entrada;
}
