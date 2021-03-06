#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Ut " UT_VERSION);
    this->setMinimumSize(540, 480);
    QIcon icon("../assets/pictures/cle.png");
    this->setWindowIcon(icon);

    this->mainLayout = new QGridLayout();
    this->ui->centralWidget->setLayout(this->mainLayout);

    constructMenuBar();
    constructLayout();

    this->parametersWindow = new ParametersDisplay();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::constructMenuBar()
{
    QMenuBar* menuBar = new QMenuBar();

    QMenu* file = menuBar->addMenu("Fichier");
    QAction* newFile = new QAction("Nouveau", menuBar);
    connect(newFile, SIGNAL(triggered(bool)), this, SLOT(slotNewFile()));
    QAction* importFile = new QAction("Importer", menuBar);
    connect(importFile, SIGNAL(triggered(bool)), this, SLOT(slotImportFile()));
    QAction* saveFile = new QAction("Enregistrer", menuBar);
    connect(saveFile, SIGNAL(triggered(bool)), this, SLOT(slotSaveFile()));
    QAction* closeFile = new QAction("Quitter", menuBar);
    connect(closeFile, SIGNAL(triggered(bool)), this, SLOT(slotCloseFile()));
    file->addAction(newFile);
    file->addAction(importFile);
    file->addAction(saveFile);
    file->addAction(closeFile);

    QMenu* chords = menuBar->addMenu("Accords");
    QAction* addChords = new QAction("Ajouter", menuBar);
    connect(addChords, SIGNAL(triggered(bool)), this, SLOT(slotAddChord()));
    QAction* deleteChords = new QAction("Supprimer", menuBar);
    connect(deleteChords, SIGNAL(triggered(bool)), this, SLOT(slotDeleteChordView()));
    chords->addAction(addChords);
    chords->addAction(deleteChords);

    QMenu* scales = menuBar->addMenu("Gammes");
    QAction* addScales = new QAction("Ajouter", menuBar);
    connect(addScales, SIGNAL(triggered(bool)), this, SLOT(slotAddScale()));
    QAction* deleteScales = new QAction("Supprimer", menuBar);
    connect(deleteScales, SIGNAL(triggered(bool)), this, SLOT(slotDeleteScaleView()));

    scales->addAction(addScales);
    scales->addAction(deleteScales);

    // A decommenter le jour ou on implementera un onglet d'options du programme.
    //     QMenu *options = menuBar->addMenu("Options");

    QAction* stats = menuBar->addAction("Statistiques");
    connect(stats, SIGNAL(triggered(bool)), this, SLOT(slotStats()));

    this->setMenuBar(menuBar);
}

void MainWindow::constructLayout()
{
    this->mainLayout->setAlignment(Qt::AlignTop);
    this->chordsLayout = new QGridLayout();
    constructChordsLayout();
    this->choicesDisplay = new QGroupBox();
    this->choicesLayout = new QGridLayout();

    this->choicesDisplay->setLayout(choicesLayout);
    constructChoicesLayout();

    this->scalesLayout = new QGridLayout();
    constructScalesLayout();
    this->returnButton = new QPushButton("Retour");
    QObject::connect(this->returnButton, SIGNAL(clicked()), this, SLOT(slotReturnButton()));
    this->returnButton->setVisible(false);

    this->mainLayout->addLayout(this->chordsLayout, 0, 0, 1, 1);
    this->mainLayout->addWidget(this->choicesDisplay, 1, 0, 1, 1);
    this->mainLayout->addLayout(this->scalesLayout, 2, 0, 1, 1);
    this->mainLayout->addWidget(this->returnButton, 4, 0, 1, 1);
}
void MainWindow::constructChordsLayout()
{
    this->clearLayout(this->chordsLayout, true);

    this->cListDisplay = new ChordsListDisplay();
    this->reinitializeButton = new QPushButton("Réinitialiser");
    this->reinitializeButton->setFixedWidth(70);
    QObject::connect(this->reinitializeButton, SIGNAL(clicked()), this, SLOT(slotReinitializeButton()));

    this->chordsLayout->addWidget(this->cListDisplay, 0, 0, 2, 6);
    this->chordsLayout->addWidget(this->reinitializeButton, 1, 6, 1, 1);
    this->reinitializeButton->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
}
void MainWindow::constructChoicesLayout()
{
    this->clearLayout(this->choicesLayout, true);

    this->choicesDisplay->setFixedHeight(70);

    this->noteLabel = new QLabel("Fondamentale");
    this->noteLabel->setAlignment(Qt::AlignCenter);

    this->hsLabel = new QLabel("Structure harmonique");
    this->hsLabel->setAlignment(Qt::AlignCenter);

    this->noteComboBox = new QComboBox();
    this->noteComboBox->addItem("C");
    this->noteComboBox->addItem("C#");
    this->noteComboBox->addItem("D");
    this->noteComboBox->addItem("D#");
    this->noteComboBox->addItem("E");
    this->noteComboBox->addItem("F");
    this->noteComboBox->addItem("F#");
    this->noteComboBox->addItem("G");
    this->noteComboBox->addItem("G#");
    this->noteComboBox->addItem("A");
    this->noteComboBox->addItem("A#");
    this->noteComboBox->addItem("B");

    this->hsComboBox = new QComboBox();
    this->addButton = new QPushButton("Ajouter", this);
    QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(slotAddButton()));

    this->parametersButton = new QPushButton("Paramètres de Calcul");
    QObject::connect(this->parametersButton, SIGNAL(clicked()), this, SLOT(slotParametersButton()));

    this->generateButton = new QPushButton("Générer");
    QObject::connect(this->generateButton, SIGNAL(clicked()), this, SLOT(slotGenerateButton()));

    this->choicesLayout->addWidget(this->noteLabel, 0, 0, 1, 1);
    this->choicesLayout->addWidget(this->hsLabel, 0, 1, 1, 1);
    this->choicesLayout->addWidget(this->noteComboBox, 1, 0, 1, 1);
    this->choicesLayout->addWidget(this->hsComboBox, 1, 1, 1, 1);
    this->choicesLayout->addWidget(this->addButton, 1, 2, 1, 1);
    this->choicesLayout->addWidget(new QLabel(), 1, 3, 1, 1);
    this->choicesLayout->addWidget(this->parametersButton, 1, 4, 1, 1);
    this->choicesLayout->addWidget(new QLabel(), 1, 5, 1, 1);
    this->choicesLayout->addWidget(this->generateButton, 1, 6, 1, 1);
}

void MainWindow::constructScalesLayout()
{
    this->clearLayout(this->scalesLayout, true);

    this->sListDisplay = new ScalesListDisplay();

    this->scalesLayout->addWidget(this->sListDisplay, 0, 0, 1, 1);

    this->sListDisplay->setVisible(false);
    connect(this->sListDisplay, SIGNAL(saveScaleSignal(QVector<QString>)), this, SLOT(slotSaveScale(QVector<QString>)));
    connect(this->sListDisplay, SIGNAL(exportScaleSignal(QVector<QString>)), this, SLOT(slotExportScale(QVector<QString>)));
}

void MainWindow::clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (deleteWidgets) {
            if (QWidget* widget = item->widget())
                delete widget;
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}

/**
 * @brief openExplorer
 *  Verifie si une note est dans une suite de notes
 *  (suite de notes qui represente un accord ou une gamme)
 * @param i
 *  mode de lancement de la méthode
 * @return QString
 * path du fichier a ouvrir
 */
QString MainWindow::openExplorer(int i)
{
    this->explorer = new QFileDialog();
    QStringList fileNameTemp;
    QString fileName = "";

    switch (i) {
    case 1:
        this->explorer->setFileMode(QFileDialog::ExistingFile);
        break;
    case 2:        
        this->explorer->setNameFilter(tr("Fichiers textes (*.txt)"));
        break;
    case 3:
        this->explorer->setNameFilter(tr("Fichiers xml (*.xml)"));
        break;
    }

    if (this->explorer->exec()) {
        fileNameTemp = this->explorer->selectedFiles();
        fileName = fileNameTemp[0];
    }

    return fileName;
}

/**
 * @brief testFile
 * Vérifie si le fichier texte à importer est conforme aux normes instaurées
 * @param filePath
 *  path du file a tester
 * @return QVector<QString>
 * liste des accords a ajouter à la vue
 */
QVector<QString> MainWindow::testFile(QString filePath)
{
    QString fileContent = "";
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        fileContent = file.readAll();

        // Suppression du caractere EOF sur linux
        if (fileContent[fileContent.length() - 1] == '\n')
            fileContent = fileContent.left(fileContent.length() - 1);

        file.close();
    }

    QStringList listChords = fileContent.split(' ');
    QVector<QString> res = listChords.toVector();
    vector<Chord*> chords;
    Chord* testChord;

    int i = 0;
    while (i < res.size()) {
        try {
            testChord = new Chord(res[i]);
            testChord->getName();
        }
        catch (std::out_of_range) {
            res.clear();
            cout << "Exception raised by " << testChord->getName().toStdString() << ", accord numero " << i << endl;
            break;
        }

        i++;
    }

    return res;
}

void MainWindow::saveFile(QString filePath, QString fileContent)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Création d'un objet QTextStream à partir de notre objet QFile
        QTextStream flux(&file);
        // On choisit le codec correspondant au jeu de caractère que l'on souhaite ; ici, UTF-8
        flux.setCodec("UTF-8");
        // Écriture des différentes lignes dans le fichier
        flux << fileContent;
        file.close();
    }
}
void MainWindow::fillComboBoxHS(QVector<QString> listHS)
{
    this->hsComboBox->clear();
    for (int i = 0; i < listHS.size(); i++) {
        this->hsComboBox->addItem(listHS[i]);
    }
}

void MainWindow::fillParametersLists(QVector<QString> listHSScales, QVector<QString> listAlias, QVector<QString> listHSCustomScales, QVector<QString> listCustomAlias)
{
    this->parametersWindow->fillLists(listHSScales, listAlias, listHSCustomScales, listCustomAlias);
}

void MainWindow::constructScaleFoundView(QVector<QVector<QString> > listFoundScales, QString msg)
{
    this->sListDisplay->constructScalesFoundList(listFoundScales);
    this->sListDisplay->setName(msg);
}

ParametersDisplay* MainWindow::getParametersDisplay()
{
    return this->parametersWindow;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    this->cListDisplay->refresh();
    this->sListDisplay->refresh();
}

void MainWindow::removeDeletedChords(HSChord* hs)
{
    this->cListDisplay->removeChordByHs(hs);
}

void MainWindow::slotAddButton() //Ajoute lors de l'appuie sur le bouton "Ajouter", les choix d'accords courant au layout d'accords
{
    this->cListDisplay->addChord(this->noteComboBox->currentText(), this->hsComboBox->currentText());
}
void MainWindow::slotGenerateButton()
{
    if (this->cListDisplay->getListChords().size() > 0) {
        this->sListDisplay->setVisible(true);
        this->choicesDisplay->setVisible(false);
        this->returnButton->setVisible(true);
        this->reinitializeButton->setDisabled(true);
        this->cListDisplay->disableDeletingChords();
        emit generateSignal(cListDisplay->getListChordsName());
    }
    else {
        QMessageBox::information(this, "Aucun accord spécifié", "Vous n'avez sélectionné aucun accord. Pour générer une suite de gamme, veuillez d'abord entrer une suite d'accord.");
    }
}

void MainWindow::goToResultsInterface()
{
    this->sListDisplay->setVisible(true);
    this->choicesDisplay->setVisible(false);
    this->returnButton->setVisible(true);
    this->reinitializeButton->setDisabled(true);
    this->cListDisplay->disableDeletingChords();
}

void MainWindow::slotReturnButton()
{
    constructScalesLayout();
    this->sListDisplay->setVisible(false);
    this->choicesDisplay->setVisible(true);
    this->returnButton->setVisible(false);
    this->reinitializeButton->setDisabled(false);
    this->cListDisplay->enableDeletingChords();
    clearLayout(this->scalesLayout);
    constructScalesLayout();
}
void MainWindow::slotReinitializeButton()
{
    clearLayout(this->chordsLayout);
    constructChordsLayout();
}
void MainWindow::slotParametersButton()
{
    this->parametersWindow->show();
}
void MainWindow::slotNewFile()
{
    clearLayout(this->mainLayout);
    constructLayout();
}
void MainWindow::slotImportFile()
{
    QString filePath = openExplorer(1);
    QVector<QString> listChords = testFile(filePath);

    if (listChords.size() != 0) {
        for (int i = 0; i < listChords.size(); i++) {
            this->cListDisplay->addChord(listChords[i]);
        }
    }
    else {
        QMessageBox::warning(this, "Fichier erroné", "Le fichier que vous avez sélectionné n'est pas au bon format. Il peut s'agir de l'extension (.txt) ou bien de la convention lors de la rédaction de vos accords qui n'a pas été respéctée. Veuillez vérifier votre fichier et recommencer.\nPour plus d'informations sur la façon de rédiger vos accords, veuillez vous référer à l'aide.");
    }
}
void MainWindow::slotSaveFile()
{
    QString filePath = openExplorer(2);

    QStringList ext = filePath.split('.');
    if (ext.last() != "txt")
        filePath += ".txt";

    QVector<QString> listChordsName = this->cListDisplay->getListChordsName();
    QString fileContent = "";
    for (int i = 0; i < listChordsName.size(); i++) {
        fileContent += listChordsName[i];
        if (i != listChordsName.size() - 1) {
            fileContent += " ";
        }
    }

    saveFile(filePath, fileContent);
}
void MainWindow::slotCloseFile()
{
    this->close();
}
void MainWindow::slotSaveScale(QVector<QString> listScale)
{
    emit SaveScaleSignal(this->cListDisplay->getListChordsName(), listScale);
}
void MainWindow::slotExportScale(QVector<QString> listScale)
{
    cout << "Export Signal entered in MainWindow" << endl
         << flush;
    emit ExportScaleSignal(this->cListDisplay->getListChordsName(), listScale);
}
void MainWindow::slotStats()
{
    StatsDisplay* stats = new StatsDisplay();
    stats->show();
}
void MainWindow::slotAddChord()
{
    AddChordsScalesView* addChordView = new AddChordsScalesView(true);
    addChordView->show();
    connect(addChordView, SIGNAL(createChordSignal(QString, vector<int>)), this, SLOT(slotCreateChord(QString, vector<int>)));
}
void MainWindow::slotAddScale()
{
    AddChordsScalesView* addScaleView = new AddChordsScalesView(false);
    addScaleView->show();
    connect(addScaleView, SIGNAL(createScaleSignal(QString, vector<int>, QString)), this, SLOT(slotCreateScale(QString, vector<int>, QString)));
}
void MainWindow::slotDeleteChordView()
{
    DeleteChordsScalesView* deleteChordView = new DeleteChordsScalesView(true);
    deleteChordView->show();
    connect(deleteChordView, SIGNAL(deleteChordSignal(HSChord*)), this, SLOT(slotDeleteChord(HSChord*)));
}

void MainWindow::slotDeleteScaleView()
{
    DeleteChordsScalesView* deleteScaleView = new DeleteChordsScalesView(false);
    deleteScaleView->show();
    connect(deleteScaleView, SIGNAL(deleteScaleSignal(HSScale*)), this, SLOT(slotDeleteScale(HSScale*)));
}

void MainWindow::slotCreateChord(QString name, vector<int> hs)
{
    emit createChordSignal(name, hs);
}

void MainWindow::slotCreateScale(QString name, vector<int> hs, QString alias)
{
    emit createScaleSignal(name, hs, alias);
}

void MainWindow::slotDeleteScale(HSScale* hs)
{
    emit deleteScaleSignal(hs);
}

void MainWindow::slotDeleteChord(HSChord* hs)
{
    emit deleteChordSignal(hs);
}
