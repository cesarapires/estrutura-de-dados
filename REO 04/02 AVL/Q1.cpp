#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <queue>

typedef std::string TChave; // chave da árvore
typedef float TValor; // valor da árvore

// === Declarações das classes ===================================================
class NohAVL; // declaração avançada

class AVL {
    public:
        AVL();
        ~AVL();
        TValor& Valor(TChave chave);
        void EscreverEmOrdem();
        void EscreverNivelANivel(std::ostream& saida);
        void Inserir(TChave chave, const TValor& valor);
        bool ConferirLigacoes();
        void Remover(TChave chave);
    private:
        NohAVL* mPtRaiz;
};

class NohAVL {
    friend std::ostream& operator<<(std::ostream& saida, NohAVL* ptNoh);
    friend void AVL::EscreverNivelANivel(std::ostream& saida);
    public:
        NohAVL (TChave c, const TValor& v);
        ~NohAVL();
        void DesalocarFilhosRecursivo();
        NohAVL* InserirRecursivo(NohAVL* ptNoh);
        NohAVL* MenorRecursivo();
        NohAVL* RemoverRecursivo(TChave chave);
        TValor& Valor(TChave chave);
    private:
        NohAVL* ArrumarBalanceamento();
        void AtualizarAltura();
        int FatorBalanceamento();
        NohAVL* Remover();
        NohAVL* RotacionarEsquerda();
        NohAVL* RotacionarDireita();
        void SubstitutirPor(NohAVL* ptNoh);
        void Transplantar(NohAVL* ptFilho);
        void TrocarFilho(NohAVL* ptAntigo, NohAVL* ptNovo);
        TChave mChave;
        TValor mValor;
        NohAVL* mPtEsq;
        NohAVL* mPtDir;
        NohAVL* mPtPai;
        unsigned int mAltura; // folhas têm altura 1
};

// === Implementações das classes ================================================

using namespace std;

// === Classe NohAVL =============================================================

NohAVL::NohAVL(TChave c, const TValor& v)
    : mChave(c), mValor(v), mPtEsq(NULL), mPtDir(NULL), mPtPai(NULL), mAltura(1) {
}

NohAVL::~NohAVL() {
}

// Faz as rotações e ajustes necessários inclusive do nó pai. Atualiza a altura.
// Retorna o ponteiro para o nó que ficar na posição dele após os ajustes.
NohAVL* NohAVL::ArrumarBalanceamento() {
    AtualizarAltura();
    int fatorBal = FatorBalanceamento();

    if (fatorBal > 1) {
        if (mPtDir->FatorBalanceamento() < 0)
            mPtDir = mPtDir->RotacionarDireita();
            return RotacionarEsquerda();
    } else if (fatorBal < -1) {
        if (mPtEsq->FatorBalanceamento() >0)
            mPtEsq = mPtEsq->RotacionarEsquerda();
        return RotacionarDireita();
    }

    return this;
}

// Calcula e atualiza a altura de um nó.
void NohAVL::AtualizarAltura() {
    int alturaEsq = (mPtEsq != NULL) ? mPtEsq->mAltura : 0;
    int alturaDir = (mPtDir != NULL) ? mPtDir->mAltura : 0;
    mAltura = max(alturaEsq, alturaDir) + 1;
}

// Desaloca todos os descendentes.
void NohAVL::DesalocarFilhosRecursivo() {
    if (mPtEsq != NULL) {
        mPtEsq->DesalocarFilhosRecursivo();
        delete mPtEsq;
    }
    if (mPtDir != NULL) {
        mPtDir->DesalocarFilhosRecursivo();
        delete mPtDir;
    }
}

// Calcula e retorna o fator de balanceamento do nó.
int NohAVL::FatorBalanceamento() {
    int alturaEsq = (mPtEsq != NULL) ? mPtEsq->mAltura : 0;
    int alturaDir = (mPtDir != NULL) ? mPtDir->mAltura : 0;
    return alturaDir - alturaEsq;
}

// Insere um nó numa subárvore. Retorna o ponteiro para o nó que ficou no lugar do que recebeu
// a mensagem.
NohAVL* NohAVL::InserirRecursivo(NohAVL* ptNoh) {
    if (ptNoh->mChave < mChave) {
        if (mPtEsq == NULL) {
            mPtEsq = ptNoh;
            ptNoh->mPtPai = this;
        } else {
            mPtEsq = mPtEsq->InserirRecursivo(ptNoh);
        }
    } else if (ptNoh->mChave > mChave) {
        if (mPtDir == NULL) {
            mPtDir = ptNoh;
            ptNoh->mPtPai = this;
        } else {
            mPtDir = mPtDir->InserirRecursivo(ptNoh);
        }
    }

    return ArrumarBalanceamento();
}

// Busca o nó que tem a menor chave. Retorna o ponteiro para ele.
NohAVL* NohAVL::MenorRecursivo() {
    if (mPtEsq == NULL)
        return this;
    return mPtEsq->MenorRecursivo();
}

// Remove o nó. Retorna o ponteiro para o nó que ficou no lugar dele.
// Confira com RemoverRecursivo(TChave).
NohAVL* NohAVL::Remover() {
    if (mPtEsq == NULL && mPtDir == NULL) {
        if (mPtPai != NULL) {
            if (mPtPai->mPtEsq == this)
                mPtPai->mPtEsq = NULL;
            else
                mPtPai->mPtDir = NULL;
        }
        delete this;
        return NULL;
    } else if (mPtEsq != NULL && mPtDir != NULL) {
        NohAVL* sucessor = mPtDir->MenorRecursivo();
        mChave = sucessor->mChave;
        mValor =sucessor->mValor;
        return mPtDir->RemoverRecursivo(sucessor->mChave);
    } else {
        NohAVL* filho = (mPtEsq != NULL) ? mPtEsq : mPtDir;
        filho->mPtPai = mPtPai;
        if (mPtPai != NULL) {
            if (mPtPai->mPtEsq == this)
                mPtPai->mPtEsq = filho;
            else
                mPtPai->mPtDir = filho;
        }
        delete this;
        return filho;
    }
}

// Busca recursivamente um nó com dada chave e o remove. Retorna o ponteiro para o nó que ficou
// no lugar do nó que recebeu a mensagem.
// Confira com Remover().
NohAVL* NohAVL::RemoverRecursivo(TChave chave) {
    if (chave < mChave) {
        if (mPtEsq == nullptr)
            throw runtime_error("Chave não encontrada.");
        mPtEsq = mPtEsq->RemoverRecursivo(chave);
    } else if (chave > mChave) {
        if (mPtDir == nullptr)
            throw runtime_error("Chave não encontrada.");
        mPtDir = mPtDir->RemoverRecursivo(chave);
    } else {
        if (mPtEsq == nullptr && mPtDir == nullptr) {
            // Caso 1: Nó sem filhos
            delete this;
            return nullptr;
        } else if (mPtEsq != nullptr && mPtDir != nullptr) {
            // Caso 2: Nó com dois filhos
            NohAVL* sucessor = mPtDir->MenorRecursivo();
            mChave = sucessor->mChave;
            mValor = sucessor->mValor;
            mPtDir = mPtDir->RemoverRecursivo(sucessor->mChave);
        } else {
            // Caso 3: Nó com um filho
            NohAVL* filho = (mPtEsq != nullptr) ? mPtEsq : mPtDir;
            filho->mPtPai = mPtPai;
            Transplantar(filho);  // Substitui o nó atual pelo filho
            delete this;
            return filho;
        }
    }

    return ArrumarBalanceamento();
}

// Rotaciona à direita a subárvore. Retorna a nova raiz da subárvore.
NohAVL* NohAVL::RotacionarDireita() {
    NohAVL* aux = mPtEsq;
    mPtEsq = aux->mPtDir;
    if (aux->mPtDir != NULL)
        aux->mPtDir->mPtPai = this;
    aux->mPtPai = mPtPai;
    aux->mPtDir = this;
    mPtPai = aux;
    AtualizarAltura();
    aux->AtualizarAltura();
    return aux;
}

// Rotaciona à esquerda a subárvore. Retorna a nova raiz da subárvore.
NohAVL* NohAVL::RotacionarEsquerda() {
    NohAVL* aux = mPtDir;
    mPtDir = aux->mPtEsq;
    if (aux->mPtEsq != NULL)
        aux->mPtEsq->mPtPai = this;
    aux->mPtPai = mPtPai;
    aux->mPtEsq = this;
    mPtPai = aux;
    AtualizarAltura();
    aux->AtualizarAltura();
    return aux;
}

// Atualiza todas as ligações, para que ptNoh, fique no lugar deste nó.
// Usado na remoção com dois filhos.
void NohAVL::SubstitutirPor(NohAVL* ptNoh) {
    if (mPtPai != NULL) {
        if (mPtPai->mPtEsq == this)
            mPtPai->mPtEsq = ptNoh;
        else
            mPtPai->mPtDir = ptNoh;
    }
    if (mPtEsq != NULL)
        mPtEsq->mPtPai = ptNoh;
    if (mPtDir != NULL)
        mPtDir->mPtPai = ptNoh;
}

// Muda as ligações do pai e do filho para desligar o nó atual.
// Usado para remoção na situação em que não existem os dois filhos.
void NohAVL::Transplantar(NohAVL* ptFilho) {
    if (mPtPai == nullptr) {
        // O nó atual é a raiz da árvore.
        if (ptFilho != nullptr) {
            ptFilho->mPtPai = nullptr;
        }
    } else if (this == mPtPai->mPtEsq) {
        // O nó atual é o filho esquerdo do seu pai.
        mPtPai->mPtEsq = ptFilho;
        if (ptFilho != nullptr) {
            ptFilho->mPtPai = mPtPai;
        }
    } else {
        // O nó atual é o filho direito do seu pai.
        mPtPai->mPtDir = ptFilho;
        if (ptFilho != nullptr) {
            ptFilho->mPtPai = mPtPai;
        }
    }
}

// Substitui um dos filhos por um novo nó.
void NohAVL::TrocarFilho(NohAVL* ptAntigo, NohAVL* ptNovo) {
    if (mPtEsq == ptAntigo)
        mPtEsq = ptNovo;
    else if (mPtDir == ptAntigo)
        mPtDir = ptNovo;
    else
        throw runtime_error("Erro na troca de filho.");
    if (ptNovo != NULL)
        ptNovo->mPtPai = this;
}

// Busca recursivamente uma dada chave e retorna o valor associado a ela.
// Levanta exceção se não encontrar a chave.
TValor& NohAVL::Valor(TChave chave) {
    if (chave < mChave) {
        if (mPtEsq != NULL)
            return mPtEsq->Valor(chave);
    } else if (chave > mChave) {
        if (mPtDir != NULL)
            return mPtDir->Valor(chave);
    } else {
        return mValor;
    }
    throw runtime_error("Chave não encontrada.");
}

// Escreve o conteúdo de um nó no formato [altura:chave/valor].
// Escreve "[]" se o ponteiro recebido for NULL.
ostream& operator<<(ostream& saida, NohAVL* ptNoh) {
    if (ptNoh == NULL)
        saida << "[]";
    else
        saida << '[' << ptNoh->mAltura << ':' << ptNoh->mChave << '/' << ptNoh->mValor << ']';
    return saida;
}

// === Classe AVL =================================================================================
AVL::AVL() : mPtRaiz(NULL) {
}

AVL::~AVL() {
    if (mPtRaiz != NULL) {
        mPtRaiz->DesalocarFilhosRecursivo();
        delete mPtRaiz;
    }
}

// Retorna o valor associado a uma dada chave.
TValor& AVL::Valor(TChave chave) {
    if (mPtRaiz != NULL)
        return mPtRaiz->Valor(chave);
    throw runtime_error("Chave não encontrada.");
}

// Escreve o conteúdo da árvore nível a nível, na saída de dados informada.
// Usado para conferir se a estrutra da árvore está correta.
void AVL::EscreverNivelANivel(ostream& saida) {
    queue<NohAVL*> filhos;
    NohAVL* fimDeNivel = new NohAVL(TChave(), TValor()); // nó especial para marcar fim de um nível
    filhos.push(mPtRaiz);
    filhos.push(fimDeNivel);
    while (not filhos.empty()) {
        NohAVL* ptNoh = filhos.front();
        filhos.pop();
        if (ptNoh == fimDeNivel) {
            saida << "\n";
            if (not filhos.empty())
                filhos.push(fimDeNivel);
        }
        else {
            saida << ptNoh << ' ';
            if (ptNoh != NULL) {
                filhos.push(ptNoh->mPtEsq);
                filhos.push(ptNoh->mPtDir);
            }
        }
    }
    delete fimDeNivel;
}

// Insere um par chave/valor na árvore.
void AVL::Inserir(TChave chave, const TValor& valor) {
    NohAVL* novo = new NohAVL(chave, valor);
    if (mPtRaiz == NULL) {
        mPtRaiz = novo;
    } else {
        mPtRaiz = mPtRaiz->InserirRecursivo(novo);
    }
}

// Remove da árvore o nó que tiver uma dada chave.
void AVL::Remover(TChave chave) {
    if (mPtRaiz == NULL)
        throw runtime_error("Árvore vazia.");
    mPtRaiz = mPtRaiz->RemoverRecursivo(chave);
}

// === Programa ===================================================================================
int main() {
    AVL minhaArvore;
    char opcao;
    TChave chave;
    TValor valor;
    do {
        cin >> opcao;
        switch (opcao) {
            case 'i': // Inserir
                cin >> chave >> valor;
                minhaArvore.Inserir(chave, valor);
                break;
            case 'r': // Remover
                try {
                    cin >> chave;
                    minhaArvore.Remover(chave);
                }
                catch (runtime_error& erro) {
                    cerr << erro.what() << endl;
                }
                break;
            case 'b': // Buscar
                try {
                    cin >> chave;
                    valor = minhaArvore.Valor(chave);
                    cout << valor << endl;
                }
                catch (runtime_error& erro) {
                    cerr << erro.what() << endl;
                }
                break;
            case 'e': // Escrever nós nível a nível
                minhaArvore.EscreverNivelANivel(cout);
                break;
            case 'f': // Finalizar o programa
                // vai verificar depois
                break;
            default:
                cerr << "Opção inválida\n";
        }
    } while (opcao != 'f');
    return 0;
}