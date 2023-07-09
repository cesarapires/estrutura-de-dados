/*
Identificação do grupo:

Alunos:
    Nome: Cesar Augusto Pires
    Nome: Gabriel Aguiar Alves e Silva
*/

#include "Processador/conversor.h"
#include "Operacoes/operacoes.h"
#include "Ordenador/ordenador.h"
#include "Menu/menu.h"

using namespace std;

const string NOME_ARQUIVO_SAIDA_TEXTO = "PropertyTransferStatistics.txt";
const string NOME_ARQUIVO_ENTRADA = "PropertyTransferStatistics.csv";
const string NOME_ARQUIVO_SAIDA = "PropertyTransferStatistics.bin";
const string NOME_ARQUIVO_SAIDA_ORDENADO = "PropertyTransferStatisticsOrdenado.bin";

int main() {
    
    Conversor* conversor = new Conversor(NOME_ARQUIVO_ENTRADA, NOME_ARQUIVO_SAIDA);

    conversor->processar();

    char operacaoOrdenacao;

    cout << "Digite 'o' para realizar a ordenação do arquivo: " ;
    cin >> operacaoOrdenacao;

    string arquivoOperado = NOME_ARQUIVO_SAIDA;

    if (operacaoOrdenacao == 'o') {
        Ordenador* ordenador = new Ordenador(NOME_ARQUIVO_SAIDA, NOME_ARQUIVO_SAIDA_ORDENADO);
        ordenador->ordenar();
        arquivoOperado = NOME_ARQUIVO_SAIDA_ORDENADO;
    }
    
    Operacoes* operacoes = new Operacoes(arquivoOperado, NOME_ARQUIVO_SAIDA_TEXTO);

    Menu* menu = new Menu(operacoes);

    menu->iniciarMenu();

    return 0;
}