#include <iostream>
#include <stdexcept>

using namespace std;

struct Dado {
    string nome;
    string premio;
    char tipo;
    int tempo;
};

// Imprime as informações de um dado qualquer
void imprimir_dado(const Dado& umDado) {
    cout << "Nome: " << umDado.nome << " ";
    cout << "Premio: " << umDado.premio << " ";
    cout << "Tipo: " << umDado.tipo << " ";
    cout << "tempo: " << umDado.tempo << endl;
}

class Noh {
    friend class Fila;
    private:
        Dado mDado; // poderia ser outro tipo de variável
        Noh* mProx;
    public:
        Noh(Dado v) {
            mDado = v;
            mProx = NULL;
        }        
};

class Fila {
    public:
        // Constrói Fila vazia.
        Fila();
        // Destrutor que desaloca memória.
        ~Fila();
        // Contagem e impressão do tempo para realizar as atividades de um mesmo tipo as colocando na frente da fila.
        void encontrarTipoEColocarNaFrente(const char& tipo); 
        // Retira e retorna o elemento que estiver na frente da Fila.
        Dado Desenfileirar();
        // Insere um elemento na Fila.
        void Enfileirar(const Dado& d);
        // Apagar todos os dados da Fila.
        void LimparTudo();
        // Retorna o elemento que está na frente da Fila, sem desenfileirar.
        inline void Primeiro();
        // Informa se a Fila está Vazia.
        inline bool Vazia();
    private:
        Noh* mPtPrimeiro;
        Noh* mPtrUltimo;
        int tamanho;
};

Fila::Fila() {  
    mPtPrimeiro = NULL;
    mPtrUltimo = NULL;
    tamanho = 0; 
}

Fila::~Fila() {
    mPtPrimeiro = NULL;
}

void Fila::encontrarTipoEColocarNaFrente(const char& tipo) {
    if (this->Vazia()) throw runtime_error("Erro: Fila vazia!");
    int tempoTotal = 0;

    Fila filaAuxiliar;
    Fila inicioFilaAuxilar;

    while (not this->Vazia()){
        Dado auxliar = this->Desenfileirar();

        if (auxliar.tipo == tipo) {
            inicioFilaAuxilar.Enfileirar(auxliar);
            tempoTotal += auxliar.tempo;
        } else {
            filaAuxiliar.Enfileirar(auxliar);
        }
    }

    while (not inicioFilaAuxilar.Vazia()) {
        this->Enfileirar(inicioFilaAuxilar.Desenfileirar());
    }


    while (not filaAuxiliar.Vazia()) {
        this->Enfileirar(filaAuxiliar.Desenfileirar());
    }

    if (tempoTotal > 0) {
        cout << tempoTotal << endl;
    }

}

Dado Fila::Desenfileirar() {
    if (this->Vazia()) {
        mPtrUltimo = NULL;
        throw runtime_error("Erro: Fila vazia!");
    }
    
    Noh* aux = mPtPrimeiro;

    mPtPrimeiro = aux->mProx;

    tamanho--;

    return aux->mDado;
}

void Fila::Enfileirar(const Dado& d) {
    Noh* noh = new Noh(d);

    if (this->Vazia()) {
        mPtPrimeiro = noh;
    } else {
        mPtrUltimo->mProx = noh;
    }

    mPtrUltimo = noh;
    tamanho++;
}

void Fila::LimparTudo() {
 while (not this->Vazia()) {
        this->Desenfileirar();
    }
}

void Fila::Primeiro() {
    if (this->Vazia()) throw runtime_error("Erro: Fila vazia!");

    imprimir_dado(mPtPrimeiro->mDado);
}

bool Fila::Vazia() {
    if (tamanho == 0) {
        return true;
    }   

    return false;
}


int main() {
    Fila fila;
    Dado info;
    char comando;
    do {
        try{
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nome >> info.premio >> info.tipo >> info.tempo;
                    fila.Enfileirar(info);
                    break;
                case 'r': // remover
                    imprimir_dado(fila.Desenfileirar());
                    break;
                case 'l': // limpar tudo
                    fila.LimparTudo();
                    break;
                case 'e': // espiar                
                    fila.Primeiro();
                    break;
                case 'a':
                    char tipo;
                    cin >> tipo;
                    fila.encontrarTipoEColocarNaFrente(tipo);
                    break;
                case 'f': // finalizar
                    // checado no do-while
                    break;
                default:
                    cerr << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    while (not fila.Vazia()) {
        imprimir_dado(fila.Desenfileirar());
    }
    cout << endl;
    return 0;
}