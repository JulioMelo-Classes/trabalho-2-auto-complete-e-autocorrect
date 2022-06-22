#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>
#include <vector>
#include "Autocomplete.hpp"
#include "Autocorrect.hpp"

class Interface{
    private:
        std::string m_entrada; //<! PREFIXO DADO PELO USUÁRIO
    public:
        /**
         * FUNÇÃO QUE REALIZA A LEITURA DA ENTRADA (LEITURA DO PREFIXO OU PALAVRA)
         * @return PREFIXO OU PALAVRA DADO(A) PELO USUÁRIO
         */
        std::string leitura_entrada();

        /**
         * IMPRIME A MENSAGEM INICIAL DA ENTRADA
         */
        void impressao_msg_inicial();

        /**
         * IMPRIME A INTERFACE COM AS PALAVRAS EM POTENCIAL PARA O AUTOCOMPLETE E PARA O AUTOCORRECT
         * @param dados_autocomplete REFERÊNCIA DA CLASSE AUTOCOMPLETE
         * @param dados_autocorrect REFERÊNCIA DA CLASSE AUTOCORRECT
         */
        void impressao_autocomplete_autocorrect(Autocomplete* dados_autocomplete, Autocorrect *dados_autocorrect);
};

#endif