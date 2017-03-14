#include "scalesdisplay.h"

ScalesDisplay::ScalesDisplay(QVector<QString> scaleList) : QGroupBox()
{
    this->scalesLayout = new QGridLayout();
    this->scalesLayout->setAlignment(Qt::AlignTop);
    this->scalesLayout->setHorizontalSpacing(4);
    for(int i=0; i<scaleList.size(); i++)
    {
        this->scalesList.push_back(new ScaleDisplay(scaleList[i]));
    }
    this->setLayout(scalesLayout);

    this->setMinimumSize(400, 100);
    this->setContentsMargins(10, 10, 10, 10);

    refresh();
}

void ScalesDisplay::refresh()
{
    int i=0;
    int j=0;
    int k=0;
    int nb = 0;
    while(i<this->scalesList.size())
    {
        if((i*64)+80>this->width() && !nb)
        {
            nb = k;
            k = 0;
            j++;
        }
        else
        {
            if(k>0 && k==nb)
            {
                k = 0;
                j++;
            }
        }
        this->scalesLayout->addWidget(this->scalesList[i], j, k, 1, 1);
        k++;
        i++;
    }
}
