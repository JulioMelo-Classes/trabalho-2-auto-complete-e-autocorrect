#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include <functional>
#include "Ordenacao.hpp"

using namespace std;

vector<pair<int, string>> Ordenacao::ordenacao_auto_complete(vector<pair<int, string>> dados){
    sort(dados.begin(), dados.end(),
            [] (const auto &x, const auto &y) {return x.second < y.second; });
    return dados;
};

std::vector<std::pair<int, std::string>> Ordenacao::ordenacao_peso(std::vector<std::pair<int, std::string>> dados){
    sort(dados.begin(), dados.end());
    reverse(dados.begin(), dados.end());
    //sort(dados.begin(), dados.end(), greater<int>());
    return dados;
};

std::vector<std::pair<int, std::string>> Ordenacao::ordenacao_auto_correct(std::vector<std::pair<int, std::string>> dados){
    sort(dados.begin(), dados.end(),
            [] (const auto &x, const auto &y) {return x.second.size() < y.second.size(); });
    return dados;
    /*for(auto pp : dados){
        cout << pp.first << " " << pp.second << endl;
    }*/
};