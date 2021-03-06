#include <iostream>
#include <fstream>

#include "../include/database.hpp"
#include "../include/interface.hpp"
#include "../include/process.hpp"

using namespace std;

int main(int argc, char* argv[]){

    Database dado(argv[1]);

    Interface l_menu;
    Process l_processa;

    while(true){
        l_menu.recebeEntrada();

        dado.busca(l_menu.getEntrada());

        l_processa.limpa();
    }
    return 0;
}
