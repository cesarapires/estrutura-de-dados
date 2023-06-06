#include <iostream>

using namespace std;

class Noh {
    friend class Pilha;
    private:
        int mDado; // poderia ser outro tipo de variável
        Noh* mProx;
    public:
        Noh(int v) {
            mDado = v;
            mProx = NULL;
        }        
};

class Pilha {
    public:
        Pilha();
        void operator=(const Pilha& pilha);
        ~Pilha();
        int Desempilhar();
        void Empilhar(const int& d);
        void LimparTudo();
        inline int Topo();
        inline bool Vazia();
    private:
        Noh* mPtTopo;
        int tamanho;
};

Pilha::Pilha() {
    mPtTopo = NULL;
    tamanho = 0;
}

void Pilha::operator=(const Pilha& pilha) {
    this->mPtTopo = pilha.mPtTopo;
    this->tamanho = pilha.tamanho;
}

Pilha::~Pilha() {
    LimparTudo();
}

int Pilha::Desempilhar() {
    Noh* nohAux = mPtTopo;
    mPtTopo = mPtTopo->mProx;
    tamanho--;

    return nohAux->mDado;
}

int Pilha::Topo() {
    return this->mPtTopo->mDado;
}

void Pilha::Empilhar(const int& d) {
    Noh* nohNovo = new Noh(d);

    nohNovo->mProx = this->mPtTopo;
    this->mPtTopo = nohNovo; 
   
    this->tamanho++;
}

void Pilha::LimparTudo() {
    while (not this->Vazia()) {
        cout << this->Desempilhar();
        if (not this->Vazia()) {
            cout << " ";
        }
    }
    cout << endl;
}

bool Pilha::Vazia() {
    if (this->mPtTopo == NULL and this->tamanho == 0) {
        return true;
    }
    return false;
}

void ordenar (Pilha& pilha) {
    Pilha pilhaAux;
    
    while (not pilha.Vazia()) {
        int auxPilha = pilha.Desempilhar();

        if (pilhaAux.Vazia() && not pilha.Vazia()) {
            pilhaAux.Empilhar(pilha.Desempilhar());
        }

        while (not pilhaAux.Vazia() && auxPilha > pilhaAux.Topo()) {
            pilha.Empilhar(pilhaAux.Desempilhar());
        }

        pilhaAux.Empilhar(auxPilha);
    }
}

int main() {
    Pilha pilha;
    int quantidadeNohs, contador = 0;

    cin >> quantidadeNohs;
    while (contador < quantidadeNohs) {
        int valor;
        cin >> valor;
        pilha.Empilhar(valor);
        contador++;
    }

    ordenar(pilha);

    pilha.LimparTudo();

    return 0;
}