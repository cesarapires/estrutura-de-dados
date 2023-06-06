#include <iostream>

typedef int Dado;

class Noh {
    friend class Pilha;
    private:
        Dado mDado; // poderia ser outro tipo de variável
        Noh* mPtProx;
};

class Pilha {
    public:
        // Constrói pilha vazia.
        Pilha();
        // Destrutor que desaloca memória.
        ~Pilha();
        // Retira e retorna o valor que estiver no mPtTopo da pilha.
        // Escreve uma mensagem de erro se não for possível desempilhar.
        Dado Desempilhar(); // retorna o mPtTopo da Pilha
        // Insere um valor na pilha.
        void Empilhar(const Dado& d);
        // Apagar todos os dados da pilha.
        void LimparTudo();
        // Informa quantos valores existem na pilha.
        unsigned Tamanho() { return mTamanho; }
        // Retorna o valor que está no mPtTopo sem desempilhar.
        Dado Topo() const;
        // Informa se a pilha está Vazia.
        bool Vazia() const;
    private:
        Noh* mPtTopo;
        unsigned mTamanho;
};

using namespace std;

Pilha::Pilha(){
    posTopo = PILHAVAZIA;
    mPilha = new Dado[TAMANHOPILHA];
}

Pilha::~Pilha() {
    posTopo = PILHAVAZIA;
    mPilha = new Dado[TAMANHOPILHA];
}

Dado Pilha::Desempilhar() {
    if (this->Vazia()) throw runtime_error("Erro: pilha vazia!");

    Dado nohAux = mPilha[posTopo];
    posTopo--;
    return nohAux;
}

void Pilha::Empilhar(const Dado& d) {
    if (this->Cheia()) throw runtime_error("Erro: pilha cheia!");

    this->posTopo++;
    this->mPilha[posTopo] = d;
}

void Pilha::LimparTudo() {
    posTopo = PILHAVAZIA;
}

void Pilha::Topo() {
    if (this->Vazia()) throw runtime_error("Erro: pilha vazia!");

    imprimir_dado(this->mPilha[this->posTopo]);
}

bool Pilha::Vazia() {
    return posTopo == PILHAVAZIA;
}

bool Pilha::Cheia() {
    return posTopo == TAMANHOPILHA - 1;
}

int main() {
    Pilha pilha;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                pilha.Empilhar(valor);
                break;
            case 'r': // remover
                cout << pilha.Desempilhar() << endl;
                break;
            case 'l': // limpar tudo
                pilha.LimparTudo();
                break;
            case 't': // consultar tamanho
                cout << pilha.Tamanho() << endl;
                break;
            case 'e': // espiar
                cout << pilha.Topo() << endl;
                break;
            case 'f': // finalizar
                // checado no do-while
                break;
            default:
                cerr << "comando inválido\n";
        }
    } while (comando != 'f'); // finalizar execução
    while (not pilha.Vazia()) {
        cout << pilha.Desempilhar() << ' ';
    }
    cout << endl;
    return 0;
}