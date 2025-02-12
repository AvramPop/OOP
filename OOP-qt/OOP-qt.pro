#-------------------------------------------------
#
# Project created by QtCreator 2019-05-14T22:09:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OOP-qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
        Exception.cpp \
        FileRepository.cpp \
        FileSaver.cpp \
        GUI.cpp \
        InMemoryRepository.cpp \
        MockRepository.cpp \
        Mode.cpp \
        Repository.cpp \
        Scanner.cpp \
        Validator.cpp \
        VictimFile.cpp \
        VictimFileService.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        Exception.h \
        FileRepository.h \
        FileSaver.h \
        GUI.h \
        InMemoryRepository.h \
        MockRepository.h \
        Mode.h \
        Repository.h \
        Scanner.h \
        Validator.h \
        VictimFile.h \
        VictimFileService.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    conf.in \
    data.txt \
    temp.txt \
    transfer.csv
