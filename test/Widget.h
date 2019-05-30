#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    void initGUI();
    void initConnections();
    QPushButton *button1;
    QPushButton *button2;
    QLineEdit *lineEdit;
    QLabel *label;
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
