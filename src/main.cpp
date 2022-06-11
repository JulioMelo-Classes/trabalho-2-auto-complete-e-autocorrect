#include <iostream>
//#include <ncurses.h>
#include <iterator>
#include <algorithm>
#include <cctype>
#include "Processamento.hpp"
#include "Autocomplete.hpp"
#include "Interface.hpp"
#include "Autocorrect.hpp"

using namespace std;

int main(int argc, char *argv[]){
    Processamento* p;
    Autocomplete* Acomp;
    Autocorrect* Acorr;
    Interface inter;
    p = new Processamento(argv[1]);
    if(!p->validacao_arquivo()){
        exit(-1);
    }else{
        p->leitura_arquivo();
        string entrada;
        inter.impressao_msg_inicial();
        while(cin >> ws){
            entrada = inter.leitura_entrada();
            while(true){
                if(p->validacao_entrada(entrada)){
                    break;
                }else{
                    inter.impressao_msg_inicial();
                    entrada = inter.leitura_entrada();
                }
            }
            Acomp = new Autocomplete(entrada);
            Acorr = new Autocorrect(entrada.size());
            Acomp->auto_complete(p);
            Acorr->auto_correct(p, entrada);
            inter.impressao_autocomplete(Acomp);
            inter.impressao_autocorrect(Acorr);
            inter.impressao_msg_inicial();
            delete Acomp;
            delete Acorr;
        }
    }
    return 0;
};