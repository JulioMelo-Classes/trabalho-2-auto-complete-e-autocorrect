#ifndef Ordenacao_hpp
#define Ordenacao_hpp

#include <vector>
#include <iostream>

class Ordenacao{
    public:
        std::vector<std::pair<int, std::string>> ordenacao_auto_complete(std::vector<std::pair<int, std::string>> dados);
        std::vector<std::pair<int, std::string>> ordenacao_peso(std::vector<std::pair<int, std::string>> dados_autocomplete);
};

#endif