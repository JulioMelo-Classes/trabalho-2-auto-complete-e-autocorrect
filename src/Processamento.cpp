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

void Processamento::leitura_arquivos(){
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

void Processamento::ordenacao(){
    sort(m_dados.begin(), m_dados.end(),
            [] (const auto &x, const auto &y) {return x.second < y.second; });
};

void Processamento::busca(string prefixo){
    int pos_inicio = 0, pos_fim = m_dados.size()-1;
    for(auto pp : m_dados){
        if(pp.second[0] == prefixo[0]){

        }
        if(find(pp.second.begin(), pp.second.end(), prefixo[0]) != pp.second.end()){

        }
    }
    while(pos_inicio <= pos_fim){
        int pos_meio = (int)((pos_inicio + pos_fim) / 2);
        if(find(m_dados[pos_meio].second.begin(), m_dados[pos_meio].second.end(), prefixo) != m_dados[pos_meio].second.end()){
            m_dados_com_prefixo.push_back(make_pair(m_dados[pos_meio].first, m_dados[pos_meio].second));
        }
    }
};