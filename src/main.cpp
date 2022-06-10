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
    p->leitura_arquivo();
    /*Processamento Processamento(argv[1]);
    Processamento.leitura_arquivo();*/
    string entrada;
    cout << ">>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): ";
    while(cin >> ws >> entrada){
        for(int ii=0; ii < entrada.size(); ii++){
            entrada[ii] = toupper(entrada[ii]);
        }
        Acomp = new Autocomplete(entrada);
        Acorr = new Autocorrect(entrada.size());
        Acomp->auto_complete(p);
        Acorr->auto_correct(p, entrada);
        inter.impressao_autocomplete(Acomp);
        inter.impressao_autocorrect(Acorr);
        cout << ">>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): ";
        delete Acomp;
        delete Acorr;
    }
    /*cout << ">>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): ";
    for(int ii=0; ii < entrada.size(); ii++){
        entrada[ii] = toupper(entrada[ii]);
    }*/
    /*Autocomplete Autocomplete(entrada);
    Autocorrect Autocorrect(entrada.size());*/
    /*Acomp = new Autocomplete(entrada);
    Acorr = new Autocorrect(entrada.size());
    Acomp->auto_complete(p);
    Acorr->auto_correct(p, entrada);*/
    //cout << 23 << endl;
    /*for(auto qq : p->get_dados()){
        cout << qq.first << " " << qq.second << endl;
    }*/
    //inter.impressao_autocomplete(Acomp);
    //inter.impressao_autocorrect(Acorr);
    /*Autocomplete.auto_complete(p);
    Autocorrect.auto_correct(p, entrada);*/
    /*Autocomplete.auto_complete(Processamento.get_dados());
    Autocorrect.auto_correct(Processamento.get_dados(), entrada);
    inter.impressao_autocomplete(Autocomplete.get_dados_com_prefixo());
    inter.impressao_autocorrect(Autocorrect.get_dados_correct());*/
    return 0;
};