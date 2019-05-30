#include "Widget.h"
#include "ui_Widget.h"
#include <QDebug>
#include <QHBoxLayout>

void Widget::initGUI()
{
    qDebug() << "initialising GUI";
    QHBoxLayout *horizontalLayout = new QHBoxLayout{ this };
    QWidget* leftSide = new QWidget{};
    QWidget* middleSide = new QWidget{};
    QWidget* rightSide = new QWidget{};
    QVBoxLayout *verticalLayoutLeft = new QVBoxLayout{leftSide};
    QVBoxLayout *verticalLayoutMiddle = new QVBoxLayout{middleSide};
    QVBoxLayout *verticalLayoutRight = new QVBoxLayout{rightSide};
    this->button1 = new QPushButton();
    this->button1->setText("button1");
    this->button2 = new QPushButton();
    this->button2->setText("button2");
    this->lineEdit = new QLineEdit{};
  //  this->lineEdit->text("DAVE DAVE");
    this->label = new QLabel();
    this->label->setText("label");
    verticalLayoutLeft->addWidget(this->button1);
    verticalLayoutLeft->addWidget(this->button2);
    verticalLayoutMiddle->addWidget(this->label);
    verticalLayoutRight->addWidget(this->lineEdit);
    horizontalLayout->addWidget(leftSide);
    horizontalLayout->addWidget(middleSide);
    horizontalLayout->addWidget(rightSide);
}

void Widget::initConnections()
{
   // QObject::connect(this->button1, &QPushButton::clicked, this, &Widget::button1Handler);
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    initGUI();
    //ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
