#include <iostream>

using namespace std;

const int FILAVAZIA = -1;
const int CAPACIDADE_FILA = 6;

// Imprime informações de um dado qualquer.
void imprimir_dado(const int& umDado){
    cout << "Nome: " << umDado.nome << " ";
    cout << "Assunto: " << umDado.assunto << " ";
    cout << "Tipo: " << umDado.tipo << " ";
    cout << "Processo: " << umDado.nProcesso << endl;
}

class Fila {
    private:
        int* mFila;
        int posPrimeiro, posUltimo, tamanho, capacidade;
    public:
        // Constrói fila vazia.
        Fila(int capacidade);
        // Destrutor que desaloca memória.
        ~Fila();
        // Retira e retorna o elemento que estiver na primeira posição.
        int Desenfileirar(); 
        // Insere um elemento na fila.
        void Enfileirar(const int& d);
        // Apagar todos os dados da fila.
        void LimparTudo();
        // Imprime os valores do elemento que está na frente da fila, sem Desenfileirar.
        inline void PrimeiroDaFila();
        // Informa se a fila está Vazia.
        inline bool Vazia();
        // Informa se a fila está Cheia.
        inline bool Cheia();
};

Fila::Fila(int capacidade){
    this->posPrimeiro = FILAVAZIA;
    this->posUltimo = FILAVAZIA;
    this->tamanho = 0;
    this->capacidade = capacidade;
    this->mFila = new int[capacidade];
}

Fila::~Fila() {
    delete[] this->mFila;
}

int Fila::Desenfileirar() {
    if (this->Vazia()) return;
    
    int aux = mFila[posPrimeiro];

    if (posPrimeiro == posUltimo) {
        posPrimeiro = FILAVAZIA;
        posUltimo = FILAVAZIA;
    } else {
        posPrimeiro = (posPrimeiro + 1) % CAPACIDADE_FILA;
    }

    tamanho--;
    return aux;
}

void Fila::Enfileirar(const int& d) {
    if (this->Cheia()) return;

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
    if (this->Vazia()) return;
   
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

void removeFila (
        const Fila& primeiraFila, 
        const Fila& segundaFila
    ) {
    

}


int main() {
    int capacidade;

    cin >> capacidade;
    // Cria a fila 1 e preenche ela
    Fila fila1(capacidade);
    for (int i = 0; i < capacidade; i++) {
        int dado;
        cin >> dado;
        fila1.Enfileirar(dado);
    }

    cin >> capacidade;
    // Cria a fila 2 e preenche ela
    Fila fila2(capacidade);
    for (int i = 0; i < capacidade; i++) {
        int dado;
        cin >> dado;
        fila2.Enfileirar(dado);
    }
    
    return 0;
}