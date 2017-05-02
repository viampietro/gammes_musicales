#include "algobrutomega.h"

AlgoBrutOmega::AlgoBrutOmega(vector<Chord*> SA,vector<Scale*> AS):AlgoBrut(SA,AS)
{

}


void AlgoBrutOmega::generateSolsRec(int index,vector<Scale*> solutionPossible,int omega,int constraint)
{

    if (index>=(int)filteredKpartiteGraph.size()){
        minOmega=min(minOmega,omega);
        if (omega<=minOmega){
            omegas.push_back(omega);
            possiblesSolutions.push_back(solutionPossible);
        }
    }
    else
    {
        for (size_t i=0;i<filteredKpartiteGraph[index].size();i++)
        {
            int value;

            if (constraint==0){//LeastsConsecutivesNotesChanges
                if (solutionPossible.size()==0)
                    value=0;
                else value=solutionPossible.back()->notesDifferencesWithScale(filteredKpartiteGraph[index][i]);
            }
            else if (constraint==1){//LeastsConsecutivesScalesChanges
                if (solutionPossible.size()==0)
                    value=0;
                else if (solutionPossible.back()->equals(filteredKpartiteGraph[index][i]))
                    value=0;
                else value=1;
            }
            else if (constraint==2){//LeastsTotalScales
                if (solutionPossible.size()==0)
                    value=1;
                else if (isScaleInScales(filteredKpartiteGraph[index][i],solutionPossible))
                    value=0;
                else value=1;
            }

            if ((omega+value)<=minOmega){
                vector<Scale*> sol=solutionPossible;
                sol.push_back(filteredKpartiteGraph[index][i]);
                generateSolsRec(index+1,sol,omega+value,constraint);
            }

            /***plus performant mais plus moche***
            solutionPossible.push_back(filteredKpartiteGraph[index][i]);
            generateSolsRec(index+1,solutionPossible,omega+value);
            solutionPossible.pop_back();
            **************************************/
        }
    }
}

void AlgoBrutOmega::findLeastsConsecutivesNotesChanges(){
    possiblesSolutions.clear();
    vector<Scale*> vide;
    minOmega=10000000;
    generateSolsRec(0,vide,0,0);
    filterPossiblesSolutions();
    minOmega=10000000;
    results=possiblesSolutions;
}

void AlgoBrutOmega::findLeastsConsecutivesScalesChanges(){
    possiblesSolutions.clear();
    vector<Scale*> vide;
    minOmega=10000000;
    generateSolsRec(0,vide,0,1);
    filterPossiblesSolutions();
    minOmega=10000000;
    results=possiblesSolutions;
}

void AlgoBrutOmega::findLeastsTotalScales(){
    possiblesSolutions.clear();
    vector<Scale*> vide;
    minOmega=10000000;
    generateSolsRec(0,vide,0,2);
    filterPossiblesSolutions();
    minOmega=10000000;
    results=possiblesSolutions;

}


void AlgoBrutOmega::filterPossiblesSolutions(){
    if ((int)possiblesSolutions.size()!=(int)omegas.size())
        return;
    vector<vector<Scale*> > filteredPossiblesSolutions;
    for (size_t i=0;i<omegas.size();i++){
        if (omegas[i]<=minOmega)
            filteredPossiblesSolutions.push_back(possiblesSolutions[i]);
    }
    possiblesSolutions=filteredPossiblesSolutions;
}