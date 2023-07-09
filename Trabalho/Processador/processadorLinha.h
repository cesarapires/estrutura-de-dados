#include "../PropertyTransferStatistics/PropertyTransferStatisticsStruct.h"
#include <cstring>
#include <string>

using namespace std;

class ProcessadorLinha {
public:
    PropertyTransferStatisticsStruct processarLinha(int numeroRegistro, string linhaCSV);

private:
    string atributoLinha;
    string restanteLinha;

    void tratarLinha(string linhaCsv);
};

void ProcessadorLinha::tratarLinha(string linhaCsv) {
    size_t posFimCampo = linhaCsv.find(',');
    atributoLinha = linhaCsv.substr(0, posFimCampo);
    linhaCsv.erase(0, posFimCampo + 1);
    restanteLinha = linhaCsv;
}

PropertyTransferStatisticsStruct ProcessadorLinha::processarLinha(int numeroRegistro, string linhaCSV) {
    PropertyTransferStatisticsStruct propertyTransferStatistics;
    propertyTransferStatistics.id = numeroRegistro;

    tratarLinha(linhaCSV);
    strcpy(propertyTransferStatistics.seriesReference, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.period, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.dataValue, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.status, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.units, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.magnitude, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.subject, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.periodicity, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.group, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.seriesTitle1, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.seriesTitle2, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.seriesTitle3, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.seriesTitle4, atributoLinha.c_str());

    tratarLinha(restanteLinha);
    strcpy(propertyTransferStatistics.seriesTitle5, atributoLinha.c_str());

    return propertyTransferStatistics;
}