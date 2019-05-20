#ifndef GENESGUI_H
#define GENESGUI_H


#pragma once
#include <qwidget.h>
#include "VictimFile.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "VictimFileService.h"
#include <QVector>

class GUI: public QWidget
{
    Q_OBJECT

public:
    GUI(unique_ptr<VictimFileService> victimFileService, QWidget *parent = 0);
    ~GUI();

private:
    unique_ptr<VictimFileService> victimFileService;
    QListWidget* victimFilesList;
    QListWidget* transferList;
    QLineEdit* nameEdit;
    QLineEdit* placeEdit;
    QLineEdit* ageEdit;
    QLineEdit* fileEdit;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* saveButton;
    QPushButton* nextButton;
    QPushButton* filterButton;
    QPushButton* openButton;

    void initGUI();
    int getSelectedIndex();
    void connectSignalsAndSlots();

    void populateVictimFilesList();
    void populateTransferList();
//    // When an item in the list is clicked, the text boxes get filled with the item's information
    void listItemChanged();

    void addVictimFileButtonHandler();
    void deleteVictimFileButtonHandler();
    void updateVictimFileButtonHandler();
    void filterVictimFileButtonHandler();
    void nextVictimFileButtonHandler();
    void saveVictimFileButtonHandler();
    void openVictimFileButtonHandler();

signals:
    void victimFilesUpdatedSignal();
    void transferListUpdatedSignal();
    void addVictimFileSignal(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void deleteVictimFileSignal(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void updateVictimFileSignal(const std::string& oldName, const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void saveVictimFileSignal(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void nextVictimFileSignal(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void filterVictimFileSignal(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void openVictimFileSignal(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);

public slots:
    void addVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
//    void deleteVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void updateVictimFile(const std::string& oldName, const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void saveVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void nextVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void filterVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
    void openVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto);
};

#endif // GENESGUI_H