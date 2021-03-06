#ifndef HARMONICSTRUCTURE_H
#define HARMONICSTRUCTURE_H

//Bibliotheques c++
#include <vector>

//Bibliotheques Qt
#include <QString>




using namespace std;


class HarmonicStructure
{
private:
    QString name;
    QString alias;
    std::vector<int> intervals;

public:
    HarmonicStructure();
    HarmonicStructure(QString,std::vector<int>,QString al="");
    QString getSerial();
    std::vector<int> getIntervals();
    QString getName();
    QString getAlias();

};

#endif // HARMONICSTRUCTURE_H
