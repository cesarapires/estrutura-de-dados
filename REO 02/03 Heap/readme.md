# Heap e torneios

## 1. O que é uma estrutura Heap? Qual é a sua utilização? Como ela é usualmente implementada?

Heap é uma estrutura de dados em árvore que mantém o maior (ou menor) elemento na raiz da árvore. **É comumente usado em algoritmos de ordenação, como o heapsort**, e é implementado **como um vetor em que os pais são sempre maiores ou menores do que seus filhos, dependendo do tipo de heap**. A inserção e remoção de elementos são feitas de forma a manter a propriedade do heap. É uma estrutura útil em diversas aplicações, **como seleção dos maiores/menores elementos e algoritmos de grafos**.

## 2. O que é um grafo? Qual é a sua relação com a Heap? Quais os principais conceitos de grafos que precisamos saber?
Um grafo é uma **estrutura composta por um conjunto de vértices e um conjunto de arestas que ligam os vértices**. A Heap pode ser utilizada em algoritmos de grafos para **selecionar o próximo vértice a ser visitado**. Os principais conceitos de grafos são **vértices**, **arestas**, **grau**, **caminho**, **ciclo**, **grafo direcionado**, **grafo não-direcionado **e **peso**.

## 3. O que é uma árvore? O que é uma raiz de uma árvore? Quais os principais conceitos de grafos que precisamos saber?
Uma árvore é uma estrutura hierárquica de dados que **consiste em nós conectados por arestas direcionadas sem ciclos**. **A raiz é o nó principal sem pai**, e cada **nó pode ter zero ou mais nós filhos**. Os principais conceitos são **nós**, **arestas**, **raiz**, **filhos**, **pais**, **folhas**, **altura**, **profundidade** e **subárvore**.

## 4. Quais são os dois tipos de Heaps? Quais são as características que os diferenciam?
Existem dois tipos de Heap: **Heap Max** e **Heap Min**. 
A Heap Max tem como característica o fato de que o **nó raiz tem o maior valor de todos** os nós da Heap e a operação de **remoção remove o maior elemento**. Já a Heap Min tem como característica o fato de que o **nó raiz tem o menor valor de todos** os nós da Heap e a operação de **remoção remove o menor elemento**. As Heaps são utilizadas para manter dados em uma estrutura de árvore binária completa e otimizar a busca pelo maior ou menor valor.

## 5. Porque as características intrínseca das estruturas Heaps fazem com que essas estruturas sejam implementadas em arranjos?
As Heaps são implementadas em arranjos porque a estrutura de árvore binária completa **pode ser facilmente representada em um arranjo**. Isso ocorre porque cada nó tem no **máximo dois filhos** e a **árvore é completa**, o que significa que **todos os níveis da árvore são preenchidos, exceto talvez o último**, que é preenchido da esquerda para a direita. Além disso, as operações de **inserção e remoção em uma Heap envolvem apenas a troca de elementos adjacentes no arranjo**, o que torna a implementação bastante eficiente. O uso de arranjos também simplifica o processo de manipulação de memória em comparação com outras estruturas de dados encadeadas, por exemplo.

## 6. Como a estrutura Heap se mantém organizada? Como esses métodos funcionam?
A estrutura Heap se mantém organizada por meio dos métodos heapify, **corrigirSubindo** e **corrigirDescendo**. O heapify transforma uma árvore em uma Heap válida verificando se cada nó tem o valor correto em relação aos seus filhos. O método **corrigirSubindo é usado após a inserção de um elemento e consiste em subir o novo elemento na árvore, verificando se ele é maior (ou menor) que o seu pai.** **O método corrigirDescendo é usado após a remoção do elemento raiz e "desce" o novo elemento na árvore, verificando se ele é menor (ou maior) que os seus filhos.**

## 7. Construa uma minheap com os elementos 108, 26,84,33, 54, 16, 9, 41, 23, 8, 11, 1
### Passo 1: Construir uma árvore binária com os elementos


          108
       /      \
      26       84
     /  \     /  \
   33   54  16   9
  /  \  /
41  23 8

### Passo 2: Transformar a árvore em uma minheap usando o método heapify


           8
       /        \
      11         9
     /   \      /  \
   23   54   16  41
  /  \   /
108 33  84

## 8. Retire três elementos da minheap construída anteriormente
### Passo 1: Retirar o primeiro elemento, que é o menor

           9
       /        \
     11         41
    /   \      /  \
  23   54   16  108
 /  \
33  84

### Passo 2: Retirar o segundo menor elemento

          11
       /        \
     23         41
    /   \      /  \
  84   54   16  108
 /
33

### Passo 3: Retirar o terceiro menor elemento

         16
       /        \
     23         41
    /   \      /  \
  84   54  108
 /
33

## 9. Insira os elementos 3 e 20 na minheap.
### Passo 1: Adicionar o novo elemento na última posição da minheap

         16
       /        \
     23         41
    /   \      /  \
  84   54  108   33
 /
3

### Passo 2: Fazer a correção da minheap usando o método heapify

         3
       /        \
     16         41
    /   \      /  \
  23   54   108   33
 /
84

### Passo 3: Adicionar o segundo novo elemento na última posição da minheap

         3
       /        \
     16         41
    /   \      /  \
  23   54   108   33
 /  \
84  20

### Passo 4: Fazer a correção da minheap usando o método heapify

         3
       /        \
     16         20
    /   \      /  \
  23   54   108   33
 /
84

## 10. Como fazemos para encontrar o nó pai, filho à esquerda ou direita? Considere o arranjo iniciando da posição 0 e 1.
Na implementação de uma Heap em arranjos, é possível calcular a posição do pai de um nó, dado sua posição no arranjo, utilizando a fórmula (**posição - 1) / 2**. Para calcular a posição do filho à esquerda de um nó, podemos utilizar a fórmula **2 * posição + 1**, e para o filho à direita, a **fórmula 2 * posição + 2**. É importante ressaltar que as operações de inserção e remoção na Heap utilizam esses cálculos para manter a propriedade da Heap e garantir que a estrutura continue organizada corretamente.

## 11. Quais são os procedimentos necessários no construtor e destrutor da Heap? Qual é o ponto que precisamos ter atenção nestes procedimentos?
No construtor da Heap, é necessário alocar espaço na memória para o arranjo que irá representar a estrutura, além de inicializar o tamanho da Heap como 0. Já no destrutor, é importante liberar o espaço de memória alocado para o arranjo.

Um ponto importante a se atentar é para a correta alocação e liberação de memória, evitando vazamentos ou corrupção de dados na memória, o que pode levar a falhas no programa. Também é importante garantir que o tamanho da Heap seja atualizado corretamente após cada operação de inserção ou remoção.

## 12. Como é implementado o corrigeDescendo?
O método corrigeDescendo é utilizado na estrutura Heap para manter a propriedade da Heap após a remoção de um elemento. Ele compara o valor do nó removido com o valor dos seus filhos e troca o valor do nó com o menor valor dos filhos, até que o valor removido esteja em uma posição adequada na Heap. O método é implementado recursivamente ou de forma iterativa e é importante para manter a ordem e propriedades da Heap.

## 13. Como é implementado a constroiHeap (Heapify## )?.Qual a importância e finalidade deste método? 
O método constroiHeap (Heapify) é responsável por transformar um arranjo desordenado em uma Heap válida. Ele faz isso percorrendo o arranjo da posição n/2 até a posição 0, aplicando o método corrigeDescendo em cada posição, de forma a garantir que a propriedade da Heap seja satisfeita. A importância deste método é garantir que a Heap seja construída de forma eficiente e válida, permitindo que as outras operações sejam executadas corretamente.

## 14.  Como é implementada a remoção em heap? O que deve ser feito após a remoção de um elemento da estrutura?
A remoção em Heap é realizada sempre a partir da raiz, que é o elemento de menor valor em uma Min Heap ou o elemento de maior valor em uma Max Heap. Para remover o elemento da raiz, ele é substituído pelo último elemento da Heap e em seguida, o método corrigeDescendo é aplicado à raiz, para garantir que a propriedade da Heap seja mantida.

Após a remoção de um elemento da Heap, é necessário garantir que a estrutura ainda seja válida, aplicando o método corrigeDescendo na raiz. Além disso, é preciso ajustar a posição do último elemento, de forma a mantê-lo no final do arranjo, para que ele possa ser utilizado em outras operações.

## 15. Como é implementado o corrigeSubindo? Como é implementada a inserção em um heap?
O método corrigeSubindo é responsável por verificar se um nó inserido na Heap viola a propriedade de ordem e, se necessário, corrigir sua posição subindo na árvore.

A inserção em um Heap começa adicionando o novo elemento ao final da estrutura. Em seguida, o método corrigeSubindo é chamado para posicionar o novo nó na posição correta na Heap, subindo na árvore se necessário.

## 16. O que é um torneio? Qual é a diferença em relação ao Heap?
Torneio é uma estrutura de dados que também é usada para implementar uma fila de prioridade. Ao contrário da Heap, o torneio é uma árvore binária completa que contém todos os elementos da fila de prioridade em seus nós folha. A raiz da árvore contém o menor elemento e cada nó pai contém o menor elemento de seus dois filhos. A principal diferença em relação ao Heap é que o torneio é uma árvore binária completa e, portanto, não precisa de uma matriz para armazenar seus elementos. Além disso, o processo de inserção e remoção de elementos em um torneio é mais complexo e requer a reorganização da árvore para manter sua propriedade de menor elemento na raiz.

## 17. O que é um torneio incompleto? Como resolver esse problema?
Um torneio incompleto é aquele em que o número de elementos na árvore não é uma potência de 2. Para resolver esse problema, podemos adicionar elementos "fantasmas" à árvore para que ela se torne completa, ou seja, ter potência de 2 elementos. Esses elementos fantasmas podem ter valores arbitrários, como um valor infinito ou zero, dependendo da aplicação. Isso permite que a árvore seja manipulada como uma estrutura de árvore completa e mantenha as propriedades de um torneio.