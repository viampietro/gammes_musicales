#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T10:10:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UtProject
TEMPLATE = app


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
    controler/QMidiFile.cpp \
    controler/QMidiOut.cpp \
    controler/OS/QMidi_ALSA.cpp \
    controler/OS/QMidi_Haiku.cpp \
    controler/OS/QMidi_Win32.cpp \


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
    modele/ttt.h \
    controler/ut.h \
<<<<<<< HEAD
    modele/note.h
=======
    controler/QMidiFile.h \
    controler/QMidiOut.h \
>>>>>>> 818e3fe00dc20f5afa793df87ac8bf4ab7cfffc2


FORMS    += view/mainwindow.ui

# QMidi include file for QMake
CONFIG += c++11

win32 {
        LIBS += -lwinmm
        SOURCES += $$PWD/controler/OS/QMidi_Win32.cpp
}

linux* {
        LIBS += -lasound
        SOURCES += $$PWD/controler/OS/QMidi_ALSA.cpp
}

haiku* {
        LIBS += -lmidi2
        SOURCES += $$PWD/controler/OS/QMidi_Haiku.cpp
}
