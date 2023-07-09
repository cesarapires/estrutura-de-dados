#include "../Operacoes/operacoes.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Menu {
    private:
        Operacoes* operacoes;
        char opcao;
        void mostrarMenu();
        void mostrarMensagemProsseguir();
    public:
        void iniciarMenu();
        Menu(Operacoes* operacoes);
};

Menu::Menu(Operacoes* operacoes) {
    this->operacoes = operacoes;
};

void Menu::mostrarMenu() {
    system("clear||cls");
    cout << "================ O que você deseja ? ================" << endl;
    cout << "(a) Imprimir todos os propertyTransferStatisticss" << endl;
    cout << "(b) Imprimir propertyTransferStatisticss de posição x a y" << endl;
    cout << "(c) Trocar posição de dois propertyTransferStatisticss" << endl;
    cout << "(d) Alterar dados de uma posição" << endl;
    cout << "(e) Adicionar propertyTransferStatistics em uma posição" << endl;
    cout << "(f) Gerar arquivo texto" << endl;
    cout << "(s) Sair" << endl;
    cout << "Opção: ";
    cin >> this->opcao;
};

void Menu::mostrarMensagemProsseguir() {
    char garbage;
    cout << "Precione qualquer tecla para voltar ao menu principal!" << endl;
    cin >> garbage;
};

void Menu::iniciarMenu() {
    do {
        this->mostrarMenu();
        switch (this->opcao){
            case 'a':
                system("clear||cls");
                cout << "================ Imprimir todos os propertyTransferStatisticss ================" << endl;
                this->operacoes->busca();
                this->mostrarMensagemProsseguir();
                break;
            case 'b':
                system("clear||cls");
                cout << "================ Imprimir propertyTransferStatisticss ================" << endl;
                int inicio, fim;
                cout << "Digite a posição de inicio da impressão: ";
                cin >> inicio;
                cout << "Digite a posição de fim da impressão: ";
                cin >> fim;
                this->operacoes->busca(inicio, fim);
                this->mostrarMensagemProsseguir();
                break;
            case 'c':
                system("clear||cls");
                cout << "================ Trocar Posição dos propertyTransferStatisticss ================" << endl;
                int primeira, segunda;
                cout << "Digite a primeira posição: ";
                cin >> primeira;
                cout << "Digite a segunda posição: ";
                cin >> segunda;
                this->operacoes->trocaPosicao(primeira, segunda);
                this->mostrarMensagemProsseguir();
                break;
            case 'd':
                system("clear||cls");
                cout << "================ Mudar Registro de uma Posição ================" << endl;
                int posicao;
                cout << "Digite a posição do propertyTransferStatistics: ";
                cin >> posicao;
                this->operacoes->alterarRegistroPosicao(posicao);
                this->mostrarMensagemProsseguir();
                break;
            case 'e':
                system("clear||cls");
                cout << "================ Inserir propertyTransferStatistics em uma posição ================" << endl;
                cout << "Digite a posição: ";
                cin >> posicao;
                this->operacoes->insereNaPosicao(posicao);
                this->mostrarMensagemProsseguir();
                break;
            case 'f':
                system("clear||cls");
                cout << "================ Gerar arquivo .txt ================" << endl;
                this->operacoes->transformaEmTxt();
                this->mostrarMensagemProsseguir();
                break;
            case 's':
                break;
            default:
                cout << "Opção inválida!!" << endl;
                break;
        }

    } while(opcao != 's');
}