#ifndef Processamento_hpp
#define Processamento_hpp

#include <iostream>
#include <vector>

class Processamento{
    private:
        std::string m_palavras_ptbr; //<! NOME DO ARQUIVO QUE CONTEM A BASE DE PALAVRAS 
        std::vector<std::pair<int, std::string>> m_dados; //<! VETOR DE PARES CONTENDO A BASE DE PALAVRAS
    public:
        /**
         * CRIA UM CONSTRUTOR PROCESSAMENTO QUE RECEBE O NOME DO ARQUIVO COM A BASE DE PALAVRAS 
         * @param palavras_ptbr NOME DO ARQUIVO COM A BASE DE PALAVRAS
         */
        Processamento(std::string palavras_ptbr);

        /**
         * REALIZA A ABERTURA E LEITURA LINHA A LINHA DO ARQUIVO COM A BASE DE PALAVRAS
         */
        void leitura_arquivo();

        /**
         * IMPLEMENTAÇÃO DE BUSCA BINÁRIA REALIZADA PELAS FUNÇÕES lower_bound() E upper_bound()
         * PARA FAZER UM RECORTE NA BASE DE DADOS GERAL DE ACORDO COM A PALAVRA OU PREFIXO DADO
         * @param prefixo PALAVRA OU PREFIXO DADO PELO USUÁRIO
         * @return VETOR DE PARES CONTENDO AS PALAVRAS EM POTENCIAL PARA O AUTOCOMPLETE 
         */
        std::vector<std::pair<int, std::string>> autocomplete(std::string prefixo);

        /**
         * FILTRAGEM DA BASE DE DADOS GERAL, PEGANDO SOMENTE AS PALAVRAS QUE POSSUEM TAMANHO S OU S+1, EM QUE
         * S É O TAMANHO DO PREFIXO OU PALAVRA DADA PELO USUÁRIO
         * @param len_prefixo TAMANHO DO PREFIXO
         * @return VETOR COM AS PALAVRAS DE TAMANHO S OU S+1 
         */
        std::vector<std::pair<int, std::string>> autocorrect(int len_prefixo);

        /**
         * RECEBE A ENTRADA DADA PELO USUÁRIO NA LEITURA DA ENTRADA E VERIFICA CARACTERE A CARACTERE SE É VÁLIDA, OU SEJA,
         * 1° NÃO POSSUI CARACTERE ESPECIAL;
         * 2° NÃO POSSUI NÚMEROS;
         * 3° NÃO É VAZIA;
         * @param entrada PREFIXO/PALAVRA DADA PELO USUÁRIO
         */
        bool validacao_entrada(std::string entrada);

        /**
         * ABRE O ARQUIVO E VERIFICA SE É UM ARQUIVO VÁLIDO PARA SER USADO PELO PROGRAMA
         * VERIFICAÇÕES:
         * 1° EXISTÊNCIA DO ARQUIVO;
         * 2° PRESENÇA DE PALAVRA COM CARACTERE ESPECIAL;
         * 3° PRESENÇA DE PESO NEGATIVO;
         * @return UM VALOR LÓGICO INDICANDO SE A ENTRADA É VALIDA OU NÃO
         */
        bool validacao_arquivo();
};

#endif
