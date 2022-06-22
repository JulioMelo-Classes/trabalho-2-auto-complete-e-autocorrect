#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include "Autocomplete.hpp"

using namespace std;

Autocomplete::Autocomplete(string pre){
    m_prefixo = pre;
};

void Autocomplete::auto_complete(Processamento* p){
    vector<pair<int, string>> Acomp;
    Acomp = p->autocomplete(m_prefixo);
    sort(Acomp.begin(), Acomp.end());
    reverse(Acomp.begin(), Acomp.end());
    m_dados_autocomplete = Acomp;
};

std::vector<std::pair<int, std::string>> Autocomplete::dados_autocomplete_interface(){
    std::vector<std::pair<int, std::string>> dados;
    int N;
    if(!m_dados_autocomplete.empty()){
        if(m_dados_autocomplete.size() < 10){
            N = m_dados_autocomplete.size();   
        }else{
            N = 7;
        }
        for(int tt=0; tt < N; tt++){
            dados.push_back(make_pair(m_dados_autocomplete[tt].first, m_dados_autocomplete[tt].second));
        } 
    }
    return dados;
};