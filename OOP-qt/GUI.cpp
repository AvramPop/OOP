#include "GUI.h"
#include <QDebug>

GUI::GUI(unique_ptr<VictimFileService> victimFileService, QWidget * parent): QWidget{parent}
{
   // this->transferFileVector = std::make_unique<std::vector<VictimFile>>();
   // this->transfer = std::vector<VictimFile>();
    this->victimFileService = std::move(victimFileService);
    this->initGUI();
    this->connectSignalsAndSlots();
    this->populateVictimFilesList();
}

GUI::~GUI()
{
}
void GUI::connectSignalsAndSlots()
{
    // when the vector of genes is updated - re-populate the list
    //QObject::connect(this, SIGNAL(genesUpdatedSignal()), this, SLOT(populateGenesList()));
    QObject::connect(this, &GUI::victimFilesUpdatedSignal, this, &GUI::populateVictimFilesList);
    QObject::connect(this, &GUI::transferListUpdatedSignal, this, &GUI::populateTransferList);
    //QObject::connect(this, &GUI::transferListUpdatedSignal, this, &GUI::populateTransferList);
    // add a connection: function listItemChanged() will be called when an item in the list is selected
    QObject::connect(this->victimFilesList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });

    // add button connections
  /**/  QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addVictimFileButtonHandler);
  /**/  QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::deleteVictimFileButtonHandler);
  /**/  QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateVictimFileButtonHandler);
    QObject::connect(this->saveButton, &QPushButton::clicked, this, &GUI::saveVictimFileButtonHandler);
    QObject::connect(this->nextButton, &QPushButton::clicked, this, &GUI::nextVictimFileButtonHandler);
    QObject::connect(this->filterButton, &QPushButton::clicked, this, &GUI::filterVictimFileButtonHandler);
    QObject::connect(this->openButton, &QPushButton::clicked, this, &GUI::openVictimFileButtonHandler);


    // connect the addGene signal to the addGene slot, which adds a gene to vector
    QObject::connect(this, SIGNAL(addVictimFileSignal(const std::string&, const std::string&, const int, const std::string&)),
                        this, SLOT(addVictimFile(const std::string&, const std::string&, const int, const std::string&)));
    QObject::connect(this, SIGNAL(updateVictimFileSignal(const std::string&, const std::string&, const std::string&, const int, const std::string&)),
                        this, SLOT(updateVictimFile(const std::string&, const std::string&, const std::string&, const int, const std::string&)));
 // QObject::connect(this, SIGNAL(saveVictimFileSignal(const std::string&, const std::string&, const int, const std::string&)),
      //                  this, SLOT(saveVictimFile(const std::string&, const std::string&, const int, const std::string&)));
    QObject::connect(this, SIGNAL(nextVictimFileSignal(const std::string&, const std::string&, const int, const std::string&)),
                        this, SLOT(nextVictimFile(const std::string&, const std::string&, const int, const std::string&)));
    QObject::connect(this, SIGNAL(filterVictimFileSignal(const std::string&, const std::string&, const int, const std::string&)),
                        this, SLOT(filterVictimFile(const std::string&, const std::string&, const int, const std::string&)));
    QObject::connect(this, SIGNAL(openVictimFileSignal(const std::string&, const std::string&, const int, const std::string&)),
                        this, SLOT(openVictimFile(const std::string&, const std::string&, const int, const std::string&)));
}

void GUI::updateVictimFile(const std::string& oldName, const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto)
{
    VictimFile victimFileFromInput(victimFileName, victimFilePlace, victimFileAge, victimFilePhoto);
    this->victimFileService->updateVictimFile(oldName, victimFileFromInput);
    emit victimFilesUpdatedSignal();
}

void GUI::updateVictimFileButtonHandler()
{
    // read data from the textboxes and add the new gene
    int idx = this->getSelectedIndex();

    if (idx < 0 || idx >= this->victimFileService->getRepositorySize())
        return;

    QString oldName = QString::fromStdString((this->victimFileService->getList()[idx]).getName());
    QString victimFileName = this->nameEdit->text();
    QString victimFilePlace = this->placeEdit->text();
    QString victimFileAge = this->ageEdit->text();
    QString victimFilePhoto = this->fileEdit->text();

    emit updateVictimFileSignal(oldName.toStdString(), victimFileName.toStdString(), victimFilePlace.toStdString(), std::stoi(victimFileAge.toStdString()), victimFilePhoto.toStdString());
}

void GUI::addVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto)
{
   // this->genes.push_back(Gene{ geneName, organismName, sequence });
   VictimFile newVictimFile(victimFileName, victimFilePlace, victimFileAge, victimFilePhoto);
    this->victimFileService->addVictimFile(newVictimFile);
    // emit the signal: the genes were updated
    emit victimFilesUpdatedSignal();
}

void GUI::addVictimFileButtonHandler()
{
    // read data from the textboxes and add the new gene
    QString victimFileName = this->nameEdit->text();
    QString victimFilePlace = this->placeEdit->text();
    QString victimFileAge = this->ageEdit->text();
    QString victimFilePhoto = this->fileEdit->text();

    emit addVictimFileSignal(victimFileName.toStdString(), victimFilePlace.toStdString(), std::stoi(victimFileAge.toStdString()), victimFilePhoto.toStdString());
}

void GUI::deleteVictimFileButtonHandler()
{
    // get the selected index and delete the gene
    int idx = this->getSelectedIndex();

    if (idx < 0 || idx >= this->victimFileService->getRepositorySize())
        return;

    this->victimFileService->removeVictimFile((this->victimFileService->getList()[idx]).getName());
    //controller remove victim file at index-----------------------------------------------
    // emit the signal: the genes were updated
    emit victimFilesUpdatedSignal();
}
void GUI::filterVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto)
{
   // this->genes.push_back(Gene{ geneName, organismName, sequence });
//add victim file to controller ++++++++++++++++++++++++++++++++++++++++++++++++
    // emit the signal: the genes were updated
    emit victimFilesUpdatedSignal();
}

void GUI::filterVictimFileButtonHandler()
{
    // read data from the textboxes and add the new gene
    QString victimFileName = this->nameEdit->text();
    QString victimFilePlace = this->placeEdit->text();
    QString victimFileAge = this->ageEdit->text();
    QString victimFilePhoto = this->fileEdit->text();

    emit addVictimFileSignal(victimFileName.toStdString(), victimFilePlace.toStdString(), stoi(victimFileAge.toStdString()), victimFilePhoto.toStdString());
}
void GUI::nextVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto)
{
   // this->genes.push_back(Gene{ geneName, organismName, sequence });
//add victim file to controller ++++++++++++++++++++++++++++++++++++++++++++++++
    // emit the signal: the genes were updated
    emit victimFilesUpdatedSignal();
}

void GUI::nextVictimFileButtonHandler()
{
    // read data from the textboxes and add the new gene
    QString victimFileName = this->nameEdit->text();
    QString victimFilePlace = this->placeEdit->text();
    QString victimFileAge = this->ageEdit->text();
    QString victimFilePhoto = this->fileEdit->text();

    emit addVictimFileSignal(victimFileName.toStdString(), victimFilePlace.toStdString(), stoi(victimFileAge.toStdString()), victimFilePhoto.toStdString());
}
void GUI::openVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto)
{
   // this->genes.push_back(Gene{ geneName, organismName, sequence });
//add victim file to controller ++++++++++++++++++++++++++++++++++++++++++++++++
    // emit the signal: the genes were updated
    emit victimFilesUpdatedSignal();
}

void GUI::openVictimFileButtonHandler()
{
    // read data from the textboxes and add the new gene
    QString victimFileName = this->nameEdit->text();
    QString victimFilePlace = this->placeEdit->text();
    QString victimFileAge = this->ageEdit->text();
    QString victimFilePhoto = this->fileEdit->text();

    emit addVictimFileSignal(victimFileName.toStdString(), victimFilePlace.toStdString(), stoi(victimFileAge.toStdString()), victimFilePhoto.toStdString());
}
void GUI::saveVictimFile(const std::string& victimFileName, const std::string& victimFilePlace, const int victimFileAge, const std::string& victimFilePhoto)
{
   // this->genes.push_back(Gene{ geneName, organismName, sequence });
//add victim file to controller ++++++++++++++++++++++++++++++++++++++++++++++++
    // emit the signal: the genes were updated
    emit victimFilesUpdatedSignal();
}

void GUI::saveVictimFileButtonHandler()
{
    // read data from the textboxes and add the new gene
    int idx = this->getSelectedIndex();

    if (idx < 0 || idx >= this->victimFileService->getRepositorySize())
        return;

    this->victimFileService->addToTransfer(this->victimFileService->getList()[idx]);
    emit transferListUpdatedSignal();
}


int GUI::getSelectedIndex()
{
    if (this->victimFilesList->count() == 0)
        return -1;

    // get selected index
    QModelIndexList index = this->victimFilesList->selectionModel()->selectedIndexes();
    if (index.size() == 0)
    {
        this->nameEdit->clear();
        this->placeEdit->clear();
        this->ageEdit->clear();
        this->fileEdit->clear();
        return -1;
    }

    int idx = index.at(0).row();
    return idx;
}

void GUI::listItemChanged()
{
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex == -1)
        return;

    // get the song at the selected index
    if (selectedIndex >= this->victimFileService->getRepositorySize())
        return;
    VictimFile victimFile = this->victimFileService->getList()[selectedIndex];

    this->nameEdit->setText(QString::fromStdString(victimFile.getName()));
    this->placeEdit->setText(QString::fromStdString(victimFile.getPlaceOfOrigin()));
    this->ageEdit->setText(QString::fromStdString(std::to_string(victimFile.getAge())));
    this->fileEdit->setText(QString::fromStdString(victimFile.getPhotograph()));
}

void GUI::populateTransferList()
{
    // clear the list, if there are elements in it
    if (this->transferList->count() > 0)
        this->transferList->clear();

    for (auto file : this->victimFileService->getTransfer())
    {
        QString itemInList = QString::fromStdString(file.getName() + ", " + file.getPlaceOfOrigin() + ", " + std::to_string(file.getAge()) + " years old, " + file.getPhotograph());
        QFont f{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->transferList->addItem(item);
    }

//    if (this->victimFileService->getRepositorySize() > 0)
//        this->victimFilesList->setCurrentRow(0);
}

void GUI::populateVictimFilesList()
{
    // clear the list, if there are elements in it
    if (this->victimFilesList->count() > 0)
        this->victimFilesList->clear();

    for (auto file : this->victimFileService->getList())
    {
        QString itemInList = QString::fromStdString(file.getName() + ", " + file.getPlaceOfOrigin() + ", " + std::to_string(file.getAge()) + " years old, " + file.getPhotograph());
        QFont f{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->victimFilesList->addItem(item);
    }

//    if (this->victimFileService->getRepositorySize() > 0)
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
    this->saveButton = new QPushButton(">");
    this->saveButton->setFont(f);
    middleLayout->addWidget(this->saveButton);

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