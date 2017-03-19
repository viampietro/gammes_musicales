#include "algobrut.h"

using namespace std;

AlgoBrut::AlgoBrut(std::vector<std::vector<Scale *> > graph):KpartiteGraph(graph)
{

}


void AlgoBrut::generateSols(int index,vector<Scale*> solutionPossible)
{

    if (index>=KpartiteGraph.size())
        solutionsPossibles.push_back(solutionPossible);
    else
    {
        for (int i=0;i<KpartiteGraph[index].size();i++)
        {
            solutionPossible.push_back(KpartiteGraph[index][i]);
            generateSols(index+1,solutionPossible);
        }

    }
}


vector<vector<Scale*> > AlgoBrut::findLeastsConsecutivesNotesChanges()
{
    vector<int> values;
    int value;

    for (int i=0;i<solutionsPossibles.size();i++)//on remplit le tableau values
    {
        value=0;
        for (int j=0;j<solutionsPossibles[i].size()-1;j++)//on fait la somme des differences de notes entre chaque couple de gammes consécutives
            value+=solutionsPossibles[i][j]->notesDifferencesWithScale(solutionsPossibles[i][j+1]);
        values.push_back(value);
    }

    int minValue=INFINITY;
    for (int i=0;i<values.size();i++)//on cherche la plus petite valeur possible
        minValue=min(values[i],minValue);

    vector<vector<Scale*> >res;
    for (int i=0;i<values.size();i++)//on ajoute dans le résultat retour toutes les occurences de la contrainte optimisée
        if (values[i]==minValue)
            res.push_back(solutionsPossibles[i]);

    return res;

}

vector<vector<Scale*> > AlgoBrut::findLeastsConsecutivesScalesChanges()
{
    vector<int> values;
    int value;

    for (int i=0;i<solutionsPossibles.size();i++)
    {
        value=0;
        for (int j=0;j<solutionsPossibles[i].size()-1;j++)
            if (!solutionsPossibles[i][j]->equals(solutionsPossibles[i][j+1]))
                value++;
        values.push_back(value);
    }

    int minValue=INFINITY;
    for (int i=0;i<values.size();i++)
        minValue=min(minValue,values[i]);

    vector<vector<Scale*> > res;
    for (int i=0;i<values.size();i++)
        if (values[i]==minValue)
            res.push_back(solutionsPossibles[i]);

    return res;
}

vector<vector<Scale*> > AlgoBrut::findLeastsTotalScales()
{
    vector<int> values;
    vector<Scale*> distinctsScales;//sert à stocker les différentes gammes de chaque suite de gammes

    for (int i=0;i<solutionsPossibles.size();i++)
    {

        for (int j=0;j<solutionsPossibles[i].size();j++)
            if (isScaleInScales(solutionsPossibles[i][j],distinctsScales))
                distinctsScales.push_back(solutionsPossibles[i][j]);

        values.push_back(distinctsScales.size());
        distinctsScales.clear();
    }

    int minValue=INFINITY;
    for (int i=0;i<values.size();i++)
        minValue=min(minValue,values[i]);

    vector<vector<Scale*> > res;
    for (int i=0;i<values.size();i++)
        if (values[i]==minValue)
            res.push_back(solutionsPossibles[i]);

    return res;
}

