# Trabalho-2-Autocomplete-e-Autocorrect
* Repositório destinado ao Trabalho II de Linguagem de Programação I, disciplina ministrada no semestre 2022.1.

# Introdução ao Autocomplete e Autocorrect
* O Autocomplete é um recurso usado para completar a palavra de forma automática ou estática, a partir do prefixo digitado pelo usuário.
* O Autocorrect é um recurso usado para correção de erros ortográficos ou de digitação de forma automática ou estática, a partir do prefixo digitado pelo usuário.

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
        
        ![f8b07524-5369-433f-9ea0-1a2c18f59134_](https://user-images.githubusercontent.com/82531511/174893542-e952489e-af22-491f-8f7d-24559b22ab9e.gif)


    - (b) ERRO DE CARACTERE ESPECIAL; <br />
        Para testar o erro de "Caractere Especial", execute o comando:
        ```
            ./words_complete_correct ../data/teste1.txt
        ```
        A saída esperada é:
        
        ![82a1b69d-63ee-41c9-8b6b-512a9cf91fb3_](https://user-images.githubusercontent.com/82531511/174893937-d9ab4a91-a813-416b-90b6-096ce92365df.gif)
        

    - (c) ERRO DE PESO NEGATIVO; <br />
        Para testar o erro "Peso Negativo", execute o comando:
        ```
            ./words_complete_correct ../data/teste2.txt
        ```
        A saída esperada é:
        
        ![c5b4e220-2f06-4843-adee-2154062dc9ff_](https://user-images.githubusercontent.com/82531511/174894295-5b749c7d-5a8e-4f50-9693-7b5583376490.gif)


2. Entrada:  
    - (a) ERRO DE ENTRADA INVALIDA - CARACTERE ESPECIAL; <br />
        Para testar o erro "Caractere Especial", digite na entrada de dados:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): br@
        ```
        A saída esperada é:

        ![01f902c8-0c2e-481a-9a7c-76d4f026a0ee_](https://user-images.githubusercontent.com/82531511/174894779-cfa48c31-ad13-420f-adae-91960e703b19.gif)


    - (b) ERRO DE ENTRADA INVALIDA - CARACTERE NUMÉRICO; <br />
        Para testar o erro "Caractere Numérico", digite na entrada de dados:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): var1
        ```
        A saída esperada é:

        ![6fc4c1ba-c19b-4676-a117-d19932fc32f3_](https://user-images.githubusercontent.com/82531511/174895934-05f81d11-b7cd-43ba-8c39-977d84726fdc.gif)
    

    -(c) ERRO DE ENTRADA INVALIDA - PALAVRA VAZIA; <br />
        Para testar o erro "Palavra Vazia", tecle ENTER na entrada de dados:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar):
        ```
        A saída esperada é:

    
3. Autocomplete e Autocorrect
    - (a) VALIDAÇÃO DA IMPLEMENTAÇÃO DO AUTOCOMPLETE E AUTOCORRECT; <br />
        Para testar o funcionamento do Autocomplete e Autocorrect, digite na entrada de dados:
        - (I) Teste 1:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): prep
        ```
        A saída esperada é:
        
        ![8eb0c2f4-dfb7-40e8-9444-396a658ec51f_](https://user-images.githubusercontent.com/82531511/174896868-81786cbc-c93e-4c36-9c6c-2bdd13049907.gif)


        - (II) Teste 2:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): zar
        ```
        A saída esperada é:
        
        ![64a3c6ab-9e15-433b-b069-bbd35314d6b8_](https://user-images.githubusercontent.com/82531511/174897577-3a550203-be41-4ef0-a22e-39e6a7ddcaeb.gif)


        - (III) Teste 3:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): lir
        ```
        A saída esperada é:
        
        ![a10e39ac-3e2c-4814-b505-bfa3e69b84f5_](https://user-images.githubusercontent.com/82531511/174897801-5c9c9a98-2b6d-4ff2-a9ce-78adc63b5908.gif)

        
        - (IV) Teste 4:
        ```
            >>> Digite uma palavra ou parte dela e digite ENTER (pressione Ctrl + D para finalizar): ter
        ```
        A saída esperada é:
        
        ![d9efe31d-75f6-4485-bfba-c09a453e3029_](https://user-images.githubusercontent.com/82531511/174898020-cf848f61-4722-4815-9085-f881298f8ab7.gif)


        
