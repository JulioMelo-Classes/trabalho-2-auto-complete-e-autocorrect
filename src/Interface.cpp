#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include "Interface.hpp"

using namespace std;

void Interface::impressao_autocomplete(std::vector<std::pair<int, std::string>> dados){
    cout << "Autocomplete" << endl;
    if(dados.empty()){
        cout << ">>> no match found <<<" << endl;
    } else{
        for(auto pp : dados){
            cout << pp.second << endl;
        }
    }
};

void Interface::impressao_autocorrect(std::vector<std::pair<int, std::string>> dados){
    cout << "Autocorrect" << endl;
    if(dados.empty()){
        cout << ">>> no match found <<<" << endl;
    } else{
        for(auto pp : dados){
            cout << pp.second << endl;
        }
    }
}
