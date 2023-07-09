#ifndef OPERACOES_H
#define OPERACOES_H

#include "../PropertyTransferStatistics/PropertyTransferStatisticsStruct.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

class Operacoes {
    private:
        fstream arquivoEntrada;
        ofstream arquivoSaida;
    public:
        Operacoes(const string& arquivoEntrada, const string& arquivoSaida);
        void busca();
        void busca(int comeco, int fim);
        void trocaPosicao(int primeiraPosicao, int segundaPosicao);
        void alterarRegistroPosicao(int posicao);
        void insereNaPosicao(int posicao);
        void transformaEmTxt();
};

Operacoes::Operacoes(const string& nomeArquivoEntrada, const string& nomeArquivoSaida) {
    this->arquivoEntrada.open(nomeArquivoEntrada, ios::binary | ios::out | ios::in);
    this->arquivoSaida.open(nomeArquivoSaida, ios::out);
};

void Operacoes::busca(){
    PropertyTransferStatisticsStruct propertyTransferStatistics;

    this->arquivoEntrada.seekg(0, this->arquivoEntrada.end);
    int quantidadeRegistros = this->arquivoEntrada.tellg()/sizeof(PropertyTransferStatisticsStruct);

    int contador = 0;
    while (contador < quantidadeRegistros) {
        this->arquivoEntrada.seekg(contador * sizeof(PropertyTransferStatisticsStruct));
        this->arquivoEntrada.read((char *)&propertyTransferStatistics, sizeof(PropertyTransferStatisticsStruct));

        cout << propertyTransferStatistics;

        contador++;
    } 
};

void Operacoes::busca(int inicio, int fim){
    PropertyTransferStatisticsStruct propertyTransferStatistics;

    // Caso o inicio seja menor que 0
    if(inicio < 0) inicio = 0;

    // Caso o inicio seja maior que o final
    if(inicio > fim) {
        fim = inicio;
        inicio = 0;
    }

    while (inicio <= fim) {
        this->arquivoEntrada.seekg(inicio * sizeof(PropertyTransferStatisticsStruct));
        this->arquivoEntrada.read((char *)&propertyTransferStatistics, sizeof(PropertyTransferStatisticsStruct));

        cout << propertyTransferStatistics;
        
        inicio++;
    }
};

void Operacoes::trocaPosicao(int primeiraPosicao, int segundaPosicao){
    PropertyTransferStatisticsStruct propertyTransferStatisticsPrimeiraPosicao;
    PropertyTransferStatisticsStruct propertyTransferStatisticsSegundaPosicao;

    this->arquivoEntrada.open("PropertyTransferStatisticsStruct.bin", ios::binary | ios::out | ios::in);

    PropertyTransferStatisticsStruct propertyTransferStatistics;

    this->arquivoEntrada.seekg(primeiraPosicao * sizeof(PropertyTransferStatisticsStruct));
    this->arquivoEntrada.read((char *)&propertyTransferStatisticsPrimeiraPosicao, sizeof(PropertyTransferStatisticsStruct));

    this->arquivoEntrada.seekg(segundaPosicao * sizeof(PropertyTransferStatisticsStruct));
    this->arquivoEntrada.read((char *)&propertyTransferStatisticsSegundaPosicao, sizeof(PropertyTransferStatisticsStruct));

    int posicaoAux = propertyTransferStatisticsPrimeiraPosicao.id;
    propertyTransferStatisticsPrimeiraPosicao.id = propertyTransferStatisticsSegundaPosicao.id;
    propertyTransferStatisticsSegundaPosicao.id = posicaoAux;

    this->arquivoEntrada.seekg(primeiraPosicao * sizeof(PropertyTransferStatisticsStruct));
    this->arquivoEntrada.write((char *)&propertyTransferStatisticsSegundaPosicao, sizeof(PropertyTransferStatisticsStruct));

    this->arquivoEntrada.seekg(segundaPosicao * sizeof(PropertyTransferStatisticsStruct));
    this->arquivoEntrada.write((char *)&propertyTransferStatisticsPrimeiraPosicao, sizeof(PropertyTransferStatisticsStruct));
};

void Operacoes::insereNaPosicao(int posicao) {
    PropertyTransferStatisticsStruct propertyTransferStatistics;
    propertyTransferStatistics.novasPropertyTransferStatistics(posicao);
    PropertyTransferStatisticsStruct aux1;

    this->arquivoEntrada.seekg(0, this->arquivoEntrada.end);
    int quantidadeRegistros = this->arquivoEntrada.tellg()/sizeof(PropertyTransferStatisticsStruct);

    while((quantidadeRegistros) >= (posicao)){

        this->arquivoEntrada.seekg((quantidadeRegistros - 1) * sizeof(PropertyTransferStatisticsStruct));
        this->arquivoEntrada.read((char *)&aux1, sizeof(PropertyTransferStatisticsStruct));
        aux1.id = quantidadeRegistros + 1;
        this->arquivoEntrada.seekg((quantidadeRegistros) * sizeof(PropertyTransferStatisticsStruct));
        this->arquivoEntrada.write((char *)&aux1, sizeof(PropertyTransferStatisticsStruct));

        quantidadeRegistros--;
    }

    this->arquivoEntrada.seekg(posicao * sizeof(PropertyTransferStatisticsStruct));
    this->arquivoEntrada.write((char *)&propertyTransferStatistics, sizeof(PropertyTransferStatisticsStruct));
};

void Operacoes::alterarRegistroPosicao(int posicao){
    PropertyTransferStatisticsStruct propertyTransferStatistics;

    propertyTransferStatistics.novasPropertyTransferStatistics(posicao);

    this->arquivoEntrada.seekg(posicao * sizeof(PropertyTransferStatisticsStruct));
    this->arquivoEntrada.write((char *)&propertyTransferStatistics, sizeof(PropertyTransferStatisticsStruct));
};

void Operacoes::transformaEmTxt() {
    PropertyTransferStatisticsStruct propertyTransferStatistics;

    this->arquivoEntrada.seekg(0, this->arquivoEntrada.end);
    int inicio = 0;
    int quantidadeRegistros = this->arquivoEntrada.tellg()/sizeof(PropertyTransferStatisticsStruct);

    while (inicio <= quantidadeRegistros) {
        this->arquivoEntrada.seekg(inicio * sizeof(PropertyTransferStatisticsStruct));
        this->arquivoEntrada.read((char *)&propertyTransferStatistics, sizeof(PropertyTransferStatisticsStruct));

        this->arquivoSaida << propertyTransferStatistics;

        cout << propertyTransferStatistics;

        inicio++;
    }

};

#endif