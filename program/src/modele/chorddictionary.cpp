#include "chorddictionary.h"
#include "chord.h"
using namespace std;

ChordDictionary::ChordDictionary()
{

}

ChordDictionary* ChordDictionary::getInstance()
{
    if (INSTANCE==NULL)
        INSTANCE=new ChordDictionary;
    return INSTANCE;
}

bool ChordDictionary::contains(HSChord * c)
{
    for (size_t i=0;i<chords.size();i++)
        if (chords[i]->getIntervals()==c->getIntervals())
            return true;
    return false;
}


int ChordDictionary::getSize(){return chords.size();}
void ChordDictionary::generateBaseChords()
{
    getInstance()->add(new HSChord("M",{4,3}));
    getInstance()->add(new HSChord("+",{4,4}));
    getInstance()->add(new HSChord("m",{3,4}));
    getInstance()->add(new HSChord("2",{2,2,3}));
    getInstance()->add(new HSChord("m2",{2,1,4}));
    getInstance()->add(new HSChord("m4",{3,2,2}));
    getInstance()->add(new HSChord("dim",{3,3}));
    getInstance()->add(new HSChord("sus",{5,2}));
    getInstance()->add(new HSChord("4",{4,1,2}));
    getInstance()->add(new HSChord("m6",{3,4,2}));
    getInstance()->add(new HSChord("m(M7)",{3,4,4}));
    getInstance()->add(new HSChord("7sus",{5,2,3}));
    getInstance()->add(new HSChord("6",{4,3,2}));
    getInstance()->add(new HSChord("M7",{4,3,4}));
    getInstance()->add(new HSChord("m7",{3,4,3}));
    getInstance()->add(new HSChord("M7(#11)",{4,2,5}));
    getInstance()->add(new HSChord("M7(b5)",{4,2,5}));
    getInstance()->add(new HSChord("M7(#5)",{4,4,3}));
    getInstance()->add(new HSChord("m7(b5)",{3,3,4}));
    getInstance()->add(new HSChord("7",{4,3,3}));
    getInstance()->add(new HSChord("m(#5)",{3,5}));
    getInstance()->add(new HSChord("5",{7}));
    getInstance()->add(new HSChord("dim7",{3,3,3}));
    getInstance()->add(new HSChord("7(b5)",{4,2,4}));
    getInstance()->add(new HSChord("7(#5)",{4,4,2}));

}


QVector<QString> ChordDictionary::getHSnames(){
    QVector<QString> res;
    for (size_t i=0;i<chords.size();i++)
        res.push_back(chords[i]->getName());
    return res;
}

HSChord* ChordDictionary::getHSbyName(QString s){
    for (size_t i=0;i<chords.size();i++)
        if (chords[i]->getName()==s)
            return chords[i];
    return NULL;
}

HSChord* ChordDictionary::getChordByIndex(int i){return chords[i];}
vector<Chord*> ChordDictionary::getAllChords()
{
    vector<Chord*> res;
    for (size_t j=0;j<chords.size();j++)
        for (int i=0;i<12;i++)
            res.push_back(new Chord((Note)i,chords[j]));
    return res;
}

void ChordDictionary::add(HSChord *h){if (!contains(h)) chords.push_back(h);}

ChordDictionary* ChordDictionary::INSTANCE = NULL;
