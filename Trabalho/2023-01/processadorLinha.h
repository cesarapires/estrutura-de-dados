#include "PropertyTransferStatisticsStruct.h"
#include <cstring>
#include <string>

using namespace std;

class ProcessadorLinha{
    public:
        PropertyTransferStatisticsStruct processarLinha(int numeroRegistro, string linhaCSV);
    private:
        string atributoLinha;
        string restanteLinha;
        void tratarLinha(string linhaCsv);
        float tratarPorcentagem(string atributoLinha);
};

void ProcessadorLinha::tratarLinha(string linhaCsv) {
    string campo;
    unsigned posFimCampo;

    posFimCampo = linhaCsv.find(',');
    campo = linhaCsv.substr(0, posFimCampo);
    linhaCsv.erase(0, posFimCampo + 1);

    this->atributoLinha = campo;
    this->restanteLinha = linhaCsv;
}

float ProcessadorLinha::tratarPorcentagem(string atributoLinha) {
    int ultimaPosicaoAtributo = atributoLinha.length() - 1;
    float atributoRetorno;

    if (atributoLinha[ultimaPosicaoAtributo] == '%') {
        atributoLinha = atributoLinha.substr(0, ultimaPosicaoAtributo);
        atributoRetorno = stof(atributoLinha) / 100;
    }
    else {
        atributoRetorno = stof(atributoLinha);
    }

    return atributoRetorno;
}

PropertyTransferStatisticsStruct ProcessadorLinha::processarLinha(int numeroRegistro, string linhaCSV) {
        PropertyTransferStatisticsStruct subnationalPeriodLifeTables;

        subnationalPeriodLifeTables.id = numeroRegistro;

        this->tratarLinha(linhaCSV);
        strcpy(subnationalPeriodLifeTables.seriesReference, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.period, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.dataValue, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.status, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.units, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.magnitude, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.subject, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.periodicity, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.group, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.seriesTitle1, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.seriesTitle2, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.seriesTitle3, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.seriesTitle4, this->atributoLinha.c_str());

        this->tratarLinha(this->restanteLinha);
        strcpy(subnationalPeriodLifeTables.seriesTitle5, this->atributoLinha.c_str());

        return subnationalPeriodLifeTables;
}