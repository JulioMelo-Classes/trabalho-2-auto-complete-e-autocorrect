#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include "Interface.hpp"

using namespace std;

void Interface::impressao_autocomplete(Autocomplete* dados){
    cout << "Autocomplete" << endl;
    if(dados->get_dados_com_prefixo().empty()){
        cout << ">>> no match found <<<" << endl;
    } else{
        for(auto pp : dados->get_dados_com_prefixo()){
            cout << pp.second << endl;
        }
    }
};

void Interface::impressao_autocorrect(Autocorrect* dados){
    cout << "Autocorrect" << endl;
    if(dados->get_dados_correct().empty()){
        cout << ">>> no match found <<<" << endl;
    } else{
        for(auto pp : dados->get_dados_correct()){
            cout << pp.second << endl;
        }
    }
};

string Interface::leitura_entrada(){
    getline(cin, m_entrada);
    for(int ii=0; ii < m_entrada.size(); ii++){
        m_entrada[ii] = toupper(m_entrada[ii]);
    }
    return m_entrada;
};

void Interface::impressao_msg_inicial(){
    cout << ">>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): ";
};
