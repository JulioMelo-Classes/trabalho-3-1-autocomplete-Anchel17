#include <iostream>
#include <fstream>

#include "../include/database.hpp"
#include "../include/interface.hpp"

using namespace std;

int main(int argc, char* argv[]){

    Database dado(argv[1]);

    Interface menu;
    string entrada = "";

    while(true){
        menu.recebeEntrada();
    }
    return 0;
}
