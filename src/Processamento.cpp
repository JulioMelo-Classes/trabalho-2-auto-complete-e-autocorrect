#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "Processamento.hpp"

using namespace std;

Processamento::Processamento(string palavras_ptbr, string cidades, string palavras_eng){
    m_palavras_ptbr = palavras_ptbr;
    m_cidades = cidades;
    m_palavras_eng = palavras_eng;
};

void Processamento::leitura_arquivos(){
    fstream arq1;
    fstream arq2;
    fstream arq3;
    string line;
    arq1.open(m_cidades, ios::in);
    while(!arq1.eof()){
        getline(arq1, line);
        cout << line << endl;
    }
    arq1.close();

}