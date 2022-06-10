#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include "Interface.hpp"

using namespace std;

//void Interface::impressao_autocomplete(std::vector<std::pair<int, std::string>> dados){
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

//void Interface::impressao_autocorrect(std::vector<std::pair<int, std::string>> dados){
void Interface::impressao_autocorrect(Autocorrect* dados){
    cout << "Autocorrect" << endl;
    if(dados->get_dados_correct().empty()){
        cout << ">>> no match found <<<" << endl;
    } else{
        for(auto pp : dados->get_dados_correct()){
            cout << pp.second << endl;
        }
    }
}
