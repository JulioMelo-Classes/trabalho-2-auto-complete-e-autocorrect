#ifndef Autocorrect_hpp
#define Autocorrect_hpp

#include <iostream>
#include <vector>
#include "Processamento.hpp"
class Autocorrect{
    private:
        std::vector<std::pair<int, std::string>> m_dados_correct;
        int m_len_prefixo;
    public:
        Autocorrect(int len_prefixo);
        //void auto_correct(std::vector<std::pair<int, std::string>> dados, std::string prefixo);
        void auto_correct(Processamento* p, std::string prefixo);
        std::vector<std::pair<int, std::string>> get_dados_correct();
};

#endif