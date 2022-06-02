#ifndef Processamento_hpp
#define Processamento_hpp

#include <iostream>
using namespace std;

class Processamento{
    private:
        string m_palavras_ptbr, m_cidades, m_palavras_eng;
    public:
        Processamento(string palavras_ptbr, string cidades, string palavras_eng);

        void leitura_arquivos();

};

#endif // Processamento_hpp;
