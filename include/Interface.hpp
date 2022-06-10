#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>
#include <vector>
#include "Autocomplete.hpp"
#include "Autocorrect.hpp"

class Interface{
    public:
        void impressao_autocomplete(Autocomplete* dados_autocomplete);
        void impressao_autocorrect(Autocorrect* dados_autocorrect);
        //void impressao_autocomplete(std::vector<std::pair<int, std::string>> dados_autocomplete);
        //void impressao_autocorrect(std::vector<std::pair<int, std::string>> dados_autocorrect);

};

#endif