#ifndef CHORDDICTIONARY_H
#define CHORDDICTIONARY_H

#include <vector>
#include "hschord.h"
class ChordDictionary
{
private :
    static ChordDictionary* INSTANCE;
    std::vector<HSChord*> chords;
    ChordDictionary();
public:
    static ChordDictionary * getInstance();
    HSChord* getChordByIndex(int);
    bool contains(HSChord*);
    void add(HSChord*);
    void generateBaseChords();

};

#endif // CHORDDICTIONARY_H