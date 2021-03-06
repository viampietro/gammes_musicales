#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define UT_VERSION "1.3"

//Bibliotheques c++
#include <iostream>
#include <thread>

//Bibliotheques Qt
#include <QFile>
#include <QSpacerItem>
#include <QTextStream>
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QGridLayout>
#include <QLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QSpacerItem>
#include <QGroupBox>
#include <QCoreApplication>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QApplication>
#include <QVector>

//Classes
#include "modele/hschord.h"
#include "modele/hsscale.h"
#include "view/addchordsscalesview.h"
#include "view/chordslistdisplay.h"
#include "view/deletechordsscalesview.h"
#include "view/scaleslistdisplay.h"
#include "view/statsdisplay.h"
#include "view/parametersdisplay.h"

using namespace std;

//Fenêtre principal du programme, affichée en permanence
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    //Layout
    QGridLayout *mainLayout;//Layout principale servant de support aux différents layouts d'affichage
    QGridLayout *chordsLayout;
    QGridLayout *choicesLayout;//Layout affichant l'interface permettant à l'utilisateur de choisir accords et paramètres, "visible" avant lancement de l'algorithme, "hidden" après
    QGridLayout *scalesLayout;
    ChordsListDisplay *cListDisplay;//Layout affichant les accords choisit par l'utilisateur
    QGroupBox *choicesDisplay;
    ScalesListDisplay *sListDisplay;//Layout affichant les gammes générées, "hidden" avant lancement de l'algorithme, "visible" après lancement


    //Button
    QPushButton *addButton;
    QPushButton *generateButton;
    QPushButton *returnButton;
    QPushButton *reinitializeButton;
    QPushButton *parametersButton;

    //ComboBox
    QComboBox *noteComboBox;
    QComboBox *hsComboBox;

    //Label
    QLabel *noteLabel;
    QLabel *hsLabel;

    //FileDialog
    QFileDialog *explorer;

    //Widget
    ParametersDisplay *parametersWindow;

public:
    //Constructeurs
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void constructMenuBar();
    void constructLayout();
    void constructChordsLayout();
    void constructChoicesLayout();
    void constructScalesLayout();

    //Accesseurs
    ParametersDisplay *getParametersDisplay();
    void removeDeletedChords(HSChord *hs);

    //Méthodes
    void clearLayout(QLayout *layout, bool deleteWidgets);
    QString openExplorer(int i);
    static QVector<QString> testFile(QString filePath);
    void saveFile(QString filePath, QString fileContent);
    void resizeEvent ( QResizeEvent * event );
    void fillComboBoxHS(QVector<QString> listHS);
    void fillParametersLists(QVector<QString> listHSScales, QVector<QString> listAlias, QVector<QString> listHSCustomScales, QVector<QString> listCustomAlias);
    void constructScaleFoundView(QVector<QVector<QString> > listFoundScales, QString msg);
    void goToResultsInterface();

public slots :
    void slotAddButton();
    void slotGenerateButton();
    void slotReturnButton();
    void slotReinitializeButton();
    void slotParametersButton();
    void slotNewFile();
    void slotImportFile();
    void slotSaveFile();
    void slotCloseFile();
    void slotSaveScale(QVector<QString> listScale);
    void slotExportScale(QVector<QString> listScale);
    void slotStats();
    void slotAddChord();
    void slotAddScale();
    void slotDeleteChordView();
    void slotDeleteScaleView();
    void slotCreateChord(QString name, vector<int> hs);
    void slotCreateScale(QString name, vector<int> hs, QString alias);
    void slotDeleteScale(HSScale* hs);
    void slotDeleteChord(HSChord* hs);


signals :

    void generateSignal(QVector<QString> listChords);
    void SaveScaleSignal(QVector<QString> listChords, QVector<QString> listScale);
    void ExportScaleSignal(QVector<QString> listChords, QVector<QString> listScale);
    void createChordSignal(QString name, vector<int> hs);
    void createScaleSignal(QString name, vector<int> hs, QString alias);
    void deleteChordSignal(HSChord* hs);
    void deleteScaleSignal(HSScale* hs);
};

#endif // MAINWINDOW_H
