#include <iostream>
//#include <ncurses.h>
#include <iterator>
#include <algorithm>
#include <cctype>
#include "Processamento.hpp"
#include "Autocomplete.hpp"
#include "Ordenacao.hpp"
#include "Interface.hpp"

using namespace std;

int main(int argc, char *argv[]){
    Processamento Processamento(argv[1]);
    Processamento.leitura_arquivos();
    Ordenacao ord;
    Interface inter;
    string entrada;
    cout << ">>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): ";
    getline(cin, entrada);
    for(int ii=0; ii < entrada.size(); ii++){
        entrada[ii] = toupper(entrada[ii]);
    }
    Autocomplete Autocomplete(entrada);
    Autocomplete.auto_complete(ord.ordenacao_auto_complete(Processamento.get_dados()));
    inter.impressao_autocomplete(ord.ordenacao_peso(Autocomplete.get_dados_com_prefixo()));
    return 0;
};