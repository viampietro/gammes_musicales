#ifndef SCALEDICTIONARY_H
#define SCALEDICTIONARY_H

//Bibliotheques c++
#include <iostream>
#include <vector>

//Bibliotheques Qt
#include <QFile>
#include <QTextStream>
#include <QVector>

//Classes
#include "modele/hsscale.h"
#include "modele/scale.h"

class ScaleDictionary
{
private:
    static ScaleDictionary* INSTANCE;
    std::vector<HSScale*> scales;
    std::vector<HSScale*> customScales;

    ScaleDictionary();

public:
    static ScaleDictionary* getInstance();
    vector<Scale*> getScalesByTypes(QVector<QString>);
    HSScale* getScaleByIndex(int);
    HSScale* getHSbyName(QString);
    bool contains(HSScale*);
    void add(HSScale*);
    void addCustom(HSScale*);
    void removeCustom(HSScale*);

    std::vector<Scale*> getAllScales();
    std::vector<Scale*> getBaseScales();
    std::vector<Scale*> getCustomScales();

    void generateBaseScale();
    void generateCustomScale();

    QVector<QString> getHSnames();
    QVector<QString> getCustomHSnames();
    QVector<QString> getBaseHSnames();

    QVector<QString> getHSalias();
    QVector<QString> getCustomHSalias();
    QVector<QString> getBaseHSalias();

    void fillCustomTextFile();

};

#endif // SCALEDICTIONARY_H
