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
        /**
         * FUNÇÃO QUE REALIZA A LEITURA DA ENTRADA (LEITURA DO PREFIXO OU PALAVRA)
         * @return PREFIXO OU PALAVRA DADO(A) PELO USUÁRIO
         */
        string leitura_entrada();

        /**
         * IMPRIME A MENSAGEM INICIAL DA ENTRADA
         */
        void impressao_msg_inicial();

        /**
         * IMPRIME A INTERFACE COM AS PALAVRAS EM POTÊNCIAL PARA O AUTOCOMPLETE
         * @param dados_autocomplete REFERÊNCIA DA CLASSE AUTOCOMPLETE
         */
        void impressao_autocomplete(Autocomplete* dados_autocomplete);

        /**
         * IMPRIME A INTERFACE COM AS PALAVRAS EM POTÊNCIAL PARA O AUTOCORRECT
         * @param dados_autocorrect REFERÊNCIA DA CLASSE AUTOCORRECT
         */
        void impressao_autocorrect(Autocorrect* dados_autocorrect);
};

#endif