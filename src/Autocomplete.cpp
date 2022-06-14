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
    p->ordenacao_autocomplete();
    vector<pair<int, string>> C;
    for(auto pp : p->get_dados()){
        if(pp.second[0] == m_prefixo[0]){
            string substring = pp.second.substr(0, m_prefixo.size());
            if(substring == m_prefixo){
                for(auto qq : C){
                    if(pp.second == qq.second){
                        verif = 1;
                        break;
                    }
                }
                if(verif != 1){
                    C.push_back(make_pair(pp.first, pp.second)); 
                }
                verif = 0;
            }
        }
    }
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());
    if(!C.empty()){
        if(C.size() < 10){
            N = C.size();   
        }else{
            N = 10;
        }
        for(int tt=0; tt < N; tt++){
            m_dados_com_prefixo.push_back(make_pair(C[tt].first, C[tt].second));
        } 
    }
    /*[] (const auto &x) {return x.second.substring(0, m_prefixo.size()) == m_prefixo; };
    vector<string> vetor;
    for(auto pp : dados){
        vetor.push_back(pp.second);
    }
    vector<pair<int, string>>::iterator it1 = lower_bound(dados.begin(), dados.end(), m_prefixo, [] (const auto &x) {return x.second.substring(0, m_prefixo.size()) < m_prefixo; }); 
    cout << it1-dados.begin()+1 << endl;
    int pos_inicio = 0, pos_fim = (int)(dados.size()-1), pos_meio=0;*/
        /*while(pos_inicio <= pos_fim){
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
        if(pos_inicio == pos_fim){
            break;
        }*/
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