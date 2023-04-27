# Pilha

## 1. Em computação, qual é a definição de pilha? O que significa LIFO?

Em computação, uma pilha é uma estrutura de dados que segue o princípio **LIFO (Last In, First Out)**, o que significa que o último elemento adicionado à pilha é o primeiro a ser removido.

A pilha é uma estrutura de dados linear que consiste em uma lista de elementos, na qual a inserção (ou empilhamento) e a remoção (ou desempilhamento) dos elementos ocorrem apenas em uma extremidade da lista, **conhecida como topo da pilha**.

Quando um elemento é adicionado à pilha, ele é empurrado para o topo, e quando um elemento é removido, o elemento no topo da pilha é removido primeiro.

As pilhas são amplamente utilizadas em algoritmos de programação para armazenar informações temporárias, como variáveis locais, endereços de retorno e parâmetros de chamada de função. Também são usadas em sistemas operacionais para gerenciar a memória do computador.

## 2. Qual é a principal regra da pilha? Porque não devemos quebrá-la?

A principal regra da pilha é o princípio **LIFO (Last In, First Out)**, que determina que o último elemento adicionado à pilha deve ser o primeiro a ser removido. Essa regra é fundamental para garantir a **integridade** dos dados armazenados na pilha e a **correta execução de algoritmos** que utilizam essa estrutura de dados.

Ao quebrar a regra da pilha, ou seja, ao remover um elemento que não esteja no topo da pilha, ou inserir um elemento no meio da pilha, pode ocorrer uma **corrupção dos dados** armazenados na pilha, resultando em comportamentos inesperados do programa.

## 3. Com os seguintes símbolos: 5, 92, 18, 1, 38. Insira esses elementos na pilha, um por vez.  

|  Pilha  |  Pilha  |  Pilha  |  Pilha  |  Pilha  |
|---------|---------|---------|---------|---------|
|   Topo  |   Topo  |   Topo  |   Topo  |   Topo  |  
|     5   |    92   |    18   |     1   |    38   |
|  Fundo  |     5   |    92   |    18   |     1   |
|         |  Fundo  |     5   |    92   |    18   |
|         |         |  Fundo  |     5   |    92   |
|         |         |         |  Fundo  |     5   |
|         |         |         |         |  Fundo  |


## 4. Como faço para remover o elemento com o símbolo 18 da pilha, mantendo os demais na pilha, usando somente a estrutura pilha?

|  Pilha  |  Pilha  |  Pilha  |  Pilha  |  Pilha  |  Pilha  |
|---------|---------|---------|---------|---------|---------|
|   Topo  |   Topo  |   Topo  |   Topo  |   Topo  |   Topo  |
|    38   |     1   |    18   |    92   |     1   |    38   |
|     1   |    18   |    92   |     5   |    92   |     1   |
|    18   |    92   |     5   |  Fundo  |     5   |    92   |
|    92   |     5   |  Fundo  |         |  Fundo  |     5   |
|     5   |  Fundo  |         |         |         |  Fundo  |
|  Fundo  |         |         |         |         |         |

|  Pilha Auxiliar  |  Pilha Auxiliar  |  Pilha Auxiliar  |  Pilha Auxiliar  |  Pilha Auxiliar  |
|------------------|------------------|------------------|------------------|------------------|
|        Topo      |        Topo      |        Topo      |        Topo      |        Topo      |
|       Fundo      |        38        |         1        |         1        |       Fundo      |
|                  |       Fundo      |        38        |       Fundo      |                  |
|                  |                  |       Fundo      |                  |                  |

## 5. Qual é a utilidade da pilha? Cite exemplos.

A pilha é uma estrutura de dados importante em programação, que é utilizada para armazenar e gerenciar informações de forma organizada. Sua principal utilidade é permitir o acesso rápido e eficiente a dados que foram adicionados por último 

* Avaliação de expressões matemáticas
* Verificação de sintaxe em linguagens de programação
* Execução de operações em sistemas operacionais
* Navegação por históricos em navegadores web
* Gerenciamento de chamadas em sistemas de telefonia
* Criação e gerenciamento de menus em programas de computador
* Desfazer e refazer ações em editores de texto e programas de desenho gráfico
* Rastreamento de execução de programas (chamadas de função, registro de erros, etc.)

## 6. Quais os principais componentes da pilha? O que é o topo? Qual é a importância do topo da pilha?

Os principais componentes da pilha são:

* **Topo:** Elemento mais recente inserido na pilha. Todas as operações de inserção e remoção são feitas a partir do topo da pilha.
* **Base:** Elemento mais antigo inserido na pilha. Todas as operações de inserção e remoção são feitas a partir do topo da pilha, mas a base serve como um limite físico para a pilha.
* **Elementos:** São os objetos que são armazenados na pilha.

O topo é um componente fundamental da pilha, pois todas as operações de inserção e remoção de elementos são feitas a partir dele. É por isso que a pilha é uma estrutura de dados do tipo LIFO (Last In, First Out), o que significa que o último elemento inserido é o primeiro a ser removido. O topo permite que a pilha seja facilmente acessada e manipulada.

## 7. Quais as formas mais comuns de implementação de pilha? Mostre como as diferentes implementações se comportam.

Existem duas formas comuns de implementação de pilha: com **vetor** e com **lista encadeada**.

A implementação com vetor é mais simples e eficiente em termos de acesso aos elementos, uma vez que os elementos da pilha são armazenados em uma estrutura de vetor. Nessa implementação, **o topo da pilha é representado por um índice** que aponta para o **último elemento inserido**. Quando um elemento é inserido na pilha, ele é armazenado na posição apontada pelo topo e o valor do topo é incrementado. Quando um elemento é removido da pilha, o valor do topo é decrementado e o elemento é considerado removido.

Por outro lado, **a implementação com lista encadeada é mais flexível** e não requer que o tamanho da pilha seja definido previamente. **Nessa implementação, cada elemento da pilha é armazenado em um nó da lista encadeada** e **cada nó aponta para o nó que está abaixo dele na pilha**. O topo da pilha é representado pelo nó da lista encadeada que está no topo da pilha. Quando um elemento é inserido na pilha, um novo nó é criado e inserido no início da lista encadeada, tornando-se o novo topo da pilha. Quando um elemento é removido da pilha, o nó do topo da pilha é removido da lista encadeada e o nó que está abaixo dele se torna o novo topo da pilha.

A principal diferença entre as duas implementações é que a implementação com vetor requer um tamanho fixo para a pilha e pode ficar limitada pelo tamanho máximo do vetor, enquanto a implementação com **lista encadeada não tem essa limitação** e pode crescer dinamicamente. No entanto, a implementação com **vetor tem uma melhor eficiência de acesso aos elementos**, uma vez que o acesso aos elementos é feito **diretamente pela posição no vetor**, enquanto a implementação com lista encadeada **requer percorrer os nós da lista para acessar os elementos**.

## 8. Em C++, considerando a implementação por encadeamento de nós, o que é necessário fazer na função de criar pilha?

* Criar um ponteiro do tipo No e atribuir o valor NULL a ele. Esse ponteiro servirá como o topo da pilha.
* Alocar memória para o nó utilizando o operador new. É necessário verificar se a alocação de memória foi bem sucedida, e caso contrário, retornar um erro.
* Atribuir os valores iniciais para o nó criado, como o valor do elemento e o ponteiro para o próximo nó.
* Atualizar o valor do ponteiro do topo da pilha para apontar para o nó criado.
* Retornar o ponteiro do topo da pilha.

## 9. Em C++, considerando a implementação por encadeamento de nós, o que é necessário fazer na função de inserir na pilha?

* Criar um novo nó com o valor do elemento a ser inserido e o ponteiro para o próximo nó igual a null.
* Verificar se a pilha está vazia, ou seja, se o ponteiro para o topo da pilha é igual a null.
* Se a pilha estiver vazia, o ponteiro para o topo da pilha deve apontar para o novo nó criado.
* Caso contrário, o ponteiro para o próximo nó do novo nó deve apontar para o nó que atualmente está no topo da pilha e o ponteiro para o topo da pilha deve ser atualizado para apontar para o novo nó criado.

## 10. Em C++, considerando a implementação por encadeamento de nós, o que é necessário fazer na função de remover da pilha?

* Verificar se a pilha está vazia, ou seja, se o ponteiro para o topo é nulo.
* Se a pilha não estiver vazia, criar um ponteiro temporário para o nó do topo.
* Atribuir o ponteiro do topo para o próximo nó da pilha.
* Deletar o nó temporário criado no passo 2.
* Retornar o valor do elemento removido.

## 11. Além das três funções básicas, quais outras funções que a pilha pode ter? Quais são as características das funções para justificar a necessidade de implementá-las?

**Função para verificar se a pilha está vazia:** Essa função retorna um valor booleano indicando se a pilha está vazia ou não. É uma função útil para evitar erros ao tentar remover um elemento de uma pilha vazia.

**Função para verificar se a pilha está cheia:** Em algumas implementações de pilha, é possível definir um tamanho máximo para a pilha. Essa função retorna um valor booleano indicando se a pilha está cheia ou não. É uma função útil para evitar erros ao tentar inserir um elemento em uma pilha cheia.

**Função para esvaziar a pilha:** Essa função remove todos os elementos da pilha, deixando-a vazia. É uma função útil em situações em que é necessário reutilizar a pilha ou quando é necessário liberar a memória alocada para os elementos da pilha.

**Função para copiar uma pilha:** Essa função cria uma cópia de uma pilha existente. É uma função útil quando é necessário trabalhar com duas pilhas diferentes que possuem os mesmos elementos.

**Função para inverter a pilha:** Essa função inverte a ordem dos elementos da pilha. É uma função útil em situações em que é necessário processar os elementos da pilha na ordem inversa.

**Função para encontrar um elemento na pilha:** Essa função recebe como parâmetro um elemento a ser procurado na pilha e retorna a posição em que ele se encontra ou um valor indicando que o elemento não está na pilha. É uma função útil em situações em que é necessário verificar se um elemento está presente na pilha e em qual posição ele se encontra.

## 12. Quais as vantagens e desvantagens da implementação de pilha por arranjos? 

Vantagens:

* Fácil de implementar;
* Acesso direto aos elementos da pilha, o que permite acesso rápido ao topo da pilha;
* Uso eficiente de memória, pois não há necessidade de alocar espaço adicional para ponteiros de ligação entre os elementos da pilha;
* Adequado para situações em que o tamanho da pilha é fixo e conhecido antecipadamente.

Desvantagens:

* Tamanho fixo, ou seja, uma vez definido o tamanho do array, não é possível alterá-lo dinamicamente durante a execução do programa;
* O tamanho do array pode ser desperdiçado, caso o número de elementos da pilha seja menor do que o tamanho do array;
* Operações de inserção e remoção podem ser ineficientes quando o tamanho da pilha é grande, pois a realocação de elementos do array pode ser necessária, a fim de manter os elementos consecutivos e a pilha organizada;
* Quando a pilha está cheia, novos elementos não podem ser adicionados, mesmo que haja espaço suficiente em memória, o que pode levar a problemas de uso de memória.