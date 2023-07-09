#include "../PropertyTransferStatistics/PropertyTransferStatisticsStruct.h"
#include "auxiliarOrdenador.h"
#include <cstring>
#include <fstream>
#include <iostream>

typedef PropertyTransferStatisticsStruct Struct;

using namespace std;

class Ordenador {
    private:
        ifstream arquivoDesordenado;
        ofstream arquivoOrdenado;
        Struct registro;
        int comparaChavesPrimaria(Struct registro1, Struct registro2);
        int comparaChavesSecundaria(Struct registro1, Struct registro2);
        bool intercalaBloco(ifstream auxEntrada[2], ofstream auxSaida[2], int passo, int posicaoSaida);
        void lerRegistros(ifstream auxEntrada[2], Struct registros[2], bool valido[2], int arrayPosicao[2], int passo);
        void intercalarRegistros(Struct registros[2], ofstream auxSaida[2], int posicaoSaida, bool valido[2], int arrayPosicao[2]);
        void escreverRegistroUnico(Struct registros[2], ofstream auxSaida[2], int posicaoSaida, bool valido[2], int arrayPosicao[2]);
        void intercalarBlocosRegistros(int quantidadeRegistros);
    public: 
        Ordenador(const string& arquivoDesordenado, const string& arquivoOrdenado);
        void ordenar();
};

Ordenador::Ordenador(const string& arquivoDesordenado, const string& arquivoOrdenado) {
    this->arquivoDesordenado.open(arquivoDesordenado, ios::binary);
    this->arquivoOrdenado.open(arquivoOrdenado, ios::binary);
};

// chave primária: "seriesReference"
int Ordenador::comparaChavesPrimaria(Struct registro1, Struct registro2) {
    return strcmp(registro1.seriesReference, registro2.seriesReference);
}

// chave secundária: "period"
int Ordenador::comparaChavesSecundaria(Struct registro1, Struct registro2) {
    string periodo1 = registro1.period;
    string periodo2 = registro2.period;

    int ano1 = stoi(periodo1.substr(0, 4));
    int ano2 = stoi(periodo2.substr(0, 4));

    if (ano1 < ano2) {
        return -1;
    } else if (ano1 == ano2) {
        int mes1 = stoi(periodo1.substr(5, 2));
        int mes2 = stoi(periodo2.substr(5, 2));
        if (mes1 <= mes2) {
            return -1;
        }
    }

    return 0;
}

bool Ordenador::intercalaBloco(ifstream auxEntrada[2], ofstream auxSaida[2], int passo, int posicaoSaida) {
    bool intercalou = false;
    bool valido[2] = { false, false };
    int arrayPosicao[2] = { 0, 0 };

    Struct registros[2];

    while ((arrayPosicao[0] + arrayPosicao[1]) < 2 * passo) {
        lerRegistros(auxEntrada, registros, valido, arrayPosicao, passo);
        if (valido[0] && valido[1]) {
            intercalou = true;
            intercalarRegistros(registros, auxSaida, posicaoSaida, valido, arrayPosicao);
        } else {
            intercalou = true;
            escreverRegistroUnico(registros, auxSaida, posicaoSaida, valido, arrayPosicao);
        }
    }

    return intercalou;
}

void Ordenador::lerRegistros(ifstream auxEntrada[2], Struct registros[2], bool valido[2], int arrayPosicao[2], int passo) {
    for (int i = 0; i < 2; i++) {
        if ((arrayPosicao[i] < passo) && (!valido[i])) {
            if (auxEntrada[i].read((char*)(&registros[i]), sizeof(Struct))) {
                valido[i] = true;
            }
            else {
                arrayPosicao[i] = passo;
            }
        }
    }
}

void Ordenador::intercalarRegistros(Struct registros[2], ofstream auxSaida[2], int posicaoSaida, bool valido[2], int arrayPosicao[2]) {
    int comparacao = comparaChavesPrimaria(registros[0], registros[1]);
    if (comparacao < 0) {
        auxSaida[posicaoSaida].write((const char*)(&registros[0]), sizeof(Struct));
        valido[0] = false;
        arrayPosicao[0]++;
    }
    else if (comparacao > 0) {
        auxSaida[posicaoSaida].write((const char*)(&registros[1]), sizeof(Struct));
        valido[1] = false;
        arrayPosicao[1]++;
    }
    else {
        comparacao = comparaChavesSecundaria(registros[0], registros[1]);
        if (comparacao == -1) {
            auxSaida[posicaoSaida].write((const char*)(&registros[0]), sizeof(Struct));
            valido[0] = false;
            arrayPosicao[0]++;
        }
        else {
            auxSaida[posicaoSaida].write((const char*)(&registros[1]), sizeof(Struct));
            valido[1] = false;
            arrayPosicao[1]++;
        }
    }
}

void Ordenador::escreverRegistroUnico(Struct registros[2], ofstream auxSaida[2], int posicaoSaida, bool valido[2], int arrayPosicao[2]) {
    for (int i = 0; i < 2; i++) {
        if (valido[i]) {
            auxSaida[posicaoSaida].write((const char*)(&registros[i]), sizeof(Struct));
            valido[i] = false;
            arrayPosicao[i]++;
        }
    }
}

void Ordenador::ordenar() {
    ofstream arquivoTemporarioB1("arquivoTemporarioB1.dat", ios::binary);
    ofstream arquivoTemporarioB2("arquivoTemporarioB2.dat", ios::binary);
    verificarFalhaAberturaArquivos(this->arquivoDesordenado, this->arquivoOrdenado, arquivoTemporarioB1, arquivoTemporarioB2);

    this->arquivoDesordenado.seekg(0, ios::end);

    long int tamanhoArquivo = obterTamanhoArquivo(this->arquivoDesordenado);
    long int quantidadeRegistros = obterQuantidadeRegistrosArquivo(tamanhoArquivo, this->registro);
    exibirInformacoesArquivo(tamanhoArquivo, quantidadeRegistros);

    this->arquivoDesordenado.seekg(0, ios::beg);

    cout << "Iniciando a ordenação!!" << endl << endl;

    float fatorCorrecao = 0.5;
    long metade = (quantidadeRegistros / 2.0) + fatorCorrecao;
    long int inicio = 0;
    tratarBlocosArquivo(inicio, metade, this->registro, this->arquivoDesordenado, arquivoTemporarioB1);
    tratarBlocosArquivo(metade, quantidadeRegistros, this->registro, this->arquivoDesordenado, arquivoTemporarioB2);

    fecharArquivo(arquivoTemporarioB1);
    fecharArquivo(arquivoTemporarioB2);
    fecharArquivo(this->arquivoDesordenado);

    intercalarBlocosRegistros(quantidadeRegistros);

    remove("arquivoTemporarioB1.dat");
    remove("arquivoTemporarioB2.dat");
    remove("arquivoTemporarioC1.dat");
    remove("arquivoTemporarioC2.dat");
}

void Ordenador::intercalarBlocosRegistros(int quantidadeRegistros) {
    ifstream auxEntrada[2];
    ofstream auxSaida[2];

    long int passo = 1;
    bool ida = true;
    bool ultimo[2];

    while (passo <= quantidadeRegistros) {
        if (ida) {
            auxEntrada[0].open("arquivoTemporarioB1.dat", ios::binary);
            auxEntrada[1].open("arquivoTemporarioB2.dat", ios::binary);
            auxSaida[0].open("arquivoTemporarioC1.dat", ios::binary);
            auxSaida[1].open("arquivoTemporarioC2.dat", ios::binary);
        } else {
            auxEntrada[0].open("arquivoTemporarioC1.dat", ios::binary);
            auxEntrada[1].open("arquivoTemporarioC2.dat", ios::binary);
            auxSaida[0].open("arquivoTemporarioB1.dat", ios::binary);
            auxSaida[1].open("arquivoTemporarioB2.dat", ios::binary);
        }

        if (
            verificarFalhaAberturaArquivo(auxEntrada[0]) ||
            verificarFalhaAberturaArquivo(auxEntrada[1]) ||
            verificarFalhaAberturaArquivo(auxSaida[0]) ||
            verificarFalhaAberturaArquivo(auxSaida[1])
        ) {
            cerr << "Arquivos auxiliares nao puderam ser abertos!" << endl;
            exit(EXIT_FAILURE);
        }

        while ((!auxEntrada[0].eof()) && (!auxEntrada[1].eof())) {
            ultimo[0] = intercalaBloco(auxEntrada, auxSaida, passo, 0);
            ultimo[1] = intercalaBloco(auxEntrada, auxSaida, passo, 1);
        }

        fecharArquivo(auxEntrada[0]);
        fecharArquivo(auxEntrada[1]);
        fecharArquivo(auxSaida[0]);
        fecharArquivo(auxSaida[1]);

        ida = !(ida);
        passo *= 2;
    }

    ifstream auxEnt;
    abrirAuxiliarEntrada(auxEnt, ida, ultimo);
    if(verificarFalhaAberturaArquivo(auxEnt)) {
        cerr << "Arquivo auxiliar nao pode ser aberto!" << endl;
        exit(EXIT_FAILURE);
    }

    while (auxEnt.read((char *)(&this->registro), sizeof(Struct))) {
        this->arquivoOrdenado.write((char *)(&this->registro), sizeof(Struct));
    }

    cout << "Ordenação Finalizada!!" << endl;

    fecharArquivo(auxEnt);
}