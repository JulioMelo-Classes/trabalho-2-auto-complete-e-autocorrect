# Autocomplete e Autocorrect

### Sumário
1. [Introdução](#1-introdução)
2. [Autocomplete vs Autocorrect](#2-autocomplete-vs-autocorrect)
3. [Interface](#3-interface)
4. [Implementação e Modelagem](#4-implementação-e-modelagem)
5. [Saída](#5-saída)
6. [Validação e Testes](#6-validação-e-testes)

# 1-Introdução

Autocomplete é uma ferramenta comum em aplicações modernas. Enquanto o usuário digita, o programa prevê o quê o usuário está tentando digitar (usualmente uma palavra ou frase).

Segue abaixo um exemplo típico do Autocomplete e do Autocorrect:

<img src="./pics/wa.png" width="350">

<img src="./pics/auto_correct.png" width="350">

Tanto o Autocomplete quanto o Autocorrect são mais efetivos quando quando existe um número limitado de possibilidades mais prováveis. Por exemplo, a _Internet Movie Database_ usa essas duas soluções para mostrar os nomes dos possíveis filmes enquanto o usuário digita e para buscar por nomes mais prováveis caso haja um erro de digitação; _engines_ de busca usam essas técnicas para mostrar sugestões de busca e buscar resultados mais prováveis; celulares usam a técnica para acelerar a digitação de textos.

Nestes exemplos, as aplicações preveem qual a chance estar sendo digitada uma dada sentença e apresenta ao usuário uma lista das sentenças mais prováveis, na ordem decrescente de "peso". Os pesos de um conjunto de sentenças são determinados por vários fatores, tais como o volume de vendas de um determinado filme, a frequencia de busca de cada sentença no Google ou o histórico de palavras digitadas pelo usuário do celular. 

A performance desse tipo de sistema é uma característica critica. Por exemplo, considere uma _engine_ de busca que executa uma aplicação de autocomplete em um servidor. De acordo com alguns estudos, a aplicação tem apenas algo como 50ms para retornar uma lista de sugestões de forma que essa lista seja útil para o usuário, e a aplicação tem que executar esse processamento para cada tecla digitada **para cada usuário do sistema**. Já para o autocorrect essa restrição de tempo é um pouco menor uma vez que as sujestões de correção só aparecem após a busca ou quando o usuário terminou de digitar uma palavra.

# 2-Autocomplete vs Autocorrect

Neste trabalho iremos implementar um sistema simples de _autocomplete_ e _autocorrect_, ambos os problemas são abordados de formas diferentes, enquanto o autocomplete apenas usa
uma base de dados e o prefixo buscado, o autocorrect usa o [algoritmo da distancia de edição](https://pt.wikipedia.org/wiki/Dist%C3%A2ncia_Levenshtein).

De forma similar à outros trabalhos, para facilitar o processamento dos textos, as palavras a serem consideradas aqui não devem ter acentos e outros caracteres especiais mas podem ter espaços ou hífem. Você terá que tratar os dados das bases de dados ANTES de rodar o programa para que fiquem neste formato.

## 2.1-Autocomplete

Usando a base de dados fornecida no inicio do programa, nosso sistema tem um conjunto de palavras no formato `peso + sentença`, onde a `senteça` é uma string que pode ser um possível resultado de uma operação de autocomplete, e o peso é um inteiro que representa a relevancia daquela sentença na base de dados: quanto maior o valor do peso, maior a relevancia da sentença relacionada com ele. Abaixo é mostrado um exemplo de uma base de dados de entrada, chamada [wikitionary.txt](./data/wikitionary.txt), que representa a frequencia que algumas palavras aparecem em textos em Inglês.

```
5627187200	the
3395006400	of
2994418400	and
2595609600	to
1742063600	in
1176479700	i
1107331800	that
1007824500	was
879975500	his
        ...
392323	calves
```

Note que a palavra **"the"** é a mais frequente neste caso, uma vez que ela tem o maior valor de peso: 5627187200. Claro que esse dicionário não é completo, uma vez que ele contém apenas 10 mil palavras. Após processada a base de dados o nosso sistema de autocomplete deve ser capaz de mostrar ao usuário todas as palavras que iniciam com tal prefixo, ou alguma mensagem caso o prefixo não seja encontrado, por exemplo _"no match found"_.

## 2.2-Autocorrect

De forma similar ao autocomplete, o autocorrect usa a mesma base de dados, porém ao invés de buscar apenas por prefixos o programa deve buscar apenas por palavras de um determinado tamanho. Nesse caso usaremos ambas as informações de frequencia e de tamanho da plavra.

O algoritmo da distancia de edição é um algoritmo comum na computação que é usado para encontrar **qual é a menor quantidade de manipulações específicas que transforma uma string A na string B**. Existem diversas formas de computar essa distância bem como algumas operações que podem ser ignoradas ou consideradas para simplificar o problema. Neste caso iremos considerar apenas operações de remoção, adição ou mudança de caractere, o que resume o problema ao problema da [Distancia de Levenshtein](https://en.wikipedia.org/wiki/Edit_distance). 

Uma lida rápida no algoritmo você vai notar que ele resolve o problema de achar a distancia de edição entre duas strings A e B, no entanto nossa base de dados tem N strings todas elas possíveis candidatos à serem testadas. Se formos testar contra todas as palavras da base de dados o tempo de computação seria consideravelmente grande, uma vez que este é um problema de __natureza recursiva__. Para atacar essa caracterísitca, ao invés de testar uma dada sentença, contra todas as sentenças no banco, teste apenas contra as N palavras mais relevantes que tem tamanho entre S e S+1  onde S é o tamanho da palavra digitada pelo usuário. Ajuste o valor de N para que seja aceitável o tempo de execução do programa.

Veja que diferente do problema de completar, neste caso queremos candidatos à palavra digitada, logo palavras muito pequenas com 1 ou 2 letras podem ter muitos candidatos à serem testados, levando ao problema anterior novamente. Assim também iremos limitar S à um tamanho de 3 caracteres no mínimo antes de começar a testar possíveis candidatos para distância de edição.

# 3-Interface

No exemplo abaixo, o programa tem nome de `words_complete_correct`, ele deve ler os argumentos da linha de comando como segue:

```
% ./words_complete_correct
Usage: words_complete_correct <databse_file>
  onde <database_file> é a base de dados contendo os pesos e as palavras a serem consideradas
        -[i|s] -s representa a versão estática, enquanto -i representa a versão interativa do editor.
```

O `<database_file>` é um arquivo de texto que contém as entradas, cada uma contendo uma **sentença** e seu valor correspondente de **peso**. Três arquivos de dadatabase podem ser encontrados no diretório [data](./data). Veja que a base de palavras em português foi tirada do Corpus da lingua portuguesa que pode ser
baixado no [site](http://corpusbrasileiro.pucsp.br/cb/Downloads/wl_cb_full_1gram_sketchengine.txt.zip).

Depois de ler e processar a base de dados de entrada, o seu sistema deve perguntar ao usuário por um fragmento de palavra ou senteça (ou mesmo uma palavra/sentença inteira). Depois disso, o programa deve _encontrar e retornar todas as possiveis sentenças na base de dados que iniciam com o fragmento/palavra/sentença_ que foi fornecido, e que são candidatas do algorítmo de correção automática. O programa deve mostrar mostrando o resultado na ordem decrescente de peso, separando uma coluna para o autocomplete e outra para o autocorrect. No caso em que o termo não foi encontrado, o programa deve imprimir a mensagem _"no match found"_.

Após isso o programa deve perguntar novamente por um novo prefixo de palavra ou sentença até que o usuário envie EOF(<kbd>Ctrl</kbd> + <kbd>z</kbd>) para terminar.

# 4-Implementação e Modelagem

Fique à vontade para modelar o programa como você achar que deve. No entanto, faça ao menos 4 classes:

1. Uma classe deve ficar à cargo da Interface com o usuário, especialmente ler a entrada e escrever as possíveis saídas.
2. Uma classe deve ficar à cargo de processar e guardar as informações do banco de dados.
3. Uma classe de ficar à cargo de computar o conjunto do autocorrect.
4. Outra classe deve ficar à cargo de computar o conjunto do autocomplete.

## 4.1 Versão estática

A versão estática do programa funciona de forma similar ao que estamos acostumados com problemas de Entrada/Saída, no entanto Como, neste caso, estamos interessados também na eficiencia da solução, os passos recomendados para resolver o problema são:

1. Leia o arquivo da base de dados e ordene pela _string_ correspondente à sentença;
2. Leia a entrada do usuário. Caso o usuário entre EOF (`<Ctrl>+D`) finalize, caso contrário, vá para o passo seguinte;
3. Execute uma `busca binária` para encontrar criar um conjunto com todas as entradas da base que iniciam com o prefixo buscado, para tanto você pode usar os algoritmos da stl: [`lower_bound`](http://en.cppreference.com/w/cpp/algorithm/lower_bound) e [`upper_bound`](http://en.cppreference.com/w/cpp/algorithm/upper_bound);
    1. Ordene o conjunto criado pelo peso, criando uma __vizualização__ do conjunto, vamos chamar de Vcomp.
4. Execute uma busca linear para encontrar o conjunto de palavras com tamanho S
    1. Ordene o conjutno criado pelo peso
    2. Calule a distancia de edição das N primeiras palavras do conjunto, gerando um novo conjunto Vcorr. Ordene pelo peso e pela distancia de edição (quando menor mais relevante)
5. Exiba Vcomp e Vcorr na interface e volte para o passo 2.

Outro ponto à observar é o uso de referencias ao invés de cópias quando tratamos tipos não básicos. C++ é uma linguagem muito eficiente, mas que pode perder desempenho a medida que começamos a usar cópias ao invés de referencias, especialmente quando os dados processados são escalares (vetores, matrizes, etc). Neste trabalho, quando for processar objetos que são compostos por arrays, seja em parâmetros dos métodos/funções ou nos retornos destes, tente usar referencias ao invés de cópias, caso contrário o programa pode realmente ficar com um desempenho prejudicado.

## 4.1 Versão interativa (Extra)

A versão interativa é uma variação da versão estática onde o usuário não precisa digitar o texto e pressionar enter. Nessa versão as sugestões de autocomplete
são exibidas a medida que o usuário digita algum texto. Para fazer isso você precisará usar uma biblioteca externa chamada [ncurses](https://en.wikipedia.org/wiki/Ncurses), ou algo similar (não dá pra fazer "facilmente" com cin/getline).

A ncurses é uma biblioteca muito usada em muitas aplicações de terminal pois permite um bom nível de controle da posição do cursor e de outras utilidades da interface de terminal. Como parte deste trabalho segue um exemplo de uso da ncurses, para compilar e testar crie a pasta build e faça `cmake --build . --target words_complete_correct_extra` o nome do executável é `words_complete_correct_extra`. O código do exemplo está no [main_ncurses](./src/main_ncurses.cpp). Existem ainda bastante tutoriais online sobre o uso desta biblioteca, um muito bom é [este](https://terminalroot.com.br/ncurses/). Veja que a curses é uma biblioteca feita para ser usada com C, embora ela possa ser usada com C++, tente usar as construções de C apenas para se comunicar com a biblioteca enquanto usa C++ para todo resto (evite usar char* por exemplo, trocando por `std::string s + s.char_str()`).

A versão interativa requer que você tenha feito a versão estática, no entanto algumas modificações nos passos mostrados na versão estática podem fazer com que a versão interativa fique inusável, por exemplo, calcular a distancia de edição a cada letra digitada. Pense em alguma estratégia para mitigar os problemas de desempenho especialmente limitando a quantidade de palavras buscadas, usando melhor a memória (com cache por exemplo) ou melhorando os algoritmos (versões iterativas são mais rápidas do que versões recursivas, por exemplo).

# 5-Saída

Seguem algumas saídas, cada uma com base em uma base de dados diferente. O usuário entra com __"Sao"__.

```
>>> Digite uma palavra, ou parte dela e digite Enter, o pressione Ctrl + d pra terminar: Sao
>>> Matches são
Autocomplete                  | Autocorrect
sao paulo, brazil             | sao
sao pedro da aldeia, brazil   | soa
sao pedro, brazil             | sal
sao pedro da cova, brazil     | sai

```

Note que o programa não deve ser **case sensitive**. Ou seja, não deve fazer diferença se o usuário digita "Sao", "sao", "SAO",  ou qualquer variação de maiúscula ou minúscula. A entrada do usuário deve ser convertida para um case qualquer (todas maiúsculas ou todas minúsculas), para facilitar a operação de busca na base de dados.

# 6-Validação e testes

Neste trabalho o ônus de testar e mostrar as implementações das funcionalidades é totalmente seu! Invista em criar testes e em automatizar o processo de testes uma vez que você irá precisar demonstrar a implementação do caso de uso básico, casos de erro e as funcionalidades.

Tente variar a base de dados e testar especialmente os algoritmos envolvidos para mostrar que funcionam corretamente e que a saída desejada é a que está sendo
mostrada no caso de teste.


# Autorship

The description of this programming assignment was taken from [Computer Sciecne at Pricenton University](http://introcs.cs.princeton.edu/java/assignments/autocomplete.html).

**Adaptation: Selan R. Santos, [selan@dimap.ufrn.br](mailto:selan@dimap.ufrn.br)**

**Translation to PT-Br and addition of autocorrect and curses: Julio Melo, [julio.melo@imd.ufrn.br](mailto:julio.melo@imd.ufrn.br)**

&copy; DIMAp/UFRN 2021.
&copy; IMD/UFRN 2021.
