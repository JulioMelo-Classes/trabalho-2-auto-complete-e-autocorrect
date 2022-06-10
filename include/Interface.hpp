#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>
#include <vector>
#include "Autocomplete.hpp"
#include "Autocorrect.hpp"

class Interface{
    private:
        string m_entrada;
    public:
        string leitura_entrada();
        void impressao_msg_inicial();
        void impressao_autocomplete(Autocomplete* dados_autocomplete);
        void impressao_autocorrect(Autocorrect* dados_autocorrect);

};

#endif