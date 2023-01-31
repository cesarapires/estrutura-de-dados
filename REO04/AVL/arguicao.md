# AVL

## 1. Quando uma ABB se torna ineficiente? Como isso pode ocorrer? Como resolver?
Uma ABB (Árvore Binária de Busca) pode se tornar ineficiente quando se torna muito **desequilibrada**, tornando as operações de busca, inserção e exclusão muito lentas. 

Isso pode ocorrer por diversas razões, **incluindo inserções desordenadas de dados**, **remoções frequentes de nós** e poucas rotações. 

Para resolver isso, existem diversas técnicas de balanceamento de árvores, como a **AVL**, a **Árvore Rubro-Negra** e a **Árvore Vermelho-Preto**, que mantêm a árvore equilibrada, garantindo tempos de execução rápidos.


## 2. O que é balanceamento de uma árvore? Qual é a importância da altura de um nó para o balanceamento? Qual é a forma mais simples de calcular a altura de um nó?
O balanceamento de uma árvore é uma técnica que mantém a distribuição de nós em uma estrutura de árvore o **mais equilibrada possível**, de forma que as operações de busca, inserção e exclusão sejam realizadas rapidamente. 

**A altura de um nó é importante para o balanceamento da árvore**, pois uma **árvore mais alta** tende a ser **menos eficiente** do que uma árvore menor. Uma **árvore muito desequilibrada** pode se tornar semelhante a uma **lista ligada**, o que resulta em tempo de execução lento para as operações. 

A forma mais simples de calcular a altura de um nó é **percorrer a árvore a partir desse nó** e contar o número de níveis até chegar a um nó folha. A altura do nó seria o número de níveis encontrados.

## 3. O que é uma árvore AVL? Qual é o seu princípio?
A Árvore AVL (Árvore de Balanceamento de Altura) é uma estrutura de dados de árvore binária de busca balanceada, onde a diferença de altura entre as sub-árvores de qualquer nó não excede 1. 

O princípio da AVL é manter a árvore equilibrada a cada inserção ou remoção, fazendo rotações na árvore para manter a diferença de altura entre as sub-árvores de cada nó dentro de um limite. 

Isso garante que as operações de busca, inserção e exclusão sejam realizadas rapidamente, mesmo quando a árvore tem muitos nós.

## 4. O que é feito na AVL para garantir o balanceamento?
Na Árvore AVL, rotações são realizadas para garantir o balanceamento da árvore. Essas rotações são feitas em cima dos nós que ficam desequilibrados após uma inserção ou remoção. 

Existem duas rotações possíveis na AVL: rotação simples à direita (right rotation) e rotação simples à esquerda (left rotation). Elas são usadas para ajustar a estrutura da árvore de forma a manter a diferença de altura entre as sub-árvores de cada nó dentro do limite estabelecido (no máximo 1). 

Além das rotações simples, também existem duas rotações duplas: rotação dupla à direita (right-left rotation) e rotação dupla à esquerda (left-right rotation). Essas rotações são realizadas quando uma rotação simples não é suficiente para corrigir o desequilíbrio da árvore.

## 5. De uma visão geral da implementação de AVL, comparando com a implementação de uma ABB. 
A implementação de uma Árvore AVL é semelhante à implementação de uma Árvore Binária de Busca (ABB), mas com a adição de alguns passos adicionais para garantir o equilíbrio da árvore.

Na implementação da AVL, ao inserir ou remover um nó, é preciso verificar a altura das sub-árvores de todos os nós ao longo do caminho da raiz até o nó que foi inserido ou removido. Se a diferença de altura entre as sub-árvores de um nó exceder o limite estabelecido (1), é necessário realizar rotações para corrigir o desequilíbrio da árvore.

Na implementação de uma ABB, não há verificações adicionais sobre a altura das sub-árvores ou rotações para manter o equilíbrio da árvore. Isso significa que, em uma ABB, a altura da árvore pode aumentar rapidamente, resultando em operações de busca, inserção e exclusão mais lentas. 

Em resumo, a implementação de uma AVL é mais complexa do que a implementação de uma ABB, pois requer a realização de verificações adicionais sobre a altura da árvore e rotações para mantê-la equilibrada. No entanto, essas verificações adicionais garantem que a AVL tenha melhor desempenho em termos de tempo de execução das operações de busca, inserção e exclusão.


## 6. Como resolvemos o problema do desbalanceamento de uma árvore? Quando devo realizar o balanceamento? 
O problema de desbalanceamento em uma árvore pode ser resolvido através de técnicas de balanceamento de árvore. Essas técnicas buscam manter a altura da árvore o mais equilibrada possível, garantindo que as operações de busca, inserção e exclusão sejam executadas de forma eficiente.

A realização do balanceamento depende da estratégia escolhida para garantir o equilíbrio da árvore. Por exemplo, na Árvore AVL, o balanceamento é realizado imediatamente após a inserção ou remoção de um nó, verificando-se a altura das sub-árvores de todos os nós ao longo do caminho da raiz até o nó inserido ou removido. Se a diferença de altura entre as sub-árvores de um nó exceder o limite estabelecido (1), é necessário realizar rotações para corrigir o desequilíbrio da árvore.

Já em outras estratégias de balanceamento de árvore, como a Árvore Rubro-Negra, o balanceamento é realizado de forma incremental, a cada inserção ou remoção de um nó, sem necessidade de verificar a altura de todos os nós.

Em resumo, o momento para realizar o balanceamento depende da estratégia escolhida para garantir o equilíbrio da árvore. No entanto, independentemente da estratégia escolhida, o balanceamento é realizado sempre que uma inserção ou remoção de um nó ameace o equilíbrio da árvore.


## 7. Como saber qual rotação de balanceamento deve ser feita?
A rotação de balanceamento a ser realizada depende da estratégia escolhida para garantir o equilíbrio da árvore. Na Árvore AVL, por exemplo, a escolha da rotação a ser realizada depende da diferença de altura entre as sub-árvores de um nó que ameaça o equilíbrio da árvore.

Existem quatro tipos de rotações que podem ser realizadas em uma Árvore AVL: Rotação Esquerda, Rotação Direita, Rotação Dupla Esquerda-Direita e Rotação Dupla Direita-Esquerda. A escolha da rotação a ser realizada depende da relação de altura entre as sub-árvores esquerda e direita do nó que ameaça o equilíbrio da árvore.

Em resumo, para saber qual rotação de balanceamento deve ser feita, é necessário avaliar a relação de altura entre as sub-árvores de um nó que ameaça o equilíbrio da árvore, seguindo as regras da estratégia escolhida para garantir o equilíbrio da árvore.


## 8. Insira os seguintes elementos em uma AVL: 81, 40, 22, 38, 29, 106, 95, 6.

## 9. Remova os valores dos seguintes elementos da AVL da questão anterior: 40, 95.

## 10. Quais são os procedimentos essenciais para inserção em uma AVL?
A inserção em uma árvore AVL segue os seguintes passos:

1. Adicionar o novo nó na posição adequada na árvore, como em uma árvore binária de pesquisa.
2. Verificar a balanceamento da sub-árvore a partir desse nó recém-inserido
3. Se necessário, realizar rotações simples ou duplas para equilibrar a sub-árvore.
4. Atualizar as informações de balanceamento na sub-árvore e subir na árvore até a raiz, verificando e corrigindo o balanceamento ao longo do caminho.
5. Repeat os passos 3 e 4 até chegar na raiz da árvore.

## 11. Quais são os procedimentos essenciais para remoção em uma AVL?
Encontrar o nó a ser removido na árvore, como em uma árvore binária de pesquisa.
	
1. Encontrar o nó a ser removido na árvore, como em uma árvore binária de pesquisa.
2. Verificar se o nó tem um ou dois filhos. Se tiver dois filhos, encontrar o sucessor inorder para substituí-lo.
3. Remover o nó da árvore.
4. Verificar o balanceamento da sub-árvore a partir do pai do nó removido.
5. Se necessário, realizar rotações simples ou duplas para equilibrar a sub-árvore.
6. Atualizar as informações de balanceamento na sub-árvore e subir na árvore até a raiz, verificando e corrigindo o balanceamento ao longo do caminho.
7. Repeat os passos 5 e 6 até chegar na raiz da árvore.

## 12. Quais são os procedimentos essenciais para informar/atualizar altura em uma AVL?
procedimentos essenciais para informar/atualizar a altura em uma AVL (Árvore de Busca Binária Auto-equilibrada) incluem:

1. Atualizar a altura do nó atual com base nas alturas dos seus filhos.
2. Verificar se o nó está desequilibrado.
3. Se o nó estiver desequilibrado, aplicar rotações para equilibrá-lo.
4. Atualizar a altura dos nós afetados pelas rotações.
5. Repetir o processo para os nós pai até chegar na raiz da árvore.

## 13. Quais são os procedimentos essenciais para calcular o fator de balanceamento em uma AVL?
Os procedimentos essenciais para calcular o fator de balanceamento em uma AVL (Árvore de Busca Binária Auto-equilibrada) incluem:

1. Calcular a altura dos filhos do nó atual.
2. Calcular o fator de balanceamento do nó atual como a diferença entre a altura de seu filho esquerdo e direito.
3. Verificar se o fator de balanceamento é menor ou igual a.1 ou maior ou igual a 1, o que indica que o nó está desequilibrado.
4. Se o nó estiver desequilibrado, aplicar rotações para equilibrá-lo.
5. Repetir o processo para os nós filho até chegar nas folhas da árvore.

## 14. Quais são os procedimentos essenciais para a rotação simples à esquerda?
Os procedimentos essenciais para a rotação simples à esquerda em uma AVL (Árvore de Busca Binária Auto-equilibrada) incluem:

1. Identificar o nó desequilibrado, que será o nó pivô.
2. Identificar o filho direito do nó pivô, que será o novo raiz da subárvore.
3. Atualizar os ponteiros de filhos para conectar a subárvore esquerda do nó pivô como filho esquerdo do novo raiz.
4. Atualizar os ponteiros do pai do nó pivô e do novo raiz.
5. Atualizar a altura dos nós afetados pela rotação.

## 15. Quais são os procedimentos essenciais para a rotação simples à direita?
Os procedimentos essenciais para a rotação simples à direita em uma AVL (Árvore de Busca Binária Auto-equilibrada) incluem:

1. Identificar o nó desequilibrado, que será o nó pivô.
2. Identificar o filho esquerdo do nó pivô, que será o novo raiz da subárvore.
3. Atualizar os ponteiros de filhos para conectar a subárvore direita do nó pivô como 4. filho direito do novo raiz.
5. Atualizar os ponteiros do pai do nó pivô e do novo raiz.
6. Atualizar a altura dos nós afetados pela rotação.


