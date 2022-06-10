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

void Autocorrect::auto_correct(Processamento* p, string prefixo){
    int dist_ed=0, qq=0, verif=0, N;
    vector<pair<int, string>> C_dis_ed;
    p->ordenacao_autocorrect();
    for(auto pp : p->get_dados()){
        if(((pp.second.size()-1) == m_len_prefixo || (pp.second.size()-1) == m_len_prefixo+1)){ // SOMENTE AS PALAVRAS DE TAMANHO S OU S+1
            if((pp.second.size()-1) == m_len_prefixo){
                while(qq < m_len_prefixo){  // VERIFICA AS SUBSTITUIÇÕES NECESSARIAS PARA TRANFORMAR UMA STRING NA OUTRA
                    if(pp.second[qq] != prefixo[qq]){
                        dist_ed++;
                    }
                    qq++;
                }
            } else{
                dist_ed++;  // COMO É S+1 SOMA +1 DE IMEDIATO, SIMBOLIZANDO A INSERÇÃO NECESSARIA PARA TRANFORMAR UMA STRING NA OUTRA
                while(qq < m_len_prefixo){ //VERIFICA AS SUBSTITUIÇÕES NECESSARIAS PARA TRANFORMAR UMA STRING NA OUTRA
                    if(pp.second[qq] != prefixo[qq]){
                        dist_ed++;
                    }
                    qq++;
                }
            }
            if(dist_ed < m_len_prefixo){
                for(auto qq : C_dis_ed){ // VERIFICA SE A PALAVRA JÁ ESTÁ NO VETOR, PARA NÃO DAR PUSH EM PALAVRA REPETIDA
                    if(pp.second == qq.second){
                        verif = 1;
                        break;
                    }
                }
                if(verif != 1){
                     C_dis_ed.push_back(make_pair(dist_ed, pp.second));
                }
                verif=0;
            }
            dist_ed=0;
            qq=0;
        }
    }
    sort(C_dis_ed.begin(), C_dis_ed.end());
    if(!C_dis_ed.empty()){
        if(C_dis_ed.size() < 10){
            N = C_dis_ed.size();   
        }else{
            N = 10;
        }
        for(int tt=0; tt < N; tt++){
            m_dados_correct.push_back(make_pair(C_dis_ed[tt].first, C_dis_ed[tt].second));
        } 
    }
};

std::vector<std::pair<int, std::string>> Autocorrect::get_dados_correct(){
    return m_dados_correct;
};