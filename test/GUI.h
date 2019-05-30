#ifndef GUI_H
#define GUI_H

#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>

class Thing{
public:
    QString info;

    bool operator>(const Thing& t){
        return this->info > t.info;
    }

    bool operator<(const Thing& t){
        return this->info < t.info;
    }
};

class GUI : public QWidget
{
    Q_OBJECT

private:
    void initGUI();
    void initConnections();
    QPushButton *button1;
    QPushButton *button2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit2;
    QListWidget* listWidget;
    QListWidget* listWidget2;
    QLabel *label;
    QLabel *label2;
    void button1Handler();
    void button2Handler();
    void listHandler();

public:
    explicit GUI(QWidget *parent = nullptr);

signals:
  //  void updateLabel();
    void updateLabelSignal(int newLine);
    void launchMessageBoxSignal(QString str);

public slots:
    void updateLabelSlot(int newLine);
    void launchMessageBoxSlot(QString str);
};

#endif // GUI_H
