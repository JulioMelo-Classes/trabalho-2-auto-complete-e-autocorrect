#ifndef Processamento_hpp
#define Processamento_hpp

#include <iostream>
#include <vector>
using namespace std;

class Processamento{
    private:
        string m_palavras_ptbr;
        vector<pair<int, string>> m_dados;
    public:
        Processamento(string palavras_ptbr);
        void leitura_arquivo();
        void ordenacao_autocomplete();
        void ordenacao_autocorrect();
        vector<pair<int, string>> get_dados();
};

#endif // Processamento_hpp;
