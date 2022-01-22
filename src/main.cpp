#include <iostream>
#include <fstream>

#include "../include/database.hpp"
#include "../include/interface.hpp"
#include "../include/process.hpp"

using namespace std;

int main(int argc, char* argv[]){

    Database dado(argv[1]);

    Interface l_menu;
    Process l_p;

    while(true){
        l_menu.recebeEntrada();

        l_p.busca(dado.getDados(), l_menu.getEntrada());

        l_menu.imprimeResult();
        l_p.imprime();

        l_p.limpa();
    }
    return 0;
}
