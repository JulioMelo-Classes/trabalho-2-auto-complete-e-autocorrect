# Autocomplete e Autocorrect
* Repositório destinado ao Trabalho II de Linguagem de Programação I, disciplina ministrada em 2022.1.

# Introdução ao Autocomplete e Autocorrect
* O Autocomplete é um recurso usado para completar a palavra de forma automática ou estática, a partir do prefixo digitado pelo usuário.
* O Autocorrect é um recurso usado para correção de erros ortográficos ou de digitação de forma automática ou estática, a partir do prefixo digitado pelo usuário.

# Visualização da Implementação dos Recursos

![40ca1525-729a-4d3b-895f-c20e919b5fc1_](https://user-images.githubusercontent.com/82531511/174491799-8e3749a3-fd49-486b-9fd4-be1c801101f5.gif)

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
         ![68f1b22b-a37a-4eba-b00b-93d05fdab611_](https://user-images.githubusercontent.com/82531511/174498117-662ee297-b44f-4164-8fce-959f97029113.gif)


    - (b) ERRO DE CARACTERE ESPECIAL; <br />
        Para testar o erro de "Caractere Especial", execute o comando:
        ```
            ./words_complete_correct ../data/teste1.txt
        ```
        A saída esperada é:
        ![ad23f461-e6a2-4b21-bd4e-ed1a32ed6150_](https://user-images.githubusercontent.com/82531511/174498268-388298ae-0f56-4336-8ce1-ae2af1678fed.gif)


    - (c) ERRO DE PESO NEGATIVO; <br />
        Para testar o erro "Peso Negativo", execute o comando:
        ```
            ./words_complete_correct ../data/teste2.txt
        ```
        A saída esperada é:
        ![936dc55e-0996-49e6-8d60-4a9113146ea2_](https://user-images.githubusercontent.com/82531511/174498364-26f4bd6e-365b-46bc-959b-a82b6781de85.gif)


2. Entrada:  
    - (a) ERRO DE ENTRADA INVALIDA - CARACTERE ESPECIAL; <br />
        Para testar o erro "Caractere Especial", digite na entrada de dados:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): br@
        ```
        A saída esperada é:

        ```
            Entrada Invalida - Caractere Especial encontrado. Digite novamente!!!
        ```


    - (b) ERRO DE ENTRADA INVALIDA - CARACTERE NUMÉRICO; <br />
        Para testar o erro "Caractere Numérico", digite na entrada de dados:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): var1
        ```
        A saída esperada é:

        ```
            Entrada Invalida - Caractere Numerico encontrado. Digite novamente!!!
        ```
    
3. Autocomplete e Autocorrect
    - (a) VALIDAÇÃO DA IMPLEMENTAÇÃO DO AUTOCOMPLETE E AUTOCORRECT; <br />
        Para testar o funcionamento do Autocomplete e Autocorrect, digite na entrada de dados:
        - (I) Teste 1:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): prep
        ```
        A saída esperada é:
        ```
            Autocomplete           | Autocorrect
            PREPARACAO             | PARES
            PREPARO                | PEREZ
            PREPARAR               | PIRES
            PREPARADO              | POREM
            PREPARA                | PRECO
            PREPARADOS             | PRESA
            PREPARADA              | PRESO
        ```

        - (II) Teste 2:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): zar
        ```
        A saída esperada é:
        ```
            Autocomplete           | Autocorrect
            >>> no match found <<< | >>> no match found <<<
        ```

        - (III) Teste 3:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): lir
        ```
        A saída esperada é:
        ```
            Autocomplete           | Autocorrect
            >>> no match found <<< | DIA
        ```
        - (IV) Teste 4:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): ter
        ```
        A saída esperada é:
        ```
            Autocomplete           | Autocorrect
            TERMOS                 | >>> no match found <<<
            TERIA                  |
            TERMO                  |
            TERRAS                 |
            TERRITORIO             |
            TERCEIRA               |
            TEREM                  |
        ```


