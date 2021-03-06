#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T10:10:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


QMAKE_LFLAGS_WINDOWS += -Wl,--stack,32000000000000
QMAKE_CXXFLAGS += -std=c++0x
LIB += -Wl,--stack,4194304000000000

TARGET = UtProject
TEMPLATE = app
CONFIG += release console

SOURCES += main.cpp\
        view/mainwindow.cpp \
    modele/chord.cpp \
    modele/scale.cpp \
    modele/harmonicstructure.cpp \
    modele/hschord.cpp \
    modele/hsscale.cpp \
    modele/chorddictionary.cpp \
    modele/scaledictionary.cpp \
    modele/cs.cpp \
    view/chordslistdisplay.cpp \
    view/scaleslistdisplay.cpp \
    view/chorddisplay.cpp \
    view/scaledisplay.cpp \
    view/scalesdisplay.cpp \
    modele/node.cpp \
    modele/algobrut.cpp \
    modele/algo.cpp \
    controler/ut.cpp \
    view/parametersdisplay.cpp \
    modele/abstractalgo.cpp \
    modele/parametres.cpp \
    modele/algoopti.cpp \
    modele/algobrutomega.cpp \
    test/testfunctions.cpp \
    view/statsdisplay.cpp \
    view/chordsview.cpp \
    view/addchordsscalesview.cpp \
    view/deletechordsscalesview.cpp \
    modele/export.cpp

HEADERS  += view/mainwindow.h \
    modele/chord.h \
    modele/scale.h \
    modele/harmonicstructure.h \
    modele/hschord.h \
    modele/hsscale.h \
    modele/chorddictionary.h \
    modele/scaledictionary.h \
    modele/algo.h \
    modele/cs.h \
    view/scaleslistdisplay.h \
    view/chordslistdisplay.h \
    view/chorddisplay.h \
    view/scaledisplay.h \
    view/scalesdisplay.h \
    modele/node.h \
    modele/algobrut.h \
    controler/ut.h \
    modele/note.h \
    view/parametersdisplay.h \
    modele/abstractalgo.h \
    modele/parametres.h \
    modele/algoopti.h \
    modele/algobrutomega.h \
    test/testfunctions.h \
    view/statsdisplay.h \
    view/chordsview.h \
    view/addchordsscalesview.h \
    view/deletechordsscalesview.h \
    modele/export.h

FORMS  += view/mainwindow.ui

