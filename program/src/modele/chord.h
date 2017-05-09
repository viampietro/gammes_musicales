#ifndef CHORD_H
#define CHORD_H

#include "cs.h"
#include "scale.h"
#include "scaledictionary.h"
#include <QStringList>
#include "chorddictionary.h"
#include <stdexcept>
#include <iostream>

class Chord : public CS
{
public:
    Chord(){}
    Chord(QString name);
    Chord(Note f2, HarmonicStructure* hs2);
    std::vector<Scale*> candidatesScales();

};

#endif // CHORD_H
