# Fila

## 1. Em computação, qual é a definição de fila? O que significa FIFO?

Uma fila em computação é uma estrutura de dados que segue o princípio **FIFO**, onde o **primeiro elemento a entrar é o primeiro a sair**. É uma coleção ordenada de elementos em que as operações de **inserção ocorrem no final da fila** e as operações de **remoção ocorrem no início da fila**. A fila é comumente usada em programação em algoritmos como busca em largura em grafos, escalonamento de processos e gerenciamento de tarefas.

## 2. Qual é a principal regra da fila? Porque não devemos quebrá-la?
A principal regra da fila é o **princípio FIFO (First In First Out)**, onde o primeiro elemento a entrar na fila é o primeiro a sair. **É importante seguir essa regra para garantir a ordem de processamento e evitar problemas na prestação de serviços ou no processamento de dados.** Quebrar a regra da fila pode afetar a eficiência e a qualidade do trabalho.

## 3. Com os seguintes símbolos: 5, 92, 18, 1, 38. Insira esses elementos na fila, um por vez.  

|    Fila   |    Fila   |    Fila   |    Fila   |    Fila   |
|-----------|-----------|-----------|-----------|-----------|
|   Inicio  |   Inicio  |   Inicio  |   Inicio  |   Inicio  |  
|     5     |     5     |     5     |     5     |     5     |
|    Fim    |    92     |    92     |    92     |    92     |
|           |    Fim    |    18     |    18     |    18     |
|           |           |    Fim    |     1     |     1     |
|           |           |           |    Fim    |    38     |
|           |           |           |           |    Fim    |

## 4. Como faço para remover o elemento com o símbolo 18 da fila, mantendo os demais na fila, usando somente a estrutura fila?

|    Fila   |    Fila   |    Fila   |    Fila   |    Fila   |    Fila   |
|-----------|-----------|-----------|-----------|-----------|-----------|
|   Inicio  |   Inicio  |   Inicio  |   Inicio  |   Inicio  |   Inicio  |  
|     5     |    92     |    18     |     1     |    38     |     5     |
|    92     |    18     |     1     |    38     |     5     |    92     |
|    18     |     1     |    38     |     5     |    92     |     1     |
|     1     |    38     |     5     |    92     |     1     |    38     |
|    38     |     5     |    92     |    Fim    |    Fim    |    Fim    |
|    Fim    |    Fim    |    Fim    |           |           |           |

## 5. Qual é a utilidade da fila? Cite exemplos.

* Sistemas de impressão
* Processamento de mensagens
* Gerenciamento de recursos compartilhados
* Navegação na web
* Sistemas operacionais
* Simulação de eventos discretos
* Processamento de imagens
* Processamento de dados em tempo real

## 6. Quais os principais componentes da fila? O que é o início e o fim? Qual é a sua importância na pilha?

Os principais componentes de uma fila são:

Início (também chamado de "frente" ou "head"): o ponto de entrada da fila, onde os novos elementos são adicionados.
Fim (também chamado de "trás" ou "tail"): o ponto de saída da fila, onde os elementos são removidos.

A importância do início e do fim na fila é garantir que os elementos sejam processados na ordem correta, seguindo o princípio FIFO (First-In, First-Out). O início da fila é sempre o primeiro elemento a ser removido, enquanto o fim da fila é sempre o último elemento adicionado.

## 7. Quais as formas mais comuns de implementação de fila? Mostre como as diferentes implementações se comportam.

As formas mais comuns de implementação de filas são usando um **array** (fila estática), uma **lista encadeada** (fila dinâmica) e duas pilhas. Cada uma dessas implementações possui vantagens e desvantagens específicas em relação à eficiência em espaço e tempo, capacidade e outras considerações.

## 8. Em C++, considerando a implementação por encadeamento de nós, o que é necessário fazer na função de criar fila?
1. Inicializar o ponteiro inicio com nulo.
2. Inicializar o ponteiro fim com nulo.
3. Inicializar tamanho com zero.

## 9.Em C++, considerando a implementação por encadeamento de nós, o que é necessário fazer na função de inserir na fila?
1. Criar um novo nó com o dado a ser enserido
2. Se a fila estiver vazia apontar o inicio e o fim para o novo nó
3. Se não apontar o ponteiro próximo do último elemento inserido para o novo nó
4. Apontar o fim para o novo nó inserido
5. tamanho recebe mais um

## 10. Em C++, considerando a implementação por encadeamento de nós, o que é necessário fazer na função de remover da fila?

1. Criar um ponteiro auxilar que aponte para o inicio da fila
2. Inicio aponta para o nó posterior ao nó que está sendo removido
3. tamanho reebe menos um

## 11. Além das três funções básicas, quais outras funções que a fila pode ter? Quais são as características das funções para justificar a necessidade de implementá-las?
* **tamanho:** retorna o número de elementos na fila.
Essa função pode ser útil para **controlar o tamanho máximo da fila** ou para calcular estatísticas sobre o número de elementos que entram e saem da fila.

**primeiro:** retorna o valor do elemento na frente da fila, sem removê-lo da fila.
Essa função pode ser útil para **verificar qual é o próximo elemento a ser processado** ou para permitir que um usuário visualize o próximo elemento na fila sem removê-lo.

**limpar:** remove todos os elementos da fila.
Essa função pode ser útil quando a fila não é mais **necessária e precisa ser liberada da memória** ou quando a fila precisa ser reiniciada para receber novos elementos.

**inverter:** inverte a ordem dos elementos na fila.
Essa função pode ser útil em situações em que os elementos precisam ser **processados na ordem inversa** em que foram adicionados à fila.

**copiar:** cria uma cópia da fila.
Essa função pode ser útil quando é **necessário manter uma cópia da fila original** enquanto se trabalha com uma cópia modificada da fila.

## 12. Quais as vantagens e desvantagens da implementação de fila por arranjosnecessário manter uma cópia da fila original? 
A implementação de fila por arranjos tem vantagens como acesso **aleatório**, **implementação simples** e **memória contígua**, mas desvantagens como **tamanho fixo**, **ineficiência para inserção e remoção e espaço desperdiçado**. É uma boa opção para problemas simples e que não requerem estrutura de dados dinâmica, mas se a fila precisa ser dinamicamente alterada ou a inserção e remoção de elementos forem frequentes, outras estruturas de dados devem ser consideradas.

## 13. O que é uma fila circular? Como ela se comporta?
Uma fila circular é uma estrutura de dados em que os elementos são armazenados em um arranjo circular. Os novos elementos são adicionados na extremidade traseira da fila, que "enrola" de volta para o início do arranjo quando chega ao final. A extremidade frontal da fila se move na mesma direção, mantendo a ordem dos elementos. Isso permite que a fila tenha tamanho fixo e evita a realocação de memória. É uma implementação eficiente e simples, mas requer tratamento adequado de "overflow" e "underflow".
