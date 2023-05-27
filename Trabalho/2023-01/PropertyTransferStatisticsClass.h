#ifndef PROPERTYTRANSFERSTATISTICSCLASS_H
#define PROPERTYTRANSFERSTATISTICSCLASS_H

#include "PropertyTransferStatisticsStruct.h"
#include <iostream>
#include <fstream>

using namespace std;

class PropertyTransferStatisticsClass {   
    public: 
        PropertyTransferStatisticsStruct propertyTransferStatisticsStruct;
        PropertyTransferStatisticsStruct novaPropertyTransferStatistics(int posicao);
        void imprimirNaTela();
        void imprimirNoArquivo(ofstream& arquivo);

};

PropertyTransferStatisticsStruct PropertyTransferStatisticsClass::novaPropertyTransferStatistics(int posicao) {
    this->propertyTransferStatisticsStruct.id = posicao;

    cout << "Series Reference: ";
    cin >> this->propertyTransferStatisticsStruct.seriesReference;

    cout << "Period: ";
    cin >> this->propertyTransferStatisticsStruct.period;

    cout << "Data Value: ";
    cin >> this->propertyTransferStatisticsStruct.dataValue;

    cout << "Status: ";
    cin >> this->propertyTransferStatisticsStruct.status;

    cout << "Subject: ";
    cin >> this->propertyTransferStatisticsStruct.subject;

    cout << "Periodicity: ";
    cin >> this->propertyTransferStatisticsStruct.periodicity;

    cout << "Group: ";
    cin >> this->propertyTransferStatisticsStruct.group;

    cout << "Series Title 1: ";
    cin >> this->propertyTransferStatisticsStruct.seriesTitle1;

    cout << "Series Title 2: ";
    cin >> this->propertyTransferStatisticsStruct.seriesTitle2;

    cout << "Series Title 3: ";
    cin >> this->propertyTransferStatisticsStruct.seriesTitle3;
    
    cout << "Series Title 4: ";
    cin >> this->propertyTransferStatisticsStruct.seriesTitle4;
        
    cout << "Series Title 5: ";
    cin >> this->propertyTransferStatisticsStruct.seriesTitle5;

    return this->propertyTransferStatisticsStruct;
};

void PropertyTransferStatisticsClass::imprimirNaTela() {
    cout << propertyTransferStatisticsStruct.id << " | ";
    cout << propertyTransferStatisticsStruct.seriesReference << " | ";
    cout << propertyTransferStatisticsStruct.period << " | ";
    cout << propertyTransferStatisticsStruct.dataValue << " | ";
    cout << propertyTransferStatisticsStruct.status << " | ";
    cout << propertyTransferStatisticsStruct.units << " | ";
    cout << propertyTransferStatisticsStruct.magnitude << " | ";
    cout << propertyTransferStatisticsStruct.subject << " | ";
    cout << propertyTransferStatisticsStruct.periodicity << " | ";
    cout << propertyTransferStatisticsStruct.group << " | ";
    cout << propertyTransferStatisticsStruct.seriesTitle1 << " | ";
    cout << propertyTransferStatisticsStruct.seriesTitle2 << " | ";
    cout << propertyTransferStatisticsStruct.seriesTitle3 << " | ";
    cout << propertyTransferStatisticsStruct.seriesTitle4 << " | ";
    cout << propertyTransferStatisticsStruct.seriesTitle5 << endl;
};

void PropertyTransferStatisticsClass::imprimirNoArquivo(ofstream& arquivo) {
    arquivo << propertyTransferStatisticsStruct.id << " | ";
    arquivo << propertyTransferStatisticsStruct.seriesReference << " | ";
    arquivo << propertyTransferStatisticsStruct.period << " | ";
    arquivo << propertyTransferStatisticsStruct.dataValue << " | ";
    arquivo << propertyTransferStatisticsStruct.status << " | ";
    arquivo << propertyTransferStatisticsStruct.units << " | ";
    arquivo << propertyTransferStatisticsStruct.magnitude << " | ";
    arquivo << propertyTransferStatisticsStruct.subject << " | ";
    arquivo << propertyTransferStatisticsStruct.periodicity << " | ";
    arquivo << propertyTransferStatisticsStruct.group << " | ";
    arquivo << propertyTransferStatisticsStruct.seriesTitle1 << " | ";
    arquivo << propertyTransferStatisticsStruct.seriesTitle2 << " | ";
    arquivo << propertyTransferStatisticsStruct.seriesTitle3 << " | ";
    arquivo << propertyTransferStatisticsStruct.seriesTitle4 << " | ";
    arquivo << propertyTransferStatisticsStruct.seriesTitle5 << endl;
};

#endif