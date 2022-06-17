# Autocomplete e Autocorrect

# Processo de Compilação e Execução do Programa
* Pré-Requisitos:
    - CMAKE; <br />

Para fazer a compilação (criação do executável) e executar o arquivo .exe criado, digite no terminal: <br />
```
    mkdir build
    cd build/
    cmake ..
    cmake --build . --target words_complete_correct
    ./words_complete_correct ../data/ptbrcorpus.txt
```
# Validação - Testes

1. Arquivo de Palavras:
    - (a) ERRO DE INEXISTÊNCIA;  <br />
        Para testar o erro de "Arquivo Inexistente", execute o comando:
        ```
            ./words_complete_correct ../data/teste_ex.txt
        ```
        A saída esperada é:
         ```
            Erro: Arquivo Inexistente, Arquivo: ../data/teste_ex.txt
         ```

    - (b) ERRO DE CARACTERE ESPECIAL; <br />
        Para testar o erro de "Caractere Especial", execute o comando:
        ```
            ./words_complete_correct ../data/teste1.txt
        ```
        A saída esperada é:
        ```
            Erro: Caractere especial encontrado, na linha: 13, palavra/peso: AN@LISE
        ```

    - (c) ERRO DE PESO NEGATIVO; <br />
        Para testar o erro "Peso Negativo", execute o comando:
        ```
            ./words_complete_correct ../data/teste2.txt
        ```
        A saída esperada é:
        ```
            Erro: Peso Negativo, na linha: 3, palavra/peso: -278988
        ```

2. Entrada:  
    - (a) ERRO DE ENTRADA INVALIDA - CARACTERE ESPECIAL; <br />
        Para testar o erro "Entrada invalida", digite na entrada de dados:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): br@
        ```
        A saída esperada é:

        ```
            Entrada Invalida - Caractere Especial encontrado. Digite novamente!!!
        ```


    - (b) ERRO DE ENTRADA INVALIDA - STRING VAZIA; <br />
        Para testar o erro "String Vazia", tecle ENTER na entrada de dados:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar):
        ```
        A saída esperada é:
        ```
            Entrada Invalida - Palavra Vazia. Digite novamente!!!
        ```

    -(c) ERRO DE ENTRADA INVALIDA - CARACTERE NUMERICO; <br />
        Para testar o erro "Caractere Numerico", digite na entrada de dados:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): var1
        ```
        A saída esperada é:

        ```
            Entrada Invalida - Caractere numerico encontrado. Digite novamente!!!
        ```
    
3. Autocomplete e Autocorrect
    - (a) VALIDAÇÃO DA IMPLEMENTAÇÃO DO AUTOCOMPLETE E AUTOCORRECT; <br />
        Para testar o funcionamento do Autocomplete e Autocorrect, digite na entrada de dados:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): prep
        ```
        A saída esperada é:

        ```
            Autocomplete
            PREPARACAO
            PREPARO
            PREPARAR
            PREPARADO
            PREPARA
            PREPARADOS
            PREPARADA
            PREPARADAS
            PREPARANDO
            Autocorrect
            PRECO
            PRESA
            PRESO
            PRESS
            PRETA
            PRETO
            PREVE
            AREAS
            AREIA
            ARENA
        ```

