/* avl - Árvore Binária de Busca com Balanceamento AVL
 *
 * by Joukim, Outubro de 2020 - Estrutura de Dados (GCC216)
 * Caracteristicas de implementação outubro de 2019:
 * -> tratamento de exceção
 * -> usa dado na forma chave/valor
 * -> uso de métodos recursivos
 * -> sem duplo encadeamento
 * -> invés de transplanta, usa removeMenor
 */

#include <iostream>
#include <stdexcept>

using namespace std;
#include <stdexcept>

struct dado {
    unsigned ano; // ano é a chave para ordenação na AVL
    string cidadeRealizacao;
    unsigned qtdadeFilmesApresentados;   
};

ostream& operator<<(ostream& saida, const dado& e) {
    saida << "(" << e.ano << "," << e.cidadeRealizacao << "," << e.qtdadeFilmesApresentados << ")";
    return saida;
}

istream& operator>>(istream& entrada, dado& e) {
    entrada >> e.ano >> e.cidadeRealizacao >> e.qtdadeFilmesApresentados;
    return entrada;
}
typedef unsigned tipoChave;

class noh {
    friend class avl;
    private:
        dado elemento;
        noh* esq;
        noh* dir;
        unsigned altura;
    public:
        noh(const dado& umDado):
            elemento(umDado),  esq(NULL), dir(NULL), altura(1) { }
        ~noh() { }
        int getAltura();
        int fatorBalanceamento();
};

int noh::getAltura() {
    return altura;
}

int noh::fatorBalanceamento() {
    int alturaEsq = (esq != NULL) ? esq->altura : 0;
    int alturaDir = (dir != NULL) ? dir->altura : 0;
    return alturaEsq - alturaDir;
}

class avl {
    friend ostream& operator<<(ostream& output, avl& arvore);
    private:
        noh* raiz;
        // percorrimento em ordem da árvore
        void percorreEmOrdemAux(noh* atual, int nivel);
        // funções auxiliares para remoção
        noh* encontraMenor(noh* raizSub);
        noh* removeMenor(noh* raizSub);
        // funções auxiliares para inserção e remoção usando método recursivo
        // retorna o nó para ajustar o pai ou o raiz
        noh* insereAux(noh* umNoh, const dado& umDado);
        noh* removeAux(noh* umNoh, tipoChave chave);
        // métodos para manutenção do balanceamento
        noh* rotacaoEsquerda(noh* umNoh);
        noh* rotacaoDireita(noh* umNoh);
        noh* arrumaBalanceamento(noh* umNoh);
        // busca, método iterativo
        noh* buscaAux(tipoChave chave);
        // encontra o valor da maior altura;
        int altura(noh* noh);
        // função auxiliar do destrutor, usa percorrimento pós-ordem
        void destruirRecursivamente(noh* umNoh);
        void imprimirDir(const std::string& prefixo, const noh* meuNoh);
        void imprimirEsq(const std::string& prefixo, const noh* meuNoh, bool temIrmao);
        void levantamentoAux(noh* umNoh, unsigned* ptrAnoProcurado, unsigned* ptrMaiorNumFilmesApres, unsigned* ptrAnoMaisAntigo);
    public:
        avl() { raiz = NULL; }
        ~avl();
        void imprimir();
        // inserção e remoção são recursivos
        void insere(const dado& umDado);
        void remove(tipoChave chave);
        // inserção e remoção, métodos recursivos
        // busca retorna uma cópia do objeto armazenado
        dado busca(tipoChave chave);
        // efetua levantamento do ano com maior número de filmes apresentados
        unsigned levantamento();
};

// destrutor
avl::~avl() {
    destruirRecursivamente(raiz);
}

// destrutor é recursivo, fazendo percorrimento pós-ordem
void avl::destruirRecursivamente(noh* umNoh) {
    if (umNoh != NULL) {
        destruirRecursivamente(umNoh->esq);
        destruirRecursivamente(umNoh->dir);
        delete umNoh;
    }
}

void avl::insere(const dado& umDado) {
    raiz = insereAux(raiz, umDado);
}

// inserção recursiva, devolve nó para atribuição de pai ou raiz
noh* avl::insereAux(noh* umNoh, const dado& umDado) {
    if (umNoh == NULL) {
        noh* novoNoh = new noh(umDado);
        return novoNoh;
    }

    if (umDado.ano < umNoh->elemento.ano)
        umNoh->esq = insereAux(umNoh->esq, umDado);
    else if (umDado.ano > umNoh->elemento.ano)
        umNoh->dir = insereAux(umNoh->dir, umDado);
    else
        throw runtime_error("Erro: chave já existente na árvore!");

    umNoh->altura = 1 + max(altura(umNoh->esq), altura(umNoh->dir));

    return arrumaBalanceamento(umNoh);
}

// checa e arruma, se necessário, o balanceamento em umNoh,
// fazendo as rotações e ajustes necessários
noh* avl::arrumaBalanceamento(noh* umNoh) {
    int fatorBalanceamento = umNoh->fatorBalanceamento();

    if (fatorBalanceamento < -1) {
        if (umNoh->dir->fatorBalanceamento() > 0)
            umNoh->dir = rotacaoDireita(umNoh->dir);

        return rotacaoEsquerda(umNoh);
    }

    if (fatorBalanceamento > 1) {
        if (umNoh->esq->fatorBalanceamento() < 0)
            umNoh->esq = rotacaoEsquerda(umNoh->esq);

        return rotacaoDireita(umNoh);
    }

    return umNoh;
}


// rotação à esquerda na subárvore com raiz em umNoh
// retorna o novo pai da subárvore
noh* avl::rotacaoEsquerda(noh* umNoh) {
noh* aux = umNoh->dir;
    umNoh->dir = aux->esq;
    aux->esq = umNoh;

    umNoh->altura = 1 + max(altura(umNoh->esq), altura(umNoh->dir));
    aux->altura = 1 + max(altura(aux->esq), altura(aux->dir));

    return aux;
}

// rotação à direita na subárvore com raiz em umNoh
// retorna o novo pai da subárvore
noh* avl::rotacaoDireita(noh* umNoh) {
    noh* aux = umNoh->esq;
    umNoh->esq = aux->dir;
    aux->dir = umNoh;

    umNoh->altura = 1 + max(altura(umNoh->esq), altura(umNoh->dir));
    aux->altura = 1 + max(altura(aux->esq), altura(aux->dir));

    return aux;
}


// método de busca auxiliar (retorna o nó), iterativo
noh* avl::buscaAux(tipoChave chave) {
    noh* atual = raiz;

    while (atual != NULL) {
        if (chave < atual->elemento.ano)
            atual = atual->esq;
        else if (chave > atual->elemento.ano)
            atual = atual->dir;
        else
            return atual;
    }

    return NULL;
}

// busca elemento com uma dada chave na árvore e retorna o registro completo
dado avl::busca(tipoChave chave) {
    noh* resultado = buscaAux(chave);
    if (resultado != NULL)
        return resultado->elemento;
    else
        throw runtime_error("Erro na busca: elemento não encontrado!");
}


// nó mínimo (sucessor) de subárvore com raiz em raizSub (folha mais à esquerda)
noh* avl::encontraMenor(noh* raizSub) {
    noh* atual = raizSub;

    while (atual->esq != NULL)
        atual = atual->esq;

    return atual;
}

// procedimento auxiliar para remover o sucessor substituíndo-o pelo
// seu filho à direita
noh* avl::removeMenor(noh* raizSub) {
    if (raizSub->esq == NULL)
        return raizSub->dir;
    else {
        raizSub->esq = removeMenor(raizSub->esq);
        return arrumaBalanceamento(raizSub);
    }
}

// remoção recursiva
void avl::remove(tipoChave chave) {
    raiz = removeAux(raiz, chave);
}

noh* avl::removeAux(noh* umNoh, tipoChave chave) {
    if (umNoh == NULL)
        throw runtime_error("Erro na remoção: elemento não encontrado!");

    if (chave < umNoh->elemento.ano) {
        umNoh->esq = removeAux(umNoh->esq, chave);
        umNoh = arrumaBalanceamento(umNoh);
    } else if (chave > umNoh->elemento.ano) {
        umNoh->dir = removeAux(umNoh->dir, chave);
        umNoh = arrumaBalanceamento(umNoh);
    } else {
        // Caso 1: nó sem filhos ou com apenas um filho
        if (umNoh->esq == NULL || umNoh->dir == NULL) {
            noh* temp = umNoh->esq ? umNoh->esq : umNoh->dir;
            if (temp == NULL) {
                temp = umNoh;
                umNoh = NULL;
            } else {
                *umNoh = *temp;
            }
            delete temp;
        }
        // Caso 2: nó com dois filhos
        else {
            noh* temp = encontraMenor(umNoh->dir);
            umNoh->elemento = temp->elemento;
            umNoh->dir = removeAux(umNoh->dir, temp->elemento.ano);
            umNoh = arrumaBalanceamento(umNoh);
        }
    }

    return umNoh;
}

// utiliza o nó atual e seu nível na árvore (para facilitar visualização)
void avl::percorreEmOrdemAux(noh* atual, int nivel) {
    if (atual != NULL) {
        percorreEmOrdemAux(atual->esq, nivel + 1);

        for (int i = 0; i < nivel; i++)
            cout << "   ";

        cout << "(" << atual->elemento.ano << "," << atual->elemento.cidadeRealizacao << ")" << endl;

        percorreEmOrdemAux(atual->dir, nivel + 1);
    }
}

ostream& operator<<(ostream& output, avl& arvore) {
    arvore.imprimir();
    return output;
}

// imprime formatado seguindo o padrao tree as subarvores direitas de uma avl
void avl::imprimirDir(const std::string& prefixo, const noh* meuNoh)
{
    if( meuNoh != nullptr )
    {
        std::cout << prefixo
                  << "└d─"
                  << "(" << meuNoh->elemento.ano << "," << meuNoh->elemento.cidadeRealizacao << ")"
                  << std::endl;

        // Repassa o prefixo para manter o historico de como deve ser a formatacao e chama no filho direito e esquerdo
        imprimirEsq( prefixo + "    " , meuNoh->esq , meuNoh->dir==nullptr );
        imprimirDir( prefixo + "    " , meuNoh->dir );
    }
}

// imprime formatado seguindo o padrao tree as subarvores direitas de uma avl
void avl::imprimirEsq(const std::string& prefixo, const noh* meuNoh, bool temIrmao)
{
    if( meuNoh != nullptr )
    {
        std::cout << prefixo ;

        // A impressao da arvore esquerda depende da indicacao se existe o irmao a direita
        if (temIrmao)
            std::cout << "└e─" ;
        else
            std::cout << "├e─";

        std::cout << "(" << meuNoh->elemento.ano << "," << meuNoh->elemento.cidadeRealizacao << ")"
                  << std::endl;

        // Repassa o prefixo para manter o historico de como deve ser a formatacao e chama no filho direito e esquerdo
        imprimirEsq( prefixo + "│   " , meuNoh->esq, meuNoh->dir==nullptr );
        imprimirDir( prefixo + "│   " , meuNoh->dir );
    }
}

// imprime formatado seguindo o padrao tree uma avl
void avl::imprimir()
{
    if( this->raiz != nullptr )
    {
        std::cout << "(" << this->raiz->elemento.ano << "," << this->raiz->elemento.cidadeRealizacao << ")" << std::endl;
        // apos imprimir a raiz, chama os respectivos metodos de impressao nas subarvore esquerda e direita
        // a chamada para a impressao da subarvore esquerda depende da existencia da subarvore direita
        imprimirEsq( " " , this->raiz->esq, this->raiz->dir==nullptr );
        imprimirDir( " " , this->raiz->dir );
    } else
        std::cout << "*arvore vazia*" << std::endl;
}

void avl::levantamentoAux(noh* umNoh, unsigned* ptrAnoProcurado, unsigned* ptrMaiorNumFilmesApres, unsigned* ptrAnoMaisAntigo) {
    if (umNoh != NULL) {
        levantamentoAux(umNoh->esq, ptrAnoProcurado, ptrMaiorNumFilmesApres, ptrAnoMaisAntigo);

        if (umNoh->elemento.qtdadeFilmesApresentados > *ptrMaiorNumFilmesApres) {
            *ptrMaiorNumFilmesApres = umNoh->elemento.qtdadeFilmesApresentados;
            *ptrAnoProcurado = umNoh->elemento.ano;
            *ptrAnoMaisAntigo = umNoh->elemento.ano;
        } else if (umNoh->elemento.qtdadeFilmesApresentados == *ptrMaiorNumFilmesApres && umNoh->elemento.ano < *ptrAnoMaisAntigo) {
            *ptrAnoMaisAntigo = umNoh->elemento.ano;
        }

        levantamentoAux(umNoh->dir, ptrAnoProcurado, ptrMaiorNumFilmesApres, ptrAnoMaisAntigo);
    }
}

unsigned avl::levantamento() {
    unsigned maiorNumFilmesApres = 0;
    unsigned anoProcurado = 0;
    unsigned anoMaisAntigo = 0;

    levantamentoAux(raiz, &anoProcurado, &maiorNumFilmesApres, &anoMaisAntigo);

    return anoMaisAntigo;
}

int avl::altura(noh* noh) {
    if (noh != NULL) {
        return noh->getAltura();
    }

    return 0;
}

int main() {
    avl arvore;
    tipoChave chave;
    dado umDado;
    unsigned ano;

    char operacao;

    do {
        try {
            cin >> operacao;
            switch (operacao) {
                case 'i': // Inserir recursivamente
                    // objeto recebe nome, cidade e quantidade de filmes apresentados
                    cin >> umDado;
                    arvore.insere(umDado);
                    break;
                case 'r': // Remover recursivamente
                    cin >> chave;
                    arvore.remove(chave);
                    break;
                case 'b': // Buscar
                    cin >> chave; // ler a chave
                    umDado = arvore.busca(chave); // escrever os dados do festival
                    cout << "Elemento buscado: " << umDado << endl;
                    break;
                case 'l': // Levantamento pelo ano com maior número de filmes apresentados
                    ano = arvore.levantamento( );
                    cout << "Edição com maior quantidade de filmes apresentados: " << ano << endl;
                    break;
                case 'e': // Escrever tudo (em ordem)
                    cout << arvore;
                    break;
                case 'f': // Finalizar execução
                    break;
                default:
                    cout << "Comando invalido!\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (operacao != 'f');

    return 0;
}