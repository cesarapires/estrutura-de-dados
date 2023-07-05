#include <iostream>
#include <cstdlib>

using namespace std;


struct equipe{
    string nomeEquipe;
    string lider;
    string linguagem; 
    int qtdMembros;
};


void imprimirEquipe(equipe& elenco) {
    cout << "Nome Equipe: " << elenco.nomeEquipe << " "; 
    cout << "Lider: " << elenco.lider << " "; 
    cout << "Linguagem: " << elenco.linguagem << " "; 
    cout << "Quantidade Membros: " << elenco.qtdMembros << " "; 
    cout << endl;
}

class noh {
friend class lista;
private:
    equipe elenco; // poderia ser outro tipo de variável
    noh* proximo;
public:
    //noh();
    noh(equipe d);
};

// construindo time chamando seu construtor
noh::noh(equipe d){
    elenco = d;
    proximo = NULL;
}


// lista dinamicamente encadeada
class lista {
private:
    noh* primeiro;
    int tamanho;
    void removeTodos(); // remove todos os elementos da lista
     // imprime reverso a partir de um nó -> exemplo de uso de recursão
    void imprimeReversoAux(noh* umNoh);
public:
    // construtores e destrutor
    lista();
    lista(const lista& umaLista);
    ~lista();
    // sobrecarga do operador de atribuição
    lista& operator=(const lista& umaLista);  
    // inserção, remoção e procura
    inline void insere(equipe elenco);
    void insereNoFim(equipe elenco);
    void insereNoInicio(equipe elenco);
    void insereNaPosicao(int posicao, equipe elenco);
    int procura(string valor); // retorna a posição do nó com va
    // métodos adicionais (impressão, vazia)
    void imprime();
    void imprimeReverso();
    inline bool vazia();
    void removeNoFim();
    void removeNoInicio();
};


// constrói uma lista inicialmente vazia
lista::lista() {
    this->primeiro = NULL;
    this->tamanho = 0;
}

// construtor de cópia
lista::lista(const lista& umaLista) {
    this->primeiro = umaLista.primeiro;
    this->tamanho = umaLista.tamanho;
}

// destrutor da lista (chama função privada auxiliar)
lista::~lista( ) {

}    

// remove todos os elementos da lista
void lista::removeTodos( ) {

}    

// sobrecarga do operador de atribuição
lista& lista::operator=(const lista& umaLista) {
    // limpa a lista atual
    removeTodos();
     // percorre a lista recebida como parâmetro, copiando os dados
    noh* aux = umaLista.primeiro;
    
    while (aux != NULL) {
        insereNoFim(aux->elenco);
        aux = aux->proximo;  
    }
    
    return *this; 
} 

void lista::insere(equipe elenco) {
    // Cria o novo noh
    noh* novoNoh = new noh(elenco);

    // Atualiza o ponteiro (ultimo) para o novo ultimo elemento da lista
    this->primeiro = novoNoh;

    this->tamanho++;
}


// insere no final da lista
void lista::insereNoFim(equipe elenco) {
    // Caso a lista esteja vazia chamo o método para inserir na lista vazia
    if (vazia()) {
        this->insere(elenco);
        return;
    }

    // Cria o novo noh
    noh* novoNoh = new noh(elenco);

    int ultimo = this->tamanho - 1; 
    this->insereNaPosicao(ultimo, elenco);

    this->tamanho++;
}

// insere no início da lista
void lista::insereNoInicio(equipe elenco) {
    // Caso a lista esteja vazia chamo o método para inserir na lista vazia
    if (vazia()) {
        this->insere(elenco);
        return;
    }

    // Cria o novo noh
    noh* novoNoh = new noh(elenco);

    // Aponta o proximo do novo noh para o primeiro elemento da lista
    novoNoh->proximo = this->primeiro;

    // Atualiza o ponteiro para o novo primeiro elemento da lista
    this->primeiro = novoNoh;

    this->tamanho++;
}

// insere em uma determinada posição da lista
void lista::insereNaPosicao(int posicao, equipe elenco) {
    if (vazia() and posicao <= (this->tamanho -1)) {
        this->insere(elenco);
        return;
    } else if (posicao == 0) {
        this->insereNoInicio(elenco);
        return;
    } else  if (posicao == (this->tamanho -1)) {
        this->insereNoFim(elenco);
        return;
    } else if (posicao > (this->tamanho -1)) {
        throw runtime_error("Posição Inexistente!");
    }

    // Cria o novo noh
    noh* novoNoh = new noh(elenco);

    int contadorPosicao = 1;

    // Pego o noh da posicao atual
    noh* nohAtual = this->primeiro;

    while (contadorPosicao <= (this->tamanho -1)) {
        noh* nohProximo = nohAtual->proximo;

        if (contadorPosicao == posicao) {
            novoNoh = nohProximo;
            nohAtual->proximo = novoNoh;
        }

        nohAtual = nohAtual->proximo;
        contadorPosicao++;
    }

    this->tamanho++;

}

//procura a posição de um determinado elemento
int lista::procura(string valor) {
    if (vazia()) {
        throw runtime_error("Lista vazia!");
    } 

    int contadorPosicao = 0;
    noh* noh = this->primeiro;

    while (contadorPosicao <= (this->tamanho -1)) {
        if (noh->elenco.nomeEquipe == valor) {
            return contadorPosicao;
        }

        noh = noh->proximo;

        contadorPosicao++;
    }
}


// método básico que *percorre* uma lista, imprimindo seus elementos
// poderia percorrer fazendo outra ação (multiplicando valores, por exemplo)
void lista::imprime() {
    if (vazia()) {
        throw runtime_error("Lista vazia!");
    } 

    int contadorPosicao = 0;
    noh* noh = this->primeiro;

    while (contadorPosicao <= (this->tamanho -1)) {
        imprimirEquipe(noh->elenco);
        noh = noh->proximo;

        contadorPosicao++;
    }
}

void lista::imprimeReverso() {
    if (vazia()) {
        throw runtime_error("Lista vazia!");
    }

    this->imprimeReversoAux(this->primeiro);
}

void lista::imprimeReversoAux(noh* umNoh) {
    if (vazia()) {
        throw runtime_error("Lista vazia!");
    }

    if (not umNoh->proximo == NULL) {
        this->imprimeReversoAux(umNoh->proximo);
    }

    imprimirEquipe(umNoh->elenco);
}

// verifica se a lista está vazia
inline bool lista::vazia() {
    return (this->primeiro == NULL);
}
   
void lista::removeNoFim() {
    if (vazia()) {
        throw runtime_error("Lista vazia!");
    } 

    int contadorPosicao = 0;

    // Pego o noh da posicao atual
    noh* nohAntecessor = this->primeiro;
    noh* nohAtual = nohAntecessor->proximo;

    while (contadorPosicao <= (this->tamanho -1)) {

        if (nohAtual->proximo == NULL) {
            nohAntecessor->proximo == NULL;
        }
        
        nohAntecessor = nohAtual;
        nohAtual = nohAtual->proximo;
        contadorPosicao++;
    }
}
    
void lista::removeNoInicio() {
    if (vazia()) {
        throw runtime_error("Lista vazia!");
    } 

    // Noh auxliar aponta para o primeiro elemento da lista
    noh* nohAux = this->primeiro;

    // Noh primeiro aponta para pŕoximo do auxiliar
    this->primeiro = nohAux->proximo;
}

int main() {
    lista minhaLista;
    equipe info;
    char comando;
    int posicao;
    string nomeEquipe;

    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir no começo
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoInicio(info);
                    break;
                case 'h': // inserir no fim
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoFim(info);
                    break;             
                case 'm': // inserir no meio
                    cin >> posicao;
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNaPosicao(posicao,info);
                    break;             
                case 's': // pesquisar
                    cin >> nomeEquipe;
                    cout << minhaLista.procura(nomeEquipe) <<endl;
                    break;                    
                case 'r': // remover primeiro elemento da lista
                    minhaLista.removeNoInicio();
                    break;
                case 'a': // remover último elemento da lista
                    minhaLista.removeNoFim();
                    break;                                   
                case 'p': // limpar tudo
                    minhaLista.imprime();
                    break;
                case 'd': // limpar tudo
                    minhaLista.imprimeReverso();
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
    cout << endl;
    return 0;
}
