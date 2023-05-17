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

// Imprim apenas o processo, sem mais informações.
void imprimir_processo(const Dado& umDado){
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
        // Informar o número de processos daquele tipo e imprimir na tela.
        void mostrarProcessos( const char& tipo);
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

void Fila::mostrarProcessos(const char& tipo) {
    if (this->Vazia()) throw runtime_error("Erro: fila vazia!");

    int numeroProcessos = 0;
    Fila filaAuxiliar;

    while (not this->Vazia()) {
        Dado dadoAuxiliar = this->Desenfileirar();

        if (dadoAuxiliar.tipo == tipo) {
            imprimir_processo(dadoAuxiliar);
            numeroProcessos++;
        }

        filaAuxiliar.Enfileirar(dadoAuxiliar);
    }

    while (not filaAuxiliar.Vazia()) {
        this->Enfileirar(filaAuxiliar.Desenfileirar());
    }

    cout << "Numero de processos: " << numeroProcessos << endl;
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
    char comando;
    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nome >> info.assunto >> info.tipo >> info.nProcesso;
                    fila.Enfileirar(info);
                    break;
                case 'r': // remover
                    imprimir_dado(fila.Desenfileirar());
                    break;
                case 'l': // limpar tudo
                    fila.LimparTudo();
                    break;
                case 'e': // espiar 
                    if(!fila.Vazia())               
                        fila.PrimeiroDaFila();
                    else
                        cout << "Erro: fila vazia!"<< endl;
                    break;
                case 'c':
                    char tipo;
                    cin >> tipo;
                    fila.mostrarProcessos(tipo);
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