#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include "Interface.hpp"

using namespace std;

void Interface::impressao_autocomplete(std::vector<std::pair<int, std::string>> dados){
    if(dados.empty()){
        cout << ">>> no match found <<<" << endl;
    } else{
        cout << "Autocomplete" << endl;
        for(auto pp : dados){
            cout << pp.second << endl;
        }
    }
};

