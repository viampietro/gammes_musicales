#include "addchordsscalesview.h"

AddChordsScalesView::AddChordsScalesView(bool isChord)
{
    this->setFixedWidth(680);

    this->isChord = isChord;

    this->mainLayout = new QVBoxLayout();

    if (isChord) {
        this->lineEditLabel = new QLabel("Entrez le nom de l'accord (Maximum 5 charactères).");
    }
    else {
        this->lineEditFullNameLabel = new QLabel("Entrez le nom complet de la gamme");
        this->fullNameLineEdit = new QLineEdit();
        this->mainLayout->addWidget(this->lineEditFullNameLabel);
        this->mainLayout->addWidget(this->fullNameLineEdit);
        this->lineEditLabel = new QLabel("Entrez l'abbréviation de la gamme (Maximum 5 caractères).");
        connect(this->fullNameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(checkedSlot()));
    }
    this->lineEdit = new QLineEdit();
    this->lineEdit->setMaxLength(5);
    this->mainLayout->addWidget(this->lineEditLabel);
    this->mainLayout->addWidget(this->lineEdit);
    connect(this->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(checkedSlot()));

    this->intervalleBox = new QGroupBox("Intervalles");
    this->intervalleLayout = new QGridLayout();
    this->seconde_m = new QCheckBox("Seconde Mineur (1/2 ton)");
    connect(this->seconde_m, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(seconde_m);
    this->seconde_M = new QCheckBox("Seconde Majeur (1 ton)");
    connect(this->seconde_M, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(seconde_M);
    this->tierce_m = new QCheckBox("Tierce Mineur (1 ton + 1/2 ton)");
    connect(this->tierce_m, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(tierce_m);
    this->tierce_M = new QCheckBox("Tierce Majeur (2 tons)");
    connect(this->tierce_M, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(tierce_M);
    this->quarte = new QCheckBox("Quarte Juste (2 tons + 1/2 ton)");
    connect(this->quarte, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(quarte);
    this->quarte_a = new QCheckBox("Quarte Augmenté (3 tons)");
    connect(this->quarte_a, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(quarte_a);
    this->quinte = new QCheckBox("Quinte Juste (3 tons + 1/2 ton)");
    connect(this->quinte, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(quinte);
    this->sixte_m = new QCheckBox("Sixte Mineur (4 tons)");
    connect(this->sixte_m, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(sixte_m);
    this->sixte_M = new QCheckBox("Sixte Majeur (4 tons + 1/2 ton)");
    connect(this->sixte_M, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(sixte_M);
    this->septieme_m = new QCheckBox("Septieme Mineur (5 tons)");
    connect(this->septieme_m, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(septieme_m);
    this->septieme_M = new QCheckBox("Septieme Majeur (5 tons + 1/2 ton)");
    connect(this->septieme_M, SIGNAL(clicked(bool)), this, SLOT(checkedSlot()));
    listCheckBox.push_back(septieme_M);
    this->intervalleLayout->addWidget(seconde_m, 0, 0, 1, 1);
    this->intervalleLayout->addWidget(seconde_M, 1, 0, 1, 1);
    this->intervalleLayout->addWidget(tierce_m, 2, 0, 1, 1);
    this->intervalleLayout->addWidget(tierce_M, 3, 0, 1, 1);
    this->intervalleLayout->addWidget(quarte, 0, 1, 1, 1);
    this->intervalleLayout->addWidget(quarte_a, 1, 1, 1, 1);
    this->intervalleLayout->addWidget(quinte, 2, 1, 1, 1);
    this->intervalleLayout->addWidget(sixte_m, 0, 2, 1, 1);
    this->intervalleLayout->addWidget(sixte_M, 1, 2, 1, 1);
    this->intervalleLayout->addWidget(septieme_m, 2, 2, 1, 1);
    this->intervalleLayout->addWidget(septieme_M, 3, 2, 1, 1);
    this->intervalleBox->setLayout(intervalleLayout);
    this->mainLayout->addWidget(this->intervalleBox);

    this->fundamentalLabel = new QLabel("Fondamentale pour l'exemple : ");
    this->fundamentalExemple = new QComboBox();
    this->fundamentalExemple->addItem("C");
    this->fundamentalExemple->addItem("C#");
    this->fundamentalExemple->addItem("D");
    this->fundamentalExemple->addItem("D#");
    this->fundamentalExemple->addItem("E");
    this->fundamentalExemple->addItem("F");
    this->fundamentalExemple->addItem("F#");
    this->fundamentalExemple->addItem("G");
    this->fundamentalExemple->addItem("G#");
    this->fundamentalExemple->addItem("A");
    this->fundamentalExemple->addItem("A#");
    this->fundamentalExemple->addItem("B");
    connect(this->fundamentalExemple, SIGNAL(currentIndexChanged(int)), this, SLOT(checkedSlot()));

    this->mainLayout->addWidget(fundamentalLabel);
    this->mainLayout->addWidget(fundamentalExemple);

    this->notesList.push_back(getFundamental());
    this->exempleDisplay = new ChordsView(this->fundamentalExemple->currentText() + " " + this->lineEdit->text(), notesList, isChord);
    this->mainLayout->addWidget(exempleDisplay);

    this->buttonLayout = new QHBoxLayout();
    this->createButton = new QPushButton("Créer");
    this->returnButton = new QPushButton("Annuler");
    this->buttonLayout->addWidget(createButton);
    connect(createButton, SIGNAL(clicked(bool)), this, SLOT(createSlot()));
    this->buttonLayout->addWidget(returnButton);
    connect(returnButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    this->mainLayout->addLayout(buttonLayout);

    this->setLayout(this->mainLayout);
}

Note AddChordsScalesView::getFundamental()
{
    int choice = fundamentalExemple->currentIndex();
    switch (choice) {
    case 0:
        return Note::C;
    case 1:
        return Note::Csharp;
    case 2:
        return Note::D;
    case 3:
        return Note::Dsharp;
    case 4:
        return Note::E;
    case 5:
        return Note::F;
    case 6:
        return Note::Fsharp;
    case 7:
        return Note::G;
    case 8:
        return Note::Gsharp;
    case 9:
        return Note::A;
    case 10:
        return Note::Asharp;
    case 11:
        return Note::B;
    default:
        return END_OF_LIST;
    }
}
Note AddChordsScalesView::convertIntToNote(int i)
{
    switch (i % 12) {
    case 0:
        return Note::C;
    case 1:
        return Note::Csharp;
    case 2:
        return Note::D;
    case 3:
        return Note::Dsharp;
    case 4:
        return Note::E;
    case 5:
        return Note::F;
    case 6:
        return Note::Fsharp;
    case 7:
        return Note::G;
    case 8:
        return Note::Gsharp;
    case 9:
        return Note::A;
    case 10:
        return Note::Asharp;
    case 11:
        return Note::B;
    default:
        return END_OF_LIST;
    }
}
vector<Note> AddChordsScalesView::getNotesList()
{
    vector<Note> res;
    res.push_back(getFundamental());
    if (this->seconde_m->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 1));
    }
    if (this->seconde_M->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 2));
    }
    if (this->tierce_m->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 3));
    }
    if (this->tierce_M->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 4));
    }
    if (this->quarte->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 5));
    }
    if (this->quarte_a->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 6));
    }
    if (this->quinte->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 7));
    }
    if (this->sixte_m->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 8));
    }
    if (this->sixte_M->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 9));
    }
    if (this->septieme_m->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 10));
    }
    if (this->septieme_M->isChecked()) {
        res.push_back(convertIntToNote(getFundamental() + 11));
    }
    return res;
}
vector<int> AddChordsScalesView::getHS()
{
    vector<int> res;
    int intervalle = 1;
    for (int i = 0; i < listCheckBox.size(); i++) {
        if (listCheckBox[i]->isChecked()) {
            res.push_back(intervalle);
            intervalle = 1;
        }
        else {
            intervalle++;
        }
    }
    return res;
}
QString AddChordsScalesView::getName()
{
    return this->lineEdit->text();
}
QString AddChordsScalesView::getAlias()
{
    if (!isChord)
        return this->fullNameLineEdit->text();
}

void AddChordsScalesView::checkedSlot()
{
    this->notesList.clear();
    this->notesList = getNotesList();

    delete this->exempleDisplay;

    if (isChord)
        this->exempleDisplay = new ChordsView(this->fundamentalExemple->currentText() + " " + this->lineEdit->text(), notesList, this->isChord);
    else
        this->exempleDisplay = new ChordsView(this->fundamentalExemple->currentText() + " " + this->fullNameLineEdit->text(), notesList, this->isChord);

    this->mainLayout->insertWidget(this->mainLayout->count() - 1, exempleDisplay, Qt::AlignHCenter);
}
void AddChordsScalesView::createSlot()
{
    if (getName().size() > 0) {
        if (getHS().size() > 0) {
            if (isChord) {
                emit createChordSignal(this->getName(), this->getHS());
                QMessageBox::information(this, "Accord créé", "Votre accord " + this->getName() + " a été créé et ajouter à la liste.");
                this->close();
            }
            else {
                if (getAlias().size() > 0) {
                    emit createScaleSignal(this->getName(), this->getHS(), this->getAlias());
                    QMessageBox::information(this, "Gamme créée", "Votre gamme " + this->getAlias() + " a été créé avec succès.");
                    this->close();
                }
                else
                    QMessageBox::warning(this, "Aucun nom complet", "Veuillez entrer un nom complet");
            }
        }
        else
            QMessageBox::warning(this, "Accord non conforme", "Une structure harmonique doit être composé d'au moins 2 notes.");
    }
    else {
        QMessageBox::warning(this, "Aucun nom", "Veuillez entrer un nom raccourci");
    }
}
