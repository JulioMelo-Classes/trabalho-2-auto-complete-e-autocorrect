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
    int verif=0, N;
    vector<pair<int, string>> Acomp;
    Acomp = p->autocomplete(m_prefixo);
    sort(Acomp.begin(), Acomp.end());
    reverse(Acomp.begin(), Acomp.end());
    if(!Acomp.empty()){
        if(Acomp.size() < 10){
            N = Acomp.size();   
        }else{
            N = 10;
        }
        for(int tt=0; tt < N; tt++){
            m_dados_com_prefixo.push_back(make_pair(Acomp[tt].first, Acomp[tt].second));
        } 
    }
};

std::vector<std::pair<int, std::string>> Autocomplete::get_dados_com_prefixo(){
    return m_dados_com_prefixo;
};