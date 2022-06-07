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
    /*int verif=0;
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
    }*/
    int pos_inicio = 0, pos_fim = (int)(dados.size()-1), pos_meio=0;
    // lower_bound + lambda p/ deixar menor ao inves de maior ou igual
    // lambda como parametro igual no sort
    // upper_bound pegando o maior
        while(pos_inicio <= pos_fim){
            pos_meio = (int)((pos_inicio + pos_fim) / 2);
            if(dados[pos_meio].second[0] == m_prefixo[0]){
                string substring = dados[pos_meio].second.substr(0, m_prefixo.size());
                if(substring ==  m_prefixo){
                    m_dados_com_prefixo.push_back(make_pair(dados[pos_meio].first, dados[pos_meio].second));
                }
                break;
            } else if((int)(dados[pos_meio].second[0]) > (int)(m_prefixo[0])){
                pos_fim = pos_meio - 1;
            } else if((int)(dados[pos_meio].second[0]) < (int)(m_prefixo[0])){
                pos_inicio = pos_meio + 1;
            }
            cout << dados[pos_meio].second << endl;
            cout << (int)(dados[pos_meio].second[0]) << " " << (int)(m_prefixo[0]) << endl;
            cout << pos_inicio << " " << pos_fim << endl;
        }
        /*cout << dados[pos_meio].second << endl;
        cout << pos_meio << endl;
        cout << (int)(dados[pos_meio].second[0]) << " " << (int)(m_prefixo[0]) << endl;
        cout << pos_inicio << " " << pos_fim << endl;*/
    /*for(int qq=0; qq < m_dados_com_prefixo.size(); qq++){
        cout << m_dados_com_prefixo[qq].first << " " << m_dados_com_prefixo[qq].second << endl;
    }*/
};

std::vector<std::pair<int, std::string>> Autocomplete::get_dados_com_prefixo(){
    return m_dados_com_prefixo;
};
