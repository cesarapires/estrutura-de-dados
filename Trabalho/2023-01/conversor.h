#include "PropertyTransferStatisticsStruct.h"
#include "processadorLinha.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

class Conversor {
    private:
        ifstream arquivoEntrada;
        ofstream arquivoSaida;
        int contadorLinhas;
        void iniciarProcesso();
        void finalizarProcesso();
    public:
        Conversor(const string& nomeArquivoEntrada, const string& nomeArquivoSaida);
        void processar();

};

Conversor::Conversor(const string& nomeArquivoEntrada, const string& nomeArquivoSaida){
    this->arquivoEntrada.open(nomeArquivoEntrada);
    this->arquivoSaida.open(nomeArquivoSaida, ios::binary | ios::out);

    this->contadorLinhas = 1;
};

void Conversor::iniciarProcesso() {
    cout << "Realizando conversão do arquivo CSV em binário" << endl;

    if (!this->arquivoEntrada) {
        cerr << "Não foi possível ler o arquivo" << endl;
        this->finalizarProcesso();
        exit(EXIT_FAILURE);
    }
};

void Conversor::finalizarProcesso() {
    this->arquivoEntrada.close();
    this->arquivoSaida.close();
}

void Conversor::processar() {
    this->iniciarProcesso();

    string LinhaCSV;
    ProcessadorLinha processadorLinha;

    getline(this->arquivoEntrada, LinhaCSV);
    while (getline(this->arquivoEntrada, LinhaCSV)) {
        PropertyTransferStatisticsStruct propertyTransferStatistics = processadorLinha.processarLinha(this->contadorLinhas, LinhaCSV);

        this->arquivoSaida.write((const char *)(&propertyTransferStatistics), sizeof(PropertyTransferStatisticsStruct));
        this->contadorLinhas++;
        
        cout << '.';
    }

    cout << endl;

    this->finalizarProcesso();
};
