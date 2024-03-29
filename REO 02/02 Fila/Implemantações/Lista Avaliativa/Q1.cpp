#include <iostream>

using namespace std;

const int FILAVAZIA = -1;
const int CAPACIDADE_FILA = 6;

struct Dado {
    string nome;
    string assunto;
    char tipo;
    int nProcesso;
};

// Imprime informações de um dado qualquer.
void imprimir_dado(const Dado& umDado){
    cout << "Nome: " << umDado.nome << " ";
    cout << "Assunto: " << umDado.assunto << " ";
    cout << "Tipo: " << umDado.tipo << " ";
    cout << "Processo: " << umDado.nProcesso << endl;
}

class Fila {
    private:
        Dado* mFila;
        int posPrimeiro, posUltimo, tamanho;
    public:
        // Constrói fila vazia.
        Fila();
        // Destrutor que desaloca memória.
        ~Fila();
        // Retira e retorna o elemento que estiver na primeira posição.
        Dado Desenfileirar(); 
        // Insere um elemento na fila.
        void Enfileirar(const Dado& d);
        // Apagar todos os dados da fila.
        void LimparTudo();
        // Imprime os valores do elemento que está na frente da fila, sem Desenfileirar.
        inline void PrimeiroDaFila();
        // Informa se a fila está Vazia.
        inline bool Vazia();
        // Informa se a fila está Cheia.
        inline bool Cheia();
};

Fila::Fila(){
    posPrimeiro = FILAVAZIA;
    posUltimo = FILAVAZIA;
    tamanho = 0;
    mFila = new Dado[CAPACIDADE_FILA];
}

Fila::~Fila() {
    delete[] mFila;
}

Dado Fila::Desenfileirar() {
    if (this->Vazia()) throw runtime_error("Erro: fila vazia!");
    
    Dado aux = mFila[posPrimeiro];

    if (posPrimeiro == posUltimo) {
        posPrimeiro = FILAVAZIA;
        posUltimo = FILAVAZIA;
    } else {
        posPrimeiro = (posPrimeiro + 1) % CAPACIDADE_FILA;
    }

    tamanho--;
    return aux;
}

void Fila::Enfileirar(const Dado& d) {
    if (this->Cheia()) throw runtime_error("Erro: fila cheia!");

    if (this->Vazia()){
        posPrimeiro++;
    }

    posUltimo = (posUltimo + 1) % CAPACIDADE_FILA;
    tamanho++;
    mFila[posUltimo] = d;      
}

void Fila::LimparTudo() {
    while (not this->Vazia()) {
        this->Desenfileirar();
    }
}

void Fila::PrimeiroDaFila() {
    if (this->Vazia()) throw runtime_error("Erro: fila vazia!");
   
    imprimir_dado(mFila[posPrimeiro]);      
}

bool Fila::Vazia() {

    if (posUltimo == -1) {
        return true;
    }

    return false;

}

bool Fila::Cheia() {
     if (tamanho == CAPACIDADE_FILA) {
        return true;
    }

    return false;   

}


int main() {
    Fila fila;
    Dado info;
    
    return 0;
}