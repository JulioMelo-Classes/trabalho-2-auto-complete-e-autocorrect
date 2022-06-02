#include <iostream>
//#include <ncurses.h>
#include <iterator>
#include <algorithm>
#include <cctype>
#include "Processamento.hpp"

using namespace std;

int main(int argc, char *argv[]){
    Processamento Processamento(argv[1], argv[2], argv[3]);
    string entrada;
    cout << ">>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar):";
    getline(cin, entrada);
    cout << entrada;
    Processamento.leitura_arquivos();
    return 0;
}