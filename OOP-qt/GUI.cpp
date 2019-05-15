#include "GUI.h"
#include <QDebug>

GUI::GUI(std::vector<VictimFile> victimFiles, QWidget * parent): QWidget{parent}, victimFiles{victimFiles}
{
    this->initGUI();
  //  this->connectSignalsAndSlots();
    this->populateVictimFilesList();
}

GUI::~GUI()
{
}

void GUI::populateVictimFilesList()
{
    // clear the list, if there are elements in it
    if (this->victimFilesList->count() > 0)
        this->victimFilesList->clear();

    for (auto file : this->victimFiles)
    {
        QString itemInList = QString::fromStdString(file.getName() + ", " + file.getPlaceOfOrigin() + ", " + std::to_string(file.getAge()) + " years old, " + file.getPhotograph());
        QFont f{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->victimFilesList->addItem(item);
    }

//    if (this->victimFiles.size() > 0)
//        this->victimFilesList->setCurrentRow(0);
}

void GUI::initGUI()
{
    QHBoxLayout* layout = new QHBoxLayout{ this };

    QWidget* leftSide = new QWidget{};
    QVBoxLayout* leftLayout = new QVBoxLayout{ leftSide };
    this->victimFilesList = new QListWidget{};
    //this->victimFilesList->setSelectionMode(QAbstractItemView::SingleSelection);
    leftLayout->addWidget(this->victimFilesList);
    QWidget* victimFileDataWidget = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{ victimFileDataWidget };
    this->nameEdit = new QLineEdit{};
    this->placeEdit = new QLineEdit{};
    this->ageEdit = new QLineEdit{};
    this->fileEdit = new QLineEdit{};
    QFont f{ "Verdana", 15 };
    QLabel* nameLabel = new QLabel{ "&Name:" };
    nameLabel->setBuddy(this->nameEdit);
    QLabel* placeLabel = new QLabel{ "&Place: " };
    placeLabel->setBuddy(this->placeEdit);
    QLabel* ageLabel = new QLabel{ "&Age:" };
    ageLabel->setBuddy(this->ageEdit);
    QLabel* fileLabel = new QLabel{ "&File location:" };
    fileLabel->setBuddy(this->fileEdit);
    nameLabel->setFont(f);
    placeLabel->setFont(f);
    ageLabel->setFont(f);
    fileLabel->setFont(f);
    this->nameEdit->setFont(f);
    this->placeEdit->setFont(f);
    this->ageEdit->setFont(f);
    this->fileEdit->setFont(f);
    formLayout->addRow(nameLabel, this->nameEdit);
    formLayout->addRow(placeLabel, this->placeEdit);
    formLayout->addRow(ageLabel, this->ageEdit);
    formLayout->addRow(fileLabel, this->fileEdit);

    QWidget* buttonsLeftWidget = new QWidget{};
    QHBoxLayout* buttonsLeftLayout = new QHBoxLayout{ buttonsLeftWidget };
    this->addButton = new QPushButton("Add");
    this->addButton->setFont(f);
    this->deleteButton = new QPushButton("Delete");
    this->deleteButton->setFont(f);
    this->updateButton = new QPushButton("Update");
    this->updateButton->setFont(f);
    buttonsLeftLayout->addWidget(this->addButton);
    buttonsLeftLayout->addWidget(this->deleteButton);
    buttonsLeftLayout->addWidget(this->updateButton);

    leftLayout->addWidget(victimFileDataWidget);
    leftLayout->addWidget(buttonsLeftWidget);

    QWidget* middleSide = new QWidget{};
    QVBoxLayout* middleLayout = new QVBoxLayout{ middleSide };
    this->moveButton = new QPushButton(">");
    this->moveButton->setFont(f);
    middleLayout->addWidget(this->moveButton);

    QWidget* rightSide = new QWidget{};
    QVBoxLayout* rightLayout = new QVBoxLayout{ rightSide };

    QWidget* buttonsRightWidget = new QWidget{};
    QHBoxLayout* buttonsRightLayout = new QHBoxLayout{ buttonsRightWidget };
    this->transferList = new QListWidget{};

    rightLayout->addWidget(this->transferList);
    this->nextButton = new QPushButton("Next");
    this->nextButton->setFont(f);
    this->filterButton = new QPushButton("Filter");
    this->filterButton->setFont(f);
    buttonsRightLayout->addWidget(this->nextButton);
    buttonsRightLayout->addWidget(this->filterButton);

    rightLayout->addWidget(buttonsRightWidget);

    // add everything to the big layout
    layout->addWidget(leftSide);
    layout->addWidget(middleSide);
    layout->addWidget(rightSide);
}
