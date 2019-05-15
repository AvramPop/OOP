#ifndef GENESGUI_H
#define GENESGUI_H


#pragma once
#include <qwidget.h>
#include "gene.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

class GenesGUI: public QWidget
{
    Q_OBJECT

public:
    GenesGUI(std::vector<Gene> genes, QWidget *parent = 0);
    ~GenesGUI();

private:
    std::vector<Gene> genes;

    QListWidget* victimFilesList;
    QListWidget* transferList;
    QLineEdit* nameEdit;
    QLineEdit* placeEdit;
    QLineEdit* ageEdit;
    QLineEdit* fileEdit;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* moveButton;
    QPushButton* nextButton;
    QPushButton* filterButton;

    void initGUI();
   // int getSelectedIndex();
  //  void connectSignalsAndSlots();

  //  void populateGenesList();
//    // When an item in the list is clicked, the text boxes get filled with the item's information
//    void listItemChanged();

//    void addGeneButtonHandler();
//    void deleteGeneButtonHandler();

//signals:
//    void genesUpdatedSignal();
//    void addGeneSignal(const std::string& geneName, const std::string& organismName, const std::string& sequence);

//public slots:
//    void addGene(const std::string& geneName, const std::string& organismName, const std::string& sequence);
};


#endif // GENESGUI_H
