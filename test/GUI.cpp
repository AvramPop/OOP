#include <algorithm>
#include "GUI.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QVector>
GUI::GUI(QWidget *parent) : QWidget(parent)
{
    this->initGUI();
    this->initConnections();
}

//void GUI::listUpdated(){
//    emit updateLabel(this->listWidget->currentRow());
//}

void GUI::updateLabelSlot(int newIndex){
    qDebug() << "here";
    this->label->setText(this->listWidget->item(newIndex)->text());
}

void GUI::launchMessageBoxSlot(QString str)
{
    QMessageBox* msgBox = new QMessageBox{};
    QString msgBoxRez;
    for(int i = 0; i < this->listWidget->count(); i++){
        if(this->listWidget->item(i)->text().contains(str)){
            msgBoxRez.append(this->listWidget->item(i)->text());
            msgBoxRez.append("\n");
        }
    }
    msgBox->setText(msgBoxRez);
    msgBox->exec();
}

void GUI::initGUI()
{
    qDebug() << "initialising GUI";
    QHBoxLayout *horizontalLayout = new QHBoxLayout{ this };
    QWidget* leftSide = new QWidget{};
    QWidget* middleSide = new QWidget{};
    QWidget* rightSide = new QWidget{};
    this->listWidget = new QListWidget{};
    this->listWidget2 = new QListWidget{};
    QVBoxLayout *verticalLayoutLeft = new QVBoxLayout{leftSide};
    QVBoxLayout *verticalLayoutMiddle = new QVBoxLayout{middleSide};
    QVBoxLayout *verticalLayoutRight = new QVBoxLayout{rightSide};
    this->button1 = new QPushButton();
    this->button1->setText("button1");
    this->button2 = new QPushButton();
    this->button2->setText("button2");
    this->lineEdit = new QLineEdit{};
    this->lineEdit2 = new QLineEdit{};
  //  this->lineEdit->text("DAVE DAVE");
    this->label2 = new QLabel();
    this->label2->setText("label2");
    this->label2->setStyleSheet("QLabel {color: blue; background-color: black}");
    this->label = new QLabel();
    this->label->setText("label");
    this->label->setStyleSheet("QLabel {color: red; background-color: yellow}");
    Thing a, b, c, d;
    a.info = "damo";
    b.info = "bain";
    c.info = "aaa";
    d.info = "oikj";
    QVector<Thing> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    std::sort(v.begin(), v.end());
    qDebug() << v[0].info << " " << v[3].info << endl;
    this->listWidget->addItem("dani");
    this->listWidget->addItem("ancu");
    this->listWidget->addItem("ana");
    this->listWidget->addItem("dave");
    this->listWidget->addItem("sami");

    verticalLayoutLeft->addWidget(this->button1);
    verticalLayoutLeft->addWidget(this->button2);
    verticalLayoutMiddle->addWidget(this->label);
    verticalLayoutMiddle->addWidget(this->label2);
    verticalLayoutMiddle->addWidget(this->listWidget);
    verticalLayoutRight->addWidget(this->lineEdit);
    verticalLayoutRight->addWidget(this->lineEdit2);
    horizontalLayout->addWidget(leftSide);
    horizontalLayout->addWidget(middleSide);
    horizontalLayout->addWidget(rightSide);
}

void GUI::initConnections()
{
    QObject::connect(this->button1, &QPushButton::clicked, this, &GUI::button1Handler);
    QObject::connect(this->listWidget, &QListWidget::currentRowChanged, this, &GUI::listHandler);
    QObject::connect(this, &GUI::updateLabelSignal, this, &GUI::updateLabelSlot);
    QObject::connect(this, &GUI::launchMessageBoxSignal, this, &GUI::launchMessageBoxSlot);
    QObject::connect(this->button2, &QPushButton::clicked, this, &GUI::button2Handler);
}

void GUI::button1Handler()
{
    this->listWidget->addItem(this->lineEdit->text());

}

void GUI::button2Handler()
{
    emit this->launchMessageBoxSignal(this->lineEdit2->text());
}

void GUI::listHandler()
{
    emit updateLabelSignal(this->listWidget->currentRow());
  //  this->label->setText(this->listWidget->currentItem()->text());
}
