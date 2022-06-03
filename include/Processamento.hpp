#ifndef Processamento_hpp
#define Processamento_hpp

#include <iostream>
#include <vector>
using namespace std;

class Processamento{
    private:
        string m_palavras_ptbr;
        vector<pair<int, string>> m_dados;
        vector<pair<int, string>> m_dados_com_prefixo;
    public:
        Processamento(string palavras_ptbr);
        void leitura_arquivos();
        void busca(string prefixo);
        void ordenacao();

};

#endif // Processamento_hpp;
