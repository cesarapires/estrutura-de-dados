#include <iostream>

#ifndef MYSTRUCT_H
#define MYSTRUCT_H

using namespace std;

struct PropertyTransferStatisticsStruct
{
    int id;
    char seriesReference[19];
    char period[9];
    char dataValue[12];
    char status[8];
    char units[9];
    char magnitude[11];
    char subject[36];
    char periodicity[13];
    char group[74];
    char seriesTitle1[38];
    char seriesTitle2[23];
    char seriesTitle3[46];
    char seriesTitle4[71];
    char seriesTitle5[53];

    void novasPropertyTransferStatistics(int posicao);
    friend ostream& operator<<(ostream& os, const PropertyTransferStatisticsStruct& stats);
};

ostream& operator<<(ostream& os, const PropertyTransferStatisticsStruct& stats) {
    os << stats.id << " | "
       << stats.seriesReference << " | "
       << stats.period << " | "
       << stats.dataValue << " | "
       << stats.status << " | "
       << stats.units << " | "
       << stats.magnitude << " | "
       << stats.subject << " | "
       << stats.periodicity << " | "
       << stats.group << " | "
       << stats.seriesTitle1 << " | "
       << stats.seriesTitle2 << " | "
       << stats.seriesTitle3 << " | "
       << stats.seriesTitle4 << " | "
       << stats.seriesTitle5 << endl;
    return os;
}

void PropertyTransferStatisticsStruct::novasPropertyTransferStatistics(int posicao) {
    id = posicao;

    cout << "Series Reference: ";
    cin >> seriesReference;

    cout << "Period: ";
    cin >> period;

    cout << "Data Value: ";
    cin >> dataValue;

    cout << "Status: ";
    cin >> status;

    cout << "Subject: ";
    cin >> subject;

    cout << "Periodicity: ";
    cin >> periodicity;

    cout << "Group: ";
    cin >> group;

    cout << "Series Title 1: ";
    cin >> seriesTitle1;

    cout << "Series Title 2: ";
    cin >> seriesTitle2;

    cout << "Series Title 3: ";
    cin >> seriesTitle3;
    
    cout << "Series Title 4: ";
    cin >> seriesTitle4;
        
    cout << "Series Title 5: ";
    cin >> seriesTitle5;
};

#endif