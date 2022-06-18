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

int Autocorrect::dist_levenshtein(string str1, string str2, int len_str1, int len_str2){
    int custo;
    if(len_str1==0){
        return len_str2;
    }
    if(len_str2==0){
        return len_str1;
    }
    if(str1[len_str1-1] == str2[len_str2-1]){
        custo = 0;
    } else{
        custo = 1;
    }
    return min(min(dist_levenshtein(str1, str2, len_str1-1, len_str2)+1, dist_levenshtein(str1, str2, len_str1, len_str2-1)+1), dist_levenshtein(str1, str2, len_str1 - 1, len_str2 - 1)+custo);
}

void Autocorrect::auto_correct(Processamento* p, string prefixo){
    int dist_ed=0, verif=0, N;
    vector<pair<int, string>> Acorr;
    vector<pair<int, string>> C_dis_ed;
    Acorr = p->autocorrect(m_len_prefixo);
    for(auto pp : Acorr){
        dist_ed = dist_levenshtein(prefixo, pp.second, prefixo.length(), pp.second.length());
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
    }
    sort(C_dis_ed.begin(), C_dis_ed.end());
    if(!C_dis_ed.empty()){
        if(C_dis_ed.size() < 10){
            N = C_dis_ed.size();   
        }else{
            N = 7;
        }
        for(int tt=0; tt < N; tt++){
            m_dados_correct.push_back(make_pair(C_dis_ed[tt].first, C_dis_ed[tt].second));
        } 
    }
};

std::vector<std::pair<int, std::string>> Autocorrect::get_dados_correct(){
    return m_dados_correct;
};