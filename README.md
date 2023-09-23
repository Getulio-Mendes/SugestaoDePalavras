O objetivo do projeto é criar um sistema de previsões de palavras aos usuários, ou seja, estabelecer uma relação entre as palavras encontradas nos textos e as palavras que os usuário esta buscando, utilizando a frequência de ocorrência das palavras nos textos. 

Para isso, usaremos a estrutura de dados "árvore binária" como base central do método. Isso permitirá aprimorar a capacidade de oferecer recomendações e sugestões relevantes, melhorando assim a experiência de pesquisa e autocompletar para os usuários.

Os tipos de árvore binária utilizados foram a BST (Binary Search Tree) clássica, a AVL e a códificação Huffman, o resultado obtido em cada estrutura é expresso separadamente, permitindo a comparassão da qualidade do algoritmo quando este usa diferentes estruturas. Além disso, para cada árvore usada o resultado obtido pelas diversas formas de caminhamento diferente também foram expostas, realçando o ponto acima e o propósito didático deste trabalho.

## Entrada

A entrada é composta por o arquivo "input.txt" onde serão colocadas as palavras a que se espera que o programa complete, os textos que servem de referência à procura, nomeados "inputN.data", sendo N o número do arquivo em relação aos outros textos a partir de 1 que são colocados na pasta "docs" dentro da pasta "dataset".

### Formatação da entrada

- O programa recebe um arquivo com conteudo de texto onde cada sentença deve terminar com sinal de pontuação ex: ```. ```, ```? ```, ```! ```;
- Cada parágrafo é separado por uma linha em branco;
- Uma palavra é definida como uma sequência de letras delimitadas (pela frente e trás) por espaço ou sinal de pontuação ou marca de terminação;
- Os arquivos de input são nomeados na forma "input{n}.data", onde n é seu número a partir de 1;
- A análise a ser feita no texto desconsidera as "stop words", palavras como "a","e","mas", etc. A lista de "stop words" deve ser fornecida através de um arquivo "stopwords.txt" na pasta dataset;

Aas marcas de terminação usadas são: 
- espaço; nova linha; ```!```; ```?```; ```.```;
- ```,```; ```(```; ```)```; ```;```; ```/```; 
- ```:```; ```—```; ```"```; ```\```;
  
## Processamento

Em cada texto, é criado uma hash contento todas as palavras do texto, cada vez que uma palavra é encontrada, ela tem sua frenquência na hash aumentada. A contagem dos elementos é feita em O(n), onde n representa o número de palavras. É importante notar que todas as palavras contidas no arquivo "stopwords.txt" serão disconsideradas pelo programa e não serão adicionadas à hash.

Foi-se utilizado também a condificação UTF-8 fornecida pelas bibliotecas do C++. Além disso, o programa não diferencia entre palavras com letras minúsculas e maiúsculas, assim, "CÓDIGO" e "código" são consideradas palavras iguais. O programa considera acento nas palavras, sendo assim, "código" e "codigo" são consideradas diferentes.

Textos que não possuem nenhuma das palavras contidas no "input.txt" são desconsiderados pelo programa, se caso a palavra não esteja em um texto em específico, isso será informado na saída.

Depois se cria um heap de tamanho k (usando o padrão de 20) para cada texto, o heap é inicializado com os primeiros valores da hash e após isso ele será atualizado conforme for pertinente. Mais detalhes sobre o processo podem ser vistos no projeto [Top K elementos](https://github.com/Getulio-Mendes/Top-K-elementos), no qual este projeto se baseia.

A atualização do heap é feita compararando cada palavra restante da hash com o menor valor do heap, isto é, a palavra com menor frequência. Se a contagem for maior do que o menor valor da heap, o elemento do heap é removido, e o novo elemento é inserido no heap. A cada elemento inserido o ```heapify``` é utilizado, mantendo a estrutura heap correta. Um detalhe importante é que as palavras a serem completadas não podem ser colocadas no heap.

Uma vez que o heap de cada texto é concluído, forma-se os três tipos de árvore escolhidos, binária, AVL e Huffman utilizando as palavras mais frequêntes do texto, agora armazenadas no heap. Após isso o resultado final é impresso no arquivo "output.txt" na pasta "dataset" contendo os três caminhamentos nas três árvores de cada texto para cada palavra. Os caminhamentos escolhidos foram Pós-Ordem, Pré-Ordem e In-Ordem.

## Decisões de implementação 

Optou-se por carregar todo os textos para a memória antes de fazer seu processamento ao invés de ler do disco de pouco a pouco devido para otimizar processamento com mais prioridade do que otimizar memória. Mais detalhes sobre isso no trabalho já citado [Top K elementos](https://github.com/Getulio-Mendes/Top-K-elementos).

Não foi considerado o processamento de textos que não contem nehuma palavra do "input.txt", gerando uma otimização considerável em casos onde o input é apenas de poucas palavras específicas.

Ademais, foi-se utilizado o paradigma orientado á objetos deviado a sua maior intuitividade e facilidade de manejo de memória na maior parte do código, porém nas implementação das ávores, com exeção da Àrvore Binária Padrão, um paradigma estruturado mais parecido à C devido à dificuldade de se pensar numa lógica orientado à objetos para esse tipode programa.

## Conclusão

Foi possível examinar a construção de três tipos de árvores abordadas na diciplina de modo prático, deixando claro que cada uma delas oferecendo vantagens e desvantagens específicas, que se alinham com diferentes objetivos. A Árvore Binária de Busca, tem como sua principal vantagem sua facilidade de compreensão e implementação, tornando-a uma excelente opção onde a complexidade é baixa. Entretanto, mostra-se não tão eficiente em termos de eficiência quando confrontada com volumes significativos de dados, já que sua ausência de mecanismos de balanceamento tende a deixar o acesso e inserção mais lento, podendo até mesmo ser O(n).

O balanceamento feito pela Árvore AVL confere uma grande vantagem em casos onde a eficiência de pesquisa é essencial, principalmente quando se trabalho com grandes quantidades de dados. Seu balanceamento durante as operações de inserção e exclusão garante tempos de pesquisa consistentemente rápidos. No entanto, sua complexidade de implementação e podem torná-la menos atraente em situações de baixa complexidade.

Já Árvore de Huffman oferece uma abordagem diferente e interessante, porém seu ponto forte de compactação não foi usado neste trabalho uma vez que isso não involve o objetivo do trabalho. 

Considerando-se que estamos construindo árvores a partir de um heap do tipo min-heap, a Árvore Binária Padrão revela-se menos favorável na situação. Já que pelos elementos estarem levemente ordenados, acabamos por cair muitas vezes no pior caso de inserção da Árvore Binária, isto é, quando os dados estão completamente ou quse ordenados. Nessa situação a Árvore Binária Padrão tende a se desbalancear pra direita e pela falta de mecanismos de balanceamento na estrutura  apresenta uma performance menor que as outras.

## Compilação e Execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução.
O arquivo Makefile supporta as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
