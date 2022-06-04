#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include "Autocorrect.hpp"

using namespace std;

Autocorrect::Autocorrect(int S){
    m_len_prefixo = S;
};

void Autocorrect::auto_correct(vector<pair<int, string>> dados){
    for(auto pp : dados){
        if(pp.second.size() >= m_len_prefixo and pp.second.size() < m_len_prefixo+1){
            m_dados_correct.push_back(make_pair(pp.first, pp.second));
        }
    }
    /*for(auto qq : m_dados_correct){
        cout << qq.first << " " << qq.second << endl;
    }*/
};