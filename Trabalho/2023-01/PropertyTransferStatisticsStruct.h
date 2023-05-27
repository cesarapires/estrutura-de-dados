#ifndef MYSTRUCT_H
#define MYSTRUCT_H

using namespace std;

struct PropertyTransferStatisticsStruct
{
    int id;
    char seriesReference[256];
    char period[256];
    char dataValue[256];
    char status[256];
    char units[256];
    char magnitude[256];
    char subject[256];
    char periodicity[256];
    char group[256];
    char seriesTitle1[256];
    char seriesTitle2[256];
    char seriesTitle3[256];
    char seriesTitle4[256];
    char seriesTitle5[256];
};

#endif