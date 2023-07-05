#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int UMPRIMO = 7;

class noh {
    friend class lista;
    friend class tabelaHash;
private:
    string chave;
    char tipo;
    int valor;
    noh* proximo;
    noh(const string& c = "", const char& t = 'a', const int& v = 0, noh* prox = NULL):
        chave(c), tipo(t), valor(v), proximo(prox) { }
};

class lista {
    friend class tabelaHash;
private:
    noh* primeiro;
    unsigned short numElementos;
public:
    lista() {
        primeiro = NULL;
        numElementos = 0;
    }
    ~lista() {
        noh* atual = primeiro;
        while (atual != NULL) {
            noh* aux = atual;
            atual = atual->proximo;
            delete aux;
        }
    }
    unsigned short tamanho() {
        return numElementos;
    }
    void insere(const string& c, const char& t, const int& v) {
        noh* novoNoh = new noh(c, t, v);

        if (primeiro == NULL || c < primeiro->chave) {
            novoNoh->proximo = primeiro;
            primeiro = novoNoh;
        } else {
            noh* atual = primeiro;
            noh* anterior = NULL;
            while (atual != NULL && c > atual->chave) {
                anterior = atual;
                atual = atual->proximo;
            }
            novoNoh->proximo = atual;
            anterior->proximo = novoNoh;
        }
        numElementos++;
    }
    bool remove(const string& c) {
        noh* atual = primeiro;
        noh* anterior = NULL;
        while (atual != NULL && atual->chave != c) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (atual == NULL) {
            return false;
        }
        if (anterior == NULL) {
            primeiro = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        delete atual;
        numElementos--;
        return true;
    }
    bool busca(const string& c, char& tipoBuscado, int& valorBuscado) {
        noh* atual = primeiro;
        while (atual != NULL && atual->chave != c) {
            atual = atual->proximo;
        }
        if (atual == NULL) {
            return false;
        }
        tipoBuscado = atual->tipo;
        valorBuscado = atual->valor;
        return true;
    }
    bool verificaOcorrencia(const string& c) {
        noh* atual = primeiro;
        while (atual != NULL) {
            if (atual->chave == c) {
                return true;
            }
            atual = atual->proximo;
        }
        return false;
    }
    void imprime() {
        noh* atual = primeiro;
        while (atual != NULL) {
            cout << "[" << atual->chave << "/"
                 << atual->valor << "]";
            atual = atual->proximo;
        }
    }
};

class tabelaHash {
private:
    lista* tabela;
    unsigned numPosicoes;
    unsigned funcaoHash(const string& s) {
        return funcaoHash(s, numPosicoes);
    }
    unsigned funcaoHash(const string& s, int cap) {
        unsigned pos = 0;
        for (unsigned int i = 0; i < s.size(); ++i)
            pos = (UMPRIMO * pos + s[i]) % cap;
        return pos;
    }
public:
    tabelaHash(unsigned cap = 100) {
        tabela = new lista[cap];
        numPosicoes = cap;
    }
    ~tabelaHash() {
        delete[] tabela;
    }
    bool insere(const string& c, char& t, const int& v) {
        unsigned pos = funcaoHash(c);
        if (tabela[pos].verificaOcorrencia(c)) {
            return false;
        }
        tabela[pos].insere(c, t, v);
        return true;
    }
    bool valor(const string& c, char& tipoBuscado, int& valorRetorno) {
        unsigned pos = funcaoHash(c);
        return tabela[pos].busca(c, tipoBuscado, valorRetorno);
    }
    bool remove(const string& c) {
        unsigned pos = funcaoHash(c);
        return tabela[pos].remove(c);
    }
    void imprime() {
        for (unsigned i = 0; i < numPosicoes; i++) {
            cout << i << ": ";
            tabela[i].imprime();
            cout << endl;
        }
    }
};

int main() {
    int tamanhoTH;
    cin >> tamanhoTH;
    tabelaHash tabela(tamanhoTH);
    char comando;
    string chave;
    char tipo = 'a';
    int valor = -1;
    do {
        try {
            cin >> comando;
            switch (comando) {
            case 'i': // inserir
                cin >> chave >> tipo >> valor;
                if (!tabela.insere(chave, tipo, valor))
                    cout << "Erro na inserção: chave já existente!" << endl;
                else
                    cout << "Chave '" << chave << "' inserida na posição " << tabela.funcaoHash(chave) << endl;
                break;
            case 'r': // remover
                cin >> chave;
                if (!tabela.remove(chave))
                    cout << "Erro na remoção: chave não encontrada!" << endl;
                break;
            case 'l': // buscar
                cin >> chave;
                if (!tabela.valor(chave, tipo, valor))
                    cout << "Erro na busca: chave não encontrada!" << endl;
                else
                    cout << "Tipo: " << tipo << " Valor: " << valor << endl;
                break;
            case 'p': // mostrar estrutura
                tabela.imprime();
                break;
            case 'f': // finalizar
                // verificado no do-while
                break;
            default:
                cerr << "Comando inválido\n";
            }
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f');
    tabela.imprime();
    cout << endl;
    return 0;
}
