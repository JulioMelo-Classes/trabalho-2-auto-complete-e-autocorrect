#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>
#include <vector>

class Interface{
    public:
        void impressao_autocomplete(std::vector<std::pair<int, std::string>> dados_autocomplete);
        void impressao_autocorrect(std::vector<std::pair<int, std::string>> dados_autocorrect);

};

#endif