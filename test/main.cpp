#include "GUI.h"
#include "Widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    GUI gui;
    gui.show();
    return a.exec();
}
