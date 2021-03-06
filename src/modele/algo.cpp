#include "algo.h"

using namespace std;

vector<vector<Scale*> > KpartitesScales(vector<Chord*> SA)
{
    vector<vector<Scale*> > Kpartite;
    vector<Scale*> candidateScales;

    for (size_t i = 0; i < SA.size(); i++) {

        candidateScales = SA[i]->candidatesScales();

        if (candidateScales.size() > 0)
            Kpartite.push_back(candidateScales);
    }

    return Kpartite;
}

/**
 * @brief isNoteInNotes
 *  Verifie si une note est dans une suite de notes
 *  (suite de notes qui represente un accord ou une gamme)
 * @param n
 *  note
 * @param s
 *  suite de note
 * @return
 */
bool isNoteInNotes(Note n, vector<Note> s)
{
    for (size_t i = 0; i < s.size(); i++)
        if (s[i] == n)
            return true;
    return false;
}

bool isScaleInScales(Scale* scale, vector<Scale*> scales)
{
    for (size_t i = 0; i < scales.size(); i++)
        if (scales[i]->equals(scale))
            return true;
    return false;
}
