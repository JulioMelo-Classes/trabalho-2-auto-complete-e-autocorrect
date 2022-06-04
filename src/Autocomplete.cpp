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

void Autocomplete::auto_complete(vector<pair<int, string>> dados){
    int verif=0;
    for(auto pp : dados){
        if(pp.second.find(m_prefixo) < pp.second.size()){
            if(pp.second[0] == m_prefixo[0]){
                string substring = pp.second.substr(0, m_prefixo.size());
                if(substring == m_prefixo){
                    for(auto qq : m_dados_com_prefixo){
                        if(pp.second == qq.second){
                            verif = 1;
                            break;
                        }
                    }
                    if(verif != 1){
                       m_dados_com_prefixo.push_back(make_pair(pp.first, pp.second)); 
                    }
                    verif = 0;
                }
            }
        }
    }
    //int pos_inicio = 0, pos_fim = (int)(m_dados.size()-1);
    //vector<pair<int, string>>::iterator it1;
    //vector<pair<int, string>>::iterator it2;
    /*if(pp.second.find(prefixo) < pp.second.size()){
                    m_dados_com_prefixo.push_back(make_pair(pp.first, pp.second));
                }*/
    /*while(pos_inicio <= pos_fim){
        int pos_meio = (int)((pos_inicio + pos_fim) / 2);
        if((int)(m_dados[pos_meio].second[0]) == (int)(prefixo[0])){
            if(m_dados[pos_meio].second.find(prefixo) < m_dados[pos_meio].second.size()){
                m_dados_com_prefixo.push_back(make_pair(m_dados[pos_meio].first, m_dados[pos_meio].second));
            }
        }
        if((int)(m_dados[pos_meio].second[0]) > (int)(prefixo[0])){
            pos_fim = (pos_meio - 1);
        } else if((int)(m_dados[pos_meio].second[0]) < (int)(prefixo[0])){
            pos_inicio = (pos_meio + 1);
        }
        cout << pos_inicio << pos_fim << endl;
    }*/
    /*for(int qq=0; qq < m_dados_com_prefixo.size(); qq++){
        cout << m_dados_com_prefixo[qq].first << " " << m_dados_com_prefixo[qq].second << endl;
    }*/
};

std::vector<std::pair<int, std::string>> Autocomplete::get_dados_com_prefixo(){
    return m_dados_com_prefixo;
};