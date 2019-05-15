#include "genesgui.h"
#include <QDebug>

GenesGUI::GenesGUI(std::vector<Gene> _genes, QWidget * parent): QWidget{parent}, genes{_genes}
{
    this->initGUI();
  //  this->connectSignalsAndSlots();
    //this->populateGenesList();
}

GenesGUI::~GenesGUI()
{
}

void GenesGUI::initGUI()
{
    //General layout of the window
    QHBoxLayout* layout = new QHBoxLayout{ this };

    // left side - just the list
    QWidget* leftSide = new QWidget{};
    QVBoxLayout* leftLayout = new QVBoxLayout{ leftSide };
    this->victimFilesList = new QListWidget{};
    // set the selection model
    //this->genesList->setSelectionMode(QAbstractItemView::SingleSelection);
   // layout->addWidget(this->genesList);
    leftLayout->addWidget(this->victimFilesList);
    // gene information
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
    /*
    nameString, placeString, ageString, photoString
    */

    QWidget* middleSide = new QWidget{};
    QVBoxLayout* middleLayout = new QVBoxLayout{ middleSide };
    this->moveButton = new QPushButton(">");
    this->moveButton->setFont(f);
    middleLayout->addWidget(this->moveButton);

    // right side - gene information + buttons
    QWidget* rightSide = new QWidget{};
    QVBoxLayout* rightLayout = new QVBoxLayout{ rightSide };

    // buttons
    QWidget* buttonsRightWidget = new QWidget{};
    QHBoxLayout* buttonsRightLayout = new QHBoxLayout{ buttonsRightWidget };
    this->transferList = new QListWidget{};
    // set the selection model
    //this->genesList->setSelectionMode(QAbstractItemView::SingleSelection);
   // layout->addWidget(this->genesList);
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

//void GenesGUI::connectSignalsAndSlots()
//{
//    // when the vector of genes is updated - re-populate the list
//    //QObject::connect(this, SIGNAL(genesUpdatedSignal()), this, SLOT(populateGenesList()));
//    QObject::connect(this, &GenesGUI::genesUpdatedSignal, this, &GenesGUI::populateGenesList);

//    // add a connection: function listItemChanged() will be called when an item in the list is selected
//    QObject::connect(this->genesList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });

//    // add button connections
//    QObject::connect(this->addGeneButton, &QPushButton::clicked, this, &GenesGUI::addGeneButtonHandler);
//    QObject::connect(this->deleteGeneButton, &QPushButton::clicked, this, &GenesGUI::deleteGeneButtonHandler);

//    // connect the addGene signal to the addGene slot, which adds a gene to vector
//    QObject::connect(this, SIGNAL(addGeneSignal(const std::string&, const std::string&, const std::string&)),
//                        this, SLOT(addGene(const std::string&, const std::string&, const std::string&)));
//}

//void GenesGUI::addGene(const std::string& geneName, const std::string& organismName, const std::string& sequence)
//{
//    this->genes.push_back(Gene{ geneName, organismName, sequence });

//    // emit the signal: the genes were updated
//    emit genesUpdatedSignal();
//}

//void GenesGUI::addGeneButtonHandler()
//{
//    // read data from the textboxes and add the new gene
//    QString organismName = this->organismEdit->text();
//    QString geneName = this->geneNameEdit->text();
//    QString sequence = this->sequenceEdit->toPlainText();

//    // emit the addGene signal
//    emit addGeneSignal(geneName.toStdString(), organismName.toStdString(), sequence.toStdString());
//}

//void GenesGUI::deleteGeneButtonHandler()
//{
//    // get the selected index and delete the gene
//    int idx = this->getSelectedIndex();

//    if (idx < 0 || idx >= this->genes.size())
//        return;

//    this->genes.erase(this->genes.begin() + idx);

//    // emit the signal: the genes were updated
//    emit genesUpdatedSignal();
//}

//void GenesGUI::populateGenesList()
//{
//    // clear the list, if there are elements in it
//    if (this->genesList->count() > 0)
//        this->genesList->clear();

//    for (auto g : this->genes)
//    {
//        QString itemInList = QString::fromStdString(g.getOrganismName() + " - " + g.getName());
//        QFont f{ "Verdana", 15 };
//        QListWidgetItem* item = new QListWidgetItem{ itemInList };
//        item->setFont(f);
//        this->genesList->addItem(item);
//    }

//    // set the selection on the first item in the list
//    if (this->genes.size() > 0)
//        this->genesList->setCurrentRow(0);
//}

//int GenesGUI::getSelectedIndex()
//{
//    if (this->genesList->count() == 0)
//        return -1;

//    // get selected index
//    QModelIndexList index = this->genesList->selectionModel()->selectedIndexes();
//    if (index.size() == 0)
//    {
//        this->organismEdit->clear();
//        this->geneNameEdit->clear();
//        this->sequenceEdit->clear();
//        return -1;
//    }

//    int idx = index.at(0).row();
//    return idx;
//}

//void GenesGUI::listItemChanged()
//{
//    int idx = this->getSelectedIndex();
//    if (idx == -1)
//        return;

//    // get the song at the selected index
//    if (idx >= this->genes.size())
//        return;
//    Gene g = this->genes[idx];

//    this->organismEdit->setText(QString::fromStdString(g.getOrganismName()));
//    this->geneNameEdit->setText(QString::fromStdString(g.getName()));
//    this->sequenceEdit->setText(QString::fromStdString(g.getSequence()));
//}
