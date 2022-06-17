#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "Processamento.hpp"

using namespace std;

Processamento::Processamento(string palavras_ptbr){
    m_palavras_ptbr = palavras_ptbr;
};

void Processamento::leitura_arquivo(){
    fstream arq_palavras;
    string line, palavra;
    int pos, freq;
    arq_palavras.open(m_palavras_ptbr, ios::in);
    while(!arq_palavras.eof()){
        getline(arq_palavras, line);
        for(int ii=0; ii < line.size(); ii++){
            if(isalpha(line[ii])){
                pos = ii-1;
                break;
            }
        }
        freq = stoi(line.substr(0, pos));
        palavra = line.substr(pos+1, -1);
        m_dados.push_back(make_pair(freq, palavra));
    }
    arq_palavras.close();
};

vector<pair<int, string>> Processamento::autocomplete(string prefixo){
    vector<pair<int, string>> Acomp;
    sort(m_dados.begin(), m_dados.end(),
            [] (const auto &x, const auto &y) {return x.second < y.second; });
    auto it1 = lower_bound(m_dados.begin(), m_dados.end(), prefixo,
                            [](pair<int, string> &s_v, string value){ return s_v.second < value;});
    auto it2 = upper_bound(m_dados.begin(), m_dados.end(), prefixo, 
                            [](string value, pair<int, string> &s_v){return value < s_v.second.substr(0, value.size());});
    int ii = it1-m_dados.begin();
    while(ii != it2-m_dados.begin()){
        Acomp.push_back(make_pair(m_dados[ii].first, m_dados[ii].second));
        ii++;
    }
    return Acomp;
};

vector<pair<int, string>> Processamento::autocorrect(int len_prefixo){
    vector<pair<int, string>> Acorr;
    sort(m_dados.begin(), m_dados.end(),
            [] (const auto &x, const auto &y) {return x.second.size() < y.second.size(); });
    for(auto pp : m_dados){
        if(((pp.second.size()-1) == len_prefixo || (pp.second.size()-1) == len_prefixo+1)){
            Acorr.push_back(make_pair(pp.first, pp.second));
        }
    }
    return Acorr;
};

bool Processamento::validacao_arquivo(){
    fstream arq_palavras;
    string line, palavra, freq;
    int pos, qnt_l=0;
    arq_palavras.open(m_palavras_ptbr, ios::in);
    if(!arq_palavras.is_open()){
        cout << "Erro: Arquivo Inexistente, Arquivo: " << m_palavras_ptbr << endl;
        return false;
    } else{
        while(!arq_palavras.eof()){
            getline(arq_palavras, line);
            qnt_l++;
            for(int ii=0; ii < line.size(); ii++){
                if(isalpha(line[ii])){
                    pos = ii-1;
                    break;
                }
            }
            freq = line.substr(0, pos);
            palavra = line.substr(pos+1, -1);
            for(int pp=0; pp < (int)palavra.size(); pp++){
                if(ispunct(palavra[pp]) && (palavra[pp] != '-')){
                    cout << "Erro: Caractere especial encontrado, na linha: " << qnt_l << ", palavra/peso: " << palavra << endl;;
                    return false;
                } else if(stoi(freq) < 0){
                    cout << "Erro: Peso Negativo, na linha: " << qnt_l << ", palavra/peso: " << freq << endl;
                    return false;
                }
            }
        }
    }
    arq_palavras.close();
    return true;
};

bool Processamento::validacao_entrada(string entrada){
    if(entrada.empty()){
        cout << "Entrada Invalida - Palavra Vazia. Digite novamente!!!" << endl;
        return false;
    }else{
        for(int ii=0; ii < (int)entrada.size(); ii++){
            if(ispunct(entrada[ii]) && (entrada[ii] != '-')){
                cout << "Entrada Invalida - Caractere Especial encontrado. Digite novamente!!!" << endl;
                return false;
            } else if(isdigit(entrada[ii])){
                cout << "Entrada Invalida - Caractere numerico encontrado. Digite novamente!!!" << endl;
                return false;
            }
        }
    }
    return true;
};

vector<pair<int, string>> Processamento::get_dados(){
    return m_dados;
};

