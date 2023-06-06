/*
Identificação do grupo:

Alunos:
    Nome: Cesar Augusto Pires
    Nome: Gabriel Aguiar Alves e Silva
*/

#include "conversor.h"
#include "operacoes.h"
#include "menu.h"

using namespace std;

const string NOME_ARQUIVO_SAIDA_TEXTO = "PropertyTransferStatistics.txt";
const string NOME_ARQUIVO_ENTRADA = "PropertyTransferStatistics.csv";
const string NOME_ARQUIVO_SAIDA = "PropertyTransferStatistics.bin";

int main() {
    
    Conversor* conversor = new Conversor(NOME_ARQUIVO_ENTRADA, NOME_ARQUIVO_SAIDA);

    conversor->processar();

    Operacoes* operacoes = new Operacoes(NOME_ARQUIVO_SAIDA, NOME_ARQUIVO_SAIDA_TEXTO);

    Menu* menu = new Menu(operacoes);

    menu->iniciarMenu();

    return 0;
}